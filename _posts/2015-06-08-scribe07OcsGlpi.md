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
