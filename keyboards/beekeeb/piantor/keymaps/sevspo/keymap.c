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
    TD_Q_3EQ,
    TD_W_LBRC,
    TD_E_LCBR,
    TD_R_LPRN,
    TD_T_LT,
    TD_Y_GT,
    TD_U_RPRN,
    TD_I_RCBR,
    TD_O_RBRC,
    TD_P_ARRF,
    TD_QUOT_GRV,
    TD_B_AND,
    TD_N_OR,
};

typedef enum {
  TD_NONE,
  TD_SINGLE_TAP,
  TD_DOUBLE_TAP,
  TD_TRIPLE_TAP,
  TD_SINGLE_HOLD
} td_state_t;

typedef struct {
  bool is_press_action;
  td_state_t state;
} tap;

static tap tab_state = {
  .is_press_action = true,
  .state = TD_NONE
};

td_state_t cur_dance(tap_dance_state_t *state) {
  if (state->count == 1) {
      return TD_SINGLE_TAP;
  } else if (state->count == 2) {
      if (!state->pressed) return TD_DOUBLE_TAP;
      else return TD_SINGLE_HOLD;
  } else if (state->count == 3) {
      return TD_TRIPLE_TAP;
  }
  return TD_NONE;
}

// TD_Q_3EQ
void td_q_3eq_finished(tap_dance_state_t *state, void *user_data) {
  tab_state.state = cur_dance(state);
  switch (tab_state.state) {
      case TD_SINGLE_TAP: register_code(KC_Q); break;
      case TD_DOUBLE_TAP: register_code(KC_Q); register_code(KC_Q); break;
      case TD_SINGLE_HOLD: SEND_STRING("==="); break;
      default: break;
  }
}

void td_q_3eq_reset(tap_dance_state_t *state, void *user_data) {
  switch (tab_state.state) {
      case TD_SINGLE_TAP: unregister_code(KC_Q); break;
      case TD_DOUBLE_TAP: unregister_code(KC_Q); unregister_code(KC_Q); break;
      default: break;
  }
  tab_state.state = TD_NONE;
}

// TD_W_LBRC
void td_w_lbrc_finished(tap_dance_state_t *state, void *user_data) {
  tab_state.state = cur_dance(state);
  switch (tab_state.state) {
      case TD_SINGLE_TAP: register_code(KC_W); break;
      case TD_DOUBLE_TAP: register_code(KC_W); register_code(KC_W); break;
      case TD_SINGLE_HOLD: register_code(KC_LBRC); break;
      default: break;
  }
}

void td_w_lbrc_reset(tap_dance_state_t *state, void *user_data) {
  switch (tab_state.state) {
      case TD_SINGLE_TAP: unregister_code(KC_W); break;
      case TD_DOUBLE_TAP: unregister_code(KC_W); unregister_code(KC_W); break;
      case TD_SINGLE_HOLD: unregister_code(KC_LBRC); break;
      default: break;
  }
  tab_state.state = TD_NONE;
}

// TD_E_LCBR
void td_e_lcbr_finished(tap_dance_state_t *state, void *user_data) {
  tab_state.state = cur_dance(state);
  switch (tab_state.state) {
      case TD_SINGLE_TAP: register_code(KC_E); break;
      case TD_DOUBLE_TAP: register_code(KC_E); register_code(KC_E); break;
      case TD_SINGLE_HOLD: register_code(KC_LSFT); register_code(KC_LBRC); break;
      case TD_TRIPLE_TAP: SEND_STRING("{{"); break;
      default: break;
  }
}

void td_e_lcbr_reset(tap_dance_state_t *state, void *user_data) {
  switch (tab_state.state) {
      case TD_SINGLE_TAP: unregister_code(KC_E); break;
      case TD_DOUBLE_TAP: unregister_code(KC_E); unregister_code(KC_E); break;
      case TD_SINGLE_HOLD: unregister_code(KC_LBRC); unregister_code(KC_LSFT); break;
      default: break;
  }
  tab_state.state = TD_NONE;
}

