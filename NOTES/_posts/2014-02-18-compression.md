---
title: Compression de données
layout: post
tags: [algo]
category: notes
---

# Introduction
## Pourquoi compresser un fichier ?

 
- Pour économiser l'*espace* quand on l'enregistre
- pour économiser du *temps* quand on le transmet
- la plupart des fichiers contiennent des informations redondantes


## Qui a besoin de compresser ?

- Les processeurs suivent la loi de Moore en
  doublant leur puissance tous les deux ans
- Les données ont tendance à suivre la loi des gaz
  en augmentant pour occuper l'espae disponible 

 >L'ancien PDG de Google, Eric Schmidt, estimait en 2010 que nous produisions
    tous les deux jours environ 5 exaoctets (Eo, soit un million de Téraoctets)
    d'informations... soit autant «qu'entre le début de la culture humaine et
    2003» !


## Exemples

- Compression de fichier : zip, gzip, 7zip, rar
- Au niveau du système de fichier : ntfs, zfs, btrfs
- Images : jpeg, gif, png
- Son : mp3, ogg, wma
- Vidéo : mpeg, h.264, divx, wmv


# Compression sans perte

On dispose d'un message M et d'un algorithme de compression C.

- La taille de $C(M)$ est inférieure à celle de $M$
- L'application de compression $C$ est inversible :  $C\circ C^{-1}=Id$


```
Message M->Message compressé C(M): Compression
Message compressé C(M)-->Message M: Décompression
```

# Un exemple de compression sans perte : codage du génôme



La structure de l'ADN est une double-hélice composée de deux brins complémentaires. Chaque brin d'ADN est constitué d'un enchaînement de nucléotides notés G, A, T et C.

Comment représenter et enregistrer une séquence ?

Avec des lettres ?

| char   | hex   | binaire  |
| ------ | ----- | -------- |
| A      | 41    | 01000001 |
| C      | 43    | 01000011 |
| G      | 47    | 01000111 |
| T      | 54    | 01010100 |

ou un code binaire spécialisé ?

| char | binaire |
| ---- | ------- |
| A    | 00      |
| C    | 01      |
| G    | 10      |
| T    | 11      |  

La seconde méthode permet l'enregistrement d'un fichier correpondant à une 
séquence de N nucléotides en 2N bits au lieu de 8N bits.




Comme on le voit, la bonne méthode de compression dépend du fichier à
compresser.

Théorème : Il n'existe pas de compresseur universel sans perte.

Démonstration 1 : supposons qu'il existe un compresseur sans perte universel C,
alors, pour tout message M, on la longueur de C(M) serait stricitement
inférieure à celle de M. Une récurrence descendante immediate conduirait à la
conclusion suivante : tout message peut être compressée sans perte en un
fichier de taille nulle en appliquant C suffisamment de fois. Ce qui est
manifestement absurde.

Démonstration 2: Supposons qu'il existe un compresseur sans perte universel C,
alors il peut compresser tous les fichiers de 1000 bits. L'ensemble des
fichiers de 1000 bits contient 2^1000 éléments. Or l'ensemble des fichiers de
strictement moins de 1000 bits contient 2^1000-1 éléments. Au moins deux
fichiers différents de 1000 bits se trouveraient compressés sous la même forme,
ce qui contredit l'absence de perte. 

## Codage par plages

Le run-length encoding, appelé codage RLE ou codage par plages s'applique à des
fichiers contenant de longues séquences d'éléments répétés. Une texte scanné en
noir et blanc par exemple comportera des zones uniformes noires ou plus
fréquemment blanches.

    000000000000111110000000001111

pourrait être codé avec les nombres 12, 5, 10, 4, c'est à dire en choisissant une
représentation binaire sur 4 bits 1100, 0101, 1010, 0100 soit

    1100010110100100



