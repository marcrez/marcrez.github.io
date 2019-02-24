---
title: dfqA81
permalink: dfqA81
layout: post
date: 2019-02-24 19:04:10
category: ellipses
---

```latex
% Dans le préambule
% -----------------
\usepackage{tkz-tab}
% -----------------

\begin{tikzpicture}
\tkzTabInit[lgt=1,espcl=1.2]
   {$x$/0.8, $P$/0.5, $Q$/0.5, $PQ$/1}
           {-5 ,     1 ,     2 ,    5}
\tkzTabLine{   , - ,   , - , z , + , }
\tkzTabLine{   , - , d , + ,   , + , }
\tkzTabLine{   , + , d , - , z , + , }
\end{tikzpicture}
```