/*
Codeazerty config by papey

Base on the work of Olivier Pons, distributed under GPL
for more informations go check https://www.olivierpons.fr/infinity-ergodox/1-qmk-firmware-clavier-azerty-update
*/

// Includes
#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
// French ftw
#include "keymap_french.h"

// Layers
#define L_0 0 // base
#define L_1 1 // code chars | moves
#define L_2 2 // accents    | keypad layer
#define L_3 3 // media
#define L_4 4 // gaming

// Keys
#define CAP_CTL CTL_T(KC_CAPS) // Caps on tap, Ctrl on hold.
#define C_COPY   LCTL(KC_C) // Copy
#define C_CUT    LCTL(KC_X) // Cut
#define C_PASTE  LCTL(KC_V) // Paste
#define IPT 0x00B7 // ·
#define OE  0x0153 // œ
#define TM  0x2122 // ™
#define HRT 0x2665 // ♥
#define TLD 10 // ~ Tilde
#define NE  11 // !=
#define EE  13 // ==
#define NV  14 // :=
#define EP  15 // |>
#define EEE 16 // ===
#define C_A 20 // â
#define C_E 21 // ê
#define C_I 22 // î
#define C_O 23 // ô
#define C_U 24 // û

// Keymapping, simplified
#define ERGODOX_KEYMAP( \
  L01,L02,L03,L04,L05,L06,L07,    R01,R02,R03,R04,R05,R06,R07, \
  L08,L09,L10,L11,L12,L13,L14,    R08,R09,R10,R11,R12,R13,R14, \
  L15,L16,L17,L18,L19,L20,            R15,R16,R17,R18,R19,R20, \
  L21,L22,L23,L24,L25,L26,L27,    R21,R22,R23,R24,R25,R26,R27, \
  L28,L29,L30,L31,L32,                    R28,R29,R30,R31,R32, \
                       L33,L34,   R33,R34, \
                           L35,   R35, \
                   L36,L37,L38,   R36,R37,R38 \
  ) \
  LAYOUT_ergodox( \
      (L01),(L02),(L03),(L04),(L05),(L06),(L07),(L08),(L09),(L10),(L11) , \
      (L12),(L13),(L14),(L15),(L16),(L17),(L18),(L19),(L20),(L21),(L22) , \
      (L23),(L24),(L25),(L26),(L27),(L28),(L29),(L30),(L31),(L32),(L33) , \
      (L34),(L35),(L36),(L37),(L38),(R01),(R02),(R03),(R04),(R05),(R06) , \
      (R07),(R08),(R09),(R10),(R11),(R12),(R13),(R14),(R15),(R16),(R17) , \
      (R18),(R19),(R20),(R21),(R22),(R23),(R24),(R25),(R26),(R27),(R28) , \
      (R29),(R30),(R31),(R32),(R33),(R34),(R35),(R36),(R37),(R38) \
  )

