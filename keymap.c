/* Copyright 2023 Florent Linguenheld (@FLinguenheld)
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

#include QMK_KEYBOARD_H
#include "keycodes.h"
enum custom_layers {
  _BASE,
  _LOWER,
  _RAISE,
  _ADJUST,
  _GAMING,
};
bool process_record_user(uint16_t keycode, keyrecord_t *record) {

    /* Macros */
    switch (keycode) {

        case UNICODE:
            if (record->event.pressed) {
                tap_code16(C(S(KC_U)));
            } break;
    }

    return true;
}
enum {
  TD_CM_SCLN,
  TD_DOT_CLN,
  TD_SPC_TAB,
  TD_Q_ESC
};
tap_dance_action_t tap_dance_actions[] = {
//  [TD_CM_SCLN] = ACTION_TAP_DANCE_DOUBLE(KC_COMM, KC_SCLN),
//  [TD_DOT_CLN] = ACTION_TAP_DANCE_DOUBLE(KC_DOT, KC_COLN),
//  [TD_SPC_TAB] = ACTION_TAP_DANCE_DOUBLE(KC_SPACE, KC_TAB),
  [TD_Q_ESC] = ACTION_TAP_DANCE_DOUBLE(KC_Q, KC_ESC)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_BASE] = LAYOUT(
    //|---------------+---------------+---------------+---------------+---------------|       |---------------+---------------+---------------+---------------+---------------|
        TD(TD_Q_ESC)  ,     KC_W      ,     KC_E      ,     KC_R      ,     KC_T      ,             KC_Y      ,      KC_U     ,      KC_I     ,      KC_O     ,      KC_P     ,
    //|---------------+---------------+---------------+---------------+---------------|       |---------------+---------------+---------------+---------------+---------------|
          HOME_A      ,   HOME_S      ,   HOME_D      ,   HOME_F      ,     KC_G      ,             KC_H      ,    HOME_J     ,    HOME_K     ,    HOME_L     ,    KC_QUOT    ,
    //|---------------+---------------+---------------+---------------+---------------|       |---------------+---------------+---------------+---------------+---------------|
            KC_Z      ,     KC_X      ,     KC_C      ,     KC_V      ,     KC_B      ,             KC_N      ,      KC_M     ,   KC_COMM      ,  KC_DOT      ,    KC_SLSH    ,
    //|---------------+---------------+---------------+---------------+---------------|       |---------------+---------------+---------------+---------------+---------------|
    //                               |-------------------------+-------------------------| |-------------------------+-------------------------|
                                          LT(_LOWER, KC_BSPC)  ,        KC_SPACE        ,            KC_ENT          ,   LT(_RAISE, KC_ESC)
    //                               |-------------------------+-------------------------| |-------------------------+-------------------------|
    ),
    [_GAMING] = LAYOUT(
    //|---------------+---------------+---------------+---------------+---------------|       |---------------+---------------+---------------+---------------+---------------|
        TD(TD_Q_ESC)  ,     KC_W      ,     KC_E      ,     KC_R      ,     KC_T      ,             KC_Y      ,      KC_U     ,      KC_I     ,      KC_O     ,      KC_P     ,
    //|---------------+---------------+---------------+---------------+---------------|       |---------------+---------------+---------------+---------------+---------------|
            KC_A      ,     KC_S      ,     KC_D      ,     KC_F      ,     KC_G      ,             KC_H      ,    HOME_J     ,    HOME_K     ,    HOME_L     ,    KC_QUOT    ,
    //|---------------+---------------+---------------+---------------+---------------|       |---------------+---------------+---------------+---------------+---------------|
            KC_Z      ,     KC_X      ,     KC_C      ,     KC_V      ,     KC_B      ,             KC_N      ,      KC_M     , TD(TD_CM_SCLN), TD(TD_DOT_CLN),    KC_SLSH    ,
    //|---------------+---------------+---------------+---------------+---------------|       |---------------+---------------+---------------+---------------+---------------|
    //                               |-------------------------+-------------------------| |-------------------------+-------------------------|
                                          LT(_LOWER, KC_BSPC)   ,     TD(TD_SPC_TAB)      ,            KC_ENT        ,  LT(_RAISE, MI_OFF)
    //                               |-------------------------+-------------------------| |-------------------------+-------------------------|
    ),

    [_RAISE] = LAYOUT(
    //|---------------+---------------+---------------+---------------+---------------|       |---------------+---------------+---------------+---------------+---------------|
          KC_EXLM     ,     KC_AT     ,    KC_HASH    ,     KC_DLR    ,    KC_PERC    ,           KC_CIRC     ,   KC_AMPR     ,   KC_ASTR     ,   KC_LPRN     ,    KC_RPRN    ,
    //|---------------+---------------+---------------+---------------+---------------|       |---------------+---------------+---------------+---------------+---------------|
            KC_F1     ,      KC_F2    ,     KC_F3     ,     KC_F4     ,    KC_F5      ,           KC_MINS     ,   KC_EQL      ,   KC_LCBR     ,   KC_RCBR     ,    KC_PIPE    , //KC_GRV,
    //|---------------+---------------+---------------+---------------+---------------|       |---------------+---------------+---------------+---------------+---------------|
            KC_F6     ,      KC_F7    ,     KC_F8     ,     KC_F9     ,    KC_F10     ,           KC_UNDS     ,   KC_PLUS     ,   KC_LBRC     ,   KC_RBRC     ,    KC_BSLS    , //KC_TILD,
    //|---------------+---------------+---------------+---------------+---------------|       |---------------+---------------+---------------+---------------+---------------|
    //                               |-------------------------+-------------------------| |-------------------------+-------------------------|
                                               MO(_ADJUST)     ,         KC_BSPC         ,          UNICODE          ,       _______
    //                               |-------------------------+-------------------------| |-------------------------+-------------------------|
    ),
    [_LOWER] = LAYOUT(
    //|---------------+---------------+---------------+---------------+---------------|       |---------------+---------------+---------------+---------------+---------------|
              KC_1    ,      KC_2     ,     KC_3      ,      KC_4     ,     KC_5      ,             KC_6      ,      KC_7     ,      KC_8     ,      KC_9     ,     KC_0      ,
    //|---------------+---------------+---------------+---------------+---------------|       |---------------+---------------+---------------+---------------+---------------|
          MS_LEFT  ,   MS_UP    ,  MS_DOWN   ,  MS_RGHT  ,    KC_ESC     ,            KC_LEFT    ,    KC_DOWN    ,     KC_UP     ,    KC_RIGHT   ,     KC_GRV    ,
    //|---------------+---------------+---------------+---------------+---------------|       |---------------+---------------+---------------+---------------+---------------|
          MS_BTN1  ,    XXXXXXX    ,  MS_BTN3   ,  MS_BTN2   ,    XXXXXXX    ,            KC_HOME    ,    KC_PGDN    ,    KC_PGUP    ,     KC_END    ,     KC_TILD   ,
    //|---------------+---------------+---------------+---------------+---------------|       |---------------+---------------+---------------+---------------+---------------|
    //                               |-------------------------+-------------------------| |-------------------------+-------------------------|
                                                _______        ,        _______          ,           KC_DEL          ,      MO(_ADJUST)
    //                               |-------------------------+-------------------------| |-------------------------+-------------------------|
    ),

    [_ADJUST] = LAYOUT(
    //|---------------+---------------+---------------+---------------+------------------|       |---------------+---------------+---------------+-----------------+----------|
           QK_BOOT    ,    XXXXXXX    ,    XXXXXXX    ,    XXXXXXX    ,  KC_PRINT_SCREEN ,            XXXXXXX    ,    XXXXXXX    ,    XXXXXXX    , KC_AUDIO_VOL_UP ,  XXXXXXX ,
    //|---------------+---------------+---------------+---------------+------------------|       |---------------+---------------+---------------+-----------------+----------|
           RM_TOGG    ,  G(C(S(KC_G))),    RM_SATU    ,    RM_VALU    ,S(KC_PRINT_SCREEN),            XXXXXXX    ,    XXXXXXX    ,    XXXXXXX    ,KC_AUDIO_VOL_DOWN,  XXXXXXX ,
    //|---------------+---------------+---------------+---------------+------------------|       |---------------+---------------+---------------+-----------------+----------|
           RM_NEXT    ,    RM_HUED    ,    RM_SATD    ,    RM_VALD    ,    RM_SPDD       ,            XXXXXXX    ,    XXXXXXX    ,    XXXXXXX    ,  KC_AUDIO_MUTE  ,  XXXXXXX ,
    //|---------------+---------------+---------------+---------------+------------------|       |---------------+---------------+---------------+-----------------+----------|
    //                                  |-------------------------+-------------------------| |-------------------------+-------------------------|
                                                   XXXXXXX        ,        _______          ,           XXXXXXX         ,       XXXXXXX
    //                                  |-------------------------+-------------------------| |-------------------------+-------------------------|,
    ),
};
const key_override_t p_delete_key_override = ko_make_basic(MOD_MASK_ALT, KC_P, KC_BSPC);
const key_override_t p_supr_key_override = ko_make_basic(MOD_MASK_CTRL, KC_P, KC_DEL);
const key_override_t qesc_key_override = ko_make_basic(MOD_MASK_CTRL, KC_Q, KC_ESC);
const key_override_t esp_tab_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_SPACE, KC_TAB);
const key_override_t dot_colon_key_override = ko_make_basic(MOD_MASK_CTRL, KC_DOT, KC_COLN);
const key_override_t comm_scln_key_override = ko_make_basic(MOD_MASK_CTRL, KC_COMMA, KC_SCLN);

// This globally defines all key overrides to be used
const key_override_t *key_overrides[] = {
    &p_delete_key_override,
    &p_supr_key_override,
    &qesc_key_override,
    &esp_tab_key_override,
    &dot_colon_key_override,
    &comm_scln_key_override,
};
