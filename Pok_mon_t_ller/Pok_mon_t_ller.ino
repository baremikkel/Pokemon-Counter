#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// constants won't change. They're used here to set pin numbers:
const int buttonPin1 = 8;    // the number of the pushbutton pin
const int buttonPin2 = 9;      // the number of the LED pin
const int buttonPin3 = 10;
const int buttonPin4 = 7;

// Variables will change:
int ledState = HIGH;         // the current state of the output pin
int buttonState1;
int buttonState2;
int buttonState3;              // the current reading from the input pin
int buttonState4;
int lastButtonState1 = LOW;   // the previous reading from the input pin
int lastButtonState2 = LOW;
int lastButtonState3 = LOW;
int lastButtonState4 = LOW;

int k = 0;
// the following variables are unsigned longs because the time, measured in
// milliseconds, will quickly become a bigger number than can be stored in an int.
unsigned long lastDebounceTime = 0;  // the last time the output pin was toggled
unsigned long debounceDelay = 50;    // the debounce time; increase if the output flickers

void setup() {
  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);
  pinMode(buttonPin3, INPUT);
  pinMode(buttonPin4, INPUT);

  lcd.begin(16, 2);

  // set initial LED state
//  digitalWrite(ledPin, ledState);
}

void loop() {
  // read the state of the switch into a local variable:
  int reading1 = digitalRead(buttonPin1);
  int reading2 = digitalRead(buttonPin2);
  int reading3 = digitalRead(buttonPin3);
  int reading4 = digitalRead(buttonPin4);

  // If the switch changed, due to noise or pressing:
  if (reading1 != lastButtonState1) {
    // reset the debouncing timer
    lastDebounceTime = millis();
  }
  if (reading2 != lastButtonState2) {
    // reset the debouncing timer
    lastDebounceTime = millis();
  }
  if (reading3 != lastButtonState3) {
    // reset the debouncing timer
    lastDebounceTime = millis();
  }
  if (reading4 != lastButtonState4) {
    // reset the debouncing timer
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    // whatever the reading is at, it's been there for longer than the debounce
    // delay, so take it as the actual current state:

    // if the button state has changed:
    if (reading1 != buttonState1) {
      buttonState1 = reading1;

      // only toggle the LED if the new button state is HIGH
      if (buttonState1 == HIGH) {
        k = k + 100;
        lcd.clear();
        lcd.print("Pokemons: ");
        lcd.print(k);
      }
    }
    if (reading2 != buttonState2) {
      buttonState2 = reading2;
      
      if (buttonState2 == HIGH) {
        k = k + 10;
        lcd.clear();
        lcd.print("Pokemons: ");
        lcd.print(k);
      }

    }
    if (reading3 != buttonState3) {
      buttonState3 = reading3;
      
      if (buttonState3 == HIGH) {
        k = k + 5;
        lcd.clear();
        lcd.print("Pokemons: ");
        lcd.print(k);
      }

    }
    if (reading4 != buttonState4) {
      buttonState4 = reading4;
      
      if (buttonState4 == HIGH) {
        k = k + 1;
        lcd.clear();
        lcd.print("Pokemons: ");
        lcd.print(k);
      }

    }
  }

  // set the LED:
//  digitalWrite(ledPin, ledState);

  // save the reading. Next time through the loop, it'll be the lastButtonState:
  lastButtonState1 = reading1;
  lastButtonState2 = reading2;
  lastButtonState3 = reading3;
  lastButtonState4 = reading4;
}
