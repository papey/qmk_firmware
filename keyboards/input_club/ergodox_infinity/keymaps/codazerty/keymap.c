/*
Codeazerty config by papey

Base on the work of Olivier Pons, distributed under GPL
for more informations go check https://www.olivierpons.fr/infinity-ergodox/1-qmk-firmware-clavier-azerty-update
*/

// Includes
#include QMK_KEYBOARD_H
#include "action_layer.h"
// French ftw
#include "keymap_french.h"
#include "sendstring_french.h"

// Layers
#define L_0 0                   // macOS
#define L_1 1                   // code    | moves
#define L_2 2                   // accents | numpad
#define L_3 3                   // media
#define L_4 4                   // !macOS
#define L_5 5                   // gaming

// Keys
// for * != macOS
#define C_COPY LCTL(KC_C)       // Copy
#define C_CUT LCTL(KC_X)        // Cut
#define C_PASTE LCTL(KC_V)      // Paste
// for macOS
#define M_COPY LGUI(KC_C)       // Copy
#define M_CUT LGUI(KC_X)        // Cut
#define M_PASTE LGUI(KC_V)      // Paste

// Unicode
#define IPT 0x0153 // ·
#define OE  0x0153 // œ
#define TM  0x2122 // ™
#define C_E 0x00EA // ê
#define C_U 0x00DB // û
#define HRT 0x2665 // ♥
#define CP  0x00A9 // ©
#define VI  0x270C // ✌️
#define NOE 0x26D4 // ⛔
#define VLD 0x2713 // ✓
#define DA  0x26A0 // ⚠
#define ILD 0x274C // ❌

// Keymapping, simplified
#define ERGODOX_KEYMAP(L01, L02, L03, L04, L05, L06, L07, R01, R02, R03, R04, R05, R06, R07, L08, L09, L10, L11, L12, L13, L14, R08, R09, R10, R11, R12, R13, R14, L15, L16, L17, L18, L19, L20, R15, R16, R17, R18, R19, R20, L21, L22, L23, L24, L25, L26, L27, R21, R22, R23, R24, R25, R26, R27, L28, L29, L30, L31, L32, R28, R29, R30, R31, R32, L33, L34, R33, R34, L35, R35, L36, L37, L38, R36, R37, R38) LAYOUT_ergodox((L01), (L02), (L03), (L04), (L05), (L06), (L07), (L08), (L09), (L10), (L11), (L12), (L13), (L14), (L15), (L16), (L17), (L18), (L19), (L20), (L21), (L22), (L23), (L24), (L25), (L26), (L27), (L28), (L29), (L30), (L31), (L32), (L33), (L34), (L35), (L36), (L37), (L38), (R01), (R02), (R03), (R04), (R05), (R06), (R07), (R08), (R09), (R10), (R11), (R12), (R13), (R14), (R15), (R16), (R17), (R18), (R19), (R20), (R21), (R22), (R23), (R24), (R25), (R26), (R27), (R28), (R29), (R30), (R31), (R32), (R33), (R34), (R35), (R36), (R37), (R38))

    // Macros
    enum custom_keycodes {
        EE = SAFE_RANGE,
        THX,
        TLD,
        NV,
        NE,
        EEE,
        EP,
        DEF,
        DO,
        END,
        BND,
    };


