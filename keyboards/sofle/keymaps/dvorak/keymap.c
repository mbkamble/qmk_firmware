#include QMK_KEYBOARD_H

enum sofle_layers {
    /* _M_XYZ = Mac Os, _W_XYZ = Win/Linux */
    _QWERTY,
    _DVORAK,
    _LOWER,
    _RAISE,
    _ADJUST,
};

enum custom_keycodes {
    KC_QWERTY = SAFE_RANGE,
    KC_DVORAK,
    KC_LOWER,
    KC_RAISE,
    KC_ADJUST,
    KC_PRVWD,
    KC_NXTWD,
    KC_LSTRT,
    KC_LEND,
    KC_DLINE
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | ESC  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/      /      \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |LOWER | /  SPC /        \ENTER \  |RAISE | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/      /          \      \ |      |      |      |      |
 *            `----------------------------------'            '------''---------------------------'
 */

[_QWERTY] = LAYOUT( \
  KC_GRV,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  KC_GRV, \
  KC_ESC,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,  KC_BSPC, \
  KC_TAB,   KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                     KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN,  KC_QUOT, \
  KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, KC_MUTE,   XXXXXXX, KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_RSFT, \
              KC_LGUI,KC_LALT,KC_LCTRL, KC_LOWER,  KC_SPC,        KC_ENT,  KC_RAISE, KC_RCTRL, KC_RALT, KC_RGUI \
),
/*
 * DVORAK
 * ,--------------------------------------------.                    ,-----------------------------------------.
 * |  `   |   1  |   2  |   3  |   4  |   5     |                    |   6  |   7  |   8  |   9  |   0  |  `   |
 * |------+------+------+------+------+---------|                    |------+------+------+------+------+------|
 * | ESC  |   Q  |   J  |   K  |   P  |   Y     |                    |   F  |   G  |   C  |   R  |   L  | Bspc |
 * |------+------+------+------+------+---------|                    |------+------+------+------+------+------|
 * |LShift|   A  |   O  |ALT(E)|CTL(U)|   I     |                    |   D  |CTL(H)|ALT(T)|   N  |   S  |RShift|
 * |------+------+------+------+------+---------|-------.   .--------|------+------+------+------+------+------+
 * | Del  | " '  | < ,  |  > . |   X  |   Tab   | MUTE  |   |        |   B  |   M  |   W  |   V  |   Z  | ? /  |
 * `-------------------------------------------,-------/     \-------.---------------------------------------'
 *            | LGUI | LALT | LCTL |LOWER |   / SPACE /       \ENTER \  |RAISE | RCTL | RALT | RGUI |
 *            |      |      |      |      |  /       /         \      \ |      |      |      |      |
 *            `-------------------------------------'           '------''---------------------------'
 */

[_DVORAK] = LAYOUT( \
   KC_GRV,  KC_1,   KC_2,   KC_3,         KC_4,         KC_5,                         KC_6, KC_7,        KC_8,        KC_9, KC_0, KC_GRV, \
   KC_ESC,  KC_Q,   KC_J,   KC_K,         KC_P,         KC_Y,                         KC_F, KC_G,        KC_C,        KC_R, KC_L, KC_BSPC,\
  KC_LSFT,  KC_A,   KC_O,   LALT_T(KC_E), LCTL_T(KC_U), KC_I,                         KC_D, RCTL_T(KC_H),RALT_T(KC_T),KC_N, KC_S, KC_RSFT, \
  KC_DEL, KC_QUOT, KC_COMM, KC_DOT,         KC_X,         KC_TAB, KC_MUTE,      XXXXXXX,KC_B, KC_M,        KC_W,        KC_V, KC_Z, KC_SLSH,\
	                      KC_LGUI, KC_LALT, KC_LCTL, KC_LOWER, KC_SPC,  KC_ENT, KC_RAISE, KC_RCTL, KC_RALT, KC_RGUI \
),
/* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  F11  |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  | F10  | F12 |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  `   |   1  |   2  |   3  |   4  |   5  |                    |  6   |  7   |  8   |  9   |  0   | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LShift|   !  |   @  | LALT | LCTL |   +  |-------.    ,-------|  -   | RCTL | RALT |  {   |  }   |RShift|
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * | Del  |   [  |   ]  |  :   |  _   |  Tab |-------|    |-------|   =  |   ?  |  ;   |  \   |  |   |  /   |
 * `-----------------------------------------/      /      \      \-----------------------------------------'
 *            | LGUI | LALT | LCTL |LOWER | / SPC  /        \ENTER \  |RAISE | RCTL | RALT | RGUI |
 *            |      |      |      |      |/      /          \      \ |      |      |      |      |
 *            `----------------------------------'            '------''---------------------------'
 */
[_LOWER] = LAYOUT( \
  KC_F11,  KC_F1,    KC_F2,   KC_F3,   KC_F4,   KC_F5,                            KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F12,  \
  KC_GRV,   KC_1,     KC_2,    KC_3,    KC_4,    KC_5,                            KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______, \
  _______,  KC_EXLM,  KC_AT,   KC_LALT, KC_LCTL, KC_PLUS,                         KC_MINS, KC_RCTL, KC_RALT, KC_LCBR, KC_RCBR, _______, \
  _______,  KC_LBRC,  KC_RBRC, KC_COLN, KC_UNDS, _______, _______,       _______, KC_EQL,  KC_QUES, KC_SCLN, KC_BSLS, KC_PIPE, _______, \
                       _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______\
),
/* RAISE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      | Ins  | Pscr |  Up  | Menu | PGUP |                    | xxxx | PWrd |  Up  | NWrd | DLine|      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      | LAlt | Left | Down | Right| PGDN |-------.    ,-------| xxxx | Left | Down | Rigth|  Del |      |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * |      | Undo |  Cut | Copy | Paste|      |-------|    |-------|      | LStr |      | LEnd |      |      |
 * `-----------------------------------------/      /      \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |LOWER | /SPACE /        \ENTER \  |RAISE | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/      /          \      \ |      |      |      |      |
 *            `----------------------------------'            '------''---------------------------'
 */
[_RAISE] = LAYOUT( \
  _______, _______ , _______ , _______ , _______,  _______,                          _______, _______,  _______, _______,  _______,  _______, \
  _______,  KC_INS,  KC_PSCR,  KC_UP,    KC_APP,   KC_PGUP,                          XXXXXXX, KC_PRVWD, XXXXXXX, KC_NXTWD, KC_DLINE, _______, \
  _______, KC_LALT,  KC_LEFT,  KC_DOWN,  KC_RIGHT, KC_PGDN,                          XXXXXXX, KC_RCTL , KC_RALT, XXXXXXX,  KC_DEL,   _______, \
  _______, KC_UNDO,  KC_CUT,   KC_COPY,  KC_PASTE, XXXXXXX,  _______,       _______, XXXXXXX, KC_LSTRT, XXXXXXX, KC_LEND,  XXXXXXX,  _______, \
                         _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______ \
),
/* ADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | RESET|      |QWERTY|DVORAK|MACWIN|      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |MACWIN|      |      |      |-------.    ,-------|      | VOLDN| MUTE | VOLUP|      |      |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      | PREV | PLAY | NEXT |      |      |
 * `-----------------------------------------/      /      \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |LOWER | /SPACE /        \ENTER \ |RAISE | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/      /          \      \|      |      |      |      |
 *            `----------------------------------'            '------'---------------------------'
 */
  [_ADJUST] = LAYOUT( \
  XXXXXXX , XXXXXXX,  XXXXXXX ,  XXXXXXX , XXXXXXX, XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  RESET  , XXXXXXX,KC_QWERTY,KC_DVORAK,CG_TOGG,XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  XXXXXXX , XXXXXXX,CG_TOGG, XXXXXXX,    XXXXXXX,  XXXXXXX,                     XXXXXXX, KC_VOLD, KC_MUTE, KC_VOLU, XXXXXXX, XXXXXXX, \
  XXXXXXX , XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX,  XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX, XXXXXXX, \
                   _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______ \
  )
};

