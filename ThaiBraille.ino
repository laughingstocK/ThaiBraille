#include "src/thaiBraille.h"

Key BRAILLE_KEY[8];
Key COMMAND_KEY[6];
Key THUMB_KEY[4];
Key CURSOR_KEY[40];
Key SPACEBAR_KEY;
Driver DRIVER;
byte buff[5] ;
byte buff_write[5];

byte KEYBOARD_BUFFER[5] ;
byte NVDA_COUNTER = 0;
byte NVDA_BUFFER[40];
int default_lang_index = 0;

void setup() {

  if (USING_BRAILLE) {
    for (int i = 0; i < 8; i++) {
      Pinout __pinout__(BRAILLE_PINOUT[i], BRAILLE_EXT_RES ? INPUT : INPUT_PULLUP);
      __pinout__.Tags[0] = "BRAILLE";
      __pinout__.Tags[1] = String(i + 1);
      BRAILLE_KEY[i].Initialize(__pinout__);
      BRAILLE_KEY[i].OnKeyDown(keyDownEventHandler);
      BRAILLE_KEY[i].OnKeyUp(keyUpEventHandler);
      BRAILLE_KEY[i].OnClear(clearEventHandler);
    }
  }
  if (USING_COMMAND) {
    for (int i = 0; i < 6; i++) {
      Pinout __pinout__(COMMAND_PINOUT[i], COMMAND_EXT_RES ? INPUT : INPUT_PULLUP);
      __pinout__.Tags[0] = "COMMAND";
      __pinout__.Tags[1] = String(i + 1);
      COMMAND_KEY[i].Initialize(__pinout__);
      COMMAND_KEY[i].OnKeyDown(keyDownEventHandler);
      COMMAND_KEY[i].OnKeyUp(keyUpEventHandler);
      COMMAND_KEY[i].OnClear(clearEventHandler);
    }
  }
  if (USING_THUMB) {
    String order[4] = { "UP", "LEFT", "RIGHT", "DOWN" };
    for (int i = 0; i < 4; i++) {
      Pinout __pinout__(THUMB_PINOUT[i], THUMB_EXT_RES ? INPUT : INPUT_PULLUP);
      __pinout__.Tags[0] = "THUMB";
      __pinout__.Tags[1] = order[i];
      THUMB_KEY[i].Initialize(__pinout__);
      THUMB_KEY[i].OnKeyDown(keyDownEventHandler);
      THUMB_KEY[i].OnKeyUp(keyUpEventHandler);
      THUMB_KEY[i].OnClear(clearEventHandler);
    }
  }
  if (USING_CURSOR) {
    for (int i = 0; i < 40; i++) {
      Pinout __pinout__(CURSOR_PINOUT[i], CURSOR_EXT_RES ? INPUT : INPUT_PULLUP);
      __pinout__.Tags[0] = "CURSOR";
      __pinout__.Tags[1] = String(i + 1);
      CURSOR_KEY[i].Initialize(__pinout__);
      CURSOR_KEY[i].OnKeyDown(keyDownEventHandler);
      CURSOR_KEY[i].OnKeyUp(keyUpEventHandler);
      CURSOR_KEY[i].OnClear(clearEventHandler);
    }
  }
  if (USING_SPACEBAR) {
    Pinout __pinout__(SPACEBAR_PINOUT, SPACEBAR_EXT_RES ? INPUT : INPUT_PULLUP);
    __pinout__.Tags[0] = "SPACEBAR";
    SPACEBAR_KEY.Initialize(__pinout__);
    SPACEBAR_KEY.OnKeyDown(keyDownEventHandler);
    SPACEBAR_KEY.OnKeyUp(keyUpEventHandler);
    SPACEBAR_KEY.OnClear(clearEventHandler);
  }
  if (USING_DRIVER) {
    Pinout clockPin(HVCLK, OUTPUT);
    Pinout latchPin(HVLAT, OUTPUT);
    Pinout dataPin(HVDAT, OUTPUT);
    DRIVER.Initialize(clockPin, latchPin, dataPin);
  }
  if (USING_BUZZER) {
    pinMode(BUZZER_PINOUT, OUTPUT);
    digitalWrite(BUZZER_PINOUT, HIGH);
  }
  Serial.begin(38400);
}

//------------------------------ Pressing key and memorized --------------------------------------------//

void keyDownEventHandler(Pinout pinout, KeyEventArgs e) {
  if (pinout.Tags[0] == "BRAILLE" && USING_BRAILLE) {
    byte __sum__ = 0;
    for (int i = 0; i < 8; i++) {
      __sum__ += BRAILLE_KEY[i].IsMemorized * (1 << i);
    }
    KEYBOARD_BUFFER[0] = __sum__;
  }
  if (pinout.Tags[0] == "SPACEBAR" && USING_SPACEBAR) {
    KEYBOARD_BUFFER[1] = (byte) SPACEBAR_KEY.IsMemorized;
  }
  if (pinout.Tags[0] == "COMMAND" && USING_COMMAND) {
    byte __sum__ = 0;
    for (int i = 0; i < 6; i++) {
      __sum__ += COMMAND_KEY[i].IsMemorized * (1 << i);
    }
    KEYBOARD_BUFFER[2] = __sum__;
  }
  if (pinout.Tags[0] == "THUMB" && USING_THUMB) {
    byte __sum__ = 0;
    for (int i = 0; i < 4; i++) {
      __sum__ += THUMB_KEY[i].IsMemorized * (1 << i);
    }
    KEYBOARD_BUFFER[3] = __sum__;
  }
  if (pinout.Tags[0] == "CURSOR" && USING_CURSOR) {
    KEYBOARD_BUFFER[4] = byte(pinout.Tags[1].toInt());
  }
}

