/*
  user_config_override.h - user configuration overrides my_user_config.h for Tasmota

  Copyright (C) 2020  Theo Arends

  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef _USER_CONFIG_OVERRIDE_H_
  #define _USER_CONFIG_OVERRIDE_H_

  // force the compiler to show a warning to confirm that this file is included
  #warning **** user_config_override.h: Using Settings from this File ****

/*****************************************************************************************************\
 * USAGE:
 *   To modify the stock configuration without changing the my_user_config.h file:
 *   (1) copy this file to "user_config_override.h" (It will be ignored by Git)
 *   (2) define your own settings below
 *
 ******************************************************************************************************
 * ATTENTION:
 *   - Changes to SECTION1 PARAMETER defines will only override flash settings if you change define CFG_HOLDER.
 *   - Expect compiler warnings when no ifdef/undef/endif sequence is used.
 *   - You still need to update my_user_config.h for major define USE_MQTT_TLS.
 *   - All parameters can be persistent changed online using commands via MQTT, WebConsole or Serial.
\*****************************************************************************************************/

  // Setup DST Details
  #define TIME_DST_HEMISPHERE    North              // [TimeDst] Hemisphere (0 or North, 1 or South)
  #define TIME_DST_WEEK          Last               // Week of month (0 or Last, 1 or First, 2 or Second, 3 or Third, 4 or Fourth)
  #define TIME_DST_DAY           Sun                // Day of week (1 or Sun, 2 or Mon, 3 or Tue, 4 or Wed, 5 or Thu, 6 or Fri, 7 or Sat)
  #define TIME_DST_MONTH         Mar                // Month (1 or Jan, 2 or Feb, 3 or Mar, 4 or Apr, 5 or May, 6 or Jun, 7 or Jul, 8 or Aug, 9 or Sep, 10 or Oct, 11 or Nov, 12 or Dec)
  #define TIME_DST_HOUR          1                  // Hour (0 to 23)
  #define TIME_DST_OFFSET        +60                // Offset from UTC in minutes (-780 to +780)

  #define TIME_STD_HEMISPHERE    North              // [TimeStd] Hemisphere (0 or North, 1 or South)
  #define TIME_STD_WEEK          Last               // Week of month (0 or Last, 1 or First, 2 or Second, 3 or Third, 4 or Fourth)
  #define TIME_STD_DAY           Sun                // Day of week (1 or Sun, 2 or Mon, 3 or Tue, 4 or Wed, 5 or Thu, 6 or Fri, 7 or Sat)
  #define TIME_STD_MONTH         Oct                // Month (1 or Jan, 2 or Feb, 3 or Mar, 4 or Apr, 5 or May, 6 or Jun, 7 or Jul, 8 or Aug, 9 or Sep, 10 or Oct, 11 or Nov, 12 or Dec)
  #define TIME_STD_HOUR          2                  // Hour (0 to 23)
  #define TIME_STD_OFFSET        +0                 // Offset from UTC in minutes (-780 to +780)

  // Setup NTP Server
  #define NTP_SERVER1            "bubblegum.aknet.lan"

  // Set Time To Use DST
  #define APP_TIMEZONE           99                 // [Timezone] +1 hour (Amsterdam) (-13 .. 14 = hours from UTC, 99 = use TIME_DST/TIME_STD)

  // Enable Secure MQTT
  #ifndef USE_MQTT_TLS 
    #define USE_MQTT_TLS                            // Use TLS for MQTT connection (+34.5k code, +7.0k mem and +4.8k additional during connection handshake)
    #define MQTT_PORT            8883               // [MqttPort] MQTT port (10123 on CloudMQTT)
  #endif

  // Disable Timers
  #ifdef USE_TIMERS 
    #undef USE_TIMERS                               // Add support for up to 16 timers (+2k2 code)
  #endif

  // Disable Domoticz
  #ifdef USE_DOMOTICZ 
    #undef USE_DOMOTICZ                             // Use TLS for MQTT connection (+34.5k code, +7.0k mem and +4.8k additional during connection handshake)
    #undef DOMOTICZ_UPDATE_TIMER
  #endif

  // Disable Home Assistant
  #ifdef USE_HOME_ASSISTANT 
    #undef USE_HOME_ASSISTANT                       // Enable Home Assistant Discovery Support (+4.1k code, +6 bytes mem)
  #endif

  // Disable Rules Support
  #ifdef USE_RULES 
    #undef USE_RULES                                // Add support for rules (+8k code)
  #endif

  // Disable Discovery
  #ifdef USE_DISCOVERY 
    #undef USE_DISCOVERY                            // Enable mDNS for the following services (+8k code or +23.5k code with core 2_5_x, +0.3k mem)
  #endif

#endif  // _USER_CONFIG_OVERRIDE_H_