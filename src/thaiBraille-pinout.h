// Braille-8 Standard Position:		[B1]	[B2]	[B3]	[B4]	[B5]	[B6]	[B7]	[B8]
const byte BRAILLE_PINOUT[8] =	{	A4,		A3,		A2,		A5,		A6,		A7,		A1,		A8	};
const bool USING_BRAILLE = true;
const bool BRAILLE_EXT_RES = false;

// Braille-6 Standard Position:		[B1]	[B2]	[B3]	[B4]	[B5]	[B6]
const byte COMMAND_PINOUT[6] =	{	A10,	A11,	A9,		A12,	A13,	A14		};
const bool USING_COMMAND = true;
const bool COMMAND_EXT_RES = false;

// Arrow Order:						[UP]	[LEFT]	[RIGHT]	[DOWN]
const byte THUMB_PINOUT[4] =	{	2,		3,		4,		5		};
const bool USING_THUMB = true;
const bool THUMB_EXT_RES = false;

// LEFTMOST Cursor Position:
const byte CURSOR_PINOUT[40] =	{
	22,		23,		24,		25,		26,		27,		28,		29,		30,		31,
	32,		33,		34,		35,		36,		37,		38,		39,		40,		41,
	42,		43,		44,		45,		46,		47,		48,		49,		13,		12,
	11,		10,		A8,		A9,		A10,	A11,	A12,	A13,	A14,	A15
};
const bool USING_CURSOR = false;
const bool CURSOR_EXT_RES = false;

// Spacebar:
const byte SPACEBAR_PINOUT = 6;
const bool USING_SPACEBAR = true;
const bool SPACEBAR_EXT_RES = false;

// Buzzer Output:
const byte BUZZER_PINOUT = A15;
const bool USING_BUZZER = true;

// Battery Monitor:
const byte BATTERY_PINOUT = A0;
const bool USING_BATTERY = true;

// Driver Pinout:
const byte HVCLK = 8;
const byte HVLAT = 9;
const byte HVDAT = 10;
const bool USING_DRIVER = true;

// Debug
const bool USING_DEBUGGER = true;
