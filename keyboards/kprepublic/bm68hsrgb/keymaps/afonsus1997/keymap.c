/* Copyright 2021 peepeetee
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

// // Defines names for use in layer keycodes and the keymap
// enum layer_names {
//     _BASE,
//     _FN
// };

enum custom_keycodes {

    KC_UCIS
};

#ifdef UCIS_ENABLE
const qk_ucis_symbol_t ucis_symbol_table[] = UCIS_TABLE(
    UCIS_SYM("poop", 0x1F4A9),                   // 💩
    UCIS_SYM("look", 0x0CA0, 0x005F, 0x0CA0),    // ಠ_ಠ
    UCIS_SYM("sus", 0xD9E),                      // ඞ
    UCIS_SYM("banana", 0x1F34C),                 // 🍌
    UCIS_SYM("benis", 0x1F346),                  // 🍆
    UCIS_SYM("shrug", 0xAF, 0x5C, 0x5F, 0x28, 0x30C4, 0x29, 0x5F, 0x2F, 0xAF),                  //¯\_(ツ)_/¯
    UCIS_SYM("lenny", 0x28, 0x20, 0x361, 0xB0, 0x20, 0x35C, 0x296, 0x20, 0x361, 0xB0, 0x29),    // ( ͡° ͜ʖ ͡°)
    UCIS_SYM("gary", 0x1555, 0x28, 0x20, 0x141B, 0x20, 0x29, 0x1557),                           // ᕕ( ᐛ )ᕗ
    UCIS_SYM("donger", 0x30FD, 0xF3C, 0xE88, 0x644, 0x35C, 0xE88, 0xF3D, 0xFF89)                // ヽ༼ຈل͜ຈ༽ﾉ
);
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_UCIS:
            if (record->event.pressed){
                qk_ucis_start();
            }
            return false;
    }
    return true;
}



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_65_ansi(
         KC_GRAVE,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_MINS,  KC_EQL,  KC_BSPC,   KC_DEL,
         KC_TAB,    KC_Q,     KC_W,     KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_LBRC, KC_RBRC,  KC_BSLS, KC_HOME,
        KC_ESC,       KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,        KC_ENT,    KC_PGUP,
        KC_LSFT,         KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,     KC_RSFT,     KC_UP,  KC_PGDN,
        KC_LCTL,   LT(1, KC_LGUI),   KC_LALT,                     KC_SPC,                         KC_RALT,   KC_RGUI,KC_RCTRL, KC_LEFT, KC_DOWN,  KC_RGHT
    ),
    [1] = LAYOUT_65_ansi(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,  _______,   RGB_VAI,
        _______,   KC_VOLD, KC_VOLU, LGUI(KC_E), LGUI(KC_R), _______, _______, _______, _______, _______, KC_PSCR, _______, _______,  _______, RGB_VAD,
        KC_CAPS,    KC_MPRV, KC_MPLY, KC_MNXT, _______, _______, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, _______, _______,       _______,    RGB_MOD,
        KC_LSFT,      KC_UCIS, _______, _______, _______,   RESET, _______, KC_PAUS, _______, _______, _______,     _______,   _______,  RGB_RMOD,
        KC_LCTL,   _______,   _______,                    LGUI(KC_SPC),                         _______, _______, _______, _______, _______,  _______
    ),

};

/*
Template
    [ ] = LAYOUT_65_ansi(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______,   _______,
        _______,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______,
        _______,    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,       _______,    _______,
        _______,      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,     _______,   _______,  _______,
        _______,   _______,   _______,                    _______,                         _______, _______, _______, _______, _______,  _______
    ),
*/


