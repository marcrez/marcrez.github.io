---
title: I7GrBW
permalink: I7GrBW
layout: post
date: 2019-02-24 19:04:10
category: ellipses
---

```latex
\begin{tikzpicture}[grow'=right,level distance=2cm, sibling distance=1cm,->]

\node {A}
  child { node {B}}
  child { node {C}}
  child { node {D}
            child { node {E}}
            child { node {F}}
        };
\end{tikzpicture}
```