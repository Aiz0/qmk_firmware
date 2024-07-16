#pragma once

#include "aiz.h"

enum userspace_custom_keycodes {
    UPDIR = SAFE_RANGE,
    SCOPE,
    ENCODER_RGB_MODE,
    ENCODER_RGB_HUE,
    ENCODER_RGB_SAT,
    ENCODER_RGB_VALUE,
    ENCODER_RGB_SPEED,
    NEW_SAFE_RANGE                            // use "NEW_SAFE_RANGE for keymap specific codes
};

enum encoder_rgb_state {
    MODE,
    HUE,
    SAT,
    VALUE,
};

// Aliases for readability
#define ADJUST TG(_ADJUST)
#define GAMING_ON TO(_GAMING)   // Go from any layer to gaming and default
#define GAMING_OFF TG(_GAMING)  // Used to turn gaming layer off
