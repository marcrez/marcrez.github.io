---
title: GwMnKj
permalink: GwMnKj
layout: post
date: 2019-02-24 19:04:10
category: ellipses
---

```latex
% Dans le préambule
% -----------------
\usetikzlibrary{shapes}
% -----------------

\begin{tikzpicture}[grow=down,->]
\tikzstyle{level 1}=[sibling distance=3cm]
\tikzstyle{level 2}=[sibling distance=1.5cm]

\node[draw, ellipse] {Bernouilli}
child { node {A1}
  child { node {A2}
          edge from parent node[left=4pt] {$1-q$}
        }
  child { node {B2}
          edge from parent node[right=4pt] {$q$}
        }
  edge from parent node[left=4pt] {$1-p$}
}
child { node {B1}
  child { node {A3}
          edge from parent
          node[left=4pt] {$1-r$}
        }
  child { node {B3}
          edge from parent
          node[right=4pt] {$r$}
        }
  edge from parent node[right=4pt] {$p$}
};
\end{tikzpicture}
```