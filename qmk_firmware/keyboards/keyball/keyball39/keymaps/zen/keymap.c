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

enum Layers {
  _QWERTY,
  _MOUSE,
  _NUMBERS_AND_INPUT,
  _SYMBOLS,
  _ARROWS_AND_INPUT,
  _WINDOW_AND_FN,
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_universal(
    KC_Q           , KC_W    , KC_E    , KC_R          , KC_T                   ,                          KC_Y                        , KC_U                    , KC_I          , KC_O          , KC_P              ,
    LCTL_T(KC_A)   , KC_S    , KC_D    , KC_F          , KC_G                   ,                          KC_H                        , KC_J                    , KC_K          , KC_L          , LCTL_T(KC_ENTER)  ,
    KC_Z           , KC_X    , KC_C    , KC_V          , KC_B                   ,                          KC_N                        , KC_M                    , KC_COMM       , KC_DOT        , KC_TAB            ,
    LSFT_T(KC_ESC) , KC_LWIN , KC_LALT ,LALT_T(KC_LNG2), MO(_NUMBERS_AND_INPUT) ,LT(_SYMBOLS,KC_SPACE),    LT(_WINDOW_AND_FN,KC_SPACE) , MO(_ARROWS_AND_INPUT) , _______       , _______       , _______           , RSFT_T(KC_LNG1)
  ),

  [_MOUSE] = LAYOUT_universal(
    XXXXXXX                , XXXXXXX       , XXXXXXX       , XXXXXXX       , XXXXXXX           ,                            XXXXXXX  , KC_BTN4    , XXXXXXX       , KC_BTN5       , XXXXXXX       ,
    KC_LCTL                , XXXXXXX       , XXXXXXX       , XXXXXXX       , XXXXXXX           ,                            XXXXXXX  , KC_BTN1    , SCRL_MO       , KC_BTN2       , _______       ,
    XXXXXXX                , XXXXXXX       , XXXXXXX       , XXXXXXX       , XXXXXXX           ,                            XXXXXXX  , XXXXXXX    , XXXXXXX       , XXXXXXX       , XXXXXXX       ,
    LSFT_T(TO(_QWERTY))    , XXXXXXX       , XXXXXXX       , _______       , _______           , _______      ,             XXXXXXX  , XXXXXXX    , XXXXXXX       , XXXXXXX       , XXXXXXX       , _______
  ),

  [_NUMBERS_AND_INPUT] = LAYOUT_universal(
    XXXXXXX        , KC_1          , KC_2          , KC_3          , XXXXXXX           ,                            LCA(KC_T)  , XXXXXXX      , XXXXXXX       , XXXXXXX       , XXXXXXX       ,
    KC_0           , KC_4          , KC_5          , KC_6          , XXXXXXX           ,                            XXXXXXX    , KC_BACKSPACE , KC_DELETE     , KC_F7         , XXXXXXX       ,
    XXXXXXX        , KC_7          , KC_8          , KC_9          , XXXXXXX           ,                            XXXXXXX    , XXXXXXX      , XXXXXXX       , XXXXXXX       , XXXXXXX       ,
    _______        , XXXXXXX       , XXXXXXX       , XXXXXXX       , XXXXXXX           , XXXXXXX      ,             LCTL(KC_C) , LCTL(KC_V)   , XXXXXXX       , XXXXXXX       , XXXXXXX       , _______
  ),

  [_SYMBOLS] = LAYOUT_universal(
    LSFT(KC_4)       , LSFT(KC_5)    , LSFT(KC_6)    , LSFT(KC_7)    , LSFT(KC_8)         ,                          LSFT(KC_MINUS)     , LSFT(KC_9)            , LSFT(KC_0)             , KC_EQUAL , LSFT(KC_EQUAL) ,
    LSFT(KC_1)       , LSFT(KC_2)    , LSFT(KC_3)    , KC_GRAVE      , LSFT(KC_GRAVE)     ,                          KC_MINUS           , KC_LEFT_BRACKET       , KC_RIGHT_BRACKET       , KC_QUOTE , LSFT(KC_QUOTE) ,
    KC_SEMICOLON     , XXXXXXX       , XXXXXXX       , KC_BACKSLASH  , LSFT(KC_BACKSLASH) ,                          LSFT(KC_SEMICOLON) , LSFT(KC_LEFT_BRACKET) , LSFT(KC_RIGHT_BRACKET) , KC_SLASH , LSFT(KC_SLASH) ,
    _______          , XXXXXXX       , XXXXXXX       , XXXXXXX       , XXXXXXX            , XXXXXXX   ,              LCTL(KC_X)         , XXXXXXX               , XXXXXXX                , XXXXXXX  , XXXXXXX        , _______
  ),

