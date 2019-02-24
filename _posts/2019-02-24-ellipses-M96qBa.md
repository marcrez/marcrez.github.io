---
title: M96qBa
permalink: M96qBa
layout: post
date: 2019-02-24 19:04:10
category: ellipses
---

```latex
\begin{tikzpicture}
\matrix[nodes={draw,circle}, row sep=0.5cm,
                             column sep=0.5cm] {
  \node (a){A}; & \node (b){B}; & \node (c){C}; \\
  \node (d){D}; &             ; & \node (e){E}; \\
  \node (f){F}; & \node (g){G}; & \node (h){H}; \\
};
\tikzstyle{connect} = [draw=white, line width=3pt,
                                   double=black,-]
\draw[connect] (d) -- (b); \draw[connect] (g) -- (e);
\draw[connect] (a) -- (h); \draw[connect] (c) -- (f);
\draw[connect] (b) -- (e); \draw[connect] (d) -- (g);
\end{tikzpicture}
```