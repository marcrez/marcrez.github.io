---
title: RXrdjt
permalink: RXrdjt
layout: post
date: 2019-02-24 19:04:10
category: ellipses
---

```latex
% Dans le préambule
% -----------------
\usepackage{pstricks-add}
% -----------------

\psset{xunit=2}
\pcline(0, 0)(1, 1) \naput{Dessus}
\pcline(0, 0)(1, 0) \ncput{Sur}
\pcline(0, 0)(1,-1) \nbput{Dessous}
\pcline(1, 1)(2, 0) \naput[nrot=:U]{dessus}
\pcline(1, 0)(2, 0) \ncput*[nrot=:U]{sur}
\pcline(1,-1)(2, 0) \nbput[nrot=:U]{dessous}
```