/* Copyright 2019 Thomas Baart <thomas@splitkb.com>
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
#include QMK_KEYBOARD_H
#include "johanjoensson.h"

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* ┌──────┬──────┬──────┬──────┬──────┬──────┐                              ┌──────┬──────┬──────┬──────┬──────┬──────┐
 * │ TAB  │  Q   │  W   │  E   │  R   │  T   │                              │  Y   │  U   │  I   │  O   │  P   │  ⇤   │
 * ├──────┼──────┼──────┼──────┼──────┼──────┤                              ├──────┼──────┼──────┼──────┼──────┼──────┤
 * │ESC_CA│ A/◆  │ S/⎇  │  D   │ F/⎈  │  G   │                              │  H   │ J/⎈  │  K   │ L/⎇  │ ;/◆  │ ' "  │
 * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┬──────┐  ┌──────┬──────┼──────┼──────┼──────┼──────┼──────┼──────┤
 * │  L⇧  │  Z   │  X   │  C   │  V   │  B   │  [   │ COPY │  │PASTE │  ]   │  N   │  M   │ , <  │ . >  │ / ?  │ DEL  │
 * └──────┴──────┴──────┼──────┼──────┼──────┼──────┼──────┤  ├──────┼──────┼──────┼──────┼──────┼──────┴──────┴──────┘
 *                      │  🔇  │  L◆  │Space/│ NUM  │ ⎈+⇧  │  │ ⎈+⇧  │ SYM  │ ⏎/⇧  │  R◆  │  ⏯  │
 *                      │      │      │      │      │      │  │      │      │      │      │      │
 *                      └──────┴──────┴──────┴──────┴──────┘  └──────┴──────┴──────┴──────┴──────┘
 *                                                                               generated by [keymapviz] */
    [_BASE] = LAYOUT(
     KC_TAB  , KC_Q   , KC_W    , KC_E   , KC_R   , KC_T   ,                                         KC_Y   , KC_U   , KC_I   , KC_O    , KC_P     , KC_BSPC,
     ESC_CAP, HOME_A  , HOME_S  , KC_D   , HOME_F ,  KC_G  ,                                         KC_H   , HOME_J , KC_K   , HOME_L  , HOME_SCLN, KC_QUOT,
     KC_LSFT , KC_Z   , KC_X    , KC_C   , KC_V   , KC_B   , KC_LBRC, KC_COPY,     KC_PSTE, KC_RBRC, KC_N   , KC_M   , KC_COMM, KC_DOT  , KC_SLSH  , KC_DEL ,
                               KC_KB_MUTE, KC_LGUI,LSFT_SPC, TD(TD_NUM)    , CC_CLSH,     CC_CLSH, TD(TD_SYM)    ,LSFT_ENT, KC_RGUI, KC_MPLY
    ),
    [_COLEMAK_DH] = LAYOUT(
     KC_TAB  , KC_Q   , KC_W   , KC_F   , KC_P   , KC_B,                                          KC_J   , KC_L   , KC_U   , KC_Y   , KC_SCLN, KC_BSPC,
     ESC_CAP,  HOME_A , HOME_R , KC_S   , HOME_T , KC_G ,                                         KC_M   , HOME_N , KC_E   , HOME_I , HOME_O,  KC_QUOT,
     KC_LSFT , KC_Z   , KC_X   , KC_C   , KC_D   , KC_V, KC_LBRC, KC_COPY,     KC_PSTE, KC_RBRC,  KC_K   , KC_H   , KC_COMM, KC_DOT , KC_SLSH, KC_DEL ,
                               KC_KB_MUTE, KC_LGUI,LSFT_SPC, TD(TD_NUM)    , CC_CLSH,     CC_CLSH, TD(TD_SYM)    ,LSFT_ENT, KC_RGUI, KC_MPLY
    ),

