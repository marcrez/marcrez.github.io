---
title: Drupal 8 and Git
permalink: drupal8-and-git
layout: post
date: 2017-06-12
tags: [drupal]
---



# En pré-prod

    drush cex
    git add -A
    git commit -m "message de commit"
    git push

# En prod

    git pull
    drush cim
    drush cr
