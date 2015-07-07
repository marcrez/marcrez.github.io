---
title: Introduction Ardublock
layout: post
date: 2015-06-16
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

