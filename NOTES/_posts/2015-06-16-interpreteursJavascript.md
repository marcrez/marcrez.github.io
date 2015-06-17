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

## Markdown to Html

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


Afin que la magie opère, on place le contenu markdown dans un fichier
`monFichier.html`, on l'entoure de balises qui vont indiquer à l'interpréteur 
javascript le contenu à traiter ainsi que le thème à lui appliquer.
Il ne reste plus qu'à ajouter le chargement de `strapdown.js` à la fin du 
fichier, le tour est joué.

```html
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

</html>
```

## LaTeX to Html

On peut inclure des formules LaTeX de façon classique `$ ax^2+bx+c $` ou 
`\[ ax^2+bx+c \]` pour des formules dans le paragraphe  ou bien 
` $$ax^2+bx+c $$` ou `\[ ax^2+bx+c \]` pour des formules dans un paragraphe
dédié.

Pour que les formules soient interprétées, on va ajouter une nouvelle
library JavaScript.

```html
<!DOCTYPE html>
<html>
<body>

Une formule dans la ligne : $ ax^2+bx+c $

\[ \sum_{n=1}^{+\infty} \frac{1}{n} = \frac{\pi^2}{6} \]

</body>

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
</html>
```

## Yaml to Html

L'en-tête Yaml est un petit paragraphe en début de document, entouré de 
qutre tirets et qui donne des informations sur le document.

Pour interpréter les informations du bloc Yaml, on ajoute une nouvelle library

```html
<!DOCTYPE html>
<html>

<xmp theme="united" style="display:none;">

<div id="yaml">
title: Le Titre du document
author: Nico
tags: [markdown, html, javascript]
</div>

# Titre du document

Du texte blablabla
blablabla

</xmp>

<script type="text/javascript" src="js/yaml.js"></script>

<script type="text/javascript">
yamlObj = YAML.parse(document.getElementById('yaml').innerHTML);
document.getElementById('yaml').innerHTML = "";

document.title =  yamlObj.title;
var auth = document.createElement( 'div' ); auth.className = "authorClass";
var s = document.createTextNode("L'auteur : " + yamlObj.author);
auth.appendChild(s);
document.getElementById('yaml').appendChild(auth);

var tags = document.createElement( 'div' ); tags.id = "tags"; tags.className = "tagsClass";
var s = document.createTextNode("Les tags : ");
tags.appendChild(s);
document.getElementById('yaml').appendChild(tags);
yamlObj.tags.forEach(appendTag);

// Define the callback function.
function appendTag(value, index, ar) {
  var tag = document.createElement( 'span' ); tag.className = "tagClass";
  if (index == ar.length - 1) {
    var s = document.createTextNode(value);
  } else {
    var s = document.createTextNode(value + ", ");
  }
  tag.appendChild(s);
  document.getElementById('tags').appendChild(tag);
}
</script>

</html>
```



