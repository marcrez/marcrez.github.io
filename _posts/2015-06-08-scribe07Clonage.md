---
title: Clonage de postes
layout: post
date: 2015-06-8 13:30:00
tags: [scribe]
category: scribe
---

Lorsqu'une machine fonctionne bien et que la plupart des logiciels y sont
installés, il faut en faire une image pour pouvoir la restaurer le jour où
elle se trouverait corrmpue. Il est aussi possible de cloner son disque dur
sur un parc de machines identiques. C'est tout cela que nous allons voir.

## Préparation du poste avant le clonage

**Cette étape est essentielle** : Avant de faire une sauvegarde, il faut

1.  Désinstaller le client Scribe.
1.  Sortir la machine du domaine
1.  Bien éteindre Windows (pas de veille prolongée)

## Sauvegarde de l'image d'un poste avec DRBL

Sur le poste à cloner, on démarre l'ordinateur sur le CD-ROM DRBL dont l'image
iso est à télécharger sur <http://drbl.org>.

Un fois démarré en mode DRBL Live, sélectionner le clavier français puis choisir
un codage clavier afin de sélectionner azerty. Le mode vidéo par défaut 0
fonctionne en général, valider en appuyant sur entrée.

Maintenant que DRBL a démarré, on peut lancer la sauvegarde de l'image du
disque.

Cliquer sur l'icône *Clonezilla live* 

![DRBL-01](figs/DRBL-01.png)

Le mode que nous allons choisir est ici le premier : device-image 

![DRBL-02](figs/DRBL-02.png)

Le montage du répertoire des images va être le répertoire personnel de
l'administrateur sur le serveur Scribe pour cela, on choisit le mode
*samba\_server* puis on donne successivement

-   l'adresse ip du serveur scribe.
-   le nom du domaine
-   le nom de l'administrateur du domaine : `admin`
-   le répertoire de l'utilisateur admin : `/admin`

Le mode de sécurité étant `auto`, le mot de passe de l'administrateur du domaine
est à renseigner.

Nous entrons maintenant dans la sauvegarde avec le mode `savedisk` où il sera
demandé de choisir un nom pour la sauvegarde avant de vérifier que le disque
`sda` (le premier disque système) est bien celui qui nous intéresse.

Il ne reste plus qu'à appuyer sur entrée pour valiser les choix par défaut des
questions suivantes pour lancer la sauvegarde 

![DRBL-03](figs/DRBL-03.png)

Cela va permettre de choisir l'image à restaurer puis après avoir accepté toutes
les options par défaut, le travail va commencer.

Lorsque la restauration est terminée, le choix 1 permet de redémarrer la machine
qui vinet d'être clonée. Le travail de clonage est terminé, il ne rste plus qu'à
laisser s'effectuer les opérations de post-configuration et éventuellement
réintégrer la machine dans le domaine.

## Restauration d'image

Sur la machine à reconstruire à partir de l'image préalablement sauvegardée, on
démarre en mode DRBL Live comme dans la section précédente puis *Clonezilla
live* 

Procéder exactment comme précédement : choisir device-image 
puis renseigner les informations sur le serveur scribe et l'administrateur.

Après avoir saisi le mot de passe, nous allons choisir de restaurer avec le mode
`restoredisk` 

![DRBL-04](figs/DRBL-04.png)

## Clonage multicast

Le principe du clonage multicast est simple :

1.  la machine à dupliquer est bootée sur un cd spécial qui fait d'elle un
    serveur d'image prêt à lire chaque bit du disque dur pour l'envoyer sur le
    réseau,
2.  chaque machine à écraser est bootée sur un cd spécial qui fait d'elle un
    client prêt à recevoir via le réseau les données à écrire sur le disque dur.

On prépare la salle en mettant tout le monde en attente est quand le
derneirposte est prêt, on appuie sur une touche pour lancer le clonage de tous
les postes ensemble.

![UDPCast_schema](figs/UDPCast_schema.png)

Nous utiliserons ici SystemRescueCD et la suite udpcast qui est constitué de
deux logiciels (udp-sender et udp-receiver) capables se communiquer des données
à travers un réseau

### Préparation de la machine à dupliquer

Lancer SystemRescueCD avec l'option 2) **docache**  afin
de charger complètement le système en mémoire vive pour éjécter le CD à la fin
du chargement. Nous en aurons besoin pour les autres machines de la salle...

![Sysresccd-2](figs/Sysresccd-2.png)

La commande suivante va demander à udpcast de diffuser le contenu intégral (bit
à bit) du disque dur (`--file /dev/sda`) mais compressé à la volée
(`--pipe "lzop"`) afin d'économiser le réseau.

```
    root@sysresccd /root % udp-sender --pipe "lzop" --file /dev/sda
```

La machine se met en attente de clients. Le résultat doit ressembler à ceci

        Udp-sender 20110710
        Using full duplex mode
        Using mcast adress 232.168.1.93
        UDP sender for (stdin) at 192.168.1.93 on eth0
        Broadcasting control to 192.168.1.255

### Préparation des machines à écraser

Lancer SystemRescueCD l'option 2) (docache). On pourra éjecter le CD-ROM une
fois le chargement terminé.

La commande suivante va demander à udpcast de recevoir le contenu diffusé et de
l'écrire sur le disque dur (`--file /dev/sda`) après décompression
(`--pipe "lzop -d"`). L'option `--nokbd` évite de démarrer la diffusion par
mégarde en appuyant sur une touche d'un client.

```
    root@sysresccd /root % udp-receiver --nokbd --pipe "lzop -d" --file /dev/sda
```

En appuyant sur entrée, on obtient quelquechose comme

        Udp-receiver 20110710
        UDP sender for (stdout) at 192.168.1.86 on eth0
        received message, cap=00000009
        Connected as #0 to 192.168.1.93
        Listening to multicast on 232.168.1.93

On constate que le client a bien contacté le serveur sur 192.168.1.93. Par
ailleurs, une nouvelle ligne vient de s'afficher sur l'écran du serveur

        New connection from 192.168.1.86 (#0) 00000009
        Ready. Press any key to start sending data.

Tout se passe bien, le serveur a été contacté par le client.

On répète ces opérations sur chaque machine de la salle. Lorsque toutes les
machines clientes sont prêtes, on appuie sur une touche du clavier du serveur et
le disque dur est cloné sur toutes les machines en même temps !

Attention : cette opération peut être longue et saturer le réseau, il faut donc
éviter de la lancer pendant les heures de cours.

