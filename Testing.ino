void toOrigin2()
{
  while(y > 0 /*row limit switch is not pressed*/)
  {
    digitalWrite(2, HIGH); //decreases
    digitalWrite(4, LOW); //decreases

    digitalWrite(3, HIGH);
    digitalWrite(5, HIGH);
    delayMicroseconds(1000);
    digitalWrite(3, LOW);
    digitalWrite(5, LOW);
    delayMicroseconds(1000);
    y--;
  }
  while(x > 0/*column limit switch is not pressed*/)
  {
    digitalWrite(8, LOW); //decreases

    digitalWrite(9, HIGH);
    delayMicroseconds(1000);
    digitalWrite(9, LOW);
    delayMicroseconds(1000);
    x--;
  }
}

void testPixy()
{
  int humanR = -1;
  int humanC = -1;

  humanC = map(pixy.blocks[0].x, 85, 240, 0, 3); 
  //left is 108,right is 108 mm
  humanR = map(pixy.blocks[0].y, 22, 175, 0, 3);

  Serial.println(humanR);
  Serial.println(humanC);
}

void testRMotors()
{
  /*for(int i = 0; i < 2100; i++) //left motor
  {
    digitalWrite(2, HIGH);
    digitalWrite(4, LOW);
    digitalWrite(3, HIGH);
    digitalWrite(5, HIGH);
    delayMicroseconds(1000);
    digitalWrite(3, LOW);
    digitalWrite(5, LOW);
    delayMicroseconds(1000);
  }*/
  for(int i = 0; i < 2100; i++)
  {
    digitalWrite(2, LOW);
    digitalWrite(4, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(5, HIGH);
    delayMicroseconds(1000);
    digitalWrite(3, LOW);
    digitalWrite(5, LOW);
    delayMicroseconds(1000);
  }
}

void testCMotors()
{
  for(int i = 0; i < 1700; i++)
  {
    digitalWrite(8, LOW);
    digitalWrite(9, HIGH);
    delayMicroseconds(1000);
    digitalWrite(9, LOW);
    delayMicroseconds(1000);
  }
 /* for(int i = 0; i < 1700; i++)
  {
    digitalWrite(8, HIGH);
    digitalWrite(9, HIGH);
    delayMicroseconds(1000);
    digitalWrite(9, LOW);
    delayMicroseconds(1000);
  }*/
  
}

