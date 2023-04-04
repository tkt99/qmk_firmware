#include QMK_KEYBOARD_H
// #include "features/repeat_key.h"
// combo_t key_combos[] = {};
// uint16_t COMBO_LEN = 0;

// macros
enum custom_keycodes {
    TEST_CODE = SAFE_RANGE,
    PREV_CMD,
    VIM_COPY_REG,
    VIM_PASTE_REG,
    SHIFT_HOME,
    SHIFT_END,
    LINE_COPY,
    LINE_COPY_WIN,
    LINE_DEL,
    LINE_DEL_WIN,
    WIN_LEFT,
    WIN_RIGHT,
    WIN_UP,
    WIN_DOWN,
    MAC,
    WINDOWS
};

typedef struct {
    uint16_t tap;
    uint16_t hold;
    uint16_t held;

} tap_dance_tap_hold_t;

// tap dance
enum {
    DUAL_QUOTES,
    DUAL_SLASH,
    CT_CLN,
    EQL_PLUS,
    HYPHEN_UNDER,
    L_PBR,
    R_PBR,
    CTL_CAPS,
    LT_C,
    LT_C_WIN,

};

typedef enum {
    TD_NONE,
    TD_UNKNOWN,
    TD_SINGLE_TAP,
    TD_SINGLE_HOLD,
    TD_DOUBLE_TAP,
    // TD_DOUBLE_HOLD,
    TD_DOUBLE_SINGLE_TAP, // Send two single taps
    // TD_TRIPLE_TAP,
    // TD_TRIPLE_HOLD
} td_state_t;

static td_state_t td_state;

typedef struct {
    bool is_press_action;
    td_state_t state;
} td_tap_t;

td_state_t cur_dance(tap_dance_state_t *state);

// For the x tap dance. Put it here so it can be used in any keymap
void L_finished(tap_dance_state_t *state, void *user_data);
void L_reset(tap_dance_state_t *state, void *user_data);

void R_finished(tap_dance_state_t *state, void *user_data);
void R_reset(tap_dance_state_t *state, void *user_data);

void CC_finished(tap_dance_state_t *state, void *user_data);
void CC_reset(tap_dance_state_t *state, void *user_data);

void LT_finished(tap_dance_state_t *state, void *user_data);
void LT_reset(tap_dance_state_t *state, void *user_data);

void LT_WIN_finished(tap_dance_state_t *state, void *user_data);
void LT_WIN_reset(tap_dance_state_t *state, void *user_data);

enum layer_number {
  _QWERTY = 0,
  _RAISE,
  _LOWER,
  _QWERTY_WIN,
  _RAISE_WIN,
  _LOWER_WIN,
  _ADJUST,
  _ADJUST_WIN,
  _TEST,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * ,-------------------------------------------------.                    ,--------------------------------------------.
 * |  WINDOWS/MAC |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |INDICATOR|
 * |---------------------+------+------+------+------|                    |------+------+------+------+------+---------|
 * |      Tab     |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  =/+    |
 * |---------------------+------+------+------+------|                    |------+------+------+------+------+---------|
 * |ESC/CTRL/CAPS |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |  ;/: | ENTER   |
 * |--------------+------+------+------+------+------|CTRL(R)|    |CTRL(D)|------+------+------+------+------+---------|
 * |    LSHIFT    |   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  | /or\ |RShift   |
 * `-------------------------------------------------/       /     \      \--------------------------------------------'
 *                         | LALT | LGUI | LOWER/ | /BackSP /       \Space \  |RAISE/- |  '/" |    |    |
 *                         |      |      | DELETE |/       /         \      \ |        |      |         |
 *                         `------------------------------'           '------''-------------------------'
 */

