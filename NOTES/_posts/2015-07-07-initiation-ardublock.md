---
title: Introduction Ardublock
layout: post
date: 2015-07-07
tags: [arduino, algorithmique]
category: notes
---

![pres]({{ site.baseurl }}/images/ardublock/pres.png)
Ardublock est un plugin pour l'interface de programmation d'Arduino.
Grâce à ardublock, on peut programmer Arduino sous forme graphique, le
plugin se charge de générer le code correpondant.


## Installation

L'installation est détaillée sur le site [ardublock](http://blog.ardublock.com/engetting-started-ardublockzhardublock/)

Pour résumer, on télécharge un paquet java et on l'enregistre dans le répertoire
où se trouvent les `sketchbook`. Dans ce répertoire, on devra créer l'arborescence
`tools/ArduBlockTool/tool/` puour déposer le .jar au bout.

Par exemple pour un utilisateur nommé `abu`,

- Sous Mac, /Users/abu/Documents/Arduino/tools/ArduBlockTool/tool/ardublock-all.jar
- Sous Linux, /home/abu/sketchbook/tools/ArduBlockTool/tool/ardublock-all.jar
- Sous Windows, C:\Users\abu\Documents\Arduino\tools\ArduBlockTool\tool\ardublock-all.jar

Une fois cela fait, un nouvel outil apparaît.

![pres]({{ site.baseurl }}/images/ardublock/launch.png)


## Premier programme : blink

Le principe de programmation Ardublock est le même aue celui de Scratch :
le code se construit par assemblage de briques de couleur.

Commençons par écrire un premier programme qui va faire clignoter la LED qui se
trouve à côté de la broche 13

![gif]({{ site.baseurl }}/images/ardublock/led13.png)

Après avoir cliqué sur «Transférer», le résultat est là

![gif]({{ site.baseurl }}/images/ardublock/led13.gif)

## Second programme : Aide au stationnement

![gif]({{ site.baseurl }}/images/ardublock/sonar01.png)
![gif]({{ site.baseurl }}/images/ardublock/moniteurSerie.png)
![gif]({{ site.baseurl }}/images/ardublock/teurSerie2.png)


500ms