// TD_R_LPRN
void td_r_lprn_finished(tap_dance_state_t *state, void *user_data) {
  tab_state.state = cur_dance(state);
  switch (tab_state.state) {
      case TD_SINGLE_TAP: register_code(KC_R); break;
      case TD_DOUBLE_TAP: register_code(KC_R); register_code(KC_R); break;
      case TD_SINGLE_HOLD: register_code(KC_LSFT); register_code(KC_9); break;
      default: break;
  }
}

void td_r_lprn_reset(tap_dance_state_t *state, void *user_data) {
  switch (tab_state.state) {
      case TD_SINGLE_TAP: unregister_code(KC_R); break;
      case TD_DOUBLE_TAP: unregister_code(KC_R); unregister_code(KC_R); break;
      case TD_SINGLE_HOLD: unregister_code(KC_9); unregister_code(KC_LSFT); break;
      default: break;
  }
  tab_state.state = TD_NONE;
}

// TD_T_LT
void td_t_lt_finished(tap_dance_state_t *state, void *user_data) {
  tab_state.state = cur_dance(state);
  switch (tab_state.state) {
      case TD_SINGLE_TAP: register_code(KC_T); break;
      case TD_DOUBLE_TAP: register_code(KC_T); register_code(KC_T); break;
      case TD_SINGLE_HOLD: register_code(KC_LSFT); register_code(KC_COMMA); break;
      default: break;
  }
}

void td_t_lt_reset(tap_dance_state_t *state, void *user_data) {
  switch (tab_state.state) {
      case TD_SINGLE_TAP: unregister_code(KC_T); break;
      case TD_DOUBLE_TAP: unregister_code(KC_T); unregister_code(KC_T); break;
      case TD_SINGLE_HOLD: unregister_code(KC_COMMA); unregister_code(KC_LSFT); break;
      default: break;
  }
  tab_state.state = TD_NONE;
}

// TD_Y_GT
void td_y_gt_finished(tap_dance_state_t *state, void *user_data) {
  tab_state.state = cur_dance(state);
  switch (tab_state.state) {
      case TD_SINGLE_TAP: register_code(KC_Y); break;
      case TD_DOUBLE_TAP: register_code(KC_Y); register_code(KC_Y); break;
      case TD_SINGLE_HOLD: register_code(KC_LSFT); register_code(KC_DOT); break;
      default: break;
  }
}

void td_y_gt_reset(tap_dance_state_t *state, void *user_data) {
  switch (tab_state.state) {
      case TD_SINGLE_TAP: unregister_code(KC_Y); break;
      case TD_DOUBLE_TAP: unregister_code(KC_Y); unregister_code(KC_Y); break;
      case TD_SINGLE_HOLD: unregister_code(KC_DOT); unregister_code(KC_LSFT); break;
      default: break;
  }
  tab_state.state = TD_NONE;
}

// TD_U_RPRN
void td_u_rprn_finished(tap_dance_state_t *state, void *user_data) {
  tab_state.state = cur_dance(state);
  switch (tab_state.state) {
      case TD_SINGLE_TAP: register_code(KC_U); break;
      case TD_DOUBLE_TAP: register_code(KC_U); register_code(KC_U); break;
      case TD_SINGLE_HOLD: register_code(KC_LSFT); register_code(KC_0); break;
      default: break;
  }
}

void td_u_rprn_reset(tap_dance_state_t *state, void *user_data) {
  switch (tab_state.state) {
      case TD_SINGLE_TAP: unregister_code(KC_U); break;
      case TD_DOUBLE_TAP: unregister_code(KC_U); unregister_code(KC_U); break;
      case TD_SINGLE_HOLD: unregister_code(KC_0); unregister_code(KC_LSFT); break;
      default: break;
  }
  tab_state.state = TD_NONE;
}

// TD_I_RCBR
void td_i_rcbr_finished(tap_dance_state_t *state, void *user_data) {
  tab_state.state = cur_dance(state);
  switch (tab_state.state) {
      case TD_SINGLE_TAP: register_code(KC_I); break;
      case TD_DOUBLE_TAP: register_code(KC_I); register_code(KC_I); break;
      case TD_SINGLE_HOLD: register_code(KC_LSFT); register_code(KC_RBRC); break;
      case TD_TRIPLE_TAP: SEND_STRING("}}"); break;
      default: break;
  }
}

