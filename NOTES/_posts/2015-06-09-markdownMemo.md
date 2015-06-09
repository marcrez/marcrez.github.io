---
title: Mémo sur la syntaxe markdown
layout: post
date: 2015-6-9
tags: [markdown]
category: notes
---

#### Titre 5 with a custom class and id                 {#my-id .my-class}


#### Titre 5 with a custom class and id


### Titre 5 with a custom class and id                 {#my-id .my-class}

```
# Titre 1
## Titre 2
### Titre 3 
#### Titre 4
##### Titre 5 with a custom class and id                 {#my-id .my-class}
```

Some inline markup like _italics_,  **bold**, and `code()`.

![picture alt](https://cdn.cine.io/images/code-logos/github-logo.png "Title is optional")    

 * link to [Warped](http://warpedvisions.org),
 - literal link <http://link.com/>, http://link.com/
 + [Link back to Header 5](#my-id)
 - **Markdown** syntax [here][2],
 - **Prettify** syntax highlighting [here][prettify],

  [2]: http://daringfireball.net/projects/markdown/syntax "Markdown"
  [prettify]: https://code.google.com/p/google-code-prettify/ "prettify"

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

