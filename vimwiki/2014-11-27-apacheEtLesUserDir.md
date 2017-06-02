---
title: Répertoires utilisateur pour apache
layout: post
date: 2014-11-27
tags: [bash, linux]
category: notes
---

Dans le répertoire mods-enabled

    $ cd /etc/apache2/mods-enabled

créer les iens symboliques vers les fichiers déjà configurés
et, si nécessaire, activer le mode correspondant

    $ sudo ln -s ../mods-available/userdir.load
    $ sudo ln -s ../mods-available/userdir.conf
    $ sudo a2enmod userdir

Dans php5.conf, un jeu d'instructions désactive php 
dans les répertoires utilisateur, commentons donc les lignes

    $ vim php5.conf

    # Running PHP scripts in user directories is disabled by default
    <IfModule mod_userdir.c>
        <Directory /home/*/public_html>
            php_admin_flag engine Off
        </Directory>
    </IfModule>

C'est terminé, il ne reste plus qu'à redémarrer apache après avoir écrit
un fichier php de test

    $ echo "<?php phpinfo(); ?>" > /home/moiMeme/public_html/test.php
    $ sudo apache2ctl restart

Les infos php devraient s'afficher sur
http://localhost/~moiMeme/test.php

