---
title: JFprMs
permalink: JFprMs
layout: post
date: 2019-02-24 19:04:10
category: ellipses
---

```latex
% Dans le préambule
% -----------------
\usepackage{color}
% -----------------

% Dans le préambule
% -----------------
\definecolor{gris}{rgb}{0.5,0.5,0.5}
% -----------------

% Definition & initialisation du compteur
\newcounter{Ex}  \setcounter{Ex}{0}
% Definition de la commande
\newcommand{\exo}{\stepcounter{Ex}
 \colorbox{gris}{\textcolor{white}{\theEx}}
}

\exo Calculer $f(2)$.

\exo Déterminer $f^{-1}(0)$.

\exo Calculer $f'(0)$.
```