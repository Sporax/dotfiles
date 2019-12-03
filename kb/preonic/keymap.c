/* Copyright 2015-2017 Jack Humbert
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
#include "muse.h"

enum preonic_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  BACKLIT
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* layer 0: qwerty
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Del  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  | Ret  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |Cap/Sh|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  | Rshft|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |      | Win  | Alt  |Lower |    Space    |Raise |  Alt | TabP | TabN | Ctrl |
 * `-----------------------------------------------------------------------------------'
 */
[0] = LAYOUT_preonic_grid( \
  KC_GRV,         KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,         KC_0,         KC_DEL,  \
  KC_TAB,         KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,         KC_P,         KC_BSPC, \
  KC_ESC,         KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,         KC_SCLN,      KC_ENT,  \
  LSFT_T(KC_CAPS),KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,       KC_SLSH,      KC_RSFT, \
  KC_LCTL,        KC_NO,   KC_LGUI, KC_LALT, MO(1),   KC_SPC,  KC_SPC,  TT(2),   KC_RALT, LCTL(KC_PGUP),LCTL(KC_PGDN),KC_RCTL  \
),

/* 1: numeric
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Tab  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | [0]  |      |      |      |      |      |      |   '  |  []  |  ()  |  {}  | Ret  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|  `   |      |      |      |   \  |   -  |   =  |      |      |      | Shift|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |      | Win  | Alt  |      |     Spc     |  Up  |  Alt | TabP | TabN | Ctrl |
 * `-----------------------------------------------------------------------------------'
 */
[1] = LAYOUT_preonic_grid( \
  KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN,      KC_RPRN,      KC_DEL,  \
  KC_TAB,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,         KC_0,         KC_BSPC, \
  TO(0),   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_QUOT, KC_LBRC, KC_LPRN,      KC_RPRN,      KC_ENT,  \
  KC_LSFT, KC_GRV,  KC_NO,   KC_NO,   KC_NO,   KC_BSLS, KC_MINS, KC_EQL,  KC_RBRC, KC_LCBR,      KC_RCBR,      KC_RSFT, \
  KC_LCTL, KC_NO,   KC_LGUI, KC_LALT, KC_NO,   KC_SPC,  KC_SPC,  TO(0),   KC_RALT, LCTL(KC_PGUP),LCTL(KC_PGDN),KC_RCTL  \
),

/* 2: Raise
 * ,-------------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4   |   5  |   6  |   7   |   8  |   9  |   0  | Del  |
 * |------+------+------+------+-------+-------------+-------+------+------+------+------|
 * | Tab  | prev | Play | next | mute  |      |      |       |      |      |      | Bksp |
 * |      | track|      | track|       |      |      |       |      |      |      |      |
 * |------+------+------+------+-------+-------------+-------+------+------+------+------|
 * |  [0] |      |      |      |       | Vol_U| ☼ up |  Home | Pg Up|  Up  |Pg Dn | Del  |
 * |      |      |      |      |       |      |      |       |      |      |      |      |
 * |------+------+------+------+-------+------|------+-------+------+------+------+------|
 * | Shift| Undo | Cut  | Copy | Paste | Vol_D| ☼ dwn|  End  | Left | Down | Right| R.Sh |
 * |------+------+------+------+-------+------+------+-------+------+------+------+------|
 * | Ctrl |      |  Win |  Alt | lower |     Spc     |       |  Alt |Accel1|Accel2| Ctrl |  # ∇
 * `-------------------------------------------------------------------------------------'
 */
[2] = LAYOUT_preonic_grid( \
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,  \
  KC_TAB,  KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_BSPC, \
  TO(0),   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_VOLU, KC_BRIU, KC_HOME, KC_PGUP, KC_UP,   KC_PGDN, KC_DEL,  \
  KC_LSFT, KC_UNDO, KC_CUT,  KC_COPY, KC_PSTE, KC_VOLD, KC_BRID, KC_END,  KC_LEFT, KC_DOWN, KC_RGHT, KC_RSFT, \
  KC_LCTL, KC_NO,   KC_LGUI, KC_LALT, TO(0),   KC_SPC,  KC_SPC,  KC_NO,   KC_RCTL, KC_RALT, KC_NO,   KC_RCTL  \
),

