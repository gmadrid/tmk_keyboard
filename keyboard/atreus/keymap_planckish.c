#include "keymap_common.h"

/* My Atreus layout - based more on the Planck default keymap:
   - Number row on "raise" layer.
   - "Lower" layer is mostly shifted versions of the raise layer.
   - vi-like cursor movement keys to allow one-handed cursor movement.
   */

#define MY_EXCL SHIFT(KC_1)
#define MY_AT   SHIFT(KC_2)
#define MY_HASH SHIFT(KC_3)
#define MY_DOLL SHIFT(KC_4)
#define MY_PERC SHIFT(KC_5)
#define MY_CRAT SHIFT(KC_6)
#define MY_AMPR SHIFT(KC_7)
#define MY_STAR SHIFT(KC_8)
#define MY_LPAR SHIFT(KC_9)
#define MY_RPAR SHIFT(KC_0)

#define LAYER_BASE 0
#define LAYER_RAISE 1
#define LAYER_LOWER 2
#define LAYER_RESET 3   

const uint16_t PROGMEM fn_actions[] = {
#define MY_RAIS KC_FN0    
  [0] = ACTION_LAYER_MOMENTARY(LAYER_RAISE),

#define MY_LOWR KC_FN1
  [1] = ACTION_LAYER_MOMENTARY(LAYER_LOWER),

#define MY_RLYR KC_FN2
  [2] = ACTION_LAYER_MOMENTARY(LAYER_RESET),                // switch to reset layer

#define MY_BOOT KC_FN3
  [3] = ACTION_FUNCTION(BOOTLOADER),

#define MY_SLSH KC_FN4
  [4] = ACTION_MODS_TAP_KEY(MOD_RSFT, KC_SLSH),  // / key is LSHIFT when held down

#define MY_Z    KC_FN5
  [5] = ACTION_MODS_TAP_KEY(MOD_LSFT, KC_Z),     // Z key is RSHIFT when held down

#define MY_ENT  KC_FN6
  [6] = ACTION_MODS_TAP_KEY(MOD_RALT, KC_ENT)   // Enter key is also RALT
};

