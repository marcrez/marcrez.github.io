---
title: iQhsqb
permalink: iQhsqb
layout: post
date: 2019-02-24 19:04:10
category: ellipses
---

```latex
% Dans le préambule
% -----------------
\usepackage{pstricks-add}
% -----------------

\begin{pspicture}(-2,-1)(3.5,1.5)
\psset{xunit=0.5}
\psaxes[trigLabels=true,dx=3.1416]
                             (0,0)(-4,-1)(7,1.5)
\psplot[algebraic,linewidth=2pt ]{-4}{7}{cos(x)}
\psplot[algebraic,linecolor=gray]{-4}{7}{sin(x)}
\end{pspicture}
```