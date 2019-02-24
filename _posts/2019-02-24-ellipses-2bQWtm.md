---
title: 2bQWtm
permalink: 2bQWtm
layout: post
date: 2019-02-24 19:04:10
category: ellipses
---

```latex
% Dans le préambule
% -----------------
\usepackage{tikz}
% -----------------

\begin{tikzpicture}[scale=0.7,>=latex]
\draw[->] (-2,0)--(2.5,0);
\draw[->] (0,-2)--(0,3.5);
\foreach \x in {-1,1,2} {
  \draw (\x,1mm)--(\x,-1mm) node[below]{$\x$};
};
\draw (0,-1mm) node[below left]{$0$};

\foreach \y in {-2,...,-1} {
  \draw (1mm,\y)--(-1mm,\y) node[left]{$\y$};};
\foreach \y in {1,...,3} {
  \draw (1mm,\y)--(-1mm,\y) node[left]{$\y$};};
\end{tikzpicture}
```