#pragma once
#include "aiz.h"
#include "quantum.h"


// Used to expand macros within macros
#define _EVAL(x, y) x##y

// The "mod" parameter should be any mod _M1..._M4 defined in rules.mk
// based on HOME_ROW_MOD_ORDER

// NORMAL MODS
#define _ML(mod) _EVAL(KC_L, mod)
#define _MR(mod) _EVAL(KC_R, mod)

// MODTAP
#define _MTL(mod, key) MT( _EVAL(MOD_L, mod) , key)
#define _MTR(mod, key) MT( _EVAL(MOD_R, mod) , key)

// enable/disable in rules.mk
#ifdef HOME_ROW_MODTAP_ENABLE
    // Home row Mod taps For left hand M1 -> M4
    #define _HRMTL(a, b, c, d) _MTL(_M1, a), _MTL(_M2, b), _MTL(_M3, c), _MTL(_M4, d)
    // Home row Mod taps For right hand are mirrored M4 -> M1
    #define _HRMTR(a, b, c, d) _MTR(_M4, a), _MTR(_M3, b), _MTR(_M2, c), _MTL(_M1, d)
#else
    // no modtap :(
    #define _HRMTL(a, b, c, d) a, b, c, d
    #define _HRMTR(a, b, c, d) a, b, c, d
#endif

// Layout blocks

// clang-format off

// Colemak Mod-DH with quote and semicolon swapped
#define ______________COLEMAK_MOD_DH_L1____________             KC_Q,   KC_W,   KC_F,   KC_P,   KC_B
#define ______________COLEMAK_MOD_DH_L2____________     _HRMTL( KC_A,   KC_R,   KC_S,   KC_T),  KC_G
#define ______________COLEMAK_MOD_DH_L3____________             KC_Z,   KC_X,   KC_C,   KC_D,   KC_V

#define ______________COLEMAK_MOD_DH_R1____________     KC_J,           KC_L,   KC_U,   KC_Y,   KC_QUOT
#define ______________COLEMAK_MOD_DH_R2____________     KC_M,   _HRMTR( KC_N,   KC_E,   KC_I,   KC_O)
#define ______________COLEMAK_MOD_DH_R3____________     KC_K,           KC_H,   KC_COMM,KC_DOT, KC_SLASH

#define _____THUMB_LEFT_____                            LT(_SPECIAL, KC_ESC),   LT(_NAVIGATION, KC_SPC),    LT(_ADJUST, KC_TAB)
#define _____THUMB_RIGHT____                            LT(_SYMBOL, KC_ENT),    LT(_NUMBER, KC_BSPC),       LT(_FUNCTION, KC_DEL)

// Thumb keys without layertap
#define _____THUMB_L_NO_LT__                            KC_ESC, KC_SPC, KC_TAB
#define _____THUMB_R_NO_LT__                            KC_ENT, KC_BSPC, KC_DEL

// layaut blocks used for multiple layers
#define _____________HOME_ROW_MODS_LEFT____________     _ML(_M1), _ML(_M2), _ML(_M3), _ML(_M4), XXXXXXX
#define _____________HOME_ROW_MODS_RIGHT___________     XXXXXXX,  _MR(_M4), _MR(_M3), _MR(_M2), _ML(_M1)

#define XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
#define ___________________________________________     _______, _______, _______, _______, _______
#define ____________________                            _______, _______, _______




// Navigaton VI-style
#define _______________NAVIGATION_L1_______________     XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
#define _______________NAVIGATION_L2_______________     _____________HOME_ROW_MODS_LEFT____________
#define _______________NAVIGATION_L3_______________     XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

#define _______________NAVIGATION_R1_______________     KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_INS
#define _______________NAVIGATION_R2_______________     KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, CW_TOGG
#define _______________NAVIGATION_R3_______________     KC_AGIN, KC_PSTE, KC_COPY, KC_CUT,  KC_UNDO


// Numpad
// can be put on the left or right.
#define _________________NUMPAD_1__________________     KC_LBRC,    KC_7,   KC_8,   KC_9,   KC_RBRC
#define _________________NUMPAD_2__________________     KC_SCLN,    KC_4,   KC_5,   KC_6,   KC_EQL
#define _________________NUMPAD_3__________________     KC_GRV,     KC_1,   KC_2,   KC_3,   KC_BSLS
#define ____NUMPAD_THUMB____                                        KC_DOT, KC_0,   KC_MINS

// Symbol
#ifdef MIRYOKU_SYMBOL_LAYER

#define _________________SYMBOL_L1_________________     KC_LCBR,    KC_AMPR,    KC_ASTR,    KC_LPRN,    KC_RCBR
#define _________________SYMBOL_L2_________________     KC_COLN,    KC_DLR,     KC_PERC,    KC_CIRC,    KC_PLUS
#define _________________SYMBOL_L3_________________     KC_TILD,    KC_EXLM,    KC_AT,      KC_HASH,    KC_PIPE
#define ____SYMBOL_THUMB____                                                    KC_LPRN,    KC_RPRN,    KC_UNDS

