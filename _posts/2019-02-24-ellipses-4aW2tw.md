---
title: 4aW2tw
permalink: 4aW2tw
layout: post
date: 2019-02-24 19:04:10
category: ellipses
---

```latex
% Dans le préambule
% -----------------
\usepackage{array}
% -----------------

\newcolumntype{H}{>{deb.}c<{.fin}}

\begin{tabular}{|c|H|c|} \hline
A & B & C \\ \hline
1 & 2 & 3 \\ \hline
x & y & z \\ \hline
\end{tabular}
```