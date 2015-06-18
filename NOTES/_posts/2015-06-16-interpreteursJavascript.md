---
title: Interpréteurs JavaScript
layout: post
date: 2015-06-16
tags: [markdown, javascript]
category: notes
---

![markdown](https://upload.wikimedia.org/wikipedia/commons/thumb/4/48/Markdown-mark.svg/120px-Markdown-mark.svg.png)
On a déjà vu l'intérêt des formats texte brut pour rédiger des documents.
Dans cet article, nous allons voir comment utiliser JavaScript pour mettre
en forme un document markdown contenant un en-tête YAML et des formules LaTeX.

## Markdown to Html

Partons d'un document simple dont la mise en forme est spartiate puisque
puisque c'est du markdown, donc du texte brut

```
# Titre de niveau 1

- De la mise en forme : *italique* ou **gras**
- mais aussi du `code` ou des caractères spéciaux : &#8212;

| A      | B      |
| ------ | ------ |
| Cell A | Cell B |
```

Le but est de transformer ce contenu en un document html bien présenté
et qui pourra être lu dans un navigateur.
Pour cela on va utiliser [Strapdown.js](http://strapdownjs.com/).

Afin que la magie opère, on place le contenu markdown dans un fichier
`monFichier.html`, on l'entoure de balises qui vont indiquer à l'interpréteur
javascript le contenu à traiter ainsi que le thème (ici `united`) à lui
appliquer.  Il ne reste plus qu'à ajouter le chargement de `strapdown.js` à la
fin du fichier, le tour est joué.

[Voir l'exemple]({{ site.baseurl }}/files/2015-06-16-interpreteursJavascript-markdown2html.html)

```html
<!DOCTYPE html>
<html>
<head>
  <meta http-equiv="content-type" content="text/html; charset=utf-8">
</head>

<xmp theme="united" style="display:none;">

# Titre de niveau 1

- De la mise en forme : *italique* ou **gras**
- mais aussi du `code` ou des caractères spéciaux : &#9786; &#9787;

| A      | B      |
| ------ | ------ |
| Cell A | Cell B |

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
library JavaScript capable d'afficher du code LaTeX :
[mathjax](https://www.mathjax.org/).
Voici un exmple de mise en situation.

[Voir l'exemple]({{ site.baseurl }}/files/2015-06-16-interpreteursJavascript-latex2html.html)

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


## Table des matières automatique

Lorsqu'un document est bien structuré, la table des matières doit pouvoir être
construite automatiquement. Un plugin [jquery](https://jquery.com/) nommé
[tableofcontents](http://fuelyourcoding.com/scripts/toc/examples/example1.html)
sait faire cela. Il va analyser le code html à la recherche des balises `h1`,
`h2` etc... et va remplir la balise `<div id="toc">` qu'on aura placée là où on
veut faire aparaître la table des matières.

[Voir l'exemple]({{ site.baseurl }}/files/2015-06-16-interpreteursJavascript-tableofcontents.html)

```html
<!DOCTYPE html>
<html>
 <head>
  <link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/jquery.tocify/1.9.0/stylesheets/jquery.tocify.css">
  <style> #content { margin-left: 25%; } </style>
 </head>
 <body>
 <div id="toc"></div>
 <div id="content">
  <h1>Titre A</h1>
    <h2>Titre 1</h2>
    <p> Lorem ipsum... </p>
    <h2>Titre 2</h2>
    <p> Lorem ipsum... </p>
  <h1>Titre B</h1>
    <h2>Titre 1</h2>
    <p> Lorem ipsum... </p>
 </div>
 
 </body>
 
 <script src="http://code.jquery.com/jquery-1.11.3.min.js"></script>
 <script src="http://code.jquery.com/ui/1.10.4/jquery-ui.min.js"></script>
 <script src="https://cdnjs.cloudflare.com/ajax/libs/jquery.tocify/1.9.0/javascripts/jquery.tocify.min.js"></script>
 <script type="text/javascript" charset="utf-8">
 	$(function(){ $("#toc").tocify(); })
 </script>
 
</html>

```



## Yaml to Html

L'en-tête Yaml est un petit paragraphe en début de document, entouré de 
quatre tirets et qui donne des informations sur le document.

Pour interpréter les informations du bloc Yaml, on charge la library
[JS-YAML](http://adilapapaya.com/docs/js-yaml/)

JS-YAML va récupérer les informations au format yaml qu'on aura pris soin de
coller dans une div dont l'id est `yaml`. Les quelques lignes de code javascript
ci-dessous vont mettre ces informations en forme dans des balises html auxquelles
on pourra donner un style css.

[Voir l'exemple]({{ site.baseurl }}/files/2015-06-16-interpreteursJavascript-yaml2html.html)


```html
<!DOCTYPE html>
<html>
<head>
  <style> .tagClass { border:1px solid; margin:2px; background: lightblue;} </style>
</head>
<body>

<div id="yaml">
title: Le Titre du document
author: Nicolas Poulain
tags: [markdown, html, javascript]
</div>

<h1 id="title"></h1>

<h2> Introduction </h2>
Du texte blablabla
blablabla

</body>

<!-- http://adilapapaya.com/docs/js-yaml/ -->
<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/js-yaml/3.3.1/js-yaml.min.js"></script>

<script type="text/javascript">
yamlObj = jsyaml.load(document.getElementById('yaml').innerHTML);
document.getElementById('yaml').innerHTML = "";

// Titre du document
document.title =  yamlObj.title;
document.getElementById('title').innerHTML = yamlObj.title;

// Auteur
var auth = document.createElement( 'div' ); auth.className = "authorClass";
var s = document.createTextNode("L'auteur : " + yamlObj.author);
auth.appendChild(s);
document.getElementById('yaml').appendChild(auth);

// Tags
var tags = document.createElement( 'div' ); tags.className = "tagsClass";
tags.id = "tags";
var s = document.createTextNode("Les tags : ");
tags.appendChild(s);
document.getElementById('yaml').appendChild(tags);
yamlObj.tags.forEach(appendTag);

// Callback function pour afficher les tags du tableau
function appendTag(value, index, ar) {
  var tag = document.createElement( 'span' ); tag.className = "tagClass";
  var s = document.createTextNode(value);
  tag.appendChild(s);
  document.getElementById('tags').appendChild(tag);
}
</script>

</html>

```



