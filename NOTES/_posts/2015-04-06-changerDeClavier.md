---
title: Changer de clavier
layout: post
date: 2015-04-06 09:17
tags: [linux]
category: notes
---

![qwerty International](http://upload.wikimedia.org/wikipedia/commons/thumb/e/ea/KB_USA-international.svg/500px-KB_USA-international.svg.png)

Pour passer d'un clavier azerty à qwerty, il suffit d'une ligne de commande.

    setxkbmap -layout us -variant altgr-intl -option nodeadkeys

Notes sur les raccourcis pour obtenir les caractères spéciaux :

- é : `AltGr+e`
- è : `AltGr+\`` e
- ë : `AltGr+r` ou AltGr+" e
- à : `AltGr+`` a
- ç : `AltGr+,` ou AltGr+' c
- « : `AltGr+[`
- » : `AltGr+]`
- œ : `AltGr+x` ou `AltGr+k`
- æ : `AltGr+z`
- ½ : `Altgr+&`
- ¼ : `AltGr+^`
- ¾ : `AltGr+*`
- ¹ : `AltGr+1`
- ² : `AltGr+2`
- ³ : `AltGr+3`
- × : `AltGr+=`
- ÷ : `AltGr++`
