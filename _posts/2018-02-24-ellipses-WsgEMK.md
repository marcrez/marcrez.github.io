---
 title: WsgEMK
 permalink: WsgEMK
 layout: post
 date: 2019-02-24
 tags: [ellipses]
 ---

```latex% Dans le préambule
% -----------------
\usepackage{tikz}
% -----------------

\begin{tikzpicture}
\draw (3,0) arc (0:90:3);
\draw[thick] (30:3)--++(2,0)--++(0,1)
                   --++(-2,0)--cycle;
\end{tikzpicture}
```