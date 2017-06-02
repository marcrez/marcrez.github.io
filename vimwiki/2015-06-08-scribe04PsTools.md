---
title: Gérer un parc de PC Windows à distance
layout: post
date: 2015-06-8 17:30:00
tags: [reseau]
category: scribe
---

La suite PsTools contient un utilitaire nommé psExec qui permet de prendre
le contrôle de machines distantes comme le ferait le logiciel PcAnywhere
de Symantec.


## Prendre le contrôle

Une fois le logiciel PsTools téléchargé et installé depuis 
<https://technet.microsoft.com/en-us/sysinternals/bb897553.aspx>

on lance l'invite de commande (touche Windows + R puis `cmd`)
et on va envoyer un message sur une machine distante (disons 192.168.1.100)
dont on connaît des identifiants de connexion (user = admin ; password = mdp)

```
    psexec.exe \\192.168.1.100 -u admin -p "mdp" msg * "Je prends le controle!"
```

Autre exemple qui montre qu'on peut intéragir (option `-i`) en lançant des
programmes sur la session en cours sur les machines distantes : ici, on lance
l'éditeur de texte notepad

```
    psexec.exe \\192.168.1.100 -u admin -p "mdp" -i notepad
```

Il est possible de lancer des programmes sur plusieurs machines à la fois
en séparant les IP par des virgules

```
    psexec.exe \\192.168.1.100,192.168.1.101,192.168.1.103 -u admin -p "mdp" -i notepad
```

En fait, on le verra plus bas, il est possible de placer une liste d'IP dans un fichier 
nommé par exemple `liste.txt` afin de lancer la commande sur un lot de machines

```
    psexec.exe @liste.txt -u admin -p "mdp" -i notepad
```

Maintenant, plutôt que lancer notepad, nous allons lancer des programmes
d'installation afin de déployer des applications sur des listes de machines,
tout cela à distance.


<!--
On peut aussi prendre la main sur l'invite de commande de la machine distante
pour y travailler

```
    psexec.exe \\192.168.1.100 -u admin -p "mdp" cmd
```

Pour vérifier que vous travaillez désormais sur la machine distante, essayez

```
    msg * "Je travaile à distance"
```
-->

> **En cas de problème**. Pour utiliser PsTools, il faut parfois configurer
> le système
>
> 1. *Configuration du pare-feu via GPO*\
>    Modèles d'administration / Réseau / Connexions réseau / Pare-feu Windows /
>    Profil du domaine.
>     - Pare-feu Windows: autoriser l'exception de partage de fichiers entrants et
>       d'imprimantes (définir une ip, ex: 192.168.0.0/24)
>     - Pare-feu Windows: autoriser les exceptions ICMP (pour les requêtes "echo")
> 2. *Configuration de la sécurité des comptes locaux*\
>    Panneau de configuration / Outils d'administration / Stratégie de sécurité
>    locale Stratégies de sécurité locales / Option de sécurité /
>    Accès réseau : modèle de partage et de sécurité pour les comptes locaux\
>    => Paramètres de sécurité à droite et changer "Invité" par "Classique"


## Installations silencieuses

Le but de cette section étant de lancer des installations à distance, il est 
important qu'elles se déroulent sans gêner les utilisateurs de ces machines :
ils sont sans doute en train de travailler et il faut éviter que des fenêtres 
s'ouvrent en leur posant des questions sur un installation dont ils ne savent
rien.

La plupart des programmes d'installation acceptent des options permettant une 
installation «*silencieuse*» : c'est le mot important.

En dehors des moteurs de recherche avec les mots clé «*installation silencieuse*»
ou «silent install» pour trouver comment faire pour un logiciel particulier,
il existe une base très fournie :
<https://dev-eole.ac-dijon.fr/projects/wpkg-package/repository/revisions/master/show/packages>.

sur cette page, cliquer sur un des logiciels de la liste, par exemple *7zip.xml*
puis cliquer sur *voir*. On trouve

1. Un lien de téléchargement dans la balise commençant par `<eole dl=`
2. Une commande d'installation dans la balise `<install cmd=`
2. Une commande d'e mise à jour dans la balise `<upgrade cmd=`
2. Une commande de suppression dans la balise `<remove cmd=`

Bien sûr ces liens et commandes sont écrits avec des variables qu'il faudra
adapter manuellement mais cela donne une bonne indication sur les fichiers à
télécharger et les commandes et options à écrire pour une installation
silencieuse complète.

### Java

Par exemple une recherche sur «java installation silencieuse» renvoie une page
qui explique sur un exemple que c'est l'option `/s` qui élimine les intéractions
durant la phase d'installation. 

> *Supposons que le programme d'installation JRE soit jre-7-windows-i586.exe 
> et que vous souhaitiez installer la configuration suivante :
> Effectuer une installation Windows Installer le serveur de base de JRE, les
> polices et couleurs supplémentaires et Soundbank La commande permettant
> d'installer la configuration ci-dessus est la suivante :* \
> `jre-7-windows-i586.exe /s`\
> Où `jre-7-windows-i586.exe` est bien le fichier d'installation complet 
> (plusieurs Mo) et non le lanceur de téléchargement (quelques Ko).

### LibreOffice

