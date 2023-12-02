#pragma once
#include QMK_KEYBOARD_H
#include "johanjoensson.h"

typedef struct{
    uint16_t tap;
    uint16_t hold;
    uint16_t held;
} tap_dance_tap_hold_t;

#define ACTION_TAP_DANCE_TAP_HOLD(tap, hold) \
    { .fn = {NULL, tap_dance_tap_hold_finished, tap_dance_tap_hold_reset}, .user_data = (void *)&((tap_dance_tap_hold_t){tap, hold, 0}), }


#define ACTION_TAP_DANCE_TAP_HOLD_LAYER(tap, hold) \
    { .fn = {NULL, tap_dance_tap_hold_finished, tap_dance_tap_hold_reset}, .user_data = (void *)&((tap_dance_tap_hold_t){tap, hold, 0}), }


tap_dance_action_t tap_dance_actions[] = {
        [TD_LEFT_HOME] = ACTION_TAP_DANCE_DOUBLE(KC_LEFT, KC_HOME),
        [TD_DOWN_PGDN] = ACTION_TAP_DANCE_DOUBLE(KC_DOWN, KC_PGDN),
        [TD_UP_PGUP]   = ACTION_TAP_DANCE_DOUBLE(KC_UP, KC_PGUP),
        [TD_RGHT_END]   = ACTION_TAP_DANCE_DOUBLE(KC_RGHT, KC_END),
        [TD_ESC_CAPS]   = ACTION_TAP_DANCE_DOUBLE(KC_ESC, KC_CAPS),
        [TD_BSLS_GRV]   = ACTION_TAP_DANCE_DOUBLE(KC_BSLS, KC_GRV),
        [TD_PIPE_TILD]   = ACTION_TAP_DANCE_DOUBLE(KC_PIPE, KC_TILD)
};
