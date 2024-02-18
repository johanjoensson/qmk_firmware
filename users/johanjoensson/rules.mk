SRC += johanjoensson.c

ifeq ($(strip $(RGBLIGHT_ENABLE)), yes)
  # Include my fancy rgb functions source here
  SRC += rgb_led.c
endif
ifeq ($(strip $(OLED_ENABLE)), yes)
  # Include my fancy rgb functions source here
  SRC += oled.c
ifdef RIGHT_ANIMATION
  SRC += animation.c
endif
endif
ifeq ($(strip $(LEADER_ENABLE)), yes)
  # Include my fancy rgb functions source here
  SRC += leader.c
endif
ifeq ($(strip $(TAP_DANCE_ENABLE)), yes)
  # Include my fancy rgb functions source here
  SRC += tapdance.c
endif
ifeq ($(strip $(COMBO_ENABLE)), yes)
  # Include my fancy rgb functions source here
  INTROSPECTION_KEYMAP_C = combos.c 
endif
ifeq ($(strip $(UCIS_ENABLE)), yes)
  # Include my fancy rgb functions source here
  SRC += ucis.c
endif
ifeq ($(strip $(UNICODE_MAP_ENABLE)), yes)
  # Include my fancy rgb functions source here
  SRC += unicode_map.c
endif
ifeq ($(strip $(CAPS_WORD_ENABLE)), yes)
  # Include my fancy rgb functions source here
  SRC += caps_word.c
else
  SRC += features/casemodes.c
endif
