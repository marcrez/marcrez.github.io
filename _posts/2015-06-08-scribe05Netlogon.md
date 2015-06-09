---
title: Utiliser les scripts de netlogon
layout: post
date: 2015-06-8 13:30:00
tags: [scribe]
category: scribe
---

Lorsqu'un utilisateur ouvre une session sur un poste client, le programme
logon.exe est exécuté. Il construit puis exécute le fichier de logon
`\\<scribe>\netlogon\<login><OS>.txt` qui contient les lecteurs réseau à
connecter et des commandes à exécuter lors de l'ouverture de session.

## Principes et utilisation sous Scribe

Ce fichier `<login><OS>.txt` (par exemple `adminWinXp.txt`) est le résultat
de la concaténation des fichiers `.txt` qui conviennent parmi les
sous-répertoires de `netlogon\scripts`. Par exemple on peut ajouter un script
pour différents destinataires

| Destinataire    |  Fichier
|:----------------|:--------------------------------------
| un utilisateur  | `netlogon\scripts\users\admin.txt`
| un groupe       | `netlogon\scripts\groups\eleves.txt`
| une Machine     | `netlogon\scripts\machines\poste01.txt`
| un OS (WinXP)   | `netlogon\scripts\os\WinXP.txt`
| tous            | `netlogon\scripts\groups\DomainUsers.txt`


Les scripts de netlogon peuvent faire deux choses 

1.  **Mapper un lecteur**. Par exemple, pour mapper, pour l'administrateur, un
    nouveau lecteur nommé `Z:\ ` qui pointera vers le dossier `netlogon` du
    serveur nommé `scribe`, on placera la ligne suivante dans le fichier
    (éventuellement à créer) `netlogon\scripts\users\admin.txt`

        lecteur,Z:,\\scribe\netlogon

2.  **Exécuter une commande**. Avec éventeullement les options `HIDDEN` (masque la
    fenêtre) et/ou `NOWAIT` (rend la main pour lancer de nouvelles instructions
    avant la fin de l'exécution).

    Par exemple la ligne suivante dans le fichier
    `netlogon\scripts\groups\DomainUsers.txt` affichera un message de bienvenue
    à l'utilisateur  pendant trois secondes, mettant les instructions suivantes
    en attente.

        cmd,msg %USERNAME% /TIME:3 “Bonjour”

    Autre exemple, la ligne suivante dans le fichier `netlogon\scripts\os\WinXP.txt`
    lancera notepad sur les machines WinXP et les instructions suivantes seront
    exécutées sans attendre la fermeture de notepad.

        cmd,%windir%\notepad.exe,NOWAIT

Si des instructions doivent être effectuées après les montages scribe par défaut
(nécessité d'avoir accès au lecteur "commun" par exemple), placez la balise
`%%NetUse%%` et ajoutez les instructions ensuite.

Dans l’exemple suivant, on voit que le script
`netlogon\adminWinXp` ajoute un lecteur réseau et affiche un message
de bienvenue à la connexion de l'administrateur sur une station WindowsXP.

![Un script de netlogon](figs/scribe_html_m2d0d8a5c.png)

Remarque : Le programme `logon.exe` est lancé dans l'environnement utilisateur,
il hérite donc des droits de l'utilisateur. Cela signifie que les commandes
s'exécutent avec les droits de l'utilisateur.


## Passer outre les droits d'administration

Voyons maintenant comment lancer silencieusement une installation lorsqu'un
utilisateur sans droits particuliers se connecte.

Une méthode simple consiste à consiste à écrire un fichier batch contenant les
instructions d'installation puis à convertir le fichier .bat en un fichier
exécutable .exe qui va embarquer avec lui les droits de l'administrateur pour
exécuter les commandes qu'il contient.

Sur <http://www.battoexeconverter.com/> on trouve un tel logiciel de conversion.

Une fois *batToExeConverter* lancé, on lui indique le chemin du fichier batch
à convertir. L'important est de bien cocher la case *Add administrator manifest*.

![Bat to exe Converter\](figs/battoexe.png)

En cliquant sur le bouton *Compile*, on va générer le fichier .exe qu'il restera
à placer dans un dossier dans lequel les utilisateurs sans droits ont accès.
Par exemple dans un sous-répertoire de *commun*.