void td_i_rcbr_reset(tap_dance_state_t *state, void *user_data) {
  switch (tab_state.state) {
      case TD_SINGLE_TAP: unregister_code(KC_I); break;
      case TD_DOUBLE_TAP: unregister_code(KC_I); unregister_code(KC_I); break;
      case TD_SINGLE_HOLD: unregister_code(KC_RBRC); unregister_code(KC_LSFT); break;
      default: break;
  }
  tab_state.state = TD_NONE;
}

// TD_O_RBRC
void td_o_rbrc_finished(tap_dance_state_t *state, void *user_data) {
  tab_state.state = cur_dance(state);
  switch (tab_state.state) {
      case TD_SINGLE_TAP: register_code(KC_O); break;
      case TD_DOUBLE_TAP: register_code(KC_O); register_code(KC_O); break;
      case TD_SINGLE_HOLD: register_code(KC_RBRC); break;
      default: break;
  }
}

void td_o_rbrc_reset(tap_dance_state_t *state, void *user_data) {
  switch (tab_state.state) {
      case TD_SINGLE_TAP: unregister_code(KC_O); break;
      case TD_DOUBLE_TAP: unregister_code(KC_O); unregister_code(KC_O); break;
      case TD_SINGLE_HOLD: unregister_code(KC_RBRC); break;
      default: break;
  }
  tab_state.state = TD_NONE;
}

// TD_P_ARRF
void td_p_arrf_finished(tap_dance_state_t *state, void *user_data) {
  tab_state.state = cur_dance(state);
  switch (tab_state.state) {
      case TD_SINGLE_TAP: register_code(KC_P); break;
      case TD_DOUBLE_TAP: register_code(KC_P); register_code(KC_P); break;
      case TD_SINGLE_HOLD: SEND_STRING("=>"); break;
      default: break;
  }
}

void td_p_arrf_reset(tap_dance_state_t *state, void *user_data) {
  switch (tab_state.state) {
      case TD_SINGLE_TAP: unregister_code(KC_P); break;
      case TD_DOUBLE_TAP: unregister_code(KC_P); unregister_code(KC_P); break;
      default: break;
  }
  tab_state.state = TD_NONE;
}

// TD_B_AND
void td_b_and_finished(tap_dance_state_t *state, void *user_data) {
  tab_state.state = cur_dance(state);
  switch (tab_state.state) {
      case TD_SINGLE_TAP: register_code(KC_B); break;
      case TD_DOUBLE_TAP: register_code(KC_B); register_code(KC_B); break;
      case TD_SINGLE_HOLD: SEND_STRING("&&"); break;
      default: break;
  }
}

void td_b_and_reset(tap_dance_state_t *state, void *user_data) {
  switch (tab_state.state) {
      case TD_SINGLE_TAP: unregister_code(KC_B); break;
      case TD_DOUBLE_TAP: unregister_code(KC_B); unregister_code(KC_B); break;
      default: break;
    }
  tab_state.state = TD_NONE;
}

// TD_N_OR
void td_n_or_finished(tap_dance_state_t *state, void *user_data) {
  tab_state.state = cur_dance(state);
  switch (tab_state.state) {
      case TD_SINGLE_TAP: register_code(KC_N); break;
      case TD_DOUBLE_TAP: register_code(KC_N); register_code(KC_N); break;
      case TD_SINGLE_HOLD: SEND_STRING("||"); break;
      default: break;
  }
}

void td_n_or_reset(tap_dance_state_t *state, void *user_data) {
  switch (tab_state.state) {
      case TD_SINGLE_TAP: unregister_code(KC_N); break;
      case TD_DOUBLE_TAP: unregister_code(KC_N); unregister_code(KC_N); break;
      default: break;
  }
  tab_state.state = TD_NONE;
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case TD(TD_CTRLS_C):
            return TAPPING_TERM + 100;
        case TD(TD_SLSH_CMM):
            return TAPPING_TERM + 50;
        default:
            return TAPPING_TERM;
    }
}



