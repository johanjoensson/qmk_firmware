#include QMK_KEYBOARD_H
#include "johanjoensson.h"
/*
 * Custom keycode handling
 */
uint8_t mod_state;
bool key_pressed = false;
uint16_t SH_LEAD_TIMER = 0;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
        if (record->event.pressed){
                key_pressed = true;
        }
        mod_state = get_mods();
        switch (keycode) {
                case CC_ARIN:
                // Å
                        if (record->event.pressed) {
                                if (mod_state & MOD_MASK_SHIFT) {
                                        register_unicode(0x00C5);
                                }else{
                                        register_unicode(0x00E5);
                                }
                                return false;
                        }
                        break;
                case CC_ADIA:
                // Ä
                        if (record->event.pressed) {
                                if (mod_state & MOD_MASK_SHIFT) {
                                        register_unicode(0x00C4);
                                }else{
                                        register_unicode(0x00E4);
                                }
                                return false;
                        }
                        break;
                case CC_ODIA:
                // Ö
                        if (record->event.pressed) {
                                if (mod_state & MOD_MASK_SHIFT) {
                                        register_unicode(0x00D6);
                                }else{
                                        register_unicode(0x00F6);
                                }
                                return false;
                        }
                        break;
                case CC_ALPH:
                // α
                        if (record->event.pressed) {
                                if (mod_state & MOD_MASK_SHIFT) {
                                        register_unicode(0x0391);
                                }else{
                                        register_unicode(0x03B1);
                                }
                                return false;
                        }
                        break;
                case CC_BETA:
                // β
                        if (record->event.pressed) {
                                if (mod_state & MOD_MASK_SHIFT) {
                                        register_unicode(0x0392);
                                }else{
                                        register_unicode(0x03B2);
                                }
                                return false;
                        }
                        break;
                case CC_GAMM:
                // γ
                        if (record->event.pressed) {
                                if (mod_state & MOD_MASK_SHIFT) {
                                        register_unicode(0x0393);
                                }else{
                                        register_unicode(0x03B3);
                                }
                                return false;
                        }
                        break;
                case CC_DELT:
                // δ
                        if (record->event.pressed) {
                                if (mod_state & MOD_MASK_SHIFT) {
                                        register_unicode(0x0394);
                                }else{
                                        register_unicode(0x03B4);
                                }
                                return false;
                        }
                        break;
                case CC_SIGM:
                // 
                        if (record->event.pressed) {
                                if (mod_state & MOD_MASK_SHIFT) {
                                        register_unicode(0x03A3);
                                }else{
                                        register_unicode(0x03C3);
                                }
                                return false;
                        }
                        break;
                case CC_RHO:
                // ρ
                        if (record->event.pressed) {
                                if (mod_state & MOD_MASK_SHIFT) {
                                        register_unicode(0x03A1);
                                }else{
                                        register_unicode(0x03C1);
                                }
                                return false;
                        }
                        break;
                case CC_PI:
                // π
                        if (record->event.pressed) {
                                if (mod_state & MOD_MASK_SHIFT) {
                                        register_unicode(0x03A0);
                                }else{
                                        register_unicode(0x03C0);
                                }
                                return false;
                        }
                        break;
                case CC_SNEK:
                // 🐍
                        if (record->event.pressed) {
                                if (mod_state & MOD_MASK_SHIFT) {
                                        register_unicode(0x1F40D);
                                }else{
                                        register_unicode(0x1F40D);
                                }
                                return false;
                        }
                        break;
                case KC_BSPC:
                // Left Shift + Backspace gives Delete
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
                        break;
                case CC_CLSH:
                        if (record->event.pressed) {
                                add_mods(MOD_MASK_SHIFT | MOD_MASK_CTRL);
                        }else{
                                del_mods(MOD_MASK_SHIFT | MOD_MASK_CTRL);
                        }
                        break;
                case CC_SHLD:
                        if (record->event.pressed) {
                                register_code(KC_LSFT);
                                key_pressed = false;
                                SH_LEAD_TIMER = timer_read();
                        }else{
                                unregister_code(KC_LSFT);
                                if (key_pressed){
                                        break;
                                }
                                if (timer_elapsed(SH_LEAD_TIMER) < TAPPING_TERM) {
                                        leader_start();
                                }
                        }
                        break;
                case KC_ENT:
                case KC_SPC:
                case KC_ESC:
                // End UCIS input
                // BSPC, ENT, SPC, ESC can all be used to end UCIS input and thus should turn off the _UCIS layer
                        if (record->event.pressed) {
                                if (get_highest_layer(layer_state) == _UCIS){
                                        layer_off(_UCIS);
                                }
                                break;
                        }
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

layer_state_t default_layer_state_set_user(layer_state_t state) {
#ifdef RGBLIGHT_ENABLE
    rgblight_set_layer_state(_BASE, layer_state_cmp(state, _BASE));
#endif
    return state;
}

layer_state_t layer_state_set_user(layer_state_t state) {
#ifdef RGBLIGHT_ENABLE
    rgblight_set_layer_state(_NUMPAD, layer_state_cmp(state, _NUMPAD));
    rgblight_set_layer_state(_NAV, layer_state_cmp(state, _NAV));
    rgblight_set_layer_state(_SYMBOLS, layer_state_cmp(state, _SYMBOLS));
    rgblight_set_layer_state(_FUNCTION, layer_state_cmp(state, _FUNCTION));
    rgblight_set_layer_state(_UCIS, layer_state_cmp(state, _UCIS));
#endif
    return state;
}

