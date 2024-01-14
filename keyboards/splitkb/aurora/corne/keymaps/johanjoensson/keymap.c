#include QMK_KEYBOARD_H
#include "johanjoensson.h"

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_split_3x6_3(
     KC_TAB  , KC_Q   , KC_W    , KC_E   , KC_R   , KC_T  ,                                        KC_Y   , KC_U   , KC_I   , KC_O    , KC_P     , KC_BSPC,
     ESC_CAP, HOME_A  , HOME_S  , KC_D   , HOME_F , KC_G  ,                                        KC_H   , HOME_J , KC_K   , HOME_L  , HOME_SCLN, KC_QUOT,
     KC_LSFT , KC_Z   , KC_X    , KC_C   , KC_V   , KC_B  ,                                        KC_N   , KC_M   , KC_COMM, KC_DOT  , KC_SLSH  , KC_DEL ,
                                           CC_CLSH, LSFT_SPC, NUM ,                       SYM    ,LSFT_ENT, CC_CLSH
    ),

    [_UCIS] = LAYOUT_split_3x6_3(
     XXXXXXX, KC_Q   , KC_W    , KC_E   , KC_R   , KC_T   ,                                         KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , XXXXXXX,
     XXXXXXX, KC_A   , KC_S    , KC_D   , KC_F   , KC_G   ,                                         KC_H   , KC_J   , KC_K   , KC_L   , XXXXXXX, XXXXXXX,
     XXXXXXX, KC_Z   , KC_X    , KC_C   , KC_V   , KC_B   ,                                         KC_N   , KC_M   , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                          XXXXXXX,KC_SPC , NUM    ,                        XXXXXXX, KC_ENT, XXXXXXX
    ),

    [_SYMBOLS] = LAYOUT_split_3x6_3(
      KC_GRV , KC_EXLM, KC_AT  , KC_HASH, KC_DLR , KC_PERC,                                     KC_CIRC, KC_AMPR, KC_LCBR, KC_RCBR, KC_ASTR, KC_EQL ,
     KC_TILD , CC_ALPH, CC_BETA, CC_DELT, CC_PI  , TD_BSLS,                                     KC_MINS, KC_EQL , KC_LPRN, KC_RPRN, KC_QUOT, KC_PLUS,
     KC_PIPE , CC_GAMM, CC_SIGM, CC_RHO , CC_SNEK, TD_PIPE,                                     KC_UNDS, KC_PLUS, KC_LBRC, KC_RBRC, KC_TILD, KC_QUES,
                                          XXXXXXX,CC_SHLD, NAV    ,                   XXXXXXX, XXXXXXX, XXXXXXX         
    ),

    [_NUMPAD] = LAYOUT_split_3x6_3(
      XXXXXXX, XXXXXXX, RGB_SAI, RGB_HUI, RGB_VAI, RGB_MOD ,                                     KC_ASTR, KC_7   , KC_8   , KC_9   , KC_MINS, XXXXXXX,
      XXXXXXX, RGB_TOG, RGB_SAD, RGB_HUD, RGB_VAD, RGB_RMOD,                                     KC_SLSH, KC_4   , KC_5   , KC_6   , KC_PLUS, XXXXXXX,
      XXXXXXX, XXXXXXX, XXXXXXX, DT_UP  , DT_DOWN, DT_PRNT ,                                     XXXXXXX, KC_1   , KC_2   , KC_3   , XXXXXXX, XXXXXXX,
                                          XXXXXXX, XXXXXXX , XXXXXXX,                   NAV    , KC_0, XXXXXXX
    ),
    [_NAV] = LAYOUT_split_3x6_3(
      XXXXXXX, KC_KB_VOLUME_UP  , KC_F7  , KC_F8  , KC_F9  , KC_F10 ,                                     CW_TOGG, KC_COPY, KC_PSTE, XXXXXXX, XXXXXXX, XXXXXXX,
      XXXXXXX, KC_KB_VOLUME_DOWN, KC_F4  , KC_F5  , KC_F6  , KC_F11 ,                                     TD_LEFT, TD_DOWN, TD_UP  , TD_RGHT, KC_QUOT, XXXXXXX,
      XXXXXXX, KC_KB_MUTE       , KC_F1  , KC_F2  , KC_F3  , KC_F12 ,                                     KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX, XXXXXXX, XXXXXXX,
                                                    XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX
    ),


// /*
//  * Layer template
//  *
//  * ,-------------------------------------------.                              ,-------------------------------------------.
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * `-----------------------------+------+------+------.                ,------+------+------+-----------------------------'
//  *                               |      |      |      |                |      |      |      |
//  *                               |      |      |      |                |      |      |      |
//  *                               ---------------------'                `--------------------'
//  */
//     [_LAYERINDEX] = LAYOUT(
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//                                           _______, _______, _______,                   _______, _______, _______         
//     ),
};
