---
title: ABSsde
permalink: ABSsde
layout: post
date: 2019-02-24 19:04:10
category: ellipses
---

```latex
% Dans le préambule
% -----------------
\usepackage{pstricks-add}
% -----------------

\psset{yunit=4cm}
\begin{pspicture}(-2,-0.3)(2,1.1)
\psaxes[labels=none,ticks=x](0,0)(-2,-0.3)(2,1.1)
\newcommand{\f}{(cos(2*\psPi*x))^2/(x^2+1)}

\psplot[plotpoints=40,linecolor=red]{-2}{0}{\f}
\psplot[linewidth=2pt,plotpoints=300]{0}{2}{\f}
\end{pspicture}
```