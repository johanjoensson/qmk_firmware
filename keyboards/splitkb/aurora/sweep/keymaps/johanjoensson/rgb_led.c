uint8_t bg_h = 255, bg_s = 255, bg_v = 255, kl_h = 255, kl_s = 255, kl_v = 255;
uint8_t hue_step = 17, val_step = 8, sat_step = 17;

void set_bg_hsv(uint8_t h, uint8_t s, uint8_t v)
{
    rgblight_sethsv_range(h, s, v, 0, 6);
    rgblight_sethsv_range(h, s, v, 23, 29);
    rgblight_set();
}


void set_kl_hsv(uint8_t h, uint8_t s, uint8_t v)
{
    rgblight_sethsv_range(h, s, v, 6, 23);
    rgblight_sethsv_range(h, s, v, 23, 28);
    rgblight_set();
    // rgblight_sethsv_range(h, s, v, 29, 46);
}


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


void bg_val_increase(void)
{
    if (bg_v < 255 - val_step + 1){
            ++bg_v;
    }else{
        bg_v = 255;
    }
    set_bg_hsv(bg_h, bg_s, bg_v);
}


void bg_val_decrease(void)
{
    if (bg_v > val_step){
            bg_v -= val_step;
    }else{
        bg_v = 0;
    }
    set_bg_hsv(bg_h, bg_s, bg_v);
}

void bg_hue_increase(void)
{
    if (bg_h < 255 - hue_step + 1){
            bg_h += hue_step;
    }else{
        bg_h = 255;
    }
    set_bg_hsv(bg_h, bg_s, bg_v);
}


void bg_hue_decrease(void)
{
    if (bg_h > hue_step){
            bg_h -= hue_step;
    }else{
        bg_h = 0;
    }
    set_bg_hsv(bg_h, bg_s, bg_v);
}
void bg_sat_increase(void)
{
    if (bg_s < 255 - sat_step + 1){
            bg_s += sat_step;
    }else{
        bg_s = 255;
    }
    set_bg_hsv(bg_h, bg_s, bg_v);
}


void bg_sat_decrease(void)
{
    if (bg_s > sat_step){
            bg_s -= sat_step;
    }else{
        bg_s = 0;
    }
    set_bg_hsv(bg_h, bg_s, bg_v);
}


void kl_val_increase(void)
{
    if (kl_v < 255 - val_step + 1){
            kl_v += val_step;
    }else{
        kl_v = 255;
    }
    set_kl_hsv(kl_h, kl_s, kl_v);
}


void kl_val_decrease(void)
{
    if (kl_v > val_step){
            kl_v -= val_step;
    }else{
        kl_v = 0;
    }
    set_kl_hsv(kl_h, kl_s, kl_v);
}

void kl_hue_increase(void)
{
    if (kl_h < 255 - hue_step + 1){
            kl_h += hue_step;
    }else{
        kl_h = 255;
    }
    set_kl_hsv(kl_h, kl_s, kl_v);
}


void kl_hue_decrease(void)
{
    if (kl_h > hue_step){
           kl_h -= hue_step;
    }else{
        kl_h = 0;
    }
    set_kl_hsv(kl_h, kl_s, kl_v);
}
void kl_sat_increase(void)
{
    if (kl_s < 255 - sat_step + 1){
            kl_s += sat_step;
    }else{
        kl_s = 255;
    }
    set_kl_hsv(kl_h, kl_s, kl_v);
}


void kl_sat_decrease(void)
{
    if (kl_s > sat_step){
            kl_s -= sat_step;
    }else{
        kl_s = 0;
    }
    set_kl_hsv(kl_h, kl_s, kl_v);
}
