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

void keyboard_post_init_user(void) {
    // Initialize RGB to static black
    rgblight_enable_noeeprom();
    rgblight_sethsv_noeeprom(HSV_BLACK);
    rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
}


// This seems to be run on both halves of the keyboard, 
// so it works the way I want it to, with rgblight_sethsv_range
// ONLY used predefined colors!
void housekeeping_task_user(void) {
    switch (get_highest_layer(layer_state | default_layer_state)) {
        case BASE:
            rgblight_sethsv_range(HSV_BLACK, 0, 6);
            rgblight_sethsv_range(HSV_BLACK, 23, 29);
            break;
        case CONTROL:
            rgblight_sethsv_range(HSV_GREEN, 0, 6);
            rgblight_sethsv_range(HSV_GREEN, 23, 29);
            break;
        case NUMBERS:
            rgblight_sethsv_range(HSV_RED, 0, 6);
            rgblight_sethsv_range(HSV_BLACK, 23, 29);
            break;
        case SYMBOLS:
            rgblight_sethsv_range(HSV_BLACK, 0, 6);
            rgblight_sethsv_range(HSV_RED, 23, 29);
            break;
        case NUMPAD:
            rgblight_sethsv_range(HSV_BLUE, 0, 6);
            rgblight_sethsv_range(HSV_BLUE, 23, 29);
            break;
        case FUNCTION:
            rgblight_sethsv_range(HSV_GREEN, 0, 6);
            rgblight_sethsv_range(HSV_BLACK, 23, 29);
            break;
        case RGBS:
            rgblight_sethsv_range(HSV_PURPLE, 0, 6);
            rgblight_sethsv_range(HSV_PURPLE, 23, 29);
            break;
    }
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
