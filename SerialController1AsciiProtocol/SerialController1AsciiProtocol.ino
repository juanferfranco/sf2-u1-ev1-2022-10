#define SENSOR 33 // 33 controller 1, 0 controller 2
#define ACTUATOR 25 // 25 controller, 23 controller 2

void setup()
{
  Serial.begin(115200);
  pinMode(SENSOR, INPUT_PULLUP);
  pinMode(ACTUATOR, OUTPUT);
}

void loop()
{

  if (Serial.available() > 0) {

    String dataRx = Serial.readStringUntil('\n');
    if (dataRx == "r") {
      Serial.print(digitalRead(SENSOR));
      Serial.print('\n');
    }
    else if (dataRx == "1") {
      digitalWrite(ACTUATOR, 1);
    }
    else if ( dataRx == "0") {
      digitalWrite(ACTUATOR, 0);
    }
  }
}
