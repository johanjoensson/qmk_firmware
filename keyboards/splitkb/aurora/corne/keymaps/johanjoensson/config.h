/* Copyright 2022 splitkb.com <support@splitkb.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#define TAPPING_TERM 200
#define TAPPING_TERM_PER_KEY
#define LEADER_TIMEOUT 300
#define LED_CAPS_LOCK_PIN 24
#define LED_PIN_ON_STATE 0
#ifdef RGBLIGHT_ENABLE
#   define RGBLIGHT_EFFECT_BREATHING
#endif
#undef WS2812_DI_PIN
#define WS2812_DI_PIN 25
#undef RGBLED_NUM
#define RGBLED_NUM 2
#undef RGBLED_SPLIT
#define RGBLED_SPLIT {1, 1}
#define SPLIT_LED_STATE_ENABLE
#define SPLIT_LAYER_STATE_ENABLE
