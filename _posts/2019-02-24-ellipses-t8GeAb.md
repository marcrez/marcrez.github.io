---
title: t8GeAb
permalink: t8GeAb
layout: post
date: 2019-02-24 19:04:10
category: ellipses
---

```latex
% Dans le préambule
% -----------------
\usepackage{pstricks-add}
% -----------------

\begin{pspicture}(0,0)(5,3)

\psdots(1,3)  % cartésiennes
\psdots(2;40) % polaires

\psdots[linecolor=red](3,3)
\psdots[dotstyle=o](3,2)
\psdots[dotstyle=square](3,1)
\psdots[dotsize=3mm](4,3)
\psdots[dotstyle=+, dotsize=3mm](4,2)
\psdots[dotstyle=x, dotsize=0.5cm](4,1)

\end{pspicture}
```