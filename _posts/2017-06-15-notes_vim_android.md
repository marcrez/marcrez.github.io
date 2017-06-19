---
title: Prendre des notes avec Vim (et android)
permalink: notes_vim_et_android
layout: post
date: 2017-06-12
tags: [linux, vim]
---


Cela faisait longtemps que je cherchais un moyen simple et efficace pour
rédiger des notes, des memos et autres TODO lists synchronisées à la fois sur
téléphone et editables avec mon editeur préféré ordinateur.

![img]({{ site.baseurl }}/notes_vim_android/iA.png)

# Premiers essais avec Evernote et Google Keep

Sur android les app pour ces deux solutions sont bien conçues, rien à dire.
C'est sur ordinateur que je n'ai pas été seduit. Il n'y a pas de client
officiel sous linux. On ne peut que se rabatte sur le module firefox ou chrome.

Après quelques semaines d'utilisation, j'ai abandonné ces solutions car elles
utilisent des formats specifiques et ne me permettaient pas de modifier les
fichiers avec un editeur de texte comme gedit ou vim sauf à  faire des
copier-coller manuellement.

# Définition des besoins

Les avantages et inconvénients des solutions précédentes, m'ont conduit à la
liste des besoins suivants :

* sauvegarde des notes au format texte
* editeur disposant d'une police monospace (alignements plus faciles)
* possibilité de visualiser les notes écrites en markdown
* synchronisation sur un cloud
* disponible et stable sous linux
* disponible et efficace sous android

# Dropbox, Vim et iA Writer

Sous linux, le client de synchronisation est très simple à installer et il est
d'une remarquable stabilité. Ecrire des notes sous n'importe quel editeur de
texte ne pose donc aucun problème et les documents sont synchronisés avec le
cloud quasi-instantanément à la sauvegarde.

La difficulté se situe sur le téléphone. Il faut un éditeur de texte efficace
et qui gère bien la synchronisation avec dropbox.

Après avoir testé plain qui ne dispose pas de police monospace j'ai passé un
peu de temps avec JotterPad qui est très bon dans sa version payante (environ
5€).  Finalement, j'ai choisi iA Writer qui répond à tous les critères et
dispose en plus d'un raccourci pour créer et utiliser des todo lists comme
celle-ci
    - [x] écrire un article
    - [ ] publier un article



