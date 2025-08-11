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

enum tab_dance_names {
    TD_CTRLS_C,
    TD_DASH_EQ,
    TD_SLSH_CMM,
    TD_JUMP_ONE,
    TD_W_LBRC,
    TD_E_LCBR,
    TD_R_LPRN,
    TD_T_LT,
    TD_Y_GT,
    TD_U_RPRN,
    TD_I_RCBR,
    TD_O_RBRC,
    TD_QUOT_GRV,
    TD_P_ARRF,
    // TD_Z_AND,
    TD_B_AND,
    // TD_X_OR,
    TD_N_OR,
    TD_Q_3EQ,
};

void p_arr_finished (tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        register_code(KC_P);
    } else if (state->count == 2) {
        SEND_STRING("=>");
    }
}

void p_arr_reset (tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        unregister_code(KC_P);
    }
}

// void z_and_finished (tap_dance_state_t *state, void *user_data) {
//     if (state->count == 1) {
//         register_code(KC_Z);
//     } else if (state->count == 2) {
//         SEND_STRING("&&");
//     }
// }

// void z_and_reset (tap_dance_state_t *state, void *user_data) {
//     if (state->count == 1) {
//         unregister_code(KC_Z);
//     }
// }

void b_and_finished (tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        register_code(KC_B);
    } else if (state->count == 2) {
        SEND_STRING("&&");
    }
}

void b_and_reset (tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        unregister_code(KC_B);
    }
}

// void x_or_finished (tap_dance_state_t *state, void *user_data) {
//     if (state->count == 1) {
//         register_code(KC_X);
//     } else if (state->count == 2) {
//         SEND_STRING("||");
//     }
// }

// void x_or_reset (tap_dance_state_t *state, void *user_data) {
//     if (state->count == 1) {
//         unregister_code(KC_X);
//     }
// }

void n_or_finished (tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        register_code(KC_N);
    } else if (state->count == 2) {
        SEND_STRING("||");
    }
}

void n_or_reset (tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        unregister_code(KC_N);
    }
}

void q_equal_finished (tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        register_code(KC_Q);
    } else if (state->count == 2) {
        SEND_STRING("===");
    }
}

void q_equal_reset (tap_dance_state_t *state, void *user_data) {
    if (state->count == 1) {
        unregister_code(KC_Q);
    }
}

