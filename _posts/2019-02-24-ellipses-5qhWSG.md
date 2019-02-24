---
title: 5qhWSG
permalink: 5qhWSG
layout: post
date: 2019-02-24 19:04:10
category: ellipses
---

```latex
% Dans le préambule
% -----------------
\usepackage{tikz}
% -----------------

\begin{tikzpicture}[x=2cm]
\draw(0, 0) --node[above]{Dessus}  (1,1);
\draw(0, 0) --node{Sur}            (1,0);
\draw(0, 0) --node[below]{Dessous} (1,-1);
\draw(1, 1) --node[sloped,above]{dessus}  (2,0);
\draw(1, 0) --node[fill=white]{sur}       (2,0);
\draw(1,-1) --node[sloped,below]{dessous} (2,0);
\end{tikzpicture}
```