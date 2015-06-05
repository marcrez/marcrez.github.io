---
title: Symfony notes en cours de rédaction
layout: post
date: 2014-01-26
tags: [symfony, web, twig]
category: notes
---

Symfony est un framework MVC libre écrit en PHP 5 destiné
majoritairement aux professionnels du développement. Il fournit des
fonctionnalités modulables et adaptables qui permettent de faciliter
et d’accélérer le développement d'un site web.


<!-- *Commande pour générer le pdf*
file=symfony2_intro \
&& pandoc --toc --number-sections --smart --highlight-style=pygments \
          --template ../../pandocUtils/templates/pandoc_template.tex \
   $file.md -o $file.pdf \
&& evince $file.pdf
-->
<!-- *Commande pour générer le html*
file=symfony2_intro \
&& pandoc --toc --number-sections --smart --highlight-style=pygments \
       -s --css ../pandocUtils/templates/buttondown.css \
   $file.md -o $file.html
-->


# Installation de symfony2

Pour installer symfony, nous utiliserons composer, le système de package
PHP.

![Composer]({{ site.baseurl }}/images/symfony2_intro/Composer.jpg)

> *Composer is a tool for dependency management in PHP. It allows you to
> declare the dependent libraries your project needs and it will install
> them in your project for you.*

Dans le dossier `htdocs` servi par apache, on récupère composer puis
on lui demande d'installer symfony version 2.3 dans un répertoire nommé
`sf1`

~~~~~~~~~~~~~~ {.email}
  ~/htdocs# curl -s https://getcomposer.org/installer | php
  ~/htdocs# php composer.phar create-project symfony/framework-standard-edition sf1 "2.3.x"
~~~~~~~~~~~~~~

Les lignes qui s'affichent alors sont explicites: d'abord composer
installe symfony dans sa version 2.3.23
puis tour à tour les bibliothèques tierces.

Viennent enfin quelques questions concernant la configuration.

~~~~~~~~~~~~~~ {.email}
  Installing symfony/framework-standard-edition (v2.3.23)
    - Installing symfony/framework-standard-edition (v2.3.23)
      Loading from cache
  created project in sf4
  Loading composer repositories with package information
  Installing dependencies (including require-dev) from lock file
  - Installing doctrine/lexer (v1.0.1)
    Loading from cache

  - Installing doctrine/annotations (v1.2.3)
    Loading from cache

  - Installing twig/twig (v1.18.0)
    Loading from cache
  ...      

  Some parameters are missing. Please provide them.
  database_driver (pdo_mysql):     
  database_host (127.0.0.1): 
  database_port (null): 
  database_name (symfony): sf1
  database_user (root): 
  database_password (null): motDePasseBdd
  mailer_transport (smtp): 
  mailer_host (127.0.0.1): 
  mailer_user (null): 
  mailer_password (null): 
  locale (en): fr
  secret (ThisTokenIsNotSoSecretChangeIt): passw
~~~~~~~~~~~~~~


> NOTE: Il peut arriver que des erreurs se produisent lors du téléchargement
> des bibliothèques externes (vendor). Dans ce cas, on relance l'installation.
>
>~~~~~~~~~~~~~~ {.email}
>   ~/htdocs# cd sf1
>   ~/htdocs/sf1# php ../composer.phar install
>~~~~~~~~~~~~~~

Nous avons maintenant un projet Symfony entièrement fonctionnel :

~~~~~~~~~~~~~~ {.email}
  ~/htdocs/sf1# tree -L 1
  |-- composer.json, composer.lock, LICENSE, README...
  |-- app/                        /* l'essentiel de symfony */
  |-- src/                        /* le code des bundles du projet */
  |-- vendor/                     /* les bibliothèques tierces */
  !-- web/                        /* fichiers publics et contrôleurs frontaux */
~~~~~~~~~~~~~~

Premier test : <http://localhost/sf1/web/config.php>. Des problèmes
de permission sont détéctés, nous les réglons avant de recharger la page.

~~~~~~~~~~~~~~ {.email}
  ~/htdocs/sf1# chmod -R 777 app/cache/ app/logs/
~~~~~~~~~~~~~~

# Un bundle de base

## Création du bundle

Le but : créer un mini blog. Avec des utilisateurs qui rédigent des posts.

Première étape : créer un bundle

~~~~~~~~~~~~~~ {.email}
  ~/htdocs/sf1# php app/console generate:bundle --namespace=Nico/BlogBundle --format=yml
~~~~~~~~~~~~~~

(on répondra no à `Do you want to generate the whole directory structure`)

Nous disposons de l'arborescence pour travailler

~~~~~~~~~~~~~~ {.email}
    ~/htdocs/sf1# tree -L 4 src/Nico/BlogBundle/
    |-- Controller
    |   !-- DefaultController.php
    |-- DependencyInjection
    |   |-- Configuration.php
    |   !-- NicoBlogExtension.php
    |-- NicoBlogBundle.php
    |-- Resources
    |   |-- config
    |   |   |-- routing.yml
    |   |   !-- services.yml
    |   !-- views
    |       !-- Default
    |           !-- index.html.twig
    !-- Tests
        !-- Controller
                !-- DefaultControllerTest.php
