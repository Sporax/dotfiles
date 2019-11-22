#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* layer 0: default
 * ,-------------------------------------------------------------------------------------.
 * | Esc/~ |   q  |   w  |   e  |   r  |   t  |   y  |   u  |   i  |   o  |   p  | Bksp  |
 * |-------+------+------+------+------+-------------+------+------+------+------+-------|
 * |  Tab  |   a  |   s  |   d  |   f  |   g  |   h  |   j  |   k  |   l  |   ;  | Ret   |
 * |-------+------+------+------+------+------|------+------+------+------+------+-------|
 * | Caps/S|   z  |   x  |   c  |   v  |   b  |   n  |   m  |   ,  |   .  |   /  | Shift |
 * |-------+------+------+------+------+------+------+------+------+------+------+-------|
 * |  Ctrl |  [3] |  Win |  Alt | [Dwn]|  Win |  Spc | [Up] |  Alt | TabP | TabN | Ctrl  |
 * `-------------------------------------------------------------------------------------'
 */

[0] = LAYOUT_ortho_4x12(
    KC_GESC, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT,
    LSFT_T(KC_CAPS),  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,    KC_RSFT,
    KC_LCTL, TO(3),   LM(4,MOD_LGUI),   KC_LALT, TT(1),   KC_SPC,  KC_SPC,  TT(2),   KC_RALT, LCTL(KC_PGUP), LCTL(KC_PGDN), KC_RCTL
),

/* layer 1: numbers, symbols
 * ,-----------------------------------------------------------------------------------.
 * |  [0] |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |   !  |   @  |   #  |   $  |   %  |   ^  |   '  |   [  |   (  |   )  | Ret  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | L_Sh |   `  |   ^  |   &  |   *  |   \  |   -  |   =  |   ]  |   {  |   }  | R_Sh |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |  [3] |  Win |  Alt |  [0] |     Spc     |  [2] |  Alt | TabP | TabN | Ctrl |
 * `-----------------------------------------------------------------------------------'
 */

[1] = LAYOUT_ortho_4x12(
    TO(0),   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
    KC_DEL,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_QUOT, KC_LBRC, KC_LPRN, KC_RPRN, KC_ENT,
    KC_LSFT, KC_GRV,  KC_CIRC, KC_AMPR, KC_ASTR, KC_BSLS, KC_MINS, KC_EQL,  KC_RBRC, KC_LCBR, KC_RCBR, KC_RSFT,
    KC_LCTL, TO(3),   LM(4,MOD_LGUI),   KC_LALT, TO(0),   KC_SPC,  KC_SPC,  TO(2),   KC_RALT, LCTL(KC_PGUP), LCTL(KC_PGDN), KC_RCTL
),

/* layer 2: navigation
 * ,-----------------------------------------------------------------------------------.
 * |  [0] | prev | Play | next | mute | sleep|      |      |      |      |      | Bksp |
 * |      | track|      | track|      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Tab  |      | Rec  | Stop | Play | ☼ up | Vol_U| Home | Pg Up|  Up  |Pg Dn | Del  |
 * |      |      |Macro1| Rec  |Macro1|      |      |      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift| Undo | Cut  | Copy | Paste| ☼ dwn| Vol_D| End  | Left | Down | Right| R.Sh |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |  [3] |  Win |  Alt |  [1] |     Spc     |  [0] |  Alt | Ctrl |Accel1|Accel2|   # ∇
 * `-----------------------------------------------------------------------------------'
 */

[2] = LAYOUT_ortho_4x12(
    TO(0),   KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE, KC_SLEP, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_BSPC,
    KC_TAB,  KC_NO,   DM_REC1, DM_RSTP, DM_PLY1, KC_BRIU, KC_VOLU, KC_HOME, KC_PGUP, KC_UP,   KC_PGDN, KC_DEL,
    KC_LSFT, KC_UNDO, KC_CUT,  KC_COPY, KC_PSTE, KC_BRID, KC_VOLD, KC_END,  KC_LEFT, KC_DOWN, KC_RGHT, KC_RSFT,
    KC_LCTL, TO(3),   LM(4, MOD_LGUI),  KC_LALT, TO(1),   KC_SPC,  KC_SPC,  TO(0),   KC_RCTL, KC_ACL0, KC_ACL1, KC_RCTL
),

/* layer 3: NDEFINED, extra space for macros, work automation
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  [0] |      |      |  [1] |     Spc     |  [2] |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */

[3] = LAYOUT_ortho_4x12(
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
    KC_NO,   TO(0),   KC_NO,   KC_NO,   TO(1),   KC_SPC,  KC_SPC,  TO(2),   KC_NO,   KC_NO,   KC_NO,   KC_NO
),

/* layer 8: "windows layer" (actually codes to send to i3)
 * ,-------------------------------------------------------------------------------------.
 * |  Esc  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |   -   |
 * |-------+------+------+------+------+-------------+------+------+------+------+-------|
 * |  Tab  |   q  |   w  |   e  |   f  |   t  |   h  |   j  |   k  |   l  |   ;  | Ret   |
 * |-------+------+------+------+------+------|------+------+------+------+------+-------|
 * | Caps/S|   a  |   s  |   d  |   v  |   b  |   r  | m(?) | ,(?) | .(?) | /(?) | Shift |
 * |-------+------+------+------+------+------+------+------+------+------+------+-------|
 * |  Ctrl |  ?   |  Win |  Alt |   ?  |  Win |  Spc |   ?  |  Alt |   ?  |   ?  | Ctrl  |
 * `-------------------------------------------------------------------------------------'
 */

[4] = LAYOUT_ortho_4x12(
    KC_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_F,    KC_T,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT,
    KC_LSFT, KC_A,    KC_S,    KC_D,    KC_V,    KC_B,    KC_R,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
    KC_LCTL, KC_NO,   KC_NO,   KC_LALT, KC_NO,   KC_SPC,  KC_SPC,  KC_NO,   KC_RALT, KC_NO,   KC_NO,   KC_RCTL
),
};
