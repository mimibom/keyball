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
  [0] = LAYOUT_universal(
    KC_1     , KC_2     , KC_3     , KC_4     , KC_5     , KC_6     ,                                KC_7     , KC_8     , KC_9     , KC_0     , KC_MINS  , KC_EQL   ,
    KC_ESC   , KC_Q     , KC_W     , KC_E     , KC_R     , KC_T     ,                                KC_Y     , KC_U     , KC_I     , KC_O     , KC_P     , KC_LBRC  ,
    KC_TAB   , KC_A     , KC_S     , KC_D     , KC_F     , KC_G     ,                                KC_H     , KC_J     , KC_K     , KC_L     ,LT(2,KC_SCLN),KC_QUOT,
    KC_LSFT  , KC_Z     , KC_X     , KC_C     , KC_V     , KC_B     , KC_RBRC ,            KC_NUHS , KC_N     , KC_M     , KC_COMM  , KC_DOT   , KC_SLSH  , KC_RSFT  ,
    _______  , KC_LCTL  , KC_LALT  , KC_LGUI  , MO(1)    ,LT(2,KC_SPC), LT(3,KC_ESC),      KC_BSPC ,LT(2,KC_ENT),LT(1,KC_LNG2),KC_RGUI,_______ , TT(1)    , SCRL_MO 
  ),

  [1] = LAYOUT_universal(
    _______  , _______  , _______  , _______  , _______  , _______  ,                                KC_NO    , KC_PSLS  , KC_PAST  , KC_PMNS  , _______  , KC_GRV   ,
    _______  , _______  , KC_UP    , _______  , _______  , _______  ,                                KC_P7    , KC_P8    , KC_P9    , KC_PPLS  , _______  , _______  ,
    _______  , KC_LEFT  , KC_DOWN  , KC_RGHT  , _______  , _______  ,                                KC_P4    , KC_P5    , KC_P6    , KC_PPLS  , _______  , _______  ,
    _______  , _______  , _______  , _______  , _______  , _______  , _______ ,            _______ , KC_P1    , KC_P2    , KC_P3    , KC_PEQL  , _______  , _______  ,
    _______  ,S(KC_LCTL),S(KC_LALT),S(KC_LGUI), _______  , _______  , _______ ,            KC_PDOT , KC_P0    , _______  ,S(KC_RGUI), _______  , _______  , _______
  ),

  [2] = LAYOUT_universal(
    KC_F1    , KC_F2    , KC_F3    , KC_F4    , KC_F5    , KC_F6    ,                                KC_F7    , KC_F8    , KC_F9    , KC_F10   , KC_F11   , KC_F12   ,
    KBC_SAVE , CPI_I100 , SCRL_DVI , KC_NO    , KC_NO    , KC_NO    ,                                KC_NO    , KC_BTN3  , KC_NO    , KC_BTN4  , KC_NO    , _______  ,
    KC_NO    , CPI_D100 , SCRL_DVD , KC_NO    , KC_NO    , KC_NO    ,                                KC_PGUP  , KC_BTN1  , KC_NO    , KC_BTN2  , KC_NO    , _______  ,
    KC_NO    , KC_NO    , KC_NO    , KC_NO    , KC_NO    , KC_NO    , KC_NO    ,           KC_NO   , KC_PGDN  , KC_NO    , KC_NO    , KC_NO    , KC_NO    , _______  ,
    _______  , _______  , _______  , _______  , _______  , _______  , _______  ,           KC_DEL  , _______  , _______  , _______  , _______  , _______  , _______
  ),

  [3] = LAYOUT_universal(
    RGB_TOG  , KC_NO    , KC_NO    , KC_NO    , KC_NO    , KC_NO    ,                                KC_NO    , KC_NO    , KC_NO    , KC_NO    , KC_NO    , KC_NO    ,
    KBC_SAVE , RGB_HUI  , RGB_SAI  , RGB_VAI  , KC_NO    , KC_NO    ,                                KC_NO    , KC_NO    , KC_NO    , KC_NO    , KC_NO    , _______  ,
    KC_NO    , RGB_HUD  , RGB_SAD  , RGB_VAD  , KC_NO    , KC_NO    ,                                KC_LEFT  , KC_DOWN  , KC_UP    , KC_RGHT  , KC_NO    , _______  ,
    KC_NO    , KC_NO    , KC_NO    , KC_NO    , KC_NO    , KC_NO    , EE_CLR  ,            EE_CLR  , KC_NO    , KC_NO    , KC_NO    , KC_NO    , KC_NO    , _______  ,
    QK_BOOT  , _______  , _______  , _______  , _______  , _______  , _______  ,            _______  , _______  , _______  , _______  , _______  , _______  , QK_BOOT
  )
};
// clang-format on

layer_state_t layer_state_set_user(layer_state_t state) {
    // Auto enable scroll mode when the highest layer is 3
    keyball_set_scroll_mode(get_highest_layer(state) == 3);
    uint8_t layer = biton32(state);
    switch (layer) {
        case 0:
            rgblight_sethsv(HSV_OFF);
            break;
        case 1:
            rgblight_sethsv(HSV_CHARTREUSE);
            break;
        case 2:
            rgblight_sethsv(HSV_ORANGE);
            break;
        case 3:
            rgblight_sethsv(HSV_PURPLE);
            break;
    }
    return state;
}

//layer_state_t layer_state_set_user(layer_state_t state) {
//
//    // Auto enable scroll mode on layer 2
//    keyball_set_scroll_mode(get_highest_layer(state) == 3);
//
//    // LOWER + RAISE = ADJUST のようなTri Layersを使う場合
//    // これを先に書いておかないと3の色がおかしくなる
//    state = update_tri_layer_state(state, 1, 2, 3);
//
//    uint8_t layer = biton32(state);
//    switch (layer) {
//        case 0:
//            rgblight_sethsv(HSV_RED);
//            break;
//        case 1:
//            rgblight_sethsv(HSV_BLUE);
//            break;
//        case 2:
//            rgblight_sethsv(HSV_GREEN);
//            break;
//        case 3:
//            rgblight_sethsv(HSV_WHITE);
//            break;
//    }
//    return state;
//}

#ifdef OLED_ENABLE

#    include "lib/oledkit/oledkit.h"

void oledkit_render_info_user(void) {
    keyball_oled_render_keyinfo();
    keyball_oled_render_ballinfo();
    keyball_oled_render_layerinfo();
}
#endif
