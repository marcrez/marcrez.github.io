---
title: RbaxkS
permalink: RbaxkS
layout: post
date: 2019-02-24 19:04:10
category: ellipses
---

```latex
\begin{tikzpicture}[xscale=0.6,yscale=0.06]
\draw[<->] (0,45)--(0,0)--(7,0);
\foreach \x in {1,2,...,6}
  \draw (\x,-4) node{\x};
\foreach \y in {0,10,...,40}
  \draw (1mm,\y)--(-1mm,\y) node[left]{\y};

\newcommand{\donnees}
       {(1,30)(2,17)(3,34)(4,46)(5,41)(6,10)}

\draw[line width=0.5cm,color=gray]
      plot[ycomb]  coordinates {\donnees};
\draw plot[mark=*] coordinates {\donnees};
\end{tikzpicture}
```