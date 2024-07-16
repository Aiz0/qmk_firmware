#include "aiz.h"

#include "custom_shift_keys.h"
const custom_shift_key_t custom_shift_keys[] = {
  {KC_DOT , KC_QUES}, // Shift . is ?
  {KC_COMM, KC_EXLM}, // Shift , is !
  {KC_SLSH, KC_PIPE}, // Shift / is |
};

uint8_t NUM_CUSTOM_SHIFT_KEYS =
    sizeof(custom_shift_keys) / sizeof(custom_shift_key_t);

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    #ifdef CUSTOM_SHIFT_KEYS_ENABLED
    if (!process_custom_shift_keys(keycode, record)) { return false; }
    #endif
  return true;
}
