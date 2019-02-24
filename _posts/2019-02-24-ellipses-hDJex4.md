---
title: hDJex4
permalink: hDJex4
layout: post
date: 2019-02-24 19:04:10
category: ellipses
---

```latex
% Dans le préambule
% -----------------
\usepackage{pst-circ}
% -----------------

\begin{pspicture}(0,0)(4.5,2.5)
  \pnodes(0,0){M}(0,2){N}(4,2){P}(4,0){Q}
  \switch(P)(Q){}
  \capacitor(M)(Q){$C$}
  \vac(M)(N){$E$}
  \coil(N)(P){$L$}
\end{pspicture}
```