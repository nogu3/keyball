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
#include "lib/keyball/keyball.h"

#ifdef OS_DETECTION_ENABLE
  #include "os_detection.h"
#endif

enum Layers {
  _QWERTY,
  _NUMBERS_AND_INPUT,
  _SYMBOLS,
  _ARROWS_AND_FN,
  _SIDE_SCROLL,
  _ZOOM,
};

enum CustomKeycodes {
  SCRL_MO_HOR = SAFE_RANGE,
  SCRL_MO_ZOOM,
};

// alias
#define LCS(kc) LCTL(LSFT(kc))
#define KC_D_QUOTE KC_DQUO
#define KC_L_BRACKET KC_LEFT_BRACKET
#define KC_R_BRACKET KC_RIGHT_BRACKET
#define KC_L_PAREN KC_LEFT_PAREN
#define KC_R_PAREN KC_RIGHT_PAREN

// shortcut
#define PR_SCR LCS(KC_S)
#define COPY LCTL(KC_C)
#define PASTE LCTL(KC_V)
#define CUT LCTL(KC_X)
#define ZOOM_OUT LCTL(KC_KP_MINUS)
#define ZOOM_IN LCTL(KC_KP_PLUS)
#define FULL_SCR LWIN(KC_UP)
#define NEXT_WIN SWIN(KC_RIGHT)
#define PREV_WIN SWIN(KC_LEFT)
#define HOME LCTL(KC_LEFT)
#define END LCTL(KC_RIGHT)

// hold and tap
#define ALT_OR_EN LALT_T(KC_LNG2)
#define SFT_OR_ESC RSFT_T(KC_ESC)
#define CTL_OR_ENTER LCTL_T(KC_ENTER)

// MO
#define TO_NUMBERS MO(_NUMBERS_AND_INPUT)
#define TO_AROOWS MO(_ARROWS_AND_FN)

