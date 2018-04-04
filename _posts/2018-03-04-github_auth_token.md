---
title: Ajouter un token pour composer.json 
permalink: Oauth-token-composer
layout: post
date: 2018-03-04
tags: [shell, drupal]
---


Quand github refuse le téléchargement, c'est peut être parceque
le quota est atteint. La solution  générer un token d'authentification
et le placer dans composer.json.

# Creating a personal access token for the command line

Settings > Developer settings > Personal access tokens.
Generate new token

    "config": {
            "github-oauth": {
                 "github.com": "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx"
            }
    },
