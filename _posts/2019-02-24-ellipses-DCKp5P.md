---
title: DCKp5P
permalink: DCKp5P
layout: post
date: 2019-02-24 19:04:10
category: ellipses
---

```latex
% Dans le préambule
% -----------------
\usepackage{pstricks-add}
% -----------------

\newcommand{\f}{(0.3*x)^3-0.3*x} % def fontion
\psset{algebraic,xunit=0.66cm,yunit=3cm}
\begin{pspicture}(-3.5,-0.5)(3.5,0.5)
\psaxes(0,0)(-3.5,-0.5)(3.5,0.5)
\psplot{-3.1}{2.9}{\f}           % trace courbe
\psset{arrows=<->,linewidth=1pt}
\psplotTangent{-2}{1}{\f}        % tangente 1
\psplotTangent{1.5}{1}{\f}       % tangente 2
\end{pspicture}
```