/*
Base on the work of Olivier Pons, distributed under GPL
for more informations go check https://www.olivierpons.fr/infinity-ergodox/1-qmk-firmware-clavier-azerty-update
*/

#include "simple_visualizer.h"
#include <stdio.h>

// This function should be implemented by the keymap visualizer
// Don't change anything else than state->target_lcd_color and state->layer_text as that's the only thing
// that the simple_visualizer assumes that you are updating
// Also make sure that the buffer passed to state->layer_text remains valid until the previous animation is
// stopped. This can be done by either double buffering it or by using constant strings
static void get_visualizer_layer_and_color(visualizer_state_t* state) {
    if (state->status.layer & 0x80) {
        // yellow
        state->target_lcd_color = LCD_COLOR(42, 255, 60);
        state->layer_text = "¯_(o)_/¯";

    } else if (state->status.layer & 0x10) {
        // another blue
        state->target_lcd_color = LCD_COLOR(42, 50, 60);
        state->layer_text = "Gaming";

    } else if (state->status.layer & 0x8) {
        // yellow
        state->target_lcd_color = LCD_COLOR(42, 255, 60);
        state->layer_text = "Media";

    } else if (state->status.layer & 0x4) {
        // aqua
        state->target_lcd_color = LCD_COLOR(130, 255, 155);
        state->layer_text = "Accents|Keypad";

    } else if (state->status.layer & 0x2) {
        // green
        state->target_lcd_color = LCD_COLOR(100, 255, 155);
        state->layer_text = "Code|Move";

    } else {
        // clear
        state->target_lcd_color = LCD_COLOR(  0,   0, 255);
        state->layer_text = "Base";
    }

}
