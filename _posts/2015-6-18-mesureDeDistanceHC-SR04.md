---
title: HC-SR04 Mesure de distance par ultrasons
layout: post
date: 2015-06-18 13:30:00
tags: [raspberryPi, python]
category: raspberryPi
---

![echolocation](https://upload.wikimedia.org/wikipedia/commons/8/82/Delfinekko.gif)
Le module HC-SR04 est un module à moins de 2€ constitué d'un emetteur et d'un
récepteur d'ultrasons. Comme le font les chauve-souris, ou les cétacés, 
il va mesurer le temps qui sépare l'emission de la reception de l'echo
lorsque le son rebondit contre la surface qui fait face au module.
La vitesse du son étant (relativement) constante, on en déduit la distance.

![Module]({{ site.baseurl }}/images/HC-SR04/module.png)

Lorsque la broche `Trig` reçoit un signal haut de plus de 10 microsecondes, le cylindre
marqué `T` (*Transmitter* qui est un petit haut-parleur) va
va envoyer une salve de 8 signaux ultrasons de 40kHz. Aussitôt, le cylindre marqué `R`
(*Reciever* qui est un petit micro) attend le retour de l'echo.
Si un retour a été entendu, le module va envoyer envoyer un signal haut sur la broche `Echo`
d'une durée proportionelle à la distance.

![Fonctionnement du HC-SR04]({{ site.baseurl }}/images/HC-SR04/timing.png)

## Le diviseur de tension

La [fiche technique](http://www.mpja.com/download/hc-sr04_ultrasonic_module_user_guidejohn.pdf)
nous apprend que la tension de fonctionnement du module est de 5V.
Les broches GPIO du raspberryPi reçoivent normalement du 3.3V, on va donc utiliser un montage 
[diviseur de tension](https://fr.wikipedia.org/wiki/Diviseur_de_tension) pour protéger la broche
branchée sur `echo`.

![diviseur de tension](https://upload.wikimedia.org/wikipedia/commons/thumb/d/d9/Pont_diviseur_tension.svg/220px-Pont_diviseur_tension.svg.png)

On connaît la loi d'Ohm : $U=R.I$ et la loi des mailles (ou loi de Kirchhoff) :
$U_1+U_2=U$.  Il vient alors d'une part $U_2=R_2.I$ et d'autre part
$U=(R_1+R_2)U$.  On en déduit que $\frac{U_2}{R_2} = \frac{U}{R_1+R_2}$ et donc
$U_2 = U \frac{R_2}{R_1+R_2}$

En choisissant $R_1 = 220\Omega$ (rouge-rouge-marron ou rouge-rouge-noir-noir)
et $R_2 = 330\Omega$ (organge-orange-marron) la tension $U=5V$ sera divisée et
on aura $U_2=3V$
ce qui sera suffisant.

## 




   HC-SR04 | Raspberry Pi
----------:|:------------
      VCC  | 3.3V
      Trig | GPIO 20
      Echo | GPIO 21
      Gnd  | GND


