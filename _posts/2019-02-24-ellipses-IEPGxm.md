---
title: IEPGxm
permalink: IEPGxm
layout: post
date: 2019-02-24 19:04:10
category: ellipses
---

```latex
% Dans le préambule
% -----------------
\usepackage{pstricks-add}
% -----------------

\begin{pspicture}(-3,-3)(3,3)
\psChart{44,28,19,5,4}{}{2}
\rput(psChartI1){\small \white Pacifique}
\rput(psChartI2){\small \white Atlantique}
\rput(psChartI3){\small \white Indien}
\rput(psChartI4){\small \white Austral}
\rput(psChartI5){\small Arctique}
\end{pspicture}
```