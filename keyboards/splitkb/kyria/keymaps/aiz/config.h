/* Copyright 2022 Thomas Baart <thomas@splitkb.com>
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

#pragma once

#ifdef RGBLIGHT_ENABLE
#    //define RGBLIGHT_ANIMATIONS
#    define RGBLIGHT_EFFECT_RAINBOW_SWIRL
#    define RGBLIGHT_HUE_STEP  5
#    define RGBLIGHT_SAT_STEP  5
#    define RGBLIGHT_VAL_STEP  5
#    define RGBLIGHT_LIMIT_VAL 255
#    define RGBLIGHT_SLEEP
#    define RGBLIGHT_LED_MAP { 0, 1, 2, 3, 9, 8, 4, 5, 6, 7, 10, 11, 12, 13, 19, 18, 14, 15, 16, 17}
#endif

#ifdef OLED_ENABLE
#   define SPLIT_WPM_ENABLE
#   define OLED_FONT_H "keyboards/splitkb/kyria/keymaps/aiz/glcdfont.c"
#endif
