---
title: Interpréteurs JavaScript
layout: post
date: 2015-06-16
tags: [markdown]
category: notes
---

On a déjà vu l'intérêt des formats texte brut pour rédiger des documents.
Dans cet article, nous allons voir comment utiliser JavaScript pour mettre
en forme un document markdown contenant un en-tête YAML et des formules LaTeX.

## Le document de base au format texte

Partons d'un document simple dont la mise en forme est spartiate puisque
puisque c'est du texte brut

```
# Titre du document

- de la mise en forme : *italique* ou **gras**
- mais aussi du `code` ou des caractères spéciaux : &#8212;

| A      | B      | C      |
|:------ | ------:|:------:|
| Cell A | Cell B | Cell C |

```

Le but est de transformer ce contenu en un document html bien présenté
et qui pourra être lu dans un navigateur.

## Markdown to Html

Afin que la magie opère, on place le contenu markdown dans un fichier
`monFichier.html` et on ajoute la ligne suivante à la fin du fichier.

```
<script src="http://strapdownjs.com/v/0.2/strapdown.js"></script>
```

Maintenant, on entoure le contenu markdown de balises qui vont indiquer à 
`strapdown.js` le contenu à traiter ainsi que le thème à lui appliquer.

```
<!DOCTYPE html>
<html>
<xmp theme="united" style="display:none;">

# Titre du document

- de la mise en forme : *italique* ou **gras**
- mais aussi du `code` ou des caractères spéciaux : &#8212;

| A      | B      | C      |
|:------ | ------:|:------:|
| Cell A | Cell B | Cell C |

</xmp>
<script src="http://strapdownjs.com/v/0.2/strapdown.js"></script>
```

## LaTeX to Html

On peut inclure des formules LaTeX de la façon classique `$ ax^2+bx+c $` ou 
`\[ ax^2+bx+c \]` pour des formules dans le paragraphe  ou bien 
` $$ax^2+bx+c $$` ou `\[ ax^2+bx+c \]` pour des formules dans un paragraphe
dédié.

Pour que les formules soient interprétées, on va ajouter une nouvelle
library JavaScript.

```
<!DOCTYPE html>
<html>
<xmp theme="united" style="display:none;">

# Titre du document

- de la mise en forme : *italique* ou **gras**
- une formule dans la ligne : $ ax^2+bx+c $

\[ \sum_{n=1}^{+\infty} \frac{1}{n} = \frac{\pi^2}{6} \]

</xmp>
<script type="text/x-mathjax-config">
  MathJax.Hub.Config({
    extensions: ["tex2jax.js"],
    jax: ["input/TeX", "output/HTML-CSS"],
    tex2jax: {
      inlineMath: [ ['$','$'], ["\\(","\\)"] ],
      displayMath: [ ['$$','$$'], ["\\[","\\]"] ],
      processEscapes: true
    },
    "HTML-CSS": { availableFonts: ["TeX"] }
  });
</script>
<script type="text/javascript" src="http://cdn.mathjax.org/mathjax/latest/MathJax.js"></script>
<script src="http://strapdownjs.com/v/0.2/strapdown.js"></script>
```

## Yaml to Html

L'en-tête Yaml est un petit paragraphe en début de document, entouré de 
qutre tirets et qui donne des informations sur le document.

Pour interpréter les informations du bloc Yaml, on ajoute une nouvelle library


