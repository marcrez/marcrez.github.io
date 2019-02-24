---
title: QKJRmc
permalink: QKJRmc
layout: post
date: 2019-02-24 19:04:10
category: ellipses
---

```latex
% Dans le préambule
% -----------------
\usepackage{pstricks-add}
% -----------------

\tikzstyle{every picture}+=[remember picture]
\renewcommand{\arraystretch}{2}
\begin{tabular}{|l|c|c|r}               \cline{1-3}
Volume&1&3& \tikz\node(A){}; \\ \cline{1-3}
Poids &2&6& \tikz\node(B){}; \\ \cline{1-3}
\end{tabular}
\begin{tikzpicture}[overlay]
  \draw[->, >=latex] (A.north)
            to[bend left=90]
            node[inner sep=1pt, circle,fill=white,draw]
                {$\times 2$} (B.south);
\end{tikzpicture}
```