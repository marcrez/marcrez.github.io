---
title: pTraxA
permalink: pTraxA
layout: post
date: 2019-02-24 19:04:10
category: ellipses
---

```latex
\begin{tikzpicture}
\draw[step=.25cm,lightgray,very thin]
     (-3,-1) grid (1,2);
\draw[->, thick] (-3,0) -- (1,0);
\draw[->, thick] (0,-1) -- (0,2);
\foreach \x in {-3,-2,-1,1} {
  \draw (\x,1mm)--(\x,-1mm) node[below] {$\x$};
}
\foreach \y in {-1,1}
\draw (1mm,\y) -- (-1mm,\y) node[left] {$\y$};
\draw plot[mark=*,mark size=0.6mm,smooth]
      coordinates {(-3,0) (-2,1.5) (0,0) (1,1)};
\end{tikzpicture}
```