/* ┌──────┬──────┬──────┬──────┬──────┬──────┐                              ┌──────┬──────┬──────┬──────┬──────┬──────┐
 * │      │  Q   │  W   │  E   │  R   │  T   │                              │  Y   │  U   │  I   │  O   │  P   │      │
 * ├──────┼──────┼──────┼──────┼──────┼──────┤                              ├──────┼──────┼──────┼──────┼──────┼──────┤
 * │      │  A   │  S   │  D   │  F   │  G   │                              │  H   │  J   │  K   │  L   │      │      │
 * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┬──────┐  ┌──────┬──────┼──────┼──────┼──────┼──────┼──────┼──────┤
 * │      │  Z   │  X   │  C   │  V   │  B   │      │UC_NEX│  │UC_PRE│      │  N   │  M   │      │      │      │      │
 * └──────┴──────┴──────┼──────┼──────┼──────┼──────┼──────┤  ├──────┼──────┼──────┼──────┼──────┼──────┴──────┴──────┘
 *                      │      │      │Space │ NUM  │      │  │      │      │ ENT  │      │      │
 *                      │      │      │      │      │      │  │      │      │      │      │      │
 *                      └──────┴──────┴──────┴──────┴──────┘  └──────┴──────┴──────┴──────┴──────┘
 *                                                                               generated by [keymapviz] */
    [_UCIS] = LAYOUT(
     XXXXXXX, KC_Q   , KC_W    , KC_E   , KC_R   , KC_T   ,                                         KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , XXXXXXX,
     XXXXXXX, KC_A   , KC_S    , KC_D   , KC_F   , KC_G   ,                                         KC_H   , KC_J   , KC_K   , KC_L   , XXXXXXX, XXXXXXX,
     XXXXXXX, KC_Z   , KC_X    , KC_C   , KC_V   , KC_B   , XXXXXXX, UC_NEXT,     UC_PREV, XXXXXXX, KC_N   , KC_M   , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                 XXXXXXX, XXXXXXX, KC_SPC , NUM    , XXXXXXX,     XXXXXXX, XXXXXXX, KC_ENT , XXXXXXX, XXXXXXX
    ),

/* ┌──────┬──────┬──────┬──────┬──────┬──────┐                              ┌──────┬──────┬──────┬──────┬──────┬──────┐
 * │  `   │  !   │  @   │  #   │  $   │  %   │                              │  ^   │  &   │  {   │  }   │  *   │  =   │
 * ├──────┼──────┼──────┼──────┼──────┼──────┤                              ├──────┼──────┼──────┼──────┼──────┼──────┤
 * │  ~   │  α   │  β   │  δ   │  π   │ \ `  │                              │ - _  │  =   │  (   │  )   │ ' "  │  +   │
 * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┬──────┐  ┌──────┬──────┼──────┼──────┼──────┼──────┼──────┼──────┤
 * │  |   │  γ   │  σ   │  ρ   │  🐍  │ | ~  │  {   │      │  │      │  }   │  _   │  +   │  [   │  ]   │  ~   │  ?   │
 * └──────┴──────┴──────┼──────┼──────┼──────┼──────┼──────┤  ├──────┼──────┼──────┼──────┼──────┼──────┴──────┴──────┘
 *                      │      │      │CC_SHL│ NAV  │      │  │      │      │      │      │      │
 *                      │      │      │      │      │      │  │      │      │      │      │      │
 *                      └──────┴──────┴──────┴──────┴──────┘  └──────┴──────┴──────┴──────┴──────┘
 *                                                                               generated by [keymapviz] */
    [_SYMBOLS] = LAYOUT(
      KC_GRV , KC_EXLM, KC_AT  , KC_HASH, KC_DLR , KC_PERC,                                     KC_CIRC, KC_AMPR, KC_LCBR, KC_RCBR, KC_ASTR, KC_EQL ,
     KC_TILD , CC_ALPH, CC_BETA, CC_DELT, CC_PI  , TD_BSLS,                                     KC_MINS, KC_EQL , KC_LPRN, KC_RPRN, KC_QUOT, KC_PLUS,
     KC_PIPE , CC_GAMM, CC_SIGM, CC_RHO , CC_SNEK, TD_PIPE, KC_LCBR,  XXXXXXX, XXXXXXX, KC_RCBR, KC_UNDS, KC_PLUS, KC_LBRC, KC_RBRC, KC_TILD, KC_QUES,
                                 XXXXXXX, XXXXXXX, CC_SHLD, MO(_NAV), XXXXXXX, XXXXXXX, TG(_SYMBOLS), XXXXXXX, XXXXXXX, XXXXXXX
    ),

