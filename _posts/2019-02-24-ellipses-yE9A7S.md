---
title: yE9A7S
permalink: yE9A7S
layout: post
date: 2019-02-24 19:04:10
category: ellipses
---

```latex
% Dans le préambule
% -----------------
\usepackage{tikz}
% -----------------

% Dans le préambule
% -----------------
\usetikzlibrary{patterns}
% -----------------

\begin{tikzpicture}[xscale=0.98,yscale=2.5]

\fill[pattern=north east lines]
plot [domain=-1:1] (\x, {(2^(-\x*\x))} )
-- (1,0) -- (-1,0) -- cycle;

\draw[->,>=latex] (-2.2,0) -- (2,0);
\draw[->,>=latex] (0,-0.2) -- (0,1.2);
\foreach \x in {-2,-1,1}
 \draw(\x,0.3mm)--(\x,-0.3mm) node[below]{$\x$};

\draw (1mm,1)--(-1mm,1) node[above left]{$1$};
\draw[domain=-2.2:2] plot (\x, {(2^(-\x*\x))} );
\end{tikzpicture}
```