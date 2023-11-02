// Copyright 2022 beekeeb
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum unicode_names {
    DEBAE,
    DESAE,
    DEBOE,
    DESOE,
    DEBUE,
    DESUE,
    POOP,
    WINK,
    SMILE,
    ASTONISHED,
    CRY,
    HEART,
    THUMBSUP,
    THUMBSDOWN,
    SEENOEVIL,
    HEARNOEVIL,
    SPEAKNOEVIL,
    SKULL,
    EXPLODE,
    FISTBOX,
    GRIMACE,
    HEXPLODE,
    ROBOT,
    BUG,
    FRIES,
};

enum tab_dance_names {
  TD_CTRLS_C,
  TD_DASH_EQ,
  TD_SLSH_CMM,
};

const uint32_t PROGMEM unicode_map[] = {
    [DEBAE] = 0x00C4,  // Ä
    [DESAE] = 0x00E4, // ä
    [DEBOE] = 0x00D6,  // Ö
    [DESOE] = 0x00F6,  // ö
    [DEBUE] = 0x00DC, // Ü
    [DESUE] = 0x00FC, // ü
    [POOP] = 0x1F4A9,
    [WINK] = 0x1F609,
    [SMILE] = 0x1F642,
    [ASTONISHED] = 0x1F632,
    [CRY] = 0x1F62D,
    [HEART] = 0x2764,
    [THUMBSUP] = 0x1F44D,
    [THUMBSDOWN] = 0x1F44E,
    [SEENOEVIL] = 0x1F648,
    [HEARNOEVIL] = 0x1F649,
    [SPEAKNOEVIL] = 0x1F64A,
    [SKULL] = 0x1F480,
    [EXPLODE] = 0x1F4A5,
    [FISTBOX] = 0x1F91C,
    [GRIMACE] = 0x1F62C,
    [HEXPLODE] = 0x1F92F,
    [ROBOT] = 0x1F916,
    [BUG] = 0x1F41B,
    [FRIES] = 0x1F35F,
};

