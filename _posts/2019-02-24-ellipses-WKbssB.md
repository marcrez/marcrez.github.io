---
title: WKbssB
permalink: WKbssB
layout: post
date: 2019-02-24 19:04:10
category: ellipses
---

```latex
% Dans le préambule
% -----------------
\usepackage{pstricks-add}
% -----------------

\psset{unit=1.5cm,plotpoints=200}
\begin{pspicture*}(-1.6,-1.3)(1.6,1.3)

\psaxes(0,0)(-1.6,-1.3)(1.6,1.3)

\parametricplot[algebraic]{0}{6.28}{sin(5*t) | sin(6*t)}

\end{pspicture*}
```