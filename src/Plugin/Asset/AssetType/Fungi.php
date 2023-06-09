<?php

namespace Drupal\farm_fungi\Plugin\Asset\AssetType;

use Drupal\farm_entity\Plugin\Asset\AssetType\FarmAssetType;

/**
 * Provides the fungi asset type.
 *
 * @AssetType(
 *   id = "fungi",
 *   label = @Translation("Fungi"),
 * )
 */
class Fungi extends FarmAssetType {

  /**
   * {@inheritdoc}
   */
  public function buildFieldDefinitions() {
    $fields = parent::buildFieldDefinitions();
    $field_info = [
      'fungi_type' => [
        'type' => 'entity_reference',
        'label' => $this->t('Fungi species/variety'),
        'description' => "Enter this fungi asset's species/variety.",
        'target_type' => 'taxonomy_term',
        'target_bundle' => 'fungi_type',
        'auto_create' => TRUE,
        'required' => TRUE,
        'weight' => [
          'form' => -90,
          'view' => -90,
        ],
      ],
      'substrate_type' => [
        'type' => 'entity_reference',
        'label' => $this->t('Substrate type'),
        'description' => 'Enter the type of substrate this fungi is growing on.',
        'target_type' => 'taxonomy_term',
        'target_bundle' => 'substrate_type',
        'auto_create' => TRUE,
        'weight' => [
          'form' => -85,
          'view' => -85,
        ],
      ],
    ];
    foreach ($field_info as $name => $info) {
      $fields[$name] = $this->farmFieldFactory->bundleFieldDefinition($info);
    }
    return $fields;
  }

}
