#pragma once
#include QMK_KEYBOARD_H
#include "johanjoensson.h"


/*
 * Triple tap hold tap dances for triggering various keycodes.
 * Keycode 0 corresponds to an undefined key.
 * Single tap:  Trigger single_tap on tap
 * Single hold: Trigger single_hold on hold
 * Double tap:  Trigger double_tap on double tap,
 *              if undefined trigger single_tap twice
 * Double hold: Trigger double_hold after tap and hold,
 *              if not defined trigger single_tap followed by single_hold
 * Triple tap:  Trigger triple_tap on triple tap,
 *              if not defined and double_tap defined trigger single_tap 
 *              followed by double_tap. If double_tap is not defined trigger
 *              single_tap three times
 * Triple hold: Trigger triple_hold on tap, tap hold,
 *              if not defined and double_hold is defined trigger single_tap
 *              followed by double_hold. If double_hold is not defined but 
 *              double_tap is, trigger double_tap followed by single_hold.
 *              If double_tap is not defined, trigger single_tap twice followed 
 *              by single_hold.
 */
#define ACTION_TAP_DANCE_TAP_HOLD(tap, hold) \
    { .fn = {NULL, quad_dance_finished, quad_dance_reset, NULL},\
      .user_data = (void *)&((quad_tap_data_t){tap, hold, 0, 0, 0, 0, &((td_tap_t) {.is_press_action=true, .state=TD_NONE})}),}


#define ACTION_TAP_DANCE_DOUBLE_TAP_HOLD(single_tap, single_hold,\
                                         double_tap, double_hold) \
    { .fn = {NULL, quad_dance_finished, quad_dance_reset, NULL},\
      .user_data = (void *)&((quad_tap_data_t){single_tap, single_hold,\
                                                double_tap, double_hold,\
                                                0, 0, &((td_tap_t) {.is_press_action=true, .state=TD_NONE})}),}

#define ACTION_TAP_DANCE_TRIPLE_TAP_HOLD(single_tap, single_hold,\
                                         double_tap, double_hold,\
                                         triple_tap, triple_hold) \
    { .fn = {NULL, quad_dance_finished, quad_dance_reset, NULL},\
      .user_data = (void *)&((quad_tap_data_t){single_tap, single_hold,\
                                               double_tap, double_hold,\
                                               triple_tap, triple_hold, &((td_tap_t) {.is_press_action=true, .state=TD_NONE})}),}

/*
 * Triple tap hold tap dances for triggering layer shifts.
 * Layer 255 corresponds to an undefined layer.
 * Single tap:  Oneshot layer shift to single_tap
 * Single hold: Activate single_hold while held
 * Double tap:  Toggle double_tap
 * Double hold: Activate double_hold while held,
 *              if not defined trigger single tap followed by single hold`
 * Triple tap:  Toggle triple_tap,
 *              if not defined and double tap defined trigger single tap 
 *              followed by double tap. If double tap is not defined trigger
 *              single tap.
 * Triple hold: Activate triple_hold while held,
 *              if not defined and double hold is defined trigger single tap
 *              followed by double hold. If double hold is not defined but 
 *              double tap is trigger double tap followed by single hold.
 *              If double tap is not defined, trigger single hold.
 */
#define ACTION_TAP_DANCE_TAP_HOLD_LAYER(single_tap, single_hold)\
    { .fn = {NULL, quad_dance_layer_finished, quad_dance_layer_reset, NULL},\
      .user_data = (void *)&((quad_tap_layer_data_t){single_tap, single_hold,\
                                                     255, 255, 255, 255, &((td_tap_t) {.is_press_action=true, .state=TD_NONE})}),}

#define ACTION_TAP_DANCE_DOUBLE_TAP_HOLD_LAYER(single_tap, single_hold, double_tap, double_hold) \
    { .fn = {NULL, quad_dance_layer_finished, quad_dance_layer_reset, NULL},\
      .user_data = (void *)&((quad_tap_layer_data_t){single_tap, single_hold,\
                                                     double_tap, double_hold,\
                                                     255, 255, &((td_tap_t) {.is_press_action=true, .state=TD_NONE})}),}

#define ACTION_TAP_DANCE_TRIPLE_TAP_HOLD_LAYER(single_tap, single_hold, double_tap, double_hold, triple_tap, triple_hold) \
    { .fn = {NULL, quad_dance_layer_finished, quad_dance_layer_reset, NULL},\
      .user_data = (void *)&((quad_tap_layer_data_t){single_tap, single_hold,\
                                                     double_tap, double_hold,\
                                                     triple_tap, triple_hold, &((td_tap_t) {.is_press_action=true, .state=TD_NONE})}),}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record);

td_state_t cur_dance(tap_dance_state_t *state);
void quad_dance_finished(tap_dance_state_t *state, void *user_data);
void quad_dance_reset(tap_dance_state_t *state, void *user_data);
void quad_dance_layer_finished(tap_dance_state_t *state, void *user_data);
void quad_dance_layer_reset(tap_dance_state_t *state, void *user_data);
void caps_word_dance_finished(tap_dance_state_t *state, void *user_data);
void caps_word_dance_reset(tap_dance_state_t *state, void *user_data);


tap_dance_action_t tap_dance_actions[] = {
        [TD_LEFT_HOME]  = ACTION_TAP_DANCE_DOUBLE(KC_LEFT, KC_HOME),
        [TD_DOWN_PGDN]  = ACTION_TAP_DANCE_DOUBLE(KC_DOWN, KC_PGDN),
        [TD_UP_PGUP]    = ACTION_TAP_DANCE_DOUBLE(KC_UP, KC_PGUP),
        [TD_RGHT_END]   = ACTION_TAP_DANCE_DOUBLE(KC_RGHT, KC_END),
        [TD_ESC_CAPS]   = ACTION_TAP_DANCE_DOUBLE(KC_ESC, KC_CAPS),
        [TD_BSLS_GRV]   = ACTION_TAP_DANCE_TAP_HOLD(KC_BSLS, KC_GRV),
        [TD_PIPE_TILD]  = ACTION_TAP_DANCE_TAP_HOLD(KC_PIPE, KC_TILD),
        [TD_SYM]        = ACTION_TAP_DANCE_TRIPLE_TAP_HOLD_LAYER(_SYMBOLS, _SYMBOLS, _SYMBOLS, _NAV, _MOUSE, 255),
        [TD_NUM]        = ACTION_TAP_DANCE_TRIPLE_TAP_HOLD_LAYER(_NUMPAD,  _NUMPAD,  _NUMPAD,  _NAV, _MOUSE, 255),
        [TD_CAPWORD]    = ACTION_TAP_DANCE_FN_ADVANCED(NULL, caps_word_dance_finished, caps_word_dance_reset),
};
