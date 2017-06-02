---
title: Intégrer des clients Windows ou Linux au domaine
layout: post
date: 2015-06-8 18:30:00
tags: [scribe, reseau]
category: scribe
---

Dans la section précédente, on a installé un serveur Scribe.
Il fonctionne et est accessible sur le réseau. Il est maintenant
possible d'intégrer des machines au domaine.

## Intégrer un poste Windows au domaine

1.  Première étape : faire entrer les machines windows dans le domaine. La copie
    d'écran suivante montre l'utilisateur admin faisant
    entrer dans le domaine une machine sous WindowsXP.

![intégration au domaine]({{ site.baseurl }}/images/gestionReseau/scribe_html_78aacfe6.png)

La procédure est tout à fait identique sous Windows 7 à ceci-près qu'un message
d'erreur apparaît dont on ne tiendra pas compte. Profitons de cette parenthèse
pour désactiver l'UAC *User Account Control* : ouvrez le Panneau de
configuration puis cliquez successivement sur «Comptes et protection
utilisateurs» puis «Comptes d’utilisateurs» et «Modifier les paramètres de
contrôle du compte d'utilisateur» descendez alors le cuseur au plus bas.

![UAC]({{ site.baseurl }}/images/gestionReseau/windows-seven-uac-1.jpg)

2.  Deuxième étape : installer le client scribe.

Après redémarrage et connexion en tant qu'admin sur le domaine, rendons-nous
dans le poste de travail puis dans le répertoire personnel nommé `U:` Nous
allons exécuter le programme `Install_Client_Scribe`.

![Installation du client scribe]({{ site.baseurl }}/images/gestionReseau/scribe_html_m4358be12.png)

Cette opération va configurer de nouveaux lecteurs réseau, installer VNC et
d'autres outils.

## Intégrer un poste Linux au domaine

Installer un poste sous Linux est très simple (on trouve de nombreux tutos sur
le web). C'est même déjà fait sur les ordinateurs livrés par la région Île de
France : le démarrage est multiboot et permet de choisir entre MSWindows ou
Ubuntu.

Dans le paragraphe précédent, nous avons vu comment intégrer au domaine un
poste sous Windows. Nous allons voir ici comment faire de même sous Linux afin
que 

- les utilisateurs puissent se connecter en utilisant leur login/motDePasse
  usuel (authentification sur l'annuaire de l'établissement)
- les utilisateurs connectés aient accès à leur répertoire personnel ainsi
  qu'aux lecteurs réseaux partagés (Commun, Travail)

L'intégration des postes sous Linux est simple grâce au travail de la DANE de
l'académie de Lyon qui propose un script téléchargeable sur Github.

Rendez-vous sur https://github.com/dane-lyon/ puis dans le répertoire nommé
clients-linux-scribe.

Selon la version Linux (Mint17, Ubuntu14.04, Xubuntu14.04,...) installée sur le
poste à intégrer au domaine, cliquer sur le lien qui convient.

Pour télecharger le script, cliquer sur le bouton `Raw` 
puis clic-droit et Enregistrer la page à la racine du répertoire personnel de
l'utilisateur courant.

![danelyon]({{ site.baseurl }}/images/gestionReseau/danelyon.png)

Il reste à rendre le script executable puis à le lancer. Pour cela, dans un
terminal, saisir les commande suivantes (à adapter au nom du script téléchargé)

```
    $ chmod +x client_scribe_ubuntu_14.04.sh
    $ sudo ./client_scribe_ubuntu_14.04.sh
```

Après avoir répondu aux questions sur les adresses IP de scribe et du proxy puis
avoir donné les identifiants de l'admistrateur du domaine, il ne reste plus qu'à
redémarrer la machine pour bénéficier de tous les services du réseau pédagogique.

