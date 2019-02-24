---
title: 6Eqy8N
permalink: 6Eqy8N
layout: post
date: 2019-02-24 19:04:10
category: ellipses
---

```latex
% Dans le préambule
% -----------------
\usepackage{pstricks-add}
% -----------------

\psset{yunit=3cm,algebraic,plotpoints=200}
\begin{pspicture}(-1,-0.7)(3.5,1.1)

\newcommand{\f}{1/(x^2+1)}
\newcommand{\h}{sin(\psPi*x)/(x^2+1)}

\pscustom[fillstyle=solid, fillcolor=lightgray,
          linestyle=none]{
 \psplot{1}{3}{\f}
 \psplot{3}{1}{\h}
}

\psplot{0}{3.5}{\f}
\psplot{0}{3.5}{\h}

\psaxes[Dy=0.2,labels=y](0,0)(-1,-0.7)(3.5,1.1)
```