// Layers
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[L_0] = ERGODOX_KEYMAP( // Layer 0, AZERTY (default)
  /* ┏━━━━━━━━━┯━━━━━━━┯━━━━━━━┯━━━━━━━┯━━━━━━━┯━━━━━━━┯━━━━━━━━┓   ┏━━━━━━━━┯━━━━━━━┯━━━━━━━┯━━━━━━━┯━━━━━━━┯━━━━━━━┯━━━━━━━━━┓ */
  /* ┃ Caps    │ & 1   │ é 2   │ " 3   │ ' 4   │ ( 5   │ ~L3    ┃   ┃ ->L4   │ - 6   │ è 7   │ _ 8   │ ç 9   │ à 0   │ ^ ¨     ┃ */
       KC_CAPS , KC_1  , KC_2  , KC_3  , KC_4  , KC_5  , MO(L_3),     TO(L_4), KC_6  , KC_7  , KC_8  , KC_9  , KC_0  , KC_LBRC ,
  /* ┠─────────┼───────┼───────┼───────┼───────┼───────┼────────┨   ┠────────┼───────┼───────┼───────┼───────┼───────┼─────────┨ */
  /* ┃ Tab     │ a A   │ z Z   │ e E   │ r R   │ t T   │ Bkspc  ┃   ┃ +      │ y Y   │ u U   │ i I   │ o O   │ p P   │ $       ┃ */
       KC_TAB  , FR_A  , FR_Z  , FR_E  , FR_R  , FR_T  , KC_BSPC,     FR_PLUS, FR_Y  , FR_U  , FR_I  , FR_O  , FR_P  , FR_DLR  ,
  /* ┠─────────┼───────┼───────┼───────┼───────┼───────┤────────┃   ┠────────┼───────┼───────┼───────┼───────┼───────┼─────────┨ */
  /* ┃ Esc     │ q Q   │ s S   │ d D   │ f F   │ g G   │        ┃   ┃        │ h H   │ j J   │ k K   │ l L   │ m M   │ Enter   ┃ */
       KC_ESC  , FR_Q  , FR_S  , FR_D  , FR_F  , FR_G  ,                       FR_H  , FR_J  , FR_K  , FR_L  , FR_M  , KC_ENT  ,
  /* ┠─────────┼───────┼───────┼───────┼───────┼───────┤ Del    ┃   ┃ -      ├───────┼───────┼───────┼───────┼───────┼─────────┨ */
  /* ┃ LShft   │ w W   │ x X   │ c C   │ v V   │ b B   │        ┃   ┃        │ n N   │  , ?  │  ; .  │  : /  │  ! §  │ RShft   ┃ */
       KC_LSFT , FR_W  , FR_X  , FR_C  , FR_V  , FR_B  , KC_DEL ,     FR_MINS, FR_N  ,FR_COMM,FR_SCLN,FR_COLN,FR_EXLM, KC_RSFT ,
  /* ┗━━━┱─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┲━━━━━┷━━━━━━━━┛   ┗━━━━━━━━┷━━━━━┱─┴─────┬─┴─────┬─┴─────┬─┴─────┬─┴─────┲━━━┛ */
  /*     ┃ `     │ *     │ LGui  │ LCtl  │ LAlt  ┃                                 ┃ Spc   │ RGui  │ RAlt  │ ·     │ RCtl  ┃     */
           FR_GRV,KC_PAST,KC_LGUI,KC_LCTL,KC_LALT,                                   KC_SPC,KC_RGUI,KC_RALT,UC(IPT),KC_RCTL,
  /*     ┗━━━━━━━┷━━━━━━━┷━━━━━━━┷━━━━━━━┷━━━━━━━┛                                 ┗━━━━━━━┷━━━━━━━┷━━━━━━━┷━━━━━━━┷━━━━━━━┛     */
  /*                                            ┏━━━━━━━┯━━━━━━━┓   ┏━━━━━━━┯━━━━━━━                                            */
  /*                                            ┃ Copy  │ Cut   ┃   ┃ @     │ |     ┃                                            */
                                                  C_COPY, C_CUT ,     FR_AT ,FR_PIPE,
  /*                                    ┏━━━━━━━╃───────┼───────┨   ┠───────┼───────╄━━━━━━━┓                                    */
  /*                                    ┃       │       │ Paste ┃   ┃ %     │       │       ┃                                    */
                                                         C_PASTE,    FR_PERC,
  /*                                    ┃ ~L1   │ ~L2   ├───────┨   ┠───────┤ ~L2   │ ~L1   ┃                                    */
  /*                                    ┃       │       │ PgUp  ┃   ┃ PgDn  │       │       ┃                                    */
                                         MO(L_1),MO(L_2),KC_PGUP ,   KC_PGDN,MO(L_2),MO(L_1)
  /*                                    ┗━━━━━━━┷━━━━━━━┷━━━━━━━┛   ┗━━━━━━━┷━━━━━━━┷━━━━━━━┛                                    */
  ),