// Layers
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [L_0] = ERGODOX_KEYMAP(
	// Layer 0, AZERTY macOS (default)
        /* ┏━━━━━━━━━┯━━━━━━━┯━━━━━━━┯━━━━━━━┯━━━━━━━┯━━━━━━━┯━━━━━━━━┓   ┏━━━━━━━━┯━━━━━━━┯━━━━━━━┯━━━━━━━┯━━━━━━━┯━━━━━━━┯━━━━━━━━━┓ */
        /* ┃ ->L5    │ & 1   │ é 2   │ " 3   │ ' 4   │ ( 5   │ ~L3    ┃   ┃ ->L4   │ - 6   │ è 7   │ _ 8   │ ç 9   │ à 0   │ ^ ¨     ┃ */
            TO(L_5),  KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   MO(L_3),     TO(L_4), KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_LBRC,
        /* ┠─────────┼───────┼───────┼───────┼───────┼───────┼────────┨   ┠────────┼───────┼───────┼───────┼───────┼───────┼─────────┨ */
        /* ┃ Tab     │ a A   │ z Z   │ e E   │ r R   │ t T   │ Bkspc  ┃   ┃ +      │ y Y   │ u U   │ i I   │ o O   │ p P   │ $       ┃ */
            KC_TAB,   FR_A,   FR_Z,   FR_E,   FR_R,   FR_T,   KC_BSPC,     FR_PLUS, FR_Y,   FR_U,   FR_I,   FR_O,   FR_P,   FR_DLR,
        /* ┠─────────┼───────┼───────┼───────┼───────┼───────┤────────┃   ┠────────┼───────┼───────┼───────┼───────┼───────┼─────────┨ */
        /* ┃ Esc     │ q Q   │ s S   │ d D   │ f F   │ g G   │        ┃   ┃        │ h H   │ j J   │ k K   │ l L   │ m M   │ Enter   ┃ */
            KC_ESC,   FR_Q,   FR_S,   FR_D,   FR_F,   FR_G,                         FR_H,   FR_J,   FR_K,   FR_L,   FR_M,   KC_ENT,
        /* ┠─────────┼───────┼───────┼───────┼───────┼───────┤ Del    ┃   ┃ -      ├───────┼───────┼───────┼───────┼───────┼─────────┨ */
        /* ┃ LShft   │ w W   │ x X   │ c C   │ v V   │ b B   │        ┃   ┃        │ n N   │  , ?  │  ; .  │  : /  │  ! §  │ RShft   ┃ */
            KC_LSFT,  FR_W,   FR_X,   FR_C,   FR_V,   FR_B,   KC_DEL,      FR_MINS, FR_N,   FR_COMM,FR_SCLN,FR_COLN,FR_EXLM,KC_RSFT,
        /* ┗━━━┱─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┲━━━━━┷━━━━━━━━┛   ┗━━━━━━━━┷━━━━━┱─┴─────┬─┴─────┬─┴─────┬─┴─────┬─┴─────┲━━━┛ */
        /*     ┃ `     │ *     │ LCtl  │ LAlt  │ LGui  ┃                                 ┃ RGui  │ RCtl  │ RAlt  │ :thx: │·      ┃     */
                FR_GRV, KC_PAST,KC_LCTL,KC_LALT,KC_LGUI,                                  KC_RGUI,KC_RCTL,KC_RALT, THX,  UC(IPT),
        /*     ┗━━━━━━━┷━━━━━━━┷━━━━━━━┷━━━━━━━┷━━━━━━━┛                                 ┗━━━━━━━┷━━━━━━━┷━━━━━━━┷━━━━━━━┷━━━━━━━┛     */
        /*                                            ┏━━━━━━━┯━━━━━━━┓   ┏━━━━━━━┯━━━━━━━                                             */
        /*                                            ┃ Copy  │ Cut   ┃   ┃ @     │ |     ┃                                            */
                                                       M_COPY, M_CUT,      FR_AT, FR_PIPE,
        /*                                    ┏━━━━━━━╃───────┼───────┨   ┠───────┼───────╄━━━━━━━┓                                    */
        /*                                    ┃       │       │ Paste ┃   ┃ %     │       │       ┃                                    */
                                                               M_PASTE,    FR_PERC,
        /*                                    ┃ ~L1/S │ ~L2   ├───────┨   ┠───────┤ ~L2   │ ~L1/E ┃                                    */
        /*                                    ┃       │       │ PgUp  ┃   ┃ PgDn  │       │       ┃                                    */
                                        LT(L_1,KC_SPC),MO(L_2),KC_PGUP,    KC_PGDN,MO(L_2),LT(L_1, KC_ENTER)
        /*                                    ┗━━━━━━━┷━━━━━━━┷━━━━━━━┛   ┗━━━━━━━┷━━━━━━━┷━━━━━━━┛                                    */
        ),

    [L_1] = ERGODOX_KEYMAP(
	// Layer 1, code | moves
        /* Left hand = code chars                                         Right hand = moves                                           */
        /* ┏━━━━━━━━━┯━━━━━━━┯━━━━━━━┯━━━━━━━┯━━━━━━━┯━━━━━━━┯━━━━━━━━┓   ┏━━━━━━━━┯━━━━━━━┯━━━━━━━┯━━━━━━━┯━━━━━━━┯━━━━━━━┯━━━━━━━━━┓ */
        /* ┃ Caps    │ f1    │ f2    │ f3    │ f4    │ f5    │ f6     ┃   ┃ f7     │ f8    │ f9    │ f10   │ f11   │ f12   │ ^ ¨     ┃ */
            KC_TRNS,  KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,       KC_F7,   KC_F8,  KC_F9,  KC_F10, KC_F11, KC_F12, KC_TRNS,
        /* ┠─────────┼───────┼───────┼───────┼───────┼───────┼────────┨   ┠────────┼───────┼───────┼───────┼───────┼───────┼─────────┨ */
        /* ┃ _       │ \     │ ==    │ !=    │ {     │ }     │ ~      ┃   ┃ :=     │ Begin │ End   │ WH UP │ WH DW │ p P   │ $       ┃ */
            BND,      FR_BSLS, EE,    NE,     FR_LCBR,FR_RCBR,TLD,         NV,      KC_HOME,KC_END, KC_WH_U,KC_WH_D,KC_TRNS,KC_TRNS,
        /* ┠─────────┼───────┼───────┼───────┼───────┼───────┤        ┃   ┠────────┼───────┼───────┼───────┼───────┼───────┼─────────┨ */
        /* ┃ Esc     │ =     │ !     │ /     │ (     │ )     ├────────┨   ┃        │ ←     │ ↓     │ ↑     │ →     │ m M   │ Enter   ┃ */
            KC_TRNS,  KC_EQL, FR_EXLM,FR_SLSH,FR_LPRN,FR_RPRN,                      KC_LEFT,KC_DOWN,KC_UP,  KC_RGHT,KC_TRNS,KC_ENT,
        /* ┠─────────┼───────┼───────┼───────┼───────┼───────┤ ;      ┃   ┃ ===    ├───────┼───────┼───────┼───────┼───────┼─────────┨ */
        /* ┃ _       │ #     │ <     │ >     │ [     │ ]     │        ┃   ┃        │ n N   │ Copy  │ Cut   │ Paste │ ! §   │ RShft   ┃ */
            KC_TRNS,  FR_HASH,FR_LABK,FR_RABK,FR_LBRC,FR_RBRC,FR_SCLN,     EEE,     KC_TRNS,M_COPY, M_CUT,  M_PASTE,KC_TRNS,KC_TRNS,
        /* ┗━━━┱─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┲━━━━━┷━━━━━━━━┛   ┗━━━━━━━━┷━━━━━┱─┴─────┬─┴─────┬─┴─────┬─┴─────┬─┴─────┲━━━┛ */
        /*     ┃ `     │ *     │ LCtl  │ LAlt  │ |>    ┃                                 ┃ RGui  │ RCtl  │ RAlt  │ :thx: │·      ┃     */
                KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS, EP,                                      KC_TRNS,KC_TRNS, KC_TRNS,KC_TRNS,KC_TRNS,
        /*     ┗━━━━━━━┷━━━━━━━┷━━━━━━━┷━━━━━━━┷━━━━━━━┛                                 ┗━━━━━━━┷━━━━━━━┷━━━━━━━┷━━━━━━━┷━━━━━━━┛     */
        /*                                            ┏━━━━━━━┯━━━━━━━┓   ┏━━━━━━━┯━━━━━━━┓                                            */
        /*                                            ┃ Copy  │ Cut   ┃   ┃ do    │ def   ┃                                            */
                                                       KC_TRNS,KC_TRNS,     DO,     DEF,
        /*                                    ┏━━━━━━━╃───────┼───────┨   ┠───────┼───────╄━━━━━━━┓                                    */
        /*                                    ┃       │       │ Paste ┃   ┃ end   │       │       ┃                                    */
                                                               KC_TRNS,     END,
        /*                                    ┃ ~L1/S │  ~L2  ├───────┨   ┠───────┤ ~L2   │ ~L1/E ┃                                    */
        /*                                    ┃       │       │ PgUp  ┃   ┃ PgDn  │       │       ┃                                    */
                                               KC_TRNS,KC_TRNS,KC_TRNS,    KC_TRNS,KC_TRNS,KC_TRNS
        /*                                    ┗━━━━━━━┷━━━━━━━┷━━━━━━━┛   ┗━━━━━━━┷━━━━━━━┷━━━━━━━┛                                    */
        ),

    [L_2] = ERGODOX_KEYMAP(
	// Layer 2, accents, symbols | numpad
        /* Left hand = accents, symbols                                   Right hand = numpad                                          */
        /* ┏━━━━━━━━━┯━━━━━━━┯━━━━━━━┯━━━━━━━┯━━━━━━━┯━━━━━━━┯━━━━━━━━┓   ┏━━━━━━━━┯━━━━━━━┯━━━━━━━┯━━━━━━━┯━━━━━━━┯━━━━━━━┯━━━━━━━━━┓ */
        /* ┃ -       │ -     │ -     │ -     │ -     │ -     │ -      ┃   ┃ CAPS   │ -     │ -     │ /     │ *     │ -     │ -       ┃ */
            KC_TRNS,  KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,     KC_CAPS, KC_TRNS,KC_TRNS,KC_PSLS,KC_PAST,KC_TRNS,KC_TRNS,
        /* ┠─────────┼───────┼───────┼───────┼───────┼───────┼────────┨   ┠────────┼───────┼───────┼───────┼───────┼───────┼─────────┨ */
        /* ┃ -       │ é     │ è     │ ê     │ û     │ ù     │ -      ┃   ┃ -      │ =     │ 7     │ 8     │ 9     │ -     │ -       ┃ */
            KC_TRNS,  FR_EACU,FR_EGRV,UC(C_E),UC(C_U),KC_QUOT,KC_TRNS,     KC_TRNS, FR_EQL, FR_7,   FR_8,   FR_9,   KC_TRNS,KC_TRNS,
        /* ┠─────────┼───────┼───────┼───────┼───────┼───────┤        ┃   ┠────────┼───────┼───────┼───────┼───────┼───────┼─────────┨ */
        /* ┃ -       │ œ     │ ™     │ ♥     │ €     │ ©     ├────────┨   ┃        │ ,     │ 4     │ 5     │ 6     │ -     │ -       ┃ */
            KC_TRNS,  UC(OE), UC(TM), UC(HRT),FR_EURO,UC(CP),                      FR_COMM,FR_4,   FR_5,   FR_6,   KC_TRNS,KC_TRNS,
        /* ┠─────────┼───────┼───────┼───────┼───────┼───────┤ -      ┃   ┃ -      ├───────┼───────┼───────┼───────┼───────┼─────────┨ */
        /* ┃ -       │ ✌️     │ ⛔    │ ✓     │ ⚠     │ ❌    │        ┃   ┃        │ 0     │ 1     │ 2     │ 3     │ -     │ -       ┃ */
            KC_TRNS,  UC(VI), UC(NOE),UC(VLD),UC(DA), UC(ILD),KC_TRNS,     KC_TRNS, FR_0,   FR_1,   FR_2,   FR_3,   KC_TRNS,KC_TRNS,
        /* ┗━━━┱─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┲━━━━━┷━━━━━━━━┛   ┗━━━━━━━━┷━━━━━┱─┴─────┬─┴─────┬─┴─────┬─┴─────┬─┴─────┲━━━┛ */
        /*     ┃ -     │ -     │ -     │ -     │ -     ┃                                 ┃ -     │ -     │ -     │ -     │ -     ┃     */
                KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,                                  KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
        /*     ┗━━━━━━━┷━━━━━━━┷━━━━━━━┷━━━━━━━┷━━━━━━━┛                                 ┗━━━━━━━┷━━━━━━━┷━━━━━━━┷━━━━━━━┷━━━━━━━┛     */
        /*                                            ┏━━━━━━━┯━━━━━━━┓   ┏━━━━━━━┯━━━━━━━┓                                            */
        /*                                            ┃ Copy  │ Cut   ┃   ┃ -     │ -     ┃                                            */
                                                       KC_TRNS,KC_TRNS,      KC_TRNS,KC_TRNS,
        /*                                    ┏━━━━━━━╃───────┼───────┨   ┠───────┼───────╄━━━━━━━┓                                    */
        /*                                    ┃       │       │ Paste ┃   ┃ -     │       │       ┃                                    */
                                                               KC_TRNS,    KC_TRNS,
        /*                                    ┃ ~L1/S │  ~L2  ├───────┨   ┠───────┤ ~L2   │ ~L1/E ┃                                    */
        /*                                    ┃       │       │ -     ┃   ┃ -     │       │       ┃                                    */
                                               KC_TRNS,KC_TRNS,KC_TRNS,    KC_TRNS,KC_TRNS,KC_TRNS
        /*                                    ┗━━━━━━━┷━━━━━━━┷━━━━━━━┛   ┗━━━━━━━┷━━━━━━━┷━━━━━━━┛                                    */
        ),
    [L_3] = ERGODOX_KEYMAP(

	// Layer 3, media keys
        /*  Right hand is used for media keys */
        /* ┏━━━━━━━━━┯━━━━━━━┯━━━━━━━┯━━━━━━━┯━━━━━━━┯━━━━━━━┯━━━━━━━━┓   ┏━━━━━━━━┯━━━━━━━┯━━━━━━━┯━━━━━━━┯━━━━━━━┯━━━━━━━┯━━━━━━━━━┓ */
        /* ┃ -       │ -     │ -     │ -     │ -     │ -     │ ~L3    ┃   ┃        │ -     │ -     │ -     │ -     │ -     │ -       ┃ */
            KC_TRNS,  KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,MO(L_3),     KC_TRNS, KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
        /* ┠─────────┼───────┼───────┼───────┼───────┼───────┼────────┨   ┠────────┼───────┼───────┼───────┼───────┼───────┼─────────┨ */
        /* ┃ -       │ -     │ -     │ -     │ -     │ -     │ -      ┃   ┃ Vol Up │ Mute  │ Prev  │ Mply  │ Next  │ Bri U │ -       ┃ */
            KC_TRNS,  KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,     KC_VOLU, KC_MUTE,KC_MPRV,KC_MPLY,KC_MNXT,KC_BRIU,KC_TRNS,
        /* ┠─────────┼───────┼───────┼───────┼───────┼───────┤        ┃   ┠────────┼───────┼───────┼───────┼───────┼───────┼─────────┨ */
        /* ┃ -       │ -     │ -     │ -     │ -     │ -     ├────────┨   ┃        │ -     │ -     │ -     │ -     │ Bri   │ -       ┃ */
            KC_TRNS,  KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,                      KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_BRID,KC_TRNS,
        /* ┠─────────┼───────┼───────┼───────┼───────┼───────┤ -      ┃   ┃ Vol Dn ├───────┼───────┼───────┼───────┼───────┼─────────┨ */
        /* ┃ -       │ -     │ -     │ -     │ -     │ -     │        ┃   ┃        │ -     │ -     │ -     │ -     │ -     │ -       ┃ */
            KC_TRNS,  KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,     KC_VOLD, KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
        /* ┗━━━┱─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┲━━━━━┷━━━━━━━━┛   ┗━━━━━━━━┷━━━━━┱─┴─────┬─┴─────┬─┴─────┬─┴─────┬─┴─────┲━━━┛ */
        /*     ┃ -     │ -     │ -     │ -     │ -     ┃                                 ┃ -     │ -     │ -     │ -     │ -     ┃     */
                KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,                                  KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
        /*     ┗━━━━━━━┷━━━━━━━┷━━━━━━━┷━━━━━━━┷━━━━━━━┛                                 ┗━━━━━━━┷━━━━━━━┷━━━━━━━┷━━━━━━━┷━━━━━━━┛     */
        /*                                            ┏━━━━━━━┯━━━━━━━┓   ┏━━━━━━━┯━━━━━━━┓                                            */
        /*                                            ┃ Copy  │ Cut   ┃   ┃ -     │ -     ┃                                            */
                                                       KC_TRNS,KC_TRNS,      KC_TRNS,KC_TRNS,
        /*                                    ┏━━━━━━━╃───────┼───────┨   ┠───────┼───────╄━━━━━━━┓                                    */
        /*                                    ┃       │       │ Paste ┃   ┃ -     │       │       ┃                                    */
                                                               KC_TRNS,    KC_TRNS,
        /*                                    ┃ ~L1/S │  ~L2  ├───────┨   ┠───────┤ ~L2   │ ~L1/E ┃                                    */
        /*                                    ┃       │       │ -     ┃   ┃ -     │       │       ┃                                    */
                                               KC_TRNS,KC_TRNS,KC_TRNS,    KC_TRNS,KC_TRNS,KC_TRNS
        /*                                    ┗━━━━━━━┷━━━━━━━┷━━━━━━━┛   ┗━━━━━━━┷━━━━━━━┷━━━━━━━┛                                    */
        ),
    [L_4] = ERGODOX_KEYMAP(
	// Layer 4, !macOS
        /* normal copy, cut, paste keys */
        /* ┏━━━━━━━━━┯━━━━━━━┯━━━━━━━┯━━━━━━━┯━━━━━━━┯━━━━━━━┯━━━━━━━━┓   ┏━━━━━━━━┯━━━━━━━┯━━━━━━━┯━━━━━━━┯━━━━━━━┯━━━━━━━┯━━━━━━━━━┓ */
        /* ┃ -       │ -     │ -     │ -     │ -     │ -     │ -      ┃   ┃ ->L0   │ -     │ -     │ -     │ -     │ -     │ -       ┃ */
            KC_TRNS,  KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,     TO(L_0), KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
        /* ┠─────────┼───────┼───────┼───────┼───────┼───────┼────────┨   ┠────────┼───────┼───────┼───────┼───────┼───────┼─────────┨ */
        /* ┃ -       │ -     │ -     │ -     │ -     │ -     │ -      ┃   ┃ -      │ -     │ -     │ -     │ -     │ -     │ -       ┃ */
            KC_TRNS,  KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,     KC_TRNS, KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
        /* ┠─────────┼───────┼───────┼───────┼───────┼───────┤        ┃   ┠────────┼───────┼───────┼───────┼───────┼───────┼─────────┨ */
        /* ┃ -       │ -     │ -     │ -     │ -     │ -     ├────────┨   ┃        │ -     │ -     │ -     │ -     │ -     │ -       ┃ */
            KC_TRNS,  KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,                      KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
        /* ┠─────────┼───────┼───────┼───────┼───────┼───────┤ -      ┃   ┃ -      ├───────┼───────┼───────┼───────┼───────┼─────────┨ */
        /* ┃ -       │ -     │ -     │ -     │ -     │ -     │        ┃   ┃        │ -     │ -     │ -     │ -     │ -     │ -       ┃ */
            KC_TRNS,  KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,     KC_TRNS, KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
        /* ┗━━━┱─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┲━━━━━┷━━━━━━━━┛   ┗━━━━━━━━┷━━━━━┱─┴─────┬─┴─────┬─┴─────┬─┴─────┬─┴─────┲━━━┛ */
        /*     ┃ -     │ -     │ -     │ -     │ -     ┃                                 ┃ -     │ -     │ -     │ -     │ -     ┃     */
                KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,                                   KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
        /*     ┗━━━━━━━┷━━━━━━━┷━━━━━━━┷━━━━━━━┷━━━━━━━┛                                 ┗━━━━━━━┷━━━━━━━┷━━━━━━━┷━━━━━━━┷━━━━━━━┛     */
        /*                                            ┏━━━━━━━┯━━━━━━━┓   ┏━━━━━━━┯━━━━━━━┓                                            */
        /*                                            ┃ Copy  │ Cut   ┃   ┃ -     │ -     ┃                                            */
                                                       C_COPY, C_CUT,      KC_TRNS,KC_TRNS,
        /*                                    ┏━━━━━━━╃───────┼───────┨   ┠───────┼───────╄━━━━━━━┓                                    */
        /*                                    ┃       │       │ Paste ┃   ┃ -     │       │       ┃                                    */
                                                               C_PASTE,    KC_TRNS,
        /*                                    ┃ ~L1/S │  ~L2  ├───────┨   ┠───────┤ ~L2   │ ~L1/E ┃                                    */
        /*                                    ┃       │       │ -     ┃   ┃ -     │       │       ┃                                    */
                                               KC_TRNS,KC_TRNS,KC_TRNS,    KC_TRNS,KC_TRNS,KC_TRNS
        /*                                    ┗━━━━━━━┷━━━━━━━┷━━━━━━━┛   ┗━━━━━━━┷━━━━━━━┷━━━━━━━┛                                    */
        ),
    [L_5] = ERGODOX_KEYMAP(
	// Layer 5, gaming
        /* space remap for gaming */
        /* ┏━━━━━━━━━┯━━━━━━━┯━━━━━━━┯━━━━━━━┯━━━━━━━┯━━━━━━━┯━━━━━━━━┓   ┏━━━━━━━━┯━━━━━━━┯━━━━━━━┯━━━━━━━┯━━━━━━━┯━━━━━━━┯━━━━━━━━━┓ */
        /* ┃ ->L0    │ -     │ -     │ -     │ -     │ -     │ -      ┃   ┃ -      │ -     │ -     │ -     │ -     │ -     │ -       ┃ */
            TO(L_0),  KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,     KC_TRNS, KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
        /* ┠─────────┼───────┼───────┼───────┼───────┼───────┼────────┨   ┠────────┼───────┼───────┼───────┼───────┼───────┼─────────┨ */
        /* ┃ -       │ -     │ -     │ -     │ -     │ -     │ -      ┃   ┃ -      │ -     │ -     │ -     │ -     │ -     │ -       ┃ */
            KC_TRNS,  KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,     KC_TRNS, KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
        /* ┠─────────┼───────┼───────┼───────┼───────┼───────┤        ┃   ┠────────┼───────┼───────┼───────┼───────┼───────┼─────────┨ */
        /* ┃ -       │ -     │ -     │ -     │ -     │ -     ├────────┨   ┃        │ -     │ -     │ -     │ -     │ -     │ -       ┃ */
            KC_TRNS,  KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,                      KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
        /* ┠─────────┼───────┼───────┼───────┼───────┼───────┤ -      ┃   ┃ -      ├───────┼───────┼───────┼───────┼───────┼─────────┨ */
        /* ┃ -       │ -     │ -     │ -     │ -     │ -     │        ┃   ┃        │ -     │ -     │ -     │ -     │ -     │ -       ┃ */
            KC_TRNS,  KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,     KC_TRNS, KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
        /* ┗━━━┱─────┴─┬─────┴─┬─────┴─┬─────┴─┬─────┴─┲━━━━━┷━━━━━━━━┛   ┗━━━━━━━━┷━━━━━┱─┴─────┬─┴─────┬─┴─────┬─┴─────┬─┴─────┲━━━┛ */
        /*     ┃ -     │ -     │ -     │ -     │ -     ┃                                 ┃ -     │ -     │ -     │ -     │ -     ┃     */
                KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_SPC,                                   KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
        /*     ┗━━━━━━━┷━━━━━━━┷━━━━━━━┷━━━━━━━┷━━━━━━━┛                                 ┗━━━━━━━┷━━━━━━━┷━━━━━━━┷━━━━━━━┷━━━━━━━┛     */
        /*                                            ┏━━━━━━━┯━━━━━━━┓   ┏━━━━━━━┯━━━━━━━┓                                            */
        /*                                            ┃ Copy  │ Cut   ┃   ┃ -     │ -     ┃                                            */
                                                       C_COPY, C_CUT,      KC_TRNS,KC_TRNS,
        /*                                    ┏━━━━━━━╃───────┼───────┨   ┠───────┼───────╄━━━━━━━┓                                    */
        /*                                    ┃       │       │ Paste ┃   ┃ -     │       │       ┃                                    */
                                                               C_PASTE,    KC_TRNS,
        /*                                    ┃ ~L1/S │  ~L2  ├───────┨   ┠───────┤ ~L2   │ ~L1/E ┃                                    */
        /*                                    ┃       │       │ -     ┃   ┃ -     │       │       ┃                                    */
                                               KC_TRNS,KC_TRNS,KC_TRNS,    KC_TRNS,KC_TRNS,KC_TRNS
        /*                                    ┗━━━━━━━┷━━━━━━━┷━━━━━━━┛   ┗━━━━━━━┷━━━━━━━┷━━━━━━━┛                                    */
        ),


};