#define _________________SYMBOL_R1_________________     XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
#define _________________SYMBOL_R2_________________     _____________HOME_ROW_MODS_RIGHT___________
#define _________________SYMBOL_R3_________________     XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

#else

#define _________________SYMBOL_L1_________________     KC_QUOT, KC_LABK, KC_RABK, KC_DQUO, KC_DOT
#define _________________SYMBOL_L2_________________     KC_EXLM, KC_MINS, KC_PLUS, KC_EQL , KC_HASH
#define _________________SYMBOL_L3_________________     KC_CIRC, KC_SLSH, KC_ASTR, KC_BSLS, UPDIR
#define ____SYMBOL_THUMB____                            KC_LPRN,    KC_RPRN,    KC_UNDS

#define _________________SYMBOL_R1_________________     KC_AMPR, KC_SCLN, KC_LBRC, KC_RBRC, KC_PERC
#define _________________SYMBOL_R2_________________     KC_PIPE, KC_COLN, KC_LPRN, KC_RPRN, KC_GRV
#define _________________SYMBOL_R3_________________     KC_TILD, KC_DLR , KC_LCBR, KC_RCBR, KC_AT

#endif



//  Special
//  Symbols and letters accessible with ALTGR on EurKEY layout

#define ________________SPECIAL_L1_________________     XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
#define ________________SPECIAL_L2_________________     _____________HOME_ROW_MODS_LEFT____________
#define ________________SPECIAL_L3_________________     XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

#define ________________SPECIAL_R1_________________     ALGR(KC_4),     ALGR(KC_1),     ALGR(KC_2),     ALGR(KC_3),     ALGR(KC_MINS)
#define ________________SPECIAL_R2_________________     ALGR(KC_5),     ALGR(KC_W),     ALGR(KC_A),     ALGR(KC_O),     ALGR(KC_EQL)
#define ________________SPECIAL_R3_________________     ALGR(KC_SCLN),  ALGR(KC_BSLS),  RSA(KC_SCLN),   RSA(KC_DOT),    ALGR(KC_DOT)
#define ___SPECIAL_THUMB____                            RSA(KC_7),      ALGR(KC_LBRC),  ALGR(KC_RBRC)

// Mouse
#define __________________MOUSE_R1_________________     KC_WH_L,    KC_WH_D,    KC_WH_U,    KC_WH_R,    XXXXXXX
#define __________________MOUSE_R2_________________     KC_MS_L,    KC_MS_D,    KC_MS_U,    KC_MS_R,    XXXXXXX
#define __________________MOUSE_R3_________________     _______________NAVIGATION_R3_______________
#define ____MOUSE_THUMB_____                            KC_BTN1,    KC_BTN3,    KC_BTN2


#define ________________FUNCTION_L1________________      KC_F12, KC_F7, KC_F8, KC_F9, KC_PSCR
#define ________________FUNCTION_L2________________      KC_F11, KC_F4, KC_F5, KC_F6, KC_SLCT
#define ________________FUNCTION_L3________________      KC_F10, KC_F1, KC_F2, KC_F3, KC_PAUS
#define ___FUNCTION_THUMB___                             KC_APP, _______, _______


#define _________________ADJUST_L1_________________     EE_CLR, XXXXXXX, XXXXXXX, XXXXXXX, NK_ON
#define _________________ADJUST_L2_________________     XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
#define _________________ADJUST_L3_________________     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, NK_OFF

#define _________________ADJUST_R1_________________     XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
#define _________________ADJUST_R2_________________     RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, RGB_MOD
#define _________________ADJUST_R3_________________     XXXXXXX, RGB_HUD, RGB_SAD, RGB_VAD, RGB_RMOD


// Gaming
// Qwerty shifted one step right
// Requires 6 keys on left and right side since I put numbers there

#define _________________GAMING_L1_________________     KC_1,       KC_TAB,     KC_Q,       KC_W,       KC_E,       KC_R
#define _________________GAMING_L2_________________     KC_2,       KC_LSFT,    KC_A,       KC_S,       KC_D,       KC_F
#define _________________GAMING_L3_________________     KC_3,       KC_RCTL,    KC_Z,       KC_X,       KC_C,       KC_V
#define ___GAMING_THUMB_L___     KC_ESC,     KC_SPC,     KC_ENT

// Arrow keys and default layer keys.
// Number and function layer accessible with right thumb.
// turn layer off in top right

#define _________________GAMING_R1_________________     _______,    _______,    KC_UP,      _______,    _______,    GAMING_OFF
#define _________________GAMING_R2_________________     _______,    KC_LEFT,    KC_DOWN,    KC_RIGHT,   _______,    _______
#define _________________GAMING_R3_________________     _______,    _______,    _______,    _______,    _______,    _______
#define ___GAMING_THUMB_R___     KC_ENT, MO(_NUMBER), MO(_FUNCTION)

// clang-format on

// Layout wrappers
#define LAYOUT_wrapper(...) LAYOUT(__VA_ARGS__)
