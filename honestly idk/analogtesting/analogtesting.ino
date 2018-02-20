const int analogInPin = A0;
int sensorValue = 0;

void setup()
{
  // put your setup code here, to run once:
Serial.begin(115200);
}

void loop()
{
  // put your main code here, to run repeatedly:
sensorValue = analogRead(analogInPin);
Serial.println(sensorValue);
delay(100);
}
