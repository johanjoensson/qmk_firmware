#include QMK_KEYBOARD_H

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case SFT_T(KC_SPC):
            return TAPPING_TERM + 1250;
        case LT(1, KC_GRV):
            return 130;
        default:
            return TAPPING_TERM;
    }
}

enum layer_names{
        BASE = 0,
        NUMBERS,
        SYMBOLS,
        NUMPAD,
        FUNCTION,
        UNUSED_2,
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

enum {
        TD_LEFT_HOME = 0,
        TD_DOWN_PGDN,
        TD_UP_PGUP,
        TD_RGHT_END,
        TD_ESC_CAPS
};


typedef struct{
    uint16_t tap;
    uint16_t hold;
    uint16_t held;
} tap_dance_tap_hold_t;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // tap_dance_action_t *action;
    // switch (keycode) {
    //     case TD(CT_CLN):  // list all tap dance keycodes with tap-hold configurations
    //         action = &tap_dance_actions[TD_INDEX(keycode)];
    //         if (!record->event.pressed && action->state.count && !action->state.finished) {
    //             tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
    //             tap_code16(tap_hold->tap);
    //         }
    // }
    return true;
}

void tap_dance_tap_hold_finished(tap_dance_state_t *state, void *user_data) {
    tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)user_data;

    if (state->pressed) {
        if (state->count == 1
#ifndef PERMISSIVE_HOLD
            && !state->interrupted
#endif
        ) {
            register_code16(tap_hold->hold);
            tap_hold->held = tap_hold->hold;
        } else {
            register_code16(tap_hold->tap);
            tap_hold->held = tap_hold->tap;
        }
    }
}

void tap_dance_tap_hold_reset(tap_dance_state_t *state, void *user_data) {
    tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)user_data;

    if (tap_hold->held) {
        unregister_code16(tap_hold->held);
        tap_hold->held = 0;
    }
}

#define ACTION_TAP_DANCE_TAP_HOLD(tap, hold) \
    { .fn = {NULL, tap_dance_tap_hold_finished, tap_dance_tap_hold_reset}, .user_data = (void *)&((tap_dance_tap_hold_t){tap, hold, 0}), }

#define ACTION_TAP_DANCE_TAP_HOLD_LAYER(tap, hold) \
    { .fn = {NULL, tap_dance_tap_hold_finished, tap_dance_tap_hold_reset}, .user_data = (void *)&((tap_dance_tap_hold_t){tap, hold, 0}), }

void dance_fn_numers(tap_dance_state_t *state, void *user_data) {
    switch(state->count){
        case 1:
            break;
    }
}

tap_dance_action_t tap_dance_actions[] = {
        [TD_LEFT_HOME] = ACTION_TAP_DANCE_DOUBLE(KC_LEFT, KC_HOME),
        [TD_DOWN_PGDN] = ACTION_TAP_DANCE_DOUBLE(KC_DOWN, KC_PGDN),
        [TD_UP_PGUP]   = ACTION_TAP_DANCE_DOUBLE(KC_UP, KC_PGUP),
        [TD_RGHT_END]   = ACTION_TAP_DANCE_DOUBLE(KC_RGHT, KC_END),
        [TD_ESC_CAPS]   = ACTION_TAP_DANCE_DOUBLE(KC_ESC, KC_CAPS)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[BASE] = LAYOUT_split_3x6_3(
                        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                                KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
                        TD(TD_ESC_CAPS),  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                       KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
                        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                                KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_LCTL,
                                                            KC_LGUI, LT(FUNCTION, KC_SPC), MO(NUMBERS),   MO(SYMBOLS),  KC_ENT,  KC_LALT
                                             ),
	[NUMBERS] = LAYOUT_split_3x6_3(
                        _______,  KC_1,    KC_2,    KC_3,     KC_4,   KC_5,                                KC_6,    KC_7,    KC_8,  KC_9,     KC_0,    KC_BSPC,
                        _______, _______, _______, _______, _______, _______,                             TD(TD_LEFT_HOME), TD(TD_DOWN_PGDN), TD(TD_UP_PGUP), TD(TD_RGHT_END), _______, _______,
                        _______, _______, _______, _______, _______, _______,                             _______, _______, _______, _______, _______, _______,
                                                            _______, _______,  _______,        MO(NUMPAD), _______,  _______
                                                     ),
	[SYMBOLS] = LAYOUT_split_3x6_3(
                        _______, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                             KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
                        _______, TD(TD_ESC_CAPS), _______, _______, _______, _______,                             KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS, KC_GRV,
                        _______, _______, _______, _______, _______, _______,                             KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, KC_TILD,
                                                            _______, QK_LEAD,  MO(NUMPAD),        _______, _______,  _______
                                                      ),
	[NUMPAD] = LAYOUT_split_3x6_3(
                        QK_BOOT, _______, _______, _______, _______, _______,                             _______, KC_7, KC_8, KC_9, KC_0,    _______,
                        _______, _______, _______, _______, _______, _______,                             KC_PLUS, KC_5, KC_5, KC_6, KC_ASTR, _______,
                        _______, _______, _______, _______, _______, _______,                             KC_MINS, KC_1, KC_2, KC_3, KC_SLSH, _______,
                                                             _______, _______, _______,           _______, _______,  _______
                                                    ),
	[FUNCTION] = LAYOUT_split_3x6_3(
                        _______, KC_F9  , KC_F10 , KC_F11 , KC_F12 , _______,                             _______, _______, _______, _______, _______, _______,
                        _______, KC_F5  , KC_F6  , KC_F7  , KC_F8  , _______,                             _______, _______, _______, _______, _______, _______,
                        _______, KC_F1  , KC_F2  , KC_F3  , KC_F4  , _______,                             _______, _______, _______, _______, _______, _______,
                                                             _______, _______, _______,           _______, _______,  _______
                                                    ),
	[UNUSED_2] = LAYOUT_split_3x6_3(
                        _______, _______, _______, _______, _______, _______,                             _______, _______, _______, _______, _______, _______,
                        _______, _______, _______, _______, _______, _______,                             _______, _______, _______, _______, _______, _______,
                        _______, _______, _______, _______, _______, _______,                             _______, _______, _______, _______, _______, _______,
                                                             _______, _______, _______,           _______, _______,  _______
                                                    )
};

#if defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
};
#endif // defined(ENCODER_ENABLE) && defined(ENCODER_MAP_ENABLE)





