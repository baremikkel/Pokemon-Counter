#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 20, 4); // set the LCD address to 0x27 for a 16 chars and 2 line display

int aPin = A0;
const int buttonPin = 13;
int val = 0;
int intervalMin[] = {0, 201, 401, 601, 801};
int intervalMax[] = {200, 400, 600, 800, 1000};
int counterdex[] = {1, 5, 10, 100, 1000};

int  buttonState;
int lastButtonState = LOW;
int counter = 0;
int totalcount = 0;
unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 50;
void setup()
{
  lcd.init();                      // initialize the lcd
  pinMode(buttonPin, INPUT);
}

void loop()
{
  int reading = digitalRead(buttonPin);
  val = analogRead(aPin);
  for (int i = 0; i < 5; i++)
  {
    if (intervalMin[i] < val && val < intervalMax[i])
    {
      counter = counterdex[i];
    }
  }
    if (reading != lastButtonState)
      lastDebounceTime = millis();

    if ((millis() - lastDebounceTime) > debounceDelay)
    {
      if (reading != buttonState)
      {
        buttonState = reading;
        if (buttonState == HIGH)
        {
          Serial.println(counter);
          totalcount += counter;
        }
      }
    }
  lastButtonState = reading;
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Pokemon: ");
  lcd.print(totalcount);
  lcd.setCursor(0, 1);
  lcd.print("Counter: ");
  lcd.print(counter);
  delay(100);
  lcd.clear();
}
