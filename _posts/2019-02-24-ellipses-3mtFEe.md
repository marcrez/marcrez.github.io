---
title: 3mtFEe
permalink: 3mtFEe
layout: post
date: 2019-02-24 19:04:10
category: ellipses
---

```latex
\begin{tikzpicture}[scale=0.5]
\foreach \a in {0,30,...,330} {
  \draw[lightgray,thin] (0,0)--(\a:3);
 \draw (\a:3.4) node{\a}; }
\foreach \r in {1,2,3}
\draw[lightgray,thin]  (0,0) circle(\r);

\draw[domain=0:540,samples=200,line width=2pt]
plot (xy polar cs:angle =\x,
                  radius={3*cos(\x/3)});

```