#ifdef OLED_DRIVER_ENABLE

static void render_logo(void) {
    static const char PROGMEM qmk_logo[] = {
        0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
        0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
	0xC0,0xC1,0xC2,0xC3,0xC4,0xC5,0xC6,0x4d,0x69,0x6c,0x69,0x6e,0x64,0xCE,0x4b,0x61,0x6d,0x62,0x6c,0x65,0xd4,0 // Milind Kamble
    };

    oled_write_P(qmk_logo, false);
}

static void print_status_narrow(void) {
    // Print current mode
    oled_write_P(PSTR("\n\n"), false);
    oled_write_ln_P(PSTR("MODE"), false);
    oled_write_ln_P(PSTR(""), false);
    if (keymap_config.swap_lctl_lgui) {
        oled_write_ln_P(PSTR("MAC"), false);
    } else {
        oled_write_ln_P(PSTR("WIN"), false);
    }

    switch (get_highest_layer(default_layer_state)) {
        case _QWERTY:
            oled_write_ln_P(PSTR("Qwrt"), false);
            break;
        case _DVORAK:
            oled_write_ln_P(PSTR("Dvrk"), false);
            break;
        default:
            oled_write_P(PSTR("Undef"), false);
    }
    oled_write_P(PSTR("\n\n"), false);
    // Print current layer
    oled_write_ln_P(PSTR("LAYER"), false);
    switch (get_highest_layer(layer_state)) {
        case _DVORAK:
        case _QWERTY:
            oled_write_P(PSTR("Base\n"), false);
            break;
        case _RAISE:
            oled_write_P(PSTR("Raise"), false);
            break;
        case _LOWER:
            oled_write_P(PSTR("Lower"), false);
            break;
        case _ADJUST:
            oled_write_P(PSTR("Adj\n"), false);
            break;
        default:
            oled_write_ln_P(PSTR("Undef"), false);
    }
    oled_write_P(PSTR("\n\n"), false);
    led_t led_usb_state = host_keyboard_led_state();
    oled_write_ln_P(PSTR("CPSLK"), led_usb_state.caps_lock);
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_270;
    }
    return rotation;
}

