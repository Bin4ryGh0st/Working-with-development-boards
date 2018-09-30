int sensorValue,sensorMax=0,sensorMin=1023,sensorAverage;
void sensorCalibrate()
{
  Serial.println("Calibrating...");
  for(int i=1;i<=1000;i++)
  {
    sensorValue=analogRead(A0);
    if(sensorValue>=sensorMax)
    {
      sensorMax=sensorValue;
    }
    else
    {
      sensorMin=sensorValue;
    }
    delay(10);
  }
  sensorAverage=(sensorMax+sensorMin)/2;
  Serial.println(sensorAverage);
  delay(2000);
}
void setup() 
{
  Serial.begin(9600);
  pinMode(A0,INPUT);
  pinMode(13,OUTPUT);
  sensorCalibrate();
}
void loop() 
{
  sensorValue=analogRead(A0);
  if(sensorValue<=sensorAverage)
  {
    Serial.println("white");
    digitalWrite(13,HIGH);
  }
  else
  {
    Serial.println("Black");
    digitalWrite(13,LOW);
  }
} 


