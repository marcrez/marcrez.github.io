---
title: nqmQhr
permalink: nqmQhr
layout: post
date: 2019-02-24 19:04:10
category: ellipses
---

```latex
% Dans le préambule
% -----------------
\usepackage{pstricks-add}
% -----------------

\begin{pspicture}(0,-1)(2,1)
\cnode(0,0){3pt}{A}  \uput[180](A){$A$}
\cnode(3,-1){3pt}{F} \uput[-45](F){$F$}
\cnode*(1,1){3pt}{B}  \cnode*(2,0){3pt}{C}
\cnode*(1,-1){3pt}{D} \cnode*(3,1){3pt}{E}

\psset{ArrowInside=->,arrowscale=2}
\ncline{A}{B} \ncline{A}{D} \ncline{B}{C}
\ncline{C}{D} \ncline{C}{E} \ncline{D}{B}
\ncline{E}{B} \ncline{E}{F} \ncline{F}{C}
\end{pspicture}
```