const uint16_t PROGMEM fn_actions[] = {};

// Triggers macros on key press
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case EE:
        if (record->event.pressed) {
            SEND_STRING("==");
        }
	break;
    case TLD:
        if (record->event.pressed) {
            SEND_STRING("~");
        }
	break;
    case NV:
        if (record->event.pressed) {
            SEND_STRING(":=");
        }
	break;
    case NE:
        if (record->event.pressed) {
            SEND_STRING("!=");
        }
	break;
    case EEE:
        if (record->event.pressed) {
            SEND_STRING("===");
        }
	break;
    case EP:
        if (record->event.pressed) {
            SEND_STRING("|>");
        }
	break;
    case DEF:
        if (record->event.pressed) {
            SEND_STRING("def");
        }
	break;
    case DO:
        if (record->event.pressed) {
            SEND_STRING("do");
        }
	break;
    case END:
        if (record->event.pressed) {
            SEND_STRING("end");
        }
	break;
    case BND:
        if (record->event.pressed) {
            SEND_STRING("binding.irb");
        }
	break;
    case THX:
        if (record->event.pressed) {
            SEND_STRING(":thx:");
        }
	break;
    }
    return true;
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
    set_unicode_input_mode(UNICODE_MODE_LINUX);
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

#ifdef ST7565_ENABLE

