---
title: rn3qJ1
permalink: rn3qJ1
layout: post
date: 2019-02-24 19:04:10
category: ellipses
---

```latex
% Dans le préambule
% -----------------
\usepackage{tikz}
% -----------------

\begin{tikzpicture}[scale=1]
\clip (0,0) ellipse (2 and 1);
\draw (0,0) ellipse (2 and 1);
\draw (-2,-2) grid[step=0.1] (2,2);
\end{tikzpicture}
```