// IMPORTANT: Keep these layers in sync with the "LAYER" macros at the top.
// To reset: Raise->Lower->Q
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* LAYER_BASE 
    +------+------+------+------+------+             +------+------+------+------+------+
    |  Q   |  W   |  E   |  R   |  T   |             |  Y   |  U   |  I   |  O   |  P   |
    +------+------+------+------+------+             +------+------+------+------+------+
    |  A   |  S   |  D   |  F   |  G   |             |  H   |  J   |  K   |  L   |  ;   |
    +------+------+------+------+------+             +------+------+------+------+------+
    |Z/LSFT|  X   |  C   |  V   |  B   |             |  N   |  M   |  ,   |  .   |//RSFT|
    +------+------+------+------+------+------+------+------+------+------+------+------+
    | ESC  | TAB  | LSFT | LGUI | BSPC | LCTL |ENT/RA| SPC  |RAISE |  -   |  '   |LOWER |
    +------+------+------+------+------+------+------+------+------+------+------+------+
   */
  KEYMAP(KC_Q,   KC_W,   KC_E, KC_R, KC_T,     KC_Y,   KC_U,   KC_I,    KC_O,   KC_P,     \
         KC_A,   KC_S,   KC_D, KC_F, KC_G,     KC_H,   KC_J,   KC_K,    KC_L,   KC_SCLN,  \
         MY_Z,   KC_X,   KC_C, KC_V, KC_B,     KC_N,   KC_M,   KC_COMM, KC_DOT, MY_SLSH,  \
         KC_ESC, KC_TAB, KC_LSFT, KC_LGUI, KC_BSPC, KC_LCTL,                              \
                                       MY_ENT, KC_SPC, MY_RAIS,KC_MINS, KC_QUOT, MY_LOWR),

  /* LAYER_RAISE 
    +------+------+------+------+------+             +------+------+------+------+------+
    |  1   |  2   |  3   |  4   |  5   |             |  6   |  7   |  8   |  9   |  0   |
    +------+------+------+------+------+             +------+------+------+------+------+
    |      |      |      |      |      |             |      |      |  UP  |      |      |
    +------+------+------+------+------+             +------+------+------+------+------+
    |      |      |      |      |      |             |      | LEFT | DOWN |RIGHT |      |
    +------+------+------+------+------+------+------+------+------+------+------+------+
    |      |      |      |      |      |      |      |      |RAISE |      |      |RESET |
    +------+------+------+------+------+------+------+------+------+------+------+------+
   */
  KEYMAP(KC_1,  KC_2,  KC_3,  KC_4,  KC_5,             KC_6,    KC_7,    KC_8,    KC_9,     KC_0,  \
         KC_NO, KC_LEFT, KC_DOWN, KC_RIGHT, KC_NO,     KC_PGDN, KC_4,    KC_UP,   KC_6,     KC_NO, \
         KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,            KC_NO,   KC_LEFT, KC_DOWN, KC_RIGHT, KC_NO, \
                                MY_BOOT, SHIFT(KC_INS), KC_LGUI, KC_LSFT, KC_BSPC, KC_LCTL, \
                                  KC_LALT, KC_SPC, MY_RAIS, KC_DOT, KC_0, MY_RLYR), 
                                                                      
  /* LAYER_LOWER
    +------+------+------+------+------+             +------+------+------+------+------+
    |  !   |  @   |  #   |  $   |  %   |             |  ^   |  &   |  *   |  (   |  )   |
    +------+------+------+------+------+             +------+------+------+------+------+
    |      |      |      |      |      |             |      |      |      |      |      |
    +------+------+------+------+------+             +------+------+------+------+------+
    |      |      |      |      |      |             |      |      |      |      |      |
    +------+------+------+------+------+------+------+------+------+------+------+------+
    |      |      |      |      |      |      |      |      |RESET |      |      |LOWER |
    +------+------+------+------+------+------+------+------+------+------+------+------+
   */

  KEYMAP(MY_EXCL, MY_AT, MY_HASH, MY_DOLL, MY_PERC,    MY_CRAT, MY_AMPR, MY_STAR, MY_LPAR, MY_RPAR, \
                         KC_DEL, KC_LEFT, KC_DOWN, KC_RIGHT, KC_PGDN, \
                         KC_DOWN, KC_F4, KC_F5, KC_F6, KC_F11,          \
                         KC_NO, KC__VOLUP, KC_NO, KC_NO, MY_BOOT, \
                         KC_NO, KC_F1, KC_F2, KC_F3, KC_F12,            \
                         MY_RLYR, KC__VOLDOWN, KC_LGUI, KC_LSFT, KC_BSPC, KC_LCTL, \
                         KC_LALT, KC_SPC, MY_RLYR, KC_PSCREEN, KC_SLCK, MY_LOWR),

  /* LAYER_RESET - Top left key resets. All other keys do nothing. */
  KEYMAP(MY_BOOT,KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, \
         KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, \
         KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, \
         KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO)
};

void action_function(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  if (id == BOOTLOADER) {
    bootloader();
  }
}

/* 
    +------+------+------+------+------+             +------+------+------+------+------+
    |      |      |      |      |      |             |      |      |      |      |      |
    +------+------+------+------+------+             +------+------+------+------+------+
    |      |      |      |      |      |             |      |      |      |      |      |
    +------+------+------+------+------+             +------+------+------+------+------+
    |      |      |      |      |      |             |      |      |      |      |      |
    +------+------+------+------+------+------+------+------+------+------+------+------+
    |      |      |      |      |      |      |      |      |      |      |      |      |
    +------+------+------+------+------+------+------+------+------+------+------+------+
 */
