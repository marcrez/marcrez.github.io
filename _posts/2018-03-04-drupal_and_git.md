---
title: Drupal 8 and Git
permalink: drupal8-and-git
layout: post
date: 2018-03-04
tags: [drupal]
---



Maintenir un site drupal 8 en prod cohérent avec la pré-prod grâce à drush et git.

# En pré-prod

    drush cex
    git add -A
    git commit -m "message de commit"
    git push

# En prod

    git pull
    drush cim
    drush cr
