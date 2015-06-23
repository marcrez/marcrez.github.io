---
title: Un ordinateur portable avec du matériel recyclé (en cours d'écriture...)
permalink: raspberry-android-ebook-reader-laptop
layout: post
date: 2015-06-23 20:31:00
tags: [raspberryPi, linux, reseau]
category: raspberryPi
---

![Canon XP3000]({{ site.baseurl }}/images/rPiLaptop/install.png)
Le but est ici de trouver une solution pour disposer d'un ordinateur portable
complet en utilisant un raspberryPi, une liseuse d'eBook et
d'un télephone Android.

## Un rPi et un téléphone Android


Commençons par un cas simple : un rPi est connceté en USB à un téléphone rooté.

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

L'adresse du rPi est 192.168.42.51. On va s'y connecter.

```
$ ssh pi@192.168.42.51
```

![Canon XP3000]({{ site.baseurl }}/images/rPiLaptop/Screen01.png)


## Un rPi, un téléphone Android et un clavier

Bientôt...



## Les articles en rapport

http://www.mobileread.com/forums/showthread.php?t=216501

Le clavier

- http://stackoverflow.com/questions/8483246/can-a-phone-pretend-to-be-a-bluetooth-keyboard
- http://forum.xda-developers.com/showthread.php?t=940511
- https://play.google.com/store/apps/details?id=com.skygears.airkeyboardandroid
- https://play.google.com/store/apps/details?id=com.steppschuh.remoteinput
- https://play.google.com/store/apps/details?id=pc.remote
- https://play.google.com/store/apps/details?id=com.hungrybolo.remotemouseandroid
- https://play.google.com/store/apps/details?id=com.necta.wifimousefree

L'écran

- http://www.ponnuki.net/2012/09/kindleberry-pi/
- http://maxogden.com/kindleberry-wireless.html
- http://www.theregister.co.uk/2012/09/11/kindleberry_pi/
- http://guilev-concept.net/pinkhttps://pihw.wordpress.com/guides/guide-to-using-the-nook-simple-touch-as-a-remote-eink-raspberry-pi-screen/
- https://projectdp.wordpress.com/2012/09/24/pi-k3w-kindle-3-display-for-raspberry-pi/


Autres liens

- http://mohammedlakkadshaw.com/blog/Android_as_display.html#.VYkGDORnor6
- http://www.linux-magazine.com/Online/Blogs/Productivity-Sauce/Use-an-Android-Device-as-Screen-and-Input-for-Raspberry-Pi

