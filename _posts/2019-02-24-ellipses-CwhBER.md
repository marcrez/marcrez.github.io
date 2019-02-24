---
title: CwhBER
permalink: CwhBER
layout: post
date: 2019-02-24 19:04:10
category: ellipses
---

```latex
% Dans le préambule
% -----------------
\usepackage{pstricks-add}
% -----------------

\psset{xunit=1cm,yunit=0.5cm}
\begin{pspicture}(-1.5,-1)(3.5,4.5)

\psaxes(0,0)(-1.5,-0.5)(3.5,4.5)
\psplot[algebraic]{-1.1}{3.1}{ (1+x)*(3-x) }

% PLace le point A et les pointills
\psdots(2,3) \uput[45](2,3){$A$}
\psline[linestyle=dotted](2,0)(2,3)(0,3)

\end{pspicture}
```