/*need to figure out where to bring drawing back to
 *can figure out how many steps to travel whole board
 *calculate how many steps from origin
 */

#include <SPI.h>  
#include <Pixy.h>
#include <Servo.h>

//each move corresponds to robot's moves, not total
boolean move1 = false;
boolean move2 = false;
boolean rest = false;
boolean over = false;
int taken[3][3] = { //0 is empty, 1 is robot, 2 is human
  {0, 0, 0}, 
  {0, 0, 0}, 
  {0, 0, 0}};
int x = 0;
int y = 0; 
static int i = 0;
Pixy pixy;
uint16_t blocks;
Servo marker;

void setup() {
  Serial.begin(9600);
  pinMode(2, OUTPUT); //left direction
  pinMode(3, OUTPUT); //left step
  pinMode(4, OUTPUT); //right direction
  pinMode(5, OUTPUT); //right step
  pinMode(8, OUTPUT); //C direction
  pinMode(9, OUTPUT); //C step
  pinMode(6, OUTPUT); //servo
  pinMode(12, INPUT); //turn button

  marker.attach(6);
  marker.write(180);
  delay(3000);

 // toOrigin();
  pixy.init();

  //First move
  goTo(0, 0);
  drawX();
  toOrigin(0,0);
  move1 = true;
  taken[0][0] = 1;
  Serial.println("did it again");
}

void loop() {
  blocks = pixy.getBlocks();
  //pixy range = 2.816
  //Row steps: 2100
  //Column steps: 1700

  /*boolean waiting = true.;
  while(waiting)
  {
    if(digitalRead(12) == 1)
      waiting = false;
  }

  Serial.println(waiting);*/

 /* for(int r = 0; r < 3; r++)
  {
    for(int c = 0; c < 3; c++)
    {
      goTo(r, c);
      drawX();
      toOrigin(r, c);
    }
  }*/

 /* int humanR = 0;
  int humanC = 0;
  humanR = map(pixy.blocks[0].y, 18, 163, 0, 3); 
  humanC = map(pixy.blocks[0].x, 97, 245, 0, 3);
  Serial.print(humanR);
  Serial.print(", ");
  Serial.println(humanC);*/
  

  if(move1)
  {
    int humanR = -1;
    int humanC = -1;
    boolean waiting = true;

    Serial.println("waiting");
    while(waiting)
    {
      if(digitalRead(12) == 1)
        waiting = false;
    }
    
   /* while(!blocks)
    {
      Serial.println("Blocks");
      blocks = pixy.getBlocks();
    }*/
    Serial.println(blocks);

    //figure out which square the O is here vv
    delay(2000);
   uint16_t blocks;
  int x = 0;
  int y = 0;
  blocks = pixy.getBlocks();

  if (blocks)
  {
    i++;
    if (i%50==0)
    {
      
    x = pixy.blocks[0].x + pixy.blocks[0].width/2;
    y = pixy.blocks[0].y + pixy.blocks[0].height/2;
    }
  } 

 
  //  Serial.println(pixy.blocks[0].y);
   // blocks = pixy.getBlocks();
    humanR = map(y, 18, 163, 0, 300); 
    humanC = map(x, 97, 245, 0, 300);
    //taken[humanR][humanC] = 2;
    Serial.print(humanR);
    Serial.print(" ");
    Serial.println(humanC);

   // delay(2000);
    
    if(humanR == 1 && humanC == 1)
    {
      goTo(1, 2);
      drawX();
      toOrigin(1, 2);
      taken[1][2] = 1;
    }
    else if(humanR == 0 && humanC == 2)
    {
      goTo(1, 0);
      drawX();
      toOrigin(1, 0);
      taken[1][0] = 1;
    }
    else
    {
      goTo(0, 2);
      drawX();
      toOrigin(0, 2);
      taken[0][2] = 1;
    }
    move1 = false;
    move2 = true;
  }
  if(move2)
  {
    boolean humanMoved = false;
    int humanR = -1;
    int humanC = -1;
    boolean waiting = true;

    while(waiting)
    {
      Serial.println("waiting");
      if(digitalRead(12) == 1)
        waiting = false;
    }
    
   // Serial.println(blocks);

    //figure out which square the O is here vv
    delay(2000);
    uint16_t blocks;
     while(blocks == 0){
      blocks = pixy.getBlocks();
     }
     delay(3000);

 /*   if (blocks)
    {
      i++;
      if (i%50==0)
      {
      }
    }  */
   // boolean newMove = false;
  //  while (!newMove)
  //  {
      humanR = map(pixy.blocks[0].y, 18, 163, 0, 300); 
      humanC = map(pixy.blocks[0].x, 97, 245, 0, 300);
     // taken[humanR][humanC] = 2;

      /*if(taken[humanR][humanC]==2)
      {
        humanR = map(pixy.blocks[1].y, 18, 163, 0, 2); 
        humanC = map(pixy.blocks[1].x, 97, 245, 0, 2);
        newMove = true;
      }
      taken[humanR][humanC] = 2;
    }*/

    Serial.print(humanR);
    Serial.print(", ");
    Serial.println(humanC);

   /* Serial.print(map(pixy.blocks[0].y, 18, 163, 0, 200)); 
    Serial.print(", ");
    Serial.println(map(pixy.blocks[0].x, 97, 245, 0, 200));*/
    
    if(taken[1][1]) //if human has gone in center
    {
      if(humanR == 0 && humanC == 1)
      {
        goTo(2, 1);
        drawX();
        toOrigin(2, 1);
        taken[2][1] = 1;
      }
      else if(humanR == 0 && humanC == 2)
      {
        goTo(2, 0);
        drawX();
        toOrigin(2, 0);
        taken[2][0] = 1;
      }
      else if(humanR == 2 && humanC == 1)
      {
        goTo(0, 1);
        drawX();
        toOrigin(0, 1);
        taken[0][1] = 1;
      }
      else
      {
        goTo(0, 2);
        drawX();
        toOrigin(0, 2);
        taken[0][2] = 1;
      }
    }
    else
    {
      if(taken[2][2])
      {
        goTo(2, 0);
        drawX();
        toOrigin(2, 0);
        taken[2][0] = 1;
      }
      else
      {
        goTo(1, 1);
        drawX();
        toOrigin(1,1);
        taken[1][1] = 1;
      }
    }
    move2 = false;
    rest = true;
  }
 /* if(rest)
  {
    boolean humanMoved = false;
    int humanR = -1;
    int humanC = -1;
    if(blocks > 2)
    {
      //figure out which square the O is here vv
      humanR = pixy.blocks[2].x; //needs rescaled & floored/ceilinged
      humanC = pixy.blocks[2].y; //needs rescaled & floored/ceilinged
      taken[humanR][humanC] = 2;
      humanMoved = true;
    }
    if(humanMoved)
    {
      win();
      if(!over)
        block();
    }
  }*/
}
