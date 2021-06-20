// TODO
// need safe range for all defs?
// LTR1 + above -, hold + for = instead of hold = for +
// need ; after }?
#include QMK_KEYBOARD_H

enum custom_keycodes {
    SPACE_MOD = SAFE_RANGE,
    DOT_MOD,
    NUM_MOD,
    GAME_ON,
    GAME_OFF
};

#define LTR0 0 // letters
#define LTR1 1 // letters
#define SYMB 2 // symbols
#define NMPD 3 // numpad
#define NAVI 4 // navigation
#define GAME 5 // gaming
#define FKEY 6 // function keys

// Tabularize//\*\*/\zs
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[LTR0] = LAYOUT_ergodox(
  KC_LSFT, /**/           KC_1, /**/        KC_2, /**/        LWIN(LCTL(KC_LEFT)), /**/  LWIN(LCTL(KC_RGHT)), /**/  KC_INS, /**/       KC_BSPC,
  OSM(MOD_LCTL), /**/     KC_F, /**/        KC_A, /**/        KC_R, /**/                 KC_W, /**/                 KC_P, /**/         KC_ESC,
  /**/                    KC_O, /**/        KC_E, /**/        KC_H, /**/                 KC_T, /**/                 KC_D, /**/         KC_TAB,
  OSM(MOD_LALT), /**/     KC_U, /**/        KC_I, /**/        KC_N, /**/                 KC_S, /**/                 KC_Y, /**/         KC_ENT,
  /**/                    /**/              DOT_MOD, /**/     OSL(FKEY), /**/            KC_LEAD, /**/              KC_CAPSLOCK, /**/  OSM(MOD_RSFT),
  KC_PSCR, /**/           GAME_ON,
  RGB_MOD, /**/
  KC_LWIN, /**/           NUM_MOD, /**/     SPACE_MOD
),
[LTR1] = LAYOUT_ergodox(
  KC_NO, /**/             KC_NO, /**/       KC_NO, /**/       KC_NO, /**/                KC_NO, /**/                KC_NO, /**/        KC_TRNS,
  KC_NO, /**/             KC_EXLM, /**/     KC_QUOT, /**/     KC_B, /**/                 KC_M, /**/                 KC_J, /**/         KC_EQL,
  /**/                    KC_Q, /**/        KC_Z, /**/        KC_L, /**/                 KC_C, /**/                 KC_V, /**/         KC_MINS,
  KC_NO, /**/             KC_QUES, /**/     KC_COMM, /**/     KC_K, /**/                 KC_G, /**/                 KC_X, /**/         KC_NO,
  /**/                    /**/              KC_NO, /**/       KC_NO, /**/                KC_NO, /**/                KC_NO, /**/        KC_NO,
  KC_NO, /**/             KC_NO,
  RGB_TOG, /**/
  MEH(KC_4), /**/         TT(NAVI), /**/    KC_NO
),
[SYMB] = LAYOUT_ergodox(
  KC_NO, /**/             KC_CIRC, /**/     KC_DLR, /**/      KC_SLSH, /**/              KC_BSLS, /**/              KC_NO, /**/        KC_TRNS,
  KC_NO, /**/             KC_GRV, /**/      KC_AMPR, /**/     KC_LBRC, /**/              KC_RBRC, /**/              KC_PERC, /**/      KC_NO,
  /**/                    KC_EQL, /**/      KC_ASTR, /**/     KC_LPRN, /**/              KC_RPRN, /**/              KC_SCLN, /**/      KC_NO,
  KC_NO, /**/             KC_MINS, /**/     KC_AT, /**/       KC_LABK, /**/              KC_RABK, /**/              KC_HASH, /**/      KC_NO,
  /**/                    /**/              KC_NO, /**/       KC_NO, /**/                KC_NO, /**/                KC_NO, /**/        KC_NO,
  KC_NO, /**/             KC_NO,
  KC_NO, /**/
  KC_NO, /**/             KC_NO, /**/       KC_NO
),
[NMPD] = LAYOUT_ergodox(
  KC_NO, /**/             KC_NO, /**/       KC_DLR, /**/      KC_PSLS, /**/              KC_PAST, /**/              KC_PMNS, /**/      KC_TRNS,
  KC_NO, /**/             KC_DLR, /**/      KC_7, /**/        KC_8, /**/                 KC_9, /**/                 KC_PPLS, /**/      KC_NO,
  /**/                    KC_0, /**/        KC_4, /**/        KC_5, /**/                 KC_6, /**/                 KC_EQL,  /**/      KC_DOT,
  KC_NO, /**/             KC_PERC, /**/     KC_1, /**/        KC_2, /**/                 KC_3, /**/                 KC_HASH, /**/      KC_COMM,
  /**/                    /**/              KC_TRNS, /**/     KC_TRNS, /**/              KC_NO, /**/                KC_NO, /**/        KC_NO,
  KC_NO, /**/             KC_NO,
  RGB_HUI, /**/
  KC_NO, /**/             TG(NMPD), /**/    LT(NAVI, KC_SPC)
),
[NAVI] = LAYOUT_ergodox(
  KC_MUTE, /**/           KC_NO, /**/       KC_NO, /**/       KC_NO, /**/                KC_NO, /**/                KC_NO, /**/        KC_NO,
  KC_VOLU, /**/           KC_NO, /**/       KC_HOME, /**/     KC_PGDN, /**/              KC_PGUP, /**/              KC_END, /**/       KC_NO,
  /**/                    C(KC_LEFT), /**/  KC_LEFT, /**/     KC_DOWN, /**/              KC_UP, /**/                KC_RGHT, /**/      C(KC_RGHT),
  KC_VOLD, /**/           KC_NO, /**/       KC_MPRV, /**/     KC_MPLY, /**/              KC_NO, /**/                KC_MNXT, /**/      KC_NO,
  /**/                    /**/              KC_LABK, /**/     KC_COMM, /**/              KC_DOT, /**/               KC_RABK, /**/      KC_NO,
  KC_NO, /**/             KC_NO,
  KC_NO, /**/
  KC_NO, /**/             TG(NAVI), /**/    KC_NO
),
[GAME] = LAYOUT_ergodox(
  KC_F1, /**/             KC_F2, /**/       KC_F3, /**/       KC_F4, /**/                KC_F5, /**/                KC_F6, /**/        KC_BSPC,
  KC_M, /**/              KC_E, /**/        KC_NO, /**/       KC_UP, /**/                KC_D, /**/                 KC_NO, /**/        KC_ESC,
  /**/                    KC_R, /**/        KC_LEFT, /**/     KC_DOWN, /**/              KC_RIGHT, /**/             KC_Q, /**/         KC_TAB,
  KC_I, /**/              KC_W, /**/        KC_NO, /**/       KC_NO, /**/                KC_NO, /**/                KC_NO, /**/        KC_ENT,
  /**/                    /**/              KC_NO, /**/       KC_NO, /**/                KC_NO, /**/                KC_NO, /**/        KC_RSHIFT,
  G(A(KC_PSCR)), /**/     GAME_OFF,
  G(A(KC_G)), /**/
  LWIN(KC_G), /**/        KC_S, /**/        KC_A
),
[FKEY] = LAYOUT_ergodox(
  KC_NO, /**/             KC_NO, /**/       KC_F10, /**/      KC_F11, /**/               KC_F12, /**/               KC_NO, /**/        KC_DEL,
  KC_NO, /**/             KC_NO, /**/       KC_F7, /**/       KC_F8, /**/                KC_F9, /**/                KC_NO, /**/        KC_NO,
  /**/                    KC_NO, /**/       KC_F4, /**/       KC_F5, /**/                KC_F6, /**/                KC_NO, /**/        KC_NO,
  KC_NO, /**/             KC_NO, /**/       KC_F1, /**/       KC_F2, /**/                KC_F3, /**/                KC_NO, /**/        KC_NO,
  /**/                    /**/              KC_NO, /**/       KC_NO, /**/                KC_NO, /**/                KC_NO, /**/        KC_NO,
  KC_NO, /**/             KC_NO,
  KC_NO, /**/
  KC_NO, /**/             KC_NO, /**/       KC_NO
),
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
#ifdef RGBLIGHT_COLOR_LAYER_0
  rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
};

