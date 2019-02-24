---
title: jXDSX6
permalink: jXDSX6
layout: post
date: 2019-02-24 19:04:10
category: ellipses
---

```latex
% Dans le préambule
% -----------------
\usepackage{pst-tree}
% -----------------

\pstree[nodesep=5pt,treesep=0.4]{\Tc*{2mm}}{
  \Tdia{A}
  \Tcircle{B}
  \Ttri{C}
  \TR{\psframebox{D}}
  \TR{\psframebox[shadow=true,framearc=0.3,
        fillstyle=solid,fillcolor=gray]{E}}
}
```