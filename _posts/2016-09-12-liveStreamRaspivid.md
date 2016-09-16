---
title: Flux vidéo live avec RaspberryPi
permalink: raspberryPi-live-stream
layout: post
date: 2016-09-12 23:30:00
tags: [raspberrypi, video]
category: raspberrypi
---

Le problème du streaming vidéo avec le RaspberryPi, c'est la latence de parfois
plusieurs secondes qui rend impossible le pilotage d'un robot à distance.
Après avoir essayé plusieurs méthodes, voici celle qui me semble donner le
meilleur résultat sur un RaspberryPi 2 : jacksonliam/mjpg-streamer.
![img]({{ site.baseurl }}/images/livestreamRaspivid/mjpegStreamer.png)


Il s'agit d'un fork de mjpeg-streamer qui fonctionne avec le capteur vidéo de
RaspberryPi vi le plugin input_raspicam.

La récupération du dossier depuis https://github.com/jacksonliam/mjpg-streamer
ne pose aucun problème. On procède ensui de manière classique après installtion
du nécessaire :

    sudo apt-get install cmake libjpeg8-dev
    cd mjpg-streamer-experimental
    make
    sudo make install

On peut alors lancer le serveur web qui va permettre d'accéder au flux :

    ./mjpg_streamer -o "output_http.so -w ./www -p 8078" -i "input_raspicam.so -q 5 -fps 15 -vf -hf" &

Sur l'ordinateur client, on accède alors à la page http://IP_RaspberryPi:8078/
pour voir la vidéo.
