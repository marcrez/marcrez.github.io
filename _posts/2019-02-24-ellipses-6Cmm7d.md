---
title: 6Cmm7d
permalink: 6Cmm7d
layout: post
date: 2019-02-24 19:04:10
category: ellipses
---

```latex
% Dans le préambule
% -----------------
\usepackage{pstricks-add}
% -----------------

\begin{pspicture}(0,0)(6,2)
\pspolygon[linecolor=gray](0,0)(1,0)(0.5,2)
\pspolygon[fillstyle=solid, fillcolor=red]
(2,0)(1,1)(2,2)(3,1)
\pspolygon[fillstyle=hlines,showpoints=true]
 (3,0)(4,2)(5,1)
\end{pspicture}
```