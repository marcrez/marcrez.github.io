---
title: Écrire un module pour Drupal8 
permalink: custom-module-Drupal8
layout: post
date: 2015-09-25 20:00:00
tags: [symfony]
category: symfony
---

Dans cet article, on va construire un module nommé **basic**.
Pour cela, dans le dossier ```modules``` il va falloir au minimum trois fichiers
dans des sous-dossiers qu'il faudra éventuellement créer :

- ```modules/custom/basic/basic.info.yml```
- ```modules/custom/basic/basic.routing.yml```
- ```modules/custom/basic/src/SimpleController.php```

Le fichier ```basic.info.yml``` contient la déclaration du module. Notons que le
type est obligatiore (ce pourrait être un thème par exemple) et que le package
désigne le groupe auquel ce module appartient (le fait qu'on se soit placé dans 
```modules/custom``` permet d'être cohérent même si ce n'est pas obligatoire).


```yaml
name: Basic
type: module
description: 'Un module Basique...'
package: Custom
core: 8.x
```

Le fichier ```basic.routing.yml```  va donner les correspondances entre les url
et les contrôleurs qui entrent en action lors de la visite des pages.
Ici, on définit une route nommée ```basic.helloworld```. Elle donne à Drupal 
l'iformation suivante : déclencher la méthode ```hello``` de la classe 
```SimpleController``` lors de la visite de la page 
http://monSiteDrupal.fr/helloWorld

```yaml
basic.helloworld:
  path: '/helloWorld'
  defaults:
    _controller: '\Drupal\basic\SimpleController::hello'
  requirements:
    _access: 'TRUE'
```

Le fichier ```SimpleController.php``` contient la classe et la méthode qui vont 
afficher le message classique.

```php
<?php

/**
 * @file
 * Contains \Drupal\basic\SimpleController.
 */

namespace Drupal\basic;

use Drupal\Core\Controller\ControllerBase;

/**
 * Controller for simple action.
 */
class SimpleController extends ControllerBase {

  /**
   * Render a famous sentence.
   */
  public function hello() {
    return array(
        '#type' => 'markup',
        '#markup' => t('Hello, World!'),
    );
  }
}
```


...
