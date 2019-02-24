---
title: MGSCnq
permalink: MGSCnq
layout: post
date: 2019-02-24 19:04:10
category: ellipses
---

```latex
% % Dans le préambule
% -----------------
\usepackage{pstricks-add}
% -----------------

% \begin{pspicture}(-5,0)(5,5)
% \multido{\n=0+1}{90}{ % Unités de 0 à 89 degres
 % \psline[linecolor=gray](3;\n)%
 % (!5 \n \space tan 1 add div 1 mul dup neg 5 add)  }
% \multido{\n=91+1}{90}{ % Unités de 91 à 180 degres
 % \psline[linecolor=gray](3;\n)%
 % (!5 \n \space tan 1 sub div 1 mul dup 5 add)      }
% \multido{\n=0+10}{9}{ % Dizaines de 0 à 80 degres
 % \psline(2.5;\n)%
 % (!5 \n \space tan 1 add div 1 mul dup neg 5 add)  }
% \multido{\n=100+10}{9}{ % Dizaines de 100 à 180 degres
 % \psline(2.5;\n)%
% (!5 \n \space tan 1 sub div 1 mul dup 5 add)       }
% % le cas spécial du 90 puis le centre du rapporteur
% \psline(2.6;90)(0,5) \psdots(0,0)
% \end{pspicture}
```