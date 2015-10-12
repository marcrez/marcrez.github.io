---
title: Piloter 12 servomoteurs avec Arduino
permalink: servoDriver
layout: post
date: 2015-10-12 20:31:00
tags: [arduino, electronique]
category: arduino
---

![img]({{ site.baseurl }}/images/arduiDrone01/ensemble.png)

Pour fabriquer un robot quadrupède, il faut un paquet de moteurs.
Trois par patte, c'est bien mais cela fait 12 ...

Pour ne pas utiliser toutes les sorties, de l'arduino Uno, on peut utiliser
un servoDriver du type PCA9685.

Adafruit propose une library pour piloter ce module. 

https://github.com/adafruit/Adafruit-PWM-Servo-Driver-Library/archive/master.zip

Une fois installée, on peut charger l'exemple `servo` pour voir successivement
tourner les moteurs de 180 degrés.

Le problème que celq me pose est que les moteurs tournent à la vitesse maximale.
Cela est dû au fait que les servomoteurs premier prix, n'ont pas de contrôle de
vitesse. 

Voici comment contourner cette limitation : faire un PWM maison.

Prenons un exemple. On souhaite faire tourner le moteur de 30 degrés mais 
lentement. Pour cela, on va le faire tourner de 1 degré trente fois en
effectuant une micro-pause à chaque étape.

Comme ceci :

``` c
/*************************************************** 
  This is an example for our Adafruit 16-channel PWM & Servo driver
  Servo test - this will drive 16 servos, one after the other

  Pick one up today in the adafruit shop!
  ------> http://www.adafruit.com/products/815

  These displays use I2C to communicate, 2 pins are required to  
  interface. For Arduino UNOs, thats SCL -> Analog 5, SDA -> Analog 4

  Adafruit invests time and resources providing this open source code, 
  please support Adafruit and open-source hardware by purchasing 
  products from Adafruit!

  Written by Limor Fried/Ladyada for Adafruit Industries.  
  BSD license, all text above must be included in any redistribution
 ****************************************************/

#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

// called this way, it uses the default address 0x40
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

// Depending on your servo make, the pulse width min and max may vary, you 
// want these to be as small/large as possible without hitting the hard stop
// for max range. You'll have to tweak them as necessary to match the servos you
// have!
#define SERVOMIN  155 // this is the 'minimum' pulse length count (out of 4096)
#define ANGLEMIN  0
#define SERVOMAX  600 // this is the 'maximum' pulse length count (out of 4096)
#define ANGLEMAX  190

void setup() {
  Serial.begin(9600);
  Serial.println("16 channel Servo test!");
  pwm.begin();
  pwm.setPWMFreq(60);  // Analog servos run at ~60 Hz updates
}

void loop() {
    double pulselen;

    for (uint16_t a = 0; a < 30; a = a + 1) {
      pulselen = map(a, ANGLEMIN, ANGLEMAX, SERVOMIN, SERVOMAX);
      pwm.setPWM(servonum, 0, pulselen);
      delay(15); // wait 15 microseconds to slow servo
    }
    delay(2000); // wait 2 seconds before restart
  }

}
```

et voilà !
