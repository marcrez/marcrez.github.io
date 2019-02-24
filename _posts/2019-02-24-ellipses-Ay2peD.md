---
title: Ay2peD
permalink: Ay2peD
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
\pscircle(1,1){0.75}
\psarc[linecolor=red,arrows=->]
(1,1){0.9}{-45}{45}

\pswedge(3,1){0.8}{45}{-45}
\pswedge[fillstyle=solid, fillcolor=red]
(3.2,1){0.8}{-45}{45}
\end{pspicture}
```