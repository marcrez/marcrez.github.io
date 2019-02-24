---
title: QtXSQR
permalink: QtXSQR
layout: post
date: 2019-02-24 19:04:10
category: ellipses
---

```latex
% Dans le préambule
% -----------------
\usetikzlibrary{trees}
% -----------------

\begin{tikzpicture}[level distance=3cm, sibling distance=0.7cm]
\tikzstyle{every node}=[draw=black]
\node {George VI} [edge from parent fork right,grow'=right]
    child { node {Margaret}}
    child { node {Elisabeth II}
      child { node {Charles}}
      child { node {Anne}}
      child { node {Andrew}}
      child { node {Edouard}}
    };
\end{tikzpicture}
```