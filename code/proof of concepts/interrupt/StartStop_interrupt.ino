#include <ezButton.h>
int LED = 2;

#define LOOP_STATE_STOPPED 0
#define LOOP_STATE_STARTED 1

ezButton button(3);  // create ezButton object that attach to pin 7;
int loopState = LOOP_STATE_STOPPED;

void setup() {
pinMode(LED, OUTPUT);

  button.setDebounceTime(50); // set debounce time to 50 milliseconds
}

void loop() {
  button.loop(); // MUST call the loop() function first

  if (button.isPressed()) {
    if (loopState == LOOP_STATE_STOPPED)
      loopState = LOOP_STATE_STARTED;
    else // if(loopState == LOOP_STATE_STARTED)
      loopState = LOOP_STATE_STOPPED;
      digitalWrite(LED, LOW);
  }

  if (loopState == LOOP_STATE_STARTED) {
    digitalWrite(LED, HIGH);
  }
}