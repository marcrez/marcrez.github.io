---
 title: kdB1d3
 permalink: kdB1d3
 layout: post
 date: 2019-02-24
 tags: [ellipses]
 ---

```latex% Dans le préambule
% -----------------
\usepackage{tikz}
% -----------------

\begin{tikzpicture}
  \draw (0,0)--(1,1)--(0,1)--(1,0);

\begin{scope}[xshift=2cm]
  \draw (0,0)--(1,1)--(0,1)--(1,0);
\end{scope}

\begin{scope}[xshift=2cm,yshift=1cm,rotate=20]
  \draw (0,0)--(1,1)--(0,1)--(1,0);
\end{scope}
\end{tikzpicture}
```