const unsigned int LCD_MIN_ITENSITY = UINT16_MAX / 2;

void st7565_task_user(void) {
    st7565_clear();

    switch (get_highest_layer(layer_state)) {
        case L_0:
            // lpink 255,20,147
            ergodox_infinity_lcd_color(LCD_MIN_ITENSITY + 25500, LCD_MIN_ITENSITY + 9900, LCD_MIN_ITENSITY + 7100);
            st7565_write_P(PSTR("\n\n_macOS\n"), false);
            break;
        case L_1:
            // blue 0,191,255
            ergodox_infinity_lcd_color(LCD_MIN_ITENSITY, LCD_MIN_ITENSITY + 19100, LCD_MIN_ITENSITY + 25500);
            st7565_write_P(PSTR("\n\n=~ Code / Moves\n"), false);
            break;
        case L_2:
            // Green 50,205,50
            ergodox_infinity_lcd_color(LCD_MIN_ITENSITY + 5000, LCD_MIN_ITENSITY + 20500, LCD_MIN_ITENSITY + 5000);
            st7565_write_P(PSTR("\n\n!Fr Baguette\n"), false);
            break;
        case L_3:
            // pink 255,99,71
            ergodox_infinity_lcd_color(LCD_MIN_ITENSITY + 25500, LCD_MIN_ITENSITY + 2000, LCD_MIN_ITENSITY + 14700);
            st7565_write_P(PSTR("\n\n|> Media\n"), false);
            break;
        case L_4:
            ergodox_infinity_lcd_color(LCD_MIN_ITENSITY, LCD_MIN_ITENSITY, LCD_MIN_ITENSITY);
            st7565_write_P(PSTR("\n\n!macOS\n"), false);
            break;
        case L_5:
            ergodox_infinity_lcd_color(LCD_MIN_ITENSITY + 4242, LCD_MIN_ITENSITY, LCD_MIN_ITENSITY + 22420);
            st7565_write_P(PSTR("\n\n_gaming\n"), false);
            break;
    }
}

#endif
