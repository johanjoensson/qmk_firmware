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
        CAPWORD,
        SNEKCAS,
};

enum layer_names{
        _BASE = 0,
        _COLEMAK_DH,
        _UCIS,
        _SYMBOLS,
        _NUMPAD,
        _NAV,
        _FUNCTION,
        _MOUSE,
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
#define HOME_A LGUI_T(KC_A) /*QWERTY and COLEMAK-DH*/
#define HOME_S LALT_T(KC_S) /*QWERTY*/
#define HOME_R LALT_T(KC_R) /*COLEMAK-DH*/
#define HOME_F LCTL_T(KC_F) /*QWERTY*/
#define HOME_T LCTL_T(KC_T) /*COLEMAK-DH*/
#define HOME_J LCTL_T(KC_J) /*QWERTY*/
#define HOME_N LCTL_T(KC_N) /*COLEMAK-DH*/
#define HOME_L LALT_T(KC_L) /*QWERTY*/
#define HOME_I LALT_T(KC_I) /*COLEMAK-DH*/
#define HOME_SCLN LGUI_T(KC_SCLN) /*QWERY*/
#define HOME_O LGUI_T(KC_O) /*COLEMAK-DH*/
#define LSFT_ENT RSFT_T(KC_ENT)
#define LSFT_SPC LSFT_T(KC_SPC)

/*
 * Mod-taps
 */
#define CONTROL_SPC LT(_NAV, KC_SPC)



#ifdef TAP_DANCE_ENABLE
        typedef enum {
           /*
            * All different states a tap dance can be in,
            * and UNKNOWN
            */
            TD_NONE,
            TD_UNKNOWN,
            TD_SINGLE_TAP,
            TD_SINGLE_HOLD,
            TD_DOUBLE_TAP,
            TD_DOUBLE_HOLD,
            TD_DOUBLE_SINGLE_TAP, // Send two single taps
            TD_TRIPLE_TAP,
            TD_TRIPLE_HOLD
        } td_state_t;

        typedef struct {
            /*
             * Keep track of the tap dance state
             */
            bool is_press_action;
            td_state_t state;
        } td_tap_t;

        typedef struct{
            /*
             * User data, store all tap/hold keycodes as well as the dance state
             */
            uint16_t single_tap;
            uint16_t single_hold;
            uint16_t double_tap;
            uint16_t double_hold;
            uint16_t triple_tap;
            uint16_t triple_hold;
            td_tap_t* tap_state;
        } quad_tap_data_t;

        typedef struct{
            /*
             * User data, store all tap/hold layers as well as the dance state
             */
            uint8_t single_tap;
            uint8_t single_hold;
            uint8_t double_tap;
            uint8_t double_hold;
            uint8_t triple_tap;
            uint8_t triple_hold;
            td_tap_t* tap_state;
        } quad_tap_layer_data_t;

        enum {
                TD_LEFT_HOME = 0,
                TD_DOWN_PGDN,
                TD_UP_PGUP,
                TD_RGHT_END,
                TD_ESC_CAPS,
                TD_BSLS_GRV,
                TD_PIPE_TILD,
                TD_SYM,
                TD_NUM,
                TD_CAPWORD,
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
