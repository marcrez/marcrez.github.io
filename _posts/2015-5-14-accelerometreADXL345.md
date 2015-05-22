---
title: Acceleromètre ADXL345 sous RaspberryPi
layout: post
date: 2015-05-14 13:30:00
tags: [Raspberry, Python]
category: Raspberry
---

Le module ADXL345 est un accéléromètre à trois axes.
Dans cet article, nous allons voir comment l'utiliser pour construire un
niveau à bulle éléctronique.

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

1. Lancer la commande `sudo nano /etc/modules` pour ajouter au fichier
   `modules` les deux lignes suivantes 
   *(Ctrl+O puis Ctrl+X pour enregistrer puis quitter nano)*
   ```
   i2c-bcm2708 
   i2c-dev
   ```
2. Si le fichier `/etc/modprobe.d/raspi-blacklist.conf` existe 
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


## Récupérer une librairie pour piloter le module

Un projet qui fonctionne :
https://github.com/pimoroni/adxl345-python/blob/master/adxl345.py

Mais on va utiliser celui proposé par AdaFruit

```
$ wget https://raw.githubusercontent.com/adafruit/Adafruit-Raspberry-Pi-Python-Code/master/Adafruit_I2C/Adafruit_I2C.py
```


## Montage

Commençons par raccorder les pattes du module au Raspberry

ADXL345 | Raspberry Pi
--------|-------------
   GND  | GND
  3.3V  | 3.3V
  SCL0  | SCL
  SDA0  | SDA
    CS  | 3.3V
   SDO  | GND

Maintenant, les quatre LEDs qui indiqueront la direction où le module penche.

![ADXL345]({{ site.baseurl }}/images/accelerometreADXL345/ADXL345.png)

# Code Python

