#include <Keyboard.h>

const int ledPin = 17;
const int pins[9] = { 2, 3, 4, 6, 7, 8, 15, 14, 16 };
const int values[9] = { KEY_F13, KEY_F14, KEY_F15, KEY_F16, KEY_F17, KEY_F18, KEY_F19, KEY_F20, KEY_F21 };

bool lastState[9];

void setup() {
  pinMode(ledPin, OUTPUT);
  for (int i = 0; i < 9; i++) {
    pinMode(pins[i], INPUT_PULLUP);
  }

  Keyboard.begin();
}

void loop() {
  for (int i = 0; i < 9; i++) {
    bool currentState = digitalRead(pins[i]);

    if (lastState[i] == HIGH && currentState == LOW) {
      Keyboard.press(KEY_LEFT_ALT);
      Keyboard.press(KEY_LEFT_CTRL);
      Keyboard.press(values[i]);

      delay(50);

      Keyboard.releaseAll();
    }

    lastState[i] = currentState;
  }
}
