<?php
/**
 * @file
 * farm_mushroom.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function farm_mushroom_taxonomy_default_vocabularies() {
  return array(
    'farm_mushroom_species' => array(
      'name' => 'Farm Mushroom Species',
      'machine_name' => 'farm_mushroom_species',
      'description' => 'A vocabulary of mushroom species.',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
    'farm_substrate_types' => array(
      'name' => 'Farm Substrate Types',
      'machine_name' => 'farm_substrate_types',
      'description' => 'A vocabulary of farm mushroom substrate types.',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
    ),
  );
}
