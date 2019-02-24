---
title: 6GbiTI
permalink: 6GbiTI
layout: post
date: 2019-02-24 19:04:10
category: ellipses
---

```latex
% Dans le préambule
% -----------------
\usepackage{pstricks-add}
% -----------------

\begin{pspicture}(-1,-0.25)(1,1.5)
\cnode(0,0){4pt}{A}   \cnode(1,1){4pt}{B}
\cnode(0,1.5){4pt}{C} \cnode(-1,1){4pt}{D}
\psset{arcangle=20} % definit la courbure
\ncarc{A}{B} \ncarc{B}{A}
\ncarc{A}{D} \ncarc{D}{A}
\ncarc{C}{B} \ncarc{D}{C}
\ncline{A}{C}       % la liason droite
\end{pspicture}
```