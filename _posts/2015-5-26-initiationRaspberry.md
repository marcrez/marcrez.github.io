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

>  Remarque : C'est une différence importante avec Arduino qui est capable, lui,
>  de lire les signaux digitaux aussi bien qu'analogiques.

RaspberryPi 2 est doté de 40 broches de sortie dont 25 broches GPIO.

![GPIO]({{ site.baseurl }}/images/iniRasp/rPi-GPIO.png)

Pour désigner les broches GPIO, on peut 
- soit donner leur numéro sur la carte *BOARD* en anglais, de 1 à 40
- soit donner le nom de GPIO de 2 à 26 dans la nomenclature *BCM* (pour *Broadcom SoC channel*)

Par exemple la broche 18 dans la nomenclature BOARD correspond 
à la GPIO 18 dans la nomenclature BCM.

On on reparlera dans le paragraphe qui vient.

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
3. On déclare la broche GPIO21 comme sortie. Elle délivrera    
   - soit un signal haut (un 1, c'est à dire une tension de +3,3V)    
   - soit un signal bas (un 0, c'est à dire 0V)
4. On modifie l'état de sortie de la broche GPIO21, qui passe à 1. Cela devrait
   envoyer un courant de 3,3V dans le circuit de la LED qui va s'allumer.

Concernant le montage, on raccorde l'anode de la LED (patte longue) sur la
GPIO21 puis on raccorde à la masse (broche GND) en intercalant en serie une
resistance de 500 à 1k Ohms afin de limiter l'intensité (la résistance interne
d'une LED étant très faible).

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

>  Remarque : Un message Warning apparaît. Il dit que le GPIO21 n'a pas été purgé
>  lors de la précédente session. On verra comment régler ce problème.

## Suite : commander une LED avec un bouton pousoir

Le principe de base étant posé, on va maintenant intéragir avec le RaspberryPi
via un bouton poussoir.

On choisit ici de raccorder (pourquoi pas ?)  la broche GPIO16 au bouton 
poussoir. 
Par mesure de sécurité, le raccordement au 3,3V se fait via
une résistance pour éviter un court circuit si par erreur le GPIO16 était
configuré en sortie plutôt qu'en entrée.
Un court-circuit sur une sortie sur RaspberryPi pourrait l'endommager.


![PullUp](http://upload.wikimedia.org/wikipedia/commons/thumb/1/12/Switch_Pull_Up_Circuit.png/220px-Switch_Pull_Up_Circuit.png)

Voici donc le montage

![Montage LED avec BP]({{ site.baseurl }}/images/iniRasp/ledEtBp.png)

En cas d'appui sur le bouton poussoir, le GPIO16 ne reçoit plus le signal
qui part directement à la terre On a donc

    Bouton relâché : GPIO16 à l'état 1 (ou True)
    Bouton enfoncé : GPIO16 à l'état 0 (ou False)

Le programme `led.py` s'écrit donc de la manière suivante

{% highlight python linenos %}
import RPi.GPIO as GPIO
# La numerotation choisie pour nommer les broches
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

## Mise au propre du code

La boucle `while True` de la ligne 9 du programme précédent permet de détecter
les changements d'état : à chaque tour de boucle, on vérifie quel est l'état de
l'entrée GPIO. Cela fonctionne mais c'est gourmand en ressources processeur pour
pas grand chose.

Une meilleure façon de procéder ici, c'est d'utiliser une détection de front :
on surveille les changemets d'état du bouton poussoir pour déclencher une
interruption.

La fonction `GPIO.add_event_detect(channel, GPIO.BOTH, callback=my_callback)`
ajoute sur la broche `channel` une detection de front `GPIO.BOTH` qui déclenche
une un thread parallèle `my_callback`.

voir http://deusyss.developpez.com/tutoriels/RaspberryPi/PythonEtLeGpio/#LIII-B-9
et http://sourceforge.net/p/raspberry-gpio-python/wiki/Inputs/
pour plus de détails

{% highlight python linenos %}
import RPi.GPIO as GPIO  # Gestion des GPIO
from time import sleep   # Gestion du temps

GPIO.setmode(GPIO.BCM)   # La numerotation choisie
GPIO.setup(21, GPIO.OUT) # Une sortie : la LED
GPIO.setup(16, GPIO.IN)  # Une entree : le poussoir

def my_callback(channel):
  if GPIO.input(channel):
    print('GPIO %s 0->1' %channel)
    GPIO.output(21, GPIO.LOW)
  else:
    print('GPIO %s 1->0' %channel)
    GPIO.output(21, GPIO.HIGH)

print("Le programme prendra fin dans 30s.")
print("Vous pouvez aussi terminer avec CTRL+C \n")

GPIO.add_event_detect(16, GPIO.BOTH, callback=my_callback)
print("Maintenant, le programme surveille les actions sur le poussoir\n")

try:
  sleep(30)

except KeyboardInterrupt:
  print("\nInterruption par clavier.")

finally:
  print("On arrete et nettoie les broches pour les liberer")
  print("en vue d'une prochaine utilisation.")
  GPIO.cleanup()
{% endhighlight %}


Un article complémentaire très bien fait : 
http://eskimon.fr/96-arduino-204-un-simple-bouton