  [_ARROWS_AND_INPUT] = LAYOUT_universal(
    XXXXXXX          , XXXXXXX       , XXXXXXX       , XXXXXXX       , XXXXXXX           ,                             XXXXXXX , KC_PAGE_UP , KC_UP         , KC_PAGE_DOWN  , XXXXXXX        ,
    XXXXXXX          , KC_BACKSPACE  , KC_DELETE     , XXXXXXX       , XXXXXXX           ,                       LCTL(KC_LEFT) , KC_LEFT    , KC_DOWN       , KC_RIGHT      , LCTL(KC_RIGHT) ,
    XXXXXXX          , XXXXXXX       , XXXXXXX       , XXXXXXX       , XXXXXXX           ,                             XXXXXXX , XXXXXXX    , XXXXXXX       , XXXXXXX       , XXXXXXX        ,
    _______          , AML_TO        , XXXXXXX       , LCTL(KC_A)    , RCS(KC_Z)         , LCTL(KC_Z)  ,               XXXXXXX , XXXXXXX    , XXXXXXX       , XXXXXXX       , XXXXXXX        , _______
  ),

  [_WINDOW_AND_FN] = LAYOUT_universal(
    KC_F12           , KC_F1         , KC_F2         , KC_F3         , XXXXXXX           ,                             XXXXXXX , LCTL(KC_KP_MINUS) , RCS(KC_S)     , LCTL(KC_KP_PLUS) , XXXXXXX        ,
    KC_F10           , KC_F4         , KC_F5         , KC_F6         , XXXXXXX           ,                             XXXXXXX , SWIN(KC_LEFT)     , KC_F11        , SWIN(KC_RIGHT)   , XXXXXXX        ,
    KC_F11           , KC_F7         , KC_F8         , KC_F9         , XXXXXXX           ,                             XXXXXXX , XXXXXXX           , XXXXXXX       , XXXXXXX          , XXXXXXX        ,
    _______          , AML_TO        , XXXXXXX       , XXXXXXX       , XXXXXXX           , XXXXXXX     ,               XXXXXXX , XXXXXXX           , XXXXXXX       , XXXXXXX          , XXXXXXX        , _______
  ),

  // keymap template
  // [n] = LAYOUT_universal(
  // XXXXXXX          , XXXXXXX       , XXXXXXX       , XXXXXXX       , XXXXXXX           ,                             XXXXXXX , XXXXXXX    , XXXXXXX       , XXXXXXX       , XXXXXXX       ,
  // XXXXXXX          , XXXXXXX       , XXXXXXX       , XXXXXXX       , XXXXXXX           ,                             XXXXXXX , XXXXXXX    , XXXXXXX       , XXXXXXX       , XXXXXXX       ,
  // XXXXXXX          , XXXXXXX       , XXXXXXX       , XXXXXXX       , XXXXXXX           ,                             XXXXXXX , XXXXXXX    , XXXXXXX       , XXXXXXX       , XXXXXXX       ,
  // _______          , XXXXXXX       , XXXXXXX       , XXXXXXX       , XXXXXXX           , XXXXXXX     ,               XXXXXXX , XXXXXXX    , XXXXXXX       , XXXXXXX       , XXXXXXX       , _______
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
bool is_init = true;

void oledkit_render_info_user(void) {
    // FIXME use pointing_device_init_user
    if (is_init) {
      set_auto_mouse_enable(true);
      is_init = false;
    }

    keyball_oled_render_keyinfo();
    keyball_oled_render_ballinfo();
    keyball_oled_render_layerinfo();
}
#endif

#ifdef KEYBALL_AUTO_MOUSE_THRESHOLD
bool auto_mouse_activation(report_mouse_t mouse_report) {
    int16_t total_motion = abs(mouse_report.x) + abs(mouse_report.y);
    return total_motion > KEYBALL_AUTO_MOUSE_THRESHOLD || mouse_report.buttons;
}
#endif

// FIXME use pointing_device_init_user
/* void pointing_device_init_user(void) { */
/*     // always required before the auto mouse feature will work */
/*     set_auto_mouse_enable(true); */
/* } */
