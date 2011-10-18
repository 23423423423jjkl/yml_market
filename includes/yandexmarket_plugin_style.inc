<?php
/**
 * @file
 * Contains the yandexmarket style plugin.
 */

/**
 * Style plugin to render items using YML standart.
 */
class yandexmarket_plugin_style extends views_plugin_style {
  function option_definition() {
    global $base_url, $base_path;
    $options = parent::option_definition();
    $this->definition['uses grouping'] = FALSE;
    $options['yacolumns'] = array('contains' => array(
      'type' => array('contains' => array(
        'field' => array('default' => '--static--'),
        'static' => array('default' => 'vendor.model'),
    )),
    ));
    $options['currencies'] = array('default' => '<currency id="RUR" rate="1" />');
    $options['shop'] = array('contains' => array(
      'url' => array('default' => $base_url . $base_path),
      'name' => array('default' => variable_get('uc_store_name', variable_get('site_name', ''))),
      'company' => array('default' => variable_get('uc_field_company', '')),
    ));
    $options['vocabulary'] = array('default' => '');
    return $options;
  }
  /**
   * Render the given style.
   */
  function options_form(&$form, &$form_state) {
    parent::options_form($form, $form_state);
    $handlers = $this->display->handler->get_handlers('field');
    if (empty($handlers)) {
      $form['error_markup'] = array(
        '#value' => t('You need at least one field before you can configure your table settings'),
        '#prefix' => '<div class="error form-item description">',
        '#suffix' => '</div>',
      );
      return;
    }

    // Create an array of allowed columns from the data we know:
    foreach ($handlers as $field => $handler) {
      if ($label = $handler->label()) {
        $field_names[$field] = $label;
      }
      else {
        $field_names[$field] = $handler->ui_name();
      }
    }
    $field_names[''] = '<none>';
    $field_names['--static--'] = '<static value>';

    $form['shop']['name'] =  array(
      '#type' => 'textfield',
      '#default_value' => $this->options['shop']['name'],
      '#title' => t('Shop name'),
    );
    $form['shop']['company'] = array(
      '#type' => 'textfield',
      '#default_value' => $this->options['shop']['company'],
      '#title' => t('Shop company'),
    );
    $form['shop']['url'] = array(
      '#type' => 'textfield',
      '#default_value' => $this->options['shop']['url'],
      '#title' => t('Shop url'),
    );
    $form['currencies'] = array(
      '#type' => 'textarea',
      '#title' => t('Currencies'),
      '#default_value' => $this->options['currencies'],
      '#description' => t("List of currencies used in the shop. One currency - one selement. 'id' element is code of currency, 'rate' is currency rate. 'rate' also can be CBRF, NBU, NBK or CB."),
    );
    //only taxonomy vocabularies can now be used as categories
    $vocabularies = array('' => '<none>');
    foreach (taxonomy_get_vocabularies() as $v) {
      $vocabularies[$v->vid] = $v->name;
    }
    $form['vocabulary'] = array(
      '#type' => 'select',
      '#title' => t('Vocabulary'),
      '#default_value' => $this->options['vocabulary'],
      '#options' => $vocabularies,
      '#description' => t('What vocabulary to use for categories tag.'),
    );

    foreach (yandexmarket_fields() as $tag => $value) {
      $safe = str_replace(array('][', '_', ' '), '-', $tag);
      // the $id of the column for dependency checking.
      $id = 'edit-style-options-yacolumns-' . $safe . '-field';
      $types = yandexmarket_types($tag);
      $form['yacolumns'][$tag] = array(
        '#type' => 'fieldset',
        '#title' => $tag . ' (' . implode(', ', $types) . ')',
        '#collapsible' => TRUE,
        '#tree' => TRUE,
        '#collapsed' => ($this->options['yacolumns'][$tag]['field'] == ''
        || !isset($this->options['yacolumns'][$tag]['field']))?TRUE:FALSE,
        );
        $form['yacolumns'][$tag]['field'] = array(
        '#type' => 'select',
        '#options' => $field_names,
        '#default_value' => $this->options['yacolumns'][$tag]['field'],
        );
        $form['yacolumns'][$tag]['static'] = array(
        '#type' => 'textfield',
        '#title' => t('Static value'),
        '#size' => 40,
        '#default_value' => $this->options['yacolumns'][$tag]['static'],
        '#process' => array('ctools_dependent_process'),
        '#dependency' => array($id => array('--static--')),
        );
        $form['yacolumns'][$tag]['description'] = array(
        '#value' => '<div>' . $value['description'] . '</div>',
        );
    }
    return $form;

  }
  /**
   * Validate options form.
   */
  function options_validate(&$form, &$form_state) {
    // It is very important to call the parent function here:
    parent::options_validate($form, $form_state);

    //'type' should be a field or provided with correct static value.
    if ($form_state['values']['style_options']['yacolumns']['type']['field'] == ''
    || ($form_state['values']['style_options']['yacolumns']['type']['field'] == '--static--'
    && !in_array($form_state['values']['style_options']['yacolumns']['type']['static'],
    yandexmarket_types()))) {
      form_set_error('style_options][yacolumns][type][field', t("'type' field can not be &lt;None&gt;."));
      form_set_error('style_options][yacolumns][type][static', t("If &lt;Static&gt; value selected for 'type' field, you should enter a valid type: @types",
      array('@types' => implode(', ', yandexmarket_types()))));
    }
  }
}
