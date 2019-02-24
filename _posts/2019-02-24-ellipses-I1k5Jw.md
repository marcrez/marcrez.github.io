---
title: I1k5Jw
permalink: I1k5Jw
layout: post
date: 2019-02-24 19:04:10
category: ellipses
---

```latex
% Dans le préambule
% -----------------
\usepackage{tikz}
% -----------------

\begin{tikzpicture}[x=0.5cm]
\foreach \x in {0,1,...,8} {
\draw (\x,1mm) node{$\bullet$} node[above]{\x};
}
```