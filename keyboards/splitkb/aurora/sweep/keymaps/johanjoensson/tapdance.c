enum {
        TD_LEFT_HOME = 0,
        TD_DOWN_PGDN,
        TD_UP_PGUP,
        TD_RGHT_END,
        TD_ESC_CAPS,
        TD_BSLS_GRV,
        TD_PIPE_TILD
};


typedef struct{
    uint16_t tap;
    uint16_t hold;
    uint16_t held;
} tap_dance_tap_hold_t;


uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        default:
            return TAPPING_TERM;
    }
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
        [TD_ESC_CAPS]   = ACTION_TAP_DANCE_DOUBLE(KC_ESC, KC_CAPS),
        [TD_BSLS_GRV]   = ACTION_TAP_DANCE_DOUBLE(KC_BSLS, KC_GRV),
        [TD_PIPE_TILD]   = ACTION_TAP_DANCE_DOUBLE(KC_PIPE, KC_TILD)
};

