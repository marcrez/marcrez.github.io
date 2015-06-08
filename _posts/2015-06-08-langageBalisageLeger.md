---
title: Langages de balisage léger et logiciels de conversion de documents
layout: post
date: 2015-05-14 13:30:00
tags: [balisage, pandoc, formats]
category: notes
---

## Présentation

Pour saisir et mettre en forme des textes ou des documents textuels comportant
des insertions d'images, de figures ou de tableaux, on utilise souvent un
traitement de texte, propriétaire comme Microsoft Word ou libre comme
OpenOffice.  Mais les défauts majeurs de ces logiciels sont nombreux :

1. Le rédacteur d'un document se concentre presque autant sur le fond que
   sur la forme. Outre le temps perdu, les conséquences sur le rendu sont
   nombreuses
	* Les mises en forme les plus hétéroclites sont autorisées au dépens de
	  la lisibilité ;
	* Le résultat final est souvent discutable du point du vue de la
	  typographie car les règles n'en sont pas respectées ni par
	  l'utilisateur ni par le logiciel ;
	* L'utilisation des styles est souvent anarchique et les documents mal
	  structurés, ce qui rend la production automatique de sommaire ou
	  d'index impossible ;
	* L'insertion d'images ou de figures provoque des décalages mal
	  maîtrisés.
1. En ce qui concerne les documents longs, l'inclusion de documents annexes au
   sein du document maître donne des résultats aléatoires ;
1. L'interopérabilité n'est pas assurée entre les logiciels, elle ne l'est pas
   même entre les différentes versions d'un même logiciel. La compatibilité
   ascendante ne fonctionne pas toujours et un document écrit il y a quelques
   années risque d'être perdu, faute du logiciel capable de le lire . 
   Nous reviendrons sur ce point plus tard.


À l'opposé de la composition dans un logiciel de traitement de texte, on
peut écrire des documents dans des langages de balisage. Il en existe de
nombreux : LaTeX, HTML, DocBook, etc. Les fichiers sont enregistrés au format
texte brut et doivent être interprétés par un logiciel afin d'être consultés.

En ce qui concerne HTML et LaTeX, où pratiquement toutes les mises en formes
sont possibles, le problème vient de la difficulté à écrire les balises.

Voici un exemple : un titre suivi d'une phrase contenant un mot en gras puis une liste
non numérotée. D'abord au format LaTeX :


```
	\section{Le titre du paragraphe}
 
	Voici un mot en \textbf{gras} puis une liste :
 
	\begin{enumerate}
	 \item  c'est simple ;
	 \item  c'est efficace.
	\end{enumerate}
```

Le même exemple au format HTML :

```
	<h1>Le titre du paragraphe</h1>
	<p>Voici un mot en <strong>gras</strong> puis une liste :</p>
	<ul>
	 <li> c'est simple ;</li>
	 <li> c'est efficace.</li>
	</ul>
```

