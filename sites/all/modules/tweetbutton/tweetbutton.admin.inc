<?php
// $Id: tweetbutton.admin.inc,v 1.1.4.5 2010/11/02 10:02:41 jasonleon Exp $

function tweetbutton_admin_settings() {
	$form = array();
  
  $form['button'] = array(
    '#type' => 'fieldset',
    '#title' => t('Choose your button. Customize it'),
  );
  
  $form['button']['tweetbutton_button'] = array(
    '#type' => 'select',
    '#options' => array(
      'vertical' => t('Vertical Count'),
      'horizontal' => t('Horizontal Count'),
      'none'   => t('No count'),
    ),
    '#default_value' => variable_get('tweetbutton_button', 'vertical'),
    '#id' => 'tweetbutton-button',
  );
  
  
  $form['button']['tweetbutton_tweet_text'] = array(
    '#type'          => 'textfield',
    '#title'         => t('Tweet Text'),
    '#default_value' => variable_get('tweetbutton_tweet_text',''),
    '#description'   => t('This is the text that people will include in their Tweet when they share from your website. If left empty title will be used. NOTE: Twitter will generate short url.'),
  );
  
  $form['button']['tweetbutton_text'] = array(
    '#type'          => 'fieldset',
    '#title'         => t('Available Tokens'),
    '#collapsible'   => TRUE,
    '#collapsed'     => TRUE,
  );

  $form['button']['tweetbutton_text']['tokens'] = array(
    '#value'  => theme('token_help', 'node'),
  );
  
  $form['button']['tweetbutton_language'] = array(
    '#title' => t('Language'),
    '#description' => t('This is the language that the button will render in on your website. People will see the Tweet dialog in their selected language for Twitter.com.'),
    '#type' => 'select',
    '#options' => array(
      'en' => t('English'),
      'fr' => t('French'),
      'de' => t('German'),
      'es' => t('Spanish'),
      'ja' => t('Japanese'),
    ),
    '#default_value' => variable_get('tweetbutton_language',''),
  );
  
  $form['follow'] = array(
    '#type' => 'fieldset',
    '#title' => t('Recommend people to follow'),
  );
  
  $form['follow']['tweetbutton_account'] = array(
    '#type' => 'textfield',
    '#title' => t('Twitter account to follow'),
    '#description' => t('This user will be @mentioned in the suggested'),
    '#default_value' => variable_get('tweetbutton_account',''),
    '#id' => 'tweetbutton-account',
  );
  
  $form['follow']['tweetbutton_rel_account_name'] = array(
    '#type' => 'textfield',
    '#title' => t('Related Account'),
    '#default_value' => variable_get('tweetbutton_rel_account_name',''),
  );
  
  $form['follow']['tweetbutton_rel_account_description'] = array(
    '#type' => 'textfield',
    '#title' => t('Related Account Description'),
    '#default_value' => variable_get('tweetbutton_rel_account_description',''),
  );
  
  return system_settings_form($form);
}

function tweetbutton_node_settings() {
	$form = array();
  
  $form['tweetbutton_node_types'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Node Types'),
    '#options' => node_get_types('names'),
    '#default_value' => variable_get('tweetbutton_node_types', array('story')),
  );
  
  $form['tweetbutton_node_location'] = array(
    '#type'    => 'checkboxes',
    '#title'   => t('Locations'),
    '#options' => array(
      'full'    => t('Full View'),
      'teaser'  => t('Teasers'),
      'links'   => t('Node links'),
    ),
    '#default_value' => variable_get('tweetbutton_node_location', array('full')),
  );
  
  
  $form['tweetbutton_node_weight'] = array(
    '#type'          => 'weight',
    '#title'         => t('Weight'),
    '#default_value' => variable_get('tweetbutton_node_weight', -5),
    '#description'   => t('Heavier weight will sink button to bottom on node view. This is also configurable per content type'),
  );
  
  return system_settings_form($form);
}
