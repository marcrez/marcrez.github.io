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
![img]({{ site.baseurl }}/images/customModuleD8/d8.png)

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

Le fichier `basic.routing.yml`  va donner les correspondances entre les url
et les contrôleurs qui entrent en action lors de la visite des pages.
Ici, on définit une route nommée `basic.helloworld`. Elle donne à Drupal 
l'iformation suivante : déclencher la méthode `hello` de la classe 
`SimpleController` lors de la visite de la page 
http://monSiteDrupal.fr/helloWorld

```yaml
basic.helloworld:
  path: '/helloWorld'
  defaults:
    _controller: '\Drupal\basic\SimpleController::hello'
  requirements:
    _access: 'TRUE'
```

Le fichier `SimpleController.php` contient la classe et la méthode qui vont 
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
dans le fichier `modules/custom/basic/basic.module`

```php
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
```

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

## Un formulaire simple

Commençons par un formulaire inutile mais qui fonctionne : il se contente
d'afficher le contenu posté dans un bloc.

On a besoin d'un fichier `modules/custom/basic/src/MyForm.php`

```php
<?php

/**
 * @file
 * Contains \Drupal\basic\MyForm.
 */

namespace Drupal\basic;

use Drupal\Core\Form\FormBase;
use Drupal\Core\Form\FormStateInterface;

class MyForm extends FormBase {
  
  /**
   * {@inheritdoc}.
   */
  public function getFormId() {
    return 'my_form';
  }
  
 /**
   * {@inheritdoc}.
   */
  public function buildForm(array $form, FormStateInterface $form_state) {
    
    // Form constructor
    $form['name'] = array(
      '#type' => 'textfield',
      '#title' => t('Name'),
    );
    $form['email'] = array(
      '#type' => 'email',
      '#title' => $this->t('Email address.')
    );
    $form['show'] = array(
      '#type' => 'submit',
      '#value' => $this->t('Submit'),
    );
    
    return $form;
  }
  
  /**
   * {@inheritdoc}
   */
  public function validateForm(array &$form, FormStateInterface $form_state) {
  }
  
 /**
   * {@inheritdoc}
   */
  public function submitForm(array &$form, FormStateInterface $form_state) {
    
    drupal_set_message($this->t('Your email address is @email', array('@email' => $form_state->getValue('email'))));
  }
}
```

Afin que le formulaire sois accessible, il faut ajouter une route
dans le fichier `basic.routing.yml`

```yaml
basic.myform:
  path: '/myform'
  defaults:
    _form: '\Drupal\basic\MyForm'
    _title: 'Mon Formulaire'
  requirements:
    _permission: 'access basic pages'
```



## Une nouvelle table

Pour stocker des donnés personnalisées, par exemple les nom et
email envoyés par le formulaire précédent, nous allons créer une
nouvelle table. Pour cela, on implément le `hook_schema()`
dans le fichier `modules/custom/basic/basic.install`

```php
<?php
/**
 * @file
 * Install, update and uninstall functions for the basic module.
 */

/**
 * Implements hook_schema().
 *
 * Defines the database tables used by this module.
 *
 */
function basic_schema() {
  $schema['basic'] = array(
    'description' => 'Stores example person entries for demonstration purposes.',
    'fields' => array(
      'pid' => array(
        'type' => 'serial',
        'not null' => TRUE,
        'description' => 'Primary Key: Unique person ID.',
      ),
      'name' => array(
        'type' => 'varchar',
        'length' => 255,
        'not null' => TRUE,
        'default' => '',
        'description' => 'Name of the person.',
      ),
      'email' => array(
        'type' => 'varchar',
        'length' => 255,
        'not null' => TRUE,
        'default' => '',
        'description' => 'Email of the person.',
      ),
    ),
    'primary key' => array('pid'),
    'indexes' => array(
      'name' => array('name'),
      'email' => array('email'),
    ),
  );

  return $schema;
}
```

On peut ajouter au fichier `basic.install` quelques valeurs
pour pré-peupler la table avec le `hook_install()`


```php
<?php

/**
 * Implements hook_install().
 *
 * Creates some default entries on this module custom table.
 */
function basic_install() {
  // Add a default entry.
  $fields = array(
    'name' => 'Bill',
    'email' => 'bill@yahoo.com',
  );
  db_insert('basic')
      ->fields($fields)
      ->execute();

  // Add another entry.
  $fields = array(
    'name' => 'John',
    'email' => 'john@gmail.com',
  );
  db_insert('basic')
      ->fields($fields)
      ->execute();
}
```

## Travailler avec les données de la nouvelle table

