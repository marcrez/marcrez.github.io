---
title: 5e7Pgf
permalink: 5e7Pgf
layout: post
date: 2019-02-24 19:04:10
category: ellipses
---

```latex
% Dans le préambule
% -----------------
\usepackage{circuitikz}
% -----------------

\begin{circuitikz}
  \draw (0,2) to[L=$L$] (4,2);
  \draw (4,2) to[switch] (4,0);
  \draw (0,0) to[C=$C$] (4,0);
  \ctikzset{bipoles/length=0.9cm}
  \draw (0,0) to[sV=$E$] (0,2);
  \draw (4,2) to[short] (5,2)
              to[R=$R$] (5,0)
              to[short] (4,0);
\end{circuitikz}
```