#include <Arduino.h>

#define MOISTURE A0
#define PUMP D5
#define LED D8

void setup()
{
  // OUTPUTs
  pinMode(LED, OUTPUT);
  pinMode(PUMP, OUTPUT);

  // INPUTs
  pinMode(MOISTURE, INPUT);

  Serial.begin(115200);
}

void loop()
{
  int dryness = map(analogRead(MOISTURE), 0, 1024, 0, 100);
  int isPumpOn = digitalRead(PUMP);

  Serial.print("Analog:");
  Serial.print(analogRead(MOISTURE));
  Serial.print(" | Percentage:");
  Serial.print(dryness);
  Serial.println("%");

  if (dryness >= 75)
  {
    //turn NO pump
    digitalWrite(LED, HIGH);
    digitalWrite(PUMP, HIGH);
    Serial.println("Turning ON water pump");
  }

  if (dryness <= 45 && isPumpOn)
  {
    //turn OFF pump
    digitalWrite(LED, LOW);
    digitalWrite(PUMP, LOW);
    Serial.println("Turning OFF water pump");
  }

  delay(1000);
}
