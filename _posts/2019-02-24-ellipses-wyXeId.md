---
title: wyXeId
permalink: wyXeId
layout: post
date: 2019-02-24 19:04:10
category: ellipses
---

```latex
% Dans le préambule
% -----------------
\usepackage{pstricks-add}
% -----------------

\begin{pspicture}(0,0)(5,2)
\psline(0,0)(4,1) % Référence
\pcline[offset= 8mm](0,0)(4,1) % +8mm
\pcline[offset=-4mm](0,0)(4,1) % -4mm
\end{pspicture}
```