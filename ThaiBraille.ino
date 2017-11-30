#include "src/thaiBraille.h"

Key BRAILLE_KEY[8];
Key COMMAND_KEY[6];
Key THUMB_KEY[4];
Key CURSOR_KEY[40];
Key SPACEBAR_KEY;
Driver DRIVER;
byte buff[5];

byte KEYBOARD_BUFFER[5] = { 0, 0, 0, 0, 0 };
byte NVDA_COUNTER = 0;
byte NVDA_BUFFER[40];
int default_lang_index = 0;

uint8_t BT_buf[8] = {
  0
};

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

void keyDownEventHandler(Pinout pinout, KeyEventArgs e) {
  if (pinout.Tags[0] == "BRAILLE" && USING_BRAILLE) {
    byte __sum__ = 0;
    for (int i = 0; i < 8; i++) {
      __sum__ += BRAILLE_KEY[i].IsMemorized * (1 << i);
    }
    KEYBOARD_BUFFER[0] = __sum__;
  }
  if (pinout.Tags[0] == "COMMAND" && USING_COMMAND) {
    byte __sum__ = 0;
    for (int i = 0; i < 6; i++) {
      __sum__ += COMMAND_KEY[i].IsMemorized * (1 << i);
    }
    KEYBOARD_BUFFER[1] = __sum__;
  }
  if (pinout.Tags[0] == "THUMB" && USING_THUMB) {
    byte __sum__ = 0;
    for (int i = 0; i < 4; i++) {
      __sum__ += THUMB_KEY[i].IsMemorized * (1 << i);
    }
    KEYBOARD_BUFFER[2] = __sum__;
  }
  if (pinout.Tags[0] == "CURSOR" && USING_CURSOR) {
    KEYBOARD_BUFFER[3] = byte(pinout.Tags[1].toInt());
  }
  if (pinout.Tags[0] == "SPACEBAR" && USING_SPACEBAR) {
    KEYBOARD_BUFFER[4] = (byte) SPACEBAR_KEY.IsMemorized;
  }
}

void keyUpEventHandler(Pinout pinout, KeyEventArgs e) {
  bool __flag__;
  for (int i = 0; i < 5; i++) __flag__ |= (KEYBOARD_BUFFER[i] != 0);
  if (USING_BRAILLE) for (int i = 0; i < 8; i++) __flag__ &= !BRAILLE_KEY[i].IsPressing;
  if (USING_COMMAND) for (int i = 0; i < 6; i++) __flag__ &= !COMMAND_KEY[i].IsPressing;
  if (USING_THUMB) for (int i = 0; i = 4; i++) __flag__ &= !THUMB_KEY[i].IsPressing;
  if (USING_CURSOR) for (int i = 0; i < 40; i++) __flag__ &= !CURSOR_KEY[i].IsPressing;
  if (USING_SPACEBAR) __flag__ &= !SPACEBAR_KEY.IsPressing;

  if (__flag__) {
    transmitKeyCode();
    for (int i = 0; i < 5; i++) KEYBOARD_BUFFER[i] = 0;
    if (USING_BRAILLE) for (int i = 0; i < 8; i++) BRAILLE_KEY[i].Clear();
    if (USING_COMMAND) for (int i = 0; i < 6; i++) COMMAND_KEY[i].Clear();
    if (USING_THUMB) for (int i = 0; i < 4; i++) THUMB_KEY[i].Clear();
    if (USING_CURSOR) for (int i = 0; i < 40; i++) CURSOR_KEY[i].Clear();
    if (USING_SPACEBAR) SPACEBAR_KEY.Clear();
  }
}

void clearEventHandler(Pinout pinout, KeyEventArgs e) {
  
}

void F_BrailleKey() {
  //Serial.println("Braille Key");
  if (buff[1] != 0) { //Braille Data 2 Byte
    Serial.println("Braille Key111");
    for (int i = 0; i < 19; i++) {
      if (buff[0] == BrialleKey2Byte[i][0] && buff[1] == BrialleKey2Byte[i][1] ) {
        BT_buf[0] = 0xFE;
        BT_buf[1] = 0x03;
        BT_buf[2] = BrialleKey2Byte[i][2];
        BT_buf[3] =  0x00;
        BT_buf[4] =  BrialleKey2Byte[i][3];
        Serial1.write(BT_buf, 5);
        Serial.write(BT_buf, 5);
        Serial.println("Braille Key1");
        //releaseKey();
      }
    }
  }
  else {
    int key_index = buff[0];
    //Serial.println("Braille Key1");
    BT_buf[0] = 0xFE;
    BT_buf[1] = 0x03;
    BT_buf[2] = BrailleKey[key_index][default_lang_index];
    BT_buf[3] =  0x00;
    BT_buf[4] =  BrailleKey[key_index][default_lang_index + 1];
    Serial1.write(BT_buf, 5);
    Serial.write(BT_buf, 5);
    //Serial.println("Braille Key2");
    //releaseKey();
  }
}

