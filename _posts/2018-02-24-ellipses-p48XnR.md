---
 title: p48XnR
 permalink: p48XnR
 layout: post
 date: 2019-02-24
 tags: [ellipses]
 ---

```latex% Dans le préambule
% -----------------
\usepackage{pstricks-add}
% -----------------

\begin{pspicture}(0,0)(3,2)
\pnode(1,1){A} \pnode(3,1){B}
\uput[90](A){$A$} \uput[90](B){$B$}
\psline[showpoints=true](A)(B)
\end{pspicture}
```