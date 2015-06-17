---
title: Fonctionnement d'un réseau pédagogique
layout: post
date: 2015-06-8 20:30:00
tags: [scribe]
category: scribe
---

![eole](http://eole.orion.education.fr/templates/eole/images/mw_joomla_logo.png)
Sur l'académie de Paris, les réseaux d'établissement sont généralement organisés
par la DSI, service informatique du Rectorat qui assure en plus l'administration
et la maintenance des serveurs Amon, Scribe et Horus.

![Schéma d'un réseau d'établisement.]({{ site.baseurl }}/images/gestionReseau/reseau_etab.png)

Les établissements assurent par eux-même les tâches de gestion courante des
machines et ont accès aux interfaces de gestion des serveurs pédagogiques.

## Déroulement de la formation : réseau virtuel

Durant cette formation, nous allons simuler un réseau d'établissement grâce à
des machines virtuelles. Cela nous permettra de contrôler complètement tous les
éléments, d'effectuer tous les tests sans risque pour les machines réelles sans
quitter notre siège !

![Un réseau de machines virtuelles.]({{ site.baseurl }}/images/gestionReseau/reseau_stage_schema3.png)

Un poste virtuel est un ordinateur dont tous les composants matériels sont
simulés mais sur lequel a été installé un système d'exploitation comme sur une
machine réelle. Vue depus le réseau, c'est une machine comme une autre.

Sur la figure  précédente, on simule un serveur Scribe et deux
machines clientes, une sous Windows XP et l'autre sous Windows 7 sur un
ordinateur (réel celui-là) appelée machine hôte.

La situation décrite sur la figure précédente est équivalente à
celle de la figure suivante.

![Schéma d'un réseau pédagogique.]({{ site.baseurl }}/images/gestionReseau/reseau_stage_VM.png)

