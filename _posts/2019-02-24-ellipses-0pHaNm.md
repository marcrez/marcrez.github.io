---
title: 0pHaNm
permalink: 0pHaNm
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
\usetikzlibrary{calc}
% -----------------

\begin{tikzpicture}
\draw(0,0)--(3,1);
\draw($(0,0)!8mm!90:(3,1)$)--($(3,1)!8mm!-90:(0,0)$);
\draw($(0,0)!4mm!-90:(3,1)$)--($(3,1)!4mm!90:(0,0)$);
\end{tikzpicture}
```