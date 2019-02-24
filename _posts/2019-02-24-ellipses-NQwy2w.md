---
title: NQwy2w
permalink: NQwy2w
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
\draw[->] (-2,0)--(1,0);
\draw[->] (0,-1)--(0,2);

% La courbe
\draw[domain=-1.5:1] plot (\x, {(\x)^2+\x} );
\end{tikzpicture}
```