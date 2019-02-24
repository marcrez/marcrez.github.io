---
title: 4bMIrW
permalink: 4bMIrW
layout: post
date: 2019-02-24 19:04:10
category: ellipses
---

```latex
% Dans le préambule
% -----------------
\usepackage{tikz}
% -----------------

\begin{tikzpicture}[xscale=10]
\draw (3.3,0)--(3.7,0);
\foreach \x in {3.3,3.4,...,3.7} {
  \draw[thick] (\x,5mm)--(\x,0)
  node[below]{$\pgfmathprintnumber\x$}; };
\foreach \x in {3.3,3.31,...,3.7} {
  \draw (\x,2mm)--(\x,0); };
\end{tikzpicture}
```