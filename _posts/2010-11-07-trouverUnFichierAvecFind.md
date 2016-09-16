---
title: Trouver un fichier avec `find`
layout: post
date: 2010-11-07
tags: [bash, linux]
category: notes
---

![Find](http://upload.wikimedia.org/wikipedia/commons/3/39/1328102012_Find.png)

Avec la commande find on peut effectuer des recherches. La commande suivante
affichera tous les fichiers se nommant fichier.txt à partir du répertoire
racine.

    :::bash
    $ find / -name "fichier.txt"

Cette commande affichera tous les fichiers se nommant fichier.txt à partir du
répertoire racine. Il est possible d'utiliser les expressions régulières :

    :::bash
    $ find / -name "toto*"

Le résultat sera tous les fichiers et répertoires commençant par toto, suivi de
n'importe quelle occurrence. Pour éviter d'avoir les "permission denied" sur
des répertoires :

    :::bash
    $ find / -type f -name "le_fichier_a_chercher" 2>/dev/null

find est très puissant, et permet aussi d'employer les expressions régulières,
comme le montre l'exemple suivant qui permet de trouver tous les fichiers
contenant une chaine ou une regexp dans une arborescence :

    :::bash
    $ find <repertoire_depart> -type f -exec grep -H "<chaine_ou_regexp>" {} ;

Lorsqu'il s'agit de gros volumes de fichiers :

    :::bash
    $ find <repertoire_depart> -type f | xargs grep -H "<chaine_ou_regexp>"

Renommer toutes les fichiers contenant chaine en str :

    :::bash
    $ for i in `ls *chaine*` ; do mv $i `echo $i | sed 's/chaine/str'` ; done

En récursif sur une arborescence :

    :::bash
    $ for i in `find . -type f -name "*chaine*" ; do mv $i `echo $i | sed 's/chaine/chene'` ;done

Il y a même moyen d'effectuer des opérations sur fichier en appelant des
scripts externes; par exemple : changer toutes les option=true en option=false
dans tous les fichiers .conf en recursif en gardant une copie de sauvegarde :

    :::bash
    $ find . -type f -name "*.conf" | xargs perl -pi.save -e 's/option\=true/option\=false/'`</repertoire>
