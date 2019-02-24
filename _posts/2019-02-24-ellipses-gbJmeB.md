---
title: gbJmeB
permalink: gbJmeB
layout: post
date: 2019-02-24 19:04:10
category: ellipses
---

```latex
\begin{tikzpicture}[bend angle=25, scale=2]
\tikzstyle{vide}=[inner sep=0pt, minimum width=0pt]

\foreach \a [count = \noeud] in {0,51.429,...,360}
  \node[vide] (\noeud) at (\a:1) {};

\foreach \orig in {1,...,7}
  \foreach \dest in {1,...,7}
    \draw (\orig) to[bend right] (\dest);

\end{tikzpicture}
```