Parfois les installations se font non pas avec un fichier exécutable .exe
mais avec un fichier .msi (Microsoft Software Installer). C'est le cas pour
LibreOffice. Dans l'exemple qui suit, c'est l'option `/qn` qui élimine les
intéractions.

> *Pour installer LibreOffice*
>
> - *Télécharger l'installeur LibreOffice4.x.x.msi*
> - *Lancer la commande* \
>   `msiexec /i LibreOffice4.x.x.msi ISCHECKFORPRODUCTUPDATES=0 CREATEDESKTOPLINK=0 REGISTER_ALL_MSO_TYPES=1 /qn`

## FePsTools une interface graphique pour PsTools


Afin de se simplifier la tâche, on peut utiliser l'outil FePsTools (Front-end
PsTools) disponible sur <www.davitools.com/fepstools/> il s'agit d'un
exécutable à placer dans le même dossier que les outils de la suite PsTools,
Par exemple dans le répertoire personnel de l'administrateur, ainsi les outils
seront disponibles depuis tout poste du réseau.

La figure \ref{fepstools} montre une copie d'écran de FePsTools prêt à 
lancer l'installation silencieuse de notepad++ sur une machine distante
à partir du fichier d'installation présent sur la machine pilote.

![FePsTools en action\label{fepstools}]({{ site.baseurl }}/images/gestionReseau/fepstools.png)

En fait, plutôt que déployer sur une seule machine dont on spécifie l'IP, 
il est possible d'effectuer le déploiement sur une liste de 
machines en cochant la case *Use Computer List*.

On devra alors charger un fichier nommé par exemple `liste.txt` qui contient 
la liste des IP des machines à impacter comme ceci

    192.168.1.35
    192.168.1.78
    192.168.1.95
    192.168.1.135

Si la résolution de nom des machines windows fonctionne, il est même possible 
de remplir le fichier `liste.txt` avec des noms de machine

    S30Poste01
    S30Poste02
    S30Poste03
    S30Poste04

Remarque : il serait sans doute pratique de constituer des fichiers par salle
afin de les charger au besoin pour lancer des installation ciblées, simplement
en choisissant le bon fichier.

## Un script pour automatiser les installations
    
Afin d'éviter des installations inutiles, plutôt que lancer l'installeur sur un
ensemble de machines distantes, on va lancer un script batch, c'est à dire un
petit programme, que nous allons écrire et qui va lancer l'installation
seulement si elle est nécesaire.

### Geogebra

Commençons par télécharger l'installeur GeoGebra au format .msi et déposons-le
dans un répertoire accessible depuis tout poste du réseau pédagogique le
répertoire «`Commun\logiciels`». Le chemin d'accès à l'installeur sera donc

    T:\logiciels\GeoGebra-Windows-Installer-3-2-47-0.msi

Nous écrivons maintenant un fichier nommé `ggbInstall.bat` qui contient la ligne
suivante

    msiexec /i T:\logiciels\GeoGebra-Windows-Installer-3-2-47-0.msi /qn

En lançant le programme `ggbInstall.bat` avec `psExec` ou avec `FePsTools` on
va alors installer geogebra sur une liste d'ordinateurs.

C'est bien mais on peut faire mieux. Éditons à nouveau le fichier
`ggbInstall.bat` et ajoutons-lui  ces quelques lignes qui vont tester si un
dossier `geogebra` est présent dans le dossier des programmes de la machine
distante et ainsi éviter une installation inutile.

    if exist “%PROGRAMFILES%\geogebra”  goto NoInstall
    msiexec /i T:\logiciels\GeoGebra-Windows-Installer-3-2-47-0.msi /qn
    msg * “L'installation de Geogebra est terminée”
    goto end
    :NoInstall
    msg * “Aucune installation”
    :end

<!--
> Allons encore plus loin. Supposons que le fichier contenant la liste des
> adresses IP des machines distantes contienne un grand nombre de machines mais
> qu'on souhaite installer GeoGebra seulement sur les ordinateurs de la salle23
> (tous nommés `S23POSTE01` , `S23POSTE02`, `S23POSTE03`, etc.)

> On va modifier à nouveau le fichier `ggbInstall.bat` pour lui ajouter une ligne
> qui teste si le nom de la machine contient la chaine de caractères `S23POSTE` 

> Pour cela on enregistre le nom de l'ordinateur dans la variable `ordi`.
> Ensuite, utilise le code `%ordi:S23POSTE=%` qui va afficher le nom de l'ordi
> dans lequel la chaîne `S23POSTE` sera remplacée par une chaîne vide.  On peut
> alors comparer avec la chaîne originale contenue dans la variable  `ordi`. Si
> les chaînes sont égales, c'est que la machine ne fait partie de la salle 23 et
> donc on passe l'installation.

>     set ordi=%COMPUTERNAME%
>     if x%ordi:S23POSTE=% == x%ordi%    goto NoInstall
>     if exist “%PROGRAMFILES%\geogebra” goto NoInstall
>     msiexec /i T:\logiciels\GeoGebra-Windows-Installer-3-2-47-0.msi /qn
>     msg * “Installation de Geogebra terminée”
>     goto end
>     :NoInstall
>     msg * “Aucune installation”
>     :end
-->

