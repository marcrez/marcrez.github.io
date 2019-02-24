---
title: EX65xq
permalink: EX65xq
layout: post
date: 2019-02-24 19:04:10
category: ellipses
---

```latex
% Dans le préambule
% -----------------
\usepackage{pstricks-add}
% -----------------

\savedata{\donnees}[{1,30},{2,17},{3,34},
                    {4,46},{5,41},{6,10}]
\psset{xunit=0.6,yunit=0.06}
\begin{pspicture}(-1,-10)(6,50)
  \psaxes[Dy=10]{->}(0,0)(0,0)(6,50)
\dataplot[plotstyle=line]{\donnees}
\dataplot[plotstyle=dots]{\donnees}
\dataplot[plotstyle=bar,
             barwidth=0.5]{\donnees}
\end{pspicture}
```