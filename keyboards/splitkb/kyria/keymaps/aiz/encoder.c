#include QMK_KEYBOARD_H
#include "aiz.h"


#ifdef ENCODER_ENABLE

void encoder_action_volume(bool clockwise) {
    if (clockwise)
        tap_code(KC_VOLU);
    else
        tap_code(KC_VOLD);
}

void encoder_action_mediatrack(bool clockwise) {
    if (clockwise)
        tap_code(KC_MEDIA_NEXT_TRACK);
    else
        tap_code(KC_MEDIA_PREV_TRACK);
}

void encoder_action_navword(bool clockwise) {
    if (clockwise)
        tap_code16(LCTL(KC_RGHT));
    else
        tap_code16(LCTL(KC_LEFT));
}

void encoder_action_navpage(bool clockwise) {
    if (clockwise)
        tap_code16(KC_PGUP);
    else
        tap_code16(KC_PGDN);
}

#ifdef RGBLIGHT_ENABLE
void encoder_action_rgb_speed(bool clockwise) {
    if (clockwise)
        rgblight_increase_speed_noeeprom();
    else
        rgblight_decrease_speed_noeeprom();
}
void encoder_action_rgb_hue(bool clockwise) {
    if (clockwise)
        rgblight_increase_hue_noeeprom();
    else
        rgblight_decrease_hue_noeeprom();
}
void encoder_action_rgb_saturation(bool clockwise) {
    if (clockwise)
        rgblight_increase_sat_noeeprom();
    else
        rgblight_decrease_sat_noeeprom();
}
void encoder_action_rgb_brightness(bool clockwise) {
    if (clockwise)
        rgblight_increase_val_noeeprom();
    else
        rgblight_decrease_val_noeeprom();
}
void encoder_action_rgb_mode(bool clockwise) {
    if (clockwise)
        rgblight_step_noeeprom();
    else
        rgblight_step_reverse_noeeprom();
}

void encoder_rgb_actions(bool clockwise){
    /*
    switch (encoder_rgb_state) {
        case ENCODER_RGB_HUE:
            encoder_action_rgb_hue(clockwise);
            break;
        case ENCODER_RGB_SPEED:
            encoder_action_rgb_speed(clockwise);
            break;
        default:
            encoder_action_rgb_mode(clockwise);
            break;
    }
    */
}

#endif // RGBLIGHT_ENABLE

/*
bool encoder_update_user(uint8_t index, bool clockwise) {

    if (index == 0) {
        encoder_action_volume(clockwise);
    } else if (index == 1) {

        switch (get_highest_layer(layer_state)) {
            case _NAVIGATION:
                encoder_action_navword(clockwise);
                break;
            case _ADJUST:
                encoder_rgb_actions(clockwise);
                break;
            default:
                encoder_action_navpage(clockwise);
                break;
        }
    }
    return false;
}
*/
#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [_COLEMAK_DH] =   { ENCODER_CCW_CW(KC_MS_WH_UP, KC_MS_WH_DOWN), ENCODER_CCW_CW(KC_VOLD, KC_VOLU)  },
    //[_LOWER] =  { ENCODER_CCW_CW(RGB_HUD, RGB_HUI),           ENCODER_CCW_CW(RGB_SAD, RGB_SAI)  },
    //[_RAISE] =  { ENCODER_CCW_CW(RGB_VAD, RGB_VAI),           ENCODER_CCW_CW(RGB_SPD, RGB_SPI)  },
    [_ADJUST] = { ENCODER_CCW_CW(RGB_RMOD, RGB_MOD),          ENCODER_CCW_CW(KC_RIGHT, KC_LEFT) },
};
#endif

#endif
