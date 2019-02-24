---
title: XiWB5r
permalink: XiWB5r
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
% % objets caches :
% \draw (1,0,-1)--(-1,0,-1)
              % --(-1,2,-1) coordinate (A) node [above] {$A$}
           % (A)--(-1,0,1) coordinate (B) node [below left] {$B$};
% \draw [dashed]  (-1,2,1) coordinate (D) node [above left] {$D$}
              % --(1,0,-1) coordinate (E) node [below right]{$E$};
% \coordinate (C) at (1,2,1);
% \coordinate (E1) at (1,2,-1);
% \coordinate (C0) at (1,0,1);
% \fill (barycentric cs:A=1,B=1,C=1) coordinate (G) circle (1.5pt);
% % faces du cube :
% \begin{scope}[thick, fill opacity=0.75]
    % \draw [fill=brown!20] (C)  -- (E1) -- (A) -- (D);
    % \draw [fill=brown!80] (C)  -- (C0) -- (E) -- (E1) --cycle;
    % \draw [fill=brown!50] (C0) -- (B)  -- (D) -- (C)  --cycle;
% \end{scope}
% \draw (B) -- (C) node [below right] {$C$} -- (A);
% \draw (G) node [below] {$G$};
% \draw (0,-1) node {$(DE)\perp(ABC)$};
% \end{tikzpicture}
```