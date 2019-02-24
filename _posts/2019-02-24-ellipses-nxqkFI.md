---
title: nxqkFI
permalink: nxqkFI
layout: post
date: 2019-02-24 19:04:10
category: ellipses
---

```latex
% Dans le préambule
% -----------------
\usepackage{tikz}
% -----------------

\begin{tikzpicture}[xscale=0.2]
\draw[->,>=latex] (-7,0) -- (11,0);
\draw[->,>=latex] (0,-0.5) -- (0,0.5);
\foreach \x/\label in
   {-2/-2\pi, -1/-\pi, 1/\pi, 2/2\pi, 3/3\pi} {
  \draw (\x*3.14,1mm)
     -- (\x*3.14,-1mm) node[below] {$\label$};
};
\end{tikzpicture}
\begin{tikzpicture}[xscale=1.2]
  \draw[->,>=latex] (-1.16,0) -- (1.83,0);
  \draw[->,>=latex] (0,-0.5) -- (0,0.5);
\foreach \x/\label in
   {-2/-2\pi, -1/-\pi, 1/\pi, 2/2\pi, 3/3\pi} {
  \draw (\x*3.14/6,1mm) -- (\x*3.14/6,-1mm) node[below] {$\frac{\label}{6}$};
};
\end{tikzpicture}
```