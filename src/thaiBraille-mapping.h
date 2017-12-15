void _braille(byte *param,byte *buff_write,int &default_lang_index){
    //   if (default_lang_index == 0) {
    //     buff_write[0] = 0xFE;
    //     buff_write[1] = 0x03;
    //     buff_write[2] = 0x00;
    //     buff_write[3] = BrailleKey[param[0]][0];
    //     buff_write[4] = BrailleKey[param[0]][1];
    //   }else if(default_lang_index == 2){
    //     buff_write[0] = 0xFE;
    //     buff_write[1] = 0x03;
    //     buff_write[2] = 0x00;
    //     buff_write[3] = BrailleKey[param[0]][2];
    //     buff_write[4] = BrailleKey[param[0]][3];
	   // }

  if (param[0] == 0x08){
    if(default_lang_index == 0){
      default_lang_index = 2;
        buff_write[0] = 0xFE;
        buff_write[1] = 0x03;
        buff_write[2] = 0x00;
        buff_write[3] = BrailleKey[param[0]][0];
        buff_write[4] = BrailleKey[param[0]][1];
  }else if(default_lang_index == 2){

  }
    }else{
      if (default_lang_index == 0) {
        buff_write[0] = 0xFE;
        buff_write[1] = 0x03;
        buff_write[2] = 0x00;
        buff_write[3] = BrailleKey[param[0]][0];
        buff_write[4] = BrailleKey[param[0]][1];
      }else if(default_lang_index == 2){
        buff_write[0] = 0xFE;
        buff_write[1] = 0x03;
        buff_write[2] = 0x00;
        buff_write[3] = BrailleKey[param[0]][2];
        buff_write[4] = BrailleKey[param[0]][3];
     }  
    }
}

void _cmdkey(byte *param,byte *buff_write,int &default_lang_index){
		    if (param[2] == 0x06) {
      buff_write[4] = KEY_TILDE;
      if (default_lang_index == 0) {
        default_lang_index = 2;
      }
      else if (default_lang_index == 2) {
        default_lang_index = 0;
      }
    }

      if (param[2] == 0x01)      buff_write[4] = KEY_ENTER;
      else if (param[2] == 0x02) buff_write[4] = KEY_BACKSPACE;
      else if (param[2] == 0x03) buff_write[4] = KEY_DELETE;
      else if (param[2] == 0x04) buff_write[4] = KEY_TAB;
      else if (param[2] == 0x05) buff_write[4] = KEY_CAPS_LOCK;
      else if (param[2] == 0x07) buff_write[4] = KEY_ESC;
      else if (param[2] == 0x08) buff_write[4] = KEY_INSERT;
      else if (param[2] == 0x09) buff_write[4] = KEY_HOME;
      else if (param[2] == 0x0A) buff_write[4] = KEY_PAGE_UP;
      else if (param[2] == 0x0B) buff_write[4] = KEY_END;
      else if (param[2] == 0x0C) buff_write[4] = KEY_PAGE_DOWN;
      else if (param[2] == 0x33) buff_write[4] = KEY_F1;
      else if (param[2] == 0x34) buff_write[4] = KEY_F2;
      else if (param[2] == 0x35) buff_write[4] = KEY_F3;
      else if (param[2] == 0x36) buff_write[4] = KEY_F4;
      else if (param[2] == 0x37) buff_write[4] = KEY_F5;
      else if (param[2] == 0x38) buff_write[4] = KEY_F6;
      else if (param[2] == 0x39) buff_write[4] = KEY_F7;
      else if (param[2] == 0x40) buff_write[4] = KEY_F8;
      else if (param[2] == 0x41) buff_write[4] = KEY_F9;
      else if (param[2] == 0x42) buff_write[4] = KEY_F10;
      else if (param[2] == 0x43) buff_write[4] = KEY_F11;
      else if (param[2] == 0x44) buff_write[4] = KEY_F12;

      buff_write[0] = 0xFE;
      buff_write[1] = 0x03;
      buff_write[2] = 0x00;
      buff_write[3] = 0x00;
}

void _spacekey(byte *param,byte *buff_write){
    buff_write[0] = 0xFE;
    buff_write[1] = 0x03;
    buff_write[2] = SpaceKey[param[0]][0] ;
    buff_write[3] = SpaceKey[param[0]][1] ;
    buff_write[4] = SpaceKey[param[0]][2] ;
}

void _space(byte *buff_write){
    buff_write[0] = 0xFE;
    buff_write[1] = 0x03;
    buff_write[2] = 0x00;
    buff_write[3] = 0x00;
    buff_write[4] = 0x2C;
}

void _thumbkey(byte *param,byte *buff_write){
	buff_write[0] = 0xFE;
    buff_write[1] = 0x03;
    buff_write[2] = 0x00;
    buff_write[3] = 0x00;

    if (param[3] == 0x01)      buff_write[4] = KEY_UP;
    else if (param[3] == 0x08) buff_write[4] = KEY_DOWN;
    else if (param[3] == 0x02) buff_write[4] = KEY_LEFT;
    else if (param[3] == 0x04) buff_write[4] = KEY_RIGHT;
}