[L_1] = ERGODOX_KEYMAP( // Layer 1, code chars | moves
  /* Left hand = code chars                                         Right hand = moves                                           */
  /* ┏━━━━━━━━━┯━━━━━━━┯━━━━━━━┯━━━━━━━┯━━━━━━━┯━━━━━━━┯━━━━━━━━┓   ┏━━━━━━━━┯━━━━━━━┯━━━━━━━┯━━━━━━━┯━━━━━━━┯━━━━━━━┯━━━━━━━━━┓ */
  /* ┃ Caps    │ f1    │ f2    │ f3    │ f4    │ f5    │ f6     ┃   ┃ f7     │ f8    │ f9    │ f10   │ f11   │ f12   │ ^ ¨     ┃ */
       KC_TRNS , KC_F1 , KC_F2 , KC_F3 , KC_F4 , KC_F5 , KC_F6  ,     KC_F7  , KC_F8 , KC_F9 , KC_F10, KC_F11, KC_F12, KC_TRNS ,
  /* ┠─────────┼───────┼───────┼───────┼───────┼───────┼────────┨   ┠────────┼───────┼───────┼───────┼───────┼───────┼─────────┨ */
  /* ┃ _       │ \     │ ==    │ :=    │ {     │ }     │ ~      ┃   ┃ !=     │ Begin  │ End  │ WH UP │ WH DW │ p P   │ $       ┃ */
       KC_TRNS ,FR_BSLS, M(EE), M(NV) ,FR_LCBR,FR_RCBR, M(TLD) ,     M(NE)  ,KC_HOME, KC_END,KC_WH_U,KC_WH_D,KC_TRNS, KC_TRNS ,
  /* ┠─────────┼───────┼───────┼───────┼───────┼───────┤        ┃   ┠────────┼───────┼───────┼───────┼───────┼───────┼─────────┨ */
  /* ┃ Esc     │ =     │ !     │ /     │ (     │ )     ├────────┨   ┃        │ ←     │ ↓     │ ↑     │ →     │ m M   │ Enter   ┃ */
       KC_TRNS , KC_EQL,FR_EXLM,FR_SLSH,FR_LPRN,FR_RPRN,                      KC_LEFT,KC_DOWN, KC_UP ,KC_RGHT,KC_TRNS, KC_ENT  ,
  /* ┠─────────┼───────┼───────┼───────┼───────┼───────┤ ;      ┃   ┃ ===    ├───────┼───────┼───────┼───────┼───────┼─────────┨ */
  /* ┃ _       │ <     │ #     │ >     │ [     │ ]     │        ┃   ┃        │ n N   │ Copy  │ Cut   │ Paste │ ! §   │ RShft   ┃ */
       KC_TRNS ,KC_NUBS,FR_HASH,FR_RABK,FR_LBRC,FR_RBRC, FR_SCLN,     M(EEE)  ,KC_TRNS, C_COPY, C_CUT ,C_PASTE,KC_TRNS, KC_TRNS ,
  /* ┗━━━┱─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┲━━━━━┷━━━━━━━━┛   ┗━━━━━━━━┷━━━━━┱─┴─────┬─┴─────┬─┴─────┬─┴─────┬─┴─────┲━━━┛ */
  /*     ┃ `     │ *     │ LGui  │ LCtl  │ |>    ┃                                 ┃ Spc   │ RGui  │ RAlt  │ ·     │ RCtl  ┃     */
          KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS, M(EP) ,                                  KC_TRNS, FR_DOT,KC_TRNS,KC_TRNS,KC_TRNS,
  /*     ┗━━━━━━━┷━━━━━━━┷━━━━━━━┷━━━━━━━┷━━━━━━━┛                                 ┗━━━━━━━┷━━━━━━━┷━━━━━━━┷━━━━━━━┷━━━━━━━┛     */
  /*                                            ┏━━━━━━━┯━━━━━━━┓   ┏━━━━━━━┯━━━━━━━┓                                            */
  /*                                            ┃ Copy  │ Cut   ┃   ┃ @     │ |     ┃                                            */
                                                  C_COPY, C_CUT ,    KC_TRNS,KC_TRNS,
  /*                                    ┏━━━━━━━╃───────┼───────┨   ┠───────┼───────╄━━━━━━━┓                                    */
  /*                                    ┃       │       │ Paste ┃   ┃ %     │       │       ┃                                    */
                                                         C_PASTE,    KC_TRNS,
  /*                                    ┃  ~L1  │  ~L2  ├───────┨   ┠───────┤ ~L2   │ ~L1   ┃                                    */
  /*                                    ┃       │       │ PgUp  ┃   ┃ PgDn  │       │       ┃                                    */
                                         KC_TRNS,KC_TRNS,KC_TRNS,    KC_TRNS,KC_TRNS,KC_TRNS
  /*                                    ┗━━━━━━━┷━━━━━━━┷━━━━━━━┛   ┗━━━━━━━┷━━━━━━━┷━━━━━━━┛                                    */
  ),

