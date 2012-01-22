<?php
/**
 * @file
 * Views handler: Product price field.
 */

/**
 * Changes behavour of uc_product_handler_field_price
 */
class yandexmarket_uc_product_handler_field_price extends uc_product_handler_field_price {
  function query() {
    $this->ensure_my_table();
    // Add the field.
    $this->field_alias = $this->query->add_field($this->table_alias, $this->real_field);

    $this->add_additional_fields();
  }
}