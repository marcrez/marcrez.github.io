---
title: FP2jx5
permalink: FP2jx5
layout: post
date: 2019-02-24 19:04:10
category: ellipses
---

```latex
% Dans le préambule
% -----------------
\usepackage{tikz}
% -----------------

\begin{tikzpicture}[scale=0.2]
\draw (-2,0) -- (2,0);
\draw (0,-2) -- (0,2);
\draw (1,3mm) -- (1,-3mm) node[below] {$1$};
% La courbe
\draw[domain= -2:-0.2] plot (\x, {1/\x} );
\draw[domain=0.2:2   ] plot (\x, {1/\x} );
\end{tikzpicture}
```