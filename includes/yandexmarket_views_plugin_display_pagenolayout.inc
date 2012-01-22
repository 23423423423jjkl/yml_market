<?php
/**
 * @file
 * Contains the pagenolayout display plugin.
 */
require_once(drupal_get_path('module', 'views') . '/plugins/views_plugin_display_page.inc');
/**
 * The plugin that handles a full page and renders style plugin with no layout.
 */
class yandexmarket_views_plugin_display_pagenolayout extends views_plugin_display_page {
  function uses_breadcrumb() { return FALSE; }
  function get_style_type() { return 'feed'; }

  function execute() {
    $output = $this->view->render();
    if (empty($output)) {
      return drupal_not_found();
    }
    print $output;
  }

  function preview() {
    return '<pre>' . check_plain($this->view->render()) . '</pre>';
  }
  /**
   * Instead of going through the standard views_view.tpl.php, delegate this
   * to the style handler.
   */
  function render() {
    return $this->view->style_plugin->render($this->view->result);
  }
}