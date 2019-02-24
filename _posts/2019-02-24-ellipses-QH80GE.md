---
title: QH80GE
permalink: QH80GE
layout: post
date: 2019-02-24 19:04:10
category: ellipses
---

```latex
% Dans le préambule
% -----------------
\usepackage{pstricks-add}
% -----------------

\begin{pspicture}(-2,-1)(2,1)
\pnode(1,0){A}                       % Définition
\pnode(1;72){B}     \pnode(1;144){C} % des cinq
\pnode(1;-144){D}   \pnode(1;-72){E} % noeuds

\pspolygon(A)(B)(C)(D)(E)
\psline[linestyle=dashed](A)(C)(E)(B)(D)(A)
\end{pspicture}
```