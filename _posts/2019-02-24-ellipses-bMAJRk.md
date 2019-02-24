---
title: bMAJRk
permalink: bMAJRk
layout: post
date: 2019-02-24 19:04:10
category: ellipses
---

```latex
% Dans le préambule
% -----------------
\usepackage{pst-circ}
% -----------------

\begin{pspicture}(0,0)(6,2)
  \pnodes(0,1){M}(3,1){N}(6,1){P}
  \capacitor(M)(N){$C$}
  \coil(N)(P){$L$}
\end{pspicture}
```