#include QMK_KEYBOARD_H

enum layer_number {
  _QWERTY = 0,
  _LOWER,
  _RAISE,
  _ADJUST,
  _TEST,
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | CAPS |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  =   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LCTRL |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  | ENTER|
 * |------+------+------+------+------+------|CTRL(C)|    |CTRL(D)|------+------+------+------+------+------|
 * |LSHIFT|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LALT | LGUI |LOWER | /BackSP /       \Space \  |RAISE |  '   |CTRL(R)|
 *                   |      |      |      |/       /         \      \ |      |      |       |
 *                   `----------------------------'           '------''---------------------'
 */

 [_QWERTY] = LAYOUT(
  KC_ESC,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_CAPS,
  KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_EQL,
  KC_LCTL,  KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                     KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT,
  KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, C(KC_C),  C(KC_D),  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  KC_RSFT,
                        KC_LALT, KC_LGUI, TT(_LOWER), KC_BSPC, KC_SPACE, TT(_RAISE), KC_QUOT, C(KC_R)
),


/* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |                    |  F7  |  F8  |  F9  | F10  | F11  | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |   `  |   !  |   @  |   #  |   $  |   %  |-------.    ,-------|      |   (  |   )  |   [  |   ]  |      |
 * |------+------+------+------+------+------|CTRL(C)|    |CTRL(D)|------+------+------+------+------+------|
 * |      |   ^  |   &  |   *  |   (  |   )  |-------|    |-------|      |   {  |   }  |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LALT | LGUI |LOWER | /BackSP /       \Space \  |RAISE |  '   |CTRL(R)|
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_LOWER] = LAYOUT(
  _______, _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______,
  _______, _______, RCS(KC_W), RCS(KC_E), _______, _______, _______,                   _______, _______, _______, _______, _______,
  KC_GRV, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                   LSA(KC_J), KC_LPRN, KC_RPRN, KC_LBRC, KC_RBRC, _______,
  _______, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, _______, _______, LSA(KC_K), KC_LCBR, KC_RCBR, _______, LGUI(KC_SLSH),_______,
                             _______, _______, _______, _______, LSA(KC_SPACE),  _______, _______, _______
),

/* RAISE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |   7  |   8  |   9  |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |   4  |   5  |   6  |   /  |-------.    ,-------| Left | Down |  Up  |Right |CTRL(J)|      |
 * |------+------+------+------+------+------|CTRL(C)|    |CTRL(D)|------+------+------+------+------+------|
 * |      |   0  |   1  |   2  |   3  |   .  |-------|    |-------|   +  |   -  |   _  |      |   |  |  \   |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LALT | LGUI |LOWER | /BackSP /       \Space \  |RAISE |  '   |CTRL(R)|
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

[_RAISE] = LAYOUT(
  _______, _______, _______, _______, _______, _______,                     _______, _______, _______, _______, _______, _______,
  _______, _______, KC_7,   KC_8,   KC_9,  _______,                          _______, _______, _______, _______, _______, _______,
  _______, _______,  KC_4,   KC_5,   KC_6,  KC_SLASH,                        KC_LEFT, KC_DOWN, KC_UP,  KC_RGHT, C(KC_J), _______,
  _______,   KC_0,  KC_1,   KC_2,   KC_3, KC_DOT, _______, _______,        KC_PLUS, KC_MINS, KC_UNDS, _______, KC_PIPE, KC_BACKSLASH,
                             _______, _______, _______,  _______, _______,  _______, _______, _______
),

/* ADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
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
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, MEH(KC_W), MEH(KC_E), XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                     KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MUTE, KC_MPLY, KC_MPRV, KC_MNXT, XXXXXXX, XXXXXXX, XXXXXXX,
                             KC_BRID, KC_BRIU, _______, _______, _______,  _______, KC_VOLD, KC_VOLU 
  )
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

    // Store the current modifier state in the variable for later reference
    mod_state = get_mods();
    switch (keycode) {
        case KC_BSPC: {
            // Initialize a boolean variable that keeps track
            // of the delete key status: registered or not?
            static bool delkey_registered;
            if (record->event.pressed) {
                // Detect the activation of either shift keys
                
                if (mod_state & MOD_MASK_SHIFT) {
                    // First temporarily canceling both shifts so that
                    // shift isn't applied to the KC_DEL keycode
                    del_mods(MOD_MASK_SHIFT);
                    register_code(KC_DEL);
                    // Update the boolean variable to reflect the status of KC_DEL
                    delkey_registered = true;
                    // Reapplying modifier state so that the held shift key(s)
                    // still work even after having tapped the Backspace/Delete key.
                    set_mods(mod_state);
                    return false;
                }
            } else { // on release of KC_BSPC
                // In case KC_DEL is still being sent even after the release of KC_BSPC
                if (delkey_registered) {
                    unregister_code(KC_DEL);
                    delkey_registered = false;
                    return false;
                }
            }
            // Let QMK process the KC_BSPC keycode as usual outside of shift
            return true;
        }
    }

    return true;

};
