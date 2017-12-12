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

void keyUpEventHandler(Pinout pinout, KeyEventArgs e) {
  bool __flag__;
  for (int i = 0; i < 5; i++) __flag__ |= (KEYBOARD_BUFFER[i] != 0);
  if (USING_BRAILLE) for (int i = 0; i < 8; i++) __flag__ &= !BRAILLE_KEY[i].IsPressing;
  if (USING_COMMAND) for (int i = 0; i < 6; i++) __flag__ &= !COMMAND_KEY[i].IsPressing;
  if (USING_THUMB) for (int i = 0; i < 4; i++) __flag__ &= !THUMB_KEY[i].IsPressing;
  if (USING_CURSOR) for (int i = 0; i < 40; i++) __flag__ &= !CURSOR_KEY[i].IsPressing;
  if (USING_SPACEBAR) __flag__ &= !SPACEBAR_KEY.IsPressing;


  //Serial.println("flag : " + __flag__);
  if (__flag__) {
    //    Serial.write(KEYBOARD_BUFFER,5);
    //mapping(KEYBOARD_BUFFER);
    transmitKeyCode(KEYBOARD_BUFFER);
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

void loop() {
  if (USING_SPACEBAR) SPACEBAR_KEY.Activate();
  if (USING_BRAILLE) for (int i = 0; i < 8; i++) BRAILLE_KEY[i].Activate();
  if (USING_COMMAND) for (int i = 0; i < 6; i++) COMMAND_KEY[i].Activate();
  if (USING_THUMB) for (int i = 0; i < 4; i++) THUMB_KEY[i].Activate();
  if (USING_CURSOR) for (int i = 0; i < 40; i++) CURSOR_KEY[i].Activate();



  //  if (buff[0] != 0 || buff[1] != 0 || buff[2] != 0 || buff[3] != 0 || buff[4] != 0) {
  //    transmitKeyCode();
  //  }
  //serialEvent();

  if (NVDA_COUNTER >= 40) {
    DRIVER.Begin();
    for (int i = 0; i < 40; i++) {
      DRIVER.Write(NVDA_BUFFER[i]);
    }
    DRIVER.End();
    NVDA_COUNTER = 0;
  }

}

void serialEvent() {
  while (Serial.available()) {
    NVDA_BUFFER[NVDA_COUNTER] = (byte) Serial.read();
    NVDA_COUNTER++;
  }
}

void transmitKeyCode(byte *param) {

    if (param[0] == 0 && param[1] == 0 && param[2] == 0 && param[3] != 0 && param[4] == 0) {
    //    Serial.println("S");
    //    F_SpaceKey();
    }


  if (param[0] == 0 && param[1] == 0 && param[2] == 0 && param[3] != 0 && param[4] == 0) {
    //    Serial.println("S");
    //    F_SpaceKey();
    buff_write[0] = 0xFE;
    buff_write[1] = 0x03;
    buff_write[2] = 0x00;
    buff_write[3] = 0x00;
    buff_write[4] = 0x2C;
  }

  if (param[0] == 0 && param[1] == 0 && param[2] != 0 && param[3] == 0 && param[4] == 0) {
    //    Serial.println("CMD");
    //    F_CMDKey(param);
    if (param[2] == 0x06) {
      if (default_lang_index == 0) {
        default_lang_index = 2;
      }
      else {
        default_lang_index = 0;
      }
      buff_write[0] = 0xFE;
      buff_write[1] = 0x03;
      buff_write[2] = 0x00;
      buff_write[3] = 0x00;
      buff_write[4] = 0x35;
    } else {
            Serial.write(param, 5);
      buff_write[0] = 0xFE;
      buff_write[1] = 0x03;
      buff_write[2] = 0x00;
      buff_write[3] = 0x00;
  
      if (param[2] == 0x01) {
        buff_write[4] = 0x28;
      }
      else if (param[2] == 0x02) {
        buff_write[4] = 0x2A;
      }
      else if (param[2] == 0x03) {
        buff_write[4] = 0x4C;
      }
      else if (param[2] == 0x04) {
        buff_write[4] = 0x2B;
      }
      else if (param[2] == 0x05) {
        buff_write[4] = 0x39;
      }
      else if (param[2] == 0x07) {
        buff_write[4] = 0x29;
      }
      else if (param[2] == 0x08) {
        buff_write[4] = 0x49;
      }
      else if (param[2] == 0x09) {
        buff_write[4] = 0x4A;
      }
      else if (param[2] == 0x0A) {
        buff_write[4] = 0x4B;
      }
      else if (param[2] == 0x0B) {
        buff_write[4] = 0x4D;
      }
      else if (param[2] == 0x0C) {
        buff_write[4] = 0x4E;
      }
      else if (param[2] == 0x33) {
        buff_write[4] = 0x3A;
      }
      else if (param[2] == 0x34) {
        buff_write[4] = 0x3B;
      }
      else if (param[2] == 0x35) {
        buff_write[4] = 0x3C;
      }
      else if (param[2] == 0x36) {
        buff_write[4] = 0x3D;
      }
      else if (param[2] == 0x37) {
        buff_write[4] = 0x3E;
      }
      else if (param[2] == 0x38) {
        buff_write[4] = 0x3F;
      }
      else if (param[2] == 0x39) {
        buff_write[4] = 0x40;
      }
      else if (param[2] == 0x40) {
        buff_write[4] = 0x41;
      }
      else if (param[2] == 0x41) {
        buff_write[4] = 0x42;
      }
      else if (param[2] == 0x42) {
        buff_write[4] = 0x43;
      }
      else if (param[2] == 0x43) {
        buff_write[4] = 0x44;
      }
      else if (param[2] == 0x44) {
        buff_write[4] = 0x45;
      }
   
      //      buff_write[0] = 0xFE;
      //      buff_write[1] = 0x03;
      //      buff_write[2] = 0x00;
      //      buff_write[3] = 0x00;
      //      buff_write[4] = CMDKEY[param[2]][0];
    }
  }

  if (param[0] != 0) {
    //    Serial.println("B");
    //    F_BrailleKey(param);
    if (param[3] != 0) {
      //      Serial.println("ok");
      buff_write[0] = 0xFE;
      buff_write[1] = 0x03;
      buff_write[2] = SpaceKey[param[0]][0] ;
      buff_write[3] = SpaceKey[param[0]][1] ;
      buff_write[4] = SpaceKey[param[0]][2] ;
    } else {
      if (default_lang_index == 0) {
        buff_write[0] = 0xFE;
        buff_write[1] = 0x03;
        buff_write[2] = 0x00;
        buff_write[3] = BrailleKey[param[0]][0];
        buff_write[4] = BrailleKey[param[0]][1];
      } else {
        buff_write[0] = 0xFE;
        buff_write[1] = 0x03;
        buff_write[2] = 0x00;
        buff_write[3] = BrailleKey[param[0]][2];
        buff_write[4] = BrailleKey[param[0]][3];

      }
    }

  }
  Serial.write(buff_write, 5);
}















