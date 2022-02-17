#define SENSOR 0
#define ACTUATOR 23

void setup()
{
  Serial.begin(115200);
  pinMode(SENSOR, INPUT_PULLUP);
  pinMode(ACTUATOR, OUTPUT);
}

void loop()
{
  uint8_t dataFrame[2];

  if (Serial.available() > 1) {

    dataFrame[0] = Serial.read();
    dataFrame[1] = Serial.read();

    if (dataFrame[0] == 0x01) {
      Serial.write(digitalRead(SENSOR));
    }
    else if (dataFrame[0] == 0x02) {
      digitalWrite(ACTUATOR, dataFrame[1]);
    }

  }
}
