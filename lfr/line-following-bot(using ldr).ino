/* 
0 is Black
1 is White
Maze Solver
Primus
*/
int storeCounter = 0;

int storeFlag = 0;

int s[5]={0};

char path[1000];
void setup()
{
  Serial.begin(9600);
  pinMode(7,INPUT);
  pinMode(8,INPUT);
  pinMode(10,INPUT);
  pinMode(11,INPUT);
  pinMode(12,INPUT);
  pinMode(3,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(13,OUTPUT);
}

void loop() 
{
  sensorRead(); 
  if(isStraight())
  {
      moveStraight();
  }  
  else if(s[0]==0 && s[1]==1 && s[3]==0 && s[4]==0)
  {
      turnLeftS();
  }               
  else if(s[0]==0 && s[1]==0 && s[3]==1 && s[4]==0)
  {
      turnRightS();
  }    
  else if(s[0]==1)
  {
      turnLeftF();
  }
  else if(s[3]==1 && s[4]==1)
  {
      moveStraight();
      delay(500);
      sensorRead();
      if(isStraight())
      {
          moveStraight();
      }
      else if(allBlack())
      {
          moveBack();
          delay(500);
          turnRightF();
          delay(150);
      }
  }
  else if(allWhite())
  {
      moveStraight();
      delay(200);
      if(allWhite())
      {
        stopEnd(); 
      }
  }                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                 
}
void sensorRead()
{
    s[0]=digitalRead(7);
    s[1]=digitalRead(8);
    s[2]=digitalRead(10);
    s[3]=digitalRead(11);
    s[4]=digitalRead(12);
}   
void turnLeftS()
{
    analogWrite(9,0);
    analogWrite(3,125);
    analogWrite(5,125);
    analogWrite(6,0);  
  
}
void turnRightS()
{
    analogWrite(9,125);
    analogWrite(3,0);
    analogWrite(5,0);
    analogWrite(6,125);
}
void turnLeftF()
{
    analogWrite(9,0);
    analogWrite(3,200);
    analogWrite(5,200);
    analogWrite(6,0);
} 
void turnRightF()
{
    analogWrite(9,200);
    analogWrite(3,0);
    analogWrite(5,0);
    analogWrite(6,200);
}
void moveStraight()
{
    analogWrite(9,200);
    analogWrite(3,0);
    analogWrite(5,200);
    analogWrite(6,0);
}

void stopEnd()
{
    analogWrite(9,0);
    analogWrite(3,0);
    analogWrite(5,0);
    analogWrite(6,0);
}
void moveBack()
{
    moveStraight();
    delay(500);
    turnLeftF();
}

bool allWhite()
{
  sensorRead();
  if(s[0]==1 && s[1]==1 && s[2]==1 && s[3]==1 && s[4]==1)  
  {
    return 1;  
  }
  else
  {
    return 0;  
  }
}

bool allBlack()
{
  sensorRead();
  if(s[0]==0 && s[1]==0 && s[2]==0 && s[3]==0 && s[4]==0)  
  {
    return 1;  
  }
  else
  {
    return 0;  
  }
}

bool isStraight()
{
  if((s[0]==0 && s[1]==0 && s[2]==1 && s[3]==0 && s[4]==0)||(s[0]==0 && s[1]==1 && s[2]==1 && s[3]==1 && s[4]==0))
  {
    return 1;  
  }  
  else
  {
    return 0;  
  }
}
