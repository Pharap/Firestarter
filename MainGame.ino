#include "MainGame.h"

Vector buildingLoc;

void setup() {
  arduboy.begin();
  arduboy.clear();
  arduboy.initRandomSeed();
  //uint8_t tileType = random (0,3);
  //Initialize things here
  generateMap();
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
  //Sprites::drawSelfMasked(buildingLoc.x - camera.x, buildingLoc.y - camera.y, buildingPlaceholders, tileType);
  debug();
  drawMap();
  
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