void oled_task_user(void) {
    if (is_keyboard_master()) {
        print_status_narrow();
    } else {
        render_logo();
    }
}

#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
            }
            return false;
        case KC_DVORAK:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_DVORAK);
            }
            return false;
        case KC_LOWER:
            if (record->event.pressed) {
                layer_on(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            return false;
        case KC_RAISE:
            if (record->event.pressed) {
                layer_on(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            return false;
        case KC_ADJUST:
            if (record->event.pressed) {
                layer_on(_ADJUST);
            } else {
                layer_off(_ADJUST);
            }
            return false;
        case KC_PRVWD:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    register_mods(mod_config(MOD_LALT));
                    register_code(KC_LEFT);
                } else {
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_LEFT);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LALT));
                    unregister_code(KC_LEFT);
                } else {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_LEFT);
                }
            }
            break;
        case KC_NXTWD:
             if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    register_mods(mod_config(MOD_LALT));
                    register_code(KC_RIGHT);
                } else {
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_RIGHT);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LALT));
                    unregister_code(KC_RIGHT);
                } else {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_RIGHT);
                }
            }
            break;
        case KC_LSTRT:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                     //CMD-arrow on Mac, but we have CTL and GUI swapped
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_LEFT);
                } else {
                    register_code(KC_HOME);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_LEFT);
                } else {
                    unregister_code(KC_HOME);
                }
            }
            break;
        case KC_LEND:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    //CMD-arrow on Mac, but we have CTL and GUI swapped
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_RIGHT);
                } else {
                    register_code(KC_END);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_RIGHT);
                } else {
                    unregister_code(KC_END);
                }
            }
            break;
        case KC_DLINE:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_BSPC);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_BSPC);
            }
            break;
        case KC_COPY:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_C);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_C);
            }
            return false;
        case KC_PASTE:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_V);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_V);
            }
            return false;
        case KC_CUT:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_X);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_X);
            }
            return false;
            break;
        case KC_UNDO:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_Z);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_Z);
            }
            return false;
    }
    return true;
}

#ifdef ENCODER_ENABLE

void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    } else if (index == 1) {
        if (clockwise) {
            tap_code(KC_PGDOWN);
        } else {
            tap_code(KC_PGUP);
        }
    }
}

#endif
