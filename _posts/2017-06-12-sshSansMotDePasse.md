---
title: Se connecter en SSH sans mot de passe
permalink: sshSansMotDePasse
layout: post
date: 2017-06-12
tags: [linux, bash]
---

Pour se connecter via SSH sur une machine distante, on peut éviter la saisie
systématique d'un mot de passe en échangeant une clé. Voici comment faire.

# Le but

Se connecter depuis la machineA en tant qu'alice sur la machineB en tant que bob.

# La méthode

Sur la machine A, on génère une paire de clés d'authentifiaction. Inutile de
saisir un mot de passe lorsque la commande suivante le demande.

    alice@machineA $ ssh-keygen -t rsa

Sur la machineB, on crée un répertoire `.ssh` dans le dossier personnel de bob

    alice@machineA $ ssh bob@machineB mkdir -p .ssh

On y place alors la clé publique générée il y a un instant

    alice@machineA $ cat .ssh/id_rsa.pub | ssh bob@machineB 'cat >> .ssh/authorized_keys'

La connexion se fait désormais sans mot de passe

    alice@machineA $ ssh bob@machineB
