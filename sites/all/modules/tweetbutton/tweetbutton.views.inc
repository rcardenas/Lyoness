<?php
// $Id: tweetbutton.views.inc,v 1.1.2.1 2010/11/02 10:02:41 jasonleon Exp $

function tweetbutton_views_data() {
  $data = array();
  
  $data['node']['tweetbutton'] = array(
    'field' => array(
      'title' => t('Tweet button'),
      'help' => t('Provide a tweet button field.'),
      'handler' => 'views_handler_field_tweetbutton',
    ),
  );

  return $data;
}
