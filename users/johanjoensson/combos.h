#pragma once
#include QMK_KEYBOARD_H
#include "johanjoensson.h"

enum combos {
  WE_TAB,
  ER_STAB,
  SD_ESC,
  UI_BSP,
  JK_ENT,
  IO_ARIN,
  KL_ADIA,
  LSCLN_ODIA,
  COMMDOT_ODIA,
};

const uint16_t PROGMEM we_combo[] = {KC_W, KC_E, COMBO_END};
const uint16_t PROGMEM er_combo[] = {KC_E, KC_R, COMBO_END};
const uint16_t PROGMEM sd_combo[] = {LALT_T(KC_S), KC_D, COMBO_END};
const uint16_t PROGMEM ui_combo[] = {KC_U, KC_I, COMBO_END};
const uint16_t PROGMEM jk_combo[] = {LCTL_T(KC_J), KC_K, COMBO_END};
const uint16_t PROGMEM io_combo[] = {KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM kl_combo[] = {KC_K, LALT_T(KC_L), COMBO_END};
const uint16_t PROGMEM lscln_combo[] = {LALT_T(KC_L), LGUI_T(KC_SCLN) , COMBO_END};
const uint16_t PROGMEM commdot_combo[] = {KC_COMM, KC_DOT, COMBO_END};

combo_t key_combos[] = {
  [WE_TAB] = COMBO(we_combo, KC_TAB),
  [ER_STAB] = COMBO(er_combo, LSFT(KC_TAB)),

#ifdef TAP_DANCE_ENABLE
  [SD_ESC] = COMBO(sd_combo, ESC_CAP),
#else
  [SD_ESC] = COMBO(sd_combo, KC_ESC),
#endif

  [UI_BSP] = COMBO(ui_combo, KC_BSPC),
  [JK_ENT] = COMBO(jk_combo, KC_ENT),
  [IO_ARIN] = COMBO(io_combo, CC_ARIN),
  [KL_ADIA] = COMBO(kl_combo, CC_ADIA),
  [LSCLN_ODIA] = COMBO(lscln_combo, CC_ODIA),
  [COMMDOT_ODIA] = COMBO(commdot_combo, CC_ODIA),
};
