---
title: A2f0is
permalink: A2f0is
layout: post
date: 2019-02-24 19:04:10
category: ellipses
---

```latex
% Dans le préambule
% -----------------
\usepackage{pstricks-add,pst-eucl}
% -----------------

% g(x)=(x^3)/3+x+2/3 en RPN :
\newcommand{\f}{x 3 exp 3 div x sub 2 3 div add}
% h(x)=x^2 en RPN :
\newcommand{\g}{x 2 exp}

\begin{pspicture*}(-2.2,-0.5)(2.5,2)
\psaxes[labels=none]{->}(0,0)(-2.2,-0.5)(2.5,2)
\psplot{-2.2}{2}{\f}
\psplot{-2.2}{2}{\g}

\pstInterFF[PosAngle=90]{\f}{\g}{1}{P}
\pstInterFF[PosAngle=45]{\f}{\g}{-1}{M_0}
\end{pspicture*}
```