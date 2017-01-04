---
title: Programmer Arduino sur une tablette Android
permalink: arduino-android
layout: post
date: 2017-01-04 20:31:00
tags: [arduino, electronique]
category: arduino
---

![img]({{ site.baseurl }}/images/arduinoAndroid/arduinoAndroidLogo.jpg)

Programmer une carte arduino depuis une tablette est possible,
on peut même le faire avec de des interfaces de programmation
graphique par blocs (comme avec Scratch), c'est ce que nous allons voir
dans cet article.


## Le matériel nécessaire

Il faut évidemment une carte arduino officielle (environ 20€)
ou compatible (moins de 5€) avec leur câble de connexion.

![img]({{ site.baseurl }}/images/arduinoAndroid/unoR3.jpg)
![img]({{ site.baseurl }}/images/arduinoAndroid/robotdyn.jpg)

Un câble USB OTG pour brancher le cable arduino sur le port USB du téléphone.

![img]({{ site.baseurl }}/images/arduinoAndroid/USB-OTG.jpg)


## Alimenter des moteurs à courant continu

Hors de question d'alimenter les moteurs directement avec les pins de l'arduino !

1. D'abord parcequ'un moteur consomme beaucoup et que l'intensité délivrée par
   les broches de l'arduino est faible
2. Ensuite parcequ'un moteur produit des parasites et parfois des retours de
   courant de forte tension qui pourraient endommager la carte Arduino

On va utiliser le circuit L293D  dont le rôle est de commander la mise en route
des moteurs sur commande de l'arduino.

Voici un schéma

![img]({{ site.baseurl }}/images/arduiDrone01/l293.png)

Arduino peut sans problème alimenter le circuit sur la broche 16, en revanche,
c'est une alimentation dédiée qui va délivrer du courant (max 36V, 600mA)
sur la broche 8.
Un pack de 4 piles AA convient bien à ces petits moteurs.

On le comprend, pour faire tourner le moteur 1 il va falloir envoyer un signal
haut sur la broche `Enable 1`. Ensuite

- signal haut sur `Input 1A` et signal bas sur `Input 1B` pour tourner dans un
  sens
- signal bas sur `Input 1A` et signal haut sur `Input 1B` pour tourner dans
  l'autre sens

Même chose pour le moteur 2, évidemment. On devrait pouvoir avancer, reculer,
tourner vers la gauche ou la droite.

La vitesse du moteur 1 dépend du rapport cyclique (*duty cycle*) du signal sur
`Enable 1`. Comme on va relier cette broche à `enable1_Pin` de l'arduino, il
suffira de choisir une valeur entre 0 et 254 pour la variable `value`

```
analogWrite(enable1_Pin, value);
```

on mettra donc un motreur en route avec une vitesse `speed` à l'aide d'une
fonction de la forme

```
//Fonction pour le moteur1
void SetMotor1(int speed, boolean reverse)
{
  analogWrite(enable1_pin, speed);
  digitalWrite(input1A_pin, ! reverse);
  digitalWrite(motor1B_pin, reverse);
}
```


> Remarque : La modulation de largeur d'impulsions (PWM pour Pulse Width
> Modulation), est une technique couramment utilisée pour synthétiser
> des signaux continus à l'aide de circuits à fonctionnement tout ou rien, ou
> plus généralement à états discrets.


Voici donc un programme qui va faire faire des aller-retours au drone :
un cycle constitué d'une marche avant puis d'un demi-tour.


```
// Definition des broches
int enable1_pin = 4; //pwm
int input1A_pin = 3;
int input1B_pin = 2;

int enable2_pin = 5; //pwm
int input2A_pin = 6;
int input2B_pin = 7;

void setup()
{
  // Initialisation des broches des moteurs
  pinMode(input1A_pin, OUTPUT);
  pinMode(input1B_pin, OUTPUT);
  pinMode(enable1_pin, OUTPUT);

  pinMode(input2A_pin, OUTPUT);
  pinMode(input2B_pin, OUTPUT);
  pinMode(enable2_pin, OUTPUT);

}

void loop()
{
  // marche avant pendant 5 secondes
  SetMotor1(255, true);
  SetMotor2(255, true);
  delay(5000);

  // rotation pendant 2.4s : demi-tour
  SetMotor1(175, true);
  SetMotor2(175, false);
  delay(2400);
}

//Fonction qui set le moteur1
void SetMotor1(int speed, boolean reverse)
{
  analogWrite(enable1_pin, speed);
  digitalWrite(input1A_pin, ! reverse);
  digitalWrite(input1B_pin, reverse);
}

//Fonction qui set le moteur2
void SetMotor2(int speed, boolean reverse)
{
  analogWrite(enable2_pin, speed);
  digitalWrite(input2A_pin, ! reverse);
  digitalWrite(input2B_pin, reverse);
}
```



## Un montage *quick and dirty*


![img]({{ site.baseurl }}/images/arduiDrone01/caisse.png)
![img]({{ site.baseurl }}/images/arduiDrone01/dessous.png)
![img]({{ site.baseurl }}/images/arduiDrone01/proto.png)






