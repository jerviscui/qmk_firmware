#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum custom_layer {
    _QWERTY,
    _NUMPAD,
    _FN
};

// Some basic macros
#define TASK   LCTL(LSFT(KC_ESC))
#define TAB_R  LCTL(KC_TAB)
#define TAB_L  LCTL(LSFT(KC_TAB))
#define TAB_RO LCTL(LSFT(KC_T))

#define L1 TG(_NUMPAD)
#define L2 TG(_FN)

#define OSMLS OSM(MOD_LSFT)
#define OSMWin OSM(MOD_LGUI)
#define OSMRS OSM(MOD_RSFT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT_5x7_2(
        KC_ESC,     KC_1,    KC_2,      KC_3,   KC_4,   KC_5,   KC_F12,                         KC_F11,     KC_6,    KC_7,   KC_8,       KC_9,     KC_0,     KC_GRV,
        KC_TAB,     KC_Q,    KC_W,      KC_E,   KC_R,   KC_T,   KC_MINS,                        KC_LBRC,    KC_Y,    KC_U,   KC_I,       KC_O,     KC_P,     KC_BSLS,
        KC_LCTL,    KC_A,    KC_S,      KC_D,   KC_F,   KC_G,   KC_EQL,                         KC_RBRC,    KC_H,    KC_J,   KC_K,       KC_L,     KC_SCLN,  KC_QUOT,
        OSMLS,      KC_Z,    KC_X,      KC_C,   KC_V,   KC_B,                                               KC_N,    KC_M,   KC_COMM,    KC_DOT,   KC_SLSH,  OSMRS,
        CW_TOGG,    L2,      OSMWin,    L1,                                                                                  KC_UP,  KC_DOWN,    KC_LEFT,  KC_RGHT,
                                                KC_SPC, KC_DEL,                                             KC_BSPC, KC_ENT,
                                                                KC_LCTL, KC_ENT,       KC_PGUP, KC_RCTL,
                                                                KC_LALT, SH_TG,        KC_PGDN, KC_RALT
    ),

    [_NUMPAD] = LAYOUT_5x7_2(
        _______,    KC_F1,    KC_F2,      KC_F3,   KC_F4,   KC_F5,     _______,                         KC_TRNS,   KC_F6,   KC_F7,     KC_F8,   KC_F9,      KC_F10,     XXXXXXX,
        _______,    KC_PDOT,  KC_P7,      KC_P8,   KC_P9,   KC_PAST,   KC_PMNS,                         XXXXXXX,   KC_HOME, KC_END,    KC_UP,   XXXXXXX,    KC_PGUP,    XXXXXXX,
        _______,    KC_P0,    KC_P4,      KC_P5,   KC_P6,   KC_PSLS,   KC_PPLS,                         XXXXXXX,   XXXXXXX, KC_LEFT,   KC_DOWN, KC_RGHT,    XXXXXXX,    XXXXXXX,
        _______,    KC_NO,    KC_P1,      KC_P2,   KC_P3,   KC_PEQL,                                               KC_PGUP, XXXXXXX,   XXXXXXX, XXXXXXX,    XXXXXXX,    QK_BOOT,
        _______,    _______,  _______,    _______,                                                                                     XXXXXXX, XXXXXXX,    XXXXXXX,    XXXXXXX,
                                                   _______, _______,                                               _______, _______,
                                                                       _______, _______,       _______, _______,
                                                                       _______, _______,       _______, _______
    ),

    [_FN] = LAYOUT_5x7_2(
        _______,    _______,  _______,    _______,   _______,   _______,   _______,                         _______,   _______, _______,   _______, _______,    _______,    _______,
        _______,    _______,  _______,    _______,   _______,   _______,   _______,                         _______,   _______, _______,   _______, _______,    _______,    _______,
        _______,    _______,  _______,    _______,   _______,   _______,   _______,                         _______,   _______, _______,   _______, _______,    _______,    _______,
        _______,    _______,  _______,    _______,   _______,   _______,                                               _______, _______,   _______, _______,    _______,    _______,
        _______,    _______,  _______,    _______,                                                                                         DM_REC1, DM_PLY1,    DM_REC2,    DM_PLY2,
                                                     _______, _______,                                                 _______, _______,
                                                                           _______, _______,       _______, _______,
                                                                           _______, _______,       _______, _______
    )
};

#ifdef CONSOLE_ENABLE
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // If console is enabled, it will print the matrix position and status of each key pressed
    uprintf("KL: kc: 0x%04X, col: %2u, row: %2u, pressed: %u, time: %5u, int: %u, count: %u\n", 
        keycode, record->event.key.col, record->event.key.row, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count);
    return true;
}
#endif 