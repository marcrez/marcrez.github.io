---
title: Écrire un module pour Drupal8 
permalink: custom-module-Drupal8
layout: post
date: 2015-09-25 20:00:00
tags: [symfony]
category: symfony
---

Dans cet article, on va construire un module nommé **basic**.
Cela se fera en plusieurs étapes du plus simple au plus complet.

## Un module qui affiche le Hello, World !


Pour cela, dans le dossier `modules` il va falloir au minimum trois fichiers
dans des sous-dossiers qu'il faudra éventuellement créer :

- `modules/custom/basic/basic.info.yml`
- `modules/custom/basic/basic.routing.yml`
- `modules/custom/basic/src/SimpleController.php`

Le fichier `basic.info.yml` contient la déclaration du module. Notons que le
type est obligatiore (ce pourrait être un thème par exemple) et que le package
désigne le groupe auquel ce module appartient (le fait qu'on se soit placé dans 
`modules/custom` permet d'être cohérent même si ce n'est pas obligatoire).


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

## Un module avec une aide

Afin de fournir une aide au module, on va ajouter le `hook_help()` 
dans le fichier `modules/custom/basic/basic.module.php`

<?php
use Drupal\Core\Routing\RouteMatchInterface;

/**
 * Implements hook_help().
 */
function basic_help($route_name, RouteMatchInterface $route_match) {
  switch ($route_name) {
    case 'help.page.basic':
      return t('
        <h2>Module Basique pour Drupal8.</h2>
        <h3>Instructions</h3>
        <p>Visitez la page helloWorld pour vérifier que tout fonctionne</p>
      ');
  }
}

## De nouveaux droits associés au module

Pour créer de nouveaux droits, c'est simple, il suffit de les déclarer
dans le fichier `modules/custom/basic/basic.permissions.yml`

```yaml
access basic pages:
  title: 'Accès aux pages du module basic'
admin basic module:
  title: 'Administrer le module basic (dangereux)'
```

On pourra alors limiter l'accès à la page affichant le *Hello, World !*
en modifiant le fichier `modules/custom/basic/basic.routing.yml`

```yaml
basic.helloworld:
  path: '/helloWorld'
  defaults:
    _controller: '\Drupal\basic\SimpleController::hello'
  requirements:
    #_access: 'TRUE' ## remplacé par la ligne suivante
    _permission: 'access basic pages'
```

