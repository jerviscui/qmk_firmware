#include "5x6_3_2.h"
#include "print.h"

enum custom_layer { _QWERTY, _FN, _NUMPAD };

#ifdef SWAP_HANDS_ENABLE
// __attribute__ ((weak))
// swap-hands action needs a matrix to define the swap
const keypos_t hand_swap_config[MATRIX_ROWS][MATRIX_COLS] = {
    /* Left hand, matrix positions */
    {{0, 0}, {1, 7}, {2, 7}, {3, 7}, {4, 7}, {5, 7}, {6, 0}},
    {{0, 1}, {1, 8}, {2, 8}, {3, 8}, {4, 8}, {5, 8}, {6, 1}},
    {{0, 2}, {1, 9}, {2, 9}, {3, 9}, {4, 9}, {5, 9}, {6, 2}},
    {{0, 3}, {1, 10}, {2, 10}, {3, 10}, {4, 10}, {5, 10}, {6, 3}},
    {{0, 4}, {1, 4}, {2, 4}, {3, 4}, {4, 4}, {5, 4}, {6, 4}},
    {{0, 5}, {1, 5}, {2, 5}, {3, 5}, {4, 5}, {5, 5}, {6, 5}},
    {{0, 6}, {1, 6}, {2, 6}, {3, 6}, {4, 6}, {5, 6}, {6, 6}},
    /* Right hand, matrix positions */
    {{0, 7}, {1, 7}, {2, 7}, {3, 7}, {4, 7}, {5, 7}, {6, 7}},
    {{0, 8}, {1, 8}, {2, 8}, {3, 8}, {4, 8}, {5, 8}, {6, 8}},
    {{0, 9}, {1, 9}, {2, 9}, {3, 9}, {4, 9}, {5, 9}, {6, 9}},
    {{0, 10}, {1, 10}, {2, 10}, {3, 10}, {4, 10}, {5, 10}, {6, 10}},
    {{0, 11}, {1, 11}, {2, 11}, {3, 11}, {4, 11}, {5, 11}, {6, 11}},
    {{0, 12}, {1, 12}, {2, 12}, {3, 12}, {4, 12}, {5, 12}, {6, 12}},
    {{0, 13}, {1, 13}, {2, 13}, {3, 13}, {4, 13}, {5, 13}, {6, 13}},
};
#endif

// void keyboard_post_init_user(void) {
//   // 输出调试内容
//     debug_enable=true;
// //   debug_matrix=true;
// //   debug_keyboard=true;
// //   debug_mouse=true;
// }

bool alt_pressed = false;
bool suppress_alt = false;

bool replace_alt_combo(keyrecord_t *record, uint16_t replace) {
    if (record->event.pressed) {
        suppress_alt = true;
        if (alt_pressed) {
            register_code(replace);
            return false;
        }
    } else {
        suppress_alt = false;
        if (alt_pressed) {
            unregister_code(replace);
            return false;
        }
    }

    return true;
}

bool pre_process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_I:
        case KC_J:
        case KC_K:
        case KC_L:
        case KC_Y:
        case KC_U:
        case KC_N:
        case KC_P:
            if (record->event.pressed) {
                suppress_alt = true;
            }
            break;
    }

    return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // If console is enabled, it will print the matrix position and status of each key pressed
#ifdef CONSOLE_ENABLE
    uprintf("KL: kc: 0x%04X, col: %2u, row: %2u, pressed: %u, time: %5u, int: %u, count: %u\n",
        keycode, record->event.key.col, record->event.key.row, record->event.pressed,
        record->event.time, record->tap.interrupted, record->tap.count);
#endif

    switch (keycode) {
        case KC_ESC:
            if (!record->event.pressed) {
                /* on key up */
                clear_mods();
            }
            break; /* process keycode as usual */
        case OSM(MOD_LALT):
#ifdef CONSOLE_ENABLE
            println("OSM(MOD_LALT)");
#endif
            // hold
            if (record->tap.count == 0) {
                // press
                if (record->event.pressed) {
                    // self or combo key is ijklyunp
                    if (record->tap.interrupted == 0 || suppress_alt) {
                        alt_pressed = true;
                        return false;
                    }
                }
                // release
                else {
#ifdef CONSOLE_ENABLE
                    uprintf("Release: mods: %08b, oneshot: %08b\n", get_mods(), get_oneshot_mods());
#endif
                    alt_pressed = false;
                    if (get_mods() & MOD_BIT(KC_LALT)) {
                        del_mods(MOD_BIT(KC_LALT));
                    }
                    del_oneshot_mods(MOD_BIT_LALT);
                    del_oneshot_locked_mods(MOD_BIT_LALT);
                    return false;
                }
            }
            break;
        case KC_I:
            return replace_alt_combo(record, KC_UP);
        case KC_J:
            return replace_alt_combo(record, KC_LEFT);
        case KC_K:
            return replace_alt_combo(record, KC_DOWN);
        case KC_L:
            return replace_alt_combo(record, KC_RGHT);
        case KC_Y:
            return replace_alt_combo(record, KC_HOME);
        case KC_U:
            return replace_alt_combo(record, KC_END);
        case KC_N:
            return replace_alt_combo(record, KC_PGDN);
        case KC_P:
            return replace_alt_combo(record, KC_PGUP);
    }

    return true;
}

