Rules Once
==========

Rules Once provides support for creating reusable Rules that execute once on or after a specified time and then immediately disable themselves after execution. Such rules can be created manually or programmatically by other modules.

Rules Once provides these new rules plugins:

* Condition: "After a date"
* Action: "Enable a rule"
* Action: "Disable a rule"

These can be used together to create easily reusable scheduled actions that happen on a one-time basis.

Similar functionality is possible via the Rules Scheduler module that is a sub-module of Rules. See below for differences.


Installation and Configuration
------------------------------

- Install this module using the official Backdrop CMS instructions at
  https://backdropcms.org/guide/modules.

Usage
-----

To create a one-time rule manually, create a reaction rule as follows:

* Event: "Cron maintenance tasks are performed"
* Condition: "After a date", setting the desired date
* Actions:
  * Any desired actions (e.g., log message, email, etc.)
  * "Disable a rule", setting it to this rule.

You can reuse this rule after its execution by updating the date in the condition and re-enabling it.

Modules can create and manage such rules for their own purposes by creating the desired rule(s) via `hook_rules_default_configuration()` and/or by providing a UI to administrators to enable/disable and set the date for their associated rules. Rules Once provides some functions for use by other modules that provide their own UI for enabling/disabling and setting the dates of Rules Once rules.

Note that actions happen on cron calls, so each action will happen at the next scheduled cron run on or after the scheduled time.


Similar Functionality
------

The Rules Scheduler module (a sub-module of Rules) allows you to create scheduled tasks via Rules. To do the same thing as described above in Rules Scheduler, you would:

* Create an Action Set component that contains the action(s) you wish to perform.
* Schedule it for a specific time from the drop-down menu for the component at admin/config/workflow/rules/components.

Scheduled tasks go away after they run, but you can create a new one by re-scheduling the Action set component for a new time.

If you are manually creating one-time tasks now and then, Rules Scheduler probably does everything you need. If you want to create reusable tasks that are configured from other modules via their own UI, it may be easier to use Rules Once rules and have your module interact with them via the API functions that Rules Once module provides.


Issues
------

Bugs and Feature requests should be reported in the [Issue Queue](https://github.com/backdrop-contrib/rules_once/issues).


Current Maintainers
-------------------

- [Robert J. Lang](https://github.com/bugfolder).


Credits
-------

- Created for Backdrop CMS by [Robert J. Lang](https://github.com/bugfolder).

License
-------

This project is GPL v2 software.
See the LICENSE.txt file in this directory for complete text.
