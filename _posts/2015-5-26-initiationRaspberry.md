---
title: Initiation RaspberryPi
layout: post
date: 2015-05-26 13:30:00
tags: [Raspberry, Python]
category: Raspberry
---

## Les connecteurs GPIO

Les ports GPIO (General Purpose Input/Output) sont des ports d'entrée/sortie
qui offrent à une carte électronique la possibilité de communiquer avec
d'autres circuits électroniques via des signaux numériques (1 ou 0)
exclusivement.

RaspberryPi ne dispose pas d'entrée/sortie analogique. La connexion à un
dispositif analogique devra passer donc passer par un A/D (Analog to Digital
Converter) comme le MCP3008.

Remarque : C'est une différence importante avec Arduino qui est capable, lui,
de lire les signaux digitaux aussi bien qu'analogiques.

RaspberryPi 2 est doté de 40 broches de sortie dont 25 broches GPIO.

![GPIO]({{ site.baseurl }}/images/iniRasp/rPi-GPIO.png)

## Premier montage : allumer une LED

Pour programmer les états allumé/éteitnt d'une diode, il faut un langage
de programmation et une bibliothèque (on utilisera l'anglicisme *librairie*)
pour que ce langage soit capble de communiquer
avec les entrées/sorties de broches.

Il est possible de travailler en C ou Java, ici, c'est Python qui est choisi et
la librairie RPi.GPIO.

Dans l'editeur de texte Leafpad, on va créer un programme python nommé `led.py`

{% highlight python linenos %}
import RPi.GPIO as GPIO
GPIO.setmode(GPIO.BCM)
GPIO.setup(21, GPIO.OUT)
GPIO.output(21, GPIO.HIGH)
{% endhighlight %}

Explications ligne par ligne

1. On commence par importer la librairie RPi.GPIO qu'on nomme GPIO. 
   Ses fonctions, classes et méthodes seront désormais disponibles.
2. On déclare la numérotation choisie pour se référer aux broches
   de sortie. On a choisi GPIO.BCM plutôt que GPIO.BOARD ce qui va permettre
   de parler de la broche nommée GPIO21 plutôt que de la broche numéro 40
   de la carte. Choisir BCM plutôt que BOARD permet permet juste de se
   simplifier le repérage.
3. On déclare la broche GPIO21 comme sortie. Elle délivrera soit un
   signal haut (un 1, c'est à dire une tension de +3,3V) soit un signal
   bas (un 0, c'est à dire 0V)
4. On modifie l'état de sortie de la broche GPIO21, qui passe à 1.

Concernant le montage, on raccorde l'anode (patte longue) sur la GPIO21 puis
on raccorde à la masse (broche GND) en intercalant en serie une resistance de
500 à 1k Ohms afin de limiter l'intensité (la résistance interne d'une LED étant
très faible).

![Montage LED]({{ site.baseurl }}/images/iniRasp/led.png)

Maintenant que tout est raccordé, on peut lancer le programme. Dans la console,
on lance la commande suivante avecles droits d'administratuer car les ports
GPIO ne sont accessibles qu'en mode root.

```
$ sudo python led.py
```

La diode s'allume. Pour l'éteindre, on va modifier la dernière ligne comme suit
avant de relancer le programme.

```python
GPIO.output(21, GPIO.LOW)
```

Remarque : Un message Warning apparaît. Il dit que le GPIO21 n'a pas été purgé
lors de la précédente session. On verra comment régler ce problème.

## Suite : commander une LED avec un bouton pousoir

Le principe de base étant posé, on va maintenant intéragir avec le RaspberryPi
via un bouton poussoir.

On choisit ici de raccorder (pourquoi pas ?)  la broche GPIO16 au bouton 
poussoir. 
Par mesure de sécurité, le bouton poussoir est raccordé à la terre via 
une résistance pour éviter un court circuit si par erreur le GPIO16 était
configuré en sortie plutôt qu'en entrée.
Un court-circuit sur une sortie sur RaspberryPi pourrait l'endommager.

![Montage LED avec BP]({{ site.baseurl }}/images/iniRasp/ledEtBp.png)

Le programme `led.py`

{% highlight python linenos %}
import RPi.GPIO as GPIO
# La numerotation suivant la carte BROADCOM
GPIO.setmode(GPIO.BCM)
# Une broche pour la sortie : la LED
GPIO.setup(21, GPIO.OUT)
# Une broche pour l'entree : Le poussoir
GPIO.setup(16, GPIO.IN)

while True:
# Le programme tourne en boucle dans
# l'attente d'evenement sur le poussoir
if (GPIO.input(16) == True):
    GPIO.output(21, GPIO.LOW)
  else :
    GPIO.output(21, GPIO.HIGH)
{% endhighlight %}


