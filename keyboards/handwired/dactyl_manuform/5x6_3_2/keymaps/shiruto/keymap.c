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
#define SWITCH LALT(KC_TAB)
#define TASK   LCTL(LSFT(KC_ESC))
#define TAB_R  LCTL(KC_TAB)
#define TAB_L  LCTL(LSFT(KC_TAB))
#define TAB_RO LCTL(LSFT(KC_T))

#define L1 TG(_FN)
#define L2 TG(_NUMPAD)

#define OSMLS OSM(MOD_LSFT)
#define OSMRS OSM(MOD_RSFT)
#define OSMLA OSM(MOD_LALT)
#define OSMRA OSM(MOD_RALT)
#define OSMLC OSM(MOD_LCTL)
#define OSMRC OSM(MOD_RCTL)
#define OSMWin OSM(MOD_LGUI)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT_5x6_3_2(
        KC_ESC,     KC_1,    KC_2,      KC_3,   KC_4,   KC_5,   KC_6,                         KC_7,     KC_8,    KC_9,   KC_0,       KC_MINS,     KC_EQL,     KC_GRV,
        KC_TAB,     KC_Q,    KC_W,      KC_E,   KC_R,   KC_T,   XXXXXXX,                        KC_UP,    KC_Y,    KC_U,   KC_I,       KC_O,     KC_P,     KC_BSLS,
        KC_CAPS,     KC_A,    KC_S,      KC_D,   KC_F,   KC_G,  L1,                         KC_DOWN,    KC_H,    KC_J,   KC_K,       KC_L,     KC_SCLN,  KC_QUOT,
        KC_LSFT,      KC_Z,    KC_X,      KC_C,   KC_V,   KC_B,                                               KC_N,    KC_M,   KC_COMM,    KC_DOT,   KC_SLSH,  KC_ENT,
        KC_LCTL,    KC_LALT,      KC_LEFT,  KC_RGHT,                                                                                  KC_LBRC,      KC_RBRC,  KC_LEFT,  KC_RGHT,
                                                KC_LSFT, KC_LGUI,                                             KC_LGUI, KC_RSFT,
                                                                KC_DEL,  KC_PGUP,         KC_HOME,   KC_BSPC,
                                                                L2,  KC_PGDN,        KC_END, KC_SPC
    ),

    [_FN] = LAYOUT_5x6_3_2(
        _______,    _______,    _______,      _______,     _______,     _______,     _______,               _______,   _______,   _______,     KC_PSLS,   KC_PAST,      KC_PMNS,     _______,
        _______,    _______,  _______,    _______,   _______,   _______,   QK_BOOT,                         _______,   _______, KC_P7,   KC_P8, KC_P9,    KC_PPLS,    _______,
        _______,    _______,  _______,    _______,   _______,   _______,   _______,                         _______,   _______, KC_P4,   KC_P5, KC_P6,    KC_ENT,    _______,
        _______,    _______,  _______,    _______,   _______,   _______,                                               _______, KC_P1,   KC_P2, KC_P3,    KC_ENT,    _______,
        _______,    _______,  _______,    _______,                                                                                         KC_P0, KC_PDOT,    _______,    _______,
                                                     _______,   _______,                                               _______, _______,
                                                                           _______, _______,       _______, _______,
                                                                           _______, _______,       _______, _______
    ),

    [_NUMPAD] = LAYOUT_5x6_3_2(
        _______,    KC_F1,    KC_F2,      KC_F3,   KC_F4,   KC_F5,     KC_F6,                         KC_F7,   KC_F8,     KC_F9,     KC_F10,     KC_F11,      KC_F12,     _______,
        _______,    _______,  _______,      KC_UP,   _______,   _______,   _______,                         _______,   _______,   _______,    KC_UP,     _______,    _______,    _______,
        _______,    _______,    KC_LEFT,      KC_DOWN,   KC_RGHT,   _______,   _______,                         _______,   _______,   KC_LEFT,   KC_DOWN,   KC_RGHT,    _______,    _______,
        _______,    _______,  _______,      _______,   _______,   _______,                                               _______,   _______,   _______,   _______,    _______,    _______,
        _______,    _______,  _______,    _______,                                                                                       _______,   _______,    _______,    _______,
                                                   _______, _______,                                               _______, KC_BSPC,
                                                                       _______, _______,       _______, _______,
                                                                       _______, _______,       _______, _______
    )
};
