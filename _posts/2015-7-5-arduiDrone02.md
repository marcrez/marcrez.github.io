---
title: Un drone piloté par Arduino - Étape 2 (En cours d'écriture)
permalink: arduino-drone-02
layout: post
date: 2015-07-05 20:31:00
tags: [arduino, electronique]
category: arduino
---
![img]({{ site.baseurl }}/images/arduiDrone02/realisation-small.png)

Seconde étape dans le projet de drone terrestre :
le rendre capable de se déplacer en évitant les obstacles.
On va utiliser pour cela un capteur de distance à ultrasons
comme on la vu dans l'[article sur le HC-SR04](http://npoulain.fr/mesureDeDistanceHC-SR04/)

<div class="center">
<iframe width="560" height="315" src="https://www.youtube.com/embed/rV5qc04O71w" frameborder="0" allowfullscreen></iframe>
</div>


## Un chassis pour embarquer le projet

Dans le première partie, on s'était contenté d'un chassis en carton.
Cette fois, c'est en medium de 3mm qu'on va construire.

> Remarque : le medium 3mm, c'est le matériau utilisé pour le fond des
> armoires ou placards du commerce, on le trouve très facilement et il est
> facile à découper et à coller.

Voici le plan 

![img]({{ site.baseurl }}/images/arduiDrone02/planConstr.jpg)

puis la maquette réalisée avec simplement de la colle à bois blanche.

![img]({{ site.baseurl }}/images/arduiDrone02/maquette.jpg)

La partie basse peut recevoir un bloc de piles. Sur le pont supérieur, on pourra 
fixer l'Arduino, et la plaque d'essai ainsi
que d'autres éléments qui ne manqueront
pas de venir...

![img]({{ site.baseurl }}/images/arduiDrone02/realisation.jpg)

```
/*
 This sketch originates from Virtualmix: http://goo.gl/kJ8Gl
 Has been modified by Winkle ink here: http://winkleink.blogspot.com.au/2012/05/arduino-hc-sr04-ultrasonic-distance.html
 And modified further by ScottC here: http://arduinobasics.blogspot.com.au/2012/11/arduinobasics-hc-sr04-ultrasonic-sensor.html
 on 10 Nov 2012.
 */

// Definition des broches pour les moteurs
int enable1_pin = 4; //pwm
int input1A_pin = 3;
int input1B_pin = 2;
 
int enable2_pin = 5; //pwm
int input2A_pin = 6;
int input2B_pin = 7;
 
int echo_pin = 12
int trig_pin = 11

int minimum = 10; // Minimum range needed

void setup()
{
  // Initialisation des broches pour les moteurs
  pinMode(input1A_pin, OUTPUT);
  pinMode(input1B_pin, OUTPUT);
  pinMode(enable1_pin, OUTPUT);
 
  pinMode(input2A_pin, OUTPUT);
  pinMode(input2B_pin, OUTPUT);
  pinMode(enable2_pin, OUTPUT);
}
 
void loop()
{

  if (distance() >= minimum){
    // 
    SetMotor1(170, true);
    SetMotor2(220, true);
  }
  else {
    SetMotor2(175, true);
    SetMotor1(175, false);
    delay(300);
  }
 //Delay 50ms before next reading.
 delay(50);
}

/*
 * Determine la distance par la mesur de l'echo
 */
float dist()
{
  float duration, distance; // variables utiles

  // Envoie un signal ultrason de 10 microsecondes
  digitalWrite(trigPin, LOW); 
  delayMicroseconds(2); 
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10); 
  digitalWrite(trigPin, LOW);
  // chronometre le temps mis pour le retour
  duration = pulseIn(echoPin, HIGH);
  // calcule la distance (en cm) en fonction de la vitesse du son.
  distance = duration/58.2;
  return distance
}

/*
 * Fonction qui set le moteur 1
 */
void SetMotor1(int speed, boolean reverse)
{
  analogWrite(enable1_pin, speed);
  digitalWrite(input1A_pin, ! reverse);
  digitalWrite(input1B_pin, reverse);
}
 
/*
 * Fonction qui set le moteur2
 */
void SetMotor2(int speed, boolean reverse)
{
  analogWrite(enable2_pin, speed);
  digitalWrite(input2A_pin, ! reverse);
  digitalWrite(input2B_pin, reverse);
}
```

http://picaxe.hobbizine.com/srf05.html




