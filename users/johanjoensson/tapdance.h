#pragma once
#include QMK_KEYBOARD_H
#include "johanjoensson.h"

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record);
void tap_dance_tap_hold_finished(tap_dance_state_t *state, void *user_data);
void tap_dance_tap_hold_reset(tap_dance_state_t *state, void *user_data);
void dance_fn_numbers(tap_dance_state_t *state, void *user_data);


tap_dance_action_t tap_dance_actions[] = {
        [TD_LEFT_HOME]  = ACTION_TAP_DANCE_DOUBLE(KC_LEFT, KC_HOME),
        [TD_DOWN_PGDN]  = ACTION_TAP_DANCE_DOUBLE(KC_DOWN, KC_PGDN),
        [TD_UP_PGUP]    = ACTION_TAP_DANCE_DOUBLE(KC_UP, KC_PGUP),
        [TD_RGHT_END]   = ACTION_TAP_DANCE_DOUBLE(KC_RGHT, KC_END),
        [TD_ESC_CAPS]   = ACTION_TAP_DANCE_DOUBLE(KC_ESC, KC_CAPS),
        // [TD_BSLS_GRV]   = ACTION_TAP_DANCE_DOUBLE(KC_BSLS, KC_GRV),
        // [TD_PIPE_TILD]  = ACTION_TAP_DANCE_DOUBLE(KC_PIPE, KC_TILD),
        [TD_BSLS_GRV]   = ACTION_TAP_DANCE_TAP_HOLD(KC_BSLS, KC_GRV),
        [TD_PIPE_TILD]  = ACTION_TAP_DANCE_TAP_HOLD(KC_PIPE, KC_TILD),
};
