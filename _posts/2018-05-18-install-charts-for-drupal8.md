---
title: Installer le module Charts pour Drupal 8
permalink: charts-for-drupal8
layout: post
date: 2018-04-10
tags: [drupal]
---


Le module Charts permet d'obtenir des graphiques dans Drupal 8.
Son installation demande un peu de travail.

D'abord, il faut installer le module proprement dit

    $ composer require drupal/charts

Dans un second temps, une librairie graphique doit être ajoutée.
Nous installons ici google-charts.

Suivre le README du dossier charts/modules/charts_google de modules/contrib/

    $ composer require --prefer-dist composer/installers

Vérifier que la section `"extra"` contient bien

     "web/libraries/{$name}": [
         "type:drupal-library"
     ],

Ajouter 

     "repositories": {
        "google_charts": {
            "type": "package",
            "package": {
                "name": "google/charts",
                "version": "45",
                "type": "drupal-library",
                "extra": {
                    "installer-name": "google_charts"
                },
                "dist": {
                    "url": "https://www.gstatic.com/charts/loader.js",
                    "type": "file"
                },
                "require": {
                    "composer/installers": "~1.0"
                }
            }
        },

puis lancer le téléchargement

    $ composer require --prefer-dist google/charts:45

Pour vérifier le fonctionnement de tout cela,
https://github.com/andileco/chart_block_example
