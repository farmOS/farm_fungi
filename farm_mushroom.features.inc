<?php
/**
 * @file
 * farm_mushroom.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function farm_mushroom_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_default_farm_asset_type().
 */
function farm_mushroom_default_farm_asset_type() {
  $items = array();
  $items['substrate'] = entity_import('farm_asset_type', '{
    "type" : "substrate",
    "label" : "Mushroom Substrate",
    "weight" : 0,
    "rdf_mapping" : []
  }');
  return $items;
}