void send_combo(uint8_t codeOne, uint8_t codeTwo) {
    wait_ms(1);
    register_code(codeOne);
    tap_code_delay(codeTwo, 1);
    unregister_code(codeOne);
}

layer_state_t layer_state_set_user(layer_state_t state) {
#ifdef CONSOLE_ENABLE
    uprintf("%08lX\n", state);
    uprintf("%2u\n", get_highest_layer(state));
    layer_debug();
#endif

    if (IS_LAYER_ON_STATE(state, _NUMPAD)) {
        led_t led_state = host_keyboard_led_state();
#ifdef CONSOLE_ENABLE
        uprintf("num: %2u, caps: %2u, scroll: %2u\n", led_state.num_lock, led_state.caps_lock, led_state.scroll_lock);
#endif
        if (!led_state.num_lock) {
            tap_code(KC_NUM_LOCK);
        }
    }

    switch (get_highest_layer(state)) {
        case _QWERTY:
            send_combo(KC_F15, KC_1);
            break;
        case _FN:
            send_combo(KC_F15, KC_2);
            break;
        case _NUMPAD:
            send_combo(KC_F15, KC_3);
            break;
    }

    return state;
}

void swap_hands_toggle_user(void) {
    if (is_swap_hands_on()) {
        send_combo(KC_F15, KC_9);
    } else {
        send_combo(KC_F15, KC_0);
    }
}

void oneshot_locked_mods_changed_user(uint8_t mods, uint8_t locked_mods) {
#ifdef CONSOLE_ENABLE
    // uprint_hex32();
    // uprint_bin32();
    uprintf("%08b\n%08b\n", mods, locked_mods);
#endif

    if (mods == 0) {
#ifdef CONSOLE_ENABLE
        println("Oneshot mods off");
#endif
        // when clear_oneshot_locked_mods
        send_combo(KC_F16, KC_2);
        send_combo(KC_F16, KC_4);
        send_combo(KC_F16, KC_6);
        send_combo(KC_F16, KC_8);
        send_combo(KC_F16, KC_0);
    }

    if (mods & MOD_BIT_LSHIFT) {
#ifdef CONSOLE_ENABLE
        println("Oneshot mods LSHIFT");
#endif
        if (locked_mods & MOD_BIT_LSHIFT) {
            // locked
            send_combo(KC_F16, KC_1);
        } else {
            // release
            send_combo(KC_F16, KC_2);
        }
    } else if (mods & MOD_BIT_RSHIFT) {
#ifdef CONSOLE_ENABLE
        println("Oneshot mods RSHIFT");
#endif
        if (locked_mods & MOD_BIT_RSHIFT) {
            send_combo(KC_F16, KC_3);
        } else {
            send_combo(KC_F16, KC_4);
        }
    } else if (mods & MOD_BIT_LALT) {
#ifdef CONSOLE_ENABLE
        println("Oneshot mods LALT");
#endif
        if (locked_mods & MOD_BIT_LALT) {
            send_combo(KC_F16, KC_5);
        } else {
            send_combo(KC_F16, KC_6);
        }
    } else if (mods & MOD_BIT_LCTRL) {
#ifdef CONSOLE_ENABLE
        println("Oneshot mods LCTRL");
#endif
        if (locked_mods & MOD_BIT_LCTRL) {
            send_combo(KC_F16, KC_7);
        } else {
            send_combo(KC_F16, KC_8);
        }
    } else if (mods & MOD_BIT_LGUI) {
#ifdef CONSOLE_ENABLE
        println("Oneshot mods LGUI");
#endif
        if (locked_mods & MOD_BIT_LGUI) {
            send_combo(KC_F16, KC_9);
        } else {
            send_combo(KC_F16, KC_0);
        }
    }
}
