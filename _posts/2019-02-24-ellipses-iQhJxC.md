---
title: iQhJxC
permalink: iQhJxC
layout: post
date: 2019-02-24 19:04:10
category: ellipses
---

```latex
% Dans le préambule
% -----------------
\usepackage{pstricks-add}
% -----------------

\renewcommand{\arraystretch}{2}

\tikzstyle{every picture}+=[remember picture]
\begin{tabular}{|l|c|c|r}     \cline{1-3}
Volume&1&3& \tikz\node(A){}; \\ \cline{1-3}
Poids &2&6& \tikz\node(B){}; \\ \cline{1-3}
\end{tabular}

\begin{tikzpicture}[overlay]
  \draw[->](A) -|  node[right, very near end]
                       {$\times 2$} (B) ;
\end{tikzpicture}
```