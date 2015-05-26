---
title: Accéleromètre ADXL345 sous RaspberryPi
layout: post
date: 2015-05-14 13:30:00
tags: [Raspberry, Python]
category: Raspberry
---

Le module ADXL345 est un accéléromètre à trois axes.
Dans cet article, nous allons voir comment l'utiliser pour construire un
niveau à bulle éléctronique.

![ADXL345]({{ site.baseurl }}/images/accelerometreADXL345/ADXL345.png)

## Installations et configurations

Sous Raspbian, pour pouvoir communiquer avec le module ADXL345,
il faut installer des outils complémentaires

```
$ sudo apt-get update
$ sudo apt-get install python-smbus i2c-tools
```

Ensuite, on active le chargement automatique du module I2C au noyau
dans le menu 8 *Advanced Options* 

```
$ sudo raspi-config
```

Repondre Yes à tout puis redémarrer.

Sous Raspbian, il reste du travail à faire.

- Lancer la commande `sudo nano /etc/modules` pour ajouter au fichier
  `modules` les deux lignes suivantes 
  *(Ctrl+O puis Ctrl+X pour enregistrer puis quitter nano)*

  ```
  i2c-bcm2708 
  i2c-dev
  ```
- Si le fichier de blacklist existe
  (`ls /etc/modprobe.d/` pour vérifier),
   lancer la commande `sudo nano /etc/modprobe.d/raspi-blacklist.conf` 
   pour commenter avec un `#` les éventuelles
   lignes suivantes 
   *(Ctrl+O puis Ctrl+X pour enregistrer puis quitter nano)*

   ```
   # blacklist spi-bcm2708
   # blacklist i2c-bcm2708
   ```
3. Dans le fichier `/boot/config.txt`, si les deux lignes suivantes ne sont pas présentes,
   les ajouter en fin de fichier en lançant la commande `sudo nano /boot/config.txt`
   *(Ctrl+O puis Ctrl+X pour enregistrer puis quitter nano)*

   ```
   dtparam=i2c1=on
   dtparam=i2c_arm=on
   ```


Pour plus de détails, voir https://learn.adafruit.com/adafruits-raspberry-pi-lesson-4-gpio-setup/configuring-i2c


## Une librairie pour piloter le module

On va utiliser celui proposé par AdaFruit

```
$ wget https://raw.githubusercontent.com/adafruit/Adafruit-Raspberry-Pi-Python-Code/master/Adafruit_I2C/Adafruit_I2C.py
$ wget https://raw.githubusercontent.com/adafruit/Adafruit-Raspberry-Pi-Python-Code/master/Adafruit_ADXL345/Adafruit_ADXL345.py
```

Un autre projet qui fonctionne :
https://github.com/pimoroni/adxl345-python/blob/master/adxl345.py


## Premier montage

Commençons par raccorder les pattes du module au Raspberry

   ADXL345 | Raspberry Pi
----------:|:------------
      GND  | GND
  VCC3.3V  | 3.3V
      SCL  | SCL
      SDA  | SDA
       CS  | 3.3V
      SDO  | GND

On verifie que la détection des périphériques i2c renvoie bien au moins une
valeur. SI c'est bien le cas, on va pouvoir continuer, sinon, reprendre le
premier paragraphe sur les installations et configurations

```
$ sudo i2cdetect -y 1
```


On va Maintenant vérifier que le module communique avec le Raspberry. En
penchant le module, les valeurs sont modifiées.

```
$ sudo python Adafruit_ADXL345.py
[5, -13, -258]
[6, -15, -257]
[5, -13, -255]
```

## Le niveau à bulle électronique

On va raccorder les quatre LEDs sur les pin GPIO 12, 16, 20 et 21
qui indiqueront en s'allumant la direction où le module penche.

![ADXL345]({{ site.baseurl }}/images/accelerometreADXL345/schema.png)

# Code Python

```python
#!/usr/bin/env python

from time import sleep
import RPi.GPIO as GPIO
from Adafruit_I2C import *
from Adafruit_ADXL345 import *

FREQ = 100 #Hz 
RUNNING = True

GPIO.setmode(GPIO.BCM)
i

fwd = 21
GPIO.setup(fwd, GPIO.OUT)
FWD = GPIO.PWM(fwd, FREQ)

bwd = 16
GPIO.setup(bwd, GPIO.OUT)
BWD = GPIO.PWM(bwd, 100)

lft = 12
GPIO.setup(lft, GPIO.OUT)
LFT = GPIO.PWM(lft, 100) 

rgt = 20
GPIO.setup(rgt, GPIO.OUT)
RGT = GPIO.PWM(rgt, 100)

accel = Adafruit_ADXL345()

try:
    while RUNNING:
        sleep(0.1) 
        print accel.read()
        RGT.start(0)
        FWD.start(0)
        BWD.start(0)
        LFT.start(0)
        if (accel.read()[0]<-5):
          RGT.ChangeDutyCycle(100)
        if (accel.read()[1]<-5):
          FWD.ChangeDutyCycle(100)
        if (accel.read()[1]>5):
          BWD.ChangeDutyCycle(100)
        if (accel.read()[0]>5):
          LFT.ChangeDutyCycle(100)

except KeyboardInterrupt:
    RUNNING = False
    print("\nFin. On eteint les lumieres.")

finally:
    # Arrete et nettoie les broches pour les liberer
    # en vue d'une prochaine utilisation.
    GPIO.cleanup()
```

