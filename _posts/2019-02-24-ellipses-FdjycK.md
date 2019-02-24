---
title: FdjycK
permalink: FdjycK
layout: post
date: 2019-02-24 19:04:10
category: ellipses
---

```latex
\begin{tikzpicture}[scale=1.5]
\draw[->, thick] (-1.3,0) -- (1.3,0);
\draw[->, thick] (0,-1.3) -- (0,1.3);
\foreach \x in {-1,1}
  \draw (\x,1mm)--(\x,-1mm) node[below]{$\x$};
\foreach \y in {-1,1}
  \draw (1mm,\y)--(-1mm,\y) node[left] {$\y$};

\draw[domain=0:360,samples=400,smooth]
      plot ({sin(5*\x)},{sin(6*\x)});
```