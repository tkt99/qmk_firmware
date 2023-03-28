#include QMK_KEYBOARD_H


enum {

    TEST_CODE = SAFE_RANGE,
    VIM_COPY_REG,
    VIM_PASTE_REG,
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
};



enum layer_number {
  _QWERTY = 0,
  _RAISE,
  _LOWER,
  _ADJUST,
  _TEST,
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | CAPS |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  =/+ |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LCTRL |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |  ;/: | ENTER|
 * |------+------+------+------+------+------|CTRL(C)|    |CTRL(D)|------+------+------+------+------+------|
 * |LSHIFT|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  | /or\ |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LALT | LGUI |LOWER | /BackSP /       \Space \  |RAISE |  '/" |CTRL(R)|
 *                   |      |      |      |/       /         \      \ |      |      |       |
 *                   `----------------------------'           '------''---------------------'
 */

 [_QWERTY] = LAYOUT(
  KC_ESC,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_CAPS,
  KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    TD(EQL_PLUS),
  KC_LCTL,  KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                     KC_H,    KC_J,    KC_K,    KC_L,    TD(CT_CLN), KC_ENT,
  KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, C(KC_C),  C(KC_D),  KC_N,    KC_M,    KC_COMM, KC_DOT,  TD(DUAL_SLASH),  KC_RSFT,
                        KC_LALT, KC_LGUI, TT(_LOWER), KC_BSPC, KC_SPACE, TT(_RAISE), TD(DUAL_QUOTES), C(KC_R)
),


/* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |   [  |   ]  |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |   `  |   !  |   @  |   #  |   $  |   %  |-------.    ,-------|      |   (  |   )  |      |      |      |
 * |------+------+------+------+------+------|CTRL(C)|    |CTRL(D)|------+------+------+------+------+------|
 * |      |   ^  |   &  |   *  | COPY | PASTE|-------|    |-------|      |   {  |   }  |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LALT | LGUI |LOWER | /BackSP /       \Space \  |RAISE |  '   |CTRL(R)|
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_LOWER] = LAYOUT(
  _______, _______, _______, _______, _______, _______,                         _______, _______, _______, _______, _______, _______,
  _______, _______, RCS(KC_W), RCS(KC_E), _______, _______,                     LSA(KC_H), KC_LBRC, KC_RBRC, LSA(KC_L), _______, _______,
  KC_GRV, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                          C(KC_LEFT), KC_LPRN, KC_RPRN, C(KC_RIGHT), TEST_CODE, LSA(KC_ENTER),
  _______, KC_CIRC, KC_AMPR, KC_ASTR, LGUI(KC_L), LGUI(KC_P), _______, LSA(KC_J), LSA(KC_K), KC_LCBR, KC_RCBR, _______, LGUI(KC_SLSH),_______,
                             _______, _______, _______, _______, LSA(KC_SPACE),  _______, _______, _______
),

