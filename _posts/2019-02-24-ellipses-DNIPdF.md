---
title: DNIPdF
permalink: DNIPdF
layout: post
date: 2019-02-24 19:04:10
category: ellipses
---

```latex
% Dans le préambule
% -----------------
\usepackage{scratch3}
% -----------------

\begin{scratch}
\blockinit{Quand \greenflag est cliqué}
\blockpen{stylo en position d'écriture}
\blockrepeat{répéter \ovalnum{10} fois} {
  \blockmove{avancer de \ovalnum{10}}
  \blockmove {
    tourner \turnleft{} de \ovalnum{36} degrés
  }
}
\end{scratch}
```