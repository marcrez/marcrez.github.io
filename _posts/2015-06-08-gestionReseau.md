---
title: Installation de Scribe
layout: post
date: 2015-06-8 13:30:00
tags: [reseau]
category: scribe
---



# Gestion de parc avec OCS Inventory NG

La documentation officielle en français
(<http://wiki.ocsinventory-ng.org/index.php/Documentation:Main/fr>) décrit en
ces mots l’application :

*OCS Inventory NG soit Open Computer and Software Inventory est une application
permettant de réaliser un inventaire automatisé sur la configuration matérielle
des machines du réseau et sur les logiciels qui y sont installés. OCS permet de
visualiser cet inventaire grâce à une interface web. Il comporte également la
possibilité de télé-déployer des applicationssur un ensemble de machines selon
des critères de recherche. Une fonction des agents nommée IpDiscover, couplée à
des scans snmp permet de connaître l'intégralité des interfaces du réseau.*

## Mise en place du serveur OCS (version Linux)

On suppose que le logiciel VirtualBox (<https://www.virtualbox.org/>) est
installé.

Nous allons ici détailler la mise en place de OCS dans un parc informatique sous
la forme d’une machine virtuelle (fig. \ref{m152e569c}). En configurant
correctement l'interface réseau, nous disposerons du point de vue du réseau
d’une machine à part entière qui pourra rendre tous les services souhaités.

![Un serveur OCS virtuel dans un réseau
pédagogique\label{m152e569c}](figs/scribe_html_m152e569c.png)

Avantage de la virtualisation : La simplicité, en effet sur le site web de OCS,
on trouve des images de machines virtuelles Linux pretes à l'emploi avec
OCS-serveur déjà installé et entièrement configuré.

1.  La première étape consiste à récupérer une image de machine virtuelle de
    serveur OCS :
    <http://www.ocsinventory-ng.org/en/download/download-server.html> Une fois
    téléchargée, on décompacte l’archive avec un logiciel capable de traiter les
    fichiers au format tar.gz, par exemple 7zip.

    Nous avons maintenant à disposition un dossier contenant une image de disque
    nommée Ocsinventory-ng.vmdk. Ce fichier va nous servir de disque virtuel
    pour une nouvelle machine virtuelle linux que nous allons créer dans
    VirtualBox.

    ![](figs/scribe_html_4ef60c5.jpg)

    ![](figs/scribe_html_460d6a35.jpg)

    N’oubliez pas de cocher la case «Activer PAE/NX» dans l’onglet «Processeur»
    de la section «Système» de votre machine virtuelle.

    N’oubliez pas non plus de choisir le mode d’accès par pont pour la carte
    réseau 1. Si vous voulez que votre machine virtuelle soit vue par le réseau
    d’établissement et que les remontées d’inventaire puissent se faire, c’est
    évidemment indispensable.

2.  Démarrons la machine, le compte administrateur est comme d’habitude «root»
    et le mot de passe est ici «ocs». Nous pourrions le changer après connexion
    avec la commande passwd.

3.  Premère étape : effectuer le réglage du clavier pour passez en azerty :

    ```
        root@ocsinventory-ng:~# loadkeys fr
    ```

4.  Deuxième étape régler les paramètres réseau de la machine avec l’éditeur de
    texte nano.

    > *INFO : Sous nano*

    > -   *pour enregistrer :* `<CTRL>+O+<Entrée>`
    > -   *pour quitter :* `<CTRL>+X`

    Premier fichier : `/etc/network/interfaces` ,

    ```
        root@ocsinventory-ng:~# nano /etc/network/interfaces
    ```

    Il contient les paramètres des interfaces réseau Par défaut il est réglé sur
    une ip fixe `10.10.10.10`, nous allons modifier cela

            auto eth0
            iface eth0 inet static
            address 192.168.1.205
            netmask 255.255.255.0
            broadcast 192.168.1.255
            gateway 192.168.1.1

    Si vous vouliez configurer le serveur pour qu’il reçoive une adresse ip par
    le serveur DHCP :

            auto eth0
            iface eth0 inet dhcp

    Second fichier : `/etc/resolv.conf`

    ```
        root@ocsinventory-ng:~# nano /etc/resolv.conf
    ```

    Il doit contenir les adresses IP des serveurs DNS.

            nameserver 212.27.40.241
            nameserver 212.27.40.240

    Troisième fichier : `/etc/hosts` ,

    ```
        root@ocsinventory-ng:~# nano /etc/hosts
    ```

    il doit contenir une liste d'association entre nom de machine et adresse IP
    qui passera avant la résolution de nom classique par DNS.

            127.0.0.1 localhost
            129.168.1.205 ocsinvetory-ng

5.  Le plus simple est maintenant de redémarrer la machine pour qu’elle prenne
    en compte les nouveaux paramètres.

    ```
        root@ocsinventory-ng:~# reboot
    ```

    Pour tester le fonctionnement on peut ouvrir, sur un client windows, un
    navigateur à l’adresse <http://ocsinventory-ng/ocsreports> ou
    <http://ip_du_serveur_ocs/ocsreports>. Pour se connecter, user:admin et
    password:admin. (fig. \ref{af37b4})

    ![Accueil OCS-NG\label{af37b4}](figs/scribe_html_af37b4.jpg)

## Installation de l’agent OCS sur les clients

Sur le client windows, téléchargez l’agent windows sur la page de téléchargement
du site OCS :

<http://www.ocsinventory-ng.org/en/download/download-agent.html>

Après avoir dézippé l’archive
<http://launchpad.net/ocsinventory-windows-agent/2.0/2.0.3/+download/OCSNG-Windows-Agent-2.0.3.zip>
vous obtenez un dossier dans lequel vous exécutez le programme
`OCS-NG-Windows-Agent-Setup.exe`

Lors du choix des composants, veillez à bien laisser cochée la case «Network
inventory» car nous voulons que l’inventaire soit envoyé au serveur (fig.
\ref{m3ee6b3fb}).

![Installation client OCS\label{m3ee6b3fb}](figs/scribe_html_m3ee6b3fb.jpg)

L’étape suivante permet de régler la connexion au serveur dont le nom d’hôte a
été fixé plus haut à «ocsinventory-ng». Il n’y a donc rien à modifier à la
valeur par défaut de l’URL du serveur. La validation du certificat se fera en
pointant vers le fichier partagé sur le serveur OCS (fig. \ref{m79f4548d}) :

`\\ocsinventory-ng\ocs$\cacert.pem`.

![Validation du certificat \label{m79f4548d}](figs/scribe_html_m79f4548d.jpg)

Dernière étape : demander qu’une remontée de l’inventaire soit effectuée lors de
l’installation (fig. \ref{2cef7e65}). Sans cela, il faudra attendre jusqu’à 48h
pour voir apparaître la machine dans l’interface de gestion centralisée.

![Demande de remontée de immédiate de
l’inventaire\label{2cef7e65}](figs/scribe_html_2cef7e65.jpg)

Rendez-vous à l’adresse <http://ocsinventory-ng/ocsreports> ou
[http://ip\_du\\serveur\_ocs/ocsreports](http://ip_du\serveur_ocs/ocsreports)
vous devriez voir l’inventaire du poste en cliquant sur l’icône ordinateur.

## Déploiement de paquets sur le parc

C’est une fonctionnalité essentielle mais qui nécessite un peu de pratique.
Essayons-nous sur un cas pratique : l’installation sur le parc d’un petit
logiciel de lecture de pdf : SumatraPDF.

On récupère l’installeur sur la page de téléchargement

<http://blog.kowalczyk.info/software/sumatrapdf/download-free-pdf-viewer.html>

le fichier se nomme `SumatraPDF-1.9-Install.exe`. On pourrait lancer
l’installation en éxécutant cette commande dans une fenêtre DOS. Comme par
ailleurs il est possible d’installer en mode silencieux (sans questions) avec
l’option `/S`, ocsinventory n’aura aucun mal à déployer ce logiciel sur le parc
en exécutant la commande `SumatraPDF-1.9-Install.exe /S` après l’avoir déposé
sur chaque poste.

1.  Il faut commencer par compresser le fichier SumatraPDF-1.9-Install.exe avant
    de pouvoir le déployer. Il suffit pour cela d’un clic-droit -\> Envoyer vers
    -\> Dossier compressé.

![SumatraPDF](figs/scribe_html_m2a4069ed.jpg)

2.  Maintenant, dans l’interface web ocsinventory, nous allons construire le
    paquet (figs \ref{cd6a1d0} et \ref{6297240c}).

![Construction du paquet. Étape 1\label{cd6a1d0}](figs/scribe_html_cd6a1d0.jpg)

![Construction du paquet. Étape
2\label{6297240c}](figs/scribe_html_6297240c.jpg)

Le fichier à déployer est l’archive .zip que nous avons créée. L’action est
«Execute» puisque on souhaite exécuter le fichier SumatraPDF-1.9-Install.exe et
pour éviter que l’installation intéragisse avec l’utilisateur sur le poste
client, on ajoute l’option /S pour une installation silencieuse avec les options
par défaut.

3.  Il nous faut maintenant activer le paquet. Pour cela, afficher la page
    d’activation et cliquer sur l’icône comme sur la figure \ref{m5d43378b}
    ci-dessous :

![Activation de paquet \label{m5d43378b}](figs/scribe_html_m5d43378b.jpg)

Choisir alors l’activation manuelle puis valider (fig. \ref{669af7cb})

![Activation manuelle\label{669af7cb}](figs/scribe_html_669af7cb.jpg)

4.  À présent le paquet est prêt, il reste à choisir les postes sur lesquels on
    souhaite déployer. Pour cela, cliquez sur l’icône de recherche puis «Search
    with various criteria». Dans l’exemple ci-dessous, le paramètre choisi est
    «Computers : Operating systems». (fig. \ref{m49c3e1e4})

![Recherche\label{m49c3e1e4}](figs/scribe_html_m49c3e1e4.jpg)

5.  On peut alors choisir en les cochant les postes sur lesquels on va déployer
    le paquet (fig. \ref{bcefe4})

![Sélectionner les postes pour le
déploiement\label{bcefe4}](figs/scribe_html_bcefe4.jpg)

6.  Après avoir cliqué sur l’icône de déploiement, préciser que l’affectation se
    fera pour la sélection puis cliquer sur le bouton «SELECT» correspondant au
    paquet à déployer.

![m711b1407](figs/scribe_html_m711b1407.jpg)

C’est terminé. À partir de maintenant, lorsque l’agent du poste client va
contacter le serveur, celui-ci va enregistrer une notification et sera alors
prêt à déployer le paquet au bout d’un temps aléatoire pouvant aller jusqu’à
24h. On peut suivre l’avancement des déploiements en cliquant sur
Deployment-\>Activate

![26ef5677](figs/scribe_html_26ef5677.jpg)

![m147fbe26](figs/scribe_html_m147fbe26.jpg)

Pour aller (beaucoup) plus loin, la documentation est très complète :

<http://wiki.ocsinventory-ng.org/index.php/Documentation:Teledeploy/fr>

## Installation et configuration de GLPI

Solution opensource de gestion de parc informatique et de servicedesk, GLPI est
une application Full Web pour gérer l’ensemble de vos problématiques de gestion
de parc informatique : de la gestion de l’inventaire des composantes matérielles
ou logicielles d’un parc informatique à la gestion de l’assistance aux
utilisateurs. <http://www.glpi-project.org/>

Sur notre serveur virtuel OCS Inventory NG, nous allons installer GLPI. Avec un
serveur Debian ou Ubunutu, la commande d'installation est la suivante :

```
    root@ocsinventory-ng:~# apt-get install glpi
```

Il vous sera demandé de reseigner le mot de passe de l'administrateur de a base
de données : ocs

Ensuite il vous sera demandé de proposer un mot de passe pour la base de données
de GLPI : ocs. Puis confirmation.

Connectez-vous maintenant sur l'interface GLPI : <http://ocsinventory-ng/glpi>
ou <http://ip_du_serveur_ocs/glpi>

En cliquant sur Settings en haut à droite, on accède à un menu déroulant qui
permet de franciser l'interface.

Il s'agit maintenant de faire communiquer GLPI et OCS Inventory NG. Pour cela,
cliquer sur *Configuration* puis *Générale*.

Par défaut, le mode OCSNG n'est pas activé. Pour pouvoir l'utiliser, il faut
aller dans *Configuration* → *Générale*, cliquer sur l'onglet *Inventaire*,
mettre l'option *Activer le mode OCSNG* à Oui et valider.

Le mode OCSNG est accessible désormais accessible dans *Configuration* → *Mode
OCSNG*.

En cliquant sur *localhost*, on accède aux paramètres de connexion de glpi à la
base ocs.

    ID :                                    1
    Nom :
    Hôte de la base de données OCSNG :      localhost
    Nom de la base de données OCSNG :       ocsweb
    Utilisateur de la base de données OCSNG :   ocs
    Mot de passe de l'utilisateur OCSNG :

Les paramètres ci-dessus devraient être corrects aussi trouve-t-on :

    Connexion à la base de données OCSNG
    Connexion à la base de données OCSNG réussie
    Version et Configuration OCSNG valide

On va maintenant cliquer sur les onglets successifs

**Options d'importation**

-   Imprimantes : Privilégier le mode d'import global (pour éviter au possible
    les doublons)
-   Moniteurs : Si vous devez faire une gestion des moniteurs privilégiez
    l'import unique ou unique sur numéro de série
-   Logiciels : Import unique
-   Utiliser le dictionnaire logiciel d'OCS **IMPORTANT** Toujours laisser à NON
    si le dictionnaire n'est pas utilisé. Sinon aucun logiciel ne sera remonté.
    Dans tous les cas, préférez le dictionnaire de GLPI, plus complet et plus
    puissant Base de registre : Indique si GLPI doit importer les informations
    du registre Windows remontées par les agents OCS\
     Nombre d'éléments à synchroniser via le cron : Mettez la valeur à *Aucun*

![Options d'importation](figs/glpi_11.png)

**Informations générales**

Choisissez ce que vous souhaitez voir remonter.

![Informations générales](figs/glpi_12.png)

**Liaison automatique de machines**

Activer la liaison automatique : Oui

La liaison automatique permet de lier automatiquement une machine crée dans GLPI
avec une machine remontant d'OCS.

Pour plus d'informations sur ces réglages,
<http://www.glpi-project.org/wiki/doku.php?id=fr:config:ocsng>

![Liaison automatique de machines](figs/glpi_13.png)

# Déploiement de clients légers avec LTSP

Selon la définition même du site Linux Terminal Server Project, LTSP est un
paquet additionnel pour GNU/Linux qui permet de connecter de nombreuses stations
clientes légères sur un serveur GNU/Linux. Les applications s'exécutent sur le
serveur, les stations clientes envoient les signaux d'entrée de périphérique
vers le serveur et affichent en retour le résultat donné par les applications.

![Topologie LTSP](figs/reseau_ltsp_fr2.png)

Le serveur doit proposer plusieurs services :

1.  Serveur DHCP et DNS
2.  Serveur de fichiers qui va fournir à travers le réseau
    -   d'abord l'image du noyau nécessaire au démarrage du client
    -   ensuite un système de fichier

3.  Serveur graphique pour afficher les applications

Cela représente de nombreux paquets à installer et à configurer, heureusement il
existe une distribution qui intègre nativement une distribution LTSP complète :
Eole/Eclair.

## Configuration matérielle du serveur LTSP

Avant de commencer, voici quelques précisions importantes issues de la
documentation officielle[^2]

Le serveur doit être assez performant pour exécuter rapidement pratiquement
toutes les applications lancées depuis les clients légers (excepté les
applications embarquées). Les capacités du serveur doit donc correspondre au
nombre de clients légers à servir simultanément et du type d'utilisation. Il n'y
a donc pas de règle universelle mais quelques remarques s'imposent :

-   prévoir une machine multi-processeurs (multi-cœurs). Cela évite d'avoir tous
    les clients bloqués à cause d'un processus ou d'un client particulier ;
-   ne pas descendre en dessous de 4Go de mémoire RAM sur le serveur (sauf à
    avoir peu de clients légers simultanés), (\~256 Mo de RAM par client léger)
    ;
-   prévoir un espace disque assez grand puisque le serveur va contenir un
    bureau GNU/Linux complet ainsi que les applications nécessaires ; ne pas
    descendre en dessous de 100Mb/s pour la carte réseau.
-   La solution avec 2 cartes réseau est prévue pour fonctionner en coupure,
    c'est-à-dire que le réseau dédié aux clients légers est séparé de votre
    réseau existant (ces deux réseaux peuvent communiquer ou non entre eux, cela
    dépend de la solution retenue. Par défaut, les deux réseaux communiquent).
    Il est possible d'installer un serveur Eclair sur une machine avec une seule
    carte réseau mais cela implique que vous n'ayez pas de serveur DHCP sur
    votre réseau existant afin de pouvoir utiliser celui d'Eclair.

Voici une configuration matérielle utilisée dans une école[^3], qui comporte 1
serveur LTSP et 15 PC clients.

-   Processeur Intel core i7
-   16 Go de RAM
-   un disque dur rapide
-   2 cartes réseau gigabit

Pour notre test **sous Virtualbox**, nous allons choisir
(fig.  \ref{configEclairVB})

![Serveur Eclair\label{configEclairVB}](figs/configEclairVB.png)

-   1 ou 2 Processeur(s) avec PAE/NX activé
-   2 Go de RAM
-   15 Go de disque dur (taille dynamique)
-   2 cartes réseau
    -   Carte 1 sur le réseau d'établissement : Accès réseau par pont
    -   Carte 2 sur le réseau privé avec les clients légers : Accès réseau par
        réseau interne (nom : intnet)

## Configuration matérielle du client léger

Les clients légers n'ont finalement que peu de tâches à réaliser :

-   faire transiter les informations entre le client et le serveur ;
-   réaliser l'affichage.

La configuration minimum recommandée est un P2 300mhz avec 256 Mo de RAM.

Pour notre test **sous Virtualbox**, nous allons choisir une configuration
matérielle vraiment minimale, voyez plutôt :

-   1 processeur avec PAE/NX activé (Ressources allouées 25%)
-   256 Mo de RAM
-   PAS de disque dur !
-   1 carte réseau : Accès réseau par réseau interne (nom : intnet)


## Installation d'un serveur LTSP Edubuntu

Le moyen le plus simple d'installer un serveur LTSP est sans doute de passer
par la distribution Edubuntu <https://www.edubuntu.org/>. 

Dans la suite, on utilise la version edubuntu-14.04.2-dvd-i386.iso
téléchargeable sur
<http://cdimage.ubuntu.com/edubuntu/releases/14.04.2/release/>

Après avoir inséré l'image iso dans le lecteur de la machine virtuelle,
le système démarre (fig. \ref{installEdubuntu01})

![\label{installEdubuntu01}](figs/installEdubuntu01.png)

Le moment important est celui où on choisit d'activer LTSP et où on décide de
l'interface réseau à utiliser pour le réseau de clients légers.
(fig. \ref{installEdubuntu02})

![\label{installEdubuntu02}](figs/installEdubuntu02.png)

L'installateur propose ensuite d'ajouter des paquets pédagogiques additionnels
classés par niveau. Rien n'est obligatoire ici.

La dernière étape consiste à choisir le partitionnement du disque. Pour un
serveur dédié uniquement à la tâche qui lui incombe, il semble naturel
d'utiliser tout le disque en choisissant la première option.

Une fois l'installtion terminee, la machine redémarre. Elle est prête à faire
fonctionner des clients légers.
Voir le paragraphe sur la [mise en route d'un client léger](#clientleger).

### Installation de Epoptes pour LTSP Edubuntu

Les deux commandes suivantes permettent de mettre à jour la liste des fichiers
disponibles dans les dépôts officiels puis d'installer le serveur epoptes

```
    ~$ sudo apt-get update
    ~$ sudo apt-get install epoptes
```

Nous allons maintenant descendre dans l'environnement des machines clientes
pour y installer le client epoptes après avoir mis à jour la liste des paquets

```
    ~$ sudo chroot /opt/ltsp/i386
    /# apt-get update
    /# apt-get install epoptes-client
```

Il reste à récupérer le certificat qui assure la communication entre
client et serveur epoptes avant de revenir à l'environnement du serveur et
régénérer l'image NDB

```
    /# epoptes-client -c
    /# exit
    ~$ sudo ltsp-update-image
```

Afin de permettre à un utilisateur «prof» de lancer l'interface de gestion
epoptes pour visualiser des utilisateurs «eleve» en train de travailler sur
des clients légers, nous créons deux utilisateurs et nous donnons les droits
qui conviennent à «prof».

```
    ~$ sudo adduser eleve
    ~$ sudo adduser prof
    ~$ sudo gpasswd -a prof epoptes
```

Rendez-vous sur <http://www.epoptes.org/installation> pour des informations
complémentaires.



## Installation d'un serveur LTSP Éclair

Sur la machine serveur, on monte le DVD comme un CD-ROM virtuel comme on l'a
déjà fait (figure \ref{m69a9bc5b})

Choisissez l'installtion de EclairNG (fig. \ref{installEclair01})

![\label{installEclair01}](figs/installEclair01.png)

Une fois l'installation terminée, vous pourrez vous identifier avec le login
«root».

-   Pour scribe 2.2, le mot de passe est `eole`,
-   Pour scribe 2.3, le mot de passe est `$eole&123456$`.

Avant de nous lancer dans la configuration de notre serveur Eclair, notons ici
quelques informations réseau dont nous aurons besoin pour configurer notre
serveur :

  ----------------------------- ------------------------- --------------
  Adresse IP fixe de la carte   `… . … . … . …`           (ex.
  eth0                                                    192.168.0.106)

  Masque de sous-réseau eth0    `… . … . … . …`           (ex.
                                                          255.255.255.0)

  Adresse réseau eth0           `… . … . … . …`           (ex.
                                                          255.255.255.0)

  Adresse de broadcast eth0     `… . … . … . …`           (ex.
                                                          192.168.0.255)

  L'adresse de la passerelle    `… . … . … . …`           (ex.
                                                          192.168.0.1)

  L'adresse IP du ou des        `… . … . … . …`           (ex.
  serveur(s) DNS                                          192.168.0.1)

  Le nom de la machine          `… … … … … …`             (ex. eclairng)

  Adresse IP fixe de la carte   `… . … . … . …`           (ex.
  eth1                                                    192.168.2.1)

  Adresse réseau eth1           `… . … . … . …`           (ex.
                                                          192.168.2.0)

  Masque de sous-réseau eth1    `… . … . … . …`           (ex.
                                                          255.255.255.0)

  Adresse de broadcast eth1     `… . … . … . …`           (ex.
                                                          192.168.0.255)

  Plage DHCP                    `… . … . … . …`           (ex.
                                                          192.168.2.10 à
                                                          200)
  ----------------------------- ------------------------- --------------

Mise à jour avec réglage préalable du proxy Amon :

```
    root@scribe:~# export http_proxy='http://192.168.1.254:3128'
    root@scribe:~# Maj-Auto -i
```

Saisissez la commande `gen_config` qui va lancer le générateur de configuration

```
    root@scribe:~# gen_config
```

La série d'écrans est à renseigner en étant très attentif.

Voir figures \ref{Eclair02} à \ref{Eclair06}.

![\label{Eclair02}](figs/installEclair02.png)

![\label{Eclair03}](figs/installEclair03.png)

![\label{Eclair04}](figs/installEclair04.png)

![\label{Eclair05}](figs/installEclair05.png)

![\label{Eclair06}](figs/installEclair06.png)

Après avoir rempli les champs, on peut enregistrer ces paramètres qui vont
constituer un fichier nommé `zephir.eol` dont le rôle est de donner les
instructions au programme d'instanciation instance.

```
    # instance zephir.eol
```

Au cours de l'exécution du programme, il vous sera demandé de changer les mots
de passe

-   de l'administrateur linux restreint nommé "eclair"
-   du super administrateur Linux nommé "root" : il a tous les droits sur le
    serveur;

Pour le stage nous utiliserons les mots de passe suivants

-   Le mot de passe eclair : `1a!2b$3c`
-   Le mot de passe root : `dog!cat$mouse`


À l'issue des opérations, il ne nous reste plus qu'à créer des comptes «prof»
et «eleve».  Sur le serveur, il suffit de saisir les commandes suivantes et de
répodre aux questions

```
    # adduser prof
    # adduser eleve
```

Rendez-vous sur
<http://eoleng.ac-dijon.fr/documentations/2.3/partielles/HTML/ModuleEclair> pour
des informations complémentaires.


## Mise en route d'un client léger {#clientleger}

Le serveur LTSP ayant déjà été démarré, il attend des connexions.

Lorsqu'on démarre le client léger, celui-ci est évidemment incapable de démarrer
sur son disque dur pour la raison qu'il n'en 'a pas !

En appuyant rapidement sur la touche `F12`, on accède à l'écran de sélection du
périphérique de démarrage

```
    VirtualBox temporary boot device selection

    Detected Hard disks:

    No hard disks found

    Other boot devices:
     f) Floppy
     c) CD-ROM
     l) LAN

     b) Continue booting
```

En tapant la lettre l, on lance le démarrage sur le réseau.

![\label{pxe_client}](figs/pxe_client2.png)

Comme on le voit sur la figure \ref{pxe_client}), le client demande une adresse,
notre serveur DHCP (celui de la seconde carte du serveur LTSP) lui en fournit
une. Ensuite Le client récupère via TFTP[^4] un noyau minimal `pxelinux.0` situé
sur le serveur dans le dossier `ltsp/i386` situé sur le serveur dans
`/var/lib/tftpboot`.

Ensuite la configuration pxe est transmise par les fichiers du dossier
`pxelinux.cfg/` situé sur le serveur dans `/var/lib/tftpboot/default`.

![Login](figs/login2.png)

Connectez-vous avec le login «prof» ou «eleve» définis plus haut.



[^1]: Ce compte est en général réservé à la DSI

[^2]: <http://eoleng.ac-dijon.fr/documentations/2.3/partielles/HTML/ModuleEclair/co/04-pre-requis_1.html>

[^3]: voir
    <http://dmesg.fr/categorie-installation/103-dossier-installer-serveur-ltsp-avec-debian-gnu-linux-6-squeeze>

[^4]: un protocole simplifié de transfert de fichiers.
