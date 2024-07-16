SRC += $(USER_PATH)/keyrecords/process_records.c

EXTRAKEY_ENABLE = yes

# Enable NKRO by default
NKRO_ENABLE ?= yes
CAPS_WORD_ENABLE ?= yes

KEY_LOCK_ENABLE = no
# Custom options

CUSTOM_SHIFT_KEYS_ENABLED ?= yes
ifeq ($(strip $(CUSTOM_SHIFT_KEYS_ENABLED)), yes)
    SRC += $(USER_PATH)/keyrecords/custom_shift_keys.c
    OPT_DEFS += -DCUSTOM_SHIFT_KEYS_ENABLED
endif


# Enables home row mod-tap keys on default layer
HOME_ROW_MODTAP_ENABLE ?= yes
ifeq ($(strip $(HOME_ROW_MODTAP_ENABLE)), yes)
    OPT_DEFS += -DHOME_ROW_MODTAP_ENABLE
endif

# Order for home row mods for ALL layers
# Default: ACSG/⎇ ⎈⇧◆
HOME_ROW_MOD_ORDER ?= ALT CTL SFT GUI
OPT_DEFS += -D_M1=$(word 1, $(HOME_ROW_MOD_ORDER))\
            -D_M2=$(word 2, $(HOME_ROW_MOD_ORDER))\
            -D_M3=$(word 3, $(HOME_ROW_MOD_ORDER))\
            -D_M4=$(word 4, $(HOME_ROW_MOD_ORDER))

