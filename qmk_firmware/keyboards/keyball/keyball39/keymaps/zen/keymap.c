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

#include "lib/keyball/keyball.h"
#include "quantum.h"

#ifdef OS_DETECTION_ENABLE
#include "os_detection.h"
#endif

enum Layers {
  _QWERTY,
  _NUMBERS_AND_INPUT,
  _SYMBOLS,
  _ARROWS_AND_FN,
  _ALT_TAB,
};

// alias
#define LCS(kc) LCTL(LSFT(kc))
#define KC_D_QUOTE KC_DQUO
#define KC_L_BRACKET KC_LEFT_BRACKET
#define KC_R_BRACKET KC_RIGHT_BRACKET
#define KC_L_PAREN KC_LEFT_PAREN
#define KC_R_PAREN KC_RIGHT_PAREN

// shortcut
#define LOCK_SCR LCS(KC_R)
#define PR_SCR LCS(KC_S)
#define COPY LCTL(KC_C)
#define PASTE LCTL(KC_V)
#define CUT LCTL(KC_X)
#define ZOOM_OUT LCTL(KC_KP_MINUS)
#define ZOOM_IN LCTL(KC_KP_PLUS)
#define FULL_SCR LWIN(KC_UP)
#define LEFT_WIN SWIN(KC_LEFT)
#define RIGHT_WIN SWIN(KC_RIGHT)
#define HOME LCTL(KC_LEFT)
#define END LCTL(KC_RIGHT)

// hold and tap
#define ALT_OR_EN LALT_T(KC_LNG2)
#define SFT_OR_ESC RSFT_T(KC_ESC)
#define CTL_OR_MINUS LCTL_T(KC_MINUS)
#define CTL_OR_SEMIC LCTL_T(KC_SEMICOLON)

// MO
#define TO_NUMBERS MO(_NUMBERS_AND_INPUT)
#define TO_AROOWS MO(_ARROWS_AND_FN)

