---
title: 68gAJe
permalink: 68gAJe
layout: post
date: 2019-02-24 19:04:10
category: ellipses
---

```latex
% Dans le préambule
% -----------------
\usepackage{pstricks-add}
% -----------------

{\psset{unit=3} % zoom facteur 3
\begin{pspicture}(-1.2,-0.2)(1.2,1.2)
\pswedge(0,0){1}{0}{180}
\psdots[dotstyle=o](0,0)
\multido{\n=10+10}{17}{
  \rput(0.8;\n){\small\n}
  \psline(0.87;\n)(1;\n)
}
\multido{\n=0+1}{180}{
  \psline[linewidth=0.1mm](0.9;\n)(1;\n)
}
\end{pspicture}
```