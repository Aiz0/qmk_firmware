/* Copyright 2019 Thomas Baart <thomas@splitkb.com_wrapper>
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
#include "aiz.h"

#define XXX KC_NO
#define LAYOUT_split_4x5( \
         K00, K01, K02, K03, K04,                          K05, K06, K07, K08, K09, \
         K10, K11, K12, K13, K14,                          K15, K16, K17, K18, K19, \
         K20, K21, K22, K23, K24,                          K25, K26, K27, K28, K29, \
                   K30, K31, K32, K33, K34,     K35, K36, K37, K38, K39 \
) \
LAYOUT_wrapper( \
    XXX, K00, K01, K02, K03, K04,                         K05, K06, K07, K08, K09, GAMING_ON, \
    XXX, K10, K11, K12, K13, K14,                         K15, K16, K17, K18, K19, XXX, \
    XXX, K20, K21, K22, K23, K24, XXX, XXX,     XXX, XXX, K25, K26, K27, K28, K29, XXX, \
                   K30, K31, K32, K33, K34,     K35, K36, K37, K38, K39 \
)

#define LAYOUT_split_3x5_3( \
         K00, K01, K02, K03, K04,                         K05, K06, K07, K08, K09, \
         K10, K11, K12, K13, K14,                         K15, K16, K17, K18, K19, \
         K20, K21, K22, K23, K24,                         K25, K26, K27, K28, K29, \
                             K32, K33, K34,     K35, K36, K37 \
) \
LAYOUT_wrapper( \
    XXX, K00, K01, K02, K03, K04,                         K05, K06, K07, K08, K09, XXX, \
    XXX, K10, K11, K12, K13, K14,                         K15, K16, K17, K18, K19, XXX, \
    XXX, K20, K21, K22, K23, K24, XXX, XXX,     XXX, XXX, K25, K26, K27, K28, K29, XXX, \
                   XXX, XXX, K32, K33, K34,     K35, K36, K37, XXX, XXX \
)


#define LAYOUT_split_4x5_wrapper(...)               LAYOUT_split_4x5(__VA_ARGS__)
#define LAYOUT_split_3x5_3_wrapper(...)  LAYOUT_split_3x5_3(__VA_ARGS__)


// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_COLEMAK_DH] = LAYOUT_split_4x5_wrapper(
        ______________COLEMAK_MOD_DH_L1____________,                    ______________COLEMAK_MOD_DH_R1____________,
        ______________COLEMAK_MOD_DH_L2____________,                    ______________COLEMAK_MOD_DH_R2____________,
        ______________COLEMAK_MOD_DH_L3____________,                    ______________COLEMAK_MOD_DH_R3____________,
                           ADJUST, XXX, _____THUMB_LEFT_____,   _____THUMB_RIGHT____, XXX, KC_APP
    ),

    [_GAMING] = LAYOUT_wrapper(
        _________________GAMING_L1_________________,                    _________________GAMING_R1_________________,
        _________________GAMING_L2_________________,                    _________________GAMING_R2_________________,
        _________________GAMING_L3_________________, XXX,XXX,   XXX,XXX,_________________GAMING_R3_________________,
                              XXX, XXX, ___GAMING_THUMB_L___,   ___GAMING_THUMB_R___, XXX, XXX

    ),

    [_NUMBER] = LAYOUT_split_3x5_3_wrapper(
        _________________NUMPAD_1__________________,                    XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX,
        _________________NUMPAD_2__________________,                    _____________HOME_ROW_MODS_RIGHT___________,
        _________________NUMPAD_3__________________,                    XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX,
                                        ____NUMPAD_THUMB____,   ____________________
    ),

    [_SYMBOL] = LAYOUT_split_3x5_3_wrapper(
        _________________SYMBOL_L1_________________,                    _________________SYMBOL_R1_________________,
        _________________SYMBOL_L2_________________,                    _________________SYMBOL_R2_________________,
        _________________SYMBOL_L3_________________,                    _________________SYMBOL_R3_________________,
                                        ____SYMBOL_THUMB____,   ____________________
    ),

    [_FUNCTION] = LAYOUT_split_3x5_3_wrapper(
        ________________FUNCTION_L1________________,                    XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX,
        ________________FUNCTION_L2________________,                    _____________HOME_ROW_MODS_RIGHT___________,
        ________________FUNCTION_L3________________,                    XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX,
                                        ___FUNCTION_THUMB___,   ____________________
    ),

    [_NAVIGATION] = LAYOUT_split_3x5_3_wrapper(
        _______________NAVIGATION_L1_______________,                    _______________NAVIGATION_R1_______________,
        _______________NAVIGATION_L2_______________,                    _______________NAVIGATION_R2_______________,
        _______________NAVIGATION_L3_______________,                    _______________NAVIGATION_R3_______________,
                                        ____________________,   _____THUMB_R_NO_LT__
    ),

    [_SPECIAL] = LAYOUT_split_3x5_3_wrapper(
        ________________SPECIAL_L1_________________,                    ________________SPECIAL_R1_________________,
        ________________SPECIAL_L2_________________,                    ________________SPECIAL_R2_________________,
        ________________SPECIAL_L3_________________,                    ________________SPECIAL_R3_________________,
                                        ____________________,   ___SPECIAL_THUMB____
    ),

    [_ADJUST] = LAYOUT_split_4x5_wrapper(
        _________________ADJUST_L1_________________,                    _________________ADJUST_R1_________________,
        ENCODER_RGB_SPEED, ENCODER_RGB_VALUE, ENCODER_RGB_SAT, ENCODER_RGB_HUE, ENCODER_RGB_MODE, _________________ADJUST_R2_________________,
        _________________ADJUST_L3_________________,                    _________________ADJUST_R3_________________,
                        ADJUST, XXXXXXX,____________________,   ____________________,XXXXXXX, RGB_TOG
    )
};
