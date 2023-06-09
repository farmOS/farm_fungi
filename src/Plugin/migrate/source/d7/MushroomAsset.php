<?php

namespace Drupal\farm_fungi\Plugin\migrate\source\d7;

use Drupal\asset\Plugin\migrate\source\d7\Asset;
use Drupal\fraction\Fraction;
use Drupal\migrate\Row;

/**
 * Mushroom asset source.
 *
 * Extends the Asset source plugin to include source properties needed for the
 * farm_fungi D7 migration.
 *
 * @MigrateSource(
 *   id = "d7_farm_fungi_asset",
 *   source_module = "farm_asset"
 * )
 */
class MushroomAsset extends Asset {

  /**
   * {@inheritdoc}
   */
  public function prepareRow(Row $row) {
    $id = $row->getSourceProperty('id');

    // Get quantity field values.
    $quantity_values = $this->getFieldValues('farm_asset', 'field_farm_quantity', $id);

    // Iterate through quantity field values to collect field collection item IDs.
    $field_collection_item_ids = [];
    foreach ($quantity_values as $quantity_value) {
      if (!empty($quantity_value['value'])) {
        $field_collection_item_ids[] = $quantity_value['value'];
      }
    }

    // Iterate through the field collection IDs and load values.
    $quantities = [];
    foreach ($field_collection_item_ids as $item_id) {

      // Query the quantity information from the field collection.
      $query = $this->select('field_collection_item', 'fci')
        ->condition('fci.item_id', $item_id)
        ->condition('fci.field_name', 'field_farm_quantity');

      // Join in the measure value.
      $query->leftJoin('field_data_field_farm_quantity_measure', 'fdffqm',
        "fci.item_id = fdffqm.entity_id AND fdffqm.entity_type = 'field_collection_item' AND fdffqm.bundle = 'field_farm_quantity' AND fdffqm.deleted = '0'");
      $query->addField('fdffqm', 'field_farm_quantity_measure_value', 'measure');

      // Join in the numerator and denominator values.
      $query->leftJoin('field_data_field_farm_quantity_value', 'fdffqv',
        "fci.item_id = fdffqv.entity_id AND fdffqv.entity_type = 'field_collection_item' AND fdffqv.bundle = 'field_farm_quantity' AND fdffqv.deleted = '0'");
      $query->addField('fdffqv', 'field_farm_quantity_value_numerator', 'value_numerator');
      $query->addField('fdffqv', 'field_farm_quantity_value_denominator', 'value_denominator');

      // Join in the units value.
      $query->leftJoin('field_data_field_farm_quantity_units', 'fdffqu',
        "fci.item_id = fdffqu.entity_id AND fdffqu.entity_type = 'field_collection_item' AND fdffqu.bundle = 'field_farm_quantity' AND fdffqu.deleted = '0'");
      $query->leftJoin('taxonomy_term_data', 'fdffquttd',
        "fdffqu.field_farm_quantity_units_tid = fdffquttd.tid");
      $query->addField('fdffquttd', 'name', 'units');

      // Join in the label value.
      $query->leftJoin('field_data_field_farm_quantity_label', 'fdffql',
        "fci.item_id = fdffql.entity_id AND fdffql.entity_type = 'field_collection_item' AND fdffql.bundle = 'field_farm_quantity' AND fdffql.deleted = '0'");
      $query->addField('fdffql', 'field_farm_quantity_label_value', 'label');

      // Execute the query.
      $quantities[] = $query->execute()->fetchAssoc();
    }

    // Create a string that summarizes the quantities.
    $quantity_summaries = [];
    foreach ($quantities as $quantity) {
      $quantity_summary = '';
      if (!empty($quantity['label'])) {
        $quantity_summary = $quantity['label'];
      }
      if (!empty($quantity['measure'])) {
        $measures = quantity_measures();
        $quantity_summary .= ' (' . $measures[$quantity['measure']]['label'] . ')';
      }
      if (!empty($quantity['value_numerator']) && !empty($quantity['value_denominator'])) {
        $fraction = new Fraction($quantity['value_numerator'], $quantity['value_denominator']);
        $quantity_summary .= ' ' . $fraction->toDecimal(0, TRUE);
      }
      if (!empty($quantity['units'])) {
        $quantity_summary .= ' ' . $quantity['units'];
      }
      $quantity_summaries[] = $quantity_summary;
    }
    $summary = "Quantity:\n" . implode("\n", $quantity_summaries);

    // The quantity summary is going to be prepended to the asset's Notes field,
    // but we want to make sure that whitespace is added if there is already
    // data in the Notes field.
    $description = $this->getFieldvalues('farm_asset', 'field_farm_description', $id);
    if (!empty($description)) {
      $summary = $summary . "\n\n";
    }

    // Add the quantity summary to the row for future processing.
    $row->setSourceProperty('quantity_summary', $summary);

    return parent::prepareRow($row);
  }

}
