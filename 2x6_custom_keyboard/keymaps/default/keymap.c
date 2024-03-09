// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include <qp.h>

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

// ┌───┬───┬───┬───┬───┬───┐
// │ 1 │ 2 │ 3 │ 4 │ 5 │ 6 │
// ├───┼───┼───┼───┼───┼───┤
// │ 7 │ 8 │ 9 │ 1 │ 2 │ 3 │
// └───┴───┴───┴───┴───┴───┘
 
    [0] = LAYOUT_ortho_2x6(
    KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,
    KC_7,   KC_8,   KC_9,   KC_A,   KC_B,   KC_C
)

};

// Initialize the OLED display

static painter_device_t oled_device;
void keyboard_post_init_kb(void) {
    // Create and initialize the OLED device
    oled_device = qp_sh1106_make_i2c_device(128, 64, 0x3C); // Replace 0x3C with the I2C address of your OLED
    qp_init(oled_device, QP_ROTATION_0);
}

void housekeeping_task_user(void) {
    static uint32_t last_draw = 0;
    if (timer_elapsed32(last_draw) > 33) { // Throttle to 30fps
        last_draw = timer_read32();
        // Draw r=4 filled circles down the left side of the oled_device
        for (int i = 0; i < 239; i+=8) {
            qp_circle(oled_device, 4, 4+i, 4, i, 255, 255, true);
        }
        qp_flush(oled_device);
    }
}




