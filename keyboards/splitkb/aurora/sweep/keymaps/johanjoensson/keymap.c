#include QMK_KEYBOARD_H

// enum keycodes {
//         //NEW_CODE = SAFE_RANGE,
// };

enum layer_names{
        BASE = 0,
        CONTROL,
        NUMBERS,
        SYMBOLS,
        NUMPAD,
        FUNCTION,
        RGBS,
        UNUSED_3,
        UNUSED_4,
        UNUSED_5,
        UNUSED_6,
        UNUSED_7,
        UNUSED_8,
        UNUSED_9,
        UNUSED_10,
        UNUSED_11
};

#ifdef TAP_DANCE_ENABLE
        #include "tapdance.c"
        #define ESC_CAP TD(TD_ESC_CAPS)
        #define TD_LEFT TD(TD_LEFT_HOME) 
        #define TD_DOWN TD(TD_DOWN_PGDN) 
        #define TD_UP   TD(TD_UP_PGUP)
        #define TD_RGHT TD(TD_RGHT_END)
        #define TD_BSLS TD(TD_BSLS_GRV)
        #define TD_PIPE TD(TD_PIPE_TILD)
#else
        #define ESC_CAP KC_ESC
        #define TD_LEFT KC_LEFT
        #define TD_DOWN KC_DOWN
        #define TD_UP   KC_UP
        #define TD_RGHT KC_RGHT
        #define TD_BSLS KC_BSLS
        #define TD_PIPE KC_PIPE
#endif
#ifdef UNICODEMAP_ENABLE
        #include "unicode_map.c"
#endif
#ifdef UCIS_ENABLE
        #include "ucis.c"
#endif
#ifdef LEADER_ENABLE
        #include "leader.c"
#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[BASE] = LAYOUT(
                        KC_Q,                  KC_W,                  KC_E,                  KC_R,                  KC_T,                               KC_Y, KC_U,                  KC_I,                  KC_O,                  KC_P,
                        MT(MOD_LGUI, KC_A),    MT(MOD_LALT, KC_S),    MT(MOD_LSFT, KC_D),    MT(MOD_LCTL, KC_F),    KC_G,                               KC_H, MT(MOD_LCTL, KC_J),    MT(MOD_RSFT, KC_K),    MT(MOD_LALT, KC_L),    MT(MOD_RGUI, KC_SCLN),
                        KC_Z,                  KC_X,                  KC_C,                  KC_V,                  KC_B,                               KC_N, KC_M,                  KC_COMM,               KC_DOT,                KC_SLSH,
                                                                                                                    LT(CONTROL, KC_SPC), MO(NUMBERS),   MO(SYMBOLS), LT(CONTROL, KC_ENT)
                                                                                                                    ),
	[CONTROL] = LAYOUT(
                        KC_TAB , _______, _______, _______, _______,                             _______, _______, _______, _______, KC_BSPC,
                        ESC_CAP, _______, _______, _______, _______,                             _______, _______, _______, _______, KC_QUOT,
                        _______, _______, _______, _______, _______,                             _______, _______, _______, _______, _______,
                                                            CW_TOGG, _______,           _______, CW_TOGG
                                                             ),
	[NUMBERS] = LAYOUT(
                        KC_1,    KC_2,     KC_3,    KC_4,    KC_5,                               KC_6   , KC_7   , KC_8   , KC_9   , KC_0   ,
                        _______, _______, _______, _______, _______,                             TD_LEFT, TD_DOWN, TD_UP  , TD_RGHT, _______,
                        _______, _______, _______, _______, _______,                             _______, _______, _______, _______, _______,
                                                            _______, _______,        MO(NUMPAD), _______
                                                             ),
	[SYMBOLS] = LAYOUT(
                        KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                             KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,
                        _______, _______, _______, _______, _______,                             KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, TD_BSLS,
                        _______, _______, _______, _______, _______,                             KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, TD_PIPE,
                                                            QK_LEAD,  MO(NUMPAD),       _______, _______
                                                           ),
	[NUMPAD] = LAYOUT(
                        TG(RGBS),      _______, _______, _______, _______,                             _______, KC_7, KC_8, KC_9, KC_0,
                        OSL(FUNCTION), _______, DT_UP  , DT_DOWN, DT_PRNT,                             KC_PLUS, KC_4, KC_5, KC_6, KC_ASTR,
                        _______,       _______, _______, _______, _______,                             KC_MINS, KC_1, KC_2, KC_3, KC_SLSH,
                                                                  _______, _______,           _______, _______
                                                            ),
	[FUNCTION] = LAYOUT(
                        _______, KC_F7  , KC_F8  , KC_F9  , KC_F10 ,                           _______, _______, _______, _______, _______,
                        _______, KC_F4  , KC_F5  , KC_F6  , KC_F11 ,                           _______, _______, _______, _______, _______,
                        _______, KC_F1  , KC_F2  , KC_F3  , KC_F12 ,                           _______, _______, _______, _______, _______,
                                                            _______, _______,         _______, _______
                                                            ),
	[RGBS] = LAYOUT(
                        TG(RGBS),XXXXXXX, RGB_SAI , RGB_SAD , RGB_MOD,                           XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                        RGB_TOG, XXXXXXX, RGB_HUI , RGB_HUD , RGB_RMOD,                          XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                        XXXXXXX, XXXXXXX, RGB_VAI , RGB_VAD , XXXXXXX,                           XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                                            XXXXXXX, XXXXXXX,         XXXXXXX, XXXXXXX
                                                            ),
};

#ifdef RGBLIGHT_ENABLE
#include "rgb_led.c"
#endif
#ifdef ENCODER_ENABLE
        #include "encoder.c"
#endif


layer_state_t layer_state_set_user(layer_state_t state) {
    return state;
}

uint8_t mod_state;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
        mod_state = get_mods();
        switch (keycode) {
                // Left Shift + Backspace gives Delete
                case KC_BSPC:
                        static bool delkey_registered;
                        if (record->event.pressed) {
                                if (mod_state & MOD_MASK_SHIFT) {
                                        del_mods(MOD_MASK_SHIFT);
                                        register_code(KC_DEL);
                                        delkey_registered = true;
                                        set_mods(mod_state);
                                        return false;
                                }
                        } else {
                                if (delkey_registered) {
                                        unregister_code(KC_DEL);
                                        delkey_registered = false;
                                        return false;
                                }
                        }
                        return true;
                        break;
                default:
                        break;
        }
        return true;
}


void post_process_record_user(uint16_t keycode, keyrecord_t *record){}

uint16_t keycode_config(uint16_t keycode) {
    return keycode;
}

uint8_t mod_config(uint8_t mod) {
    return mod;
}
