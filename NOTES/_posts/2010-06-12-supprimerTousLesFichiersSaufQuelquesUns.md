---
title: Supprimer tous les fichiers sauf quelques-uns.
layout: post
date: 2010-06-12
tags: [bash, linux]
category: notes
---

![Trash bin](http://upload.wikimedia.org/wikipedia/commons/thumb/b/bd/User-trash-full.svg/200px-User-trash-full.svg.png)

Aujourd'hui (la fin de l'année scolaire approchant), il s'agit de nettoyer un
dossier partagé contenant un millier de fichiers. La commande suivante crée la
liste des fichiers de ce répertoire

```
$ for i in * ; do echo $i >> ListeRep; done;
```

Après que tout le service, les utilisateurs autorisés sur le dit dossier, soit
intervenu sur cette liste, le fichier ListeRep.txt ne contient plus que les
fichiers à conserver ; les autres étant à supprimer. Voici une méthode pour le
faire en trois opérations

```
$ mkdir keep 
$ cat ListeRep.txt | while read ligne; do set $(echo $ligne); mv $1 keep/; done;
$ rm * && mv keep/* && rmdir keep
```
