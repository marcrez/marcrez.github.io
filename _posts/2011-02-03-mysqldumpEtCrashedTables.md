---
title: MysqlDump et Crashed tables
layout: post
date: 2011-02-03
tags: [mysql, linux, bash]
category: notes
---

![MySQL](http://upload.wikimedia.org/wikipedia/fr/6/62/MySQL.svg)

Suite à un crash sur le serveur, j'ai voulu sauvegarder une table dans une base de données,

    :::bash
    $ mysqldump -u root -p maTable > maTable.sql
    Enter password: 
    mysqldump: Got error: 145: Table 'maTable' is marked as crashed 
               and should be repaired when using LOCK TABLES

La solution : lancer une réparation de la table :

    :::bash
    $ cd /var/lib/mysql/maTable
    $ myisamchk -r -q maTable/*MYI
