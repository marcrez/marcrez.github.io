---
title: aa81ny
permalink: aa81ny
layout: post
date: 2019-02-24 19:04:10
category: ellipses
---

```latex
% Dans le préambule
% -----------------
\usepackage{pstricks-add,pst-eucl}
% -----------------

\begin{pspicture}(-1,-1)(5,3)
\psset{PointSymbol=none}
% Les points A, B et C
\pstTriangle(0,0){A}(3.5,0){B}(1,2){C}
% Les points E, D et F
\pstHomO[HomCoef=0.7,PosAngle=90]{B}{C}[E]
\pstProjection{A}{B}{E}[D]
\pstProjection{B}{C}{D}[F]
% Segments
\pspolygon(A)(B)(C)
\psline(E)(D)(F) \psline(C)(D)
% Marquages
\pstRightAngle[RightAngleSize=0.2]{E}{D}{A}
\pstRightAngle[RightAngleSize=0.2]{E}{F}{D}
\pstSegmentMark[SegmentSymbol=pstslashh]{C}{A}
\pstSegmentMark[SegmentSymbol=pstslashh]{C}{D}
\end{pspicture}
```