---
title: eNhHsi
permalink: eNhHsi
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
\draw (-1,0) grid[step=0.25] (3,2);
\foreach \x in {-1,0,1,2,3} {
  \draw (\x,0) node[below]{$\x$}; };
\foreach \y in {0,1,2} {
  \draw (-1,\y) node[left]{$\y$}; };
\end{tikzpicture}
```