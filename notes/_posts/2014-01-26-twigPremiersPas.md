---
title: Twig  Premiers pas
layout: post
date: 2014-01-26
tags: [symfony, web, twig]
category: notes
---

![Twig](http://creativeproject.files.wordpress.com/2013/11/twig.jpg?w=580)

Dans ce tuto, on travaille sur un projet qui predra place dans le répertoire `~/nico/htdocs/projet/`

Première étape, installer Twig à partir de l'archive 

~~~bash
    $ cd ~/nico/htdocs/projet/
    $ wget https://github.com/fabpot/Twig/archive/v1.15.0.tar.gz
    $ tar zxf Twig-1.15.0.tar.gz 
~~~

Seul le répertoire `lib` nous intéresse

~~~bash
    $ mkdir ~/nico/htdocs/projet/twig
    $ mv Twig-1.15.0/lib/ twig/
    $ rm -r Twig-1.15.0*
~~~

Un dossier pour les templates sera utile

~~~bash
    $ mkdir ~/nico/htdocs/projet/templates
~~~

Dans le dossier templates, on crée un fichier `base.tpl`

~~~html
    <html>
     <body>
      <h1> My Name is {{ name }} </h1>
      <p> And I feel {{ mood }} </p>
     </body>
    </html>
~~~

Dans notre dossier de travail, on crée maintenant un fichier `index.php`

~~~php
    <?php
    include_once('twig/lib/Twig/Autoloader.php');
    Twig_Autoloader::register();
    
    $loader = new Twig_Loader_Filesystem('templates');
    $twig = new Twig_Environment($loader, array(
        'cache' => false
    ));
    
    echo $twig->render('index.html',
        array(
            'name' => 'Winston',
            'mood' => 'sooooo happy ! ;)',
        ));
    ?>
~~~

Voilà ! Il ne reste plus qu'à faire pointer le navigateur sur le dossier 
`projet` pour voir Twig lancer la magie.





