---
title: IFkHJc
permalink: IFkHJc
layout: post
date: 2019-02-24 19:04:10
category: ellipses
---

```latex
% Dans le préambule
% -----------------
\usepackage{tikz}
% -----------------

\begin{tikzpicture}[x=3cm,y=3cm]
\foreach \a in {0,1,...,180} {
  \draw (\a:1) -- (\a:0.85);
}
\foreach \a in {10,20,...,170}{
  \draw[thick](\a:1)--(\a:0.8);
  \draw (\a:0.75) node{\tiny \a};
}
\draw(1,0) arc (0:180:1) -- cycle;
\draw (0,0) node{$\circ$};
\end{tikzpicture}
```