<?php

/**
 * @file
 * Post update hooks for the farm_fungi module.
 */

/**
 * Uninstall v1 migration configs.
 */
function farm_fungi_post_update_uninstall_v1_migrations(&$sandbox) {
  $config = \Drupal::configFactory()->getEditable('migrate_plus.migration.farm_migrate_asset_fungi');
  if (!empty($config)) {
    $config->delete();
  }
  $config = \Drupal::configFactory()->getEditable('migrate_plus.migration.farm_migrate_taxonomy_fungi_type');
  if (!empty($config)) {
    $config->delete();
  }
  $config = \Drupal::configFactory()->getEditable('migrate_plus.migration.farm_migrate_taxonomy_substrate_type');
  if (!empty($config)) {
    $config->delete();
  }
}
