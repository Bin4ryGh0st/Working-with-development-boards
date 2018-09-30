void setup() 
{
  pinMode(D0,OUTPUT);
  pinMode(D4,OUTPUT);  
}

void loop() 
{
    digitalWrite(D0,LOW);
    delay(500);
    digitalWrite(D0,HIGH);
    digitalWrite(D4,LOW);
    delay(500);
    digitalWrite(D4,HIGH);
}
