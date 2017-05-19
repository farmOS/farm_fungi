<?php
/**
 * @file
 * farm_mushroom.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function farm_mushroom_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_farm_description|farm_asset|substrate|form';
  $field_group->group_name = 'group_farm_description';
  $field_group->entity_type = 'farm_asset';
  $field_group->bundle = 'substrate';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Description',
    'weight' => '2',
    'children' => array(
      0 => 'field_farm_description',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Description',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-farm-description field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_farm_description|farm_asset|substrate|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_farm_files|farm_asset|substrate|form';
  $field_group->group_name = 'group_farm_files';
  $field_group->entity_type = 'farm_asset';
  $field_group->bundle = 'substrate';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'File attachments',
    'weight' => '4',
    'children' => array(
      0 => 'field_farm_images',
      1 => 'field_farm_files',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'File attachments',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-farm-files field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_farm_files|farm_asset|substrate|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_farm_general|farm_asset|substrate|form';
  $field_group->group_name = 'group_farm_general';
  $field_group->entity_type = 'farm_asset';
  $field_group->bundle = 'substrate';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'General information',
    'weight' => '0',
    'children' => array(
      0 => 'field_farm_substrate_type',
      1 => 'field_farm_mushroom_species',
      2 => 'name',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-farm-general field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_farm_general|farm_asset|substrate|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_farm_lineage|farm_asset|substrate|form';
  $field_group->group_name = 'group_farm_lineage';
  $field_group->entity_type = 'farm_asset';
  $field_group->bundle = 'substrate';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Lineage',
    'weight' => '3',
    'children' => array(
      0 => 'field_farm_parent',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Lineage',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-farm-lineage field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_farm_lineage|farm_asset|substrate|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Description');
  t('File attachments');
  t('General information');
  t('Lineage');

  return $field_groups;
}
