---
title: hJyyTh
permalink: hJyyTh
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
\psellipse(2,1.5)(1.5,0.25)
\psellipticarc[linestyle=dotted]
(2,0.5)(1.5,0.25){0}{180}
\psellipticarc(2,0.5)(1.5,0.25){180}{0}
\psline(0.5,0.5)(0.5,1.5)
\psline(3.5,0.5)(3.5,1.5)
\end{pspicture}
```