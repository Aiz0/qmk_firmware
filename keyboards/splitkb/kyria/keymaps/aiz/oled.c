#include QMK_KEYBOARD_H
#include "aiz.h"
#include "oled.h"


oled_rotation_t oled_init_user(oled_rotation_t rotation) { return OLED_ROTATION_180; }

static void oled_render_layer_state(void) {
    switch (get_highest_layer(layer_state|default_layer_state)) {
        case _COLEMAK_DH:
            oled_write_ln_P(PSTR("Colemak-DH"), false);
            break;
        case _GAMING:
            oled_write_ln_P(PSTR("Gaming"), false);
            break;
        case _NAVIGATION:
            oled_write_ln_P(PSTR("Navigation"), false);
            break;
        case _NUMBER:
            oled_write_ln_P(PSTR("Number"), false);
            break;
        case _SYMBOL:
            oled_write_ln_P(PSTR("Symbol"), false);
            break;
        case _SPECIAL:
            oled_write_ln_P(PSTR("Special"), false);
            break;
        case _FUNCTION:
            oled_write_ln_P(PSTR("Function"), false);
            break;
        case _ADJUST:
            oled_write_ln_P(PSTR("Adjust"), false);
            break;
        default:
            oled_write_ln_P(PSTR("Undefined"), false);
    }
}

static void oled_render_mashiro(void) {
    oled_write_raw_P(mashiro, sizeof(mashiro));
}


static void oled_render_mod_status(uint8_t x, uint8_t y) {

    const uint8_t modifiers = get_mods() | get_oneshot_mods();
    const bool alt = modifiers & MOD_MASK_ALT;
    const bool ctrl = modifiers & MOD_MASK_CTRL;
    const bool gui = modifiers & MOD_MASK_GUI;
    const bool shift = modifiers & MOD_MASK_SHIFT;

    // 
    for (uint8_t i = 0; i < 2; i++) {
        oled_set_cursor(x,y+i);
        oled_write_P(gui_icon[gui][i], false);
        oled_write_P(icon_filler[gui][alt][i],false);
        oled_write_P(alt_icon[alt][i], false);

        oled_set_cursor(x, y+i+2);
        oled_write_P(ctrl_icon[ctrl][i], false);
        oled_write_P(icon_filler[ctrl][shift][i],false);
        oled_write_P(shift_icon[shift][i], false);
    }

}

#ifdef RGBLIGHT_ENABLE

static void oled_render_rgb_status(void){
    char rgb_str[4];
    oled_write_P(PSTR("RGB: "), false);
    oled_write_ln_P(rgblight_is_enabled() ? PSTR("on"): PSTR("off"), false);

    oled_write_P(PSTR("Mode: "), false);
    itoa(rgblight_get_mode(), rgb_str, DECIMAL);
    oled_write_ln(rgb_str, false);

    oled_write_P(PSTR("Hue: "), false);
    itoa(rgblight_get_hue(), rgb_str, DECIMAL);
    oled_write_ln(rgb_str, false);

    oled_write_P(PSTR("Sat: "), false);
    itoa(rgblight_get_sat(), rgb_str, DECIMAL);
    oled_write_ln(rgb_str, false);

    oled_write_P(PSTR("Val: "), false);
    itoa(rgblight_get_val(), rgb_str, DECIMAL);
    oled_write_ln(rgb_str, false);

    oled_write_P(PSTR("Speed: "), false);
    itoa(rgblight_get_speed(), rgb_str, DECIMAL);
    oled_write_ln(rgb_str, false);
}
#endif

#ifdef WPM_ENABLE
static void oled_render_wpm(void) {
    static char wpm_str[4];
    itoa(get_current_wpm(), wpm_str, DECIMAL);
    oled_set_cursor(0, 7);
    oled_write_P(PSTR("WPM: "), false);
    oled_write(wpm_str, false);
}
#endif

static void oled_render_adjust_info(void){
    #ifdef RGBLIGHT_ENABLE
        oled_render_rgb_status();
    #endif
}

void oled_render_status(void){
    oled_render_layer_state();
    if(layer_state_is(_ADJUST)){
        adjust_info_rendered = true;
        oled_render_adjust_info();
        oled_advance_page(true);
    } else {
        if(adjust_info_rendered) {
            oled_clear();
            adjust_info_rendered = false;
        }
        oled_render_mod_status(16,2);
    }
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        oled_render_status();
    } else {
        //render_kyria_logo();
        oled_render_mashiro();
        #ifdef WPM_ENABLE
            oled_render_wpm();
        #endif
    }
    return false;
}