[L_2] = ERGODOX_KEYMAP( // Layer 2, accents, symbols | numpad
  /* Left hand = accents, symbols                                   Right hand = numpad                                          */
  /* ┏━━━━━━━━━┯━━━━━━━┯━━━━━━━┯━━━━━━━┯━━━━━━━┯━━━━━━━┯━━━━━━━━┓   ┏━━━━━━━━┯━━━━━━━┯━━━━━━━┯━━━━━━━┯━━━━━━━┯━━━━━━━┯━━━━━━━━━┓ */
  /* ┃ -       │ -     │ -     │ -     │ -     │ -     │ -      ┃   ┃ CAPS   │ -     │ NLCK  │ /     │ *     │ -     │ -       ┃ */
       KC_TRNS ,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS, KC_TRNS,    KC_CAPS ,KC_TRNS,KC_NLCK,KC_PSLS,KC_PAST,KC_TRNS, KC_TRNS ,
  /* ┠─────────┼───────┼───────┼───────┼───────┼───────┼────────┨   ┠────────┼───────┼───────┼───────┼───────┼───────┼─────────┨ */
  /* ┃ -       │ é     │ è     │ -     │ û     │ ù     │ -      ┃   ┃ -      │ =     │ 7     │ 8     │ 9     │ -     │ -       ┃ */
       KC_TRNS ,FR_EACU,FR_EGRV,KC_TRNS,M(C_U) ,KC_QUOT, KC_TRNS,     KC_TRNS, FR_EQL, FR_7  , FR_8  , FR_9  ,KC_TRNS, KC_TRNS ,
  /* ┠─────────┼───────┼───────┼───────┼───────┼───────┤        ┃   ┠────────┼───────┼───────┼───────┼───────┼───────┼─────────┨ */
  /* ┃ -       │ œ     │ ™     │ ♥     │ €     │ ù     ├────────┨   ┃        │ -     │ 4     │ 5     │ 6     │ -     │ -       ┃ */
       KC_TRNS , UC(OE), UC(TM),UC(HRT),FR_EURO,KC_QUOT,                      KC_TRNS, FR_4  , FR_5  , FR_6  ,KC_TRNS, KC_TRNS ,
  /* ┠─────────┼───────┼───────┼───────┼───────┼───────┤ -      ┃   ┃ -      ├───────┼───────┼───────┼───────┼───────┼─────────┨ */
  /* ┃ -       │ â     │ ê     │ î     │ ô     │ -     │        ┃   ┃        │ 0     │ 1     │ 2     │ 3     │ -     │ -       ┃ */
       KC_TRNS , M(C_A), M(C_E), M(C_I), M(C_O),KC_TRNS, KC_TRNS,     KC_TRNS, FR_0  , FR_1 ,  FR_2 ,  FR_3  ,KC_TRNS, KC_TRNS ,
  /* ┗━━━┱─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┲━━━━━┷━━━━━━━━┛   ┗━━━━━━━━┷━━━━━┱─┴─────┬─┴─────┬─┴─────┬─┴─────┬─┴─────┲━━━┛ */
  /*     ┃ -     │ -     │ -     │ -     │ -     ┃                                 ┃ -     │ -     │ -     │ -     │ -     ┃     */
          KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,                                  KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
  /*     ┗━━━━━━━┷━━━━━━━┷━━━━━━━┷━━━━━━━┷━━━━━━━┛                                 ┗━━━━━━━┷━━━━━━━┷━━━━━━━┷━━━━━━━┷━━━━━━━┛     */
  /*                                            ┏━━━━━━━┯━━━━━━━┓   ┏━━━━━━━┯━━━━━━━┓                                            */
  /*                                            ┃ Copy  │ Cut   ┃   ┃ -     │ -     ┃                                            */
                                                  C_COPY, C_CUT ,    KC_TRNS,KC_TRNS,
  /*                                    ┏━━━━━━━╃───────┼───────┨   ┠───────┼───────╄━━━━━━━┓                                    */
  /*                                    ┃       │       │ Paste ┃   ┃ -     │       │       ┃                                    */
                                                         C_PASTE,    KC_TRNS,
  /*                                    ┃ ~L1   │ ~L2   ├───────┨   ┠───────┤ ~L2   │ ~L1   ┃                                    */
  /*                                    ┃       │       │ -     ┃   ┃ -     │       │       ┃                                    */
                                         KC_TRNS,KC_TRNS,KC_TRNS,    KC_TRNS,KC_TRNS,KC_TRNS
  /*                                    ┗━━━━━━━┷━━━━━━━┷━━━━━━━┛   ┗━━━━━━━┷━━━━━━━┷━━━━━━━┛                                    */
  ),
