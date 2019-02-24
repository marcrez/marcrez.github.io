---
title: nPeKPt
permalink: nPeKPt
layout: post
date: 2019-02-24 19:04:10
category: ellipses
---

```latex
% Dans le préambule
% -----------------
\usepackage{pstricks-add}
% -----------------

\begin{pspicture}(0,0)(4,2)
\pnode(2,3){A} \pnode(0,0){B}
\pnode(2,0){H} \pnode(3,0){C}
\pspolygon(A)(B)(C)
\psline[linestyle=dashed](A)(H)
\uput[90]{N}(A){$A$} \uput[180]{N}(B){$B$}
\uput[-45]{N}(H){$H$} \uput[0]{N}(C){$C$}
\rput(H){ \psframe(0,0)(0.2;45) }
\pcline[offset=-3mm]{<->}(B)(H) \ncput*{4}
\psset{linestyle=none}
\pcline(B)(A) \naput{$4\sqrt2$}
\pcline(A)(C) \naput{$2\sqrt5$}
\pcline(B)(H) \ncput[nrot=:U]{\small //}
\pcline(H)(A) \ncput[nrot=:U]{\small /}
\end{pspicture}
```