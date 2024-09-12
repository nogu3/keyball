/*
Copyright 2022 @Yowkees
Copyright 2022 MURAOKA Taro (aka KoRoN, @kaoriya)

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

#include "quantum.h"

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // keymap for default (VIA)
  // keyboard layer
  [0] = LAYOUT_universal(
    KC_Q           , KC_W          , KC_E          , KC_R          , KC_T              ,                            KC_Y     , KC_U       , KC_I          , KC_O          , KC_P              ,
    LCTL_T(KC_A)   , KC_S          , KC_D          , KC_F          , KC_G              ,                            KC_H     , KC_J       , KC_K          , KC_L          , LCTL_T(KC_ENTER)  ,
    KC_Z           , KC_X          , KC_C          , KC_V          , KC_B              ,                            KC_N     , KC_M       , KC_COMM       , KC_DOT        , MO(1)             ,
    LSFT_T(KC_ESC) , KC_LWIN       , LT(2,KC_TAB)  ,LALT_T(KC_LNG2), LT(2,KC_BACKSPACE),LT(3,KC_SPACE),             KC_SPACE , MO(4)      , _______       , _______       , _______           , RSFT_T(KC_LNG1)
  ),

  // mouse layer
  [1] = LAYOUT_universal(
    XXXXXXX        , XXXXXXX       , XXXXXXX       , XXXXXXX       , XXXXXXX           ,                            XXXXXXX  , MS_BTN4    , MS_BTN3       , MS_BTN5       , XXXXXXX       ,
    _______        , XXXXXXX       , XXXXXXX       , XXXXXXX       , XXXXXXX           ,                            XXXXXXX  , MS_BTN1    , SCRL_MO       , MS_BTN2       , _______       ,
    XXXXXXX        , XXXXXXX       , XXXXXXX       , XXXXXXX       , XXXXXXX           ,                            XXXXXXX  , XXXXXXX    , XXXXXXX       , XXXXXXX       , XXXXXXX       ,
    _______        , XXXXXXX       , XXXXXXX       , _______       , _______           , _______      ,             XXXXXXX  , XXXXXXX    , XXXXXXX       , XXXXXXX       , XXXXXXX       , _______ ,
  ),
  
  // numbers layer
  [2] = LAYOUT_universal(
    XXXXXXX        , KC_1          , KC_2          , KC_3          , XXXXXXX           ,                            XXXXXXX    , XXXXXXX    , XXXXXXX       , XXXXXXX       , XXXXXXX       ,
    KC_0           , KC_4          , KC_5          , KC_6          , XXXXXXX           ,                            XXXXXXX    , XXXXXXX    , XXXXXXX       , XXXXXXX       , XXXXXXX       ,
    XXXXXXX        , KC_7          , KC_8          , KC_9          , XXXXXXX           ,                            XXXXXXX    , XXXXXXX    , XXXXXXX       , XXXXXXX       , XXXXXXX       ,
    _______        , XXXXXXX       , XXXXXXX       , XXXXXXX       , XXXXXXX           , XXXXXXX      ,             LCTL(KC_C) , LCTL(KC_V) , XXXXXXX       , XXXXXXX       , XXXXXXX       , _______ ,
  ),

  // symbols layer
  [3] = LAYOUT_universal(
    LSFT(KC_4)       , LSFT(KC_5)    , LSFT(KC_6)    , LSFT(KC_7)    , LSFT(KC_8)         ,                          LSFT(KC_MINUS)     , LSFT(KC_9)            , LSFT(KC_8)             , KC_EQUAL , LSFT(KC_EQUAL) ,
    LSFT(KC_1)       , LSFT(KC_2)    , LSFT(KC_3)    , KC_GRAVE      , LSFT(KC_GRAVE)     ,                          KC_MINUS           , KC_LEFT_BRACKET       , KC_RIGHT_BRACKET       , KC_QUOTE , LSFT(KC_QUOTE) ,
    XXXXXXX          , XXXXXXX       , KC_SEMICOLON  , KC_BACKSLASH  , LSFT(KC_BACKSLASH) ,                          LSFT(KC_SEMICOLON) , LSFT(KC_LEFT_BRACKET) , LSFT(KC_RIGHT_BRACKET) , KC_SLASH , LSFT(KC_SLASH) ,
    _______          , XXXXXXX       , XXXXXXX       , XXXXXXX       , XXXXXXX            , XXXXXXX   ,              LCTL(KC_X)         , XXXXXXX               , XXXXXXX                , XXXXXXX  , XXXXXXX        , _______ ,
  ),

  // arrows and keyball layer
  [4] = LAYOUT_universal(
    KC_F12           , KC_F1         , KC_F2         ,KC_F3          , XXXXXXX           ,                             XXXXXXX , XXXXXXX    , KC_UP         , XXXXXXX       , XXXXXXX        ,
    KC_F10           , KC_F4         , KC_F5         ,KC_F6          , XXXXXXX           ,                       LCTL(KC_LEFT) , KC_LEFT    , KC_DOWN       , KC_RIGHT      , LCTL(KC_RIGHT) ,
    KC_F11           , KC_F7         , KC_F8         ,KC_F9          , XXXXXXX           ,                             XXXXXXX , XXXXXXX    , XXXXXXX       , XXXXXXX       , XXXXXXX        ,
    _______          , AML_TO        , XXXXXXX       , LCTL(KC_A)    , KC_DELETE         , LCTL(KC_Z)  ,               XXXXXXX , XXXXXXX    , XXXXXXX       , XXXXXXX       , XXXXXXX        , _______ ,
  ),

  // keymap template
  // [n] = LAYOUT_universal(
  // XXXXXXX          , XXXXXXX       , XXXXXXX       , XXXXXXX       , XXXXXXX           ,                             XXXXXXX , XXXXXXX    , XXXXXXX       , XXXXXXX       , XXXXXXX       ,
  // XXXXXXX          , XXXXXXX       , XXXXXXX       , XXXXXXX       , XXXXXXX           ,                             XXXXXXX , XXXXXXX    , XXXXXXX       , XXXXXXX       , XXXXXXX       ,
  // XXXXXXX          , XXXXXXX       , XXXXXXX       , XXXXXXX       , XXXXXXX           ,                             XXXXXXX , XXXXXXX    , XXXXXXX       , XXXXXXX       , XXXXXXX       ,
  // _______          , XXXXXXX       , XXXXXXX       , XXXXXXX       , XXXXXXX           , XXXXXXX     ,               XXXXXXX , XXXXXXX    , XXXXXXX       , XXXXXXX       , XXXXXXX       , _______ ,
  // ),
};
// clang-format on

layer_state_t layer_state_set_user(layer_state_t state) {
    // Auto enable scroll mode when the highest layer is 3
    keyball_set_scroll_mode(get_highest_layer(state) == 3);
    return state;
}

#ifdef OLED_ENABLE

#    include "lib/oledkit/oledkit.h"

void oledkit_render_info_user(void) {
    keyball_oled_render_keyinfo();
    keyball_oled_render_ballinfo();
    keyball_oled_render_layerinfo();
}
#endif
