---
title: T9S9Fs
permalink: T9S9Fs
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

\begin{tabular}{|l|c|c|r}            \cline{1-3}
Volume&1&3&\rnode{A}{\vphantom{A}}\\ \cline{1-3}
Poids &2&6&\rnode{B}{\vphantom{B}}\\ \cline{1-3}
\end{tabular}

\ncangle[linearc=0.3,
         arm=7mm,arrowsize=2mm]{->}{A}{B}
\naput[labelsep=-1.5em]{
\psovalbox[fillstyle=solid, fillcolor=white]
          {$\times 2$}}
```