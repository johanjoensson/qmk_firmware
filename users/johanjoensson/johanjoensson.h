#pragma once
#include QMK_KEYBOARD_H

enum keycodes {
        CC_ARIN = SAFE_RANGE, // Å
        CC_ADIA,              // Ä
        CC_ODIA,              // Ö
        CC_ALPH,              // α
        CC_BETA,
        CC_DELT,
        CC_GAMM,
        CC_SIGM,
        CC_RHO,
        CC_PI,
        CC_SNEK,
        CC_CLSH,
        CC_SHLD,
};

enum layer_names{
        _BASE = 0,
        _UCIS,
        _SYMBOLS,
        _NUMPAD,
        _NAV,
        _FUNCTION,
        _UNUSED_2,
        _UNUSED_3,
        _UNUSED_4,
        _UNUSED_5,
        _UNUSED_6,
        _UNUSED_7,
        _UNUSED_8,
        _UNUSED_9,
        _UNUSED_10,
        _UNUSED_11
};

#define SYM      MO(_SYMBOLS)
#define NUM      MO(_NUMPAD)
#define NAV      MO(_NAV)

/*
 * Home-row mods
 */
#define HOME_A LGUI_T(KC_A)
#define HOME_S LALT_T(KC_S)
#define HOME_F LCTL_T(KC_F)
#define HOME_J LCTL_T(KC_J)
#define HOME_L LALT_T(KC_L)
#define HOME_SCLN LGUI_T(KC_SCLN)
#define LSFT_ENT LSFT_T(KC_ENT)
#define LSFT_SPC LSFT_T(KC_SPC)

/*
 * Mod-taps
 */
#define CONTROL_SPC LT(_NAV, KC_SPC)



#ifdef TAP_DANCE_ENABLE
        enum {
                TD_LEFT_HOME = 0,
                TD_DOWN_PGDN,
                TD_UP_PGUP,
                TD_RGHT_END,
                TD_ESC_CAPS,
                TD_BSLS_GRV,
                TD_PIPE_TILD
        };

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