~~~~~~~~~~~~~~

Non seulement on a créé une arborescence mais

1.  le bundle a été automatiquement enregistré
    dans le noyau avec la ligne

    ~~~~~~~~~~~~~~ {.php}
      <?php //app/AppKernel.php
          $bundles = array(
              ...
              new Nico\BlogBundle\NicoBlogBundle(),
    ~~~~~~~~~~~~~~

2.  le contrôleur `Default` dont l'action `index` est appelée pour la route
    `nico_blog_homepage` a bien été créé

    ~~~~~~~~~~~~~~ {.php}
      <?php //src/Nico/BlogBundle/Controller/DefaultController.php
      namespace Nico\BlogBundle\Controller;

      use Symfony\Bundle\FrameworkBundle\Controller\Controller;

      class DefaultController extends Controller
      {
          public function indexAction($name)
          {
              return $this->render('NicoBlogBundle:Default:index.html.twig', array('name' => $name));
          }
      }
    ~~~~~~~~~~~~~~

3.  le template par défaut du bundle a été créé

    ~~~~~~~~~~~~~~ {.html}
      <!-- src/Nico/BlogBundle/Resources/views/Default/index.html.twig -->
      Hello {{ name }}!
    ~~~~~~~~~~~~~~

4.  le routage du bundle a été automatiquement importé
    dans le fichier de routage principal

    ~~~~~~~~~~~~~~ {.yaml}
      # app/config/routing.yml
      nico_blog:
          resource: "@NicoBlogBundle/Resources/config/routing.yml"
          prefix: /
    ~~~~~~~~~~~~~~

    Avec un fichier de routes par défaut

    ~~~~~~~~~~~~~~ {.yaml}
      # src/Nico/BlogBundle/Resources/config/routing.yml
      nico_blog_homepage:
          path:     /hello/{name}
          defaults: { _controller: NicoBlogBundle:Default:index }
    ~~~~~~~~~~~~~~

    On peut voir tout cela fonctionner <http://localhost/sf1/web/app_dev.php/hello/Tartempion>

## Routage et contrôleurs

Une route est une correspondance entre une URL (ou un pattern d'URL) et un
contrôleur.  Le but est de bien séparer URLS des actions qui vont générer les
réponses.  En vocabulaire symfony: séparer les routes des contrôleurs.

1. Le routeur trouve une route correpondant au chemin (`path`), et détermine le
   contrôleur (`_controller`)
2. Le contrôleur (une méthode dont le nom se termine par `Action`) 
   prend les informations de la requête HTTP, construit puis
   retourne une réponse HTTP. Les contrôleurs sont regroupés ensemble
   au sein d'une classe (dont le nom se termine par `Controller`)

Concrètement, si on souhaite accéder aux profils des membres via les URL
`/member/Joe` ou `/member/Bill`, on va faire en sorte que dans un bundle
(disons `Acme/UserBundle`) le pattern d'URL `/member/{user_name}` pointe vers
une classe (disons `MemberController`) et une méthode (disons `showAction`) qui
va gérer la requête en lisant la variable `user_name` pour renvoyer une réponse
avec le résultat attendu : le profil du membre.

Le fichier de route

~~~~~~~~~~~~~~ {.yaml}
  # src/Acme/UserBundle/Resources/config/routing.yml
  member_show:
      path:   /member/{user_name}
      defaults:  { _controller: AcmeUserBundle:Member:show }
~~~~~~~~~~~~~~

Le contrôleur

~~~~~~~~~~~~~~ {.php}
  <?php //src/Acme/UserBundle/Controller/MemberController.php
  namespace Acme\UserBundle\Controller;

  use Symfony\Bundle\FrameworkBundle\Controller\Controller;

  class MemberController extends Controller
  {
      public function showAction($user_name)
      {
          $nom    = // utilisez la variable $user_name pour interroger la base de données
          $prenom = // utilisez la variable $user_name pour interroger la base de données

          return $this->render('AcmeUserBundle:Member:show.html.twig', array(
              'user_name' => $user_name, 'nom' => $nom, 'prenom' => $prenom,
          ));
      }
  }
~~~~~~~~~~~~~~

## Contrôleurs et templates

En continuant sur l'exemple précédent, notre template de page ressemble à ceci

~~~~~~~~~~~~~~ {.html}
  <!-- src/Acme/UserBundle/Resources/views/Member/show.html.twig -->
  {% extends 'AcmeUserBundle::layout.html.twig' %}

  {% block content %}
      <h2>Membre {{ user_name }}</h2>
      <ul>
        <li> Nom : {{ nom }}</li>
        <li> Prénom : {{ prenom }}</li>
      </ul>
  {% endblock %}
~~~~~~~~~~~~~~

il étend le fichier layout du bundle `AcmeUserBundle::layout.html.twig`

~~~~~~~~~~~~~~ {.html}
  <!-- src/Acme/UserBundle/Resources/views/layout.html.twig -->
  {% extends '::base.html.twig' %}

  {% block body %}
      <h1>Blog Application</h1>
      {% block content %}{% endblock %}
  {% endblock %}
~~~~~~~~~~~~~~

qui lui-même étend le fichier layout principal `::base.html.twig`

~~~~~~~~~~~~~~ {.html}
  <!-- app/Resources/views/base.html.twig -->
  <!DOCTYPE html>
  <html>
      <head>
          <meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
          <title>{% block title %}Test Application{% endblock %}</title>
      </head>
      <body>
          <div id="sidebar">
              {% block sidebar %}
              <ul>
                  <li><a href="/">Home</a></li>
                  <li><a href="/blog">Blog</a></li>
              </ul>
              {% endblock %}
          </div>

          <div id="content">
              {% block body %}{% endblock %}
          </div>
      </body>
  </html>
~~~~~~~~~~~~~~

En résumé le fonctionnement est le suivant

    +---------------------------+ --------------------- ::base.html.twig
    |   Test Application        |
    |      +-------------------+| ----- AcmeUserBundle::layout.html.twig
    |      | Blog Application  ||
    |-Home |+-----------------+|| - AcmeUserBundle:Member:show.html.twig
    |-Blog || Membre Joe      |||
    |      || - Nom : Dalton  |||
    |      || - Prénom : José |||
    |      |+-----------------+||
    |      +-------------------+|
    +---------------------------+

# Des entités pour gérer la Base de données

## Configurer l'accès et créer la base de données

Si les paramètres sont correctement renseignés dans le fichier
`app/config/parameters.yml` Symfony peut créer la BDD puis le répertoire qui va
recevoir les descriptions des tables

~~~~~~~~~~~~~~ {.email}
  ~/htdocs/sf1# php app/console doctrine:database:create
~~~~~~~~~~~~~~

## Schéma

Voici le schéma de notre base de données

               +-------------------------------------------------------+
               |                                                       |
    +---------------------+     +--------+                        +----------+
    |user provided by FOS |-----|quark   |------------------------|category  |
    +---------------------+     +--------+           |            +----------+
    |id                   |     |id      |           |            |id        |
    |...                  |     |content |    +------+-------+    |name      |
    +---------------------+     |parent  |    |quark_category|    |user_id   |
                                |user_id |    +--------------+    |created_at|
                                |created |    |quark_id      |    |updated_at|
                                |updated |    |category_id   |    +----------+
                                +--------+    +--------------+

## Utiliser le générateur d'entité Doctrine

La commande est la suivante

~~~~~~~~~~~~~~ {.email}
  ~/htdocs/sf1# php app/console generate:doctrine:entity
~~~~~~~~~~~~~~

Il est demandé de renseigner le nom de l'entité sous la forme 
`AcmeBlogBundle:Post`.
Ensuite, on donne le format de *mapping* qui va définir l'entité.

~~~~~~~~~~~~~~ {.email}
  The Entity shortcut name: NicoBlogBundle:Quark
  Configuration format (yml, xml, php, or annotation) [annotation]: annotation
~~~~~~~~~~~~~~

Ensuite, on défnit les champs de l'entité (Noter : la clé
primaire `id` est automatiquement ajoutée).

~~~~~~~~~~~~~~ {.email}
  Available types: array, simple_array, json_array, object, 
  boolean, integer, smallint, bigint, string, text, datetime, datetimetz, 
  date, time, decimal, float, blob, guid.

  New field name (press <return> to stop adding fields): content
  Field type [string]: text

  New field name (press <return> to stop adding fields): created
  Field type [string]: datetime
~~~~~~~~~~~~~~

L'entité est créée mais on va effectuer quelques modifications

- Le mot `quark` dans les commentaires sur la classe `Quark` lève une exception.
  On le supprime.
- Plutôt que de laisser doctrine créer la table en utilisant le nom de l'entité
 `Quark` (avec une majuscule), on précise le nom de la table pour se conformer
  aux bonnes pratiques MySQL.
- L'annotation `@var` est un commentaire phpdoc inutile pour Doctrine. On peut
  supprimer.
- L'attribut `id` est par défaut un entier. On va choisir 
  d'utiliser un UUID (*Universal Unique Identifier*) pour identifier les quarks
- Afin d'automatiser la mise à jour des attributs de type `date` ou `datetime`
  on utilise l'extension Doctrine `Timestampable` disponible dans le bundle 
  StofDoctrineExtensionsBundle.

~~~~~~~~~~~~~~ {.php}
<?php src/Nico/BlogBundle/Entity/Quark.php

namespace Nico\BlogBundle\Entity;                   namespace Nico\BlogBundle\Entity;

use Doctrine\ORM\Mapping as ORM;                    use Doctrine\ORM\Mapping as ORM;
                                                    use Gedmo\Mapping\Annotation as Gedmo;
/**
 * Quark
 *                                                  /**
 * @ORM\Table()                                      * @ORM\Table(name="quark")
 * @ORM\Entity                                       * @ORM\Entity
 */                                                  */
class Quark                                         class Quark
{                                                   {
    /**
     * @var integer
     *                                                  /**
     * @ORM\Column(name="id", type="integer")            * @ORM\Column(name="id", type="guid")
     * @ORM\Id                                           * @ORM\Id
     * @ORM\GeneratedValue(strategy="AUTO")              * @ORM\GeneratedValue(strategy="UUID")
     */                                                  */
    private $id;                                        private $id;

    /**
     * @var string
     *                                                  /**
     * @ORM\Column(name="content", type="text")          * @ORM\Column(name="content", type="text")
     */                                                  */
    private $content;                                   private $content;

    /**
     * @var \DateTime                                   /**
     *                                                   * @Gedmo\Timestampable(on="create")
     * @ORM\Column(name="created", type="datetime")      * @ORM\Column(name="created", type="datetime")
     */                                                  */
    private $created;                                   private $created;

    //Les getters et les setters                        //Les getters et les setters
~~~~~~~~~~~~~~

On va maintenant créer la base de données
puis la table décrite par notre schéma.

~~~~~~~~~~~~~~ {.email}
  ~/htdocs/sf1# php app/console doctrine:database:create
  ~/htdocs/sf1# php app/console doctrine:schema:create
~~~~~~~~~~~~~~

> NOTE: 
> - la commande `doctrine:schema:create` accepte l'option `--dump-sql` pour 
>   vérifier avant de créer.
> - Pour modifier une table existante, on utilisera 
>  `doctrine:schema:update --force`





# autre méthode : yml

Un peu de documentation au sujet de la synatxe de mapping

-   <http://doctrine-orm.readthedocs.org/en/latest/reference/association-mapping.html>
-   <http://doctrine-orm.readthedocs.org/en/latest/reference/yaml-mapping.html>

Nous allons créer la description de notre entité en format YAML. pour cela il
faut créer un nouveau répertoire.

~~~~~~~~~~~~~~ {.email}
  ~/htdocs/sf1# mkdir src/Nico/BlogBundle/Resources/config/doctrine/
~~~~~~~~~~~~~~

Commençons par l'entité `Category`

~~~~~~~~~~~~~~ {.yaml}
  # MyBundle/Resources/config/doctrine/Category.orm.yml
  Nico\BlogBundle\Entity\Category:
    type: entity
    table: category
    id:
      id:
        type: integer
        generator: { strategy: AUTO }
    fields:
      name:
        type: string
      user_id:
        type: integer
      created_at:
        type: datetime
    lifecycleCallbacks:
      prePersist: [ doSetCreatedAtValue ]
~~~~~~~~~~~~~~

Ensuite l'entité `Quark`

~~~~~~~~~~~~~~ {.yaml}
  # MyBundle/Resources/config/doctrine/Quark.orm.yml
  Nico\BlogBundle\Entity\Quark:
    type: entity
    table: quark
    id:
      id:
        type: integer
        generator: { strategy: AUTO }
    fields:
      content:
        type: text
      categories_csv:
        type: string
      parent:
        type: integer
      user_id:
        type: integer
      created_at:
        type: datetime
      updated_at:
        type: datetime
        nullable: true
    manyToMany:
      groups:
        targetEntity: Category
        joinTable:
          name: quark_category
          joinColumns:
            quark_id:
              referencedColumnName: id
          inverseJoinColumns:
            category_id:
              referencedColumnName: id
    lifecycleCallbacks:
      prePersist: [ doSetCreatedAtValue ]
      preUpdate: [ doSetUpdatedAtValue ]
~~~~~~~~~~~~~~

On convertit maintenant ces blocs d'instruction YAML en classes php qui
seront stockées dans le dossier `MyBundle/Entity`

~~~~~~~~~~~~~~ {.email}
   ~/htdocs/sf1# php app/console doctrine:generate:entities NicoBlogBundle
~~~~~~~~~~~~~~

Les instructions `lifecycleCallbacks` vont créer des méthodes qui seront
déclenchées juste avant le persist ou l'update de données. Ces méthodes
seront vides par défaut, il nous faut donc les compléter manuellement.

documentation : <http://symfony.com/fr/doc/current/book/doctrine.html>

~~~~~~~~~~~~~~ {.php}
    <?php //src/Nico/BlogBundle/Entity/Category.php
    /**
     * @ORM\PrePersist
     */
    public function doSetCreatedAtValue()
    {
      if(!$this->getCreatedAt())
      {
        $this->created_at = new \DateTime();
      }
    }
~~~~~~~~~~~~~~

De même

~~~~~~~~~~~~~~ {.php}
    <?php //src/Nico/BlogBundle/Entity/Quark.php
    /**
     * @ORM\PreUpdate
     */
    public function doSetUpdatedAtValue()
    {
      if(!$this->getUpdatedAt())
      {
        $this->updated_at = new \DateTime();
      }
    }
~~~~~~~~~~~~~~

## Données de test avec Fixtures

Pour installer Fixtures ave composer, il faut l'ajouter
au fichier de configuration

~~~~~~~~~~~~~~ {.json}
  # composer.json
  {
      "require": {
          "doctrine/doctrine-fixtures-bundle": "2.2.*"
      }
  }
~~~~~~~~~~~~~~

Ensuite effectuer la mise à jour des librairies

~~~~~~~~~~~~~~ {.email}
  $ php composer.phar update doctrine/doctrine-fixtures-bundle
~~~~~~~~~~~~~~

Maintenant, on trouve `DoctrineFixturesBundle` dans `vendor/doctrine`.
Reste à inscrire `DoctrineFixturesBundle` dans le kernel

~~~~~~~~~~~~~~ {.php}
  <?php //app/kernel
  public function registerBundles()
  {
       $bundles = array(
            // ...
            new Doctrine\Bundle\FixturesBundle\DoctrineFixturesBundle(),
  }
~~~~~~~~~~~~~~

On peut maintenant créer un fichier de fixtures pour la classe `Category`

~~~~~~~~~~~~~~ {.php}
  <?php //src/Nico/BlogBundle/DataFixtures/ORM/LoadCategoryData.php
  namespace Nico\BlogBundle\DataFixtures\ORM;

  use Doctrine\Common\DataFixtures\FixtureInterface;
  use Doctrine\Common\Persistence\ObjectManager;
  use Nico\BlogBundle\Entity\Category;

  class LoadCategoryData implements FixtureInterface
  {
      /**
       *  {@inheritDoc}
       */
      public function load(ObjectManager $manager)
      {
          $category01 = new Category();
          $category01->setName('Mathématiques');
          $category01->setUserId(1);

          $category02 = new Category();
          $category02->setName('Chimie');
          $category02->setUserId(1);

          $manager->persist($category01);
          $manager->persist($category02);
          $manager->flush();
      }
  }
~~~~~~~~~~~~~~

Le code précédent fonctionne très bien mais il est insuffisant car il ne
permet pas de mettre en relation les quarks avec les catégories dans la
realtion many-to-many que nous avons définie. On modifie donc ainsi

~~~~~~~~~~~~~~ {.php}
  <?php //src/Nico/BlogBundle/DataFixtures/ORM/LoadCategoryData.php
  namespace Nico\BlogBundle\DataFixtures\ORM;

  use Doctrine\Common\DataFixtures\AbstractFixture;
  use Doctrine\Common\DataFixtures\OrderedFixtureInterface;
  use Doctrine\Common\Persistence\ObjectManager;
  use Nico\BlogBundle\Entity\Category;

  class LoadQuarkData extends AbstractFixture implements OrderedFixtureInterface
  {
      /**
       *  {@inheritDoc}
       */
      public function load(ObjectManager $manager)
      {
          $category01 = new Category();
          $category01->setName('Mathématiques');
          $category01->setUserId(1);

          $category02 = new Category();
          $category02->setName('Chimie');
          $category02->setUserId(1);

          $manager->persist($category01);
          $manager->persist($category02);
          $manager->flush();

          $this->addReference('category-maths'  , $category01);
          $this->addReference('category-chimie' , $category02);
      }
      public function getOrder() {
        return 0; // Load before quarks
      }
  }
~~~~~~~~~~~~~~

On a ainsi crée deux nouvelles références qui pourront être ajoutées au quark
afin de le lier aux catégories. Pour cela il est nécessaire que fixture traite
d'abord les catégories avant les quarks, c'est pour cela qu'on a ajouté la
fonction `getOrder`.

~~~~~~~~~~~~~~ {.php}
  <?php //src/Nico/BlogBundle/DataFixtures/ORM/LoadQuarkData.php
  namespace Nico\BlogBundle\DataFixtures\ORM;

  use Doctrine\Common\DataFixtures\AbstractFixture;
  use Doctrine\Common\DataFixtures\OrderedFixtureInterface;
  use Doctrine\Common\Persistence\ObjectManager;
  use Nico\BlogBundle\Entity\Quark;

  class LoadQuarkData extends AbstractFixture implements OrderedFixtureInterface
  {
      /**
       *  {@inheritDoc}
       */
      public function load(ObjectManager $manager)
      {
          $quark01 = new Quark();
          $quark01->setContent('Un exo de Mathématiques');
          $quark01->setParent(0);
          $quark01->setcategoriesCsv("math");
          $quark01->setUserId(1);
          $quark01->addGroup($this->getReference('category-maths'));

          $manager->persist($quark01);
          $manager->flush();

      }

      /**
       *  {@inheritDoc}
       */
      public function getOrder() {
        return 1; // Load after categories
      }
  }
~~~~~~~~~~~~~~

Maintenant on insère les données en base de données, on pourra ensuite
contater que les données ont bien été entrées et dans l'ordre.

~~~~~~~~~~~~~~ {.email}
  $ php app/console doctrine:fixtures:load
  Careful, database will be purged. Do you want to continue Y/N ?y
  > purging database
  > loading [0] Nico\BlogBundle\DataFixtures\ORM\LoadCategoryData
  > loading [1] Nico\BlogBundle\DataFixtures\ORM\LoadQuarkData
~~~~~~~~~~~~~~


# FOSUserBundle

## Installer et déclarer

Pour gérer les opérations de connexion d'utilisateurs, il exite un bundle prêt
à l'emploi : FOSUser bundle. Installer FOSUserBundle est simple avec composer.
Il suffit d'ajouter une ligne de dépendance au fichier `composer.json`

~~~~~~~~~~~~~~ {.json}
  // composer.json
  ...
  "require": {
  ...
      "friendsofsymfony/user-bundle": "dev-master"
~~~~~~~~~~~~~~

puis de lancer composer qui va se charger de l'installation

~~~~~~~~~~~~~~ {.email}
  $ php composer.phar update
~~~~~~~~~~~~~~

Nous allons avoir besoin d'un nouveau bundle qui va s'appuyer sur
FOSUserBundle. Créons-le, il va se nommer `Nico/UserBundle`

~~~~~~~~~~~~~~ {.email}
  $ mkdir src/Nico/UserBundle/
~~~~~~~~~~~~~~

> NOTE: On aurait pu utiliser le générateur mais il crée des
> répertoires qui ne nous seront pas utiles
>
>~~~~~~~~~~~~~~ {.email}
>  $ php app/console generate:bundle --namespace=Nico/UserBundle --format=yml
>~~~~~~~~~~~~~~

On crée la classe de notre bundle

~~~~~~~~~~~~~~ {.php}
  <?php //src/Nico/UserBundle/NicoUserBundle.php 
  namespace Nico\UserBundle;

  use Symfony\Component\HttpKernel\Bundle\Bundle;

  class NicoUserBundle extends Bundle
  {
    public function getParent()
    {
      return 'FOSUserBundle';
    }
  }
~~~~~~~~~~~~~~

Il ne manque plus que deux lignes dans le kernel pour déclarer
`FOSUserBundle` et notre `UserBundle`

~~~~~~~~~~~~~~ {.php}
  <?php //app/AppKernel.php
      new FOS\UserBundle\FOSUserBundle(),
      new Nico\UserBundle\NicoUserBundle(),
~~~~~~~~~~~~~~

## Générer l'entité User

Dans notre nouveau bundle, nous allons utiliser la puissance de
`FOSUserBundle` pour générer en quelques lignes une entité `User.php` qui
hérite de la *mapped superclass* `BaseUser` de FOSUserBundle

~~~~~~~~~~~~~~ {.php}
    <?php //src/Nico/UserBundle/Entity/User.php
    namespace Nico\UserBundle\Entity;  # Doit correpondre au bundle

    use FOS\UserBundle\Model\User as BaseUser;
    use Doctrine\ORM\Mapping as ORM;

    /**
     * @ORM\Entity
     * @ORM\Table(name="fos_user")     # Ce sera le nom de la table en BDD
     */
    class User extends BaseUser
    {
        /**
         * @ORM\Id
         * @ORM\Column(type="integer")
         * @ORM\GeneratedValue(strategy="AUTO")
         */
        protected $id;

        public function __construct()
        {
            parent::__construct();
            // your own logic
        }
    }
~~~~~~~~~~~~~~

Avant de demander la création de la table en BDD, il faut renseigner
quelques paramètres

~~~~~~~~~~~~~~ {.yaml}
  # app/config/config.yaml

  # FOSUserBundle configuration
  fos_user:
      db_driver: orm        # Le type de Bdd
      firewall_name: main   # le firewall spécifié dans app/config/security.yml
      user_class: Nico\UserBundle\Entity\User # la classe de l'entité User
~~~~~~~~~~~~~~

Vérifions que les choses vont bien se passer au moment de la mise à jour
de la base de données

~~~~~~~~~~~~~~ {.email}
  $ app/console doctrine:schema:update --dump-sql
~~~~~~~~~~~~~~

On peut maintenant mettre à jour la BDD

~~~~~~~~~~~~~~ {.email}
  $ app/console doctrine:schema:update --force
~~~~~~~~~~~~~~

## Configurer la sécurité

dans symfony, la sécurité se gère en deux étapes

-   Le *firewall* qui s'occupe de la partie authentification c'est à
    dire qui vérifie si vous devez être idenfié ou si les anonymes sont
    autorisés à accéder à la ressource. Notre provider sera
    FosUserBundle pour nous mais cela pourrait être via Facebook, Google
    ou openID
-   L'*access control* qui s'occupe de vérifier qu'avec votre identité,
    vous avez les droits suffisants pour accéder aux ressources que vous
    demandez.

On configure tout cela, dans le fichier `security.yaml`

~~~~~~~~~~~~~~ {.yaml}
  # app/config/security.yml
  security:
      encoders:
          #Symfony\Component\Security\Core\User\User: plaintext
          FOS\UserBundle\Model\UserInterface: sha512

      role_hierarchy:
          ROLE_ADMIN:       ROLE_USER
          ROLE_SUPER_ADMIN: ROLE_ADMIN

      providers:
          fos_userbundle:
              id: fos_user.user_provider.username

      firewalls:
          main:
              pattern: ^/  # Tout le site est desrrière le pare-feu
              form_login:
                  provider: fos_userbundle
                  csrf_provider: form.csrf_provider
              logout:       true
              anonymous:    true    # Anonymes acceptés

      access_control:
          - { path: ^/login$, role: IS_AUTHENTICATED_ANONYMOUSLY }
          - { path: ^/register, role: IS_AUTHENTICATED_ANONYMOUSLY }
          - { path: ^/resetting, role: IS_AUTHENTICATED_ANONYMOUSLY }
          - { path: ^/admin/, role: ROLE_ADMIN }
~~~~~~~~~~~~~~

FOSUserBundle fournit des routes et des contrôleurs prêts à l'emploi
pour toutes les opérations sur la sécurité. Profitons-en en les
important grâce à une nouvelle ligne dans le fichier des routes

~~~~~~~~~~~~~~ {.yaml}
    # app/config/routing.yml
    fos_user:
        resource: "@FOSUserBundle/Resources/config/routing/all.xml"
~~~~~~~~~~~~~~

C'est terminé. On vérifie que les routes fonctionnent avec la commande
suivante qui fait apparaître toutes les routes `fos_user_*`

~~~~~~~~~~~~~~ {.email}
  $ app/console router:debug
~~~~~~~~~~~~~~

Nous allons maintenant créer un utilisateur puis lui attribuer un rôle

~~~~~~~~~~~~~~ {.email}
  $ app/console fos:user:create
  Please choose a username:nico
  Please choose an email:nico@nico.fr
  Please choose a password:
  Created user nico
 
  $ app/console fos:user:promote
  Please choose a username:nico
  Please choose a role:ROLE_ADMIN
  Role "ROLE_ADMIN" has been added to user "nico".
~~~~~~~~~~~~~~

## Améliorer le login/logout

Pour créer des liens de login/logout, il faut connaître les routes que 
FOSUserBundle définit.
La commande `app/console router:debug` nous les rappelle mais on peut aussi
le voir directement dans la config 

~~~~~~~~~~~~~~ {.xml}
    <!-- vendor/friendsofsymfony/user-bundle/Resources/config/routing/security.xml -->
    ...
    <route id="fos_user_security_login" pattern="/login">
        <default key="_controller">FOSUserBundle:Security:login</default>
    </route>

    <route id="fos_user_security_logout" pattern="/logout">
        <default key="_controller">FOSUserBundle:Security:logout</default>
    </route>
    ...
~~~~~~~~~~~~~~

Dans le template, on va donc écrire

~~~~~~~~~~~~~~ {.html}
  <!-- app/Resources/views/base.html.twig -->
  {% if app.user %}
    {# user is logged in #}
    <a href="{{ path('fos_user_security_logout') }}">Logout</a>
  {% else %}
    {# user is not logged in #}
    <a href="{{ path('fos_user_security_login') }}">Login</a>
  {% endif %}
~~~~~~~~~~~~~~

Cela fonctionne mais c'est affreux \url{http://localhost/sf1/web/app_dev.php/login}

~~~~~~~~~~~~~~ {.email}
  layout.login
    security.login.username __________ security.login.password ___________
    [ ] security.login.remember_me                 [security.login.submit]
~~~~~~~~~~~~~~

Première étape: tarduire les chaînes en décommentant le ligne `translator`
inactive par défaut

~~~~~~~~~~~~~~ {.yaml}
  # app/config/config.yml
  framework:
      #esi:             ~
      translator:      { fallback: %locale% } 
~~~~~~~~~~~~~~

C'est mieux : \url{http://localhost/sf1/web/app_dev.php/login}

~~~~~~~~~~~~~~ {.email}
  Login
    Username: ____________________ Password: ____________________
    [ ] Remember me                                       [Login]
~~~~~~~~~~~~~~

On souhaite personnaliser cette page de formulaire. Son template 
est le fichier suivant qui hérite du layout par défaut de FOSUserBundle

~~~~~~~~~~~~~~ {.html}
  <!-- vendor/friendsofsymfony/user-bundle/Resources/views/Security/login.html.twig -->
  {% extends "FOSUserBundle::layout.html.twig" %}
 
  {% trans_default_domain 'FOSUserBundle' %}
 
  {% block fos_user_content %}
  {% if error %}
      <div>{{ error.messageKey|trans(error.messageData, 'security') }}</div>
  {% endif %}
 
  <form action="{{ path("fos_user_security_check") }}" method="post">
   <input type="hidden" name="_csrf_token" value="{{ csrf_token }}" />
     <label for="username">{{ 'security.login.username'|trans }}</label>
   <input type="text" id="username" name="_username" value="{{ last_username }}" 
                                                  required="required" />
     <label for="password">{{ 'security.login.password'|trans }}</label>
   <input type="password" id="password" name="_password" required="required" />
   <input type="checkbox" id="remember_me" name="_remember_me" value="on" />
     <label for="remember_me">{{ 'security.login.remember_me'|trans }}</label>
   <input type="submit" id="_submit" name="_submit" value="{{ 'security.login.submit'|trans }}" />
  </form>
  {% endblock fos_user_content %}
~~~~~~~~~~~~~~

Le formulaire de login serait mieux intégré s'il héritait de notre layout
plutôt que de celui de FOSUserBundle.

Pour ce faire, il faut d'abord vérifier que la classe de notre userBundle
dispose d'une méthode `getParent` qui définit FOSUserBundle comme parent Grâce
à elle, on va pouvoir en outrepasser certaines définitions

~~~~~~~~~~~~~~ {.php}
  <?php //src/Nico/UserBundle/NicoUserBundle.php
  public function getParent()
  {
    return 'FOSUserBundle';
  }
~~~~~~~~~~~~~~

Maintenant, on crée un nouveau layout qui hérite du layout du site et qui
intègre le formulaire de login contenu dans le bloc `fos_user_content` défini
le `login.html.twig` présenté précédemment

~~~~~~~~~~~~~~ {.html}
  <!-- src/Nico/UserBundle/Resources/views/layout.html.twig -->
  {% extends "::base.html.twig" %}
  
  {% block body %}
      {% block fos_user_content %}
      {% endblock fos_user_content %}
  {% endblock %}
~~~~~~~~~~~~~~





# La magie

Nous allons demander à symfony de générer un contrôleur basique pour notre
entité Quark du bundle NicoBlogBundle Ce contrôleur CRUD (pour Create, Read,
Update, Delete) permet d'effectuer les cinq opérations de base sur un modèle.

- Afficher les enregistrements,
- Afficher un seul enregistrement en se basant sur sa clé primaire,
- Créer un nouvel enregistrement,
- Modifier un enregistrement existant,
- Supprimer un enregistrement existant.

On validera les réponses proposées par défaut

~~~~~~~~~~~~~~ {.email}
  $ php app/console doctrine:generate:crud --entity=NicoBlogBundle:Quark --route-prefix=quark 
                                                                    --with-write --format=yml
~~~~~~~~~~~~~~

Cette commande va créer le contrôleur `QuarkController.php` dans le répertoire
`Controller` du bundle et les templates `edit.html.twig`, `index.html.twig`,
`new.html.twig` et `show.html.twig` dans le répertoire `Resources/views/Quark/`

Nous aurons besoin d'ajouter une méthode `__toString()` à notre classe
Category pour que s'affiche le menu déroulant Catégorie du formulaire de
modification de quark :

~~~~~~~~~~~~~~ {.php}
    <?php //src/Nico/BlogBundle/Entity/Category.php
    public function __toString()
    {
      return $this->getName();
    }
~~~~~~~~~~~~~~

Le routage `src/Nico/BlogBundle/Resources/config/routing/quark.yml` qui a été
créé doit être chargé par le fichier de routage du bundle en ajoutant 

~~~~~~~~~~~~~~ {.yaml}
    # src/Nico/BlogBundle/Resources/config/routing.yml

    NicoBlogBundle_quark:
      resource: "@NicoBlogBundle/Resources/config/routing/quark.yml"
      prefix:   /quark
~~~~~~~~~~~~~~

L'adresse \url{http://localhost/sf1/web/app_dev.php/quark}
doit donner un résultat intéressant

Il nous reste à sécuriser les pages de création, modification et suppression.

Un coup d'œil au fichier de routage CRUD

~~~~~~~~~~~~~~ {.yaml}
  # src/Nico/BlogBundle/Resources/config/routing/quark.yml
  ...
  quark_new:
      path:     /new
      defaults: { _controller: "NicoBlogBundle:Quark:new" }

  quark_edit:
      path:     /{id}/edit
      defaults: { _controller: "NicoBlogBundle:Quark:edit" }
  ...
~~~~~~~~~~~~~~

Nous voyons que nous devons ajouter des routes dans la section `acces_control`
du fichier de configuration de sécurité

~~~~~~~~~~~~~~ {.yaml}
  # app/config/security.yml
  ...
  access_control:
      - { path: ^/quark/new, role: ROLE_ADMIN }
      - { path: ^/quark/[0-9]+/edit, role: ROLE_ADMIN }
      - { path: ^/quark/[0-9]+/delete, role: ROLE_ADMIN }
  ...
~~~~~~~~~~~~~~

NOTES ------------------------------------------------------------

FOSUserBundle FOSUserBundle FTW! VIDEO Tutorial

https://knpuniversity.com/screencast/fosuserbundle-ftw
