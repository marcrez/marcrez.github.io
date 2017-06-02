---
title: Installation de Scribe
layout: post
date: 2015-06-8 19:30:00
tags: [scribe, reseau]
category: scribe
---

Dans cette section on va voir comment créer la machine virtuelle qui va
accueillir le sytème d'exploitation Linux sur lequel fonctionne Scribe.

## Préparation de la machine virtuelle

Après avoir demandé la création d'une nouvelle machine dans VirtualBox, puis
donné un nom (disons scribe) et choisi le type de système d'exploitaion (ici
Linux-Ubuntu), passez toutes les étapes en acceptant les choix par défaut (sauf
pour la mémoire vive que nous passerons de 512Mo à 256Mo).

Une fois ces opérations terminées,

-   cocher la case «Activer PAE/NX» dans l'onglet «Processeur» de la section
    «Système» de votre machine virtuelle.
-   choisir le mode d'accès par pont pour la carte réseau 1. Elle prendra ainsi
    une adresse sur le réseau sur lequel se trouve la machine hôte.
-   L'image iso du dvd eole, téléchargée sur le site Eole
    <http://eoleng.ac-dijon.fr/pub/iso/> doit être montée comme un CD-ROM (ou
    DVD) virtuel, pour cela cliquez sur l'icône cd-rom dans l'onglet «Stockage»,
    comme sur l'image ci-dessous puis naviguez dans l'arborescence pour indiquer
    le fichier .iso. comme on le voit sur la figure suivante

![Insérer un CDROM dans le lecteur virtuel.]({{ site.baseurl }}/images/gestionReseau/scribe_html_m69a9bc5b.png)

-   On peut alors mettre en marche la machine virtuelle.

## Installation

![Menu de démarrage Scribe]({{ site.baseurl }}/images/gestionReseau/scribe_html_m1451a7db.png)

Après avoir vérifié au niveau du BIOS que la machine démarre prioritairement sur
le CD, le menu de démarrage apparaît.

Une bonne idée consiste à vérifier si le disque (le CD) a des défauts afin
d'éviter de perdre du temps avec une installation qui échouerait sans doute.

Une fois ceci fait, lançons l'installation de Scribe. La procédure est
automatique et vous n'avez qu'à observer les étapes