// LT
#define SYM_OR_SPACE LT(_SYMBOLS,KC_SPACE)
#define FN_OR_J LT(_ARROWS_AND_FN,KC_J)
#define NUMBERS_OR_D LT(_NUMBERS_AND_INPUT,KC_D)
#define SCROLL_OR_K LT(_SYMBOLS,KC_K)
#define S_SCRL_OR_I LT(_SIDE_SCROLL,KC_I)
#define ZOOM_OR_O LT(_ZOOM,KC_O)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // space wide is 15 charactor between comma and comma
  [_QWERTY] = LAYOUT_universal(
    KC_Q          , KC_W          , KC_E          , KC_R          , KC_T          ,                  KC_Y          , KC_U          , S_SCRL_OR_I   , ZOOM_OR_O     , KC_P          ,
    LCTL_T(KC_A)  , KC_S          , NUMBERS_OR_D  , KC_F          , KC_G          ,                  KC_H          , FN_OR_J       , SCROLL_OR_K   , KC_L          , CTL_OR_ENTER  ,
    KC_Z          , KC_X          , KC_C          , KC_V          , KC_B          ,                  KC_N          , KC_M          , KC_COMMA      , KC_DOT        , KC_MINUS      ,
    SFT_OR_ESC    , KC_BTN2       , KC_BTN1       , ALT_OR_EN     , TO_NUMBERS    , SYM_OR_SPACE  ,  KC_SPACE      , TO_AROOWS     , XXXXXXX       , XXXXXXX       , XXXXXXX       , RSFT_T(KC_LNG1)
  ),

  [_NUMBERS_AND_INPUT] = LAYOUT_universal(
    XXXXXXX       , KC_1          , KC_2          , KC_3          , XXXXXXX       ,                  XXXXXXX       , KC_DELETE     , CUT           , FULL_SCR      , PASTE         ,
    LCTL_T(KC_0)  , KC_4          , KC_5          , KC_6          , XXXXXXX       ,                  XXXXXXX       , KC_BACKSPACE  , COPY          , KC_F7         , XXXXXXX       ,
    XXXXXXX       , KC_7          , KC_8          , KC_9          , XXXXXXX       ,                  PREV_WIN      , NEXT_WIN      , XXXXXXX       , XXXXXXX       , KC_TAB        ,
    _______       , XXXXXXX       , XXXXXXX       , _______       , _______       , _______       ,  _______       , _______       , XXXXXXX       , XXXXXXX       , XXXXXXX       , _______
  ),

  [_SYMBOLS] = LAYOUT_universal(
    KC_DOLLAR     , KC_PERCENT    , KC_HASH       , KC_AMPERSAND  , KC_ASTERISK   ,                  KC_UNDS       , KC_L_PAREN    , KC_R_PAREN    , KC_EQUAL      , KC_PLUS       ,
    KC_EXCLAIM    , KC_LCBR       , KC_RCBR       , KC_GRAVE      , KC_SEMICOLON  ,                  KC_MINUS      , KC_L_BRACKET  , KC_R_BRACKET  , KC_D_QUOTE    , KC_QUOTE      ,
    KC_CIRC       , KC_TILDE      , KC_AT         , XXXXXXX       , XXXXXXX       ,                  KC_COLON      , KC_PIPE       , KC_BACKSLASH  , KC_SLASH      , KC_QUESTION   ,
    _______       , XXXXXXX       , XXXXXXX       , _______       , _______       , _______       ,  _______       , _______       , XXXXXXX       , XXXXXXX       , XXXXXXX       , _______
  ),

  [_ARROWS_AND_FN] = LAYOUT_universal(
    XXXXXXX       , KC_F1         , KC_F2         , KC_F3         , KC_F11        ,                  XXXXXXX       , KC_PAGE_UP    , KC_UP         , KC_PAGE_DOWN  , PR_SCR        ,
    KC_LEFT_CTRL  , KC_F4         , KC_F5         , KC_F6         , KC_F10        ,                  HOME          , KC_LEFT       , KC_DOWN       , KC_RIGHT      , END           ,
    XXXXXXX       , KC_F7         , KC_F8         , KC_F9         , KC_F12        ,                  ZOOM_OUT      , ZOOM_IN       , XXXXXXX       , XXXXXXX       , XXXXXXX       ,
    _______       , KC_BTN5       , KC_BTN4       , _______       , _______       , _______       ,  _______       , _______       , XXXXXXX       , XXXXXXX       , XXXXXXX       , _______
  ),

  [_SIDE_SCROLL] = LAYOUT_universal(
    XXXXXXX       , XXXXXXX       , XXXXXXX       , XXXXXXX       , XXXXXXX       ,                  XXXXXXX       , XXXXXXX       , XXXXXXX       , XXXXXXX       , XXXXXXX       ,
    XXXXXXX       , XXXXXXX       , XXXXXXX       , XXXXXXX       , XXXXXXX       ,                  XXXXXXX       , XXXXXXX       , XXXXXXX       , XXXXXXX       , XXXXXXX       ,
    XXXXXXX       , XXXXXXX       , XXXXXXX       , XXXXXXX       , XXXXXXX       ,                  XXXXXXX       , XXXXXXX       , XXXXXXX       , XXXXXXX       , XXXXXXX       ,
    _______       , XXXXXXX       , XXXXXXX       , XXXXXXX       , XXXXXXX       , XXXXXXX       ,  XXXXXXX       , XXXXXXX       , XXXXXXX       , XXXXXXX       , XXXXXXX       , _______
  ),

  [_ZOOM] = LAYOUT_universal(
    XXXXXXX       , XXXXXXX       , XXXXXXX       , XXXXXXX       , XXXXXXX       ,                  XXXXXXX       , XXXXXXX       , XXXXXXX       , XXXXXXX       , XXXXXXX       ,
    XXXXXXX       , XXXXXXX       , XXXXXXX       , XXXXXXX       , XXXXXXX       ,                  XXXXXXX       , XXXXXXX       , XXXXXXX       , XXXXXXX       , XXXXXXX       ,
    XXXXXXX       , XXXXXXX       , XXXXXXX       , XXXXXXX       , XXXXXXX       ,                  XXXXXXX       , XXXXXXX       , XXXXXXX       , XXXXXXX       , XXXXXXX       ,
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

layer_state_t layer_state_set_user(layer_state_t state) {
    // reset
    unregister_code(KC_LEFT_SHIFT);
    unregister_code(KC_LEFT_CTRL);
    keyball_set_scroll_mode(false);

    // set scroll mode
    uint8_t current_layer = get_highest_layer(state);
    switch (current_layer) {
        case _SYMBOLS:
          // scroll
          keyball_set_scroll_mode(true);
          break;
        case _SIDE_SCROLL:
          // side scroll
          register_code(KC_LEFT_SHIFT);
          keyball_set_scroll_mode(true);
          break;
        case _ZOOM:
          // zoom
          register_code(KC_LEFT_CTRL);
          keyball_set_scroll_mode(true);
          break;
    }
    return state;
}

#ifdef OLED_ENABLE

#    include "lib/oledkit/oledkit.h"
bool is_init = true;

void oledkit_render_info_user(void) {
    // FIXME use pointing_device_init_user
    if (is_init) {
      // set_auto_mouse_enable(true);
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

#ifdef POINTING_DEVICE_AUTO_MOUSE_ENABLE
bool is_mouse_record_user(uint16_t keycode, keyrecord_t* record) {
    switch (keycode) {
        case SCRL_MO_HOR:
        case SCRL_MO_ZOOM:
            return true;
    }
    return false;
}

void keyball_set_scroll_mode_with_modifier_key(bool enable_scroll_mode, uint16_t modifier_key) {
    if (enable_scroll_mode) {
      register_code(modifier_key);
    } else {
      unregister_code(modifier_key);
    }
    keyball_set_scroll_mode(enable_scroll_mode);
}

uint8_t mod_state;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    mod_state = get_mods();
    switch (keycode) {
      case SCRL_MO_HOR:
        keyball_set_scroll_mode_with_modifier_key(record->event.pressed, KC_LEFT_SHIFT);
        return false;
      case SCRL_MO_ZOOM:
        keyball_set_scroll_mode_with_modifier_key(record->event.pressed, KC_LEFT_CTRL);
        return false;
      case KC_F:
        // ref: https://docs.qmk.fm/feature_advanced_keycodes#checking-modifier-state
        {
          static bool click_registered;
          if(record->event.pressed) {
            if(mod_state & MOD_MASK_ALT){
              del_mods(MOD_MASK_ALT);
              register_code(KC_BTN1);
              click_registered = true;
              set_mods(mod_state);
              return false;
            }
          } else {
            if(click_registered) {
              unregister_code(KC_BTN1);
              click_registered = false;
              return false;
            }
          }
        }

        break;
    }

    return true;
}

#endif


#ifdef KEYBALL_REVERSE_SCROLL

void keyball_on_apply_motion_to_mouse_scroll_user(keyball_motion_t *m, report_mouse_t *r, bool is_left) {
    // reverse scroll
    os_variant_t os = detected_host_os();
    switch (os) {
      case OS_MACOS:
        r->h = -r->h;
        r->v = -r->v;
        break;
      default:
        // do nothing
        break;
    }
}

#endif

// FIXME use pointing_device_init_user
/* void pointing_device_init_user(void) { */
/*     // always required before the auto mouse feature will work */
/*     set_auto_mouse_enable(true); */
/* } */
