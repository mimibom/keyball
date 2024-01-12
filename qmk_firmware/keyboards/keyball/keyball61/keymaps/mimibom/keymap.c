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

enum layer_number {
	_QWERTY = 0,
	_NUMBER = 1,
	_MOUSE = 2,
	_CONFIG = 3,
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_universal(
    KC_1     , KC_2     , KC_3     , KC_4     , KC_5     , KC_6     ,                                  KC_7     , KC_8     , KC_9     , KC_0     , KC_MINS  , KC_EQL   ,
    KC_ESC   , KC_Q     , KC_W     , KC_E     , KC_R     , KC_T     ,                                  KC_Y     , KC_U     , KC_I     , KC_O     , KC_P     , KC_LBRC  ,
    KC_TAB   , KC_A     , KC_S     , KC_D     , KC_F     , KC_G     ,                                  KC_H     , KC_J     , KC_K     , KC_L     ,LT(2,KC_SCLN),KC_QUOT,
    KC_LSFT  , KC_Z     , KC_X     , KC_C     , KC_V     , KC_B     , KC_RBRC ,              KC_NUHS , KC_N     , KC_M     , KC_COMM  , KC_DOT   , KC_SLSH  , KC_RSFT  ,
    KC_LCTL  , KC_LALT  , KC_LGUI  , KC_MUTE  , MO(1)    ,LT(2,KC_SPC), LT(3,KC_ESC),        KC_BSPC ,LT(2,KC_ENT), KC_RGUI,  _______ ,  _______ , TG(1)    , SCRL_MO 
  ),
  [_NUMBER] = LAYOUT_universal(
    _______  , _______  , _______  , _______  , _______  , _______  ,                                  KC_NO    , KC_PSLS  , KC_PAST  , KC_PMNS  , _______  , KC_GRV   ,
    _______  , _______  , KC_UP    , _______  , _______  , _______  ,                                  KC_P7    , KC_P8    , KC_P9    , KC_PPLS  , _______  , _______  ,
    _______  , KC_LEFT  , KC_DOWN  , KC_RGHT  , _______  , _______  ,                                  KC_P4    , KC_P5    , KC_P6    , KC_PPLS  , _______  , _______  ,
    _______  , _______  , _______  , _______  , _______  , _______  , _______ ,              _______ , KC_P1    , KC_P2    , KC_P3    , KC_PEQL  , _______  , _______  ,
    _______  , _______  , _______  , _______  , _______  , _______  , _______ ,              KC_PDOT , KC_P0    , _______  , _______  , _______  , _______  , _______
  ),

  [_MOUSE] = LAYOUT_universal(
    KC_F1    , KC_F2    , KC_F3    , KC_F4    , KC_F5    , KC_F6    ,                                  KC_F7    , KC_F8    , KC_F9    , KC_F10   , KC_F11   , KC_F12   ,
    KBC_SAVE , CPI_I100 , SCRL_DVI , KC_NO    , KC_NO    , KC_NO    ,                                  KC_NO    , KC_BTN3  , KC_NO    , KC_BTN4  , KC_NO    , _______  ,
    KC_NO    , CPI_D100 , SCRL_DVD , KC_NO    , KC_NO    , KC_NO    ,                                  KC_PGUP  , KC_BTN1  , KC_NO    , KC_BTN2  , KC_NO    , _______  ,
    KC_NO    , KC_NO    , KC_NO    , KC_NO    , KC_NO    , KC_NO    , KC_NO    ,             KC_NO   , KC_PGDN  , KC_NO    , KC_NO    , KC_NO    , KC_NO    , _______  ,
    _______  , _______  , _______  , _______  , _______  , _______  , _______  ,             KC_DEL  , _______  , _______  , _______  , _______  , _______  , _______
  ),

  [_CONFIG] = LAYOUT_universal(
    RGB_TOG  , KC_NO    , KC_NO    , KC_NO    , KC_NO    , KC_NO    ,                                  KC_NO    , KC_NO    , KC_NO    , KC_NO    , KC_NO    , KC_NO    ,
    KBC_SAVE , RGB_HUI  , RGB_SAI  , RGB_VAI  , KC_NO    , KC_NO    ,                                  KC_NO    , KC_NO    , KC_NO    , KC_NO    , KC_NO    , KBC_SAVE ,
    KC_NO    , RGB_HUD  , RGB_SAD  , RGB_VAD  , KC_NO    , KC_NO    ,                                  KC_LEFT  , KC_DOWN  , KC_UP    , KC_RGHT  , KC_NO    , _______  ,
    KC_NO    , KC_NO    , KC_NO    , KC_NO    , KC_NO    , KC_NO    , EE_CLR  ,              EE_CLR  , KC_NO    , KC_NO    , KC_NO    , KC_NO    , KC_NO    , _______  ,
    QK_BOOT  , KC_VOLD  , KC_VOLU  , _______  , _______  , _______  , _______  ,            _______  , _______  , _______  , _______  , _______  , _______  , QK_BOOT
  )
};
// clang-format on

const rgblight_segment_t PROGMEM rgb_qwerty_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 3, HSV_RED}, // Left
    {37, 3, HSV_BLUE} // Right
);

const rgblight_segment_t PROGMEM rgb_number_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {1, 4, HSV_GREEN}, // Left
    {38, 4, HSV_GREEN} // Right
);

const rgblight_segment_t PROGMEM rgb_mouse_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {2, 5, HSV_PINK}, // Left
    {39, 5, HSV_PINK} // Right
);

const rgblight_segment_t PROGMEM rgb_config_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {3, 6, HSV_CORAL}, // Left
    {40, 6, HSV_CORAL} // Right
);

const rgblight_segment_t* const PROGMEM rgb_layers[] = RGBLIGHT_LAYERS_LIST(
	rgb_qwerty_layer,
	rgb_number_layer,
	rgb_mouse_layer,
	rgb_config_layer
);


layer_state_t layer_state_set_user(layer_state_t state) {
	rgblight_set_layer_state(0, layer_state_cmp(state, _QWERTY));
	rgblight_set_layer_state(1, layer_state_cmp(state, _NUMBER));
	rgblight_set_layer_state(2, layer_state_cmp(state, _MOUSE));
	rgblight_set_layer_state(3, layer_state_cmp(state, _CONFIG));
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
