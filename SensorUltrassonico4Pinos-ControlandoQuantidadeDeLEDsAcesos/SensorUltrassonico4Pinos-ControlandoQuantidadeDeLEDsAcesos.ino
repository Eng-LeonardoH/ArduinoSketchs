long inches = 0;
long cm = 0;

int led1 = 10;
int led2 = 11;
int led3 = 12;
int led4 = 13;

int trigger = 7;
int echo = 6;

void setup()
{
  Serial.begin(9600);
  pinMode(led4, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led1, OUTPUT);
}

void loop()
{
  cm = 0.01723 * readUltrasonicTime(trigger, echo);
  inches = (cm / 2.54);
  Serial.print(inches);
  Serial.print(" polegadas e ");
  Serial.print(cm);
  Serial.println(" centimetros.");
  delay(100);
  
  // Controle dos LEDs com base na distância
  if (cm < 10) {
    digitalWrite(led1, HIGH); 
    digitalWrite(led2, LOW); 
    digitalWrite(led3, LOW); 
    digitalWrite(led4, LOW); 
  } else if (cm < 20) {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH); 
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
  } else if (cm < 30) {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
    digitalWrite(led4, LOW);
  } else if (cm < 40){
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
    digitalWrite(led4, HIGH); 
  }else{
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW); 
  }
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
