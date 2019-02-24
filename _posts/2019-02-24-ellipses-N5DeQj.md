---
title: N5DeQj
permalink: N5DeQj
layout: post
date: 2019-02-24 19:04:10
category: ellipses
---

```latex

\begin{tikzpicture}
 \tikzstyle{ligne} = [draw,thick,-]
 \tikzstyle{plots}=[circle, draw,fill=black, inner sep=0pt]
 \tikzstyle{petit}=[plots, minimum width=3pt]
 \node[petit](A) at (1,0){}; \node[petit](B) at (2,1){};
 \node[petit](C) at (1,2){}; \node[petit](D) at (0,1){};
 \draw (A) -- (B) -- (C) -- (D) -- (A) -- (C);
 \draw (B) -- (D);

\begin{scope}[xshift=1cm, yshift=-2cm]; % on translate
 \tikzstyle{gros}=[plots, minimum width=6pt]
 \node[gros](E) at (0,0){};  \node[gros](F) at (-30:1){};
 \node[gros](G) at (90:1){}; \node[gros](H) at (-150:1){};
 \draw[ligne] (E) -- (F) -- (G) -- (H) -- (E)-- (G);
 \draw[ligne] (F) -- (H);
 \end{scope}
end{tikzpicture}
```