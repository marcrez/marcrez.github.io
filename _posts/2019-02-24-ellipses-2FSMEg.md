---
title: 2FSMEg
permalink: 2FSMEg
layout: post
date: 2019-02-24 19:04:10
category: ellipses
---

```latex
% Dans le préambule
% -----------------
\usepackage{pstricks-add}
% -----------------

\psset{unit=1cm}
\begin{pspicture}(-3,-1)(3,2)
% un quadrillage sous les axes:
\psgrid[subgriddiv=4,subgridcolor=lightgray,
        gridlabels=0,gridcolor=gray](-3,-1)(1,2)
\psaxes(0,0)(-3,-1)(1,2)
\psset{showpoints=true,dotsize=1.5mm}
% la courbe définie par 4 points :
\pscurve(-3,0)(-2,1.5)(0,0)(1,1)
\end{pspicture}
```