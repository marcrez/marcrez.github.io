---
title: jEQ6J2
permalink: jEQ6J2
layout: post
date: 2019-02-24 19:04:10
category: ellipses
---

```latex
% Dans le préambule
% -----------------
\usepackage[french,ruled,linesnumbered,vlined]{algorithm2e}
% -----------------

\begin{algorithm}
\caption{Fonction factorielle}
\Donnees{N un  entier naturel}
\Res{La valeur de N!}
\BlankLine
\eSi(\tcc*[f]{Erreur})
{N $\notin \mathbb{N}$}
{ \Retour{-1} }
(\tcc*[f]{On peut calculer N!})
{ $F \gets 1$ \;
    \Pour{i=1 \KwA N}{
      $F \gets F*i$
    }
  \Retour{F} \;
}
\end{algorithm}
```