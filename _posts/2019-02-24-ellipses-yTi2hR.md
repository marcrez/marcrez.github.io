---
title: yTi2hR
permalink: yTi2hR
layout: post
date: 2019-02-24 19:04:10
category: ellipses
---

```latex
% Dans le préambule
% -----------------
\usepackage{tikz}
% -----------------

\begin{tikzpicture}
\draw (0,0) rectangle (1,2);
\foreach \y in {0,0.2,...,2} {
  \draw (0,\y)--(1,\y);
}
\foreach \x in {1.8,2.1,...,3.7} {
  \foreach \y in {0.5,0.8,...,1.8} {
    \draw (\x,\y) node{$\bullet$};
  }
}
\end{tikzpicture}
```