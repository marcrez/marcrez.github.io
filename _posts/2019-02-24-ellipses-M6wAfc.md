---
title: M6wAfc
permalink: M6wAfc
layout: post
date: 2019-02-24 19:04:10
category: ellipses
---

```latex
% Dans le préambule
% -----------------
\usepackage{tikz}
% -----------------

\begin{tikzpicture}[>=latex]
\draw[->] (-1,0)--(2,0)   node[below]{$x$};
\draw[->] (0,-1)--(0,1.5) node[left]{$y$};

\draw (-1,0.1)--(-1,-0.1) node[below]{$-1$}
      ( 1,0.1)--( 1,-0.1) node[below]{$1$};
\draw (0.1,-1)--(-0.1,-1) node[left]{$-1$}
      ( 0.1,1)--(-0.1, 1) node[left]{$1$};

\draw (0,-0.1) node[below left]{$0$};
\end{tikzpicture}
```