tap_dance_action_t tap_dance_actions[] = {
    [TD_CTRLS_C] = ACTION_TAP_DANCE_DOUBLE(KC_F12, RCS(KC_C)),
    [TD_DASH_EQ] = ACTION_TAP_DANCE_DOUBLE(KC_MINS, KC_EQL),
    [TD_SLSH_CMM] = ACTION_TAP_DANCE_DOUBLE(KC_SLSH, RCTL(KC_SLSH)),
    [TD_JUMP_ONE] = ACTION_TAP_DANCE_DOUBLE(KC_SPACE, KC_RGHT),
    [TD_Q_3EQ] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_q_3eq_finished, td_q_3eq_reset),
    [TD_W_LBRC] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_w_lbrc_finished, td_w_lbrc_reset),
    [TD_E_LCBR] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_e_lcbr_finished, td_e_lcbr_reset),
    [TD_R_LPRN] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_r_lprn_finished, td_r_lprn_reset),
    [TD_T_LT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_t_lt_finished, td_t_lt_reset),
    [TD_Y_GT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_y_gt_finished, td_y_gt_reset),
    [TD_U_RPRN] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_u_rprn_finished, td_u_rprn_reset),
    [TD_I_RCBR] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_i_rcbr_finished, td_i_rcbr_reset),
    [TD_O_RBRC] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_o_rbrc_finished, td_o_rbrc_reset),
    [TD_P_ARRF] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_p_arrf_finished, td_p_arrf_reset),
    [TD_QUOT_GRV] = ACTION_TAP_DANCE_DOUBLE(KC_QUOT, KC_GRV),
    [TD_B_AND] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_b_and_finished, td_b_and_reset),
    [TD_N_OR] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_n_or_finished, td_n_or_reset),
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
                                                        KC_TRNS,        LCA_T(KC_TRNS), C_S_T(KC_TAB),  KC_ENT,         KC_TRNS,         KC_TRNS
    ),

    [3] = LAYOUT_split_3x6_3(
        KC_ESC,         KC_BRIU,        KC_WSCH,        KC_WBAK,        KC_WFWD,        KC_WREF,        KC_EXLM,        KC_7,           KC_8,          KC_9,            KC_BSLS,        KC_TRNS,
        KC_TRNS,        LALT_T(KC_BRID),LSFT_T(KC_TRNS),LCTL_T(KC_MUTE),KC_MPLY,        KC_VOLU,        KC_AT,          KC_4,           RCTL_T(KC_5),  RSFT_T(KC_6),    RALT_T(KC_GRV), KC_TRNS,
        KC_TRNS,        SGUI(KC_S),     LGUI(KC_E),     KC_MSTP,        KC_MFFD,        KC_VOLD,        KC_0,           KC_1,           KC_2,          KC_3,            KC_TRNS,        KC_TRNS,
                                                        KC_TRNS,        KC_TRNS,        KC_TAB,         KC_ENT,         KC_TRNS,        KC_TRNS
    ),

    [4] = LAYOUT_split_3x6_3(
        UM(HEARNOEVIL),         UM(SKULL),       UM(ASTONISHED),  UM(HEART),      UM(ROBOT),      UM(HEXPLODE),     KC_NO,        UM(DEBAE),        UM(DEBOE),        UM(DEBUE),        KC_NO,        KC_NO,
        UM(SEENOEVIL),          UM(POOP),        KC_LSFT,         UM(WINK),       UM(FISTBOX),    UM(EXPLODE),      KC_NO,        UP(DESAE, DEBAE), UP(DESOE, DEBOE), UP(DESUE, DEBUE), KC_E,         KC_NO,
        UM(SPEAKNOEVIL),        UM(CRY),         UM(FRIES),       UM(BUG),        UM(GRIMACE),    UM(SMILE),        KC_NO,        KC_NO,            KC_NO,            KC_NO,            KC_NO,        KC_NO,
                                                                  KC_TRNS,        KC_NO,          KC_TAB,           KC_ENT,       KC_TRNS,          KC_TRNS
    ),
};