tap_dance_action_t tap_dance_actions[] = {
  [TD_CTRLS_C] = ACTION_TAP_DANCE_DOUBLE(KC_F12, RCS(KC_C)),
  [TD_DASH_EQ] = ACTION_TAP_DANCE_DOUBLE(KC_MINS, KC_EQL),
  [TD_SLSH_CMM] = ACTION_TAP_DANCE_DOUBLE(KC_SLSH, RCTL(KC_SLSH)),
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
     /*
      * ┌───┬───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┬───┐
      * │Tab│ Q │ W │ E │ R │ T │       │ Y │ U │ I │ O │ P │Bsp│
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │Ctl│ A │ S │ D │ F │ G │       │ H │ J │ K │ L │ ; │ ' │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │Sft│ Z │ X │ C │ V │ B │       │ N │ M │ , │ . │ / │Sft│
      * └───┴───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┴───┘
      *               ┌───┐                   ┌───┐
      *               │GUI├───┐           ┌───┤Alt│
      *               └───┤Bsp├───┐   ┌───┤Ent├───┘
      *                   └───┤   │   │   ├───┘
      *                       └───┘   └───┘
      */

    [0] = LAYOUT_split_3x6_3(
        KC_ESC,         KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,           KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           TD(TD_DASH_EQ),
        LCTL(KC_C),     LALT_T(KC_A),   LSFT_T(KC_S),   LCTL_T(KC_D),   LT(3,KC_F),     LT(1,KC_G),     LT(3,KC_H),     LT(1,KC_J),     RCTL_T(KC_K),   RSFT_T(KC_L),   RALT_T(KC_SCLN),KC_QUOT,
        LCTL(KC_V),     KC_Z,           KC_X,           LGUI_T(KC_C),   LT(2,KC_V),     LT(4,KC_B),     LT(4,KC_N),     LT(2,KC_M),     RGUI_T(KC_COMM),KC_DOT,         TD(TD_SLSH_CMM),KC_UNDS,
                                                        TD(TD_CTRLS_C), LCA(KC_N),      KC_TAB,         KC_ENT,         KC_SPC,         KC_BSPC
    ),

    [1] = LAYOUT_split_3x6_3(
        KC_ESC,         KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          KC_NO,          KC_7,           KC_8,          KC_9,            KC_BSLS,        KC_TRNS,
        KC_TRNS,        LALT_T(KC_F6),  LSFT_T(KC_F7),  LCTL_T(KC_F8),  KC_F9,          KC_F10,         KC_NO,          KC_4,           RCTL_T(KC_5),  RSFT_T(KC_6),    RALT_T(KC_GRV), KC_QUOT,
        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_F11,         KC_F12,         KC_0,           KC_1,           KC_2,          KC_3,            KC_TRNS,        KC_UNDS,
                                                        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_ENT,         KC_SPC,         KC_BSPC
    ),

    [2] = LAYOUT_split_3x6_3(
        KC_ESC,         KC_TRNS,        KC_CIRC,        KC_AMPR,        KC_PERC,        LSFT(KC_GRV),   KC_LT,          KC_LBRC,        KC_RBRC,        KC_TRNS,        KC_TRNS,        KC_TRNS,
        KC_TRNS,        KC_ASTR,        KC_HASH,        KC_AT,          KC_EXLM,        KC_DLR,         KC_GT,          KC_LCBR,        KC_RCBR,        KC_TRNS,        KC_TRNS,        KC_TRNS,
        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_LPRN,        KC_RPRN,        KC_TRNS,        KC_TRNS,        KC_TRNS,
                                                        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_ENT,         KC_SPC,         KC_BSPC
    ),

    [3] = LAYOUT_split_3x6_3(
        KC_ESC,         KC_BRIU,        KC_WSCH,        KC_WBAK,        KC_WFWD,        KC_WREF,        RCTL(KC_X),     KC_HOME,         KC_UP,         KC_END,         KC_PGUP,        KC_PPLS,
        KC_TRNS,        LALT_T(KC_BRID),LSFT_T(KC_TRNS),LCTL_T(KC_MUTE),KC_MPLY,        KC_VOLU,        RCTL(KC_C),     KC_LEFT,         KC_DOWN,       KC_RGHT,        KC_PGDN,        KC_PMNS,
        KC_TRNS,        SGUI(KC_S),     LGUI(KC_E),     KC_MSTP,        KC_MFFD,        KC_VOLD,        RCTL(KC_V),     RCTL(KC_Z),      RCTL(KC_Y),    KC_APP,         KC_TRNS,        KC_DEL,
                                                        KC_TRNS,        LCA_T(KC_TRNS), C_S_T(KC_TRNS), KC_ENT,         KC_SPC,          KC_BSPC
    ),

    [4] = LAYOUT_split_3x6_3(
        UM(HEARNOEVIL),         UM(SKULL),       UM(ASTONISHED),  UM(HEART),      UM(ROBOT),      UM(HEXPLODE),     KC_NO,        UM(DEBAE),        UM(DEBOE),        UM(DEBUE),        KC_NO,        KC_NO,
        UM(SEENOEVIL),          UM(POOP),        UM(CRY),         UM(WINK),       UM(FISTBOX),    UM(EXPLODE),      KC_NO,        UP(DESAE, DEBAE), UP(DESOE, DEBOE), UP(DESUE, DEBUE), KC_E,         KC_NO,
        UM(SPEAKNOEVIL),        KC_LSFT,         UM(FRIES),       UM(BUG),        UM(GRIMACE),    UM(SMILE),        KC_NO,        KC_NO,            KC_NO,            KC_NO,            KC_NO,        KC_NO,
                                                                  TD(TD_CTRLS_C), KC_NO,          KC_TAB,           KC_ENT,       KC_SPC,           KC_BSPC
    )
};
