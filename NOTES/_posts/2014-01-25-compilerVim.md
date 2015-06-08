---
title: Compiler Vim avec le support python
layout: post
date: 2014-01-25
tags: [bash, vim]
category: notes
---

![Vim](https://lh5.googleusercontent.com/-xAo0F9DXVWM/UfRHNWSCtRI/AAAAAAAA0P8/U93jCkCFGGE/w469-h625/IMG_20130725_111424.jpg)

Sous Crunchbang `!#`, le support Python n'est pas activé dans la version
compilée de vim, comme on le voit ave le `-python` et `-python3` 

    $ vim --version | grep python
    +path_extra -perl +persistent_undo +postscript +printer +profile -python 
    -python3 +quickfix +reltime +rightleft -ruby +scrollbind +signs +smartindent 

Nous allons donc compiler vim depuis les sources

    $ sudo apt-get install python-dev
    $ sudo mv /usr/bin/vim /usr/bin/vimm
    $ git clone https://github.com/b4winckler/vim.git
    $ cd vim/src
    $ ./configure --enable-pythoninterp --with-python-config-dir=/usr/lib/python2.7/config
    $ make
    $ sudo make install

C'est terminé. Vérifions cela 

    $ vim --version |grep python
    +cryptv          +linebreak       +python          +viminfo
    -cscope          +lispindent      -python3         +vreplace



