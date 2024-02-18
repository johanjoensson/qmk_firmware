#include QMK_KEYBOARD_H
#include "johanjoensson.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
        KC_GRV,  KC_1   , KC_2   , KC_3   , KC_4   , KC_5,                                 KC_6    , KC_7   , KC_8   , KC_9  , KC_0     , KC_GRV ,
        KC_TAB , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,                              KC_Y    , KC_U   , KC_I   , KC_O  , KC_P     , KC_BSPC,
        ESC_CAP, HOME_A , HOME_S , KC_D   , HOME_F , KC_G  ,                               KC_H    , HOME_J , KC_K   , HOME_L, HOME_SCLN, KC_QUOT,
        KC_LSFT, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B, KC_KB_MUTE,         XXXXXXX,    KC_N    , KC_M   , KC_COMM, KC_DOT, KC_SLSH  ,  KC_RSFT,
                          KC_LGUI, KC_LALT, CC_CLSH, LSFT_SPC, TD(TD_NUM),     TD(TD_SYM), LSFT_ENT, CC_CLSH, KC_RALT, KC_RGUI

    ),
    [_COLEMK_DH] = LAYOUT(
        KC_GRV,  KC_1   , KC_2   , KC_3   , KC_4   , KC_5,                                 KC_6    , KC_7   , KC_8   , KC_9  , KC_0     , KC_GRV ,
        KC_TAB , KC_Q   , KC_W   , KC_F   , KC_P   , KC_B   ,                              KC_J   , KC_L   , KC_U   , KC_Y   , KC_SCLN,   KC_BSPC,
        ESC_CAP, HOME_A , HOME_R , KC_S   , HOME_T , KC_G  ,                               KC_M   , HOME_N , KC_E   , HOME_I , HOME_O,    KC_QUOT,
        KC_LSFT, KC_Z   , KC_X   , KC_C   , KC_D   , KC_V, KC_KB_MUTE,         XXXXXXX,    KC_K   , KC_H   , KC_COMM, KC_DOT , KC_SLSH,   KC_RSFT,
                          KC_LGUI, KC_LALT, CC_CLSH, LSFT_SPC, TD(TD_NUM),     TD(TD_SYM), LSFT_ENT, CC_CLSH, KC_RALT, KC_RGUI

    ),
    [_UCIS] = LAYOUT(
        XXXXXXX, KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,                          KC_6    , KC_7   , KC_8   , KC_9   , KC_0   , XXXXXXX,
        XXXXXXX, KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,                          KC_Y    , KC_U   , KC_I   , KC_O   , KC_P   , XXXXXXX,
        XXXXXXX, KC_A   , KC_S   , KC_D   , KC_F   , KC_G   ,                          KC_H    , KC_J   , KC_K   , KC_L   , XXXXXXX, XXXXXXX,
        XXXXXXX, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , _______,        _______, KC_N    , KC_M   , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                          XXXXXXX, XXXXXXX, XXXXXXX, KC_SPC , MO(_NUMPAD),    XXXXXXX, KC_ENT  , XXXXXXX, XXXXXXX, XXXXXXX

    ),
    [_SYMBOLS] = LAYOUT(
       _______,  _______, _______, _______, _______, _______,                           _______, _______, _______, _______, _______, _______,
       KC_GRV ,  KC_EXLM, KC_AT  , KC_HASH, KC_DLR , KC_PERC,                           KC_CIRC, KC_AMPR, KC_LCBR, KC_RCBR, KC_ASTR, KC_EQL ,
       KC_TILD,  CC_ALPH, CC_BETA, CC_DELT, CC_PI  , TD_BSLS,                           KC_MINS, KC_EQL , KC_LPRN, KC_RPRN, KC_QUOT, KC_PLUS,
       KC_PIPE , CC_GAMM, CC_SIGM, CC_RHO , CC_SNEK, TD_PIPE, _______,    _______,      KC_UNDS, KC_PLUS, KC_LBRC, KC_RBRC, KC_TILD, KC_QUES,
                          _______, _______, CC_CLSH, CC_SHLD, MO(_NAV),   TG(_SYMBOLS), KC_RSFT, CC_CLSH, XXXXXXX, XXXXXXX

    ),
    [_NUMPAD] = LAYOUT(
      _______, _______, _______, _______, _______, _______,                          _______, _______, _______, _______, _______, _______,
      XXXXXXX, DF(_COLEMAK_DH), RGB_SAI, RGB_HUI, RGB_VAI, RGB_MOD ,                         KC_ASTR, KC_7   , KC_8   , KC_9   , KC_MINS, XXXXXXX,
      XXXXXXX, RGB_TOG,         RGB_SAD, RGB_HUD, RGB_VAD, RGB_RMOD,                         KC_SLSH, KC_4   , KC_5   , KC_6   , KC_PLUS, XXXXXXX,
      XXXXXXX, DF(_BASE),       XXXXXXX, DT_UP  , DT_DOWN, DT_PRNT , _______,      XXXXXXX,  XXXXXXX, KC_1   , KC_2   , KC_3   , XXXXXXX, XXXXXXX,
                        XXXXXXX, XXXXXXX, XXXXXXX, _______ , TG(_NUMPAD),  MO(_NAV), XXXXXXX, RSFT_T(KC_0), XXXXXXX, XXXXXXX
    ),
    [_NAV] = LAYOUT(
      _______, _______, _______, _______, _______, _______,                              _______, _______, _______, _______, _______, _______,
      XXXXXXX, KC_KB_VOLUME_UP  , KC_F7  , KC_F8  , KC_F9  , KC_F10 ,             TD(TD_CAPWORD), KC_COPY, KC_PSTE, XXXXXXX, XXXXXXX, XXXXXXX,
      XXXXXXX, KC_KB_VOLUME_DOWN, KC_F4  , KC_F5  , KC_F6  , KC_F11 ,                    TD_LEFT, TD_DOWN, TD_UP  , TD_RGHT, KC_QUOT, XXXXXXX,
      XXXXXXX, KC_KB_MUTE       , KC_F1  , KC_F2  , KC_F3  , KC_F12 , _______,  XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX, XXXXXXX, XXXXXXX,
                                  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
    ),

    [_MOUSE] = LAYOUT(
      _______,  _______,     _______,        _______,        _______,        _______,                                           _______,       _______,              _______,            _______,       _______,        _______,
      XXXXXXX,  XXXXXXX,     KC_WH_L,        KC_MS_U,        KC_WH_R,        XXXXXXX,                                           LGUI(KC_LBRC), LCTL(LSFT(KC_TAB)),   RCTL(KC_TAB),       LGUI(KC_RBRC), KC_TRANSPARENT, XXXXXXX,
      XXXXXXX,  XXXXXXX,     KC_MS_L,        KC_MS_D,        KC_MS_R,        MT(MOD_LGUI,KC_DEL),                               XXXXXXX,       MT(MOD_RGUI,KC_DOWN), MT(MOD_RALT,KC_UP), XXXXXXX,       KC_ENTER,       XXXXXXX,
      XXXXXXX,  XXXXXXX,     KC_MS_BTN2,     KC_WH_U,        KC_WH_D,        KC_TRANSPARENT, KC_MS_BTN1,           KC_MS_BTN2,  KC_MS_BTN1,    KC_MS_ACCEL0,         KC_MS_ACCEL1,       KC_MS_ACCEL2,  KC_NO,          XXXXXXX,
                             XXXXXXX,        XXXXXXX,        XXXXXXX,        TO(_NUMPAD),    TG(_MOUSE),           TG(_MOUSE),  TO(_SYMBOLS),  XXXXXXX,              XXXXXXX,            XXXXXXX
    ),
};

#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
    // 0 is left-half encoder
    // 1 is right-half encoder
    switch (index){
            case 0:
                    if(layer_state_is(_MOUSE)){
                            if (clockwise) {
                                    tap_code(KC_MS_DOWN);
                            } else {
                                    tap_code(KC_MS_UP);
                            }
                    } else {
                            if (clockwise) {
                                    tap_code(KC_KB_VOLUME_UP);
                            } else {
                                    tap_code(KC_KB_VOLUME_DOWN);
                            }
                    }
                    break;
            case 1:
                    if(layer_state_is(_MOUSE)){
                            if (clockwise) {
                                    tap_code(KC_MS_RIGHT);
                            } else {
                                    tap_code(KC_MS_LEFT);
                            }
                    } else {
                            if (clockwise) {
                                    tap_code(KC_PGUP);
                            } else {
                                    tap_code(KC_PGDN);
                            }
                    }
                    break;
            default:
                    break;
    }

    return false;
}
#endif
