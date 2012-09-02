<?php

/**
 * Export Drupal Commerce seller profiles to Views.
 */

/**
 * Implements hook_views_data()
 */
function commerce_seller_views_data() {
  $data = array();

  $data['commerce_seller_profile']['table']['group']  = t('Commerce Seller Profile');

  $data['commerce_seller_profile']['table']['base'] = array(
    'field' => 'profile_id',
    'title' => t('Commerce Seller Profile'),
    'help' => t('Seller profiles containing addresses and other seller information.'),
    'access query tag' => 'commerce_seller_profile_access',
  );
  $data['commerce_seller_profile']['table']['entity type'] = 'commerce_seller_profile';

  // Expose the profile ID.
  $data['commerce_seller_profile']['profile_id'] = array(
    'title' => t('Profile ID'),
    'help' => t('The unique internal identifier of the profile.'),
    'field' => array(
      'handler' => 'commerce_seller_handler_field_seller_profile',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_numeric',
    ),
  );

  // Expose the owner uid.
  $data['commerce_seller_profile']['uid'] = array(
    'title' => t('Owner'),
    'help' => t('Relate a profile to the user it belongs to.'),
    'relationship' => array(
      'handler' => 'views_handler_relationship',
      'base' => 'users',
      'field' => 'uid',
      'label' => t('Profile owner'),
    ),
  );

  // Expose the profile status.
  $data['commerce_seller_profile']['status'] = array(
    'title' => t('Status'),
    'help' => t('Whether or not the profile is active.'),
    'field' => array(
      'handler' => 'views_handler_field_boolean',
      'click sortable' => TRUE,
      'output formats' => array(
        'active-disabled' => array(t('Active'), t('Disabled')),
      ),
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_boolean_operator',
      'label' => t('Active'),
      'type' => 'yes-no',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );

  // Expose the created and changed timestamps.
  $data['commerce_seller_profile']['created'] = array(
    'title' => t('Created date'),
    'help' => t('The date the profile was created.'),
    'field' => array(
      'handler' => 'views_handler_field_date',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort_date',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_date',
    ),
  );

  $data['commerce_seller_profile']['created_fulldate'] = array(
    'title' => t('Created date'),
    'help' => t('In the form of CCYYMMDD.'),
    'argument' => array(
      'field' => 'created',
      'handler' => 'views_handler_argument_node_created_fulldate',
    ),
  );

  $data['commerce_seller_profile']['created_year_month'] = array(
    'title' => t('Created year + month'),
    'help' => t('In the form of YYYYMM.'),
    'argument' => array(
      'field' => 'created',
      'handler' => 'views_handler_argument_node_created_year_month',
    ),
  );

  $data['commerce_seller_profile']['created_timestamp_year'] = array(
    'title' => t('Created year'),
    'help' => t('In the form of YYYY.'),
    'argument' => array(
      'field' => 'created',
      'handler' => 'views_handler_argument_node_created_year',
    ),
  );

  $data['commerce_seller_profile']['created_month'] = array(
    'title' => t('Created month'),
    'help' => t('In the form of MM (01 - 12).'),
    'argument' => array(
      'field' => 'created',
      'handler' => 'views_handler_argument_node_created_month',
    ),
  );

  $data['commerce_seller_profile']['created_day'] = array(
    'title' => t('Created day'),
    'help' => t('In the form of DD (01 - 31).'),
    'argument' => array(
      'field' => 'created',
      'handler' => 'views_handler_argument_node_created_day',
    ),
  );

  $data['commerce_seller_profile']['created_week'] = array(
    'title' => t('Created week'),
    'help' => t('In the form of WW (01 - 53).'),
    'argument' => array(
      'field' => 'created',
      'handler' => 'views_handler_argument_node_created_week',
    ),
  );

  $data['commerce_seller_profile']['changed'] = array(
    'title' => t('Updated date'),
    'help' => t('The date the profile was last updated.'),
    'field' => array(
      'handler' => 'views_handler_field_date',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort_date',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_date',
    ),
  );

  $data['commerce_seller_profile']['changed_fulldate'] = array(
    'title' => t('Updated date'),
    'help' => t('In the form of CCYYMMDD.'),
    'argument' => array(
      'field' => 'changed',
      'handler' => 'views_handler_argument_node_created_fulldate',
    ),
  );

  $data['commerce_seller_profile']['changed_year_month'] = array(
    'title' => t('Updated year + month'),
    'help' => t('In the form of YYYYMM.'),
    'argument' => array(
      'field' => 'changed',
      'handler' => 'views_handler_argument_node_created_year_month',
    ),
  );

  $data['commerce_seller_profile']['changed_timestamp_year'] = array(
    'title' => t('Updated year'),
    'help' => t('In the form of YYYY.'),
    'argument' => array(
      'field' => 'changed',
      'handler' => 'views_handler_argument_node_created_year',
    ),
  );

  $data['commerce_seller_profile']['changed_month'] = array(
    'title' => t('Updated month'),
    'help' => t('In the form of MM (01 - 12).'),
    'argument' => array(
      'field' => 'changed',
      'handler' => 'views_handler_argument_node_created_month',
    ),
  );

  $data['commerce_seller_profile']['changed_day'] = array(
    'title' => t('Updated day'),
    'help' => t('In the form of DD (01 - 31).'),
    'argument' => array(
      'field' => 'changed',
      'handler' => 'views_handler_argument_node_created_day',
    ),
  );

  $data['commerce_seller_profile']['changed_week'] = array(
    'title' => t('Updated week'),
    'help' => t('In the form of WW (01 - 53).'),
    'argument' => array(
      'field' => 'changed',
      'handler' => 'views_handler_argument_node_created_week',
    ),
  );

  // Expose links to operate on the profile.
  $data['commerce_seller_profile']['view_seller_profile'] = array(
    'field' => array(
      'title' => t('Link'),
      'help' => t('Provide a simple link to the administrator view of the profile.'),
      'handler' => 'commerce_seller_handler_field_seller_profile_link',
    ),
  );
  $data['commerce_seller_profile']['edit_seller_profile'] = array(
    'field' => array(
      'title' => t('Edit link'),
      'help' => t('Provide a simple link to edit the profile.'),
      'handler' => 'commerce_seller_handler_field_seller_profile_link_edit',
    ),
  );
  $data['commerce_seller_profile']['delete_seller_profile'] = array(
    'field' => array(
      'title' => t('Delete link'),
      'help' => t('Provide a simple link to delete the profile.'),
      'handler' => 'commerce_seller_handler_field_seller_profile_link_delete',
    ),
  );

  $data['commerce_seller_profile']['empty_text'] = array(
    'title' => t('Empty text'),
    'help' => t('Displays an appropriate empty text message for seller profile lists.'),
    'area' => array(
      'handler' => 'commerce_seller_handler_area_empty_text',
    ),
  );

  return $data;
}