Pour accéder aux données de la table, nous créons maintenant
un contrôleur CRUD (Create, Read, Update, Delete) générique :
`modules/custom/basic/src/CrudController.php`
Les méthodes définies seront utilisées dans un autre contrôleur qui se chargera
de préparer les données pour l'affichage :
`modules/custom/src/BasicDBController.php`

Afin de bien comprendre comment cela fonctione , limitons-nous à l'opération de
lecture (le R de CRUD)

Voici `CrudController.php`

```php
<?php

/**
 * @file
 * Contains \Drupal\basic\CrudController
 */

namespace Drupal\basic;

class CrudController {

  /**
   * READ from the database using a filter array.
   *
   * @param array $entry
   *   An array containing all the fields used to search the entries in the
   *   table.
   *
   * @return object
   *   An object containing the loaded entries if found.
   */
  public static function load($entry = array()) {
    // the following is for "SELECT * FROM basic AS b"
    $select = db_select('basic', 'b');
    $select->fields('b');

    // Add each field and value as a condition to this query.
    foreach ($entry as $field => $value) {
      $select->condition($field, $value);
    }
    // Return the result in object format.
    return $select->execute()->fetchAll();
  }
}
```

Voici `BasicDBController.php`

```php
<?php

/**
 * @file
 * Contains \Drupal\basic\BasicDBController
 */

namespace Drupal\basic;

use Drupal\Core\Controller\ControllerBase;

/**
 * Controller for basic table operations
 */
class BasicDBController extends ControllerBase {

  /**
   * Render a list of entries in the database.
   */
  public function entryList() {
    $content = array();

    $content['message'] = array(
      '#markup' => $this->t('Generate a list of all entries in the database. There is no filter in the query.'),
    );

    $rows = array();
    $headers = array(t('Id'), t('Name'), t('Email'));

    foreach ($entries = CrudController::load() as $entry) {
      // Sanitize each entry.
      $rows[] = array_map('Drupal\Component\Utility\SafeMarkup::checkPlain', (array) $entry);
    }

    $content['table'] = array(
      '#type' => 'table',
      '#header' => $headers,
      '#rows' => $rows,
      '#empty' => t('No entries available.'),
    );
    // Don't cache this page.
    $content['#cache']['max-age'] = 0;

    return $content;
  }
}
```

Pour afficher la page, il faudra bien sûr ajouter une route dans le fichier
`basic.routing.yml`

```yaml
basic.list: 
  path: '/list'
  defaults:
    _title: 'List'
    _controller: '\Drupal\basic\BasicDBController::entryList'
  requirements:
    _access: 'TRUE'
```






```php
<?php

/**
 * @file
 * Contains \Drupal\basic\BasicCRUD
 */

namespace Drupal\basic;

class BasicCRUD {

  /**
   * CREATE a new entry in the database.
   *
   * @param array $entry
   *   An array containing all the fields of the database record.
   *
   * @return int
   *   The number of updated rows.
   *
   * @throws \Exception
   *   When the database insert fails.
   */
  public static function insert($entry) {
    $return_value = NULL;
    try {
      $return_value = db_insert('basic')
          ->fields($entry)
          ->execute();
    }
    catch (\Exception $e) {
      drupal_set_message(t('db_insert failed. Message = %message, query= %query', array(
            '%message' => $e->getMessage(),
            '%query' => $e->query_string,
          )), 'error');
    }
    return $return_value;
  }

  /**
   * READ from the database using a filter array.
   *
   * @param array $entry
   *   An array containing all the fields used to search the entries in the
   *   table.
   *
   * @return object
   *   An object containing the loaded entries if found.
   */
  public static function load($entry = array()) {
    // the following is for "SELECT * FROM basic AS b"
    $select = db_select('basic', 'b');
    $select->fields('b');

    // Add each field and value as a condition to this query.
    foreach ($entry as $field => $value) {
      $select->condition($field, $value);
    }
    // Return the result in object format.
    return $select->execute()->fetchAll();
  }

  /**
   * UPDATE an entry in the database.
   *
   * @param array $entry
   *   An array containing all the fields of the item to be updated.
   *
   * @return int
   *   The number of updated rows.
   */
  public static function update($entry) {
    try {
      // db_update()...->execute() returns the number of rows updated.
      $count = db_update('basic')
          ->fields($entry)
          ->condition('pid', $entry['pid'])
          ->execute();
    }
    catch (\Exception $e) {
      drupal_set_message(t('db_update failed. Message = %message, query= %query', array(
            '%message' => $e->getMessage(),
            '%query' => $e->query_string,
          )), 'error');
    }
    return $count;
  }

  /**
   * DELETE an entry from the database.
   *
   * @param array $entry
   *   An array containing at least the person identifier 'pid' element of the
   *   entry to delete.
   */
  public static function delete($entry) {
    db_delete('basic')
        ->condition('pid', $entry['pid'])
        ->execute();
  }
}



