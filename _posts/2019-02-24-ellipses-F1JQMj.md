---
title: F1JQMj
permalink: F1JQMj
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
  \clip(-1.5,-0.1) rectangle (3.5,2.1);
  \draw[gray] (-1,0) grid (3,2);
  \draw[gray,very thin] (-1,0) grid[step=0.1] (3,2);
\end{tikzpicture}
```