void F_CMDKey() {
  if (CMDKEY[KEYBOARD_BUFFER[2]][0] == KEY_TILDE || CMDKEY[KEYBOARD_BUFFER[2]][0] == KEY_CAPS_LOCK) { //CT Lang (Com)
    if (default_lang_index == 0) {
      default_lang_index = 2;
      Serial.println("Change KB Thai");
    }
    else {
      default_lang_index = 0;
      Serial.println("Change KB Eng");
    }
    int key_index = KEYBOARD_BUFFER[2];
    BT_buf[0] = 0xFE;
    BT_buf[1] = 0x03;
    BT_buf[2] = 0x00;
    BT_buf[3] =  0x00;
    BT_buf[4] =  CMDKEY[key_index][0];
    Serial1.write(BT_buf, 5);
    Serial.write(BT_buf, 5);
    //releaseKey();
  }
  else {
    int key_index = KEYBOARD_BUFFER[2];
    BT_buf[0] = 0xFE;
    BT_buf[1] = 0x03;
    BT_buf[2] = 0x00;
    BT_buf[3] =  0x00;
    BT_buf[4] =  CMDKEY[key_index][0];
    Serial1.write(BT_buf, 5);
    Serial.write(BT_buf, 5);
    //releaseKey();
  }
}
void F_SpaceKey() {
  int key_index = KEYBOARD_BUFFER[0];
  BT_buf[0] = 0xFE;
  BT_buf[1] = 0x03;
  BT_buf[2] = SpaceKey[key_index][0];
  BT_buf[3] =  SpaceKey[key_index][1];
  BT_buf[4] =  SpaceKey[key_index][2];
  Serial1.write(BT_buf, 5);
  Serial.write(BT_buf, 5);
  //releaseKey();
}

void F_ArrowKey() {
  int key_index = KEYBOARD_BUFFER[4];
  BT_buf[0] = 0xFE;
  BT_buf[1] = 0x03;
  BT_buf[2] = 0x00;
  BT_buf[3] =  0x00;
  BT_buf[4] =  ArrowKey[key_index];
  Serial1.write(BT_buf, 5);
  Serial.write(BT_buf, 5);
  //releaseKey();
}

void loop() {
  if (USING_BRAILLE) for (int i = 0; i < 8; i++) BRAILLE_KEY[i].Activate();
  if (USING_COMMAND) for (int i = 0; i < 6; i++) COMMAND_KEY[i].Activate();
  if (USING_THUMB) for (int i = 0; i < 4; i++) THUMB_KEY[i].Activate();
  if (USING_CURSOR) for (int i = 0; i < 40; i++) CURSOR_KEY[i].Activate();
  if (USING_SPACEBAR) SPACEBAR_KEY.Activate();

  if (NVDA_COUNTER >= 40) {
    DRIVER.Begin();
    for (int i = 0; i < 40; i++) {
      DRIVER.Write(NVDA_BUFFER[i]);
    }
    DRIVER.End();
    NVDA_COUNTER = 0;
  }


    buff[0] = KEYBOARD_BUFFER[0]; // Braille[0]
    buff[1] = 0x00; // Braille[1], in case of Thai
    buff[2] = KEYBOARD_BUFFER[1]; // Command byte
    buff[3] = 0x00; // Space byte
    buff[4] = KEYBOARD_BUFFER[2]; // Thumb byte
    //Send data through serial port


    if (buff[0] != 0 && buff[2] == 0 && buff[3] == 0 && buff[4] == 0 ) { //Braille Key
      //Serial.println("Braille Key");
      F_BrailleKey();
     }
     else if (buff[0] == 0 && buff[1] == 0 && buff[2] != 0 && buff[3] == 0 && buff[4] == 0 ) { // Cmd Key
       //Serial.println("Cmd Key");
       F_CMDKey();
     }
     else if (buff[0] != 0 && buff[1] == 0 && buff[2] == 0 && buff[3] != 0 && buff[4] == 0 ) { // Space Key
       Serial.println("Space Key");
       F_SpaceKey();
     }
     else if (buff[0] == 0 && buff[1] == 0 && buff[2] == 0 && buff[3] == 0 && buff[4] != 0 ) { // Arrow Key
       //Serial.println("Arrow Key");
       F_ArrowKey();
     }

  //Serial.write(KEYBOARD_BUFFER, 5);
  //delay(2000);
}

void serialEvent() {
  while (Serial.available()) {
    NVDA_BUFFER[NVDA_COUNTER] = (byte) Serial.read();
    NVDA_COUNTER++;
  }
}

void transmitKeyCode() {
  byte __buffer__[5];
  
  // Serial.write(???, 5);
}
