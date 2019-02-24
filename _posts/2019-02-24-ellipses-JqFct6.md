---
title: JqFct6
permalink: JqFct6
layout: post
date: 2019-02-24 19:04:10
category: ellipses
---

```latex
\begin{tikzpicture}[very thin]

\foreach \a/\b/\label/\p in
{ 0/158.4/Pacifique/44,
  158.4/259/Atlantique/28,
  259/327.6/Indien/19,
  327.6/345.6/Austral/5,
  345.6/360/Arctique/4
} {
  \draw[fill=gray!\p]
         (0,0)
       --(\a:3) arc (\a:\b:3)
       --cycle;
  \draw({(\a+\b)/2}:2) node{\label};
}
\end{tikzpicture}
```