/* ┌──────┬──────┬──────┬──────┬──────┬──────┐                              ┌──────┬──────┬──────┬──────┬──────┬──────┐
 * │      │      │Sat ↑ │Hue ↑ │Val ↑ │RGB ↻ │                              │  *   │  7   │  8   │  9   │ - _  │      │
 * ├──────┼──────┼──────┼──────┼──────┼──────┤                              ├──────┼──────┼──────┼──────┼──────┼──────┤
 * │      │RGB ⏼ │Sat ↓ │Hue ↓ │Val ↓ │RGB ↺ │                              │ / ?  │  4   │  5   │  6   │  +   │      │
 * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┬──────┐  ┌──────┬──────┼──────┼──────┼──────┼──────┼──────┼──────┤
 * │      │      │      │Tap ↑ │Tap ↓ │PrtTap│      │      │  │      │      │      │  1   │  2   │  3   │      │      │
 * └──────┴──────┴──────┼──────┼──────┼──────┼──────┼──────┤  ├──────┼──────┼──────┼──────┼──────┼──────┴──────┴──────┘
 *                      │      │      │      │      │      │  │      │ NAV  │  0   │      │      │
 *                      │      │      │      │      │      │  │      │      │      │      │      │
 *                      └──────┴──────┴──────┴──────┴──────┘  └──────┴──────┴──────┴──────┴──────┘
 *                                                                               generated by [keymapviz] */
    [_NUMPAD] = LAYOUT(
      XXXXXXX, DF(_COLEMAK_DH), RGB_SAI, RGB_HUI, RGB_VAI, RGB_MOD ,                                             KC_ASTR,      KC_7   , KC_8   , KC_9   , KC_MINS, XXXXXXX,
      XXXXXXX, RGB_TOG,         RGB_SAD, RGB_HUD, RGB_VAD, RGB_RMOD,                                             KC_SLSH,      KC_4   , KC_5   , KC_6   , KC_PLUS, XXXXXXX,
      XXXXXXX, DF(_BASE),       XXXXXXX, DT_UP  , DT_DOWN, DT_PRNT , XXXXXXX,     XXXXXXX,    XXXXXXX, XXXXXXX,  KC_COMM,      KC_1   , KC_2   , KC_3   , KC_DOT , XXXXXXX,
                                 XXXXXXX, XXXXXXX, XXXXXXX , TG(_NUMPAD), XXXXXXX,    XXXXXXX, MO(_NAV), RSFT_T(KC_0), XXXXXXX, XXXXXXX
    ),
