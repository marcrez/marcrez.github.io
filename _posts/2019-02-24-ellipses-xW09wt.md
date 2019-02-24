---
title: xW09wt
permalink: xW09wt
layout: post
date: 2019-02-24 19:04:10
category: ellipses
---

```latex
% Dans le préambule
% -----------------
\usepackage{pstricks-add}
% -----------------

\begin{psmatrix}
$G$         & $\mathrm{im}(f)$ \\
$G/\ker(f)$ &                  \\
\end{psmatrix}

\psset{arrows=->,shortput=nab,nodesep=2mm}
\ncline{1,1}{1,2} \naput{$f$}
\ncline{1,1}{2,1} \nbput{$\varphi$}
\ncline[linestyle=dashed]{2,1}{1,2} \nbput{$h$}
```