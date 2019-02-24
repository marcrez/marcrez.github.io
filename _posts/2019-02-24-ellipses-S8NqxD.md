---
title: S8NqxD
permalink: S8NqxD
layout: post
date: 2019-02-24 19:04:10
category: ellipses
---

```latex
\begin{tikzpicture}
\begin{tikzpicture}[xscale=1,yscale=0.5]
% Les points A, B et C
\tkzDefPoint(4,-0.5){B} \tkzDefPoint(3,1){C} \tkzDefPoint(2,0){D}
% Première homothétie
\tkzDefPointBy[homothety = center C
               ratio -1](B) \tkzGetPoint{O}
\tkzDefPointBy[homothety = center D
               ratio -1](B) \tkzGetPoint{A}
% Seconde homothétie
\tkzDefPointBy[homothety = center O
               ratio -1](A) \tkzGetPoint{E}
\tkzDefPointBy[homothety = center O
               ratio -1](B) \tkzGetPoint{F}
% Dessin des segments
\tkzDrawSegments(F,B A,E F,E A,B C,D)
% Marquage des points et étiquettes
\tkzDrawPoints(A,B,C,D,O,E,F)
\tkzLabelPoints(A,B,C,D,O,E,F)
% \tkzLabelPoints[right](P,Mp)
\end{tikzpicture}
```