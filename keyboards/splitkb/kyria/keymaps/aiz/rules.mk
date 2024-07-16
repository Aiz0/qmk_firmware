OLED_ENABLE = yes
OLED_DRIVER = ssd1306   # Enables the use of OLED displays
ENCODER_ENABLE = yes       # Enables the use of one or more encoders
ENCODER_MAP_ENABLE = no   # Enables encoder maps
RGBLIGHT_ENABLE = yes      # Enable keyboard RGB underglow
WPM_ENABLE = yes

#SWAP_HANDS_ENABLE = yes

SRC +=  oled.c \
        encoder.c
