---
title: DxFnp2
permalink: DxFnp2
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
\draw (0,1/2) ellipse (1.5 and 0.25);
\draw (-1.5,-0.5) -- (-1.5,0.5);
\draw (1.5,-0.5) -- (1.5,0.5);
\draw (-1.5,-1/2) arc (-180:0:1.5 and 0.25);
\draw [dotted] (1.5,-1/2) arc (0:180:1.5 and 0.25);
\end{tikzpicture}
```