// LT
#define SYM_OR_SPACE LT(_SYMBOLS, KC_SPACE)
#define ARROWS_OR_ENT LT(_ARROWS_AND_FN, KC_ENTER)
#define NUMS_OR_ENT LT(_NUMBERS_AND_INPUT, KC_ENTER)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // space wide is 15 charactor between comma and comma
  [_QWERTY] = LAYOUT_universal(
    KC_Q          , KC_W          , KC_E          , KC_R          , KC_T          ,                  KC_Y          , KC_U          , KC_I          , KC_O          , KC_P          ,
    LCTL_T(KC_A)  , KC_S          , KC_D          , KC_F          , KC_G          ,                  KC_H          , KC_J          , KC_K          , KC_L          , CTL_OR_MINUS  ,
    KC_Z          , KC_X          , KC_C          , KC_V          , KC_B          ,                  KC_N          , KC_M          , KC_COMMA      , KC_DOT        , KC_TAB        ,
    SFT_OR_ESC    , KC_BTN2       , KC_BTN1       , ALT_OR_EN     , NUMS_OR_ENT   , SYM_OR_SPACE  ,  KC_SPACE      , ARROWS_OR_ENT , XXXXXXX       , XXXXXXX       , XXXXXXX       , RSFT_T(KC_LNG1)
  ),

  [_NUMBERS_AND_INPUT] = LAYOUT_universal(
    LOCK_SCR      , KC_1          , KC_2          , KC_3          , XXXXXXX       ,                  XXXXXXX       , KC_DELETE     , CUT           , FULL_SCR      , PASTE         ,
    LCTL_T(KC_0)  , KC_4          , KC_5          , KC_6          , XXXXXXX       ,                  XXXXXXX       , KC_BACKSPACE  , COPY          , KC_F7         , XXXXXXX       ,
    XXXXXXX       , KC_7          , KC_8          , KC_9          , XXXXXXX       ,                  LEFT_WIN      , RIGHT_WIN     , XXXXXXX       , XXXXXXX       , KC_TAB        ,
    _______       , XXXXXXX       , XXXXXXX       , _______       , _______       , _______       ,  _______       , _______       , XXXXXXX       , XXXXXXX       , XXXXXXX       , _______
  ),

  [_SYMBOLS] = LAYOUT_universal(
    KC_DOLLAR     , KC_PERCENT    , KC_HASH       , KC_AMPERSAND  , KC_ASTERISK   ,                  KC_AT         , KC_L_PAREN    , KC_R_PAREN    , KC_EQUAL      , KC_PLUS       ,
    CTL_OR_SEMIC  , KC_PIPE       , KC_BACKSLASH  , KC_GRAVE      , KC_EXCLAIM    ,                  KC_COLON      , KC_L_BRACKET  , KC_R_BRACKET  , KC_QUOTE      , KC_D_QUOTE    ,
    KC_CIRC       , XXXXXXX       , XXXXXXX       , XXXXXXX       , XXXXXXX       ,                  KC_TILDE      , KC_LCBR       , KC_RCBR       , KC_SLASH      , KC_QUESTION   ,
    _______       , XXXXXXX       , XXXXXXX       , _______       , _______       , _______       ,  _______       , _______       , XXXXXXX       , XXXXXXX       , XXXXXXX       , _______
  ),

  [_ARROWS_AND_FN] = LAYOUT_universal(
    XXXXXXX       , KC_F1         , KC_F2         , KC_F3         , KC_F11        ,                  XXXXXXX       , KC_PAGE_UP    , KC_UP         , KC_PAGE_DOWN  , PR_SCR        ,
    KC_LEFT_CTRL  , KC_F4         , KC_F5         , KC_F6         , KC_F10        ,                  HOME          , KC_LEFT       , KC_DOWN       , KC_RIGHT      , END           ,
    XXXXXXX       , KC_F7         , KC_F8         , KC_F9         , KC_F12        ,                  ZOOM_OUT      , ZOOM_IN       , XXXXXXX       , XXXXXXX       , XXXXXXX       ,
    _______       , KC_BTN5       , KC_BTN4       , _______       , _______       , _______       ,  _______       , _______       , XXXXXXX       , XXXXXXX       , XXXXXXX       , _______
  ),

  [_ALT_TAB] = LAYOUT_universal(
    XXXXXXX       , KC_TAB        , XXXXXXX       , XXXXXXX       , XXXXXXX       ,                  XXXXXXX       , XXXXXXX       , KC_UP         , XXXXXXX       , XXXXXXX       ,
    XXXXXXX       , XXXXXXX       , XXXXXXX       , KC_BTN1       , XXXXXXX       ,                  XXXXXXX       , KC_LEFT       , KC_DOWN       , KC_RIGHT      , XXXXXXX       ,
    XXXXXXX       , XXXXXXX       , XXXXXXX       , XXXXXXX       , XXXXXXX       ,                  XXXXXXX       , XXXXXXX       , XXXXXXX       , XXXXXXX       , TO(_QWERTY)   ,
    _______       , XXXXXXX       , XXXXXXX       , XXXXXXX       , XXXXXXX       , XXXXXXX       ,  XXXXXXX       , XXXXXXX       , XXXXXXX       , XXXXXXX       , XXXXXXX       , _______
  ),

  // keymap template
  // [n] = LAYOUT_universal(
  // XXXXXXX       , XXXXXXX       , XXXXXXX       , XXXXXXX       , XXXXXXX       ,                  XXXXXXX       , XXXXXXX       , XXXXXXX       , XXXXXXX       , XXXXXXX       ,
  // XXXXXXX       , XXXXXXX       , XXXXXXX       , XXXXXXX       , XXXXXXX       ,                  XXXXXXX       , XXXXXXX       , XXXXXXX       , XXXXXXX       , XXXXXXX       ,
  // XXXXXXX       , XXXXXXX       , XXXXXXX       , XXXXXXX       , XXXXXXX       ,                  XXXXXXX       , XXXXXXX       , XXXXXXX       , XXXXXXX       , XXXXXXX       ,
  // _______       , XXXXXXX       , XXXXXXX       , XXXXXXX       , XXXXXXX       , XXXXXXX       ,  XXXXXXX       , XXXXXXX       , XXXXXXX       , XXXXXXX       , XXXXXXX       , _______
  // ),
};
// clang-format on
void keyball_set_scroll_mode_and_scroll_snap_mode(
    keyball_scrollsnap_mode_t scroll_snap_mode) {
  keyball_set_scroll_mode(true);
  keyball_set_scrollsnap_mode(scroll_snap_mode);
}

