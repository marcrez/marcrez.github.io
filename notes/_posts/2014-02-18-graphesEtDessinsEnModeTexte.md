---
title: Graphes et dessins en mode texte
layout: post
date: 2014-02-18
tags: [ascii, texte, markdown, pandoc]
category: notes
---

GraphViz (diminutif de Graph Visualization Software) est un
ensemble d'outils open source créés par les laboratoires de recherche d'AT&T
qui manipulent des graphes définis à l'aide de scripts suivant le langage DOT.
Cet ensemble fournit aussi des bibliothèques permettant l'intégration de ces
outils dans diverses applications logicielles.

Le langage ressemble à cela :

    digraph my_graph {
      GrandFather -> Father -> Son01;
      Father -> Son02;
    }

[](http://fr.wikipedia.org/wiki/DOT_(langage))


Il exite un visualiseur en ligne pour les scripts en langage dot :

[](http://rise4fun.com/agl)

Autre possibilité : utiliser plantuml qui sait lire le dot, mais aussi le ditaa
et sa propre syntaxe 

Pour essayer cela, rendez-vous sur http://www.plantuml.com/plantuml/form

Et saisir le code dot suivant : 
 
    @startdot
    digraph foo {
      node [style=rounded]
      node1 [shape=box]
      node2 [fillcolor=yellow, style="rounded,filled", shape=diamond]
      node3 [shape=record, label="{ a | b | c }"]
    
      node1 -> node2 -> node3
    }
    @enddot

Ou encore le code ditaa (généré par [](http://www.asciiflow.com/#Draw) )

    @startditaa
    +--------+   +-------+    +-------+
    |        +---+ ditaa +--> |       |
    |  Text  |   +-------+    |diagram|
    |Document|   |!magic!|    |       |
    |     {d}|   |       |    |       |
    +---+----+   +-------+    +-------+
        :                         ^
        |       Lots of work      |
        +-------------------------+
    @endditaa


Ou bien du code plantuml

    @startuml
    Alice -> Bob: Authentication Request
    Bob --> Alice: Authentication Response
    
    Alice -> Bob: Another authentication Request
    Alice <-- Bob: another authentication Response
    @enduml
