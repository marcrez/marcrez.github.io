---
title: wDgXXX
permalink: wDgXXX
layout: post
date: 2019-02-24 19:04:10
category: ellipses
---

```latex
\tikzset{
  LabelStyle/.style = { rectangle, rounded corners, draw, fill=white},
  VertexStyle/.append style = { inner sep=5pt},
  EdgeStyle/.append style = {->, bend left} }
\begin{tikzpicture}
  \SetGraphUnit{5}
  \Vertex{B}
  \WE(B){A}
  \Edge[label = 1](A)(B)
  \Edge[label = 4](B)(A)
  \Loop[dist = 4cm, dir = NO, label = 5](A.west)
  \Loop[dist = 4cm, dir = SO, label = 6](B.east)
\end{tikzpicture}
```