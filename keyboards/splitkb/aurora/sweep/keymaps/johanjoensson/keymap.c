#include QMK_KEYBOARD_H
#include "johanjoensson.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

        /*
         * Base layer, QWERTY layout with homerow-mods (except shift), mod tap for enter and space / shift, combos for tab and escape.
         * As well as Swedish characters.
         * Access to _NUMPAD and _SYMBOLS layers on the thumbs.
         */
	[_BASE] = LAYOUT(
/* ┌──────┬──────┬──────┬──────┬──────┐                  ┌──────┬──────┬──────┬──────┬──────┐
 * │  Q   │  W   │  E   │  R   │  T   │                  │  Y   │  U   │  I   │  O   │  P   │
 * ├──────┼──────┼──────┼──────┼──────┤                  ├──────┼──────┼──────┼──────┼──────┤
 * │ A/◆  │ S/⎇  │  D   │ F/⎈  │  G   │                  │  H   │ J/⎈  │  K   │ L/⎇  │ ;/◆  │
 * ├──────┼──────┼──────┼──────┼──────┤                  ├──────┼──────┼──────┼──────┼──────┤
 * │  Z   │  X   │  C   │  V   │  B   │                  │  N   │  M   │ , <  │ . >  │ / ?  │
 * └───────────────────────────┼──────┼──────┐    ┌──────┼──────┼──────┴──────┴──────┴──────┘
 *                             │ ␣/⇧  │TD(TD_│    │TD(TD_│ ⏎/⇧  │
 *                             │      │      │    │      │      │
 *                             └──────┴──────┘    └──────┴──────┘
 *                                                                                   generated by [keymapviz] */
                        
                        KC_Q   , KC_W   , KC_E   , KC_R   , KC_T,                                               KC_Y   , KC_U   , KC_I   , KC_O   , KC_P,
                        HOME_A , HOME_S , KC_D   , HOME_F , KC_G,                                               KC_H   , HOME_J , KC_K   , HOME_L , HOME_SCLN,
                        KC_Z   , KC_X   , KC_C   , KC_V   , KC_B,                                               KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH,
                                                            LSFT_SPC, TD(TD_NUM),                     TD(TD_SYM), LSFT_ENT
                       ),
	[_COLEMAK_DH] = LAYOUT(
/* ┌──────┬──────┬──────┬──────┬──────┐                  ┌──────┬──────┬──────┬──────┬──────┐
 * │  Q   │  W   │  F   │  P   │  B   │                  │  J   │  L   │  U   │  Y   │ : ;  │
 * ├──────┼──────┼──────┼──────┼──────┤                  ├──────┼──────┼──────┼──────┼──────┤
 * │ A/◆  │ R/⎇  │  S   │ T/⎈  │  G   │                  │  M   │ N/⎈  │  E   │ I/⎇  │ O/◆  │
 * ├──────┼──────┼──────┼──────┼──────┤                  ├──────┼──────┼──────┼──────┼──────┤
 * │  Z   │  X   │  C   │  D   │  V   │                  │  K   │  H   │ , <  │ . >  │ / ?  │
 * └───────────────────────────┼──────┼──────┐    ┌──────┼──────┼──────┴──────┴──────┴──────┘
 *                             │ ␣/⇧  │TD(TD_│    │TD(TD_│ ⏎/⇧  │
 *                             │      │      │    │      │      │
 *                             └──────┴──────┘    └──────┴──────┘
 *                                                                                   generated by [keymapviz] */
                        
                        KC_Q   , KC_W   , KC_F   , KC_P   , KC_B,                                               KC_J   , KC_L   , KC_U   , KC_Y   , KC_SCLN,
                        HOME_A , HOME_R , KC_S   , HOME_T , KC_G,                                               KC_M   , HOME_N , KC_E   , HOME_I , HOME_O,
                        KC_Z   , KC_X   , KC_C   , KC_D   , KC_V,                                               KC_K   , KC_H   , KC_COMM, KC_DOT , KC_SLSH,
                                                            LSFT_SPC, TD(TD_NUM),                     TD(TD_SYM), LSFT_ENT
                       ),
        /*
         * _UCIS Is used for unicode input, the UCIS system requires basic keycodes A-Z, a-z, 0-9 ONLY, no mod-taps, homerow-mods, etc...
         */
	[_UCIS] = LAYOUT(
/* ┌──────┬──────┬──────┬──────┬──────┐                  ┌──────┬──────┬──────┬──────┬──────┐
 * │  Q   │  W   │  E   │  R   │  T   │                  │  Y   │  U   │  I   │  O   │  P   │
 * ├──────┼──────┼──────┼──────┼──────┤                  ├──────┼──────┼──────┼──────┼──────┤
 * │  A   │  S   │  D   │  F   │  G   │                  │  H   │  J   │  K   │  L   │UC_NEX│
 * ├──────┼──────┼──────┼──────┼──────┤                  ├──────┼──────┼──────┼──────┼──────┤
 * │  Z   │  X   │  C   │  V   │  B   │                  │  N   │  M   │  🛑   │  🛑   │UC_PRE│
 * └───────────────────────────┼──────┼──────┐    ┌──────┼──────┼──────┴──────┴──────┴──────┘
 *                             │  ␣   │ NUM  │    │ NUM  │ ENT  │
 *                             │      │      │    │      │      │
 *                             └──────┴──────┘    └──────┴──────┘
 *                                                                                   generated by [keymapviz] */
                        KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,                           KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   ,
                        KC_A   , KC_S   , KC_D   , KC_F   , KC_G   ,                           KC_H   , KC_J   , KC_K   , KC_L   , UC_NEXT,
                        KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   ,                           KC_N   , KC_M   , XXXXXXX, XXXXXXX, UC_PREV,
                                                   KC_SPC , MO(_NUMPAD),              XXXXXXX, KC_ENT
                       ),
        /*
         * _SYMBOLS gives access to a number row as well as a bunch of symbols. Leader key on left thumb, as well as access to the _FUNCTION layer.
         */
	[_SYMBOLS] = LAYOUT(
/* ┌──────┬──────┬──────┬──────┬──────┐                  ┌──────┬──────┬──────┬──────┬──────┐
 * │  !   │  @   │  #   │  $   │  %   │                  │  ^   │  &   │  {   │  }   │  *   │
 * ├──────┼──────┼──────┼──────┼──────┤                  ├──────┼──────┼──────┼──────┼──────┤
 * │  α   │  β   │  δ   │  π   │ \ `  │                  │ - _  │  =   │  (   │  )   │ ' "  │
 * ├──────┼──────┼──────┼──────┼──────┤                  ├──────┼──────┼──────┼──────┼──────┤
 * │  γ   │  σ   │  ρ   │  🐍   │ | ~  │                  │  _   │  +   │  [   │  ]   │  ~   │
 * └───────────────────────────┼──────┼──────┐    ┌──────┼──────┼──────┴──────┴──────┴──────┘
 *                             │CC_SHL│ NAV  │    │ NAV  │  R⇧  │
 *                             │      │      │    │      │      │
 *                             └──────┴──────┘    └──────┴──────┘
 *                                                                                   generated by [keymapviz] */
                        KC_EXLM, KC_AT  , KC_HASH, KC_DLR , KC_PERC,                             KC_CIRC, KC_AMPR, KC_LCBR, KC_RCBR, KC_ASTR,
                        CC_ALPH, CC_BETA, CC_DELT, CC_PI  , TD_BSLS,                             KC_MINS, KC_EQL , KC_LPRN, KC_RPRN, KC_QUOT,
                        CC_GAMM, CC_SIGM, CC_RHO , CC_SNEK, TD_PIPE,                             KC_UNDS, KC_PLUS, KC_LBRC, KC_RBRC, KC_TILD,
                                                            CC_SHLD, MO(_NAV),        TG(_SYMBOLS), KC_RSFT
                        ),
        /*
         * _NUMPAD gives acces to a numpad like layout on the right hand, RGB settings on the left and access to the _FUNCTION layer on the right thumb.
         */
	[_NUMPAD] = LAYOUT(
/* ┌──────┬──────┬──────┬──────┬──────┐                  ┌──────┬──────┬──────┬──────┬──────┐
 * │ CDH  │Sat ↑ │Hue ↑ │Val ↑ │RGB ↻ │                  │  *   │  7   │  8   │  9   │ - _  │
 * ├──────┼──────┼──────┼──────┼──────┤                  ├──────┼──────┼──────┼──────┼──────┤
 * │RGB ⏼ │Sat ↓ │Hue ↓ │Val ↓ │RGB ↺ │                  │ / ?  │  4   │  5   │  6   │  +   │
 * ├──────┼──────┼──────┼──────┼──────┤                  ├──────┼──────┼──────┼──────┼──────┤
 * │ QWR  │  🛑   │Tap ↑ │Tap ↓ │PrtTap│                  │ , <  │  1   │  2   │  3   │ . >  │
 * └───────────────────────────┼──────┼──────┐    ┌──────┼──────┼──────┴──────┴──────┴──────┘
 *                             │      │ ^NUM │    │ ^NUM │RSFT_T│
 *                             │      │      │    │      │      │
 *                             └──────┴──────┘    └──────┴──────┘
 *                                                                                   generated by [keymapviz] */
                DF(_COLEMAK_DH), RGB_SAI, RGB_HUI, RGB_VAI, RGB_MOD,                                 KC_ASTR, KC_7   , KC_8   , KC_9   , KC_MINS,
                        RGB_TOG, RGB_SAD, RGB_HUD, RGB_VAD, RGB_RMOD,                                KC_SLSH, KC_4   , KC_5   , KC_6   , KC_PLUS,
                      DF(_BASE), XXXXXXX, DT_UP  , DT_DOWN, DT_PRNT,                                 KC_COMM, KC_1   , KC_2   , KC_3   , KC_DOT,
                                                            _______, TG(_NUMPAD),          MO(_NAV), RSFT_T(KC_0)
                        ),
        /*
         * Access backspace and quotation symbols. As well as arrow navigation (vim layout) and home, page up, page down, and end keys with double taps.
         * Left thumb triggers Caps Word.
         */
	[_NAV] = LAYOUT(
/* ┌──────┬──────┬──────┬──────┬──────┐                  ┌──────┬──────┬──────┬──────┬──────┐
 * │  🔊   │  F7  │  F8  │  F9  │ F10  │                  │TD(TD_│ COPY │PASTE │  🛑   │  🛑   │
 * ├──────┼──────┼──────┼──────┼──────┤                  ├──────┼──────┼──────┼──────┼──────┤
 * │  🔉   │  F4  │  F5  │  F6  │ F11  │                  │ ← ⇐  │ ↓ ⇓  │ ↑ ⇑  │ → ⇒  │  🛑   │
 * ├──────┼──────┼──────┼──────┼──────┤                  ├──────┼──────┼──────┼──────┼──────┤
 * │  🔇   │  F1  │  F2  │  F3  │ F12  │                  │  ⏮   │  ⏯   │  ⏭   │  🛑   │  🛑   │
 * └───────────────────────────┼──────┼──────┐    ┌──────┼──────┼──────┴──────┴──────┴──────┘
 *                             │  🛑   │ ^NAV │    │ ^NAV │  🛑   │
 *                             │      │      │    │      │      │
 *                             └──────┴──────┘    └──────┴──────┘
 *                                                                                   generated by [keymapviz] */
                        KC_KB_VOLUME_UP  , KC_F7  , KC_F8  , KC_F9  , KC_F10 ,                              TD(TD_CAPWORD), KC_COPY, KC_PSTE, XXXXXXX, XXXXXXX,
                        KC_KB_VOLUME_DOWN, KC_F4  , KC_F5  , KC_F6  , KC_F11 ,                              TD_LEFT, TD_DOWN, TD_UP  , TD_RGHT, XXXXXXX,
                        KC_KB_MUTE       , KC_F1  , KC_F2  , KC_F3  , KC_F12 ,                              KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX, XXXXXXX,
                                                                      XXXXXXX, TG(_NAV),        TG(_NAV), XXXXXXX
                        ),
        [_MOUSE] = LAYOUT(
/* ┌──────┬──────┬──────┬──────┬──────┐                  ┌──────┬──────┬──────┬──────┬──────┐
 * │  🛑   │ 🖱️📜← │ 🖱️↑  │ 🖱️📜→ │  🛑   │                  │  ◆[  │  ⎈⇧  │  ⎈⇥  │  ◆]  │      │
 * ├──────┼──────┼──────┼──────┼──────┤                  ├──────┼──────┼──────┼──────┼──────┤
 * │  🛑   │ 🖱️←  │ 🖱️↓  │ 🖱️→  │ ◆/⇤  │                  │  🛑   │MT(MOD│MT(MOD│  🛑   │  ⏎   │
 * ├──────┼──────┼──────┼──────┼──────┤                  ├──────┼──────┼──────┼──────┼──────┤
 * │  🛑   │ 🖱️RB │ 🖱️📜↑ │ 🖱️📜↓ │      │                  │ 🖱️LB │ 🖱️00 │ 🖱️01 │ 🖱️01 │  🛑   │
 * └───────────────────────────┼──────┼──────┐    ┌──────┼──────┼──────┴──────┴──────┴──────┘
 *                             │ NUM  │ ^🖱️  │    │ ^🖱️  │  TO  │
 *                             │      │      │    │      │      │
 *                             └──────┴──────┘    └──────┴──────┘
 *                                                                                   generated by [keymapviz] */
                        XXXXXXX, KC_WH_L,    KC_MS_U, KC_WH_R, XXXXXXX,                                           LGUI(KC_LBRC), LCTL(LSFT(KC_TAB)),   RCTL(KC_TAB),       LGUI(KC_RBRC), _______, 
                        XXXXXXX, KC_MS_L,    KC_MS_D, KC_MS_R, MT(MOD_LGUI,KC_DEL),                               XXXXXXX,       MT(MOD_RGUI,KC_DOWN), MT(MOD_RALT,KC_UP), XXXXXXX,       KC_ENTER,     
                        XXXXXXX, KC_MS_BTN2, KC_WH_U, KC_WH_D, _______,                                           KC_MS_BTN1,    KC_MS_ACCEL0,       KC_MS_ACCEL1,       KC_MS_ACCEL2,  XXXXXXX, 
                                                               TO(_NUMPAD),           TG(_MOUSE),     TG(_MOUSE), TO(_SYMBOLS)
                        ),
};

