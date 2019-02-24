---
title: JArTit
permalink: JArTit
layout: post
date: 2019-02-24 19:04:10
category: ellipses
---

```latex
% Dans le préambule
% -----------------
\usepackage{pst-optic}
% -----------------

\psset{unit=0.3, drawing=false,lensWidth=2}
\begin{pspicture*}(-5,-3)(4,3)
\rput(0,0){\lens[XO=-4]}
\rput(0,0){\lens[XO=-2,lensType=PCVG]}
\rput(0,0){\lens[XO=1,lensType=DVG]}
\rput(0,0){\lens[XO=3,lensType=PDVG]}
\end{pspicture*}
```