---
title: RtM26b
permalink: RtM26b
layout: post
date: 2019-02-24 19:04:10
category: ellipses
---

```latex
% Dans le préambule
% -----------------
\usepackage{pstricks-add}
% -----------------

\psset{yAxis=false}
\begin{pspicture}(0,-1)(4,1)
\psaxes[subticks=2,ticksize=0 0.5](0,0)(0,0)(3.7,0)
\end{pspicture}

\begin{pspicture}(0,-1)(4,1)
\psaxes[subticks=10,ticksize=-0.1 0.2,
                  subticksize=0.5](0,0)(0,0)(3.7,0)
\end{pspicture}
```