#ifndef THAIBRAILLE_H
#define THAIBRAILLE_H

#include "Arduino.h"
#include "thaiBraille-const.h"
#include "thaiBraille-pinout.h"
#include "thaiBraille-keydef.h"
#include "thaiBraille-keymap.h"
#include "thaiBraille-mapping.h"

class Pinout {
	public:
		// Properties
		byte Pin;
		byte Mode;
		String Tags[4];

		// Initializer
		Pinout() { };
		Pinout(byte pin, byte mode) { 
			Initialize(pin, mode);
		};

		// Methods
		void Initialize(byte pin, byte mode) {
			Pin = pin;
			Mode = mode;
			if (mode == INPUT || mode == INPUT_PULLUP || mode == OUTPUT) pinMode(pin, mode);
		};
};
class EventHandler {
	public:
		EventHandler() { };
};
class EventArgs {
	public:
		// Properties
		volatile unsigned long Timestamp;
};
class KeyEventHandler : public EventHandler {
	public:
		// Properties
		// ...

		// Initializer
		KeyEventHandler() { };
};
class KeyEventArgs : public EventArgs {
	
};
class Driver {
	public:
		// Properties
		Pinout ClockPin;
		Pinout LatchPin;
		Pinout DataPin;
		bool IsBegin;
		String Tags[4];
		
		// Initializer
		Driver() { };
		Driver(Pinout clock, Pinout latch, Pinout data) {
			Initialize(clock, latch, data);
		};
		
		// Methods
		void Initialize(Pinout clock, Pinout latch, Pinout data) {
			ClockPin = clock;
			LatchPin = latch;
			DataPin = data;
		};		
		void Begin() {
			digitalWrite(LatchPin.Pin, LOW);
			IsBegin = true;
		};
		void Write(byte data) {
			shiftOut(DataPin.Pin, ClockPin.Pin, MSBFIRST, _brailleRemapping(data));
		};
		void End() {
			digitalWrite(LatchPin.Pin, HIGH);
			digitalWrite(DataPin.Pin, HIGH);
			IsBegin = false;
		};
	private:
		byte _brailleRemapping(byte original) {
			byte result;
			for (int i = 0; i < 8; i++) bitWrite(result, i, bitRead(original, BRAILLE_MAPPING[i] - 1));
			return  255-result;  //0xff up
		}
};
class Key {
	public:
		// Properties
		Pinout Pin;
		String Tags[4];
		volatile bool IsPressing; // Reset automatically after release the key
		volatile bool IsMemorized; // Reset after call 'Clear' programmatically

		// Initializer
		Key() { };
		Key(Pinout pinout) {
			Initialize(pinout);
		};

		// Methods
		void Initialize(Pinout pinout) {
			Pin = pinout;
		};
		void Activate() {
			if (!digitalRead(Pin.Pin) && !IsPressing) {
				IsMemorized = true;
				IsPressing = true;
				KeyEventArgs e;
				e.Timestamp = millis();
				(*_onKeyDownEventHandler)(Pin, e);
			}
			else if (digitalRead(Pin.Pin) && IsPressing) {
				IsPressing = false;
				KeyEventArgs e;
				e.Timestamp = millis();
				(*_onKeyUpEventHandler)(Pin, e);
			}
		};
		void Clear() {
			IsMemorized = false;
			KeyEventArgs e;
			e.Timestamp = millis();
			(*_onClearEventHandler)(Pin, e);
		};

		// Handlers
		void OnKeyDown(void (*keyEventHandler)(Pinout, KeyEventArgs)) {
			_onKeyDownEventHandler = *keyEventHandler;
		};
		void OnKeyUp(void (*keyEventHandler)(Pinout, KeyEventArgs)) {
			_onKeyUpEventHandler = *keyEventHandler;
		};
		void OnClear(void (*keyEventHandler)(Pinout, KeyEventArgs)) {
			_onClearEventHandler = *keyEventHandler;
		};
	private:
		// Properties
		// ...
		
		// Handlers
		typedef void (*_keyEventHandler)(Pinout, KeyEventArgs);
		_keyEventHandler _onKeyDownEventHandler;
		_keyEventHandler _onKeyUpEventHandler;
		_keyEventHandler _onClearEventHandler;
};

#endif