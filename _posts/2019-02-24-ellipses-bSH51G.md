---
title: bSH51G
permalink: bSH51G
layout: post
date: 2019-02-24 19:04:10
category: ellipses
---

```latex
% Dans le préambule
% -----------------
\usepackage{pstricks-add}
% -----------------

\begin{pspicture}(-1,-1)(6,1)
\begin{psmatrix}[mnode=circle,colsep=3]
A & B
\end{psmatrix}
\psset{arrows=->}
\ncarc[arcangle=20]{1,1}{1,2}  \naput{$1-x$}
\ncarc[arcangle=20]{1,2}{1,1}  \naput{$1-y$}
\nccircle[angleA=90]{1,1}{.5}
                      \nbput[npos=0.25]{$x$}
\nccircle[angleA=-90]{1,2}{.5}
                      \nbput[npos=0.75]{$y$}
\end{pspicture}
```