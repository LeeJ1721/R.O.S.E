void drawX()
{
  marker.write(100);
  delay(500);
  for(int i = 0; i < 390; i++)
  {
    digitalWrite(2, HIGH);
    digitalWrite(4, LOW);
    digitalWrite(8, HIGH);

    digitalWrite(3, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(9, HIGH);
    delayMicroseconds(1000);
    digitalWrite(3, LOW);
    digitalWrite(5, LOW);
    digitalWrite(9, LOW);
    delayMicroseconds(1000);
  }

  marker.write(180);
  delay(500);

  for(int i = 0; i < 370; i++)
  {
    digitalWrite(8, LOW);

    digitalWrite(9, HIGH);
    delayMicroseconds(1000);
    digitalWrite(9, LOW);
    delayMicroseconds(1000);
  }

  marker.write(100);
  delay(500);
  
  for(int i = 0; i < 390; i++)
  {
    digitalWrite(2, LOW);
    digitalWrite(4, HIGH);
    digitalWrite(8, HIGH);

    digitalWrite(3, HIGH);
    digitalWrite(5, HIGH);
    digitalWrite(9, HIGH);
    delayMicroseconds(1000);
    digitalWrite(3, LOW);
    digitalWrite(5, LOW);
    digitalWrite(9, LOW);
    delayMicroseconds(1000);
  }

  marker.write(180);
  delay(500);

  /*for(int i = 0; i < 1000; i++)
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
}

void goTo(int r, int c)
{
  if(r == 0)
  {
    for(int i = 0; i < 1753; i++)
    {
      digitalWrite(2, LOW); //increments
      digitalWrite(4, HIGH); //increments
  
      digitalWrite(3, HIGH);
      digitalWrite(5, HIGH);
      delayMicroseconds(1000);
      digitalWrite(3, LOW);
      digitalWrite(5, LOW);
      delayMicroseconds(1000);
    }
  }
  else if(r == 1)
  {
    for(int i = 0; i < 1260; i++)
    {
      digitalWrite(2, LOW); //increments
      digitalWrite(4, HIGH); //increments
  
      digitalWrite(3, HIGH);
      digitalWrite(5, HIGH);
      delayMicroseconds(1000);
      digitalWrite(3, LOW);
      digitalWrite(5, LOW);
      delayMicroseconds(1000);
    }
  }
  else if(r == 2)
  {
    for(int i = 0; i < 715; i++)
    {
      digitalWrite(2, LOW); //increments
      digitalWrite(4, HIGH); //increments
   
      digitalWrite(3, HIGH);
      digitalWrite(5, HIGH);
      delayMicroseconds(1000);
      digitalWrite(3, LOW);
      digitalWrite(5, LOW);
      delayMicroseconds(1000);
    }
  }

  if(c == 0)
  {
    for(int i = 0; i < 150; i++)
    {
      digitalWrite(8, HIGH); //increments
  
      digitalWrite(9, HIGH);
      delayMicroseconds(1000);
      digitalWrite(9, LOW);
      delayMicroseconds(1000);
    }
  }
  else if(c == 1)
  {
    for(int i = 0; i < 690; i++)
    {
      digitalWrite(8, HIGH); //increments
  
      digitalWrite(9, HIGH);
      delayMicroseconds(1000);
      digitalWrite(9, LOW);
      delayMicroseconds(1000);
    }
  }
  else if(c == 2)
  {
    for(int i = 0; i < 1210; i++)
    {
      digitalWrite(8, HIGH); //increments
  
      digitalWrite(9, HIGH);
      delayMicroseconds(1000);
      digitalWrite(9, LOW);
      delayMicroseconds(1000);
    }
  }
}

void toOrigin(int r, int c)
{
  if(r == 0)
  {
    for(int i = 0; i < 1753; i++)
    {
      digitalWrite(2, HIGH); //increments
      digitalWrite(4, LOW); //increments
  
      digitalWrite(3, HIGH);
      digitalWrite(5, HIGH);
      delayMicroseconds(1000);
      digitalWrite(3, LOW);
      digitalWrite(5, LOW);
      delayMicroseconds(1000);
    }
  }
  else if(r == 1)
  {
    for(int i = 0; i < 1260; i++)
    {
      digitalWrite(2, HIGH); //increments
      digitalWrite(4, LOW); //increments
  
      digitalWrite(3, HIGH);
      digitalWrite(5, HIGH);
      delayMicroseconds(1000);
      digitalWrite(3, LOW);
      digitalWrite(5, LOW);
      delayMicroseconds(1000);
    }
  }
  else if(r == 2)
  {
    for(int i = 0; i < 715; i++)
    {
      digitalWrite(2, HIGH); //increments
      digitalWrite(4, LOW); //increments
   
      digitalWrite(3, HIGH);
      digitalWrite(5, HIGH);
      delayMicroseconds(1000);
      digitalWrite(3, LOW);
      digitalWrite(5, LOW);
      delayMicroseconds(1000);
    }
  }

  if(c == 0)
  {
    for(int i = 0; i < 580; i++)
    {
      digitalWrite(8, LOW); //increments
  
      digitalWrite(9, HIGH);
      delayMicroseconds(1000);
      digitalWrite(9, LOW);
      delayMicroseconds(1000);
    }
  }
  else if(c == 1)
  {
    for(int i = 0; i < 1090; i++)
    {
      digitalWrite(8, LOW); //increments
  
      digitalWrite(9, HIGH);
      delayMicroseconds(1000);
      digitalWrite(9, LOW);
      delayMicroseconds(1000);
    }
  }
  else if(c == 2)
  {
    for(int i = 0; i < 1610; i++)
    {
      digitalWrite(8, LOW); //increments
  
      digitalWrite(9, HIGH);
      delayMicroseconds(1000);
      digitalWrite(9, LOW);
      delayMicroseconds(1000);
    }
  }
}

void win()
{
  if (!over)
  {
    //checking in rows
    for (int r = 0; r < 3; r++)
    {
      int numInL;
      for (int c = 0; c < 3; c++)
      {
        if (taken[r][c] == 1)
          numInL++;
      }

      if (numInL == 2)
      {
        for (int c = 0; c < 3; c++)
        {
          if (taken[r][c] == 0)
          {
            //go to r,c
            drawX();
            over = true;
            return;
          }
        }
      }
    }
  }
  if (!over)
  {
    //checking in columns
    for (int c = 0; c < 3; c++)
    {
      int numInL;
      for (int r = 0; r < 3; r++)
      {
        if (taken[r][c] == 1)
          numInL++;
      }

      if (numInL == 0)
      {
        for (int r = 0; r < 3; r++)
        {
          if (taken[r][c] == 2)
          {
            //go to r,c
            drawX();
            over = true;
            return;
          }
        }
      }
    }
  }
  //00 to 22 diagonal
  if (!over)
  {
    int numInL;
    for (int r = 0; r < 3; r++)
    {
      if (taken[r][r] == 1)
      {
        numInL++;
      }
    }
    if (numInL == 2)
    {
      for (int r = 0; r < 3; r++)
      {
        if (taken[r][r] == 0)
        {
          //go to r,c
          drawX();
          over = true;
          return;
        }
      }
    }
  }
  //02 to 20 diagonal
  if(!over)
  {
    int numInL;
    for (int r = 0; r < 3; r++)
    {
      if (taken[r][2-r] == 1)
      {
        numInL++;
      }
    }
    if (numInL == 2)
    {
      for (int r = 0; r < 3; r++)
      {
        if (taken[r][2-r] == 0)
        {
          //go to r,c
          drawX();
          over = true;
          return;
        }
      }
    }
  }
}

void block()
{
  boolean endOfTurn = false;
  if(!endOfTurn)
  {
    //checking in rows
    for (int r = 0; r < 3; r++)
    {
      int numInL;
      for (int c = 0; c < 3; c++)
      {
        if (taken[r][c] == 2)
          numInL++;
      }
  
      if (numInL == 2)
      {
        for (int c = 0; c < 3; c++)
        {
          if (taken[r][c] == 0)
          {
            //go to r,c
            drawX();
            endOfTurn = true;
            return;
          }
        }
      }
    }
  }
  if(!endOfTurn)
  {
    //checking in columns
    for (int c = 0; c < 3; c++)
    {
      int numInL;
      for (int r = 0; r < 3; r++)
      {
        if (taken[r][c] == 2)
          numInL++;
      }
  
      if (numInL == 2)
      {
        for (int r = 0; r < 3; r++)
        {
          if (taken[r][c] == 0)
          {
            //go to r,c
            drawX();
            endOfTurn = true;
            return;
          }
        }
      }
    }
  }
  //00 to 22 diagonal
  if(!endOfTurn)
  {
    int numInL;
    for (int r = 0; r < 3; r++)
    {
      if (taken[r][r] == 2)
      {
        numInL++;
      }
    }
    if (numInL == 2)
    {
      for (int r = 0; r < 3; r++)
      {
        if (taken[r][r] == 0)
        {
          //go to r,c
          drawX();
          endOfTurn = true;
          return;
        }
      }
    }
  }
  //02 to 20 diagonal
  if(!endOfTurn)
  {
    int numInL;
    for (int r = 0; r < 3; r++)
    {
      if (taken[r][2-r] == 2)
      {
        numInL++;
      }
    }
    if (numInL == 2)
    {
      for (int r = 0; r < 3; r++)
      {
        if (taken[r][2-r] == 0)
        {
          //go to r,c
          drawX();
          endOfTurn = true;
          return;
        }
      }
    }
  }
}
