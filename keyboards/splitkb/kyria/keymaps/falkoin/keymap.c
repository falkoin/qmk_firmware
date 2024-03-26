#include QMK_KEYBOARD_H


#define _LAYER0 0
#define _LAYER1 1
#define _LAYER2 2
#define _LAYER3 3
#define _LAYER4 4

enum custom_keycodes {
    LAYER0 = SAFE_RANGE,
    LAYER1,
    LAYER2,
    LAYER3,
    LAYER4,
};

 const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

 [_LAYER0] = LAYOUT(
    KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T,                                      KC_Y, KC_U, KC_I, KC_O, KC_P, KC_MINS,
    KC_ESC, KC_A, KC_S, KC_D, KC_F, KC_G,                                      KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_LCTL,
    MO(3),  KC_Z, KC_X, KC_C, KC_V, KC_B, KC_VOLD, KC_MUTE,   KC_NO, KC_VOLU, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, OSL(4),
                   KC_LALT, MO(1), KC_LGUI, KC_LSFT, KC_NO,   KC_NO, KC_ENT, KC_SPC, MO(2), KC_NO),

[_LAYER1] = LAYOUT(KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,                                            KC_CIRC, KC_AMPR, KC_ASTR, KC_NO, LALT(KC_S), QK_MACRO_0,
                   KC_GRV, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC,                                    KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, QK_MACRO_1, QK_MACRO_2,
                   KC_LSFT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS, HYPR(KC_DOWN), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                              KC_TRNS, KC_TRNS, KC_LALT, KC_LGUI, KC_TRNS,   KC_TRNS, KC_TRNS, KC_LCTL, KC_TRNS, KC_NO),

[_LAYER2] = LAYOUT(KC_0, KC_1, KC_2, KC_3, KC_4, KC_5,                                                           KC_6, KC_7, KC_8, KC_9, KC_TRNS, KC_TRNS,
                   KC_TILD, KC_TRNS, KC_LCBR, KC_LBRC, KC_LPRN, KC_UNDS,                                         KC_EQL, KC_RPRN, KC_RBRC, KC_RCBR, KC_QUOT, KC_TRNS,
                   KC_LCTL, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_V, KC_TRNS, KC_TRNS,        KC_TRNS, KC_TRNS, KC_BSLS, S(KC_EQUAL), S(KC_BSLS), KC_TRNS, KC_TRNS, KC_TRNS,
                                           KC_TRNS, MO(1), KC_TRNS, KC_TRNS, KC_TRNS,        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

[_LAYER3] = LAYOUT(KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_TRNS, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, KC_TRNS, KC_TAB, KC_BSPC, KC_DEL, KC_SPC, KC_ENT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

[_LAYER4] = LAYOUT(KC_TAB, HYPR(KC_Q), HYPR(KC_W), HYPR(KC_E), HYPR(KC_R), HYPR(KC_T), HYPR(KC_Y), HYPR(KC_U), HYPR(KC_I), HYPR(KC_O), HYPR(KC_P), KC_MINS, KC_ESC, HYPR(KC_A), HYPR(KC_S), HYPR(KC_D), HYPR(KC_F), HYPR(KC_G), HYPR(KC_H), HYPR(KC_J), HYPR(KC_K), HYPR(KC_L), HYPR(KC_SCLN), KC_QUOT, KC_LCTL, HYPR(KC_Z), HYPR(KC_X), HYPR(KC_C), HYPR(KC_V), HYPR(KC_B), KC_VOLD, KC_MUTE, KC_NO, KC_VOLU, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_TRNS, KC_NO, TT(1), SC_SENT, MO(3), KC_NO, KC_NO, TT(4), KC_SPC, MO(2), KC_NO)

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch (keycode) {
            case QK_MACRO_0:
                SEND_STRING(SS_DOWN(X_LALT)SS_DOWN(X_U)SS_DELAY(20)SS_UP(X_LALT)SS_UP(X_U)SS_TAP(X_U));
                return false;
            case QK_MACRO_1:
                SEND_STRING(SS_DOWN(X_LALT)SS_DOWN(X_U)SS_DELAY(20)SS_UP(X_LALT)SS_UP(X_U)SS_TAP(X_O));
                return false;
            case QK_MACRO_2:
                SEND_STRING(SS_DOWN(X_LALT)SS_DOWN(X_U)SS_DELAY(20)SS_UP(X_LALT)SS_UP(X_U)SS_TAP(X_A));
                return false;
        }
    }

    return true;
};

void keyboard_pre_init_user(void) {
  // Set our LED pin as output
  setPinOutput(24);
  // Turn the LED off
  // (Due to technical reasons, high is off and low is on)
  writePinHigh(24);
}
