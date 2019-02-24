---
title: ngI8R2
permalink: ngI8R2
layout: post
date: 2019-02-24 19:04:10
category: ellipses
---

```latex
% % Dans le préambule
% -----------------
\usepackage{pstricks-add}
% -----------------

% \savedata{\temper}[{ {1,-10},{2,-5},{3,2},
     % {4,8},{5,12},{6,14}{7,14}{8,13},{9,8},{10,3}}]
% \savedata{\precip}[{ {1,150},{2,132},{3,110},
  % {4,80},{5,85},{6,60}{7,55}{8,60},{9,98},{10,122}}]

% \psset{xunit=0.5cm,yunit=0.1cm}
% \begin{pspicture}(0,-13)(11,19)
% \psset{yunit=0.1} % Echelle 1/10 axe (Oy)
% \dataplot[plotstyle=bar,barwidth=0.4,
          % fillstyle=solid,fillcolor=gray] {\precip}
% \psaxes[ticks=y,labels=y,Dy=30,ylabelPos=right]{->}
                                % (11,0)(0,0)(11,190)
% \psset{yunit=10} % Retour a la normale car 0.1x10=1
% \dataplot[showpoints=true,plotstyle=curve]{\temper}
% \psaxes[ticks=y,tickcolor=lightgray,yticksize=11,
              % labels=y,Dy=5]{->}(0,0)(0,-13)(11,19)
% \end{pspicture}
```