![En cours d'installation]({{ site.baseurl }}/images/gestionReseau/scribe_html_4b5e166b.png)

Après redémarrage, le gestionnaire de démarrage GRUB vous propose plusiers
entrées. Nous choisissons celle par défaut

![Menu Grub]({{ site.baseurl }}/images/gestionReseau/scribe_html_m6522c87a.png)

Vous pouvez maintenant vous identifier avec le login `root` et le mot de passe
`$eole&123457$`. (dans le cas scribe2.3)

Avant de nous lancer dans la configuration de notre contôleur de domaine scribe,
notons ici quelques informations réseau dont nous aurons besoin pour configurer
notre serveur :

| Titre                                   | Notes       | Exemple
|:--------------------------------------- |:----------- |:-------------------
| Adresse IP fixe de la carte réseau      | `… … … …`   | (ex. 192.168.1.209)
| Le masque de sous-réseau                | `… … … …`   | (ex 255.255.255.0)
| L'adresse réseau                        | `… … … …`   | (ex 192.168.1.0)
| L'adresse de broadcast                  | `… … … …`   | (ex. 192.168.1.255)
| L'adresse de la passerelle              | `… … … …`   | (ex. 192.168.1.254)
| L'adresse IP du ou des serveur(s) DNS   | `… … … …`   | (ex. 192.168.1.254)
| Le nom de la machine                    | `…………`      | (ex. scribe09)
| Le nom du serveur de fichier            | `…………`      | (ex. scribe09)
| Le nom du domaine samba                 | `…………`      | (ex. oiseaux09)

On peut maintenant effectuer la mise à jour 
après avoir préalablement réglé l'accès au proxy Amon :

```
    root@scribe:~# export http_proxy='http://192.168.1.254:3128'
    root@scribe:~# Maj-Auto -i
```

## Configuration de scribe 2.3

Saisissez la commande `gen_config` qui va lancer le générateur de configuration

```
    root@scribe:~# gen_config
```

La série d'écrans est à renseigner en étant très attentif.

![Scribe 2.3 - Général]({{ site.baseurl }}/images/gestionReseau/23_01.png)


Onglet «Général»

- l'**Identifiant de l'établissement** doit être unique ;
- Sur un réseau local le **nom de domaine** est privé et on peut tout à
  fait utiliser des domaines de premier niveau, et leur donner la
  sémantique
  que l'on veut.
- Une valeur par défaut est attribuée Pour le **serveur de temps NTP**. 
  Il est possible de changer cette valeur pour utiliser un serveur de
  temps personnalisé.
- La variable **Adresse IP du serveur DNS** donne la possibilité de saisir 
  une ou plusieurs adresses IP du ou des serveur(s) de nom DNS. 
- Le champ **Nom du contrôleur de domaine** (le nom d'ordinateur NetBIOS) 
  est le  nom qui sera utilisé pour accéder aux fichiers avec la syntaxe
  `\\machine`. *En mode conteneur (sur les modules AmonEcole et ses
  variantes), il doit   impérativement être différent du Nom de la
  machine.*
- Le champ **Nom du domaine Samba** (le nom d'ordinateur NetBIOS), est 
  aussi   appelé groupe de travail (workgroup), il est à utiliser lors de
  l'intégration  d'une station au domaine.


![Scribe 2.3 - Messagerie]({{ site.baseurl }}/images/gestionReseau/23_03.png) 

Onglet «Messagerie»

- Nom de domaine de la messagerie de l'établissement (ex : monetab.ac-aca.fr),
  saisir un nom de domaine valide, par défaut un domaine privé est
  automatiquement créé avec le préfixe i-;
- Adresse électronique recevant les courriers électroniques à destination du
  compte root, permet de configurer une adresse pour recevoir les éventuels
  messages envoyés par le système ;
- Passerelle SMTP, permet de saisir l'adresse IP ou le nom DNS de la passerelle
  SMTP à utiliser.

![Scribe 2.3 - Interface-0]({{ site.baseurl }}/images/gestionReseau/23_04.png)

Onglet «Interface-0»

- L'interface réseau nécessite un adressage statique, il faut renseigner
  l'adresse IP (hors plage DHCP) et le masque.
- EOLE supporte les alias sur les cartes réseaux. Définir des alias IP consiste
  à affecter plus d'une adresse IP à une interface.
- Il est possible de configurer des VLAN (réseau local virtuel) sur une
  interface déterminée du module.


![Scribe 2.3 - Mots de passe]({{ site.baseurl }}/images/gestionReseau/23_05.png)

Onglet «Mots de passe»

- Pour faciliter le travail durant le stage on va régler les paramètres au
  minimum.

![Scribe 2.3 - Bacula]({{ site.baseurl }}/images/gestionReseau/23_07.png)

Onglet «Bacula»

- L'usage sur l'académie de Paris est un réglage à 10 pour les rétentions.

![Scribe 2.3 - ESU]({{ site.baseurl }}/images/gestionReseau/23_08.png)

Onglet «ESU»

- Le réglage du proxy est essentiel.

![Scribe 2.3 Système*]({{ site.baseurl }}/images/gestionReseau/23_13.png)

Onglet «Système»

- Passer en mode expert
- Pour faciliter le travail durant le stage on désactive la vérification
  de complexité des mots de passe.

Les autres onglets peuvent être validés avec les options par défaut.

Pour plus d'informations, consulter la documentation officielle :
http://eoleng.ac-dijon.fr/documentations/2.3/completes/HTML/ModuleScribe/co/ModuleScribe.html


## Instanciation

Après avoir rempli les champs, on peut enregistrer ces paramètres qui vont
constituer un fichier nommé `zephir.eol` dont le rôle est de donner les
instructions au programme d'instanciation instance.

```
    # instance zephir.eol
```

Au cours de l'exécution du programme, il vous sera demandé de changer les mots
de passe

- du super-administrateur Linux nommé `root` : il a tous les droits sur le
  serveur;
- de l'administrateur linux restreint nommé `eole`
- de l'admistrateur du domaine nommé `admin`.

Pour le stage nous utiliserons les mots de passe suivants

- Le mot de passe root : `root`
- Le mot de passe eole : `eole`
- Le mot de passe admin : `admin`

Lors de l'installation, le programme vous proposera sans doute de télécharger
des mises à jour. Il est essentiel d'accepter car elles corrigent des problèmes
de sécurité comme elles apportent des améliorations des programmes de la
distribution Ubuntu mais aussi de la suite Scribe développée par l'académie de
Dijon.

À la fin du processus, après construction des bases de données et exécution de
tous les scripts de pré/postinstance, la machine doit redémarrer.

## Pourquoi n'utiliser instance qu'une seule fois ?

Un fois les modifications apportées au fichier `config.eol`, on se gardera bien
de relancer le programme d'instanciation `instance`. En effet il poserait des
questions inutiles, pourrait effacer des comptes, perturber gravement les
connexions au domaine des machines déjà intégrées.

En cas de changement sur le réseau ou d'erreur lors de la configuration, il est
possible de relancer la commande `gen_config` afin de modifier le fichier
`/etc/eole/config.eol`. Pour ensuite lancer une reconfiguration avec le
programme reconfigure. dont la fonction est de lire le fichier
`/etc/eole/config.eol` pour en appliquer les paramètres aux différents services
en fonctionnement.

```
    # gen_config /etc/eole/config.eol
    # reconfigure
```

