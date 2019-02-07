void setup() {
  Serial.begin(9600);
}

void loop() 
{
  analogWrite(5, 100);
  Serial.println(analogRead(A6));
  delay(500);
  
}