static bool key_check;
static uint16_t key_timer;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	switch (keycode) {
		case SPACE_MOD:
			// if SPACE_MOD is pressed
			if (record->event.pressed) {
				// activate layer 1
				layer_on(LTR1);
				// reset key detection
				key_check = 0;
				// start timer
				key_timer = timer_read();
			}
			// if SPACE_MOD is released
			else if (!record->event.pressed) {
				// deactivate layer 1
				layer_off(LTR1);
				// if no other keys were detected while SPACE_MOD was pressed
				// AND if SPACE_MOD was held for shorter than 300ms
				if (key_check == 0 && timer_elapsed(key_timer) < 300) {
					// tap space
					tap_code(KC_SPC);
				}
			}
			return false;
		case DOT_MOD:
			// if DOT_MOD is pressed
			if (record->event.pressed) {
				// activate layer 2
				layer_on(SYMB);
				// reset key detection
				key_check = 0;
				// start timer
				key_timer = timer_read();
			}
			// if DOT_MOD is released
			else if (!record->event.pressed) {
				// deactivate layer 2
				layer_off(SYMB);
				// if no other keys were detected while DOT_MOD was pressed
				// AND if DOT_MOD was held for shorter than 300ms
				if (key_check == 0 && timer_elapsed(key_timer) < 300) {
					tap_code(KC_DOT);
				}
			}
			return false;
		case NUM_MOD:
			// if NUM_MOD is pressed
			if (record->event.pressed) {
				// activate layer 3
				layer_on(NMPD);
				// reset key detection
				key_check = 0;
				// start timer
				key_timer = timer_read();
			}
			// if NUM_MOD is released
			else if (!record->event.pressed) {
				// deactivate layer 3
				layer_off(NMPD);
				// if no other keys were detected while NUM_MOD was pressed
				// AND if NUM_MOD was held for shorter than 300ms
				if (key_check == 0 && timer_elapsed(key_timer) < 300) {
					tap_code(KC_0);
				}
			}
			return false;
		case GAME_ON:
			// if GAME_ON is pressed
			if (record->event.pressed) {
				// activate layer 5
				layer_on(GAME);
				// turn off autoshift
				autoshift_disable();
			}
			return false;
		case GAME_OFF:
			// if GAME_OFF is pressed
			if (record->event.pressed) {
				// deactivate layer 5
				layer_off(GAME);
				// turn on autoshift
				autoshift_enable();
			}
			return false;
		default:
			// if ANY key is pressed (but not released) at any time
			if (record->event.pressed) {
				// key has been detected, set true
				key_check = 1;
			}
			return true;
	}
}

// Leader definitions
LEADER_EXTERNS();
void matrix_scan_user(void) {
	LEADER_DICTIONARY() {
		leading = false;
		leader_end();
		SEQ_FIVE_KEYS(KC_R, KC_E, KC_S, KC_E, KC_T) {
			reset_keyboard();
    }
  }
}

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
