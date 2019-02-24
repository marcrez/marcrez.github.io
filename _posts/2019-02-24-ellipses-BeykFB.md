---
title: BeykFB
permalink: BeykFB
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
usetikzlibrary{calc}
% -----------------

\begin{tikzpicture}
\draw (-1,0) grid (3,3);
\foreach \y in {0,1,2} {
  \foreach \yy in {1,2,...,10}
    \draw (-1,{\y+ln(\yy)/ln(10)})
        --(3,{\y+ln(\yy)/ln(10)});
}
\foreach \x in {-1,0,1,2,3}
  \draw (\x,0) node[below]{$\x$};
\foreach \y in {0,1,2,3}
  \draw (-1,\y) node[left]{$10^\y$};
\end{tikzpicture}
```