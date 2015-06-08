---
title: Codeur rotatif et afficheur 7 segments sous RaspberryPi
permalink: raspberryPi-codeurRotatif-afficheur7segments-led
layout: post
date: 2015-05-15 20:31:00
tags: [raspberryPi, python]
category: raspberryPi
---

Dans cet article, on va décrire comment pour piloter un affichier LED à sept
segments via un multiplexeur 74HC595N.
On va aussi faire fonctionner un codeur rotatif.
Le but est de simuler le comportement d'un bouton de volume.

Le comportement sera le suivant 

- L'appui sur le bouton central, allume ou éteint l'afficheur LED
- La rotation dans le sens des aiguilles d'une montre incrémente 
  le compteur qui s'affiche avec un maximum à 9
- La rotation dans le sens inverse des aiguilles d'une montre décrémente
  le compteur qui s'affiche avec un minimum à 0



## Fonctionnement de l'afficheur LED 7 segments

![7 segments](http://upload.wikimedia.org/wikipedia/commons/thumb/a/ad/Seven_segment_02_Pengo.jpg/280px-Seven_segment_02_Pengo.jpg)

Il y a deux sortes d'afficheurs 7 segments

- afficheur à **anode** commune : toutes les anodes sont reliées et connectées au
  potentiel haut. La commande du segment se fait par sa cathode mise au
  potentiel bas.
- afficheur à **cathode** commune : toutes les cathodes sont reliées et connectées
  au potentiel bas.  La commande du segment se fait par son anode mise au
  potentiel haut.


Le kit [*Sunfounder Project Super Starter Kit for Raspberry Pi*](http://www.amazon.fr/gp/product/B00P2E9W30?psc=1&redirect=true&ref_=oh_aui_detailpage_o04_s00)
fournit deux afficheurs à cathode commune, c'est de ce type d'afficheur dont il
est désormais question.

Un afficheur 7 segments (8 en fait si on compte le DP pour *Decimal Point* 
en bas à droite) possède 10 connecteurs.

- deux cathodes communes, on relie l'une d'entre elles à la masse via une
  résistance de 200&#8486;.
- 8 connecteurs qui recevront directement un signal haut ou bas pour allumer ou
  éteindre chacun des segments.

> Remarque : Oui, c'est vrai il y a un problème. En n'utilisant qu'une
> résistance sur la cathode commune, les lois de l'électricité nous apprennent
> que l'intensité pour chacun des segments va dépendre du nombre de segments
> allumés : un `1` avec ses 2 segments allumés sera 3 fois plus lumineux qu'un
> `0` avec ses 6 segments allumés.   
> Le montage correct consiste à relier une des deux cathodes communes à la
> masse et connecter les 8 segments via chacun une résistance de 200&#8486;.   
> Voir à ce sujet
> [un bon article en anglais](http://melabs.com/resources/articles/ledart.htm).

Maintenant, reste à connaitre le schema de branchement 
pour allumer les bons segments.

![74HC595N schema]({{ site.baseurl }}/images/7segments/7_segment_display_labeled.png)    

### Le registre à décalage 74HC595N

Pour commander les 7 (8 en fait) segments de l'afficheur, on devrait utiliser
autant de broches GPIO.  Ce n'est pas ainsi qu'on va procéder, nous allons voir
comment multiplexer l'afficheur 7 Segments avec un registre à décalage
74HC595N.

![74HC595N]({{ site.baseurl }}/images/7segments/74hc595n.jpeg)

Pour faire simple, un registre à décalage reçoit une entrée série
(signaux à la suite les uns des autres) sur une broche et renvoie une sortie 
parallèle sur 8 broches.


![74HC595N schema]({{ site.baseurl }}/images/7segments/74HC595N.png)    
(image issue de [DatasheetCatalog.com](http://www.datasheetcatalog.com/datasheets_pdf/7/4/H/C/74HC595N.shtml) )

- les broches 8 `GND` et 13 `OE` sont reliées à la masse
- la broche 16 `VCC` est reliée au +5V
- Les 8 sorties, de `Q0` à `Q7` vont être connectées aux segments de
  l'afficheur : `Q0` sur `A`, `Q1` sur `B`, ... , `Q5` sur `F`, `Q6` sur `G` 
  et `Q7` sur `DP`.

Le principe de fonctionnement est le suivant :

À chaque pulsation sur l'horloge (broche 11 `SHCP`), l'état HIGH ou LOW de
l'entrée série (broche 14 `DS`) est enregistré dans le STORAGE REGISTER et les
bits précedement enregistrés sont décalés d'un cran.

Durant les opérations d'enregistrement des données, rien ne semble se passer ;
ceci grâce au loquet : *latch* en anglais (broche 12 `STCP`).  Tant que le
*latch* est LOW, les sorties restent dans leur état, mais s'il passe à
HIGH, les valeurs des 8 bits du STORAGE REGISTER sont envoyées aux
8 sorties `Q0` à `Q7`.

Concernant les trois dernières broches, on a

- La broche *Memory Reset* (broche 10 `MR`) reçoit un état HIGH en général. 
  Un signal LOW efface le STORAGE REGISTER. 
- La broche *Output Enable* (broche 13 `OE`) doit être LOW pour qu'il y ait
  affichage.
- La broche (broche 9 `Q7S`) permet de brancher un second circuit 74HC595N
  en cascade, cette broche sera alors reliée à l'entrée série `DS` du suivant.

> Remarque : Si `MR` et `OE` sont surmontées d'une barre, c'est parcequ'il
> s'agit de commandes inversées : les états à appliquer pour leur fonctionnment
> sont contre-intuitifs.

### Branchement et mise en route

![74HC595N schema]({{ site.baseurl }}/images/7segments/7segments2.png)    


Mettons tout cela en application dans un petit programme Python.
Pour obtenir l'animation suivante dans laquelle chaque segment est allumé tour à
tour.

![Anim]({{ site.baseurl }}/images/7segments/7segAnim96.gif)

Se référer à 
l'article [*LED et poussoir*]({% post_url 2015-5-26-raspberryLedPoussoir %})
si besoin.


```python
import RPi.GPIO as GPIO
import time

# Les broches GPIO du RaspberryPi
DATA=18   # vers DS
CLOCK=23  # vers SHCP
LATCH=24  # vers STCP
CLEAR=25  # vers MR

# Initialisation
GPIO.setmode(GPIO.BCM)
GPIO.setup(DATA,GPIO.OUT, initial=GPIO.LOW)
GPIO.setup(CLOCK,GPIO.OUT, initial=GPIO.LOW)
GPIO.setup(LATCH,GPIO.OUT, initial=GPIO.LOW)
GPIO.setup(CLEAR,GPIO.OUT, initial=GPIO.LOW)
GPIO.output(CLEAR,GPIO.HIGH)
# le STORAGE REGISTER est clean : il contient 00000000

# On envoie 1 dans le STORAGE REGISTER
GPIO.output(DATA,GPIO.HIGH)
GPIO.output(CLOCK,GPIO.HIGH)
GPIO.output(CLOCK,GPIO.LOW)

# On affiche le contenu du STORAGE REGISTER : 00000001
# le segment A s'allume.
GPIO.output(LATCH,GPIO.HIGH)
GPIO.output(LATCH,GPIO.LOW)

# On envoie une serie de sept 0 consecutifs dans
# le STORAGE REGISTER qui va contenir tour a
# tour 00000010 (le segment B s'allume)
# puis 00000100 (le segment C s'allume)
# puis 00001000 (le segment D s'allume) ... etc.
for i in range(0,7):
  time.sleep(1) # allume 1 seconde
  GPIO.output(DATA,GPIO.LOW)
  GPIO.output(CLOCK,GPIO.HIGH)
  GPIO.output(CLOCK,GPIO.LOW)
  GPIO.output(LATCH,GPIO.HIGH)
  GPIO.output(LATCH,GPIO.LOW)

time.sleep(1)
GPIO.cleanup()
```


Les bases sont maintenant posées, on peut théoriquement afficher des chiffres.
Essayons avec le chiffre 2. Pour cela il va falloir allumer les segments 
A, B, D, E et G.
Autrement dit, remplir le STORAGE REGISTER avec `11011010`.
On va donc pousser successivement les bits dans l'ordre inverse
`01011011` ce qui revient à `1011011`, le premier 0 étant inutile.

![2](http://upload.wikimedia.org/wikipedia/commons/thumb/f/f8/7-segment_abdeg.svg/144px-7-segment_abdeg.svg.png)


```python
#!/usr/bin/python
import RPi.GPIO as GPIO
import time

# Init
DATA=18   #DS
CLOCK=23  #SHCP
LATCH=24  #STCP
CLEAR=25  #MR

GPIO.setmode(GPIO.BCM)
GPIO.setup(DATA,GPIO.OUT, initial=GPIO.LOW)
GPIO.setup(CLOCK,GPIO.OUT, initial=GPIO.LOW)
GPIO.setup(LATCH,GPIO.OUT, initial=GPIO.LOW)
GPIO.setup(CLEAR,GPIO.OUT, initial=GPIO.LOW)
GPIO.output(CLEAR,GPIO.HIGH)

seq = [1,0,1,1,0,1,1]

# on envoie la sequence dqns le STORAGE REGISTER
for i in seq:
  if i==1:
    GPIO.output(DATA,GPIO.HIGH)
  else:
    GPIO.output(DATA,GPIO.LOW)
  GPIO.output(CLOCK,GPIO.HIGH)
  GPIO.output(CLOCK,GPIO.LOW)

# On affiche le contenu du STORAGE REGISTER
# le chiffre 2 apparait
GPIO.output(LATCH,GPIO.HIGH)
GPIO.output(LATCH,GPIO.LOW)

time.sleep(5)
# Extinction des segments
GPIO.setup(CLEAR,GPIO.OUT, initial=GPIO.LOW)
GPIO.output(LATCH,GPIO.HIGH)

# Nettoyage des broches
GPIO.cleanup()
```


# Se simplifier la tâche de programmation

Afin d'accéder plus facilement au multiplexeur 74HC595N, nous utilisons la
library *PiShiftPy*
Auparavant, on raccorde directement la broche 10 (`MR`) sur le +5V car
PiShiftPy ne gère pas le reset qui doit donc être relié au potentiel haut.

Pour télécharger PiShiftPy, c'est simple

```
$ wget https://raw.githubusercontent.com/shrikantpatnaik/PiShiftPy/master/build/lib/PiShiftPy.py
```

Nous allons pouvoir désormais facilement afficher des chiffres dès lors qu'on
sait comment les représenter sur l'afficheur

Chiffre | `DP G  F  E  D  C  B  A` | Valeur Hexa
--------|--------------------------|:-----------
   0    | `0  0  1  1  1  1  1  1` | 3F
   1    | `0  0  0  0  0  1  1  0` | 06
   2    | `0  1  0  1  1  0  1  1` | 5B
   3    | `0  1  0  0  1  1  1  1` | 4F
   4    | `0  1  1  0  0  1  1  0` | 66
   5    | `0  1  1  0  1  1  0  1` | 6D
   6    | `0  1  1  1  1  1  0  1` | 7D
   7    | `0  0  0  0  0  1  1  1` | 07
   8    | `0  1  1  1  1  1  1  1` | 7F
   9    | `0  1  1  0  1  1  1  1` | 6F



```python
#!/usr/bin/env python

import PiShiftPy as shift
import time
import RPi.GPIO as GPIO

tab = [0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F]
print("de 0 a 9, c'est parti")

shift.init(18, 23, 24) # Data_in, clock, latch
for i in tab:
  shift.write(i)
  time.sleep(1)

print("\nOn eteint la lumiere.")

# Arrete et nettoie les broches pour les liberer
# en vue d'une prochaine utilisation.
shift.init()
GPIO.cleanup()
```


## Fonctionnement du codeur rotatif

On commence par vérifier le fonctionnement de l'encodeur rotatif en
affichant des messages à l'écran.


### Les connexions

D'abord les branchements

Rotary encoder | Raspberry Pi
---------------|-------------
           CLK | GPIO 21
            DT | GPIO 20
            SW | GPIO 16
             + | GPIO 5V
           GND | GPIO Ground

![rotary]({{ site.baseurl }}/images/7segments/rotary.png)


### Le code

Il existe de nombreuses façons de programmer l'intéraction avec le codeur
rotatif. Ici on va se baser sur la classe `RotaryEncoder` de Bob Rathbone.


```
$ wget https://raw.githubusercontent.com/bobrathbone/pirotary/master/rotary_class.py
```

Une fois le fichier `rotary_class.py` déposé dans le bon dossier,
ouvrons leafpad pour écrire le programme suivant qu'on nomme `rotary.py`


```python
from rotary_class import RotaryEncoder
from time import sleep

# Define GPIO inputs
SW = 16
DT = 20
CLK = 21

# Fonction de callback qui agit selon les evenements
def switch_event(event):
        if event == RotaryEncoder.CLOCKWISE:
              print("Plus")
              sleep(.2)
        elif event == RotaryEncoder.ANTICLOCKWISE:
              print("Moins")
              sleep(.2)
        elif event == RotaryEncoder.BUTTONDOWN:
              print("Bdown")
        return

# Definit la détection de front
rswitch = RotaryEncoder(CLK,DT,SW,switch_event)

try:
  print("Le programme fonctionne pendant 60s.")
  sleep(60)

except KeyboardInterrupt:
  print("\nInterruption par clavier.")

finally:
  print("On arrete tout")
```

On peut maintenant lancer le programme 

```
$ sudo python rotary.py
```

et observer la console lorsqu'on agit sur
le codeur en appuyant sur le poussoir ou tournant dans un sens ou dans l'autre.

## Fin

```python
from rotary_class import RotaryEncoder
import PiShiftPy as shift
from time import sleep
import RPi.GPIO as GPIO

# Define GPIO inputs
SW = 13
DT = 19
CLK = 26
shift.init(18,23,24)

# This is the event callback routine to handle events
def switch_event(event):
        global i
        global tab
        global ON
        if event == RotaryEncoder.CLOCKWISE:
              i = i+1
              shift.write(tab[i])
              sleep(.5)
        elif event == RotaryEncoder.ANTICLOCKWISE:
              i = i-1
              shift.write(tab[i])
              sleep(.5)
        elif event == RotaryEncoder.BUTTONDOWN:
              if ON:
                shift.init()
                ON = False
              else:
                i = 5
                shift.write(tab[i])
                ON = True
        return

# Define the switch
rswitch = RotaryEncoder(CLK,DT,SW,switch_event)

try:
  print("Le programme fonctionne pendant 60s.")
  tab = [0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F]
  i = 5
  ON = True
  sleep(30)

except KeyboardInterrupt:
  print("\nInterruption par clavier.")

finally:
  print("On arrete tout")
  shift.init()
  GPIO.cleanup()
```

