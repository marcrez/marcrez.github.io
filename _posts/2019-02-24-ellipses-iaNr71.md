---
title: iaNr71
permalink: iaNr71
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
\draw[dashed] (0,0)--(1,2);
\draw[->] (1,0)--(2,2)--(3,1);
\draw[line width=2pt, |->] (3,0)--(4,2);
\draw[{[-]},blue]  (4,0)--(3,2);
\end{tikzpicture}
```