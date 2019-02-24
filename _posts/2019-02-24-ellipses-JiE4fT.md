---
title: JiE4fT
permalink: JiE4fT
layout: post
date: 2019-02-24 19:04:10
category: ellipses
---

```latex
% Dans le préambule
% -----------------
\usepackage{pstricks-add}
% -----------------

\begin{pspicture}(-2,-1)(1,2)

\psaxes{->}(0,0)(-2,-1)(1.5,2)     % le repère
\psplot[algebraic]{-1.5}{1}{x^2+x} % la courbe

\end{pspicture}
```