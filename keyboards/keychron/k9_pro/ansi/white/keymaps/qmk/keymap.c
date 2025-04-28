/* Copyright 2023 @ Keychron (https://www.keychron.com)
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

enum layers{
    MAC_BASE,
    _FN1,
    MAC_FN,
    WIN_FN,
    L_FN1,
};

enum custom_keycodes {
    MC_CTRL_A = SAFE_RANGE,
    MC_CTRL_D,
    MC_CTRL_U,
    MC_CTRL_C,
    MC_CTRL_N,
    MC_CTRL_P
};

// 콤보 정의
const uint16_t PROGMEM u_i_combo[] = {KC_U, KC_I, COMBO_END};
const uint16_t PROGMEM m_comma_combo[] = {KC_M, KC_COMM, COMBO_END};
const uint16_t PROGMEM comma_dot_combo[] = {KC_COMM, KC_DOT, COMBO_END};
const uint16_t PROGMEM l_k_combo[] = {KC_L, KC_K, COMBO_END};
const uint16_t PROGMEM j_k_combo[] = {KC_J, KC_K, COMBO_END};

enum combo_events {
    /* UI_TO_SHIFT9, */
    UI_TO_MINS,
    MC_COMBO_BRACKET,
    MC_COMBO_RBRACKET,
    LK_TO_ESC,
    JK_TO_BSPC,
    COMBO_LENGTH
};

const uint16_t COMBO_LEN = COMBO_LENGTH;

combo_t key_combos[COMBO_LENGTH] = {
    /* [UI_TO_SHIFT9] = COMBO(u_i_combo, UI_TO_SHIFT9), */
    [UI_TO_MINS] = COMBO(u_i_combo, KC_MINS),
    [MC_COMBO_BRACKET] = COMBO(m_comma_combo, KC_LBRC), // [ 대괄호 열기
    [MC_COMBO_RBRACKET] = COMBO(comma_dot_combo, KC_RBRC),
    [LK_TO_ESC] = COMBO(l_k_combo, KC_ESC),
    [JK_TO_BSPC] = COMBO(j_k_combo, KC_BSPC),

};


// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [MAC_BASE] = LAYOUT_61_ansi(
        QK_GESC,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,   KC_EQL,  KC_BSPC,
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,   KC_RBRC, KC_BSLS,
        MO(1),  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,            KC_ENT,
        KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,            KC_RSFT,
        KC_LCTL,  KC_LOPTN, KC_LCMMD,                               KC_SPC,                                 KC_F18,MO(L_FN1),KC_LEFT,KC_RGHT),

    [_FN1] = LAYOUT_61_ansi(
        KC_GRAVE,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     MC_CTRL_U,     KC_I,     KC_O,     MC_CTRL_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,
        KC_CAPS,  MC_CTRL_A,     KC_S,     MC_CTRL_D,     KC_LSFT,     KC_HOME,     KC_LEFT,     KC_DOWN,     KC_UP,     KC_RGHT,     KC_END,  KC_QUOT,            KC_ENT,
        KC_LSFT,            KC_Z,     KC_X,     MC_CTRL_C,     KC_V,     KC_B,     MC_CTRL_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,            KC_RSFT,
        KC_LCTL,  KC_LALT,  KC_LGUI,                                KC_SPC,                                 KC_RALT, MO(WIN_FN),MO(L_FN1),KC_RCTL),

    [MAC_FN] = LAYOUT_61_ansi(
        KC_GRV,   KC_BRID,  KC_BRIU,  KC_MCTL,  KC_LPAD,  BL_DOWN,  BL_UP,    KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,  _______,
        _______,  BT_HST1,  BT_HST2,  BT_HST3,  _______,  _______,  _______,  _______,  _______,  _______,  KC_INS,   KC_PGUP,  KC_HOME,  _______,
        BL_TOGG,  BL_STEP,  BL_UP,    _______,  _______,  _______,  _______,  _______,  KC_UP,    KC_SNAP,  KC_PGDN,  KC_END,             _______,
        _______,            _______,  BL_DOWN,  _______,  _______,  _______,  NK_TOGG,  KC_LEFT,  KC_DOWN,  KC_RIGHT, KC_DEL,             _______,
        _______,  _______,  _______,                                _______,                                _______,  _______,  _______,  _______),

    [WIN_FN] = LAYOUT_61_ansi(
        KC_GRV,   KC_BRID,  KC_BRIU,  KC_TASK,  KC_FILE,  BL_DOWN,  BL_UP,    KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,  _______,
        _______,  BT_HST1,  BT_HST2,  BT_HST3,  _______,  _______,  _______,  _______,  KC_APP,   KC_SCRL,  KC_INS,   KC_PGUP,  KC_HOME,  _______,
        BL_TOGG,  BL_STEP,  BL_UP,    _______,  _______,  _______,  _______,  _______,  KC_UP,    KC_PSCR,  KC_PGDN,  KC_END,             _______,
        _______,            _______,  BL_DOWN,  _______,  _______,  _______,  NK_TOGG,  KC_LEFT,  KC_DOWN,  KC_RIGHT, KC_DEL,             _______,
        _______,  _______,  _______,                                _______,                                _______,  _______,  _______,  _______),

    [L_FN1] = LAYOUT_61_ansi(
        _______,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   QK_BOOT,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
        BL_TOGG,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
        _______,            _______,  _______,  _______,  _______,  BAT_LVL,  _______,  _______,  _______,  _______,  _______,            _______,
        _______,  _______,  _______,                                _______,                                _______,  _______,  _______,  _______),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!record->event.pressed) return true;

    // FN 레이어에서만 동작하도록 제한
    if (get_highest_layer(layer_state) != _FN1) return true;

    switch (keycode) {
        case MC_CTRL_A:
            tap_code16(C(KC_A));
            return false;
        case MC_CTRL_D:
            tap_code16(C(KC_D));
            return false;
        case MC_CTRL_C:
            tap_code16(C(KC_C));
            return false;
        case MC_CTRL_U:
            tap_code16(C(KC_U));
            return false;
        case MC_CTRL_P:
            tap_code16(C(KC_LEFT));
            return false;
        case MC_CTRL_N:
            tap_code16(C(KC_RGHT));
            return false;
    }
    return true;
}
