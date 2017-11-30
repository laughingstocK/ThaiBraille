byte ArrowKey[16] = {
    0x00,               KEY_UP,         KEY_LEFT,       0x00,                   // 0,   1,  2,  3
    KEY_RIGHT,          0x00,           0x00,           0x00,                   // 4,   5,  6,  7
    KEY_DOWN,           0x00,           0x00,           0x00,                   // 8,   9,  10, 11
    0x00,               0x00,           0x00,           0x00,                   // 12,  13, 14, 15
};
byte CMDKEY[64][4] = {
    {0x00,              0x00,           0x00,           0x00},                  // 0
    {KEY_ENTER,         0x00,           0x00,           0x00},                  // 1
    {KEY_BACKSPACE,     0x00,           0x00,           0x00},                  // 2
    {KEY_DELETE,        0x00,           0x00,           0x00},                  // 3
    {KEY_TAB,           0x00,           0x00,           0x00},                  // 4
    {KEY_CAPS_LOCK,     0x00,           0x00,           0x00},                  // 5
    {KEY_TILDE,         0x00,           0x00,           0x00},                  // 6 Change KB Com & Android
    {KEY_ESC,           0x00,           0x00,           0x00},                  // 7
    {KEY_INSERT,        0x00,           0x00,           0x00},                  // 8
    {KEY_HOME,          0x00,           0x00,           0x00},                  // 9
    {KEY_PAGE_UP,       0x00,           0x00,           0x00},                  // 10
    {KEY_END,           0x00,           0x00,           0x00},                  // 11
    {KEY_PAGE_DOWN,     0x00,           0x00,           0x00},                  // 12
    {0x00,              0x00,           0x00,           0x00},                  // 13
    {0x00,              0x00,           0x00,           0x00},                  // 14
    {0x00,              0x00,           0x00,           0x00},                  // 15
    {0x00,              0x00,           0x00,           0x00},                  // 16
    {0x00,              0x00,           0x00,           0x00},                  // 17
    {0x00,              0x00,           0x00,           0x00},                  // 18
    {0x00,              0x00,           0x00,           0x00},                  // 19
    {0x00,              0x00,           0x00,           0x00},                  // 20
    {0x00,              0x00,           0x00,           0x00},                  // 21
    {0x00,              0x00,           0x00,           0x00},                  // 22
    {0x00,              0x00,           0x00,           0x00},                  // 23
    {0x00,              0x00,           0x00,           0x00},                  // 24
    {0x00,              0x00,           0x00,           0x00},                  // 25
    {0x00,              0x00,           0x00,           0x00},                  // 26
    {0x00,              0x00,           0x00,           0x00},                  // 27
    {0x00,              0x00,           0x00,           0x00},                  // 28
    {0x00,              0x00,           0x00,           0x00},                  // 29
    {0x00,              0x00,           0x00,           0x00},                  // 30
    {0x00,              0x00,           0x00,           0x00},                  // 31
    {0x00,              0x00,           0x00,           0x00},                  // 32
    {KEY_F1,            0x00,           0x00,           0x00},                  // 33
    {KEY_F2,            0x00,           0x00,           0x00},                  // 34
    {KEY_F3,            0x00,           0x00,           0x00},                  // 35
    {KEY_F4,            0x00,           0x00,           0x00},                  // 36
    {KEY_F5,            0x00,           0x00,           0x00},                  // 37
    {KEY_F6,            0x00,           0x00,           0x00},                  // 38
    {KEY_F7,            0x00,           0x00,           0x00},                  // 39
    {KEY_F8,            0x00,           0x00,           0x00},                  // 40
    {KEY_F9,            0x00,           0x00,           0x00},                  // 41
    {KEY_F10,           0x00,           0x00,           0x00},                  // 42
    {KEY_F11,           0x00,           0x00,           0x00},                  // 43
    {KEY_F12,           0x00,           0x00,           0x00},                  // 44
    {0x00,              0x00,           0x00,           0x00},                    // 45
    {0x00,              0x00,           0x00,           0x00},                  // 46
    {0x00,              0x00,           0x00,           0x00},                  // 47
    {0x00,              0x00,           0x00,           0x00},                  // 48
    {0x00,              0x00,           0x00,           0x00},                  // 49
    {0x00,              0x00,           0x00,           0x00},                  // 50
    {0x00,              0x00,           0x00,           0x00},                  // 51
    {0x00,              0x00,           0x00,           0x00},                  // 52
    {0x00,              0x00,           0x00,           0x00},                  // 53
    {0x00,              0x00,           0x00,           0x00},                  // 54
    {0x00,              0x00,           0x00,           0x00},                  // 55
    {0x00,              0x00,           0x00,           0x00},                  // 56
    {0x00,              0x00,           0x00,           0x00},                  // 57
    {0x00,              0x00,           0x00,           0x00},                  // 58
    {0x00,              0x00,           0x00,           0x00},                  // 59
    {0x00,              0x00,           0x00,           0x00},                  // 60
    {0x00,              0x00,           0x00,           0x00},                  // 61
    {0x00,              0x00,           0x00,           0x00},                  // 62
    {0x00,              0x00,           0x00,           0x00},                  // 63
};
byte BrailleKey[256][4] = {
    {0x00,              0x00,           0x00,           0x00},                  // 0
    {0x00,              KEY_A,          0x00,           KEY_T},                 // 1 char a or ะ
    {0x00,              KEY_1,          0x00,           KEY_Q},                 // 2 char 1 or ๆ
    {0x00,              KEY_B,          0x00,           KEY_B},                 // 3 char b or อิ
    {0x00,              KEY_QUOTE,      0x00,           KEY_H},                 // 4 char ' (APOSTROPHE) or อ็
    {0x00,              KEY_K,          0x00,           KEY_MINUS},             // 5 char k or ข
    {0x00,              KEY_2,          0x00,           KEY_U},                 // 6 char 2 or อี
    {0x00,              KEY_L,          0x00,           KEY_RIGHT_BRACE},       // 7 char l or ล
    {0x00,              KEY_TILDE,      0x00,           0x00},                  // 8 char ` (GRAVE ACCENT)
    {0x00,              KEY_C,          0x00,           KEY_6},                 // 9 char c or อุ
    {0x00,              KEY_I,          KEY_SHIFT,      KEY_F},                 // 10 char i or โ
    {0x00,              KEY_F,          0x00,           KEY_G},                 // 11 char f or เ
    {0x00,              KEY_SLASH,      KEY_SHIFT,      KEY_C},                 // 12 char / (SLASH) or ฉ
    {0x00,              KEY_M,          0x00,           KEY_COMMA},             // 13 char m or ม
    {0x00,              KEY_S,          0x00,           KEY_L},                 // 14 char s or ส
    {0x00,              KEY_P,          0x00,           KEY_Z},                 // 15 char p or ผ
    {0x00,              KEY_QUOTE,      0x00,           0x00},                  // 16 char " ([RIGHT,LEFT] DOUBLE QUOTATION) or
    {0x00,              KEY_E,          0x00,           0x00},                  // 17 char e
    {0x00,              KEY_3,          KEY_SHIFT,      KEY_6},                 // 18 char 3 or อู
    {0x00,              KEY_H,          0x00,           KEY_S},                 // 19 char h or ห
    {0x00,              KEY_9,          0x00,           KEY_J},                 // 20 char 9 or อ่
    {0x00,              KEY_O,          0x00,           KEY_V},                 // 21 char o or อ
    {0x00,              KEY_6,          0x00,           0x00},                  // 22 char 6 or
    {0x00,              KEY_R,          0x00,           KEY_I},                 // 23 char r or ร
    {KEY_SHIFT,         KEY_TILDE,      0x00,           0x00},                  // 24 char ~ (TILDE)
    {0x00,              KEY_D,          0x00,           KEY_F},                 // 25 char d or ด
    {0x00,              KEY_J,          0x00,           KEY_0},                 // 26 char j or จ
    {0x00,              KEY_G,          0x00,           KEY_D},                 // 27 char g or ก
    {KEY_SHIFT,         KEY_PERIOD,     0x00,           KEY_Y},                 // 28 char > (GREATER THAN) or อั
    {0x00,              KEY_N,          0x00,           KEY_O},                 // 29 char n or น
    {0x00,              KEY_T,          0x00,           KEY_5},                 // 30 char t or ถ
    {0x00,              KEY_Q,          0x00,           0x00},                  // 31 char q or
    {0x00,              KEY_COMMA,      0x00,           0x00},                  // 32 char,          (COMMA)
    {KEY_SHIFT,         KEY_8,          0x00,           KEY_K},                 // 33 char * (ASTERISK) or า
    {0x00,              KEY_5,          0x00,           KEY_N},                 // 34 char 5 or อื
    {KEY_SHIFT,         KEY_COMMA,      0x00,           KEY_C},                 // 35 char < (LESS THAN) or แ
    {0x00,              KEY_MINUS,      0x00,           0x00},                  // 36 char - (HYPHEN)
    {0x00,              KEY_U,          0x00,           KEY_8},                 // 37 char u or ค
    {0x00,              KEY_8,          KEY_SHIFT,      KEY_J},                 // 38 char 8 or อ๋
    {0x00,              KEY_V,          0x00,           KEY_LEFT_BRACE },       // 39 char v or บ
    {0x00,              KEY_PERIOD,     0x00,           0x00},                  // 40 char . (PERIOD)
    {KEY_SHIFT,         KEY_5,          0x00,           0x00},                  // 41 char % (PERCENT) or
    {KEY_SHIFT,         KEY_LEFT_BRACE, 0x00,           KEY_7},                 // 42 char    { (LEFT BRACE) or อึ
    {KEY_SHIFT,         KEY_4,          0x00,           KEY_A},                 // 43 char $ (DOLLAR SIGN) or ฟ
    {KEY_SHIFT,         KEY_EQUAL,      0x00,           KEY_EQUAL},             // 44 char + (PLUS) or ช
    {0x00,              KEY_X,          0x00,           KEY_SLASH},             // 45 char x or ฝ
    {KEY_SHIFT,         KEY_1,          KEY_SHIFT,      KEY_SEMICOLON},         // 46 char ! (EXCLAMATION) or ซ
    {KEY_SHIFT,         KEY_7,          0x00,           KEY_X},                 // 47 char & (AMPERSAND) or ป
    {0x00,              KEY_SEMICOLON,  0x00,           0x00},                  // 48 char ; (SEMICOLON) or
    {KEY_SHIFT,         KEY_SEMICOLON,  0x00,           KEY_W},                 // 49 char : (COLON) or ไ
    {0x00,              KEY_4,          0x00,           KEY_H},                 // 50 char 4 or อ้
    {KEY_SHIFT,         KEY_BACKSLASH,  0x00,           KEY_9},                 // 51 char | (VERTICAL BAR) or ต
    {0x00,              KEY_0,          KEY_SHIFT,      KEY_N},                 // 52 char 0 or อ์
    {0x00,              KEY_Z,          0x00,           KEY_E},                 // 53 char z or อำ
    {0x00,              KEY_7,          KEY_SHIFT,      KEY_U},                 // 54 char 7 or อ๊
    {KEY_SHIFT,         KEY_9,          0x00,           0x00},                  // 55 char ( (LEFT PARENTHESES)
    {0x00,              0x00,           0x00,           0x00},                  // 56
    {KEY_SHIFT,         KEY_SLASH,      0x00,           KEY_R},                 // 57 char ? (QUESTION) or พ
    {0x00,              KEY_W,          0x00,           KEY_SEMICOLON},         // 58 char w or ว
    {KEY_SHIFT,         KEY_RIGHT_BRACE,0x00,           KEY_QUOTE},             // 59 char } (RIGHT BRACE) or ง
    {KEY_SHIFT,         KEY_3,          0x00,           0x00},                  // 60 char # (NUMBER SIGN)
    {0x00,              KEY_Y,          0x00,           KEY_P},                 // 61 char y or ย
    {KEY_SHIFT,         KEY_0,          0x00,           KEY_M},                 // 62 char ) (RIGHT PARENTHESES) or ท
    {0x00,              KEY_EQUAL,      KEY_SHIFT,      KEY_V},                 // 63 char = (EQUAL SIGN) or ฮ
    {0x00,              0x00,           0x00,           0x00},                  // 64
    {KEY_SHIFT,         KEY_A,          0x00,           0x00},                  // 65 char A
    {0x00,              0x00,           KEY_SHIFT,      KEY_2},                 // 66 เลข ๑
    {KEY_SHIFT,         KEY_B,          0x00,           0x00},                  // 67 char B
    {KEY_SHIFT,         KEY_K,          0x00,           0x00},                  // 69 char K
    {0x00,              0x00,           KEY_SHIFT,      KEY_3},                 // 70 เลข ๒
    {KEY_SHIFT,         KEY_L,          KEY_SHIFT,      KEY_PERIOD},            // 71 char L or ฬ
    {KEY_SHIFT,         KEY_2,          0x00,           0x00},                  // 72 char @ (AT SIGN)
    {KEY_SHIFT,         KEY_C,          0x00,           0x00},                  // 73 char C
    {KEY_SHIFT,         KEY_I,          0x00,           0x00},                  // 74 char I
    {KEY_SHIFT,         KEY_F,          0x00,           0x00},                  // 75 char F
    {0x00,              0x00,           0x00,           0x00},                  // 76 char
    {KEY_SHIFT,         KEY_M,          0x00,           0x00},                  // 77 char M
    {KEY_SHIFT,         KEY_S,          KEY_SHIFT,      KEY_L},                 // 78 char S or ศ
    {KEY_SHIFT,         KEY_P,          0x00,           0x00},                  // 79 char P
    {0x00,              0x00,           0x00,           0x00},                  // 80 char
    {KEY_SHIFT,         KEY_E,          0x00,           0x00},                  // 81 char E
    {0x00,              0x00,           KEY_SHIFT,      KEY_4},                 // 82 เลข ๓
    {KEY_SHIFT,         KEY_H,          0x00,           0x00},                  // 83 char H
    {0x00,              0x00,           KEY_SHIFT,      KEY_EQUAL},             // 84 เลข ๙
    {KEY_SHIFT,         KEY_O,          0x00,           0x00},                  // 85 char O
    {0x00,              0x00,           KEY_SHIFT,      KEY_9},                 // 86 เลข ๖
    {KEY_SHIFT,         KEY_R,          0x00,           0x00},                  // 87 char R
    {KEY_SHIFT,         KEY_6,          0x00,           0x00},                  // 88 char ^ (CARET)
    {KEY_SHIFT,         KEY_D,          KEY_SHIFT,      KEY_E},                 // 89 char D or ฎ
    {KEY_SHIFT,         KEY_J,          0x00,           0x00},                  // 90 char J
    {KEY_SHIFT,         KEY_G,          0x00,           0x00},                  // 91 char G
    {0x00,              0x00,           0x00,           0x00},                  // 92
    {KEY_SHIFT,         KEY_N,          KEY_SHIFT,      KEY_I},                 // 93 char N or ณ
    {KEY_SHIFT,         KEY_T,          KEY_SHIFT,      KEY_LEFT_BRACE},        // 94 char T or ฐ
    {KEY_SHIFT,         KEY_Q,          0x00,           0x00},                  // 95 char Q
    {0x00,              0x00,           0x00,           0x00},                  // 96
    {0x00,              0x00,           0x00,           0x00},                  // 97
    {0x00,              0x00,           KEY_SHIFT,      KEY_8},                 // 98 เลข ๕
    {0x00,              0x00,           0x00,           0x00},                  // 99
    {0x00,              0x00,           0x00,           0x00},                  // 100
    {KEY_SHIFT,         KEY_U,          KEY_SHIFT,      KEY_S},                 // 101 char U or ฆ
    {0x00,              0x00,           KEY_SHIFT,      KEY_MINUS},             // 102 เลข ๘
    {KEY_SHIFT,         KEY_V,          0x00,           0x00},                  // 103 char V
    {0x00,              0x00,           0x00,           0x00},                  // 104
    {0x00,              0x00,           0x00,           0x00},                  // 105
    {0x00,              KEY_LEFT_BRACE, 0x00,           0x00},                  // 106 char [ (LEFT BRACKET)
    {0x00,              0x00,           0x00,           0x00},                  // 107
    {0x00,              0x00,           KEY_SHIFT,      KEY_G},                 // 108 ฌ
    {KEY_SHIFT,         KEY_X,          0x00,           0x00},                  // 109 char X
    {0x00,              0x00,           0x00,           0x00},                  // 110
    {0x00,              0x00,           0x00,           0x00},                  // 111
    {0x00,              0x00,           0x00,           0x00},                  // 112
    {0x00,              0x00,           0x00,           0x00},                  // 113
    {0x00,              0x00,           KEY_SHIFT,      KEY_5},                 // 114 เลข ๔
    {0x00,              KEY_BACKSLASH,  KEY_SHIFT,      KEY_D},                 // 115 char \ (BACK SLASH) or ฏ
    {0x00,              0x00,           KEY_SHIFT,      KEY_Q},                 // 116 เลข ๐
    {KEY_SHIFT,         KEY_Z,          0x00,           0x00},                  // 117 char Z
    {0x00,              0x00,           KEY_SHIFT,      KEY_0},                 // 118 เลข ๗
    {0x00,              0x00,           0x00,           0x00},                  // 119
    {KEY_SHIFT,         KEY_MINUS,      0x00,           0x00},                  // 120 char _ (UNDERSCORE,           UNDERLINE)
    {0x00,              0x00,           0x00,           KEY_4},                 // 121 ภ
    {KEY_SHIFT,         KEY_W,          0x00,           0x00},                  // 122 char W
    {0x00,              KEY_RIGHT_BRACE,0x00,           0x00},                  // 123 char ] (RIGHT BRACKET)
    {0x00,              0x00,           0x00,           0x00},                  // 124
    {KEY_SHIFT,         KEY_Y,          KEY_SHIFT,      KEY_P},                 // 125 char Y or ญ
    {0x00,              0x00,           KEY_SHIFT,      KEY_R},                 // 126 ฑ
    {0x00,              0x00,           0x00,           0x00},                  // 127
    {0x00,              0x00,           0x00,           0x00},                  // 128
    {0x00,              0x00,           0x00,           0x00},                  // 129
    {0x00,              0x00,           0x00,           0x00},                  // 130
    {0x00,              0x00,           KEY_SHIFT,      KEY_7},                 // 131 ฿ (บาท)
    {0x00,              0x00,           KEY_SHIFT,      KEY_B},                 // 132 . (พินทุ)
    {0x00,              0x00,           0x00,           0x00},                  // 133
    {0x00,              0x00,           0x00,           0x00},                  // 134
    {0x00,              0x00,           KEY_SHIFT,      KEY_SLASH},             // 135 ฦ
    {0x00,              0x00,           0x00,           0x00},                  // 136
    {0x00,              0x00,           0x00,           0x00},                  // 137
    {0x00,              0x00,           0x00,           0x00},                  // 138
    {0x00,              0x00,           0x00,           0x00},                  // 139
    {0x00,              0x00,           0x00,           0x00},                  // 140
    {0x00,              0x00,           0x00,           0x00},                  // 141
    {0x00,              0x00,           KEY_SHIFT,      KEY_K},                 // 142 ษ
    {0x00,              0x00,           0x00,           0x00},                  // 143
    {0x00,              0x00,           KEY_SHIFT,      KEY_Y},                 // 144 อํ (นิคหิต)
    {0x00,              0x00,           0x00,           0x00},                  // 145
    {0x00,              0x00,           0x00,           0x00},                  // 146
    {0x00,              0x00,           0x00,           0x00},                  // 147
    {0x00,              0x00,           0x00,           0x00},                  // 148
    {0x00,              0x00,           0x00,           0x00},                  // 149
    {0x00,              0x00,           0x00,           0x00},                  // 150
    {0x00,              0x00,           KEY_SHIFT,      KEY_A},                 // 151 ฤ
    {0x00,              0x00,           0x00,           0x00},                  // 152
    {0x00,              0x00,           0x00,           0x00},                  // 153
    {0x00,              0x00,           0x00,           0x00},                  // 154
    {0x00,              0x00,           0x00,           0x00},                  // 155
    {0x00,              0x00,           0x00,           0x00},                  // 156
    {0x00,              0x00,           0x00,           0x00},                  // 157
    {0x00,              0x00,           0x00,           0x00},                  // 158
    {0x00,              0x00,           0x00,           0x00},                  // 159
    {0x00,              0x00,           0x00,           0x00},                  // 160
    {0x00,              0x00,           0x00,           KEY_1},                 // 161 ๅ (ลากข้างยาว)
    {0x00,              0x00,           0x00,           0x00},                  // 162
    {0x00,              0x00,           0x00,           0x00},                  // 163
    {0x00,              0x00,           0x00,           0x00},                  // 164
    {0x00,              0x00,           KEY_SHIFT,      KEY_BACKSLASH},         // 165 ฅ
    {0x00,              0x00,           0x00,           0x00},                  // 166
    {0x00,              0x00,           0x00,           0x00},                  // 167
    {0x00,              0x00,           0x00,           0x00},                  // 168
    {0x00,              0x00,           0x00,           0x00},                  // 169
    {0x00,              0x00,           0x00,           0x00},                  // 170
    {0x00,              0x00,           0x00,           0x00},                  // 171
    {0x00,              0x00,           0x00,           0x00},                  // 172
    {0x00,              0x00,           0x00,           0x00},                  // 173
    {0x00,              0x00,           0x00,           0x00},                  // 174
    {0x00,              0x00,           0x00,           0x00},                  // 175
    {0x00,              0x00,           KEY_SHIFT,      KEY_O},                 // 176
    {0x00,              0x00,           0x00,           KEY_PERIOD},            // 177 ใ
    {0x00,              0x00,           0x00,           0x00},                  // 178
    {0x00,              0x00,           0x00,           0x00},                  // 179
    {0x00,              0x00,           0x00,           0x00},                  // 180
    {0x00,              0x00,           0x00,           0x00},                  // 181
    {0x00,              0x00,           0x00,           0x00},                  // 182
    {0x00,              0x00,           0x00,           0x00},                  // 183
    {0x00,              0x00,           0x00,           0x00},                  // 184
    {0x00,              0x00,           0x00,           0x00},                  // 185
    {0x00,              0x00,           0x00,           0x00},                  // 186
    {0x00,              0x00,           0x00,           0x00},                  // 187
    {0x00,              0x00,           0x00,           0x00},                  // 188
    {0x00,              0x00,           0x00,           0x00},                  // 189
    {0x00,              0x00,           KEY_SHIFT,      KEY_COMMA},             // 190 ฒ
    {0x00,              0x00,           0x00,           0x00},                  // 191
    {0x00,              0x00,           0x00,           0x00},                  // 192
    {0x00,              0x00,           0x00,           0x00},                  // 193
    {0x00,              0x00,           0x00,           0x00},                  // 194
    {0x00,              0x00,           0x00,           0x00},                  // 195
    {0x00,              0x00,           0x00,           0x00},                  // 196
    {0x00,              0x00,           0x00,           KEY_BACKSLASH},         // 197 ฃ
    {0x00,              0x00,           0x00,           0x00},                  // 198
    {0x00,              0x00,           0x00,           0x00},                  // 199
    {0x00,              0x00,           0x00,           0x00},                  // 200
    {0x00,              0x00,           0x00,           0x00},                  // 201
    {0x00,              0x00,           0x00,           0x00},                  // 202
    {0x00,              0x00,           0x00,           0x00},                  // 203
    {0x00,              0x00,           0x00,           0x00},                  // 204
    {0x00,              0x00,           0x00,           0x00},                  // 205
    {0x00,              0x00,           0x00,           0x00},                  // 206
    {0x00,              0x00,           0x00,           0x00},                  // 207
    {0x00,              0x00,           0x00,           0x00},                  // 208
    {0x00,              0x00,           0x00,           0x00},                  // 209
    {0x00,              0x00,           0x00,           0x00},                  // 210
    {0x00,              0x00,           0x00,           0x00},                  // 211
    {0x00,              0x00,           0x00,           0x00},                  // 212
    {0x00,              0x00,           0x00,           0x00},                  // 213
    {0x00,              0x00,           0x00,           0x00},                  // 214
    {0x00,              0x00,           0x00,           0x00},                  // 215
    {0x00,              0x00,           0x00,           0x00},                  // 216
    {0x00,              0x00,           0x00,           0x00},                  // 217
    {0x00,              0x00,           0x00,           0x00},                  // 218
    {0x00,              0x00,           0x00,           0x00},                  // 219
    {0x00,              0x00,           0x00,           0x00},                  // 220
    {0x00,              0x00,           0x00,           0x00},                  // 221
    {0x00,              0x00,           0x00,           0x00},                  // 222
    {0x00,              0x00,           0x00,           0x00},                  // 223
    {0x00,              0x00,           0x00,           0x00},                  // 224
    {0x00,              0x00,           0x00,           0x00},                  // 225
    {0x00,              0x00,           0x00,           0x00},                  // 226
    {0x00,              0x00,           0x00,           0x00},                  // 227
    {0x00,              0x00,           0x00,           0x00},                  // 228
    {0x00,              0x00,           0x00,           0x00},                  // 229
    {0x00,              0x00,           0x00,           0x00},                  // 230
    {0x00,              0x00,           0x00,           0x00},                  // 231
    {0x00,              0x00,           0x00,           0x00},                  // 232
    {0x00,              0x00,           0x00,           0x00},                  // 233
    {0x00,              0x00,           0x00,           0x00},                  // 234
    {0x00,              0x00,           0x00,           0x00},                  // 235
    {0x00,              0x00,           0x00,           0x00},                  // 236
    {0x00,              0x00,           0x00,           0x00},                  // 237
    {0x00,              0x00,           0x00,           0x00},                  // 238
    {0x00,              0x00,           0x00,           0x00},                  // 239
    {0x00,              0x00,           0x00,           0x00},                  // 240
    {0x00,              0x00,           0x00,           0x00},                  // 241
    {0x00,              0x00,           0x00,           0x00},                  // 242
    {0x00,              0x00,           0x00,           0x00},                  // 243
    {0x00,              0x00,           0x00,           0x00},                  // 244
    {0x00,              0x00,           0x00,           0x00},                  // 245
    {0x00,              0x00,           0x00,           0x00},                  // 246
    {0x00,              0x00,           0x00,           0x00},                  // 247
    {0x00,              0x00,           0x00,           0x00},                  // 248
    {0x00,              0x00,           0x00,           0x00},                  // 249
    {0x00,              0x00,           0x00,           0x00},                  // 250
    {0x00,              0x00,           0x00,           0x00},                  // 251
    {0x00,              0x00,           0x00,           0x00},                  // 252
    {0x00,              0x00,           0x00,           0x00},                  // 253
    {0x00,              0x00,           KEY_SHIFT,      KEY_T},                 // 254 ธ
    {0x00,              0x00,           0x00,           0x00},                  // 255
    {0x00,              0x00,           0x00,           0x00},                  // 256
};
byte BrialleKey2Byte[19][4] = {
    {0x07,              0x02,           KEY_SHIFT,      KEY_SLASH},             // 0 ฦ
    {0x17,              0x02,           KEY_SHIFT,      KEY_A},                 // 1 ฤ
    {0x20,              0x25,           KEY_SHIFT,      KEY_BACKSLASH},         // 2 ฅ
    {0x20,              0x2C,           KEY_SHIFT,      KEY_G},                 // 3 ฌ
    {0x20,              0x3D,           KEY_SHIFT,      KEY_P},                 // 4 ญ
    {0x20,              0x19,           KEY_SHIFT,      KEY_E},                 // 5 ฎ
    {0x20,              0x33,           KEY_SHIFT,      KEY_D},                 // 6 ฏ
    {0x20,              0x1E,           KEY_SHIFT,      KEY_LEFT_BRACE},        // 7 ฐ
    {0x20,              0x3E,           KEY_SHIFT,      KEY_R},                 // 8 ฑ
    {0x20,              0x1D,           KEY_SHIFT,      KEY_I},                 // 9 ณ
    {0x20,              0x39,           0x00,           KEY_4},                 // 10 ภ
    {0x20,              0x0E,           KEY_SHIFT,      KEY_L},                 // 11 ศ
    {0x24,              0x25,           KEY_SHIFT,      KEY_S},                 // 12 ฆ
    {0x24,              0x05,           KEY_SHIFT,      KEY_SEMICOLON},         // 13 ซ
    {0x24,              0x0E,           KEY_SHIFT,      KEY_K},                 // 14 ษ
    {0x24,              0x07,           KEY_SHIFT,      KEY_PERIOD},            // 15 ฬ
    {0x30,              0x3E,           KEY_SHIFT,      KEY_COMMA},             // 16 ฒ
    {0x31,              0x01,           0x00,           KEY_PERIOD},            // 17 ใ
    {0x34,              0x3E,           KEY_SHIFT,      KEY_T},                 // 18 ธ
};
byte SpaceKey[129][4] = {
    {0x00,              0x00,           0x00,           0x00},                  // 0
    {KEY_CTRL,          0x00,           KEY_A,          0x00},                  // 1 Select all text.
    {KEY_ALT,           0x00,           KEY_F,          0x00},                  // 2 File menu options in current program. (Key_1)
    {KEY_CTRL,          0x00,           KEY_B,          0x00},                  // 3 Change selected text to be Bold
    {0x00,              0x00,           0x00,           0x00},                  // 4
    {KEY_CTRL,          0x00,           KEY_K,          0x00},                  // 5 Insert hyperlink for selected text
    {KEY_ALT,           0x00,           KEY_E,          0x00},                  // 6 Edit options in current program (Key_2)
    {0x00,              0x00,           0x00,           0x00},                  // 7
    {0x00,              0x00,           0x00,           0x00},                  // 8
    {KEY_CTRL,          0x00,           KEY_C,          0x00},                  // 9 Copy selected item
    {KEY_CTRL,          0x00,           KEY_I,          0x00},                  // 10 Change selected text to be in Italics
    {KEY_CTRL,          0x00,           KEY_F,          0x00},                  // 11 Open find window for current document or window
    {0x00,              0x00,           0x00,           0x00},                  // 12
    {0x00,              0x00,           0x00,           0x00},                  // 13
    {KEY_CTRL,          0x00,           KEY_S,          0x00},                  // 14 Save current document file.
    {KEY_CTRL,          0x00,           KEY_P,          0x00},                  // 15 Print the current page or document.
    {0x00,              0x00,           0x00,           0x00},                  // 16
    {0x00,              0x00,           0x00,           0x00},                  // 17
    {KEY_ALT,           0x00,           KEY_TAB,        0x00},                  // 18 Switch between open programs (Key_3)
    {0x00,              0x00,           0x00,           0x00},                  // 19
    {0x00,              0x00,           KEY_9,          0x00},                  // 20 (Key_9)
    {KEY_CTRL,          0x00,           KEY_O,          0x00},                  // 21 Open a file in current software program
    {KEY_CTRL,          KEY_SHIFT,      KEY_ESC,        0x00},                  // 22 Opens Windows Task Manager (Key_6)
    {0x00,              0x00,           0x00,           0x00},                  // 23
    {0x00,              0x00,           0x00,           0x00},                  // 24
    {0x00,              0x00,           0x00,           0x00},                  // 25
    {0x00,              0x00,           0x00,           0x00},                  // 26
    {0x00,              0x00,           0x00,           0x00},                  // 27
    {0x00,              0x00,           0x00,           0x00},                  // 28
    {KEY_CTRL,          0x00,           KEY_N,          0x00},                  // 29 Create a new, blank document in some software programs
    {0x00,              0x00,           0x00,           0x00},                  // 30
    {0x00,              0x00,           0x00,           0x00},                  // 31
    {0x00,              0x00,           0x00,           0x00},                  // 32
    {0x00,              0x00,           0x00,           0x00},                  // 33
    {KEY_CTRL,          0x00,           KEY_ESC,        0x00},                  // 34 Opens the START menu (Key_5)
    {0x00,              0x00,           0x00,           0x00},                  // 35
    {0x00,              0x00,           0x00,           0x00},                  // 36
    {KEY_CTRL,          0x00,           KEY_U,          0x00},                  // 37 Change selected text to be Underlined
    {KEY_ALT,           0x00,           KEY_ENTER,      0x00},                  // 38 Open the Properties for the selected item (file, folder, shortcut, etc.) (Key_8)
    {KEY_CTRL,          0x00,           KEY_V,          0x00},                  // 39 Paste
    {0x00,              0x00,           0x00,           0x00},                  // 40
    {0x00,              0x00,           0x00,           0x00},                  // 41
    {0x00,              0x00,           0x00,           0x00},                  // 42
    {0x00,              0x00,           0x00,           0x00},                  // 43
    {0x00,              0x00,           0x00,           0x00},                  // 44
    {KEY_CTRL,          0x00,           KEY_X,          0x00},                  // 45 Cut selected item.
    {0x00,              0x00,           0x00,           0x00},                  // 46
    {0x00,              0x00,           0x00,           0x00},                  // 47
    {0x00,              0x00,           0x00,           0x00},                  // 48
    {0x00,              0x00,           0x00,           0x00},                  // 49
    {KEY_SHIFT,         0x00,           KEY_DELETE,     0x00},                  // 50 Cut selected item. (Key_4)
    {0x00,              0x00,           0x00,           0x00},                  // 51
    {0x00,              0x00,           KEY_0,          0x00},                  // 52 (Key_0)
    {KEY_CTRL,          0x00,           KEY_Z,          0x00},                  // 53 Undo
    {KEY_ALT,           0x00,           KEY_F4,         0x00},                  // 54 Close the currently active program (Key_7)
    {0x00,              0x00,           0x00,           0x00},                  // 55
    {0x00,              0x00,           0x00,           0x00},                  // 56
    {0x00,              0x00,           0x00,           0x00},                  // 57
    {KEY_CTRL,          0x00,           KEY_W,          0x00},                  // 58 Close Current Page
    {0x00,              0x00,           0x00,           0x00},                  // 59
    {0x00,              0x00,           0x00,           0x00},                  // 60
    {0x00,              0x00,           0x00,           0x00},                  // 61
    {0x00,              0x00,           0x00,           0x00},                  // 62
    {0x00,              0x00,           0x00,           0x00},                  // 63
    {0x00,              0x00,           0x00,           0x00},                  // 64
    {KEY_CTRL,          0x00,           KEY_A,          0x00},                  // 65 Select all text.
    {0x00,              0x00,           0x00,           0x00},                  // 66
    {KEY_CTRL,          0x00,           KEY_B,          0x00},                  // 67 Change selected text to be Bold
    {0x00,              0x00,           0x00,           0x00},                  // 68
    {KEY_CTRL,          0x00,           KEY_K,          0x00},                  // 69 Insert hyperlink for selected text
    {0x00,              0x00,           0x00,           0x00},                  // 70
    {0x00,              0x00,           KEY_L,          0x00},                  // 71
    {0x00,              0x00,           0x00,           0x00},                  // 72
    {KEY_CTRL,          0x00,           KEY_C,          0x00},                  // 73 Copy selected item
    {KEY_CTRL,          0x00,           KEY_I,          0x00},                  // 74 Change selected text to be in Italics
    {KEY_CTRL,          0x00,           KEY_F,          0x00},                  // 75 Open find window for current document or window
    {0x00,              0x00,           0x00,           0x00},                  // 76
    {0x00,              0x00,           0x00,           0x00},                  // 77
    {KEY_CTRL,          0x00,           KEY_S,          0x00},                  // 78 Save current document file.
    {KEY_CTRL,          0x00,           KEY_P,          0x00},                  // 79 Print the current page or document.
    {0x00,              0x00,           0x00,           0x00},                  // 80
    {0x00,              0x00,           KEY_E,          0x00},                  // 81
    {0x00,              0x00,           0x00,           0x00},                  // 82
    {0x00,              0x00,           KEY_H,          0x00},                  // 83
    {0x00,              0x00,           0x00,           0x00},                  // 84
    {KEY_CTRL,          0x00,           KEY_O,          0x00},                  // 85 Open a file in current software program
    {0x00,              0x00,           0x00,           0x00},                  // 86
    {0x00,              0x00,           KEY_R,          0x00},                  // 87
    {0x00,              0x00,           0x00,           0x00},                  // 88
    {0x00,              0x00,           KEY_D,          0x00},                  // 89
    {0x00,              0x00,           KEY_J,          0x00},                  // 90
    {0x00,              0x00,           KEY_G,          0x00},                  // 91
    {0x00,              0x00,           0x00,           0x00},                  // 92
    {KEY_CTRL,          0x00,           KEY_N,          0x00},                  // 93 Create a new, blank document in some software programs
    {0x00,              0x00,           KEY_T,          0x00},                  // 94
    {0x00,              0x00,           KEY_Q,          0x00},                  // 95
    {0x00,              0x00,           0x00,           0x00},                  // 96
    {0x00,              0x00,           0x00,           0x00},                  // 97
    {0x00,              0x00,           0x00,           0x00},                  // 98
    {0x00,              0x00,           0x00,           0x00},                  // 99
    {0x00,              0x00,           0x00,           0x00},                  // 100
    {KEY_CTRL,          0x00,           KEY_U,          0x00},                  // 101 Change selected text to be Underlined
    {0x00,              0x00,           0x00,           0x00},                  // 102
    {KEY_CTRL,          0x00,           KEY_V,          0x00},                  // 103 Paste
    {0x00,              0x00,           0x00,           0x00},                  // 104
    {0x00,              0x00,           0x00,           0x00},                  // 105
    {0x00,              0x00,           0x00,           0x00},                  // 106
    {0x00,              0x00,           0x00,           0x00},                  // 107
    {0x00,              0x00,           0x00,           0x00},                  // 108
    {KEY_CTRL,          0x00,           KEY_X,          0x00},                  // 109 Cut selected item.
    {0x00,              0x00,           0x00,           0x00},                  // 110
    {0x00,              0x00,           0x00,           0x00},                  // 111
    {0x00,              0x00,           0x00,           0x00},                  // 112
    {0x00,              0x00,           0x00,           0x00},                  // 113
    {0x00,              0x00,           0x00,           0x00},                  // 114
    {0x00,              0x00,           0x00,           0x00},                  // 115
    {0x00,              0x00,           0x00,           0x00},                  // 116
    {KEY_CTRL,          0x00,           KEY_Z,          0x00},                  // 117 Undo
    {0x00,              0x00,           0x00,           0x00},                  // 118
    {0x00,              0x00,           0x00,           0x00},                  // 119
    {0x00,              0x00,           0x00,           0x00},                  // 120
    {0x00,              0x00,           0x00,           0x00},                  // 121
    {0x00,              0x00,           KEY_W,          0x00},                  // 122 Close Current Page
    {0x00,              0x00,           0x00,           0x00},                  // 123
    {0x00,              0x00,           0x00,           0x00},                  // 124
    {KEY_CTRL,          0x00,           KEY_Y,          0x00},                  // 125 Redo
    {0x00,              0x00,           0x00,           0x00},                  // 126
    {0x00,              0x00,           0x00,           0x00},                  // 127
    {0x00,              0x00,           KEY_ENTER,      0x00},                  // 128 Key Enter
};