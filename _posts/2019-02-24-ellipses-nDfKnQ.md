---
title: nDfKnQ
permalink: nDfKnQ
layout: post
date: 2019-02-24 19:04:10
category: ellipses
---

```latex
\begin{tikzpicture}[bend angle=20]
  \tikzstyle{dblanc}=[circle, draw, inner sep=0pt, minimum width=6pt]
  \node[dblanc] (A) at (0,0) {};
  \node[dblanc] (B) at (1,1) {};
  \node[dblanc] (C) at (0,1.5) {};
  \node[dblanc] (D) at (-1,1) {};
  \draw (A) to[bend right] (B);
  \draw (A) to[bend right] (D);
  \draw (A) -- (C);
  \draw (B) to[bend right] (A);
  \draw (B) to[bend right=60] (C);
  \draw (D) to[bend right] (A);
  \draw (D) to[bend left=60] (C);
\end{tikzpicture}
```