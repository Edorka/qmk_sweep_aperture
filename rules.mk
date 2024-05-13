LTO_ENABLE = yes
CONVERT_TO = promicro_rp2040

### SRC += features/auto_shift.c
### INTROSPECTION_KEYMAP_C = features/combo.c # Replace SRC, see issue #21137
###  SRC += features/leader.c
## SRC += oled/oled.c

OLED_ENABLE = yes

MOUSEKEY_ENABLE = yes
AUTO_SHIFT_ENABLE = no
AUTO_SHIFT_MODIFIERS = no
COMBO_ENABLE = no
LEADER_ENABLE = yes
KEY_OVERRIDE_ENABLE = yes

UNICODE_ENABLE = yes
SEND_STRING_ENABLE = yes
TAP_DANCE_ENABLE = yes
RGBLIGHT_ENABLE = yes
RGB_MATRIX_ENABLE = yes
