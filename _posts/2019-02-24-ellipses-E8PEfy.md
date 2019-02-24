---
title: E8PEfy
permalink: E8PEfy
layout: post
date: 2019-02-24 19:04:10
category: ellipses
---

```latex
% Dans le préambule
% -----------------
\usepackage{pstricks-add}
% -----------------

\psset{yunit=2.5cm}
\begin{pspicture}(-2.2,-0.3)(2,1.3)
\psaxes {->}(0,0)(-2.2,-0.3)(2,1.2)
\newcommand{\f}{1/(2^(x^2))}

\pscustom[fillstyle=vlines,linestyle=none]
{
  \psplot[algebraic]{-1}{1}{\f}
  \psline(1,0)(-1,0)
}
\psplot[algebraic]{-2.2}{2}{\f}
\end{pspicture}
```