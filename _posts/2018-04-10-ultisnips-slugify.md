---
title: Ultisnips slugify
permalink: ultisnips-slugify
layout: post
date: 2018-04-10
tags: [vim]
---

Ultisnips est capable de transformer ce que vous tapez en à peu près ce que vous
voulez. Un exemple.

# Ultisnips slugify

On souhaite ici taper un titre et générer un permalien à partir de ce titre.
Nous aurons besoin des modules `re` (généralement installé par défaut) et 
`unidecode` qu'on installera au besoin.

    $ pip install unidecode

Un slug est une chaine constituée des caractères de a à z et de 0 à 9
entrecoupés éventuellement du caractère `-`. Nous allons donc faire en sorte
que le titre que nous taperons soit directement transformé en slug sur la ligne
suivante.

Maintenant, ajoutons un nouveau snippet, par exemple au fichier `all.snippets`.

    global !p
    import re
    import unidecode
    def slugify(text):
        text = unidecode.unidecode(text).lower()
        return re.sub(r'\W+', '-', text)
    endglobal

    snippet slugtitle "Slugify title"
    title: ${1:Titre à slugifier}
    permalink: `!p snip.rv = slugify(t[1])`
    $0
    endsnippet
