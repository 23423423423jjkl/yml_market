<?php
/**
 * @file
 * Interface between yandexmarket.module and views.module.
 */

/**
 * Implementation of hook_views_plugins().
 */
function yandexmarket_views_plugins() {
  $path = drupal_get_path('module', 'yandexmarket') ;
  $views_path = drupal_get_path('module', 'views');
  return array(
    'style' => array(
      'yandexmarket' => array(
        'title' => t('Yandex market'),
        'help' => t('Displays content as YML file for http://yandex.market.ru'),
        'handler' => 'yandexmarket_plugin_style',
        'path' => "$path/includes",
        'theme' => 'yandexmarket',
        'theme file' => 'theme.inc',
        'theme path' => "$path/theme",
        'uses row plugin' => False,
        'uses fields' => TRUE,
        'uses options' => TRUE,
        'type' => 'feed',
  ),
  ),
    'display' => array(
      'pagenolayout' => array(
        'title' => t('Page with no layout'),
        'help' => t('Display the view as a page, with URL and menu links. But without external layout.'),
        'handler' => 'yandexmarket_views_plugin_display_pagenolayout',
        'path' => "$path/includes",
        'uses hook menu' => TRUE,
        'use ajax' => FALSE,
        'use pager' => FALSE,
        'accept attachments' => TRUE,
        'admin' => t('Page with no layout'),
        'help topic' => 'display-page',
  ),
  ),
  );
}

/**
 * Implementation of hook_views_handlers().
 */
function yandexmarket_views_handlers() {
  return array(
    'info' => array(
      'path' => drupal_get_path('module', 'yandexmarket') . '/includes',
  ),
    'handlers' => array(
      'yandexmarket_handler_field_node_url' => array(
        'parent' => 'views_handler_field_node_link',
  ),
      'yandexmarket_uc_product_handler_field_price' => array(
        'parent' => 'uc_product_handler_field_price',
  ),
      'yandexmarket_content_handler_field_multiple' => array(
        'parent' => 'content_handler_field_multiple',
  ),
      'yandexmarket_handler_field_term_node_tid' => array(
        'parent' => 'views_handler_field_term_node_tid',
  ),
  ),
  );
}

/**
 * Implementation of hook_views_data_alter().
 * This function:
 * -clone each CCK views field,that uses 'content_handler_field_multiple'
 * and set its handler to 'yandexmarket_content_handler_field_multiple'.
 * -adds 'node_url' field thar simply returns url of node
 * -changes 'sell_price' fields bugy handler
 */
function yandexmarket_views_data_alter(&$data) {
  foreach ($data as $k => $v) {
    foreach ($v as $kk => $vv) {
      if(!is_array($vv)) continue;
      if (isset($vv['field']) && $vv['field']['handler'] == 'content_handler_field_multiple') {
        $data[$k]['yandexmarket_' . $kk] = array(
          'group' => t('Yandex market'),
          'title' => $vv['title'],
          'title short' => $vv['title short'],
          'help' => $vv['help'],
          'field' => $vv['field'],
        );
        $data[$k]['yandexmarket_' . $kk]['field']['handler'] = 'yandexmarket_content_handler_field_multiple';
      }
    }
  }
  $data['node']['node_url'] = array(
    'group' => t('Yandex market'),
    'field' => array(
      'title' => t('Node url'),
      'help' => t('Url of the node'),
      'handler' => 'yandexmarket_handler_field_node_url',
  ),
  );
  $data['term_node']['yandexmarket_tid'] = array(
    'title' => t('Term ID1'),
    'help' => t('The taxonomy term ID1'),
    'group' => t('Yandex market'),
    'field' => array(
      'title' => t('One term id'),
      'help' => t('Display one taxonomy term associated with a node from specified vocabularies.'),
      'handler' => 'yandexmarket_handler_field_term_node_tid',
      'skip base' => 'term_data',
  ),
  );
  $data['uc_products']['sell_price'] = array(
    'title' => t('Sell price'),
    'help' => t('The price for which the product is sold.'),
    'field' => array(
      'handler' => 'yandexmarket_uc_product_handler_field_price',
      'click sortable' => TRUE,
      'float' => TRUE,
      'additional fields' => array(
        'nid' => array(
          'table' => 'node',
          'field' => 'nid',
  ),
  ),
  ),
    'sort' => array(
      'handler' => 'views_handler_sort',
  ),
    'filter' => array(
      'handler' => 'views_handler_filter_float',
  ),
  );
}
