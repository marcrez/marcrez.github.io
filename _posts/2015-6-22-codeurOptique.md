---
title: Codeur optique d'une imprimante Canon Pixma IP3000 
permalink: codeur-optique-ip3000
layout: post
date: 2015-06-22 20:31:00
tags: [raspberryPi]
category: raspberryPi
---

![Canon XP3000]({{ site.baseurl }}/images/canon/xp3000.png)
Dans cet article, on va voir comment fonctionne le positionnement
si précis des élements mobiles d'une imprimante, en particulier 
la Canon Pixma XP3000.


## Démontage de l'imprimante

Dans l'imprimante, on peut voir que le galet d'entrainement des feuilles est
piloté par un moteur dont la référence est QK1-0558.
Il entraîne le galet via une petite courroie et engrenage sur un pignon.

![Canon XP3000]({{ site.baseurl }}/images/canon/loin.png)

Ce qui est intéressant ici, c'est ce disque transparent fixé sur le pignon et 
marqué de petits segments noirs.

![Canon XP3000]({{ site.baseurl }}/images/canon/proche.png)

Le détecteur noir est constitué de deux faces : une de chaque côté du disque 
transparent. Une face contient une led et l'autre contient deux détecteurs 
qui sont les bases de deux transistors.

![Canon XP3000]({{ site.baseurl }}/images/canon/perspective.png)


> Remarque : Un peu comme dans un [photocoupleur](https://fr.wikipedia.org/wiki/Photocoupleur)

Lorsque le disque tourne, il va successivement occulter ou laisser passer le 
signal lumineux et on pourra mesurer la rotation.

Voyons le schéma d'un tel circuit (d'après [madpenguin.ca](http://madpenguin.ca/blog/2011/06/14/tutorial-use-an-old-inkjet-printer-to-learn-servo-motor-control-with-emc2-part-2-2/))

![Canon XP3000]({{ site.baseurl }}/images/canon/schema.png)




