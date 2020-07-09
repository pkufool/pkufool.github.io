#include <pthread.h>
#include <string.h>
#include <sys/resource.h>

#include <cmath>
#include <iostream>
#include <string>
#include <vector>

class Thread {
 public:
  Thread() {}
  ~Thread() {}

  void Start() {
    const int err = pthread_create(&tid_, NULL, Thread::RunThread, this);
    if (err != 0) {
      std::cout << "Thread create failed: " << strerror(err);
      return;
    }
  }

  void Run() {
    int result = 0;
    for (int i = 0; i < 100000; ++i) {
      for (int j = i; j < 100000; ++j) {
        result += log(i * 1.0) + log(j * 1.0);
      }
    }
    std::cout << "Final result for thread " << pthread_self()
              << " is " << result;
  }

  void Join() {
    const int err = pthread_join(tid_, NULL);
    if (err != 0) {
      std::cout << "Thread join failed: " << strerror(err);
    }
  }
  
  void SetName(const std::string& name) {
    int res = pthread_setname_np(tid_, name.c_str());
    if (res != 0) {
      std::cout << "Thread " << tid_ << " setname failed: "
                << strerror(res) << std::endl;
    }
  }

  void SetNiceValue(const int nice) {
    nice_ = nice;
  }

  void BindCpu(const std::vector<int>& cpus) {
    if (cpus.empty()) {
      return;
    }
    cpu_set_t cpuset;
    CPU_ZERO(&cpuset);
    for (const auto& id : cpus) {
      CPU_SET(id, &cpuset);
    }
    std::cout << "set cpu count: " << CPU_COUNT(&cpuset)
              << " for thread:" << tid_;
    int ret = pthread_setaffinity_np(tid_, sizeof(cpuset), &cpuset);
    if (ret != 0) {
      std::cout << "Failed to call pthread_setaffinity_np.";
    }
  }

  void SetSchedulerPolicy(const std::string& policy, const int priority) {
    struct sched_param param;
    int policy_type = SCHED_OTHER;
    if (policy == "SCHED_OTHER") {
      policy_type = SCHED_OTHER;
    } else if (policy == "SCHED_FIFO") {
      policy_type = SCHED_FIFO;
    } else if (policy == "SCHED_RR") {
      policy_type = SCHED_RR;
    } else if (policy == "SCHED_BATCH") {
      policy_type = SCHED_BATCH;
    } else if (policy == "SCHED_IDLE") {
      policy_type = SCHED_IDLE;
    }

    int old_policy, old_priority;
    pthread_getschedparam(tid_, &old_policy, &param);
    old_priority = param.sched_priority;
    param.sched_priority = priority;

    int s = pthread_setschedparam(tid_, policy_type, &param);
    if (s != 0)
      std::cout << "pthread_setschedparam failed, return value : "
                << strerror(s);
    std::cout << "old policy : " << old_policy
              << ", old priority : " << old_priority
              << ", new policy : " << policy_type
              << ", priority : " << priority << std::endl;
  }

 private:
  static void* RunThread(void *v) {
    Thread* t = static_cast<Thread*>(v);

    int ret = setpriority(PRIO_PROCESS, 0, t->nice_);
    if (ret != 0) {
      std::cout << "Setpriority for thread " << t->tid_
                << " failed: " << strerror(ret) << std::endl;
    } else {
      std::cout << "Setpriority for thread " << t->tid_
                << " to " << t->nice_ << std::endl;
    }
    t->Run();
    return 0;
  }

  pthread_t tid_ = 0;
  int nice_ = 0;
};

int main() {
  std::vector<Thread> threads;
  for (int i = 1; i < 4; ++i) {
    Thread t1;
    t1.SetNiceValue(-1 * i);
    t1.Start();
    t1.SetName("thread_" + std::to_string(i));
    t1.SetSchedulerPolicy("SCHED_RR", i);
    threads.push_back(t1);
  }
  Thread t1;
  t1.SetNiceValue(-10);
  t1.Start();
  t1.SetName("thread_10");
  t1.Join();
  for (auto &t : threads) {
    t.Join();
  }
}