[L_3] = ERGODOX_KEYMAP( // Layer 3, media keys
  /*  Right hand is used for media keys */
  /* ┏━━━━━━━━━┯━━━━━━━┯━━━━━━━┯━━━━━━━┯━━━━━━━┯━━━━━━━┯━━━━━━━━┓   ┏━━━━━━━━┯━━━━━━━┯━━━━━━━┯━━━━━━━┯━━━━━━━┯━━━━━━━┯━━━━━━━━━┓ */
  /* ┃ -       │ -     │ -     │ -     │ -     │ -     │ ~L3    ┃   ┃ -      │ -     │ -     │ -     │ -     │ -     │ -       ┃ */
       KC_TRNS ,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS, MO(L_3),     KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS, KC_TRNS ,
  /* ┠─────────┼───────┼───────┼───────┼───────┼───────┼────────┨   ┠────────┼───────┼───────┼───────┼───────┼───────┼─────────┨ */
  /* ┃ -       │ -     │ -     │ -     │ -     │ -     │ -      ┃   ┃ Vol Up │ Mute  │ Prev  │ Mply  │ Next  │ Bri U │ -       ┃ */
       KC_TRNS ,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS ,     KC_VOLU,KC_MUTE,KC_MPRV,KC_MPLY,KC_MNXT,KC_BRIU, KC_TRNS ,
  /* ┠─────────┼───────┼───────┼───────┼───────┼───────┤        ┃   ┠────────┼───────┼───────┼───────┼───────┼───────┼─────────┨ */
  /* ┃ -       │ -     │ -     │ -     │ -     │ -     ├────────┨   ┃        │ -     │ -     │ -     │ -     │ Bri   │ -       ┃ */
       KC_TRNS ,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,                      KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_BRID,KC_TRNS,
  /* ┠─────────┼───────┼───────┼───────┼───────┼───────┤ -      ┃   ┃ Vol Dn ├───────┼───────┼───────┼───────┼───────┼─────────┨ */
  /* ┃ -       │ -     │ -     │ -     │ -     │ -     │        ┃   ┃        │ -     │ -     │ -     │ -     │ -     │ -       ┃ */
       KC_TRNS ,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS ,     KC_VOLD,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS, KC_TRNS ,
  /* ┗━━━┱─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┲━━━━━┷━━━━━━━━┛   ┗━━━━━━━━┷━━━━━┱─┴─────┬─┴─────┬─┴─────┬─┴─────┬─┴─────┲━━━┛ */
  /*     ┃ -     │ -     │ -     │ -     │ -     ┃                                 ┃ -     │ -     │ -     │ -     │ -     ┃     */
          KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,                                  KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
  /*     ┗━━━━━━━┷━━━━━━━┷━━━━━━━┷━━━━━━━┷━━━━━━━┛                                 ┗━━━━━━━┷━━━━━━━┷━━━━━━━┷━━━━━━━┷━━━━━━━┛     */
  /*                                            ┏━━━━━━━┯━━━━━━━┓   ┏━━━━━━━┯━━━━━━━┓                                            */
  /*                                            ┃ Copy  │ Cut   ┃   ┃ -     │ -     ┃                                            */
                                                  C_COPY, C_CUT ,    KC_TRNS,KC_TRNS,
  /*                                    ┏━━━━━━━╃───────┼───────┨   ┠───────┼───────╄━━━━━━━┓                                    */
  /*                                    ┃       │       │ Paste ┃   ┃ -     │       │       ┃                                    */
                                                         C_PASTE,    KC_TRNS,
  /*                                    ┃  ~L1  │  ~L2  ├───────┨   ┠───────┤ ~L2   │ ~L1   ┃                                    */
  /*                                    ┃       │       │ -     ┃   ┃ -     │       │       ┃                                    */
                                         KC_TRNS,KC_TRNS,KC_TRNS,    KC_TRNS,KC_TRNS,KC_TRNS
  /*                                    ┗━━━━━━━┷━━━━━━━┷━━━━━━━┛   ┗━━━━━━━┷━━━━━━━┷━━━━━━━┛                                    */
  ),
  [L_4] = ERGODOX_KEYMAP( // Layer 4, gaming
  /* Gaming, just remap Space key to previous alt */
  /* ┏━━━━━━━━━┯━━━━━━━┯━━━━━━━┯━━━━━━━┯━━━━━━━┯━━━━━━━┯━━━━━━━━┓   ┏━━━━━━━━┯━━━━━━━┯━━━━━━━┯━━━━━━━┯━━━━━━━┯━━━━━━━┯━━━━━━━━━┓ */
  /* ┃ -       │ -     │ -     │ -     │ -     │ -     │ ->L0   ┃   ┃ ->L0   │ -     │ -     │ -     │ -     │ -     │ -       ┃ */
       KC_TRNS ,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS, TO(L_0),     TO(L_0),KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS, KC_TRNS ,
  /* ┠─────────┼───────┼───────┼───────┼───────┼───────┼────────┨   ┠────────┼───────┼───────┼───────┼───────┼───────┼─────────┨ */
  /* ┃ -       │ -     │ -     │ -     │ -     │ -     │ -      ┃   ┃ -      │ -     │ -     │ -     │ -     │ -     │ -       ┃ */
       KC_TRNS ,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS, KC_TRNS,     KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS, KC_TRNS ,
  /* ┠─────────┼───────┼───────┼───────┼───────┼───────┤        ┃   ┠────────┼───────┼───────┼───────┼───────┼───────┼─────────┨ */
  /* ┃ -       │ -     │ -     │ -     │ -     │ -     ├────────┨   ┃        │ -     │ -     │ -     │ -     │ -     │ -       ┃ */
       KC_TRNS ,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,                      KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS, KC_TRNS ,
  /* ┠─────────┼───────┼───────┼───────┼───────┼───────┤ -      ┃   ┃ -      ├───────┼───────┼───────┼───────┼───────┼─────────┨ */
  /* ┃ -       │ -     │ -     │ -     │ -     │ -     │        ┃   ┃        │ -     │ -     │ -     │ -     │ -     │ -       ┃ */
       KC_TRNS ,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS ,     KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS, KC_TRNS ,
  /* ┗━━━┱─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┲━━━━━┷━━━━━━━━┛   ┗━━━━━━━━┷━━━━━┱─┴─────┬─┴─────┬─┴─────┬─┴─────┬─┴─────┲━━━┛ */
  /*     ┃ -     │ -     │ -     │ -     │ Space ┃                                 ┃ -     │ -     │ -     │ -     │ -     ┃     */
          KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS, KC_SPC,                                  KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
  /*     ┗━━━━━━━┷━━━━━━━┷━━━━━━━┷━━━━━━━┷━━━━━━━┛                                 ┗━━━━━━━┷━━━━━━━┷━━━━━━━┷━━━━━━━┷━━━━━━━┛     */
  /*                                            ┏━━━━━━━┯━━━━━━━┓   ┏━━━━━━━┯━━━━━━━┓                                            */
  /*                                            ┃ Copy  │ Cut   ┃   ┃ -     │ -     ┃                                            */
                                                  C_COPY, C_CUT ,    KC_TRNS,KC_TRNS,
  /*                                    ┏━━━━━━━╃───────┼───────┨   ┠───────┼───────╄━━━━━━━┓                                    */
  /*                                    ┃       │       │ Paste ┃   ┃ -     │       │       ┃                                    */
                                                         C_PASTE,    KC_TRNS,
  /*                                    ┃  ~L1  │  ~L2  ├───────┨   ┠───────┤ ~L2   │ ~L1   ┃                                    */
  /*                                    ┃       │       │ -     ┃   ┃ -     │       │       ┃                                    */
                                         KC_TRNS,KC_TRNS,KC_TRNS,    KC_TRNS,KC_TRNS,KC_TRNS
  /*                                    ┗━━━━━━━┷━━━━━━━┷━━━━━━━┛   ┗━━━━━━━┷━━━━━━━┷━━━━━━━┛                                    */
  ),

};

