---
title: xXfX8c
permalink: xXfX8c
layout: post
date: 2019-02-24 19:04:10
category: ellipses
---

```latex
% % Dans le préambule
% -----------------
\usepackage{tikz}
% -----------------

% \begin{tikzpicture}
% % les cotes du triangle :
% \draw [thick] (0:1.5)   coordinate (A) node[right] {$A$}
           % -- (120:1.5) coordinate (B) node[above] {$B$}
           % -- (240:1.5) coordinate (C) node[below] {$C$}
           % -- cycle;
% % les medianes :
% \draw
% (C)--(barycentric cs:A=1,B=1) coordinate (C') node[above right]{$C'$}
% (A)--(barycentric cs:B=1,C=1) coordinate (A') node[left]       {$A'$}
% (B)--(barycentric cs:C=1,A=1) coordinate (B') node[below right]{$B'$};
% % le centre de gravite :
% \fill (barycentric cs:A=1,B=1,C=1) circle (1.5pt) node[above=5] {$G$};
% \end{tikzpicture}
```