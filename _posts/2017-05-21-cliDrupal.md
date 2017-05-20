---
title: Drupal et la ligne de commande
permalink: cli_drupal
layout: post
date: 2017-05-21
tags: [drupal]
category: raspberrypi
---

Télécharger la dernière version

```
wget http://files.drush.org/drush.phar
```

Vérification :

```
php drush.phar core-status
```

Déplacer et renommer `drush.phar` pour qu'il soit accessible en exécution 

```
chmod +x drush.phar
sudo mv drush.phar /usr/local/bin/drush
```

