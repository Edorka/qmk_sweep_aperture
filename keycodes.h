// Copyright 2023 Florent Linguenheld (@FLinguenheld)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once
#include "keymap_us_extended.h"


// Left-hand home row mods
#define HOME_A LGUI_T(KC_A)
#define HOME_S LALT_T(KC_S)
#define HOME_D LSFT_T(KC_D)
#define HOME_F LCTL_T(KC_F)

// Right-hand home row mods
#define HOME_J RCTL_T(KC_J)
#define HOME_K RSFT_T(KC_K)
#define HOME_L LALT_T(KC_L)
#define HOME_SCLN RGUI_T(KC_SCLN)

enum custom_keys {
  UNICODE = QK_KB_0, // Replace SAFE_RANGE, see pr #19909

  /* See auto-shift */
  CS_A_GRAVE,
  CS_E_GRAVE,
  CS_U_GRAVE,

  CS_A_CIRCUMFLEX,
  CS_E_CIRCUMFLEX,
  CS_I_CIRCUMFLEX,
  CS_O_CIRCUMFLEX,
  CS_U_CIRCUMFLEX,

  CS_E_DIAERESIS,
  CS_I_DIAERESIS,
  CS_U_DIAERESIS,
  CS_Y_DIAERESIS,
};