/* ┌──────┬──────┬──────┬──────┬──────┬──────┐                              ┌──────┬──────┬──────┬──────┬──────┬──────┐
 * │      │  🔊  │  F7  │  F8  │  F9  │ F10  │                              │CapWrd│ COPY │PASTE │      │      │      │
 * ├──────┼──────┼──────┼──────┼──────┼──────┤                              ├──────┼──────┼──────┼──────┼──────┼──────┤
 * │      │  🔉  │  F4  │  F5  │  F6  │ F11  │                              │ ← ⇐  │ ↓ ⇓  │ ↑ ⇑  │ → ⇒  │ ' "  │      │
 * ├──────┼──────┼──────┼──────┼──────┼──────┼──────┬──────┐  ┌──────┬──────┼──────┼──────┼──────┼──────┼──────┼──────┤
 * │      │  🔇  │  F1  │  F2  │  F3  │ F12  │      │      │  │      │      │  ⏮  │  ⏯  │  ⏭  │      │      │      │
 * └──────┴──────┴──────┼──────┼──────┼──────┼──────┼──────┤  ├──────┼──────┼──────┼──────┼──────┼──────┴──────┴──────┘
 *                      │      │      │      │      │      │  │      │      │      │      │      │
 *                      │      │      │      │      │      │  │      │      │      │      │      │
 *                      └──────┴──────┴──────┴──────┴──────┘  └──────┴──────┴──────┴──────┴──────┘
 *                                                                               generated by [keymapviz] */
    [_NAV] = LAYOUT(
      XXXXXXX, KC_KB_VOLUME_UP  , KC_F7  , KC_F8  , KC_F9  , KC_F10 ,                              TD(TD_CAPWORD), KC_COPY, KC_PSTE, XXXXXXX, XXXXXXX, XXXXXXX,
      XXXXXXX, KC_KB_VOLUME_DOWN, KC_F4  , KC_F5  , KC_F6  , KC_F11 ,                                     TD_LEFT, TD_DOWN, TD_UP  , TD_RGHT, KC_QUOT, XXXXXXX,
      XXXXXXX, KC_KB_MUTE       , KC_F1  , KC_F2  , KC_F3  , KC_F12 , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX, XXXXXXX, XXXXXXX,
                                  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
    ),
    [_MOUSE] = LAYOUT(
      XXXXXXX, XXXXXXX, KC_WH_L,    KC_MS_U, KC_WH_R, XXXXXXX,                                                  LGUI(KC_LBRC), LCTL(LSFT(KC_TAB)),   RCTL(KC_TAB),       LGUI(KC_RBRC), _______ , XXXXXXX,
      XXXXXXX, XXXXXXX, KC_MS_L,    KC_MS_D, KC_MS_R, MT(MOD_LGUI,KC_DEL),                                      XXXXXXX,       MT(MOD_RGUI,KC_DOWN), MT(MOD_RALT,KC_UP), XXXXXXX,       KC_ENTER,  XXXXXXX,
      XXXXXXX, XXXXXXX, KC_MS_BTN2, KC_WH_U, KC_WH_D, _______,     XXXXXXX,    XXXXXXX,       XXXXXXX, XXXXXXX, KC_MS_BTN1,    KC_MS_ACCEL0,         KC_MS_ACCEL1,       KC_MS_ACCEL2,  XXXXXXX , XXXXXXX,
                                    XXXXXXX, XXXXXXX, TO(_NUMPAD), TG(_MOUSE), XXXXXXX,       XXXXXXX, KC_RALT, TO(_SYMBOLS),  XXXXXXX,              XXXXXXX
    ),


// /*
//  * Layer template
//  *
//  * ,-------------------------------------------.                              ,-------------------------------------------.
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
//  * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        `----------------------------------'  `----------------------------------'
//  */
//     [_LAYERINDEX] = LAYOUT(
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
//                                  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
//     ),
};

/* The default OLED and rotary encoder code can be found at the bottom of qmk_firmware/keyboards/splitkb/kyria/rev1/rev1.c
 * These default settings can be overriden by your own settings in your keymap.c
 * For your convenience, here's a copy of those settings so that you can uncomment them if you wish to apply your own modifications.
 * DO NOT edit the rev1.c file; instead override the weakly defined default functions by your own.
 */

