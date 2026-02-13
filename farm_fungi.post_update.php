<?php

/**
 * @file
 * Post update hooks for the farm_fungi module.
 */

function farm_fungi_removed_post_updates() {
  return [
    'farm_fungi_post_update_uninstall_v1_migrations' => '3.x',
  ];
}
