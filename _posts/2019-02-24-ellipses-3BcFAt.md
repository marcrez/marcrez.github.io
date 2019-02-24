---
title: 3BcFAt
permalink: 3BcFAt
layout: post
date: 2019-02-24 19:04:10
category: ellipses
---

```latex
% Dans le préambule
% -----------------
\usetikzlibrary{shapes,shadows}
% -----------------

\begin{tikzpicture}[grow=down,
                    level distance=3cm]
\node[draw, circle, fill=black] {}
 child { node[draw, diamond] {A}}
 child { node[draw, circle] {B}}
 child { node[draw, regular polygon,
              regular polygon sides=5]{C}}
 child { node[draw, rectangle] {D}}
 child { node[draw, rectangle, white,
              fill=black!75, rounded corners,
              drop shadow] {E}};
\end{tikzpicture}
```