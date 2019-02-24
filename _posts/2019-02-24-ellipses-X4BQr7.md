---
title: X4BQr7
permalink: X4BQr7
layout: post
date: 2019-02-24 19:04:10
category: ellipses
---

```latex
% Dans le préambule
% -----------------
\usepackage{pstricks-add,pst-func}
% -----------------

% Definition de f en RPN
\newcommand{\f}[1]{#1 2 exp neg EXP}

\begin{pspicture}(-1,-0.5)(2,1.4)
\psaxes{->}(0,0)(-1,-0.5)(2,1.4)
\psplot{-1}{1.7}{\f{x}}
\psset{linestyle=dotted,showpoints=true,dotstyle=o}
\psline(!0.5 0)(!0.5 \f{0.5})(!0 \f{0.5})
\end{pspicture}

On a $f(0.5)\simeq$ \psPrintValue[decimals=3]{\f{0.5}}
```