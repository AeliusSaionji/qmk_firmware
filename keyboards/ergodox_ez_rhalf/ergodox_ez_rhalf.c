#include QMK_KEYBOARD_H

extern inline void ergodox_board_led_on(void);
extern inline void ergodox_right_led_1_on(void);
extern inline void ergodox_right_led_2_on(void);
extern inline void ergodox_right_led_3_on(void);
extern inline void ergodox_right_led_on(uint8_t led);

extern inline void ergodox_board_led_off(void);
extern inline void ergodox_right_led_1_off(void);
extern inline void ergodox_right_led_2_off(void);
extern inline void ergodox_right_led_3_off(void);
extern inline void ergodox_right_led_off(uint8_t led);

extern inline void ergodox_led_all_on(void);
extern inline void ergodox_led_all_off(void);

extern inline void ergodox_right_led_1_set(uint8_t n);
extern inline void ergodox_right_led_2_set(uint8_t n);
extern inline void ergodox_right_led_3_set(uint8_t n);
extern inline void ergodox_right_led_set(uint8_t led, uint8_t n);

extern inline void ergodox_led_all_set(uint8_t n);

void matrix_init_kb(void) {
   // keyboard LEDs (see "PWM on ports OC1(A|B|C)" in "teensy-2-0.md")
    TCCR1A = 0b10101001;  // set and configure fast PWM
    TCCR1B = 0b00001001;  // set and configure fast PWM

    // (tied to Vcc for hardware convenience)
    DDRB  &= ~(1<<4);  // set B(4) as input
    PORTB &= ~(1<<4);  // set B(4) internal pull-up disabled

    // unused pins - C7, D4, D5, D7, E6
    // set as input with internal pull-up enabled
    DDRC  &= ~(1<<7);
    DDRD  &= ~(1<<5 | 1<<4);
    DDRE  &= ~(1<<6);
    PORTC |=  (1<<7);
    PORTD |=  (1<<5 | 1<<4);
    PORTE |=  (1<<6);

    ergodox_blink_all_leds();

    matrix_init_user();
}


void ergodox_blink_all_leds(void)
{
    ergodox_led_all_off();
    ergodox_led_all_set(LED_BRIGHTNESS_DEFAULT);
    ergodox_right_led_1_on();
    _delay_ms(50);
    ergodox_right_led_2_on();
    _delay_ms(50);
    ergodox_right_led_3_on();
    _delay_ms(50);
    ergodox_right_led_1_off();
    _delay_ms(50);
    ergodox_right_led_2_off();
    _delay_ms(50);
    ergodox_right_led_3_off();
    //ergodox_led_all_on();
    //_delay_ms(333);
    ergodox_led_all_off();
}


#ifdef RGB_MATRIX_ENABLE
const is31_led g_is31_leds[DRIVER_LED_TOTAL] = {
/*   driver
 *   |  R location
 *   |  |      G location
 *   |  |      |      B location
 *   |  |      |      | */
    {0, C3_1,  C2_1,  C4_1}, // LED1 on right
    {0, C6_1,  C5_1,  C7_1}, // LED2
    {0, C4_2,  C3_2,  C5_2}, // LED3
    {0, C7_2,  C6_2,  C8_2}, // LED4
    {0, C2_3,  C1_3,  C3_3}, // LED5
    {0, C5_3,  C4_3,  C6_3}, // LED6
    {0, C8_3,  C7_3,  C9_3}, // LED7
    {0, C2_4,  C1_4,  C3_4}, // LED8
    {0, C6_4,  C5_4,  C7_4}, // LED9
    {0, C2_5,  C1_5,  C3_5}, // LED10
    {0, C7_5,  C6_5,  C8_5}, // LED11
    {0, C2_6,  C1_6,  C3_6}, // LED12
    {0, C5_6,  C4_6,  C6_6}, // LED13
    {0, C8_6,  C7_6,  C9_6}, // LED14
    {0, C2_7,  C1_7,  C3_7}, // LED15
    {0, C5_7,  C4_7,  C6_7}, // LED16
    {0, C2_8,  C1_8,  C3_8}, // LED17
    {0, C5_8,  C4_8,  C6_8}, // LED18

    {0, C3_9,  C2_9,  C4_9}, // LED19
    {0, C6_9,  C5_9,  C7_9}, // LED20
    {0, C4_10, C3_10, C5_10}, // LED21
    {0, C7_10, C6_10, C8_10}, // LED22
    {0, C2_11, C1_11, C3_11}, // LED23
    {0, C5_11, C4_11, C6_11}, // LED24

};


const rgb_led g_rgb_leds[DRIVER_LED_TOTAL] = {

    /*{row | col << 4}
      |             {x=0..224, y=0..64}
      |              |                    modifier
      |              |                    | */
    {{ 8|(0<<4)},   {17.2* 8, 12.8*0}, 0}, // LED 1 on right > Key 6
    {{ 9|(0<<4)},   {17.2* 9, 12.8*0}, 0}, // LED 2 > Key 7
    {{10|(0<<4)},   {17.2*10, 12.8*0}, 0}, // LED 3 > Key 8
    {{11|(0<<4)},   {17.2*11, 12.8*0}, 0}, // LED 4 > Key 9
    {{12|(0<<4)},   {17.2*12, 12.8*0}, 0}, // LED 5 > Key 0

    {{ 8|(1<<4)},   {17.2* 8, 12.8*1}, 0}, // LED 6
    {{ 9|(1<<4)},   {17.2* 9, 12.8*1}, 0}, // LED 7
    {{10|(1<<4)},   {17.2*10, 12.8*1}, 0}, // LED 8
    {{11|(1<<4)},   {17.2*11, 12.8*1}, 0}, // LED 9
    {{12|(1<<4)},   {17.2*12, 12.8*1}, 0}, // LED 10

    {{ 8|(2<<4)},   {17.2* 8, 12.8*2}, 0}, // LED 11
    {{ 9|(2<<4)},   {17.2* 9, 12.8*2}, 0}, // LED 12
    {{10|(2<<4)},   {17.2*10, 12.8*2}, 0}, // LED 13
    {{11|(2<<4)},   {17.2*11, 12.8*2}, 0}, // LED 14
    {{12|(2<<4)},   {17.2*12, 12.8*2}, 0}, // LED 15

    {{ 8|(3<<4)},   {17.2* 8, 12.8*3}, 0}, // LED 16
    {{ 9|(3<<4)},   {17.2* 9, 12.8*3}, 0}, // LED 17
    {{10|(3<<4)},   {17.2*10, 12.8*3}, 0}, // LED 18
    {{11|(3<<4)},   {17.2*11, 12.8*3}, 0}, // LED 19
    {{12|(3<<4)},   {17.2*12, 12.8*3}, 0}, // LED 20

    {{ 9|(4<<4)},   {17.2* 9, 12.8*4}, 1}, // LED 21
    {{10|(4<<4)},   {17.2*10, 12.8*4}, 1}, // LED 22
    {{11|(4<<4)},   {17.2*11, 12.8*4}, 1}, // LED 23
    {{12|(4<<4)},   {17.2*12, 12.8*4}, 1}, // LED 24

};
#endif
