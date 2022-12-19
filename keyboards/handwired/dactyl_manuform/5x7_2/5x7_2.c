#include "5x7_2.h"

#ifdef SWAP_HANDS_ENABLE
// __attribute__ ((weak))
// swap-hands action needs a matrix to define the swap
const keypos_t hand_swap_config[MATRIX_ROWS][MATRIX_COLS] = {
    /* Left hand, matrix positions */
    {{0, 0}, {7, 1}, {7, 2}, {7, 3}, {7, 4}, {7, 5}, {0, 6}},
    {{1, 0}, {8, 1}, {8, 2}, {8, 3}, {8, 4}, {8, 5}, {1, 6}},
    {{2, 0}, {9, 1}, {9, 2}, {9, 3}, {9, 4}, {9, 5}, {2, 6}},
    {{3, 0}, {10, 1}, {10, 2}, {10, 3}, {10, 4}, {10, 5}, {3, 6}},
    {{4, 0}, {4, 1}, {4, 2}, {4, 3}, {4, 4}, {4, 5}, {4, 6}},
    {{5, 0}, {5, 1}, {5, 2}, {5, 3}, {5, 4}, {5, 5}, {5, 6}},
    {{6, 0}, {6, 1}, {6, 2}, {6, 3}, {6, 4}, {6, 5}, {6, 6}},
    /* Right hand, matrix positions */
    {{7, 0}, {7, 1}, {7, 2}, {7, 3}, {7, 4}, {7, 5}, {7, 6}},
    {{8, 0}, {8, 1}, {8, 2}, {8, 3}, {8, 4}, {8, 5}, {8, 6}},
    {{9, 0}, {9, 1}, {9, 2}, {9, 3}, {9, 4}, {9, 5}, {9, 6}},
    {{10, 0}, {10, 1}, {10, 2}, {10, 3}, {10, 4}, {10, 5}, {10, 6}},
    {{11, 0}, {11, 1}, {11, 2}, {11, 3}, {11, 4}, {11, 5}, {11, 6}},
    {{12, 0}, {12, 1}, {12, 2}, {12, 3}, {12, 4}, {12, 5}, {12, 6}},
    {{13, 0}, {13, 1}, {13, 2}, {13, 3}, {13, 4}, {13, 5}, {13, 6}},
};
#endif

#ifdef CONSOLE_ENABLE
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // If console is enabled, it will print the matrix position and status of each key pressed
    uprintf("KL: kc: 0x%04X, col: %2u, row: %2u, pressed: %u, time: %5u, int: %u, count: %u\n", 
        keycode, record->event.key.col, record->event.key.row, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count);
    return true;
}
#endif 