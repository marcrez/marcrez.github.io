---
title: CJp5MX
permalink: CJp5MX
layout: post
date: 2019-02-24 19:04:10
category: ellipses
---

```latex
\begin{tikzpicture}[node distance=2.5cm]
\node(g){$G$};
\node(im)  [right of=g] {$\mathrm{im}(f)$};
\node(quo) [below of=g] {$G/\ker(f)$};

\tikzstyle{fleche}=[draw,->,>=latex]
\tikzstyle{tirets}=[fleche, dashed]

\draw[fleche] (g)  -- node[above] {$f$} (im);
\draw[fleche] (g)  -- node[left] {$\varphi$} (quo);
\draw[tirets] (quo)-- node[below] {$h$} (im);
\end{tikzpicture}
```