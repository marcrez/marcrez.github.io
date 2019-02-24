---
 title: WHkpdd
 permalink: WHkpdd
 layout: post
 date: 2019-02-24
 tags: [ellipses]
 ---

```latex\begin{tikzpicture}
\coordinate (A) at (0:1)  ;
\coordinate (B) at (72:1) ; \coordinate (C) at (144:1);
\coordinate (E) at (-72:1); \coordinate (D) at (-144:1);

\draw(A)--(B)--(C)--(D)--(E)--cycle;
\draw[dashed](A)--(C)--(E)--(B)--(D)--cycle;
\end{tikzpicture}
```