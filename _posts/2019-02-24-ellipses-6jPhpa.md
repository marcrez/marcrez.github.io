---
title: 6jPhpa
permalink: 6jPhpa
layout: post
date: 2019-02-24 19:04:10
category: ellipses
---

```latex
% Dans le préambule
% -----------------
\usepackage{pstricks-add}
% -----------------

\begin{pspicture}(0,0)(4,2)
\psline[linestyle=dashed](0,0)(1,2)
\psline[arrows=->](1,0)(2,2)(3,1)
\psline[arrows=|->,linewidth=0.8mm](3,0)(4,2)
\psline[arrows={[-]},linecolor=blue](3,2)(4,0)
\end{pspicture}
```