---
title: ppbPhE
permalink: ppbPhE
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
\draw (1,3) node {$\bullet$}; % cartésiennes
\draw (40:2) node{$\bullet$}; % polaires

\draw (3,3) node {$\red\bullet$};
\draw (3,2) node {$\circ$};
\draw (3,1) node {$\Box$};
\draw (4,3) node[scale=2]{$\bullet$};
\draw (4,2) node[scale=2]{$+$};
\draw (4,1) node[scale=3]{$\times$};
\end{tikzpicture}
```