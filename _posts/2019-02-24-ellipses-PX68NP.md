---
title: PX68NP
permalink: PX68NP
layout: post
date: 2019-02-24 19:04:10
category: ellipses
---

```latex
% Dans le préambule
% -----------------
\usepackage{pstricks-add}
% -----------------

\psset{xunit=0.5}
\begin{pspicture}(0,0)(1,8)
\multido{\i=0+1}{9}{
  \psdots(\i,0)
  \uput[90](\i,0){\i}
}
\end{pspicture}
```