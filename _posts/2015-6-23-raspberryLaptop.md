---
title: Un ordinateur portable avec du matériel recyclé
permalink: raspberry-android-ebook-reader-laptop
layout: post
date: 2015-06-23 20:31:00
tags: [raspberryPi, linux, reseau]
category: raspberryPi
---

![Canon XP3000]({{ site.baseurl }}/images/rPiLaptop/install.png)
Le but est ici de trouver une solution pour disposer d'un ordinateur portable
complet en utilisant un RaspberryPi, 
un télephone Android et
une liseuse d'eBook Sony PRS-T1.

## Étape 1 : Un rPi et un téléphone Android

Commençons par un cas simple : un rPi est connceté en USB à un téléphone rooté.
Ici, le téléphone sert d'écran et de clavier pour l'unité centrale RaspberryPi.

![Canon XP3000]({{ site.baseurl }}/images/rPiLaptop/topo01.png)

D'abord, partager la connexion du télephone : pour cela dans les paramètres,
choisir **Plus...** puis **Partage de connexion** et cocher la case **Via USB**.

Maintenant, le rPi a une adresse IP fournie par le serveur DHCP du télephone.
Pour la connaître, on lance le *Terminal Emulator* puis les commandes suivantes 
pour obtenir les droits de root puis afficher la table 
[ARP](https://fr.wikipedia.org/wiki/Address_Resolution_Protocol)

```
$ su
# cat /proc/net/arp
IP address       HW type   Flags   HW address         Mask   Device
192.168.42.51    0x1       0x2     8e:e1:c2:a3:5d:eb  *      rndis0
192.168.42.254   0x1       0x2     00:23:a1:b2:cc:15  *      wlan0
```

L'adresse du rPi est 192.168.42.51. On va s'y connecter après avoir rendu les
droits de root avec la commande `exit`

```
$ ssh pi@192.168.42.51
```

![Canon XP3000]({{ site.baseurl }}/images/rPiLaptop/Screen01.png)

## Étape 2 : Un téléphone Android et une liseuse Sony PRS-T1 

Dans ce paragraphe, la liseuse devient un écran annexe pour une session de
travail en console sur un téléphone Android.

![Canon XP3000]({{ site.baseurl }}/images/rPiLaptop/topo01bis.png)

### Rooter la liseuse

La procédure est assez simple : télécharger `minimal-root.zip` sur le 
[dossier de Porkupan](http://projects.mobileread.com/reader/users/porkupan/PRST1/flash_packages/)

Déziper et déposer les fichiers à la racine de SDCARD.

La racine de SDCARD doit contenir le fichier `PRS-T1 Updater.package` et 
les dossiers `tmp` et `updates`.

Éteindre la liseuse puis redémarrer en maintenant les boutons **Home** et **Menu**
jusqu'à l'apparition de l'écran *Opening book*.

C'est fini. Pour plus d'informations ou en cas de problème 

- [PRST1 Rooting and Tweaks](http://wiki.mobileread.com/wiki/PRST1_Rooting_and_Tweaks)
- [Sony PRS-T1 step-by-step rooting and tweaking guide](http://www.mobileread.com/forums/showthread.php?t=184646)


### Installer le client ssh ConnectBot sur la liseuse

Par défaut, GooglePlay Store n'est pas présent. On va donc installer le magasin d'applications libres F-Droid sur
la liseuse afin de pouvoir installer facilement des applications.

D'abord, activer le wifi, puis avec le navigateur de la liseuse, aller sur
https://f-droid.org/ et télécharger l'installeur.

Une fois F-Droid installé, on peut lancer l'installation de **ConnectBot**.

### Installer SSH Server sur le téléphone

Par défaut, le téléphone n'accepte pas les connexionx entrantes. On va donc 
installer un serveur ssh pour que la liseuse puisse se conncter au téléphone.

![Canon XP3000]({{ site.baseurl }}/images/rPiLaptop/sshserver.png)

### Connecter la liseuse au téléphone

Pour cela, il faut configurer le téléphone en point d'accès wifi.

D'abord, partager la connexion du télephone : pour cela dans les paramètres,
choisir **Plus...** puis **Partage de connexion** et
**Point d'accès Wi-Fi mobile**.

Les étapes sont alors faciles à suivre : on va définir un nom pour le réseau et
un mot de passe d'accès.  Sur la liseuse, on peut alors facilement se connecter
au réseau servi par le téléphone.

Le bouton **Info** de l'application **SSH Server** du téléphone permet de 
connaitre l'adresse ip wifi du téléphone.

On peut lancer ConnectBot sur la liseuse pour se conncter au téléphone.


## Étape 3 : Un rPi, un téléphone Android et une liseuse Sony PRS-T1

Résumé des étapes précédentes :

1. Le téléphone est connecté, par le cable USB, sur le serveur ssh du rPi.
2. La liseuse est connctée, par le wifi, sur le serveur ssh du téléphone.

L'objectif : le télephone sert de clavier et la liseuse sert d'écran pour
l'unité centrale RaspberryPi.

![Canon XP3000]({{ site.baseurl }}/images/rPiLaptop/topo02.png)

Il ne reste plus que deux opérations à effectuer :

1. Depuis le téléphone, dans le terminal connecté au rPi, créer un session de
   screen nommée `foo`
2. Depuis la liseuse, dans ConnectBot connecté au téléphone, se connecter au rPi
   et rejoindre la session screen nommée `foo`.

   
## Un article sur le même sujet avec une liseuse Kindle

http://www.ponnuki.net/2012/09/kindleberry-pi/

