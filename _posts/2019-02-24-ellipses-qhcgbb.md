---
title: qhcgbb
permalink: qhcgbb
layout: post
date: 2019-02-24 19:04:10
category: ellipses
---

```latex
% Dans le préambule
% -----------------
\usepackage{tikz}
% -----------------

\begin{tikzpicture}[scale=0.66]
  \draw(0,0)--(0,{2+sqrt(2)})
            --({2+sqrt(2)},0)--cycle;
  \draw (1,1) circle(1);
\end{tikzpicture}
```