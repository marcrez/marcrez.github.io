---
title: Un drone piloté par Arduino - Étape 1 (En cours d'écriture)
permalink: arduino-drone-01
layout: post
date: 2015-06-26 20:31:00
tags: [arduino, electronique]
category: arduino
---

![img]({{ site.baseurl }}/images/arduiDrone01/ensemble.png)
Aujourd'hui, premier article sur Arduino. Pourquoi ne pas commencer avec
un projet sympa plutôt que faire clignoter une diode ? 
On va voir comment construire un drone terrestre pour moins de 50 euros 
et en quelques étapes dont voici la première.

<div class="center">
<iframe width="560" height="315" src="https://www.youtube.com/embed/UrUc7om5AZE" frameborder="0" allowfullscreen></iframe>
</div>


## Le matériel nécessaire

Le montage est essentiellement basé sur Arduino Uno et une boîte à engrenages 
double qui va faire office de traction et de direction pour le drone.

![img]({{ site.baseurl }}/images/arduiDrone01/tamiya.png)

Le matériel peut être acheté en ligne, par exemple chez http://www.robotshop.com

Ci-dessous le panier avec presque tout le nécessaire, il faudra ajouter un circuit
L293D (moins de 3€ sur eBay) dont nous allons parler dans le paragraphe suivant.

![img]({{ site.baseurl }}/images/arduiDrone01/shop.png)


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

On le comprend, pour faire tourner le moteur 1 il va falloir envoyer un signal
haut sur la broche `Enable 1`. Ensuite

- signal haut sur `Input 1A` et signal bas sur `Input 1B` pour tourner dans un
  sens
- signal bas sur `Input 1A` et signal haut sur `Input 1B` pour tourner dans
  l'autre sens

Même chose pour le moteur 2, évidemment. On devrait pouvoir avancer, reculer,
tourner vers la gauche ou la droite.

La suite bientôt.....

## Un montage *quick and dirty*


![img]({{ site.baseurl }}/images/arduiDrone01/caisse.png)
![img]({{ site.baseurl }}/images/arduiDrone01/dessous.png)
![img]({{ site.baseurl }}/images/arduiDrone01/proto.png)






