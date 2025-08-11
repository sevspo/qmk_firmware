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
        KC_ESC,         KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,           KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_MINS,
        LCTL(KC_C),     LALT_T(KC_A),   LSFT_T(KC_S),   LCTL_T(KC_D),   LT(1,KC_F),     LT(3,KC_G),     LT(3,KC_H),     LT(1,KC_J),     RCTL_T(KC_K),   RSFT_T(KC_L),   RALT_T(KC_SCLN),KC_QUOT,
        LCTL(KC_V),     KC_Z,           KC_X,           KC_C,           LT(2,KC_V),     LT(4,KC_B),     LT(4,KC_N),     LT(2,KC_M),     RGUI_T(KC_COMM),KC_DOT,         KC_SLSH,        KC_UNDS,
                                                        KC_F12,         KC_NO,          KC_TAB,         KC_ENT,         KC_SPC,         KC_BSPC
    ),

    [1] = LAYOUT_split_3x6_3(
        KC_ESC,         KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          KC_LBRC,        KC_7,           KC_8,          KC_9,            KC_EQL,         KC_MINS,
        KC_TRNS,        LALT_T(KC_F6),  LSFT_T(KC_F7),  LCTL_T(KC_F8),  KC_F9,          KC_F10,         KC_RBRC,        KC_4,           RCTL_T(KC_5),  RSFT_T(KC_6),    RALT_T(KC_0),   KC_BSLS,
        KC_TRNS,        KC_F11,         KC_F12,         KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_GRV,         KC_1,           KC_2,          KC_3,            KC_SLSH,        KC_UNDS,
                                                        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_ENT,         KC_SPC,         KC_BSPC
    ),

    [2] = LAYOUT_split_3x6_3(
        KC_ESC,         KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_LBRC,        KC_RBRC,        KC_TRNS,        KC_TRNS,        KC_TRNS,
        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_LT,          KC_LCBR,        KC_RCBR,        KC_TRNS,        KC_TRNS,        KC_BSLS,
        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_GT,          KC_LPRN,        KC_RPRN,        KC_TRNS,        KC_TRNS,        KC_TRNS,
                                                        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_ENT,         KC_SPC,         KC_BSPC
    ),

    [3] = LAYOUT_split_3x6_3(
        KC_ESC,         KC_BRIU,        KC_WSCH,        KC_WBAK,        KC_WFWD,        KC_WREF,        KC_X,        KC_HOME,        KC_UP,        KC_END,        KC_PGUP,        KC_PPLS,
        KC_TRNS,        LALT_T(KC_BRID),        LSFT_T(KC_TRNS),        LCTL_T(KC_MUTE),        KC_MPLY,        KC_VOLU,        KC_C,        KC_LEFT,        KC_DOWN,        KC_RGHT,        KC_PGDN,        KC_PMNS,
        KC_TRNS,        SGUI(KC_S),        LGUI(KC_E),        KC_MSTP,        KC_MFFD,        KC_VOLD,        KC_V,        KC_Z,        KC_Y,        KC_APP,        QK_BOOT,        KC_DEL,
        KC_TRNS,        LCA_T(KC_TRNS),        C_S_T(KC_TRNS),        KC_ENT,        KC_SPC,        KC_BSPC
    ),

    [4] = LAYOUT_split_3x6_3(
        KC_NO,          KC_NO,        KC_NO,        KC_NO,        KC_NO,        KC_NO,        KC_NO,        KC_NO,        KC_NO,        KC_NO,        KC_NO,        KC_NO,
        KC_NO,          UM(POOP),        LSFT_T(UM(CRY)),        UM(WINK),        UM(FISTBOX),        UM(EXPLODE),        KC_NO,        UP(DESAE, DEBAE),        UP(DESOE, DEBOE),        UP(DESUE, DEBUE),        KC_E,        KC_NO,
        KC_NO,          KC_NO,        KC_NO,        KC_NO,        KC_NO,        UM(SMILE),        KC_NO,        KC_NO,        KC_NO,        KC_NO,        KC_NO,        KC_NO,
        KC_F12,         KC_NO,      KC_TAB,       KC_ENT,       KC_SPC,        KC_BSPC
    )
};
