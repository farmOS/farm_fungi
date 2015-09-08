<?php
/**
 * @file
 * farm_mushroom.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function farm_mushroom_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_farm_asset_substrate_pattern';
  $strongarm->value = 'farm/substrate/[farm_asset:name]';
  $export['pathauto_farm_asset_substrate_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_farm_mushroom_species_pattern';
  $strongarm->value = 'farm/mushroom-species/[term:name]';
  $export['pathauto_taxonomy_term_farm_mushroom_species_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_farm_substrate_types_pattern';
  $strongarm->value = 'farm/substrate/type/[term:name]';
  $export['pathauto_taxonomy_term_farm_substrate_types_pattern'] = $strongarm;

  return $export;
}