const uint16_t PROGMEM fn_actions[] = {
};

// Map macros to actions
const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
    // MACRODOWN only works in this function
    switch(id) {
        case TLD: // ~
            return MACRODOWN(D(RALT), T(2), U(RALT), END);
        case NE: // !=
            return MACRODOWN(T(SLSH), T(EQL), END);
        case EP: // |>, elixir pipe, ftw
            return MACRODOWN(D(ALGR), T(6), U(ALGR), D(LSFT), T(NUBS), U(LSFT), END);
        case NV: // :=
            return MACRODOWN(T(DOT), T(EQL), END);
        case EE: // ==
            return MACRODOWN(T(EQL), T(EQL), END);
        case EEE: // ===
            return MACRODOWN(T(EQL), T(EQL), T(EQL), END);
        case C_A: // â
            return MACRODOWN(T(LBRC), T(Q), END);
        case C_E: // ê
            return MACRODOWN(T(LBRC), T(E), END);
        case C_I: // î
            return MACRODOWN(T(LBRC), T(I), END);
        case C_O: // ô
            return MACRODOWN(T(LBRC), T(O), END);
        case C_U: // û
            return MACRODOWN(T(LBRC), T(U), END);
    };
    return MACRO_NONE;
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
     set_unicode_input_mode(UC_LNX);
};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    switch (layer) {
        case 1:
            ergodox_right_led_1_on();
            break;
        case 2:
            ergodox_right_led_2_on();
            break;
        default:
            // burp !
        break;
    }

};
