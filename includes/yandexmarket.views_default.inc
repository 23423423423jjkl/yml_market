<?php
/**
 * @file
 * Contains the yandexmarket default style plugin.
 */

/**
 * Implementation of hook_views_default_views().
 */
function yandexmarket_views_default_views() {
  /*
   * View 'yandexmarket'
   */
  global $base_url, $base_path;
  
  $view = new view;
  $view->name = 'yandexmarket';
  $view->description = '';
  $view->tag = '';
  $view->view_php = '';
  $view->base_table = 'node';
  $view->is_cacheable = FALSE;
  $view->api_version = 2;
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->override_option('fields', array(
    'nid' => array(
      'label' => 'Nid',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'link_class' => '',
        'alt' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'strip_tags' => 0,
        'html' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'link_to_node' => 0,
      'exclude' => 0,
      'id' => 'nid',
      'table' => 'node',
      'field' => 'nid',
      'override' => array(
        'button' => 'Override',
      ),
      'relationship' => 'none',
    ),
    'title_1' => array(
      'label' => 'Название',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'link_class' => '',
        'alt' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'strip_tags' => 0,
        'html' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'link_to_node' => 0,
      'exclude' => 0,
      'id' => 'title_1',
      'table' => 'node',
      'field' => 'title',
      'override' => array(
        'button' => 'Override',
      ),
      'relationship' => 'none',
    ),
    'node_url' => array(
      'label' => 'Node url',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'link_class' => '',
        'alt' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'strip_tags' => 0,
        'html' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'exclude' => 0,
      'id' => 'node_url',
      'table' => 'node',
      'field' => 'node_url',
      'override' => array(
        'button' => 'Override',
      ),
      'relationship' => 'none',
    ),
    'teaser' => array(
      'label' => 'Краткая аннотация',
      'alter' => array(
        'alter_text' => 0,
        'text' => '',
        'make_link' => 0,
        'path' => '',
        'link_class' => '',
        'alt' => '',
        'prefix' => '',
        'suffix' => '',
        'target' => '',
        'help' => '',
        'trim' => 0,
        'max_length' => '',
        'word_boundary' => 1,
        'ellipsis' => 1,
        'strip_tags' => 0,
        'html' => 0,
      ),
      'empty' => '',
      'hide_empty' => 0,
      'empty_zero' => 0,
      'exclude' => 0,
      'id' => 'teaser',
      'table' => 'node_revisions',
      'field' => 'teaser',
      'override' => array(
        'button' => 'Override',
      ),
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('filters', array(
    'status' => array(
      'operator' => '=',
      'value' => '1',
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
      ),
      'id' => 'status',
      'table' => 'node',
      'field' => 'status',
      'override' => array(
        'button' => 'Override',
      ),
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('access', array(
    'type' => 'none',
  ));
  $handler->override_option('cache', array(
    'type' => 'none',
  ));
  $handler->override_option('items_per_page', 0);
  $handler->override_option('distinct', 1);
  $handler->override_option('style_options', array(
    'grouping' => '',
  ));
  $handler = $view->new_display('pagenolayout', 'Page with no layout', 'pagenolayout_1');
  $handler->override_option('style_plugin', 'yandexmarket');
  $handler->override_option('style_options', array(
    'shop' => array(
      'name' => variable_get('uc_store_name', variable_get('site_name', '')),
      'company' => variable_get('uc_field_company', ''),
      'url' => $base_url . $base_path,
    ),
    'currencies' => '<currency id="RUR" rate="1" />',
    'vocabulary' => '',
    'yacolumns' => array(
      'id' => array(
        'field' => 'nid',
        'static' => '',
      ),
      'bid' => array(
        'field' => '',
        'static' => '',
      ),
      'cbid' => array(
        'field' => '',
        'static' => '',
      ),
      'available' => array(
        'field' => '',
        'static' => '',
      ),
      'type' => array(
        'field' => '--static--',
        'static' => 'vendor.model',
      ),
      'url' => array(
        'field' => 'node_url',
        'static' => '',
      ),
      'price' => array(
        'field' => '',
        'static' => '',
      ),
      'local_delivery_cost' => array(
        'field' => '',
        'static' => '',
      ),
      'currencyId' => array(
        'field' => '--static--',
        'static' => 'RUR',
      ),
      'categoryId' => array(
        'field' => '',
        'static' => '',
      ),
      'picture' => array(
        'field' => '',
        'static' => '',
      ),
      'typePrefix' => array(
        'field' => '',
        'static' => '',
      ),
      'vendor' => array(
        'field' => '',
        'static' => '',
      ),
      'model' => array(
        'field' => '',
        'static' => '',
      ),
      'name' => array(
        'field' => '',
        'static' => '',
      ),
      'delivery' => array(
        'field' => '',
        'static' => '',
      ),
      'description' => array(
        'field' => 'teaser',
        'static' => '',
      ),
      'vendorCode' => array(
        'field' => '',
        'static' => '',
      ),
      'sales_notes' => array(
        'field' => '',
        'static' => '',
      ),
      'manufacturer_warranty' => array(
        'field' => '',
        'static' => '',
      ),
      'country_of_origin' => array(
        'field' => '',
        'static' => '',
      ),
      'downloadable' => array(
        'field' => '',
        'static' => '',
      ),
      'author' => array(
        'field' => '',
        'static' => '',
      ),
      'publisher' => array(
        'field' => '',
        'static' => '',
      ),
      'series' => array(
        'field' => '',
        'static' => '',
      ),
      'year' => array(
        'field' => '',
        'static' => '',
      ),
      'ISBN' => array(
        'field' => '',
        'static' => '',
      ),
      'volume' => array(
        'field' => '',
        'static' => '',
      ),
      'part' => array(
        'field' => '',
        'static' => '',
      ),
      'language' => array(
        'field' => '',
        'static' => '',
      ),
      'binding' => array(
        'field' => '',
        'static' => '',
      ),
      'page_extent' => array(
        'field' => '',
        'static' => '',
      ),
      'table_of_contents' => array(
        'field' => '',
        'static' => '',
      ),
      'performed_by' => array(
        'field' => '',
        'static' => '',
      ),
      'performance_type' => array(
        'field' => '',
        'static' => '',
      ),
      'format' => array(
        'field' => '',
        'static' => '',
      ),
      'storage' => array(
        'field' => '',
        'static' => '',
      ),
      'recording_length' => array(
        'field' => '',
        'static' => '',
      ),
      'artist' => array(
        'field' => '',
        'static' => '',
      ),
      'title' => array(
        'field' => '',
        'static' => '',
      ),
      'media' => array(
        'field' => '',
        'static' => '',
      ),
      'starring' => array(
        'field' => '',
        'static' => '',
      ),
      'director' => array(
        'field' => '',
        'static' => '',
      ),
      'originalName' => array(
        'field' => '',
        'static' => '',
      ),
      'country' => array(
        'field' => '',
        'static' => '',
      ),
      'worldRegion' => array(
        'field' => '',
        'static' => '',
      ),
      'region' => array(
        'field' => '',
        'static' => '',
      ),
      'days' => array(
        'field' => '',
        'static' => '',
      ),
      'dataTour' => array(
        'field' => '',
        'static' => '',
      ),
      'hotel_stars' => array(
        'field' => '',
        'static' => '',
      ),
      'room' => array(
        'field' => '',
        'static' => '',
      ),
      'meal' => array(
        'field' => '',
        'static' => '',
      ),
      'included' => array(
        'field' => '',
        'static' => '',
      ),
      'transport' => array(
        'field' => '',
        'static' => '',
      ),
      'place' => array(
        'field' => '',
        'static' => '',
      ),
      'hall plan' => array(
        'field' => '',
        'static' => '',
      ),
      'date' => array(
        'field' => '',
        'static' => '',
      ),
      'is_premiere' => array(
        'field' => '',
        'static' => '',
      ),
      'is_kids' => array(
        'field' => '',
        'static' => '',
      ),
    ),
  ));
  $handler->override_option('path', 'yandexmarket');
  $handler->override_option('menu', array(
    'type' => 'none',
    'title' => '',
    'description' => '',
    'weight' => 0,
    'name' => 'navigation',
  ));
  $handler->override_option('tab_options', array(
    'type' => 'none',
    'title' => '',
    'description' => '',
    'weight' => 0,
  ));

  $views[$view->name] = $view;

  return $views;
}