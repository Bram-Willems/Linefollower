# Proof of concepts

Starten en stoppen van de robot moet ook met een fysieke monostabiele schakelaar op de robot kunnen. Deze schakelaar cyclisch gaan afvragen is geen goed idee. Dit kan enerzijds de timing van de rest van het programma in de war sturen en anderzijds riskeer je pulsen te missen. De schakelaar aan een externe interrupt van de microcontroller hangen en deze hardwarematig te bewaken is een stuk handiger.

Debouncen van de schakelaar kan je hard- of softwarematig doen. Of beide.


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
