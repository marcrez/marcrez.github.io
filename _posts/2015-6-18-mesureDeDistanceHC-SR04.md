---
title: HC-SR04 Mesure de distance par ultrasons (en cours d'écriture)
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

![branchement]({{ site.baseurl }}/images/HC-SR04/branchement.png)

Sur le schéma de [circuitLab](https://www.circuitlab.com/circuit/4znzk9/raspberry-pi-ultrasonic-module/)
on propose 330 et 470 Ohm. On peut évidemment modifier ces valeurs.

En choisissant $R_1 = 220\Omega$ (rouge-rouge-marron ou rouge-rouge-noir-noir)
et $R_2 = 330\Omega$ (organge-orange-marron) la tension $U=5V$ sera divisée et
on aura $U_2=3V$
ce qui sera suffisant.

![Montage]({{ site.baseurl }}/images/HC-SR04/montage.png)

## Programme Python

On va utiliser le programme de 
[Matt Hawkins](http://www.raspberrypi-spy.co.uk/2012/12/ultrasonic-distance-measurement-using-python-part-1/)
pour faire fonctionner le module. La seule chose à faire sera d'adapter les numéros des groches GPIO au
montage qu'on aura cablé.

```python
#!/usr/bin/python
#+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
#|R|a|s|p|b|e|r|r|y|P|i|-|S|p|y|.|c|o|.|u|k|
#+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
#
# ultrasonic_1.py
# Measure distance using an ultrasonic module
#
# Author : Matt Hawkins
# Date   : 09/01/2013
# -----------------------

# Import required Python libraries
import time
import RPi.GPIO as GPIO

# Use BCM GPIO references
# instead of physical pin numbers
GPIO.setmode(GPIO.BCM)

# Define GPIO to use on Pi
GPIO_TRIGGER = 23
GPIO_ECHO    = 24

print "Ultrasonic Measurement"

# Set pins as output and input
GPIO.setup(GPIO_TRIGGER,GPIO.OUT)  # Trigger
GPIO.setup(GPIO_ECHO,GPIO.IN)      # Echo

# Set trigger to False (Low)
GPIO.output(GPIO_TRIGGER, False)

# Allow module to settle
time.sleep(0.5)

# Send 10us pulse to trigger
GPIO.output(GPIO_TRIGGER, True)
time.sleep(0.00001)
GPIO.output(GPIO_TRIGGER, False)
start = time.time()

while GPIO.input(GPIO_ECHO)==0:
  start = time.time()

while GPIO.input(GPIO_ECHO)==1:
  stop = time.time()

# Calculate pulse length
elapsed = stop-start

# Distance pulse travelled in that time is time
# multiplied by the speed of sound (cm/s)
distance = elapsed * 34300

# That was the distance there and back so halve the value
distance = distance / 2

print "Distance : %.1f" % distance

# Reset GPIO settings
GPIO.cleanup()
```




## Tests


Pour vérifier la fiabilité des mesures, on va effectuer deux séries de deux mesures 
avec deux HC-SR04 côte à côte.

![Tests]({{ site.baseurl }}/images/HC-SR04/tests.png)

Voici les résultats obtenus.

![echantillon]({{ site.baseurl }}/images/HC-SR04/echantillon.png)

Mis à part un bug sur la mesure à 15cm, on constate aue les quatre mesures 
en bleu sont proches de la mesure théorique en vert.
Il faudrait refaire une série de mseusre pour confirmer ce graphique.

Ci-dessous le programme utilisé pour générer ces statistiques.


```python
import RPi.GPIO as GPIO                    #Import GPIO library
import time                                #Import time library
import matplotlib.pyplot as plt
GPIO.setmode(GPIO.BCM)                     #Set GPIO pin numbering 

TRIG1 = 19
ECHO1 = 20
TRIG2 = 26
ECHO2 = 21 

GPIO.setup(TRIG1,GPIO.OUT)                  #Set pin as GPIO out
GPIO.setup(TRIG2,GPIO.OUT)                  #Set pin as GPIO out
GPIO.setup(ECHO1,GPIO.IN)                   #Set pin as GPIO in
GPIO.setup(ECHO2,GPIO.IN)                   #Set pin as GPIO in

d=0
x = [0]
y = [0]

while d!= -1:

  d = input("dist : ")
  
  GPIO.output(TRIG1, False)                 #Set TRIG as LOW
  #print "Waitng For Sensor To Settle"
  time.sleep(2)                            #Delay of 2 seconds

  GPIO.output(TRIG1, True)                  #Set TRIG as HIGH
  time.sleep(0.00001)                      #Delay of 0.00001 seconds
  GPIO.output(TRIG1, False)                 #Set TRIG as LOW

  while GPIO.input(ECHO1)==0:               #Check whether the ECHO is LOW
    pulse_start = time.time()              #Saves the last known time of LOW pulse

  while GPIO.input(ECHO1)==1:               #Check whether the ECHO is HIGH
    pulse_end = time.time()                #Saves the last known time of HIGH pulse 

  pulse_duration = pulse_end - pulse_start #Get pulse duration to a variable

  distance = pulse_duration * 17150        #Multiply pulse duration by 17150 to get distance
  distance = round(distance, 2)            #Round to two decimal points
  print "Distance:",distance  #Print distance with 0.5 cm calibration
  x.append(d)
  y.append(distance)

  GPIO.output(TRIG2, False)                 #Set TRIG as LOW
  #print "Waitng For Sensor To Settle"

  GPIO.output(TRIG2, True)                  #Set TRIG as HIGH
  time.sleep(0.00001)                      #Delay of 0.00001 seconds
  GPIO.output(TRIG2, False)                 #Set TRIG as LOW

  while GPIO.input(ECHO2)==0:               #Check whether the ECHO is LOW
    pulse_start = time.time()              #Saves the last known time of LOW pulse

  while GPIO.input(ECHO2)==1:               #Check whether the ECHO is HIGH
    pulse_end = time.time()                #Saves the last known time of HIGH pulse 

  pulse_duration = pulse_end - pulse_start #Get pulse duration to a variable

  distance = pulse_duration * 17150        #Multiply pulse duration by 17150 to get distance
  distance = round(distance, 2)            #Round to two decimal points
  print "Distance:",distance  #Print distance with 0.5 cm calibration
  x.append(d)
  y.append(distance)

print(x)
print(y)
plt.plot(x,y,'o')
plt.plot(x,x,'o')
plt.show()
```


x = [0, 3, 3, 3, 3, 5, 5, 5, 5, 8, 8, 8, 8, 10, 10, 10, 10, 15, 15, 15, 15, 20, 20, 20, 20, 13, 13, 13, 13, 23, 23, 23, 23, 25, 25, 25, 25, 28, 28, 28, 28, 30, 30, 30, 30, 35, 35, 35, 35, 40, 40, 40, 40, 50, 50, 50, 50]
y = [0, 2.98, 2.93, 3.48, 3.23, 5.06, 4.39, 4.99, 4.8, 7.85, 7.27, 7.87, 7.25, 9.88, 9.65, 9.79, 9.23, 17.18, 17.46, 18.38, 17.2, 21.23, 20.27, 21.3, 21.49, 13.38, 13.63, 13.38, 13.72, 23.34, 23.24, 23.34, 23.25, 25.01, 25.33, 25.0, 25.19, 27.82, 27.69, 27.8, 27.63, 29.71, 30.11, 29.75, 29.38, 34.75, 34.4, 34.82, 34.75, 39.75, 39.34, 39.7, 38.6, 50.32, 49.46, 49.89, 49.55]





