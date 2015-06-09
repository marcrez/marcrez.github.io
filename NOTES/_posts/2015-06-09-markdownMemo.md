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
Des balises pour du texte _italique_,  **gras**, et même du `code()`.
```

Des balises pour du texte _italique_,  **gras**, et même du `code()`.

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

## Des images et des liens

```
![picture alt](https://cdn.cine.io/images/code-logos/github-logo.png "Title is optional")    
```

![picture alt](https://cdn.cine.io/images/code-logos/github-logo.png "Title is optional")    

```
- Les adresses sont traduites en lien cliquable : http://w3.org
- On peut nommer les liens : [Google](http://google.com)
- On peut référencer les liens : [wikipedia][WP]

  [WP]: https://fr.wikipedia.org/ "En français"
```

- Les adresses sont traduites en lien cliquable : http://w3.org
- On peut nommer les liens : [Google](http://google.com)
- On peut référencer les liens : [wikipedia][WP]

  [WP]: https://fr.wikipedia.org/ "En français"

```
> **NOTE :** Blockquotes are like quoted text in email replies
>> And, they can be nested
```

> **NOTE :** Blockquotes are like quoted text in email replies
>> And, they can be nested


## Tableaux

```| Header   | L      | R      | C
| ---      | :---   | ---:   | :---:
| Cellule  | LLLLL  | RRRRR  | CCCCC
| Cell     | L      | R      | C
```

| Header   | L      | R      | C
| ---      | :---   | ---:   | :---:
| Cellule  | LLLLL  | RRRRR  | CCCCC
| Cell     | L      | R      | C


## Blocs de code


Pour écrire du code, on peut décaler de plus de 4 espaces ou entourer le
paragraphe de triple backticks.

```
    var bar = 0;

```javascript
var foo = baz;
```
```

var bar = 0;

```javascript
var foo = baz;
```


<!--
### MathJax
 
You can include **LaTex** expressions to render the *Gamma function* satisfying $\Gamma(n) = (n-1)!\quad\forall
n\in\mathbb N$ is via through the Euler integral

$$
\Gamma(z) = \int_0^\infty t^{z-1}e^{-t}dt\,.
$$

-->
