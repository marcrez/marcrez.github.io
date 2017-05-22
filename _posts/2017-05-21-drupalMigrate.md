---
title: Drupal Migrate
permalink: drupal_migrate
layout: post
date: 2017-05-21
tags: [drupal]
category: raspberrypi
---

Migrate est un module qui permet d'importer des données dans des entités
existantes.
Nous nous instéressons ici à Migrate pour Drupal 8. Le module est déjà présent
dans le cœur mais non actif, de plus pour réussir à injecter des données issues
de fichiers csv, nous allons installer des modules supplémentaires.
![img]({{ site.baseurl }}/images/drupalMigrate/migrateAPI.png)

# Prérequis

Télécharger les modules nécessaires :
- migrate_source_csv permet d'importer un fichier csv comme source de données
- migrate tools fournit à drush les fonctions nécessaires pour lancer l'import
  de données
- migrate_plus est requis par migrate_tools.

```
$ drush dl migrate_plus  migrate_source_csv  migrate_tools
```

Nous pouvons maintenant activer les modules

```
$ drush en migrate migrate_source_csv migrate_plus migrate_tools
```

# Fichier de données

Nous disposons de données sous la forme d'un fichier csv. En voici un extrait

id    , vocab  , weight , name  , descr      , code
"752" , "lang" , "1"    , "ALL" , "ALLEMAND" , "2S11"
"753" , "lang" , "2"    , "ANG" , "ANGLAIS"  , "2S12"
"762" , "lang" , "3"    , "ESP" , "ESPAGNOL" , "2S22"
"765" , "lang" , "4"    , "ITA" , "ITALIEN"  , "2S25"

Ce fichier est enregistré dans le dossier `public://langs.csv`
(cf.**Configuration > Media > Système de fichiers**
`/admin/config/media/file-system`)

Afin de pouvoir importer ce fichier comme une liste de termes de taxonomie pour
Drupal 8, nous devons

- créer une vocabulaire de taxonomie nommée `langues`
- ajouter un champ de type *texte (brut)* que nous nommons `codelang` et dont
  le nom machine sera et `field_codelang`.

Cette nouvelle configuration peut même être exportée

```
$ drush cex
```

Rendez-vous maintenant dans
**Configuration > Développement > Synchornisation de configuration**
puis **Importer > Élément individuel**
(`/admin/config/development/configuration/single/import')

Concernant le type de configuration, nous choisissons **Migration**

Le point le plus délicat est la configuration à coller dans le champ
qui suit.

    dependencies: {  }
    id: import_langues_2017
    migration_group: migrated_terms
    label: 'Migrate terms from the source CSV to taxonomy terms'
    source:
      plugin: csv
      path: 'public://langs.csv'
      header_row_count: 1
      keys:
        - name
      column_names:
        -
          id: Id
        -
          vocab: vocabulary
        -
          weight: Weight
        -
          name: Name
        -
          description: Description
        -
          code: Code
    process:
      tid: id
      vid: vocab
      weight: weight
      name: name
      description: description
      field_co_orie: code
    destination:
      plugin: 'entity:taxonomy_term'
      default_bundle: langues
    migration_dependencies: {  }


Reste à lancer la commande qui va lancer l'import

```
drush migrate-import import_langues_2017
```

Là encore, on peut exporter cette configuration d'import

```
$ drush cex
```


En cas d'erreur, il est possible de lister les fichiers de config
pour vérifier le nom et supprimer ensuite ce fichier :

```
$ drush config-list |less
$ drush config-delete nom_de _la_config_a_supprimer
```

# Lectures

- https://www.drupal.org/docs/8/api/migrate-api/migrate-api-overview
- https://evolvingweb.ca/blog/drupal-8-migration-migrating-basic-data-part-1
- https://makina-corpus.com/blog/metier/2016/utiliser-migrate-en-drupal-8
- https://opc.com.au/media/blog/drupal-8-migrate-source-csv-migrating-structured-taxonomy-terms
- https://www.drupal.org/docs/8/modules/migrate-source-csv/using-the-migrate-source-csv-plugin
