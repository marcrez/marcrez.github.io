---
title: Programmer Arduino sous Android en USB
permalink: arduino-android
layout: post
date: 2017-01-04 20:31:00
tags: [arduino, electronique]
category: arduino
---

![img]({{ site.baseurl }}/images/arduinoAndroid/arduinoAndroidLogo.jpg)

Programmer une carte Arduino depuis une tablette ou un téléphone Android
est possible, on peut même le faire avec de des interfaces de programmation
graphique par blocs (comme avec Scratch), c'est ce que nous allons voir
dans cet article.


## Le matériel nécessaire

1. La tablette/smartphone Android doit être compatible USB OTG. Cela signifie
que le port Micro-USB peut servir d'USB-Host, autrement dit, qu'il est capable
de recevoir une clé USB ou un clavier. Pour vérifier si votre périphérique
Android est compatible USB OTG, il suffit d'installer une application du type
«USB OTG checker» comme par exemple
[USB OTG Check Compatibilité](https://play.google.com/store/apps/details?id=com.faitaujapon.otg&hl=fr)

2. Il faut aussi un câble USB OTG *On-The-Go* (environ 3€) pour brancher le
   cable Arduino sur le port USB du téléphone.

   ![img]({{ site.baseurl }}/images/arduinoAndroid/USB-OTG.jpg)

3. Il faut enfin évidemment une carte Arduino

   - soit une carte Arduino officielle (environ 20€) avec son câble de connexion USB-A - USB-B

     ![img]({{ site.baseurl }}/images/arduinoAndroid/unoR3.jpg)
   - soit une carte compatible (moins de 5€) avec son câble de connexion qui peut être USB-A - Micro-USB.
     ![img]({{ site.baseurl }}/images/arduinoAndroid/robotdyn.jpg)


![img]({{ site.baseurl }}/images/arduinoAndroid/cablage.jpg)

## L'applcation pour tablette ou téléphone Android

Pour programmer la carte Arduino il faut une application permettant
d'écrire des programmes et de se connecter à la carte pour y déposer
le code. C'est ce que fait l'application ArduinoDroid, disponible sur
Google Play (la version payante n'affiche pas de publicités et donne accès à des
fonctions utiles mais non indispensables).


[![img]({{ site.baseurl }}/images/arduinoAndroid/arduinodroid.png)](https://play.google.com/store/apps/details?id=name.antonsmirnov.android.arduinodroid2&hl=fr)

![img]({{ site.baseurl }}/images/arduinoAndroid/arduinodroidScreen.jpg)

## Programmer par blocs

Deux projets basés sur [Blockly](https://fr.wikipedia.org/wiki/Blockly)
permettent de construire des programmes Arduino (en C++) sans écrire de code
mais en déplaçant des blocs graphiques correspondant à des instructions. Le
code correspondant est alors automatiquement généré. Aucune installation n'est
nécessaire : ce sont des applications web, un navigateur suffit.

BlocklyDuino

- le projet : <https://github.com/BlocklyDuino>
- démo : <http://easycoding.tn/bde/demos/code/?lang=fr>

Blockly@rduino

- le projet : <https://github.com/technologiescollege/Blockly-at-rduino>
- démo : <http://www.techmania.fr/BlocklyDuino/>


Voici une exemple dans lequel 4 blocs ont été disposés pour faire clignoter
au rythme de 1 seconde la LED de la carte Arduino (pin 13)
![img]({{ site.baseurl }}/images/arduinoAndroid/blockly.png)

On va pouvoir copier le code généré, le coller dans
l'application ArduinoDroid. Après compilation puis téléversement dans la carte,
le résultat est la :

![img]({{ site.baseurl }}/images/ardublock/led13.gif)