/* DELETE THIS LINE TO UNCOMMENT (1/2)
#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) { return OLED_ROTATION_180; }

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        // QMK Logo and version information
        // clang-format off
        static const char PROGMEM qmk_logo[] = {
            0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
            0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
            0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0};
        // clang-format on

        oled_write_P(qmk_logo, false);
        oled_write_P(PSTR("Kyria rev1.0\n\n"), false);

        // Host Keyboard Layer Status
        oled_write_P(PSTR("Layer: "), false);
        switch (get_highest_layer(layer_state|default_layer_state)) {
            case _QWERTY:
                oled_write_P(PSTR("QWERTY\n"), false);
                break;
            case _DVORAK:
                oled_write_P(PSTR("Dvorak\n"), false);
                break;
            case _COLEMAK_DH:
                oled_write_P(PSTR("Colemak-DH\n"), false);
                break;
            case _NAV:
                oled_write_P(PSTR("Nav\n"), false);
                break;
            case _SYM:
                oled_write_P(PSTR("Sym\n"), false);
                break;
            case _FUNCTION:
                oled_write_P(PSTR("Function\n"), false);
                break;
            case _ADJUST:
                oled_write_P(PSTR("Adjust\n"), false);
                break;
            default:
                oled_write_P(PSTR("Undefined\n"), false);
        }

        // Write host Keyboard LED Status to OLEDs
        led_t led_usb_state = host_keyboard_led_state();
        oled_write_P(led_usb_state.num_lock    ? PSTR("NUMLCK ") : PSTR("       "), false);
        oled_write_P(led_usb_state.caps_lock   ? PSTR("CAPLCK ") : PSTR("       "), false);
        oled_write_P(led_usb_state.scroll_lock ? PSTR("SCRLCK ") : PSTR("       "), false);
    } else {
        // clang-format off
        static const char PROGMEM kyria_logo[] = {
            0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,128,192,224,240,112,120, 56, 60, 28, 30, 14, 14, 14,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7, 14, 14, 14, 30, 28, 60, 56,120,112,240,224,192,128,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
            0,  0,  0,  0,  0,  0,  0,192,224,240,124, 62, 31, 15,  7,  3,  1,128,192,224,240,120, 56, 60, 28, 30, 14, 14,  7,  7,135,231,127, 31,255,255, 31,127,231,135,  7,  7, 14, 14, 30, 28, 60, 56,120,240,224,192,128,  1,  3,  7, 15, 31, 62,124,240,224,192,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
            0,  0,  0,  0,240,252,255, 31,  7,  1,  0,  0,192,240,252,254,255,247,243,177,176, 48, 48, 48, 48, 48, 48, 48,120,254,135,  1,  0,  0,255,255,  0,  0,  1,135,254,120, 48, 48, 48, 48, 48, 48, 48,176,177,243,247,255,254,252,240,192,  0,  0,  1,  7, 31,255,252,240,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
            0,  0,  0,255,255,255,  0,  0,  0,  0,  0,254,255,255,  1,  1,  7, 30,120,225,129,131,131,134,134,140,140,152,152,177,183,254,248,224,255,255,224,248,254,183,177,152,152,140,140,134,134,131,131,129,225,120, 30,  7,  1,  1,255,255,254,  0,  0,  0,  0,  0,255,255,255,  0,  0,  0,  0,255,255,  0,  0,192,192, 48, 48,  0,  0,240,240,  0,  0,  0,  0,  0,  0,240,240,  0,  0,240,240,192,192, 48, 48, 48, 48,192,192,  0,  0, 48, 48,243,243,  0,  0,  0,  0,  0,  0, 48, 48, 48, 48, 48, 48,192,192,  0,  0,  0,  0,  0,
            0,  0,  0,255,255,255,  0,  0,  0,  0,  0,127,255,255,128,128,224,120, 30,135,129,193,193, 97, 97, 49, 49, 25, 25,141,237,127, 31,  7,255,255,  7, 31,127,237,141, 25, 25, 49, 49, 97, 97,193,193,129,135, 30,120,224,128,128,255,255,127,  0,  0,  0,  0,  0,255,255,255,  0,  0,  0,  0, 63, 63,  3,  3, 12, 12, 48, 48,  0,  0,  0,  0, 51, 51, 51, 51, 51, 51, 15, 15,  0,  0, 63, 63,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 48, 48, 63, 63, 48, 48,  0,  0, 12, 12, 51, 51, 51, 51, 51, 51, 63, 63,  0,  0,  0,  0,  0,
            0,  0,  0,  0, 15, 63,255,248,224,128,  0,  0,  3, 15, 63,127,255,239,207,141, 13, 12, 12, 12, 12, 12, 12, 12, 30,127,225,128,  0,  0,255,255,  0,  0,128,225,127, 30, 12, 12, 12, 12, 12, 12, 12, 13,141,207,239,255,127, 63, 15,  3,  0,  0,128,224,248,255, 63, 15,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
            0,  0,  0,  0,  0,  0,  0,  3,  7, 15, 62,124,248,240,224,192,128,  1,  3,  7, 15, 30, 28, 60, 56,120,112,112,224,224,225,231,254,248,255,255,248,254,231,225,224,224,112,112,120, 56, 60, 28, 30, 15,  7,  3,  1,128,192,224,240,248,124, 62, 15,  7,  3,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
            0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  3,  7, 15, 14, 30, 28, 60, 56,120,112,112,112,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,112,112,112,120, 56, 60, 28, 30, 14, 15,  7,  3,  1,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0
        };
        // clang-format on
        oled_write_raw_P(kyria_logo, sizeof(kyria_logo));
    }
    return false;
}
#endif

#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {

    if (index == 0) {
        // Volume control
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    } else if (index == 1) {
        // Page up/Page down
        if (clockwise) {
            tap_code(KC_PGDN);
        } else {
            tap_code(KC_PGUP);
        }
    }
    return false;
}
#endif
DELETE THIS LINE TO UNCOMMENT (2/2) */
