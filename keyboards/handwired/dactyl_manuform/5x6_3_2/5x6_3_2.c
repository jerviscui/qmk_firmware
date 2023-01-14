#include "5x6_3_2.h"
#include "print.h"

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

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  // If console is enabled, it will print the matrix position and status of each key pressed
#ifdef CONSOLE_ENABLE
    uprintf("KL: kc: 0x%04X, col: %2u, row: %2u, pressed: %u, time: %5u, int: %u, count: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count);
#endif

    switch (keycode)
    {
        case KC_ESC:
            if (!record->event.pressed)
            {
                /* on key up */
                clear_mods();
            }
            return true;            /* process keycode as usual */
    }

  return true;
}

// int clear = 0;
// void oneshot_mods_changed_user(uint8_t mods) {
//     //mods
//     //lctrl 1   0000_0001
//     //rctrl 16  0001_0000
//     //lalt  4   0000_0100
//     //ralt  64  0100_0000
//     //lsft  2   0001_0010
//     //rsft  32  0010_0000
//     //win   8   0000_1000

// uint8_t real_mods = get_mods();

// #ifdef CONSOLE_ENABLE
//     uprintf("mods: %u, real_mods: %u, SHIFT: %u, CTRL: %u, ALT: %u, GUI: %u\n", mods, real_mods, MOD_MASK_SHIFT, MOD_MASK_CTRL, MOD_MASK_ALT, MOD_MASK_GUI);
// #endif

//     if (mods == 4) {
//         println("xxxx on");
//     }

//     if (mods & MOD_MASK_SHIFT) {
// #ifdef CONSOLE_ENABLE
//         println("MOD_MASK_SHIFT on");
// #endif
//         if (mods != 2 && mods != 32) {
//             clear++;
//         }
//     }
//     if (mods & MOD_MASK_CTRL) {
// #ifdef CONSOLE_ENABLE
//         println("MOD_MASK_CTRL on");
// #endif
//         if (mods != 1 && mods != 16) {
//             clear++;
//         }
//     }
//     if (mods & MOD_MASK_ALT) {
// #ifdef CONSOLE_ENABLE
//         println("MOD_MASK_ALT on");
// #endif
//         if (mods != 4 && mods != 64) {
//             clear++;
//         }
//     }
//     if (mods & MOD_MASK_GUI) {
// #ifdef CONSOLE_ENABLE
//         println("MOD_MASK_GUI on");
// #endif 
//         if (mods != 8) {
//             clear++;
//         }
//     }

//     if (!mods) {
// #ifdef CONSOLE_ENABLE
//         println("Oneshot mods off");
// #endif 
//         if(clear != 0){
//             clear = 0;
//             // clear_mods();
//         }
//     }

// #ifdef CONSOLE_ENABLE
//     uprintf("clear: %u\n", clear);
// #endif 
// }