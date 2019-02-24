---
title: cimyBC
permalink: cimyBC
layout: post
date: 2019-02-24 19:04:10
category: ellipses
---

```latex
% Dans le préambule
% -----------------
\usepackage{pstricks-add,pst-eucl}
% -----------------

\begin{pspicture}(-2,-1)(5,3)
% \psset{PointSymbol=none, yunit=0.5cm}
\psset{yunit=0.5cm}
% Les points B, C et D
\pstGeonode[PosAngle=45](4,-0.5){B}
\pstGeonode[PosAngle=90](3,1){C}
\pstGeonode[PosAngle=-45](2,0){D}
% Premiere homothetie
\pstHomO[HomCoef=2,PosAngle=90]{B}{C}[O]
\pstHomO[HomCoef=2,PosAngle=-45]{B}{D}[A]
% Seconde homothetie
\pstHomO[HomCoef=2,PosAngle=135]{A}{O}[E]
\pstHomO[HomCoef=2,PosAngle=45]{B}{O}[F]
% Segments
\pstLineAB[nodesep=-1]{B}{F}
\pstLineAB[nodesep=-1]{A}{E}
\pstLineAB[nodesep=-1]{E}{F}
\pstLineAB[nodesepA=-2,nodesepB=-0.6]{A}{B}
\pstLineAB[nodesepA=-0.2,nodesepB=-1]{D}{C}
\end{pspicture}
```