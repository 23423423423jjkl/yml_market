<?php
/**
 * @file
 * Interface between yandexmarket.module and views.module.
 */

/**
 * Implementation of hook_views_plugins().
 */
function yandexmarket_views_plugins() {
  $path = drupal_get_path('module', 'views_export_yml') ;
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
