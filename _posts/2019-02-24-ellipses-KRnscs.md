---
title: KRnscs
permalink: KRnscs
layout: post
date: 2019-02-24 19:04:10
category: ellipses
---

```latex
% Dans le préambule
% -----------------
\usepackage{pstricks-add}
% -----------------

\begin{pspicture}(-2,-2)(2,2)

\multido{\rA=0+51.429,\nA=0+1}{7}{
  \cnode*(2;\rA){1pt}{Nd\nA}
}

\multido{\nA=0+1}{7}{
  \multido{\nB=0+1}{7}{
    \ncarc[arcangle=-40]{Nd\nA}{Nd\nB}
  }
}
\end{pspicture}
```