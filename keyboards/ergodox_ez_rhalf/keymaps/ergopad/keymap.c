#include QMK_KEYBOARD_H

#define LTR0 0 // letters
#define LTR1 1 // letters
#define SYMB 2 // symbols
#define NMPD 3 // numpad
#define NAVI 4 // navigation

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[LTR0] = LAYOUT_ergodox(
  KC_NO,         KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, RESET,
  KC_NO,         KC_F,    KC_A,    KC_R,    KC_W,    KC_P,  KC_NO,
                 KC_O,    KC_E,    KC_H,    KC_T,    KC_D,  KC_TAB,
  OSM(MOD_LSFT), KC_U,    KC_I,    KC_N,    KC_S,    KC_Y,  KC_ENT,
                          KC_BSPC, KC_NO,   KC_NO,   KC_NO, KC_NO,
  KC_NO,   KC_NO,
  KC_PGUP,
  KC_PGDN, KC_NO, LT(LTR1, KC_SPC)
),
[LTR1] = LAYOUT_ergodox(
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_B,    KC_M,    KC_J,    KC_TRNS,
           KC_Q,    KC_Z,    KC_L,    KC_C,    KC_V,    KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_K,    KC_G,    KC_X,    KC_TRNS,
                    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  RGB_TOG, KC_TRNS,
  KC_TRNS,
  KC_TRNS, RGB_HUD, RGB_HUI
),
[NMPD] = LAYOUT_ergodox(
  KC_TRNS, KC_TRNS, KC_TRNS, KC_SLSH, KC_ASTR, KC_MINS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_7,    KC_8,    KC_9,    KC_PLUS, KC_TRNS,
           KC_TRNS, KC_4,    KC_5,    KC_6,    KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_1,    KC_2,    KC_3,    KC_TRNS, KC_TRNS,
                    KC_0,    KC_DOT,  KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS,
  KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS
),
[NAVI] = LAYOUT_ergodox(
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
           KC_TRNS, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS,
  KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS
),
[SYMB] = LAYOUT_ergodox(
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_QUES, KC_AMPR, KC_ASTR, KC_COLN, KC_SCLN, KC_TRNS,
           KC_SLSH, KC_EXLM, KC_MINS, KC_AT,   KC_UNDS, KC_TRNS,
  KC_TRNS, KC_DQUO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS,
  KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS
),
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
#ifdef RGBLIGHT_COLOR_LAYER_0
  rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
};

// Runs whenever there is a layer state change.
uint32_t layer_state_set_user(uint32_t state) {
  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();

  uint8_t layer = biton32(state);
  switch (layer) {
      case 0:
        #ifdef RGBLIGHT_COLOR_LAYER_0
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
        #else
        #ifdef RGBLIGHT_ENABLE
          rgblight_init();
        #endif
        #endif
        break;
      case 1:
        ergodox_right_led_1_on();
        #ifdef RGBLIGHT_COLOR_LAYER_1
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_1);
        #endif
        break;
      case 2:
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_2
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_2);
        #endif
        break;
      case 3:
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_3
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_3);
        #endif
        break;
      case 4:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_4
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_4);
        #endif
        break;
      case 5:
        ergodox_right_led_1_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_5
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_5);
        #endif
        break;
      case 6:
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_6
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
        #endif
        break;
      case 7:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_7
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_7);
        #endif
        break;
      default:
        break;
    }

  return state;
};
