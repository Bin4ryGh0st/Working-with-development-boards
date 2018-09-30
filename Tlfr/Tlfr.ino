/*
 * 
Black : 0;
White : 1;
*/
int i,j,sensorValue[4],sensorMax[4]={0},sensorMin[4]={1023},sensorAverage[4]={0},s[4];
/*---------------------------------------*/
void turnRight()
{
  analogWrite(3,0);               /*Moves Right*/
  analogWrite(5,175);
  analogWrite(6,0);
  analogWrite(9,0);
}
/*---------------------------------------*/
void turnLeft()
{
  analogWrite(6,0);               /*Moves Left*/
  analogWrite(9,175);
  analogWrite(3,0);
  analogWrite(5,0);  
}
/*---------------------------------------*/
void moveStraight()
{
  analogWrite(3,0);               /*Moves Straight*/
  analogWrite(5,220);
  analogWrite(6,0);               
  analogWrite(9,220);  
}
/*---------------------------------------*/
void stopIt()
{
  analogWrite(3,0);               /*Stops*/
  analogWrite(5,0);
  analogWrite(6,0);               
  analogWrite(9,0);
}
/*-----------------------------------*/
void fullTurn()
{
  analogWrite(3,0);               /*full turn*/
  analogWrite(5,255);
  analogWrite(6,255);               
  analogWrite(9,0);
}
/*------------------------------------*/
void reverse()
{
  analogWrite(3,220);               /*Moves Back*/
  analogWrite(5,0);
  analogWrite(6,220);               
  analogWrite(9,0);   
}
/*------------------------------------*/
void twistRight()
{
  analogWrite(3,0);               /*Twist Right*/
  analogWrite(5,120);
  analogWrite(6,120);
  analogWrite(9,0);   
}
/*------------------------------------*/
void twistLeft()
{
   analogWrite(6,0);               /*Twists Left*/
   analogWrite(9,120);
   analogWrite(3,120);
   analogWrite(5,0); 
}
/*------------------------------------*/
void sensorCalibrate()
{
  //Serial.println("Calibrating...");
  /*---------------------------------------*/  
  for(i=1;i<=1000;i++)
  {
    if(i<250)
    {
      twistRight();
    }
    else if(i>=250 && i<500)
    {
      twistLeft();
    }
    else if(i>=500 && i<750)
    {
      twistRight();
    }
    else
    {
      twistLeft(); 
    }
    sensorValue[0]=analogRead(A0);
    if(sensorValue[0]>=sensorMax[0])
    {
      sensorMax[0]=sensorValue[0];
    }
    if(sensorValue[0]<=sensorMin[0])
    {
      sensorMin[0]=sensorValue[0];
    }
    /*---------------------------------------*/    
    sensorValue[1]=analogRead(A1);
    if(sensorValue[1]>=sensorMax[1])
    {
      sensorMax[1]=sensorValue[1];
    }
    if(sensorValue[1]<=sensorMin[1])
    {
      sensorMin[1]=sensorValue[1];
    }
    /*---------------------------------------*/    
    sensorValue[2]=analogRead(A2);
    if(sensorValue[2]>=sensorMax[2])
    {
      sensorMax[2]=sensorValue[2];
    }
    if(sensorValue[2]<=sensorMin[2])
    {
      sensorMin[2]=sensorValue[2];
    }
    /*---------------------------------------*/        
    sensorValue[3]=analogRead(A3);
    if(sensorValue[3]>=sensorMax[3])
    {
      sensorMax[3]=sensorValue[3];
    }
    if(sensorValue[3]<=sensorMin[3])
    {
      sensorMin[3]=sensorValue[3];
    }
    /*---------------------------------------*/ 
    delay(3);
  }
  sensorAverage[0]=(sensorMax[0]+sensorMin[0])/2;
  sensorAverage[1]=(sensorMax[1]+sensorMin[1])/2;
  sensorAverage[2]=(sensorMax[2]+sensorMin[2])/2;
  sensorAverage[3]=(sensorMax[3]+sensorMin[3])/2;
  twistRight();
}
/*---------------------------------------*/
void whiteCondn()
{
  analogWrite(3,0);               /*Moves Straight*/
  analogWrite(5,170);
  analogWrite(6,0);               
  analogWrite(9,170); 
}
/*---------------------------------------*/
void sAssign()
{
  sensorValue[0]=analogRead(A0);
  sensorValue[1]=analogRead(A1);
  sensorValue[2]=analogRead(A2);
  sensorValue[3]=analogRead(A3);
  s[0]=(sensorValue[0]<=sensorAverage[0]);
  s[1]=(sensorValue[1]<=sensorAverage[1]);  
  s[2]=(sensorValue[2]<=sensorAverage[2]);    
  s[3]=(sensorValue[3]<=sensorAverage[3]);
}
/*---------------------------------------*/

void setup() 
{
  Serial.begin(9600);
  pinMode(A0,INPUT);
  pinMode(A1,INPUT);
  pinMode(A2,INPUT);
  pinMode(A3,INPUT);
  pinMode(3,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(9,OUTPUT);
  sensorCalibrate();
}

void loop() 
{
  sAssign();
  if(s[0]==0 && s[1]==1 && s[2]==0)
  {
     moveStraight();
  }
  else if(s[2]==1)
  {
     twistLeft();
  }
  else if(s[3]==1)
  {
      moveStraight();
  }
  else if(s[0]==1)
  {
      twistRight();
  }
  else if(s[3]==0)
  {
      moveStraight();
      delay(50);
      twistLeft();
  }
  /*
  Serial.println();
  Serial.print("    ");
  Serial.print(sensorValue[3]);
  Serial.println(" ");
  Serial.print(sensorValue[2]);
  Serial.print(" ");
  Serial.print(sensorValue[1]);
  Serial.print(" ");
  Serial.print(sensorValue[0]);
  Serial.println();
  delay(1000);
  */
} 


