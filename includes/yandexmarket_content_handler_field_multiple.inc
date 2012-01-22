<?php
/**
 * @file
 * An extended subclass for multiple field handling that renders it's values without
 * any html markup
 */
class yandexmarket_content_handler_field_multiple extends content_handler_field_multiple {
  function render($values) {
    // If this is not a grouped field, use content_handler_field::render().
    if (!$this->defer_query) {
      return parent::render($values);
    }

    // We're down to a single node here, so we can retrieve the actual field
    // definition for the node type being considered.
    $field = content_fields($this->content_field['field_name'], $values->{$this->aliases['type']});
    $options = $this->options;

    $vid = $values->{$this->field_alias};
    if (isset($this->field_values[$vid])) {
      // Gather items, respecting the 'Display n values starting from m' settings.
      $count_skipped = 0;
      $items = array();
      foreach ($this->field_values[$vid] as $item) {
        if (empty($options['multiple']['multiple_from']) || ($count_skipped >= $options['multiple']['multiple_from'])) {
          if (empty($options['multiple']['multiple_number']) || (count($items) < $options['multiple']['multiple_number'])) {
            // Grab the nid - needed for render_link().
            $nid = $item['_nid'];
            unset($item['_nid']);
            $items[] = $item;
          }
          else {
            break;
          }
        }
        $count_skipped++;
      }

      // Build a pseudo-node from the retrieved values.
      $node = drupal_clone($values);
      // content_format and formatters will need a 'type'.
      $node->type = $values->{$this->aliases['type']};
      $node->nid = $values->{$this->aliases['nid']};
      $node->vid = $values->{$this->aliases['vid']};

      // Some formatters need to behave differently depending on the build_mode
      // (for instance: preview), so we provide one.
      $node->build_mode = NODE_BUILD_NORMAL;

      // Render items.
      $formatter_name = $options['format'];
      if ($items && ($formatter = _content_get_formatter($formatter_name, $field['type']))) {
        $rendered = array();
        if (content_handle('formatter', 'multiple values', $formatter) == CONTENT_HANDLE_CORE) {
          // Single-value formatter.
          foreach ($items as $item) {
            $output = content_format($field, $item, $formatter_name, $node);
            if (!empty($output)) {
              $rendered[] = $this->render_link($output, (object) array('nid' => $nid));
            }
          }
        }
        else {
          // Multiple values formatter.
          $output = content_format($field, $items, $formatter_name, $values);
          if (!empty($output)) {
            $rendered[] = $this->render_link($output, (object) array('nid' => $nid));
          }
        }

        if (count($rendered) > 1) {
          // TODO: could we use generic field display ?
          //only this string is changed in whole method
          return theme('yandexmarket_content_view_multiple_field', $rendered, $field, $values);
        }
        elseif ($rendered) {
          return $rendered[0];
        }
      }
    }

    return '';
  }
}