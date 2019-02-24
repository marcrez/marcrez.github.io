---
title: 4KTJkJ
permalink: 4KTJkJ
layout: post
date: 2019-02-24 19:04:10
category: ellipses
---

```latex
\newenvironment{extraitter}[1]
{\og \def\foo{#1}}
{\fg{}\begin{flushright}
        \textsc \foo
      \end{flushright} }

\begin{extraitter}{ Lavoisier }
  Rien ne se perd.
\end{extraitter}
```