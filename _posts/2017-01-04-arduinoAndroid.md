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
   - soit une carte compatible (moins de 5€) avec son câble de connexion qui peut être USB-A - Micro-USB-A.
     ![img]({{ site.baseurl }}/images/arduinoAndroid/robotdyn.jpg)

2. Il faut aussi un câble USB OTG pour brancher le cable arduino
   sur le port USB du téléphone.

   ![img]({{ site.baseurl }}/images/arduinoAndroid/USB-OTG.jpg)


![img]({{ site.baseurl }}/images/arduinoAndroid/cablage.jpg)

## Installation sur la tablette ou le téléphone Android

Pour programmer la carte Arduino il faut une application permettant
d'écrire des programmes et de se connecter à la carte pour y déposer
le code. C'est ce que fait l'application arduinoDroid, disponible sur
Google Play


[![img]({{ site.baseurl }}/images/arduinoAndroid/arduinodroid.png)](https://play.google.com/store/apps/details?id=name.antonsmirnov.android.arduinodroid2&hl=fr)

