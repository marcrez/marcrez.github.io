---
title: Présentation de Arduino
permalink: intro-arduino
layout: post
date: 2017-05-01 17:55:00
tags: [electronique, algo, arduino]
category: raspberrypi
---

Comment faire de l'électronique quand on ne sait pas souder, qu'on n'est pas 
très calé en électicité mais qu'on a déjà un peu programmé, par exemple avec
Scratch ?  
Réponse  : Arduino.
![img]({{ site.baseurl }}/images/presentationArduino/arduino.jpg)


Arduino est une carte programmable sur laquelle on peut connecter des capteurs
(de pression, de luminosité, de mouvement, etc.) pour déclencher des actions sur 
des moteurs, des diodes, des écans d'affichage, etc.

Les activités d'algorithmique et de programmation peuvent trouver des
applications concrètes en robotique, pour des expériences scientifiques ou des
réalisations artistiques.

Les réalisations autour d'Arduino peuvent être très simples : un jeu de lumière
ou un télémètre à sonar ou un instrument de musique ne nécessitent aucune
compétence technique mais demandent un travail sur l'algorithmique qui entre
tout à fait dans le cadre des nouveaux programmes de mathématiques.  

Dans le cadre d'EPI, des options ISN ou ICN, on pourra construire des projets
plus ambitieux comme un drone, une station météo ou un ensemble domotique.

Arduino présente de nombreux avantages :
- elle est permet de réaliser des petits projets à la portée de tous grâce à des 
  interfaces de programmation intuitives par blocs
- elle permet de construire des projets ambitieux car elle dispose de nombreuses
  entrées/sorties peut se programmer avec un langage très complet.
- elle est très populaire et l'Internet fourmille de tutoriels et d'idées de
  projets
- elle est solide
- elle est peu onéreuse (entre 30€ pour une carte Arduino Uno officielle et 
  moins de 2€ pour certaines cartes compatibles)

# Quelle carte Arduino choisir ?

On peut être perdu dans l'offre proposée chez les différents marchands de
matériel électronique.  Arduino Uno, Genuino, Arduino Nano, Leonardo, Arduino
mega, Seeduino... sans parler des génériques sans véritable nom.

![img]({{ site.baseurl }}/images/presentationArduino/gamme.png)

À l'origine, c'est la carte Arduino Uno qui a fait le succès de ce type de
carte.  Elle a été développée en italie pour rendre l'électronique plus
accessible.  Depuis, Arduino est devenu un standard et les cartes faisant
référence à ce nom sont compatibles, ce qui signifie que les programmes qu'on
pourra écrire pour l'une fonctionneront pour les autres.

Aujourd'hui, les cartes nommées UNO quelle qu'en soit la marque sont des clones
les unes des autres. Le choix est une question de prix et de qualité.

Pour démarrer, les sites marchands proposent des kits contenant une carte
arduino et divers composants électroniques (capteurs, moteurs, diodes...).  Ces
kits sont souvent accompagnés de petits manuels pour s'initier sans peine.

Pour de projets très ambitieux, on pourra se tourner vers les cartes Arduino
Yun, Leonardo ou Mega.  Si le volume ou le poids sont des critères, on choisira
les cartes Arduino Nano ou Mini. L'offre est très étoffée ; Il existe même une
version nommée lilypad qui peut être cousue pour s'intégrer à un vêtement !

<https://www.arduino.cc/en/Main/Products>

# Programmation d'une carte Arduino

Programmer une carte arduino, c'est donner des instructions au circuit intégré
(le mini-ordinateur qui est le cœur de la carte) pour qu'il traite les
informations données par les capteurs et envoie des informations aux
actionneurs qui vont agir sur le monde physique.

Pour programmer, on peut commencer en utilisant des environnements de
développement par blocs qui ressemeblent à Scratch

- BlocklyDuino : <http://easycoding.tn/bde/demos/code/?lang=fr>
- Blockly@rduino : <http://www.techmania.fr/BlocklyDuino/>

Voici une exemple dans lequel 4 blocs ont été disposés pour faire clignoter
au rythme de 1 seconde la LED de la carte Arduino (pin 13)
![img]({{ site.baseurl }}/images/arduinoAndroid/blockly.png)

Pour ceux qui préfèrent écrire le code à la main, il existe des environnements 
de développement dédiés, à installer ou en ligne : 
<https://www.arduino.cc/en/main/software>

![img]({{ site.baseurl }}/images/presentationArduino/ide.png)

# Branchement des composants

Avant de contruire réellement le circuit électrique avec la carte Arduino et
tous ses composants, il est possible de simuler le montage et de tester le code
sur une plateforme nommée circuits.io.

Voici par exemple un petit montage pour un jeu de lumières avec quatre diodes
électroluminescentes (DEL ou LED). À gauche le montage en cours de construction
sur circuits.io et à droite le montage réalisé.

![img]({{ site.baseurl }}/images/presentationArduino/montage1.png)

