#include "MainGame.h"
#include "GameSprites.h"
#include <Arduboy2.h>
Arduboy2 arduboy;

Vector camera;
Vector buildingLoc;

void setup() {
  arduboy.begin();
  arduboy.clear();
  
  //Initialize things here
}

uint8_t frame = 0;

void loop() {
  if (!arduboy.nextFrame()) {
    return;
  }
 
  arduboy.clear();
 
  //Game code here
  arduboy.pollButtons();
  // Handle input
  handleInput();
  Sprites::drawSelfMasked(buildingLoc.x - camera.x, buildingLoc.y - camera.y, building0, 0);
  debug();
  
  arduboy.display();
}

void handleInput()
{

  // Move cursor and camera
  if (arduboy.pressed(UP_BUTTON))
  {
      --camera.y;
      
      //update player
  }

  if (arduboy.pressed(DOWN_BUTTON))
  {
      ++camera.y;

      //update player
  }

  if (arduboy.pressed(LEFT_BUTTON))
  {
      --camera.x;
      
      //update player
}

  if (arduboy.pressed(RIGHT_BUTTON))
  {
      ++camera.x;

      //update player
  }
}

void debug()
{
  arduboy.print(camera.x);
  arduboy.print(camera.y);
}
