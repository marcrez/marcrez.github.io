---
title: igcc07
permalink: igcc07
layout: post
date: 2019-02-24 19:04:10
category: ellipses
---

```latex
% Dans le préambule
% -----------------
\usepackage{tikz}
% -----------------

\begin{tikzpicture}[xscale=20,xshift=34]
\draw (0.7,0)--(0.9,0);
\foreach \x/\val in { {0.7/34,7},{0.8/34,8},{0.9/34,9}} {
  \draw[thick] (\x,5mm)--(\x,0)
  node[below]{$\val$};
};
\foreach \x in {0.7,0.71,...,0.9} {
  \draw (\x,2mm)--(\x,0);
};
\draw (0.75,0) node{$\bullet$} node[below]{$A$};
\draw (0.86,0) node{$\bullet$} node[below]{$B$};
\end{tikzpicture}
```