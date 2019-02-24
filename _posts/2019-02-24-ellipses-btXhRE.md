---
title: btXhRE
permalink: btXhRE
layout: post
date: 2019-02-24 19:04:10
category: ellipses
---

```latex
% Dans le préambule
% -----------------
\usepackage{tikz}
% -----------------

\begin{tikzpicture}[xscale=0.4,domain=-4:7]
\draw[->] (-4,0) -- (7,0) node[right] {$x$};
\draw[->] (0,-1) -- (0,1.5) node[above] {$y$};
\foreach \x/\xtext in {-1/-\pi,1/\pi,2/2\pi} {
  \draw (3.14*\x,1mm) --
        (3.14*\x,-1mm) node[below]{$\xtext$}; }
\foreach \y in {-1,1}
  \draw (1mm,\y)--(-1mm,\y) node[left]{$\y$};
\draw plot[smooth] (\x, {sin(\x r)} );
\draw[line width=2pt,smooth]
      plot (\x, {cos(\x r)} );
\end{tikzpicture}
```