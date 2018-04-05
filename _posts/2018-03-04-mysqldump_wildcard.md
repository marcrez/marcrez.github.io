---
title: MySQLdump wildcard 
permalink: mysqldump-wildcard
layout: post
date: 2018-04-05
tags: [mysql]
---



Pour sauvegarder toutes les tables d'une base de données Mysql, mysqldump est
l'outil idéal. Cependadant, si on souhaite sauvegrder seulement certaines
tables, il faut ruser.  

# La technique

On va sauvegarder ici dans le fichier `BKP.sql` l'ensemble des tables
de la base `MYDB` dont le nom commence par `XX`

    mysqldump -u root -p MYDB $(mysql -u root -p -D MYBD -Bse "show tables like 'XX%'") > BKP.sql

