<?php
/**
 * @file
 * les_taxonomy.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function les_taxonomy_taxonomy_default_vocabularies() {
  return array(
    'tegevused' => array(
      'name' => 'Tegevused',
      'machine_name' => 'tegevused',
      'description' => 'Seltsi tegevuste nimekiri',
      'hierarchy' => '0',
      'module' => 'taxonomy',
      'weight' => '0',
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
