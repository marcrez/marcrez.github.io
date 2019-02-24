---
title: 2TmjA6
permalink: 2TmjA6
layout: post
date: 2019-02-24 19:04:10
category: ellipses
---

```latex
% Dans le préambule
% -----------------
\usepackage{pstricks-add}
% -----------------

\psset{unit=0.9cm}
\begin{pspicture*}(-3,-3)(3,3)

\psaxes[axesstyle=polar, labels=y,
        labelFontSize=\scriptstyle](2,361)

\psplot[polarplot,algebraic,linewidth=2pt]
                         {0}{9.32}{3*cos(x/3)}

\end{pspicture*}
```