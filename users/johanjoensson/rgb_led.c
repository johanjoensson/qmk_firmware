#include QMK_KEYBOARD_H
#include "johanjoensson.h"
#include "rgb_led.h"

uint8_t bg_h = 255, bg_s = 255, bg_v = 255, kl_h = 255, kl_s = 255, kl_v = 255;
uint8_t hue_step = 17, val_step = 8, sat_step = 17;

void keyboard_pre_init_user(void) {
  // Set our LED pin as output
  setPinOutput(24);
  // Turn the LED off
  // (Due to technical reasons, high is off and low is on)
  writePinHigh(24);
}

const rgblight_segment_t PROGMEM capslock_indicator[] = RGBLIGHT_LAYER_SEGMENTS(
    {22, 1, HSV_RED},       // Light 1 LED, starting with LED 22
    {44, 1, HSV_RED}       // Light 1 LED, starting with LED 45
);
// Light LEDs 9 & 10 in cyan when keyboard layer 1 is active
const rgblight_segment_t PROGMEM base_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 6, HSV_BLACK},
    {23, 6, HSV_BLACK}
);
const rgblight_segment_t PROGMEM nav_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 6, HSV_GREEN},
    {23, 6, HSV_GREEN}
);
const rgblight_segment_t PROGMEM numpad_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 6, HSV_RED},
    {23, 6, HSV_BLACK}
);
const rgblight_segment_t PROGMEM symbols_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 6, HSV_BLACK},
    {23, 6, HSV_RED}
);
const rgblight_segment_t PROGMEM ucis_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 6, HSV_TURQUOISE},
    {23, 6, HSV_TURQUOISE}
);

const rgblight_segment_t* const PROGMEM rgb_layers[] = RGBLIGHT_LAYERS_LIST(
                [_BASE] = base_layer,
                [_NAV] = nav_layer,
                [_UCIS] = ucis_layer,
                [_SYMBOLS] = symbols_layer,
                [_NUMPAD] = numpad_layer,
                [7] = capslock_indicator
);

void keyboard_post_init_user(void) {
    // Initialize RGB to static black
    rgblight_enable_noeeprom();
    rgblight_sethsv_noeeprom(HSV_BLACK);
    rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
    rgblight_layers = rgb_layers;

}

bool led_update_user(led_t led_state) {
    rgblight_set_layer_state(7, led_state.caps_lock);
    return true;
}
