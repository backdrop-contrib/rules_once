<?php
/**
 * @file
 * Standard Rules include file.
 */

/**
 * Implements hook_rules_condition_info().
 */
function rules_once_rules_condition_info() {
  return array(
    'rules_once_condition_after' => array(
      'label' => t('After a date'),
      'parameter' => array(
        'date' => array(
          'label' => t('Execute on or after'),
          'type' => 'date',
          'restriction' => 'input',
        ),
      ),
      'group' => t('Once'),
      'callbacks' => array(
        'execute' => 'rules_once_compare_date',
      ),
    ),
  );
}

/**
 * Callback function for rules condition: test if it's on or after the date.
 */
function rules_once_compare_date($date) {
  return REQUEST_TIME >= strtotime($date);
}

/**
 * Implements hook_rules_action_info().
 */
function rules_once_rules_action_info() {
  return array(
    'enable_rule' => array(
      'label' => t('Enable a rule'),
      'group' => t('System'),
      'parameter' => array(
        'rule' => array(
          'restriction' => 'input',
          'type' => 'rules_config',
          'label' => t('Rule'),
          'options list' => 'rules_once_rules_options',
          'description' => t('Select the rule to enable.'),
        ),
      ),
      'base' => 'rules_once_enable_rule',
      'access callback' => 'rules_system_integration_access',
    ),
    'disable_rule' => array(
      'label' => t('Disable a rule'),
      'group' => t('System'),
      'parameter' => array(
        'rule_name' => array(
          'restriction' => 'input',
          'type' => 'rules_config',
          'label' => t('Rule'),
          'options list' => 'rules_once_rules_options',
          'description' => t('Select the rule to disable.'),
        ),
      ),
      'base' => 'rules_once_disable_rule',
      'access callback' => 'rules_system_integration_access',
    ),
  );
}

/**
 * Return the list of rules to be used as the option list in enable/disable
 * rule actions,
 */
function rules_once_rules_options() {
  $rules = rules_config_load_multiple(FALSE);
  $options = array();
  foreach ($rules as $name => $rule) {
    $options[$name] = $rule->label;
  }
  return $options;
}

/**
 * Callback function for rules action to enable a rule.
 */
function rules_once_enable_rule($rule) {
  $rule->active = 1;
  $rule->save();
}

/**
 * Callback function for rules action to disable a rule.
 */
function rules_once_disable_rule($rule) {
  $rule->active = 0;
  $rule->save();
}
