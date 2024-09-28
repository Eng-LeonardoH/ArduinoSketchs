long inches = 0;
long cm = 0;

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  cm = 0.01723 * readUltrasonicTime(6, 7);
  inches = (cm / 2.54);
  Serial.print(inches);
  Serial.print(" polegadas e ");
  Serial.print(cm);
  Serial.println(" centimetros.");
  delay(100);
}
long readUltrasonicTime(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  return pulseIn(echoPin, HIGH);
}