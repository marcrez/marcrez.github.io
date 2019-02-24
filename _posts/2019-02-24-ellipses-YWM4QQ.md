---
title: YWM4QQ
permalink: YWM4QQ
layout: post
date: 2019-02-24 19:04:10
category: ellipses
---

```latex
% Dans le préambule
% -----------------
\usepackage{pst-tree}
% -----------------

\psset{nodesep=5pt,treesep=1.2,
       levelsep=1.5cm,arrows=->}
\pstree{\Toval{Bernouilli}}{
  \pstree{\TR{A} \nbput{1-p}}
             {\TR{A}  \nbput{1-p}
              \TR{B}  \naput{p}   }
  \pstree{\TR{B} \naput{p} }
             {\TR{A}  \nbput{1-p}
              \TR{B}  \naput{p}   }
}
```