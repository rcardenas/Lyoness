<?php
// $Id: tweetbutton_views_field_handlers.inc,v 1.1.2.1 2010/11/02 10:02:41 jasonleon Exp $

class views_handler_field_tweetbutton extends views_handler_field {
  function construct() {
    parent::construct();
    $this->additional_fields['nid'] = 'nid';
  }


  function option_definition() {
    $options = parent::option_definition();
    $options['tweetbutton_button'] = array('default' => 'vertical');
    return $options;
  }

  function query() {
    $this->ensure_my_table();
    $this->add_additional_fields();
  }


  function options_form(&$form, &$form_state) {
    parent::options_form($form, &$form_state);

    $form['tweetbutton_button'] = array(
      '#type' => 'select',
      '#options' => array(
        'vertical' => t('Vertical Count'),
        'horizontal' => t('Horizontal Count'),
        'none'   => t('No count'),
      ),
      '#title' => t('Tweetbutton type'),
      '#default_value' => $this->options['tweetbutton_button'],
    );
  }

  function render($values) {
    $nid = $values->nid;
    $options['type'] = $this->options['tweetbutton_button'];
    $output = theme('tweetbutton_display', node_load($nid), $options);
    return $output;
  }
}