 [_QWERTY] = LAYOUT(
  TO(_QWERTY_WIN),   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    MAC,
  KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    TD(EQL_PLUS),
  TD(CTL_CAPS),  KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                     KC_H,    KC_J,    KC_K,    KC_L,    TD(CT_CLN), KC_ENT,
  KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, C(KC_R),  C(KC_D),  KC_N,    KC_M,    KC_COMM, KC_DOT,  TD(DUAL_SLASH),  KC_RSFT,
                        KC_LALT, KC_LGUI, TD(LT_C), KC_BSPC, KC_SPACE, LT(_RAISE, KC_MINS), TD(DUAL_QUOTES), KC_PIPE

),
 [_QWERTY_WIN] = LAYOUT(
  TO(_QWERTY),   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    WINDOWS,
  KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    TD(EQL_PLUS),
  TD(CTL_CAPS),  KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                     KC_H,    KC_J,    KC_K,    KC_L,    TD(CT_CLN), KC_ENT,
  KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, C(KC_R),  C(KC_D),  KC_N,    KC_M,    KC_COMM, KC_DOT,  TD(DUAL_SLASH),  KC_RSFT,
                        KC_LALT, KC_LGUI, TD(LT_C_WIN), KC_BSPC, KC_SPACE, LT(_RAISE_WIN, KC_MINS), TD(DUAL_QUOTES), KC_PIPE 

),


/* LOWER
 * ,-----------------------------------------.                    ,--------------------------------------------.
 * |      |      |      |       |      |      |                    |       |       |       |      |       |      |
 * |------+------+------+-------+------+------|                    |-------+-------+-------+------+-------+------|
 * |   @  |   ~  |      |       |      |      |                    |YY(VIM)| U(VIM)|       |      |P(VIM) |      |
 * |------+------+------+------+------+------|                     |-------+-------+-------+------+-------+------|
 * |   ^  |   !  |   #  |DD(VIM)|   $  |   %  |-------.    ,-------|       | (/{/[ | )/}/] |      |       |      |
 * |------+------+------+-------+------+------|   &   |    |       |-------+-------+-------+------+-------+------|
 * |   `  |   *  | UNDO |  CUT  | COPY | PASTE|-------|    |-------|       |       |       |      |COMMENT|      |
 * `-----------------------------------------/       /     \      \----------------------------------------------'
 *                   |      |      |      | /       /       \      \  |      |      |      |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_LOWER] = LAYOUT(
  _______, _______, _______, _______, _______, _______,                         _______, _______, _______, _______, _______, _______,
  KC_AT, KC_TILD, RCS(KC_W), RCS(KC_E), _______, _______,                     LINE_COPY, LGUI(KC_Z), _______, _______, LGUI(KC_V), _______,
  KC_CIRC, KC_EXLM, KC_HASH, LINE_DEL, KC_DLR,  KC_PERC,                          C(KC_LEFT), TD(L_PBR), TD(R_PBR), C(KC_RIGHT), _______, LSA(KC_ENTER),
  KC_GRV, KC_ASTR, LGUI(KC_Z), LGUI(KC_X), LGUI(KC_C), LGUI(KC_V), KC_AMPR,  _______, LSA(KC_H), LSA(KC_J), LSA(KC_K), LSA(KC_L), LGUI(KC_SLSH),_______,
                             _______, _______, _______, _______, LSA(KC_SPACE),  _______, _______, _______
),
[_LOWER_WIN] = LAYOUT(
  _______, _______, _______, _______, _______, _______,                         _______, _______, _______, _______, _______, _______,
  KC_AT, KC_TILD, _______, _______, _______, _______,                     LINE_COPY_WIN, C(KC_Z), _______, _______, C(KC_V), _______,
  KC_CIRC, KC_EXLM, KC_HASH, LINE_DEL_WIN, KC_DLR,  KC_PERC,                          LGUI(KC_LEFT), TD(L_PBR), TD(R_PBR), LGUI(KC_RIGHT), _______, _______,
  KC_GRV, KC_ASTR, C(KC_Z), C(KC_X), C(KC_C), C(KC_V), KC_AMPR,  _______, WIN_LEFT, WIN_DOWN, WIN_UP, WIN_RIGHT, C(KC_SLSH),_______,
                             _______, _______, _______, _______, _______,  _______, _______, _______
),
/* RAISE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      | /or\ |   7  |   8  |   9  | -/_  |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   .  |   4  |   5  |   6  |   .  |--------.   ,-------| Left | Down |  Up  |Right |      |      |
 * |------+------+------+------+------+-------|CTRL(=)|   |       |------+------+------+------+------+------|
 * |      |   0  |   1  |   2  |   3  |BackSP|-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/ Word- /     \      \-----------------------------------------'
 *                 |CTRL(+)|CTRL(-)|      | / BackSP/       \      \  |      |GUI(+) |GUI(-)|
 *                 |       |       |      |/       /         \      \ |      |       |      |
 *                 `------------------------------'           '------''---------------------'
 */

[_RAISE] = LAYOUT(
  _______, _______, _______, _______, _______, _______,                     _______, _______, _______, _______, _______, _______,
  _______, TD(DUAL_SLASH), KC_7,   KC_8,   KC_9,  TD(HYPHEN_UNDER),                       LSA(KC_LEFT), LSFT(KC_LEFT), LSFT(KC_RIGHT), LSA(KC_RIGHT), _______, _______,
  _______, KC_ENT,  KC_4,   KC_5,   KC_6,  KC_DOT,                        KC_LEFT, KC_DOWN, KC_UP,  KC_RGHT, LALT(KC_RIGHT), TEST_CODE,
  _______,   KC_0,  KC_1,   KC_2,   KC_3, KC_BSPC, C(KC_EQL), LALT(KC_LEFT), LSG(KC_LEFT), LSFT(KC_DOWN), LSFT(KC_UP), LSG(KC_RIGHT), _______, PREV_CMD,
                             C(KC_PLUS), C(KC_MINS), _______,  LALT(KC_BSPC),  _______,  _______, LGUI(KC_PLUS), LGUI(KC_MINS) 
                            
), 

[_RAISE_WIN] = LAYOUT(
  _______, _______, _______, _______, _______, _______,                     _______, _______, _______, _______, _______, _______,
  _______, TD(DUAL_SLASH), KC_7,   KC_8,   KC_9,  TD(HYPHEN_UNDER),                       RCS(KC_LEFT), LSFT(KC_LEFT), LSFT(KC_RIGHT), RCS(KC_RIGHT), _______, _______,
  _______, KC_ENT,  KC_4,   KC_5,   KC_6,  KC_DOT,                        KC_LEFT, KC_DOWN, KC_UP,  KC_RGHT, C(KC_RIGHT), TEST_CODE,
  _______,   KC_0,  KC_1,   KC_2,   KC_3, KC_BSPC, C(KC_EQL), C(KC_LEFT), SHIFT_HOME, LSFT(KC_DOWN), LSFT(KC_UP), SHIFT_END, _______, PREV_CMD,
                             C(KC_PLUS), C(KC_MINS), _______,  C(KC_BSPC),  _______,  _______, LGUI(KC_PLUS), LGUI(KC_MINS) 
                            
),
/* RAISE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |                    |  F7  |  F8  |  F9  | F10  | F11  | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      | MUTE | PLAY | PREV | NEXT |      |-------.    ,-------| HOME | PGDN | PGUP |  END |      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \----------------------------------------'
 *                   | B+   | B-   |      | /       /       \      \  |      | Vol- | Vol+ |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_ADJUST] = LAYOUT(
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                               KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
  XXXXXXX, XXXXXXX, MEH(KC_W), MEH(KC_E), XXXXXXX, XXXXXXX,                         MEH(KC_1), MEH(KC_2), MEH(KC_3), MEH(KC_4), MEH(KC_5), XXXXXXX,
  XXXXXXX, KC_MUTE, KC_MPLY, KC_MPRV, KC_MNXT, XXXXXXX,                             LGUI(KC_LEFT), KC_PGDN, KC_PGUP, LGUI(KC_RIGHT), XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, VIM_COPY_REG, VIM_PASTE_REG, XXXXXXX, XXXXXXX, MEH(KC_H), MEH(KC_J), MEH(KC_K), MEH(KC_L), XXXXXXX, XXXXXXX,
                             KC_BRID, KC_BRIU, _______, _______, _______,  _______, KC_VOLD, KC_VOLU 
  ),
[_ADJUST_WIN] = LAYOUT(
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                               KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
  XXXXXXX, KC_W, LSG(KC_RIGHT), LSG(KC_LEFT), XXXXXXX, XXXXXXX,                         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, KC_MUTE, KC_MPLY, KC_MPRV, KC_MNXT, XXXXXXX,                             KC_HOME, KC_PGDN, KC_PGUP, KC_END, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, VIM_COPY_REG, VIM_PASTE_REG, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                             KC_BRID, KC_BRIU, _______, _______, _______,  _______, KC_VOLD, KC_VOLU 
  ),
};

layer_state_t layer_state_set_user(layer_state_t state) {
  state = update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
  state = update_tri_layer_state(state, _LOWER_WIN, _RAISE_WIN, _ADJUST_WIN);
  return state;
}

uint8_t mod_state;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // if (!process_repeat_key(keycode, record, AREPEAT)) { return false; }

    // MACROS
    if (record -> event.pressed) {
       switch (keycode) {

        // Common
        case MAC: SEND_STRING("MAC" SS_DELAY(250) SS_TAP(X_BSPC) SS_TAP(X_BSPC) SS_TAP(X_BSPC)); break;
        case WINDOWS: SEND_STRING("WINDOWS" SS_DELAY(250) SS_TAP(X_BSPC) SS_TAP(X_BSPC) SS_TAP(X_BSPC) SS_TAP(X_BSPC) SS_TAP(X_BSPC) SS_TAP(X_BSPC) SS_TAP(X_BSPC) ); break;
        case TEST_CODE: SEND_STRING(SS_LCTL("j") SS_DELAY(50) SS_TAP(X_UP) SS_DELAY(50) SS_TAP(X_ENTER)); break;
        case PREV_CMD: SEND_STRING(SS_TAP(X_UP) SS_DELAY(50) SS_TAP(X_ENTER)); break;
        case VIM_COPY_REG: SEND_STRING("\"" SS_DELAY(10) "a" SS_DELAY(10) "y"); break;
        case VIM_PASTE_REG: SEND_STRING("\"" SS_DELAY(10) "a" SS_DELAY(10) "p"); break;

        // MAC
        case LINE_COPY: SEND_STRING(SS_DOWN(X_LGUI) SS_DELAY(50) SS_TAP(X_LEFT) SS_DELAY(50) SS_DOWN(X_LSFT) SS_DELAY(50) SS_TAP(X_RIGHT) SS_DELAY(50) SS_UP(X_LSFT) SS_DELAY(50) "c" SS_DELAY(50) SS_UP(X_LGUI)); break;
        case LINE_DEL: SEND_STRING(SS_DOWN(X_LGUI) SS_DELAY(50) SS_TAP(X_LEFT) SS_DELAY(50) SS_DOWN(X_LSFT) SS_DELAY(50) SS_TAP(X_RIGHT) SS_DELAY(50) SS_UP(X_LSFT) SS_DELAY(50) "c" SS_DELAY(50) SS_TAP(X_BSPC) SS_DELAY(50) SS_UP(X_LGUI)); break;

        // Windows
        case SHIFT_HOME: SEND_STRING(SS_DOWN(X_LSFT) SS_DELAY(50) SS_TAP(X_HOME) SS_DELAY(50) SS_UP(X_LSFT)); break;
        case SHIFT_END: SEND_STRING(SS_DOWN(X_LSFT) SS_DELAY(50) SS_TAP(X_END) SS_DELAY(50) SS_UP(X_LSFT));  break;
        case LINE_COPY_WIN: SEND_STRING(SS_TAP(X_HOME) SS_DELAY(50) SS_DOWN(X_LSFT) SS_DELAY(50) SS_TAP(X_END) SS_DELAY(50) SS_UP(X_LSFT) SS_DELAY(50) SS_LCTL("c") SS_DELAY(50) SS_TAP(X_RIGHT)); break;
        case LINE_DEL_WIN: SEND_STRING(SS_TAP(X_END) SS_DELAY(50) SS_DOWN(X_LSFT) SS_DELAY(50) SS_TAP(X_HOME) SS_DELAY(50) SS_UP(X_LSFT) SS_DELAY(50) SS_LCTL("c") SS_DELAY(50) SS_TAP(X_BSPC) ); break;
        case WIN_LEFT: SEND_STRING(SS_DOWN(X_LGUI) SS_DELAY(10) SS_TAP(X_LEFT) SS_DELAY(10) SS_UP(X_LGUI) SS_DELAY(50) SS_TAP(X_ESC)); break;
        case WIN_RIGHT: SEND_STRING(SS_DOWN(X_LGUI) SS_DELAY(10) SS_TAP(X_RIGHT) SS_DELAY(10) SS_UP(X_LGUI) SS_DELAY(50) SS_TAP(X_ESC)); break;
        case WIN_UP: SEND_STRING(SS_DOWN(X_LGUI) SS_DELAY(10) SS_TAP(X_UP) SS_DELAY(10) SS_UP(X_LGUI) SS_DELAY(50) SS_TAP(X_ESC)); break;
        case WIN_DOWN: SEND_STRING(SS_DOWN(X_LGUI) SS_DELAY(10) SS_TAP(X_DOWN) SS_DELAY(10) SS_UP(X_LGUI) SS_DELAY(50) SS_TAP(X_ESC)); break;

       }

    }
    tap_dance_action_t *action;

    switch (keycode) {
        case TD(CT_CLN):  // list all tap dance keycodes with tap-hold configurations


            action = &tap_dance_actions[TD_INDEX(keycode)];
            if (!record->event.pressed && action->state.count && !action->state.finished) {
                tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
                tap_code16(tap_hold->tap);
            }

            break;

        case TD(EQL_PLUS):  

            action = &tap_dance_actions[TD_INDEX(keycode)];

            if (!record->event.pressed && action->state.count && !action->state.finished) {
                tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
                tap_code16(tap_hold->tap);
            }
            break;

        case TD(DUAL_QUOTES):  

            action = &tap_dance_actions[TD_INDEX(keycode)];

            if (!record->event.pressed && action->state.count && !action->state.finished) {
                tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
                tap_code16(tap_hold->tap);
            }
            break;

        case TD(DUAL_SLASH):  

            action = &tap_dance_actions[TD_INDEX(keycode)];

            if (!record->event.pressed && action->state.count && !action->state.finished) {
                tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
                tap_code16(tap_hold->tap);
            }
            break;

        case TD(HYPHEN_UNDER):  

            action = &tap_dance_actions[TD_INDEX(keycode)];

            if (!record->event.pressed && action->state.count && !action->state.finished) {
                tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
                tap_code16(tap_hold->tap);
            }

            break;

        case TD(LT_C):  

            action = &tap_dance_actions[TD_INDEX(keycode)];

            if (!record->event.pressed && action->state.count && !action->state.finished) {
                tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
                tap_code16(tap_hold->tap);
            }

            break;
    }

    return true;

};

// ??
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        //case KC_LPRN: return 50;
        //case KC_RPRN: return 50;
        case KC_BACKSLASH: 
            return 499;
        case KC_SLASH: 
            return 499;
        default:
            return TAPPING_TERM;
    }
}

void tap_dance_tap_hold_finished(tap_dance_state_t *state, void *user_data) {

    tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)user_data;

    if (state->pressed) {
        if (state->count == 1
#ifndef PERMISSIVE_HOLD
            && !state->interrupted
#endif
        ) {
            register_code16(tap_hold->hold);
            tap_hold->held = tap_hold->hold;

        } else {
            register_code16(tap_hold->tap);
            tap_hold->held = tap_hold->tap;
        }
    }
}

void tap_dance_tap_hold_reset(tap_dance_state_t *state, void *user_data) {
    tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)user_data;

    if (tap_hold->held) {
        unregister_code16(tap_hold->held);
        tap_hold->held = 0;
    }
}

#define ACTION_TAP_DANCE_TAP_HOLD(tap, hold) \
    { .fn = {NULL, tap_dance_tap_hold_finished, tap_dance_tap_hold_reset}, .user_data = (void *)&((tap_dance_tap_hold_t){tap, hold, 0}), }



/* Return an integer that corresponds to what kind of tap dance should be executed.
 *
 * How to figure out tap dance state: interrupted and pressed.
 *
 * Interrupted: If the state of a dance is "interrupted", that means that another key has been hit
 *  under the tapping term. This is typically indicitive that you are trying to "tap" the key.
 *
 * Pressed: Whether or not the key is still being pressed. If this value is true, that means the tapping term
 *  has ended, but the key is still being pressed down. This generally means the key is being "held".
 *
 * One thing that is currenlty not possible with qmk software in regards to tap dance is to mimic the "permissive hold"
 *  feature. In general, advanced tap dances do not work well if they are used with commonly typed letters.
 *  For example "A". Tap dances are best used on non-letter keys that are not hit while typing letters.
 *
 * Good places to put an advanced tap dance:
 *  z,q,x,j,k,v,b, any function key, home/end, comma, semi-colon
 *
 * Criteria for "good placement" of a tap dance key:
 *  Not a key that is hit frequently in a sentence
 *  Not a key that is used frequently to double tap, for example 'tab' is often double tapped in a terminal, or
 *    in a web form. So 'tab' would be a poor choice for a tap dance.
 *  Letters used in common words as a double. For example 'p' in 'pepper'. If a tap dance function existed on the
 *    letter 'p', the word 'pepper' would be quite frustating to type.
 *
 * For the third point, there does exist the 'TD_DOUBLE_SINGLE_TAP', however this is not fully tested
 *
 */
td_state_t cur_dance(tap_dance_state_t *state) {
    if (state->count == 1) {
        if (!state->pressed) return TD_SINGLE_TAP;
        // Key has not been interrupted, but the key is still held. Means you want to send a 'HOLD'.
        else return TD_SINGLE_HOLD;
    } else if (state->count == 2) {
        // TD_DOUBLE_SINGLE_TAP is to distinguish between typing "pepper", and actually wanting a double tap
        // action when hitting 'pp'. Suggested use case for this return value is when you want to send two
        // keystrokes of the key, and not the 'double tap' action/macro.
        if (state->interrupted) return TD_DOUBLE_SINGLE_TAP;
        //else if (state->pressed) return TD_DOUBLE_HOLD;
        return TD_DOUBLE_TAP;
    }

    // Assumes no one is trying to type the same letter three times (at least not quickly).
    // If your tap dance key is 'KC_W', and you want to type "www." quickly - then you will need to add
    // an exception here to return a 'TD_TRIPLE_SINGLE_TAP', and define that enum just like 'TD_DOUBLE_SINGLE_TAP'
    //if (state->count == 3) {
     //   if (state->interrupted || !state->pressed) return TD_TRIPLE_TAP;
     //   else return TD_TRIPLE_HOLD;
    else return TD_UNKNOWN;
}

// Create an instance of 'td_tap_t' for the 'x' tap dance.
static td_tap_t xtap_state = {
    .is_press_action = true,
    .state = TD_NONE
};

void L_finished(tap_dance_state_t *state, void *user_data) {
    xtap_state.state = cur_dance(state);
    switch (xtap_state.state) {
        case TD_SINGLE_TAP: register_code16(S(KC_9)); break;
        case TD_SINGLE_HOLD: register_code16(S(KC_LBRC)); break;
        case TD_DOUBLE_TAP: register_code(KC_LBRC); break;

        // case TD_DOUBLE_HOLD: register_code(KC_LALT); break;
        // Last case is for fast typing. Assuming your key is `f`:
        // For example, when typing the word `buffer`, and you want to make sure that you send `ff` and not `Esc`.
        // In order to type `ff` when typing fast, the next character will have to be hit within the `TAPPING_TERM`, which by default is 200ms.
        case TD_DOUBLE_SINGLE_TAP: tap_code16(S(KC_9)); register_code16(S(KC_9)); break;
        default: break;
    }
}

void L_reset(tap_dance_state_t *state, void *user_data) {
    switch (xtap_state.state) {
        case TD_SINGLE_TAP: unregister_code16(S(KC_9)); break;
        case TD_SINGLE_HOLD: unregister_code16(S(KC_LBRC)); break;
        case TD_DOUBLE_TAP: unregister_code(KC_LBRC); break;
        // case TD_DOUBLE_HOLD: unregister_code(KC_LALT); break;
        case TD_DOUBLE_SINGLE_TAP: unregister_code16(S(KC_9)); break;
        default: break;
    }
    xtap_state.state = TD_NONE;
}

void R_finished(tap_dance_state_t *state, void *user_data) {
    xtap_state.state = cur_dance(state);
    switch (xtap_state.state) {
        case TD_SINGLE_TAP: register_code16(S(KC_0)); break;
        case TD_SINGLE_HOLD: register_code16(S(KC_RBRC)); break;
        case TD_DOUBLE_TAP: register_code(KC_RBRC); break;

        // case TD_DOUBLE_HOLD: register_code(KC_LALT); break;
        // Last case is for fast typing. Assuming your key is `f`:
        // For example, when typing the word `buffer`, and you want to make sure that you send `ff` and not `Esc`.
        // In order to type `ff` when typing fast, the next character will have to be hit within the `TAPPING_TERM`, which by default is 200ms.
        // case TD_DOUBLE_SINGLE_TAP: tap_code(KC_X); register_code(KC_X); break;
        case TD_DOUBLE_SINGLE_TAP: tap_code16(S(KC_0)); register_code16(S(KC_0)); break;
        default: break;
    }
}

void R_reset(tap_dance_state_t *state, void *user_data) {
    switch (xtap_state.state) {
        case TD_SINGLE_TAP: unregister_code16(S(KC_0)); break;
        case TD_SINGLE_HOLD: unregister_code16(S(KC_RBRC)); break;
        case TD_DOUBLE_TAP: unregister_code(KC_RBRC); break;
        // case TD_DOUBLE_HOLD: unregister_code(KC_LALT); break;
        case TD_DOUBLE_SINGLE_TAP: unregister_code16(S(KC_9)); break; 
        default: break;
    }
    xtap_state.state = TD_NONE;
}

void CC_finished(tap_dance_state_t *state, void *user_data) {
    xtap_state.state = cur_dance(state);
    switch (xtap_state.state) {
        case TD_SINGLE_TAP: register_code16(KC_ESC); break;
        case TD_SINGLE_HOLD: register_code(KC_LCTL); break;
        case TD_DOUBLE_TAP: register_code(KC_CAPS); break;

        // case TD_DOUBLE_HOLD: register_code(KC_LALT); break;
        // Last case is for fast typing. Assuming your key is `f`:
        // For example, when typing the word `buffer`, and you want to make sure that you send `ff` and not `Esc`.
        // In order to type `ff` when typing fast, the next character will have to be hit within the `TAPPING_TERM`, which by default is 200ms.
        // case TD_DOUBLE_SINGLE_TAP: tap_code(KC_X); register_code(KC_X); break;
        //kkcase TD_DOUBLE_SINGLE_TAP: tap_code16(S(KC_0)); register_code16(S(KC_0)); break;
        default: break;
    }
}

void CC_reset(tap_dance_state_t *state, void *user_data) {
    switch (xtap_state.state) {
        case TD_SINGLE_TAP: unregister_code16(KC_ESC); break;
        case TD_SINGLE_HOLD: unregister_code(KC_LCTL); break;
        case TD_DOUBLE_TAP: unregister_code(KC_CAPS); break;
        // case TD_DOUBLE_HOLD: unregister_code(KC_LALT); break;
        //case TD_DOUBLE_SINGLE_TAP: unregister_code16(S(KC_9)); break; 
        default: break;
    }
    xtap_state.state = TD_NONE;
}

void LT_finished(tap_dance_state_t *state, void *user_data) {
    td_state = cur_dance(state);
    switch (td_state) {
        case TD_SINGLE_TAP: register_code16(C(KC_C)); break;
        case TD_SINGLE_HOLD: layer_on(_LOWER); break;
        // case TD_DOUBLE_TAP: register_code(KC_CAPS); break;

        // case TD_DOUBLE_HOLD: register_code(KC_LALT); break;
        // Last case is for fast typing. Assuming your key is `f`:
        // For example, when typing the word `buffer`, and you want to make sure that you send `ff` and not `Esc`.
        // In order to type `ff` when typing fast, the next character will have to be hit within the `TAPPING_TERM`, which by default is 200ms.
        case TD_DOUBLE_SINGLE_TAP: tap_code16(C(KC_C)); register_code16(C(KC_C)); break;
        default: break;
    }
}

void LT_reset(tap_dance_state_t *state, void *user_data) {
    switch (td_state) {
        case TD_SINGLE_TAP: unregister_code16(C(KC_C)); break;
        case TD_SINGLE_HOLD: layer_off(_LOWER); break;
        // case TD_DOUBLE_TAP: unregister_code(KC_CAPS); break;
        // case TD_DOUBLE_HOLD: unregister_code(KC_LALT); break;
        case TD_DOUBLE_SINGLE_TAP: unregister_code16(C(KC_C)); break; 
        default: break;
    }
}

void LT_WIN_finished(tap_dance_state_t *state, void *user_data) {
    td_state = cur_dance(state);
    switch (td_state) {
        case TD_SINGLE_TAP: register_code16(C(KC_C)); break;
        case TD_SINGLE_HOLD: layer_on(_LOWER_WIN); break;
        // case TD_DOUBLE_TAP: register_code(KC_CAPS); break;

        // case TD_DOUBLE_HOLD: register_code(KC_LALT); break;
        // Last case is for fast typing. Assuming your key is `f`:
        // For example, when typing the word `buffer`, and you want to make sure that you send `ff` and not `Esc`.
        // In order to type `ff` when typing fast, the next character will have to be hit within the `TAPPING_TERM`, which by default is 200ms.
        case TD_DOUBLE_SINGLE_TAP: tap_code16(C(KC_C)); register_code16(C(KC_C)); break;
        default: break;
    }
}

void LT_WIN_reset(tap_dance_state_t *state, void *user_data) {
    switch (td_state) {
        case TD_SINGLE_TAP: unregister_code16(C(KC_C)); break;
        case TD_SINGLE_HOLD: layer_off(_LOWER_WIN); break;
        // case TD_DOUBLE_TAP: unregister_code(KC_CAPS); break;
        // case TD_DOUBLE_HOLD: unregister_code(KC_LALT); break;
        case TD_DOUBLE_SINGLE_TAP: unregister_code16(C(KC_C)); break; 
        default: break;
    }
}
tap_dance_action_t tap_dance_actions[] = {
    //[CTL_CAPS] = ACTION_TAP_DANCE_DOUBLE(KC_LCTL, KC_CAPS),
    [DUAL_QUOTES] = ACTION_TAP_DANCE_TAP_HOLD(KC_QUOT, KC_DOUBLE_QUOTE),
    [DUAL_SLASH] = ACTION_TAP_DANCE_TAP_HOLD(KC_SLSH, KC_BACKSLASH),
    [CT_CLN] = ACTION_TAP_DANCE_TAP_HOLD(KC_SCLN, KC_COLN),
    [EQL_PLUS] = ACTION_TAP_DANCE_TAP_HOLD(KC_EQL, KC_PLUS),
    [HYPHEN_UNDER] = ACTION_TAP_DANCE_TAP_HOLD(KC_MINS, KC_UNDS),
    [L_PBR] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, L_finished, L_reset),
    [R_PBR] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, R_finished, R_reset),
    [CTL_CAPS] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, CC_finished, CC_reset),
    [LT_C] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, LT_finished, LT_reset),
    [LT_C_WIN] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, LT_WIN_finished, LT_WIN_reset),
};

