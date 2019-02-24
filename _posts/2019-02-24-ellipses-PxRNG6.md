---
title: PxRNG6
permalink: PxRNG6
layout: post
date: 2019-02-24 19:04:10
category: ellipses
---

```latex
\begin{tikzpicture}
\tikzstyle{noir}=[circle, draw, fill=black, inner sep=0pt, minimum width=6pt]
\tikzstyle{blanc}=[circle, draw, inner sep=0pt, minimum width=6pt]
\tikzstyle{fleche} = [draw,thick,->,>=latex]

% Les deux noeuds blancs
\node[blanc] (A) at (0,0)
               [label=left:$A$] {};
\node[blanc] (F) at (3,-1)
               [label=below right:$F$] {};

% Les noeuds noirs
\foreach \pos/\name in {(1,1)/B, (2,0)/C,
                        (1,-1)/D, (3,1)/E}
  \node[noir] (\name) at \pos {};

% Les connexions
\foreach \orig/\dest in {A/B, A/D, B/C, C/D, C/E, D/B, E/B, E/F, F/C}
  \draw[fleche] (\orig) -- (\dest);
\end{tikzpicture}
```