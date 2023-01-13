/*
Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#include "config_common.h"

/* key matrix size */
// left rows + right rows
#define MATRIX_ROWS 14
#define MATRIX_COLS 7

// wiring of each half
#define MATRIX_ROW_PINS { D0, D4, C6, D7, E6, B4, B5 }
#define MATRIX_COL_PINS { F5, F6, F7, B1, B3, B2, B6 }

// COL2ROW 表示二极管指向行导线，反之 ROW2COL 二极管指列
#define DIODE_DIRECTION COL2ROW

#undef SOFT_SERIAL_PIN
#define SOFT_SERIAL_PIN D1  // or D0, D2, D3

// WS2812 RGB LED strip input and number of LEDs
// // 连接led数据引脚
// #define RGB_DI_PIN D3
// // 连接的led数量
// #define RGBLED_NUM 12
// // (可选)对于分割键盘，每一半直接连接到RGB_DI_PIN的led数量
// #define RGBLED_SPLIT 12

#define DYNAMIC_MACRO_NO_NESTING

#define SPLIT_USB_DETECT
