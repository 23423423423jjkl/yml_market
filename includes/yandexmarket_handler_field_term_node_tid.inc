<?php
/**
 * @file
 * Contains the yandexmarket_handler_field_term_node_tid field handler.
 */

/**
 * Field handler for one taxonomy term from selected vocabulary.
 */
class yandexmarket_handler_field_term_node_tid extends views_handler_field_term_node_tid {

  function render_item($count, $item) {
    return $item['tid'];
  }
  /**
   * Render only first item in this field together.
   * No theming. The simplest way.
   */
  function render_items($items) {
    return $items[0];
  }
}