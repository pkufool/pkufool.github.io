---
permalink: /
title: ""
excerpt: ""
author_profile: true
redirect_from: 
  - /about/
  - /about.html
---

{% if site.google_scholar_stats_use_cdn %}
{% assign gsDataBaseUrl = "https://cdn.jsdelivr.net/gh/" | append: site.repository | append: "@" %}
{% else %}
{% assign gsDataBaseUrl = "https://raw.githubusercontent.com/" | append: site.repository | append: "/" %}
{% endif %}
{% assign url = gsDataBaseUrl | append: "google-scholar-stats/gs_data_shieldsio.json" %}

<span class='anchor' id='about-me'></span>

I work at Xiaomi AI lab as a senior engineer now, developing the Next-gen Kaldi under the leadership of [Daniel Povey](http://danielpovey.com/). Our team focus on the advanced and efficient open source E2E automatic speech recognition. If you are interested in our Next-gen Kaldi project and want to know more about it, feel free to email me at wkang.pku@gmail.com.

I graduated from Peking University with a master's degree majoring in Technology of Computer Application. I got my bachelor's degree from School of Electronic Science and Engineering, Nanjing University. 

I used to work for [China Highway Engineering Consultants Corporation (CHECC)](http://www.checc.com.cn/) as an big data engineer. At the spring of 2019, I changed my direction to Automatic Speech Recognition. Thanks to [Mobvoi](https://www.chumenwenwen.com/),  it gave me a chance to start my ASR research as a layman. I worked there for more than 2 years focusing on intelligent cockpit. After that, at the summer of 2021, I joined Daniel's team.


# 🔥 News
- *2022.06*: &nbsp;🎉🎉 Pruned rnnt paper is accepted by InterSpeech 2022 [pdf](https://arxiv.org/pdf/2206.13236.pdf).
- *2022.03*: &nbsp;🎉🎉 We finish our [pruned rnnt loss](https://github.com/danpovey/fast_rnnt) (also in [k2](https://github.com/k2-fsa/k2)), which is much faster and memory efficient than RNNTLoss in torchaudio.
- *2021.12*: &nbsp;🎉🎉 We decide to change our direction from CTC/MMI to RNN-T like models, because it is more suitable for efficient streaming ASR.
- *2021.08*: &nbsp;🎉🎉 We release the first version of [Icefall](https://github.com/k2-fsa/icefall) at the InterSpeech 2021.

# 📝 Publications 

<div class='paper-box'><div class='paper-box-image'><div><div class="badge">InterSpeech 2022</div><img src='images/pruned-rnnt.png' alt="sym" width="100%"></div></div>
<div class='paper-box-text' markdown="1">

[Pruned RNN-T for fast, memory-efficient ASR training](https://arxiv.org/pdf/2206.13236.pdf)

Fangjun Kuang, Liyong Guo, **Wei Kang**, Long Lin, Mingshuang Luo, Zengwei Yao, Daniel Povey, Shaoqing Ren, Jian Sun

[**fast_rnnt**](https://github.com/danpovey/fast_rnnt) [**k2**](https://github.com/k2-fsa/k2/blob/master/k2/python/k2/rnnt_loss.py)
- We introduce a method for faster and more memoryefficient RNN-T loss computation.
  - We first obtain pruning bounds for the RNN-T recursion using a simple joiner network that is linear in the encoder and decoder embeddings. 
  - We then use those pruning bounds to evaluate the full, non-linear joiner network.
</div>
</div>

# 🚀 Projects

<div class='paper-box'><div class='paper-box-image'><div><div class="badge">k2</div><img src='images/k2-500x300.png' alt="sym" width="100%"></div></div>
<div class='paper-box-text' markdown="1">

[k2: The core algorithm of the Next-gen Kaldi](https://github.com/k2-fsa/k2)

![](https://img.shields.io/github/stars/k2-fsa/k2?style=social)

- Ragged Tensor running on both CPU and GPU.
- Differentiable Finite State Acceptor.
- Pruned RNN-T Loss.

</div>
</div>

<div class='paper-box'><div class='paper-box-image'><div><div class="badge">Icefall</div><img src='images/icefall-500x300.png' alt="sym" width="100%"></div></div>
<div class='paper-box-text' markdown="1">

[Icefall: The recipes of the Next-gen Kaldi](https://github.com/k2-fsa/icefall)

![](https://img.shields.io/github/stars/k2-fsa/icefall?style=social)

- Conformer CTC / MMI.
- Xformer transducer.
- MVQ training.
- Pipeline to build an ASR.

</div>
</div>

# 📖 Educations
- *2014.09 - 2017.06 (Master)*, Computer Science (CS), Peking University (PKU).
  - Technology of Computer Application, Institute of Network Computing and Information Systems (NC&IS)
- *2010.09 - 2014.06 (Bachelor)*: Electronics Engineering (EE), Nanjing University (NJU).
  - Information Electronic, School of Electronic Science and Engineering

# 💬 Invited Talks
- *2022.07*, I give a presentation about the Next-gen Kaldi.  \| [\[video\]](https://bilibili.com/)

# 💻 Work Experiences
- *2021.06 - Now*, Xiaomi Corporation, Senior Engineer.
- *2019.01 - 2021.05*, Mobvoi Beijing, Speech Engineer.
- *2017.02 - 2018.12*, China Highway Engineering Consultants Corporation (CHECC), Data R & D Engineer.
- *2016.03 - 2016.12 (Internship)*, Mobvoi Beijing, Search Engineer.
