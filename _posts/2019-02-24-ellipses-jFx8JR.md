---
title: jFx8JR
permalink: jFx8JR
layout: post
date: 2019-02-24 19:04:10
category: ellipses
---

```latex
% Dans le préambule
% -----------------
\usepackage{pstricks-add}
% -----------------

\begin{pspicture}(0,0)(6,2)
\pspolygon(1,0)(2,2)(3,2)(4,0)

\pcline(2,2)(3,2)
\naput{L1}

\pcline(1,0)(4,0)
\nbput{L2}

\pcline[offset=5mm,arrows=<->](1,0)(2,2)
\ncput*{$H_1$}

\pcline[offset=4mm,arrows=|-|](3,2)(4,0)
\naput*[nrot=:U]{$x$}

\end{pspicture}
```