/* 3: Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Reset|      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |Aud on|AudOff|AGnorm|AGswap|      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|MusOff|MidiOn|MidOff|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[3] = LAYOUT_preonic_grid( \
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  \
  _______, RESET,   _______, _______, _______, _______, _______, TERM_ON, TERM_OFF,_______, _______, KC_DEL,  \
  _______, _______, MU_MOD,  AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, _______, _______, _______, _______, _______, \
  _______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  \
)


};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
        case QWERTY:
          if (record->event.pressed) {
            set_single_persistent_default_layer(0);
          }
          return false;
          break;
        case LOWER:
          if (record->event.pressed) {
            layer_on(1);
            update_tri_layer(1, 2, 3);  // sets 3 if 1&2 are on
          } else {
            layer_off(1);
            update_tri_layer(1, 2, 3);
          }
          return false;
          break;
        case RAISE:
          if (record->event.pressed) {
            layer_on(2);
            update_tri_layer(1, 2, 3);
          } else {
            layer_off(2);
            update_tri_layer(1, 2, 3);
          }
          return false;
          break;
        case BACKLIT:
          if (record->event.pressed) {
            register_code(KC_RSFT);
            #ifdef BACKLIGHT_ENABLE
              backlight_step();
            #endif
            #ifdef __AVR__
            writePinLow(E6);
            #endif
          } else {
            unregister_code(KC_RSFT);
            #ifdef __AVR__
            writePinHigh(E6);
            #endif
          }
          return false;
          break;
      }
    return true;
};

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

void encoder_update_user(uint8_t index, bool clockwise) {
  if (muse_mode) {
    if (IS_LAYER_ON(2)) {
      if (clockwise) {
        muse_offset++;
      } else {
        muse_offset--;
      }
    } else {
      if (clockwise) {
        muse_tempo+=1;
      } else {
        muse_tempo-=1;
      }
    }
  } else {
    if (clockwise) {
      register_code(KC_PGDN);
      unregister_code(KC_PGDN);
    } else {
      register_code(KC_PGUP);
      unregister_code(KC_PGUP);
    }
  }
}

void dip_switch_update_user(uint8_t index, bool active) {
    switch (index) {
        case 0:
            if (active) {
                layer_on(3);
            } else {
                layer_off(3);
            }
            break;
        case 1:
            if (active) {
                muse_mode = true;
            } else {
                muse_mode = false;
            }
    }
}


void matrix_scan_user(void) {
#ifdef AUDIO_ENABLE
    if (muse_mode) {
        if (muse_counter == 0) {
            uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
            if (muse_note != last_muse_note) {
                stop_note(compute_freq_for_midi_note(last_muse_note));
                play_note(compute_freq_for_midi_note(muse_note), 0xF);
                last_muse_note = muse_note;
            }
        }
        muse_counter = (muse_counter + 1) % muse_tempo;
    } else {
        if (muse_counter) {
            stop_all_notes();
            muse_counter = 0;
        }
    }
#endif
}

bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    case RAISE:
    case LOWER:
      return false;
    default:
      return true;
  }
}

/*
* upgrade notes: alt+bksp = delete
* ~~replace current bksp with |~~ backspace is more ergo here
* del isn't working for me... make it quot or something else?? can make it just bksp for now since i keep hitting it expecting bksp to be there
* add macros to make work efficient
* add macros for bracket insertion: add closing pair and move left
* use esc as win when held
* create layer for win key with shortcuts for top row and also including the num row
* modify tt to be 2 for switching, order more gat reds to replace 4 keys on upper row, 4 keys on lower row, 2 in middle of home row
  and numbers 12,90
*/