/* RAISE
 * ,-----------------------------------------.                    ,------------------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |             |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------+------|
 * |      | /or\ |   7  |   8  |   9  |      |                    |      |      |      |      |             |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------+------|
 * |      |   .  |   4  |   5  |   6  |      |-------.    ,-------| Left | Down |  Up  |Right |SHFT(Right)  |      |
 * |------+------+------+------+------+------|CTRL(C)| |SHFT(Left)|------+------+------+------+------+------+------|
 * |      |   0  |   1  |   2  |   3  |      |-------|    |-------|   +  |   -  |   _  |      |      |      |      |
 * `-----------------------------------------/       /     \      \------------------------------------------------'
 *                   | LALT | LGUI |LOWER | /BackSP /       \Space \  |RAISE |  '   |CTRL(R)|
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

[_RAISE] = LAYOUT(
  _______, _______, _______, _______, _______, _______,                     _______, _______, _______, _______, _______, _______,
  _______, TD(DUAL_SLASH), KC_7,   KC_8,   KC_9,  _______,                       LSA(KC_LEFT), LALT(KC_LEFT), LALT(KC_RIGHT), LSA(KC_RIGHT), _______, _______,
  _______, KC_DOT,  KC_4,   KC_5,   KC_6,  _______,                        KC_LEFT, KC_DOWN, KC_UP,  KC_RGHT, LSFT(KC_RIGHT), _______,
  _______,   KC_0,  KC_1,   KC_2,   KC_3, KC_BSPC, C(KC_EQL), LSFT(KC_LEFT), LSG(KC_LEFT), TD(HYPHEN_UNDER), KC_UNDS, LSG(KC_RIGHT), KC_PIPE, _______,
                             C(KC_PLUS), C(KC_MINS), _______,  KC_DELETE, _______,  _______, LGUI(KC_PLUS), LGUI(KC_MINS)
),
/* ADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |                    |  F7  |  F8  |  F9  | F10  | F11  | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      |      |      |      |      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LALT | LGUI |LOWER | /BackSP /       \Space \  |RAISE |  '   |CTRL(R)|
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_ADJUST] = LAYOUT(
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                               KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
  XXXXXXX, XXXXXXX, MEH(KC_W), MEH(KC_E), XXXXXXX, XXXXXXX,                         MEH(KC_1), MEH(KC_2), MEH(KC_3), MEH(KC_4), MEH(KC_5), XXXXXXX,
  XXXXXXX, KC_MPRV, KC_MPLY, KC_MUTE, KC_MNXT, XXXXXXX,                             KC_HOME, KC_PGDN, KC_PGUP, KC_END, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, VIM_COPY_REG, VIM_PASTE_REG, XXXXXXX, XXXXXXX, LGUI(KC_LEFT), XXXXXXX, XXXXXXX, LGUI(KC_RIGHT), XXXXXXX, XXXXXXX,
                             KC_BRID, KC_BRIU, _______, _______, _______,  _______, KC_VOLD, KC_VOLU 
  ),

};
layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

//SSD1306 OLED update loop, make sure to enable OLED_ENABLE=yes in rules.mk
#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master())
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  return rotation;
}

// When you add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

bool oled_task_user(void) {
  if (is_keyboard_master()) {
    // If you want to change the display of OLED, you need to change here
    oled_write_ln(read_layer_state(), false);
    oled_write_ln(read_keylog(), false);
    oled_write_ln(read_keylogs(), false);
    //oled_write_ln(read_mode_icon(keymap_config.swap_lalt_lgui), false);
    //oled_write_ln(read_host_led_state(), false);
    //oled_write_ln(read_timelog(), false);
  } else {
    oled_write(read_logo(), false);
  }
    return false;
}
#endif // OLED_ENABLE

uint8_t mod_state;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // if (!process_caps_word(keycode, record)) { return false; }
    if (record -> event.pressed) {
       switch (keycode) {

           // ctrl-j set as focusTerminal on VSCode
           case TEST_CODE:
               SEND_STRING(SS_LCTL("j") SS_DELAY(100) SS_TAP(X_UP) SS_DELAY(100) SS_TAP(X_ENTER));
               break;

           case VIM_COPY_REG:
               SEND_STRING("\"" SS_DELAY(100) "a" SS_DELAY(100) "y");
               break;

           case VIM_PASTE_REG:
               SEND_STRING("\"" SS_DELAY(100) "a" SS_DELAY(100) "p");
               break;
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


    }

    // Store the current modifier state in the variable for later reference
//    mod_state = get_mods();
//    switch (keycode) {
//        case KC_BSPC: {
//            // Initialize a boolean variable that keeps track
//            // of the delete key status: registered or not?
//            static bool delkey_registered;
//            if (record->event.pressed) {
//                // Detect the activation of either shift keys
//                
//                if (mod_state & MOD_MASK_SHIFT) {
//                    // First temporarily canceling both shifts so that
//                    // shift isn't applied to the KC_DEL keycode
//                    del_mods(MOD_MASK_SHIFT);
//                    register_code(KC_DEL);
//                    // Update the boolean variable to reflect the status of KC_DEL
//                    delkey_registered = true;
//                    // Reapplying modifier state so that the held shift key(s)
//                    // still work even after having tapped the Backspace/Delete key.
//                    set_mods(mod_state);
//                    return false;
//                }
//            } else { // on release of KC_BSPC
//                // In case KC_DEL is still being sent even after the release of KC_BSPC
//                if (delkey_registered) {
//                    unregister_code(KC_DEL);
//                    delkey_registered = false;
//                    return false;
//                }
//            }
//            // Let QMK process the KC_BSPC keycode as usual outside of shift
//            return true;
//        }
//    }
//
    return true;

};

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

tap_dance_action_t tap_dance_actions[] = {
    //[DUAL_QUOTES] = ACTION_TAP_DANCE_DOUBLE(KC_QUOT, KC_DOUBLE_QUOTE),
    [DUAL_QUOTES] = ACTION_TAP_DANCE_TAP_HOLD(KC_QUOT, KC_DOUBLE_QUOTE),
    [DUAL_SLASH] = ACTION_TAP_DANCE_TAP_HOLD(KC_SLSH, KC_BACKSLASH),
    [CT_CLN] = ACTION_TAP_DANCE_TAP_HOLD(KC_SCLN, KC_COLN),
    [EQL_PLUS] = ACTION_TAP_DANCE_TAP_HOLD(KC_EQL, KC_PLUS),
    [HYPHEN_UNDER] = ACTION_TAP_DANCE_TAP_HOLD(KC_MINS, KC_UNDS),
};