void clearEventHandler() {

}

//------------- Check pressing key and transmit value and clear value memorized ---------------------//


void keyUpEventHandler(Pinout pinout, KeyEventArgs e) {
  bool __flag__;
  for (int i = 0; i < 5; i++) __flag__ |= (KEYBOARD_BUFFER[i] != 0);
  if (USING_BRAILLE) for (int i = 0; i < 8; i++) __flag__ &= !BRAILLE_KEY[i].IsPressing;
  if (USING_COMMAND) for (int i = 0; i < 6; i++) __flag__ &= !COMMAND_KEY[i].IsPressing;
  if (USING_THUMB) for (int i = 0; i < 4; i++) __flag__ &= !THUMB_KEY[i].IsPressing;
  if (USING_CURSOR) for (int i = 0; i < 40; i++) __flag__ &= !CURSOR_KEY[i].IsPressing;
  if (USING_SPACEBAR) __flag__ &= !SPACEBAR_KEY.IsPressing;

  if (__flag__) {
    transmitKeyCode(KEYBOARD_BUFFER);
    for (int i = 0; i < 5; i++) KEYBOARD_BUFFER[i] = 0;
    if (USING_BRAILLE) for (int i = 0; i < 8; i++) BRAILLE_KEY[i].Clear();
    if (USING_COMMAND) for (int i = 0; i < 6; i++) COMMAND_KEY[i].Clear();
    if (USING_THUMB) for (int i = 0; i < 4; i++) THUMB_KEY[i].Clear();
    if (USING_CURSOR) for (int i = 0; i < 40; i++) CURSOR_KEY[i].Clear();
    if (USING_SPACEBAR) SPACEBAR_KEY.Clear();
  }
}

void loop() {

  if (USING_SPACEBAR) SPACEBAR_KEY.Activate();
  if (USING_BRAILLE) for (int i = 0; i < 8; i++) BRAILLE_KEY[i].Activate();
  if (USING_COMMAND) for (int i = 0; i < 6; i++) COMMAND_KEY[i].Activate();
  if (USING_THUMB) for (int i = 0; i < 4; i++) THUMB_KEY[i].Activate();
  if (USING_CURSOR) for (int i = 0; i < 40; i++) CURSOR_KEY[i].Activate();

  serialEvent();
  displayNvda();

}

//------------- Read value from serial to display -------------//
int start_byte = 0;
int start_len = 0;
int start_end = 0;
void serialEvent() {
  while (Serial.available()) {
    byte d = (byte) Serial.read();
    if (d == 0xff && start_byte==0) {
      start_byte = 1;
     // Serial.write("start read");
    } else if (start_byte == 1 && start_len == 0) {
      start_len = 40;
       //Serial.write("start lan");

    } else if (start_byte == 1 && start_len == 40 && start_end == 0) {
    //  Serial.write("get byte");
      NVDA_BUFFER[NVDA_COUNTER] = d;
      NVDA_COUNTER++;
      if (start_len == NVDA_COUNTER) {
        start_end = 1;
        // Serial.write("end byte");
      }
    }
  }
}

//----------- Drive to display -----------//

void displayNvda() {
  if (start_end == 1) {
    DRIVER.Begin();
    for (int i = 0; i < 40; i++) {
      DRIVER.Write(NVDA_BUFFER[i]);
    }
    DRIVER.End();
    NVDA_COUNTER = 0;
    start_byte = 0;
    start_len = 0;
    start_end = 0;
  }
}

//------- Mapping pressed key and convert value to HID Keyboard value and send --------//

void transmitKeyCode(byte *param) {
  if (param[0] != 0 && param[1] == 0 && param[2] == 0 && param[3] == 0 && param[4] == 0  ) { //Braille Key
    _braille(param, buff_write, default_lang_index);
  }

  else if (param[0] == 0 && param[1] != 0 && param[2] == 0 && param[3] == 0 && param[4] == 0 ) { // Space
    _space(buff_write);
  }

  else if (param[0] != 0 && param[1] != 0 && param[2] == 0 && param[3] == 0 && param[4] == 0 ) { // Space key
    _spacekey(param, buff_write);
  }

  else if (param[0] == 0 && param[1] == 0 && param[2] != 0 && param[3] == 0 && param[4] == 0 ) { // Cmd Key
    _cmdkey(param, buff_write, default_lang_index);
  }

  else if (param[0] == 0 && param[1] == 0 && param[2] == 0 && param[3] != 0 && param[4] == 0 ) { // Thumb Key
    _thumbkey(param, buff_write);
  }
  else if (param[0] == 0 && param[1] == 0 && param[2] == 0 && param[3] == 0 && param[4] != 0 ) { // Cursor Key

  }

  Serial.write(buff_write, 5);
}



