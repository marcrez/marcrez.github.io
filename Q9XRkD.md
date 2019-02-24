```latex
% Dans le préambule
% -----------------
\usepackage{siunitx}
\sisetup{locale = FR,
    inter-unit-product = \ensuremath{{}\cdot{}}}
% -----------------

\si{\meter\joule\per\second\tothe{3}}

\si[per-mode=symbol]{\meter\joule\per\second\tothe{3}}
```
