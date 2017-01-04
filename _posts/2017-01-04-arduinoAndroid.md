---
title: Programmer Arduino sur une tablette Android
permalink: arduino-android
layout: post
date: 2017-01-04 20:31:00
tags: [arduino, electronique]
category: arduino
---

![img]({{ site.baseurl }}/images/arduinoAndroid/arduinoAndroidLogo.jpg)

Programmer une carte arduino depuis une tablette ou un téléphone Android
est possible, on peut même le faire avec de des interfaces de programmation
graphique par blocs (comme avec Scratch), c'est ce que nous allons voir
dans cet article.


## Le matériel nécessaire

1. Il faut évidemment une carte arduino

   - soit une carte Arduino officielle (environ 20€) avec son câble de connexion USB-A - USB-B

     ![img]({{ site.baseurl }}/images/arduinoAndroid/unoR3.jpg)
   - soit une carte compatible (moins de 5€) avec son câble de connexion qui peut être USB-A - Micro-USB.
     ![img]({{ site.baseurl }}/images/arduinoAndroid/robotdyn.jpg)

2. Il faut aussi un câble USB OTG (On-The-Go) pour brancher le cable arduino
   sur le port USB du téléphone.

   ![img]({{ site.baseurl }}/images/arduinoAndroid/USB-OTG.jpg)


![img]({{ site.baseurl }}/images/arduinoAndroid/cablage.jpg)

## L'applcation pour tablette ou téléphone Android

Pour programmer la carte Arduino il faut une application permettant
d'écrire des programmes et de se connecter à la carte pour y déposer
le code. C'est ce que fait l'application arduinoDroid, disponible sur
Google Play


[![img]({{ site.baseurl }}/images/arduinoAndroid/arduinodroid.png)](https://play.google.com/store/apps/details?id=name.antonsmirnov.android.arduinodroid2&hl=fr)

![img]({{ site.baseurl }}/images/arduinoAndroid/arduinodroidScreen.jpg)

## Programmer par blocs

Deux projets basés sur [Blockly](https://fr.wikipedia.org/wiki/Blockly)
permettent de construire des programmes arduino (en C++) sans écrire de code
mais en déplaçant des blocs graphiques correspondant à des instructions.

![img]({{ site.baseurl }}/images/arduinoAndroid/blockly.png)

BlocklyDuino

- le projet : <https://github.com/BlocklyDuino>
- démo : <http://easycoding.tn/bde/demos/code/?lang=fr>

Blockly@rduino

- le projet : <https://github.com/technologiescollege/Blockly-at-rduino>
- démo : <http://www.techmania.fr/BlocklyDuino/>

