<?php
/**
 * @file
 * Theming functions and preprocessors
 */
/**
 * Generates YML file. Called by views syste.
 * 
 * Function uses filter_xss($str, array()) not check_plain for output values in most cases, 
 * because we want to strip out html tags, not encode them.
 * @param $view
 * @param $options
 * @param $rows
 * @param $title
 * @return YML file
 */
function theme_yandexmarket($view) {

  $handler  = $view['view']->style_plugin;

  $renders = $handler->render_fields($view['rows']);

  $output .= "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n";
  $output .= "<!DOCTYPE yml_catalog SYSTEM \"shops.dtd\">\n";
  $output .= "<yml_catalog date=\"" . date("Y-m-d H:i") . "\">\n";
  $output .= "<shop>\n";
  $output .= "  <name>" . filter_xss($view['options']['shop']['name'], array()) . "</name>\n";
  $output .= "  <company>" . filter_xss($view['options']['shop']['company'], array()) . "</company>\n";
  $output .= "  <url>" . filter_xss($view['options']['shop']['url'], array()) . "</url>\n\n";
  $output .= "  <currencies>\n";
  $output .= "    " . filter_xss($view['options']['currencies'], array('currency'));
  $output .= "\n  </currencies>\n\n";
  if ($view['options']['vocabulary']) {
    $output .= "  <categories>\n";
    $categories=taxonomy_get_tree($view['options']['vocabulary']);
    foreach ($categories as $c) {
      $output .= "    <category id=\"" . $c->tid . "\"";
      if ($c->parents[0]!=0) $output .= " parentId=\"" . $c->parents[0] . "\"";
      $output .= ">" . $c->name . "</category>\n";
    }
    $output .= "  </categories>\n\n";
  }
  $output .= "  <offers>\n\n";
  foreach ($view['rows'] as $num => $row) {
    $output .= "    <offer ";
    foreach (yandexmarket_offerattributes() as $id) {
      $v=_yandexmarket_getattribute($id, $view['options'], $renders[$num]);
      if($v=='easy') continue;
      if ($v!==FALSE) $output .= $id . "=\"" . $v . "\" ";
    }
    $output .= ">\n";
    foreach (yandexmarket_offertags(_yandexmarket_getattribute('type', $view['options'], $renders[$num])) as $id) {
      $v=_yandexmarket_getattribute($id, $view['options'], $renders[$num]);
      if($id=='categoryId' && strpos($v,',')) {
	$vv=explode(', ',$v); 
	foreach($vv as $vi)
	  $output .= "      <" . $id . ">" . $vi . "</" . $id . ">\n";
      } elseif ($v!==FALSE) $output .= "      <" . $id . ">" . $v . "</" . $id . ">\n";
    }
    $output .= "    </offer>\n\n";
  }
  $output .= "  </offers>\n";
  $output .= "</shop>\n";
  $output .= "</yml_catalog>\n";
  return $output;
}
/**
 * Search for value for given tag if in defferent places
 * @param $id
 *   name of tag
 * @param $options
 *   array of views options
 * @param $renderedrow
 *   array of rendered views data row
 *
 * @return
 * 	 Rendered value for given $id. FALSE if it shouldn't be showed.
 */
function _yandexmarket_getattribute($id, $options, $renderedrow) {
  
  if ($options['yacolumns'][$id]['field']=='') {
    return FALSE;
  }
  elseif ($options['yacolumns'][$id]['field']=='--static--') {
    return filter_xss($options['yacolumns'][$id]['static'], array());
  }
  else {
    return filter_xss($renderedrow[$options['yacolumns'][$id]['field']], array());
  }
}
/**
 * Same as theme_content_view_multiple_field but without any html markup.
 * Usefull for XML files.
 */
function theme_yandexmarket_content_view_multiple_field($items, $field, $values) {
  $output = '';
  $i = 0;
  foreach ($items as $item) {
    if (!empty($item) || $item == '0') {
      if ($i!=0) $output .= ', ';
      $output .= $item;
      $i++;
    }
  }
  return $output;
}
