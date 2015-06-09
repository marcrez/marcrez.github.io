---
title: Mémo sur la syntaxe markdown
layout: post
date: 2015-6-9
tags: [markdown]
category: notes
---

## Des titres et des sous-titres pour structurer

```
# Titre 1
## Titre 2
### Titre 3 
#### Titre 4
```

## Composer et mettre en forme du texte

```
Des balises pour du texte _italique_,  **gras**, and `code()`.
```

Des balises pour du texte _italique_,  **gras**, and `code()`.

```
- Une liste
- avec des puces

1. Une liste
2. avec des numéros
```

- Une liste
- avec des puces

1. Une liste
2. avec des numéros

## des images et des liens

```
![picture alt](https://cdn.cine.io/images/code-logos/github-logo.png "Title is optional")    
```

![picture alt](https://cdn.cine.io/images/code-logos/github-logo.png "Title is optional")    

```
- Les liens sont automatiquement traduits : http://w3.org
- On peut nommer les liens : [Google](http://google.com),
- On peur enfin référencer les liens : [wikipedia][WP],

  [WP]: https://fr.wikipedia.org/ "En français"
```

- Les liens sont automatiquement traduits : http://w3.org
- On peut nommer les liens : [Google](http://google.com),
- On peur enfin référencer les liens : [wikipedia][WP],

  [WP]: https://fr.wikipedia.org/ "En français"

----------

 1. A numbered list
 2. Which is numbered
 3. With periods and a space 

### Markdown plus definition lists

 
Definition lists
: Multiple definitions and terms are possible
: Definitions can include multiple paragraphs too
 
Term 1
Term 2

:   Definition C

:   Definition D

	> part of definition D

 
> **NOTE :** Blockquotes are like quoted text in email replies
>> And, they can be nested
 
--------------------------

### Tables

| Header    | R      |    C
| ---       | ---:   |  :---:
|  Cellule  |  2100  |    1
|  Cell     |     2  |  112234
 

* Outer pipes on tables are optional
* Colon used for alignment (right versus left)
* You can specify column alignment with one or two colons:


### Fenced code blocks

**GitHub**'s fenced code blocks are also supported with **Prettify** syntax highlighting:


    var bar = 0;

```
var foo = baz;
```


### MathJax
 
You can include **LaTex** expressions to render the *Gamma function* satisfying $\Gamma(n) = (n-1)!\quad\forall
n\in\mathbb N$ is via through the Euler integral

$$
\Gamma(z) = \int_0^\infty t^{z-1}e^{-t}dt\,.
$$

### Un jeu d'icônes

![img](http://benweet.github.io/stackedit/img/glyphicons-halflings.png)

