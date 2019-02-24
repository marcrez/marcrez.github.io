---
title: wpqNj1
permalink: wpqNj1
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
\draw (0,0)--(1,0)--(0.5,2)--cycle;
\draw[fill=red]
        (2,0)--(1,1)--(2,2)--(3,1)--cycle;
\draw[pattern=north east lines]
               (3,0)--(4,2)--(5,1)--cycle;
\end{tikzpicture}
```