void keyball_reset_scroll_mode_and_scroll_snap_mode(void) {
  keyball_set_scroll_mode(false);
  keyball_set_scrollsnap_mode(KEYBALL_SCROLLSNAP_MODE_FREE);
}

layer_state_t layer_state_set_user(layer_state_t state) {
  // set scroll mode
  uint8_t current_layer = get_highest_layer(state);
  switch (current_layer) {
  case _NUMBERS_AND_INPUT:
    // scroll
    keyball_set_scroll_mode_and_scroll_snap_mode(
        KEYBALL_SCROLLSNAP_MODE_HORIZONTAL);
    break;
  default:
    keyball_reset_scroll_mode_and_scroll_snap_mode();
  }
  return state;
}

#ifdef OLED_ENABLE
void keyball_oled_render_osinfo(void) {
  oled_write_char('O', false);
  oled_write_char('S', false);
  oled_write_char(' ', false);

  switch (detected_host_os()) {
  case OS_MACOS:
    oled_write_char('M', false);
    oled_write_char('A', false);
    oled_write_char('C', false);
    break;
  case OS_IOS:
    oled_write_char('I', false);
    oled_write_char('O', false);
    oled_write_char('S', false);
    break;
  case OS_WINDOWS:
    oled_write_char('W', false);
    oled_write_char('I', false);
    oled_write_char('N', false);
    break;
  case OS_LINUX:
    oled_write_char('L', false);
    oled_write_char('I', false);
    oled_write_char('N', false);
    break;
  case OS_UNSURE:
    oled_write_char('U', false);
    oled_write_char('N', false);
    oled_write_char('S', false);
    break;
  }
}

#include "lib/oledkit/oledkit.h"

void oledkit_render_info_user(void) {
  keyball_oled_render_keyinfo();
  keyball_oled_render_ballinfo();
  keyball_oled_render_layerinfo();
  keyball_oled_render_osinfo();
}
#endif

#ifdef KEYBALL_AUTO_MOUSE_THRESHOLD
bool auto_mouse_activation(report_mouse_t mouse_report) {
  int16_t total_motion = abs(mouse_report.x) + abs(mouse_report.y);
  return total_motion > KEYBALL_AUTO_MOUSE_THRESHOLD || mouse_report.buttons;
}
#endif

bool is_alt_tab_mode(void) {
  uint8_t current_layer = get_highest_layer(layer_state);
  return current_layer == _ALT_TAB;
}

bool is_alt_pressed_only(void) {
  uint8_t mods = get_mods();
  bool pressed_alt = mods & MOD_MASK_ALT;
  bool pressed_alt_only = (mods & ~MOD_MASK_ALT) == 0;
  return pressed_alt && pressed_alt_only;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
  case KC_W:
    // ref:
    // https://docs.qmk.fm/feature_advanced_keycodes#checking-modifier-state
    if (record->event.pressed) {
      if (!is_alt_tab_mode()) {
        if (is_alt_pressed_only()) {
          register_code(KC_LALT);
          tap_code(KC_TAB);
          layer_on(_ALT_TAB);
          return false;
        }
      }
    }
    break;
  case ALT_OR_EN:
    if (record->event.pressed) {
      keyball_set_scroll_mode_and_scroll_snap_mode(
          KEYBALL_SCROLLSNAP_MODE_VERTICAL);
    } else {
      keyball_reset_scroll_mode_and_scroll_snap_mode();
    }

    if (record->event.pressed) {
      return true;
    }

    if (is_alt_tab_mode()) {
      layer_off(_ALT_TAB);
      unregister_code(KC_LALT);
      return false;
    }
    break;
  }

  return true;
}

#ifdef KEYBALL_REVERSE_SCROLL

void keyball_on_apply_motion_to_mouse_scroll_user(keyball_motion_t *m,
                                                  report_mouse_t *r,
                                                  bool is_left) {
  // reverse scroll
  os_variant_t os = detected_host_os();
  switch (os) {
  case OS_MACOS:
  case OS_IOS:
    r->h = -r->h;
    r->v = -r->v;
    break;
  default:
    // do nothing
    break;
  }
}

#endif