tap_dance_action_t tap_dance_actions[] = {
    [TD_CTRLS_C] = ACTION_TAP_DANCE_DOUBLE(KC_F12, RCS(KC_C)),
    [TD_DASH_EQ] = ACTION_TAP_DANCE_DOUBLE(KC_MINS, KC_EQL),
    [TD_SLSH_CMM] = ACTION_TAP_DANCE_DOUBLE(KC_SLSH, RCTL(KC_SLSH)),
    [TD_JUMP_ONE] = ACTION_TAP_DANCE_DOUBLE(KC_SPACE, KC_RGHT),
    [TD_W_LBRC] = ACTION_TAP_DANCE_DOUBLE(KC_W, KC_LBRC),
    [TD_E_LCBR] = ACTION_TAP_DANCE_DOUBLE(KC_E, KC_LCBR),
    [TD_R_LPRN] = ACTION_TAP_DANCE_DOUBLE(KC_R, KC_LPRN),
    [TD_T_LT] = ACTION_TAP_DANCE_DOUBLE(KC_T, KC_LT),
    [TD_Y_GT] = ACTION_TAP_DANCE_DOUBLE(KC_Y, KC_GT),
    [TD_U_RPRN] = ACTION_TAP_DANCE_DOUBLE(KC_U, KC_RPRN),
    [TD_I_RCBR] = ACTION_TAP_DANCE_DOUBLE(KC_I, KC_RCBR),
    [TD_O_RBRC] = ACTION_TAP_DANCE_DOUBLE(KC_O, KC_RBRC),
    [TD_QUOT_GRV] = ACTION_TAP_DANCE_DOUBLE(KC_QUOT, KC_GRV),
    [TD_P_ARRF] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, p_arr_finished, p_arr_reset),
    // [TD_Z_AND] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, z_and_finished, z_and_reset),
    [TD_B_AND] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, b_and_finished, b_and_reset),
    // [TD_X_OR] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, x_or_finished, x_or_reset),
    [TD_N_OR] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, n_or_finished, n_or_reset),
    [TD_Q_3EQ] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, q_equal_finished, q_equal_reset),
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
        KC_ESC,         TD(TD_Q_3EQ),   TD(TD_W_LBRC),  TD(TD_E_LCBR),  TD(TD_R_LPRN),  TD(TD_T_LT),    TD(TD_Y_GT),    TD(TD_U_RPRN),  TD(TD_I_RCBR),  TD(TD_O_RBRC),  TD(TD_P_ARRF),  TD(TD_DASH_EQ),
        LCTL(KC_C),     LALT_T(KC_A),   LSFT_T(KC_S),   LCTL_T(KC_D),   LT(1,KC_F),     LT(4,KC_G),     LT(4,KC_H),     LT(1,KC_J),     RCTL_T(KC_K),   RSFT_T(KC_L),   RALT_T(KC_SCLN),TD(TD_QUOT_GRV),
        LCTL(KC_V),     KC_Z,           KC_X,           LGUI_T(KC_C),   LT(3,KC_V),     TD(TD_B_AND),   TD(TD_N_OR),    LT(3,KC_M),     RGUI_T(KC_COMM),KC_DOT,         TD(TD_SLSH_CMM),KC_UNDS,
                                                        TD(TD_CTRLS_C), LCA(KC_N),      KC_TAB,         KC_ENT,         TD(TD_JUMP_ONE),KC_BSPC
    ),

    [1] = LAYOUT_split_3x6_3(
        KC_ESC,         KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          RCTL(KC_X),     KC_HOME,         KC_UP,         KC_END,         KC_PGUP,        KC_PPLS,
        KC_TRNS,        LALT_T(KC_F6),  LSFT_T(KC_F7),  LCTL_T(KC_F8),  KC_F9,          KC_F10,         RCTL(KC_C),     KC_LEFT,         KC_DOWN,       KC_RGHT,        KC_PGDN,        KC_PMNS,
        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_F11,         KC_F12,         RCTL(KC_V),     RCTL(KC_Z),      RCTL(KC_Y),    KC_APP,         KC_TRNS,        KC_DEL,
                                                        KC_TRNS,        KC_TRNS,        KC_TRNS,        KC_ENT,         KC_TRNS,         KC_TRNS
    ),

    [3] = LAYOUT_split_3x6_3(
        KC_ESC,         KC_BRIU,        KC_WSCH,        KC_WBAK,        KC_WFWD,        KC_WREF,        KC_EXLM,        KC_7,           KC_8,          KC_9,            KC_BSLS,        KC_TRNS,
        KC_TRNS,        LALT_T(KC_BRID),LSFT_T(KC_TRNS),LCTL_T(KC_MUTE),KC_MPLY,        KC_VOLU,        KC_AT,          KC_4,           RCTL_T(KC_5),  RSFT_T(KC_6),    RALT_T(KC_GRV), KC_TRNS,
        KC_TRNS,        SGUI(KC_S),     LGUI(KC_E),     KC_MSTP,        KC_MFFD,        KC_VOLD,        KC_0,           KC_1,           KC_2,          KC_3,            KC_TRNS,        KC_TRNS,
                                                        KC_TRNS,        LCA_T(KC_TRNS), C_S_T(KC_TRNS), KC_ENT,         KC_TRNS,        KC_TRNS
    ),

    [4] = LAYOUT_split_3x6_3(
        UM(HEARNOEVIL),         UM(SKULL),       UM(ASTONISHED),  UM(HEART),      UM(ROBOT),      UM(HEXPLODE),     KC_NO,        UM(DEBAE),        UM(DEBOE),        UM(DEBUE),        KC_NO,        KC_NO,
        UM(SEENOEVIL),          UM(POOP),        UM(CRY),         UM(WINK),       UM(FISTBOX),    UM(EXPLODE),      KC_NO,        UP(DESAE, DEBAE), UP(DESOE, DEBOE), UP(DESUE, DEBUE), KC_E,         KC_NO,
        UM(SPEAKNOEVIL),        KC_LSFT,         UM(FRIES),       UM(BUG),        UM(GRIMACE),    UM(SMILE),        KC_NO,        KC_NO,            KC_NO,            KC_NO,            KC_NO,        KC_NO,
                                                                  TD(TD_CTRLS_C), KC_NO,          KC_TAB,           KC_ENT,       KC_TRNS,          KC_TRNS
    ),
};
