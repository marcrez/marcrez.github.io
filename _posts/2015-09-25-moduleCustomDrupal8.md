---
title: Écrire un module pour Drupal8 
permalink: custom-module-Drupal8
layout: post
date: 2015-09-25 20:00:00
tags: [symfony]
category: symfony
---

Dans cet article, on va construire un module nommé ```basic```.

Pour cela, dans le dossier ```modules```, on crée un dossier ```basic```.
Dans ce nouveau dossier il faut au minimum trois fichiers :

- basic.info.yml
- basic.routing.yml
- src/BasicController.php

Le fichier ```basic.info.yml``` contient la déclaration du module

```yaml
name: Basic
type: module
description: 'Un module Basique...'
package: Custom
core: 8.x
```

Le fichier ```basic.routing.yml```  va donner les correspondances entre les url
et les contrôleurs qui entrent en action lors de la visite des pages

```yaml
basic.helloworld:
  path: '/helloWorld'
  defaults:
    _controller: '\Drupal\basic\SimpleController::hello'
  requirements:
    _access: 'TRUE'
```

Le fichier ```SimpleController``` placé dans le sous-dossier ```src``` de ```basic```
contient 


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
class simpleController extends ControllerBase {

  /**
   * Render a list of entries in the database.
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
