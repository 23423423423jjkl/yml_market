<?php
/**
 * @file
 * Contains the node_url field handler.
 */

/**
 * Field handler to provide simple renderer of url path to node.
 */
class yandexmarket_handler_field_node_url extends views_handler_field {
  function construct() {
    parent::construct();
    $this->additional_fields['nid'] = 'nid';
  }

  function query() {
    $this->ensure_my_table();
    $this->add_additional_fields();
  }
  function render($values) {
    $nid = $values->{$this->aliases['nid']};
    return $this->sanitize_value(check_url(url("node/$nid", array('absolute' => TRUE))));
  }
}