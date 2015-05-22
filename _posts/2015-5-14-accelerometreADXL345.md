---
title: Acceleromètre ADXL345 sous Raspberry Pi
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

Mais on va utiliser celui-ci :


    $ wget https://raw.githubusercontent.com/adafruit/Adafruit-Raspberry-Pi-Python-Code/master/Adafruit_I2C/Adafruit_I2C.py

```python
#!/usr/bin/env python

# Python library for ADXL345 accelerometer.

# Copyright 2013 Adafruit Industries

# Permission is hereby granted, free of charge, to any person obtaining a
# copy of this software and associated documentation files (the "Software"),
# to deal in the Software without restriction, including without limitation
# the rights to use, copy, modify, merge, publish, distribute, sublicense,
# and/or sell copies of the Software, and to permit persons to whom the
# Software is furnished to do so, subject to the following conditions:

# The above copyright notice and this permission notice shall be included
# in all copies or substantial portions of the Software.

# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
# IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
# FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
# THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
# LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
# FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
# DEALINGS IN THE SOFTWARE.

from Adafruit_I2C import Adafruit_I2C


class Adafruit_ADXL345(Adafruit_I2C):

    # Minimal constants carried over from Arduino library

    ADXL345_ADDRESS          = 0x53

    ADXL345_REG_DEVID        = 0x00 # Device ID
    ADXL345_REG_DATAX0       = 0x32 # X-axis data 0 (6 bytes for X/Y/Z)
    ADXL345_REG_POWER_CTL    = 0x2D # Power-saving features control

    ADXL345_DATARATE_0_10_HZ = 0x00
    ADXL345_DATARATE_0_20_HZ = 0x01
    ADXL345_DATARATE_0_39_HZ = 0x02
    ADXL345_DATARATE_0_78_HZ = 0x03
    ADXL345_DATARATE_1_56_HZ = 0x04
    ADXL345_DATARATE_3_13_HZ = 0x05
    ADXL345_DATARATE_6_25HZ  = 0x06
    ADXL345_DATARATE_12_5_HZ = 0x07
    ADXL345_DATARATE_25_HZ   = 0x08
    ADXL345_DATARATE_50_HZ   = 0x09
    ADXL345_DATARATE_100_HZ  = 0x0A # (default)
    ADXL345_DATARATE_200_HZ  = 0x0B
    ADXL345_DATARATE_400_HZ  = 0x0C
    ADXL345_DATARATE_800_HZ  = 0x0D
    ADXL345_DATARATE_1600_HZ = 0x0E
    ADXL345_DATARATE_3200_HZ = 0x0F

    ADXL345_RANGE_2_G        = 0x00 # +/-  2g (default)
    ADXL345_RANGE_4_G        = 0x01 # +/-  4g
    ADXL345_RANGE_8_G        = 0x02 # +/-  8g
    ADXL345_RANGE_16_G       = 0x03 # +/- 16g


    def __init__(self, busnum=-1, debug=False):

        self.accel = Adafruit_I2C(self.ADXL345_ADDRESS, busnum, debug)

        if self.accel.readU8(self.ADXL345_REG_DEVID) == 0xE5:
            # Enable the accelerometer
            self.accel.write8(self.ADXL345_REG_POWER_CTL, 0x08)

    def setRange(self, range):
        # Read the data format register to preserve bits.  Update the data
        # rate, make sure that the FULL-RES bit is enabled for range scaling
        format = ((self.accel.readU8(self.ADXL345_REG_DATA_FORMAT) & ~0x0F) |
          range | 0x08)
        # Write the register back to the IC
        seld.accel.write8(self.ADXL345_REG_DATA_FORMAT, format)

    def getRange(self):
        return self.accel.readU8(self.ADXL345_REG_DATA_FORMAT) & 0x03

    def setDataRate(self, dataRate):
        # Note: The LOW_POWER bits are currently ignored,
        # we always keep the device in 'normal' mode
        self.accel.write8(self.ADXL345_REG_BW_RATE, dataRate & 0x0F)

    def getDataRate(self):
        return self.accel.readU8(self.ADXL345_REG_BW_RATE) & 0x0F

    # Read the accelerometer
    def read(self):
        raw = self.accel.readList(self.ADXL345_REG_DATAX0, 6)
        res = []
        for i in range(0, 6, 2):
            g = raw[i] | (raw[i+1] << 8)
            if g > 32767: g -= 65536
            res.append(g)
        return res

# Simple example prints accelerometer data once per second:
if __name__ == '__main__':

    from time import sleep

    accel = Adafruit_ADXL345()

    print '[Accelerometer X, Y, Z]'
    while True:
        print accel.read()
        sleep(1) # Output is fun to watch if this is commented out
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

