---
title: RY2QRg
permalink: RY2QRg
layout: post
date: 2019-02-24 19:04:10
category: ellipses
---

```latex
% Dans le préambule
% -----------------
\usepackage{pstricks-add}
% -----------------

\psset{unit=0.666cm}  % Echelle 1/3

\begin{pspicture}(-3,0)(3.5,3.5)
\pspolygon(!0 0)(!0 2 sqrt 2 add)
                (!2 sqrt 2 add 0)
\pscircle[linecolor=gray](!1 1){1}
\end{pspicture}
```