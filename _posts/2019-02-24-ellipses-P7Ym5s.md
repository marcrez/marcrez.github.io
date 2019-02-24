---
title: P7Ym5s
permalink: P7Ym5s
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
  \draw (0,0)--(1,1)--(0,1)--(1,0);

\begin{scope}[xshift=1.5cm,scale=0.5]
  \draw (0,0)--(1,1)--(0,1)--(1,0);
\end{scope}

\begin{scope}[xshift=2.5cm,yshift=1cm,x=0.6cm,y=-2cm]
  \draw (0,0)--(1,1)--(0,1)--(1,0);
\end{scope}
\end{tikzpicture}
```