#include "MainGame.h"

Vector buildingLoc;

//bool isPaused = false;
bool isMinimapVisible = false;

void setup() {
  arduboy.begin();
  arduboy.clear();
  arduboy.initRandomSeed();
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
  
  if (isMinimapVisible == true)
  {
    drawMap();
  }
  
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

  if(arduboy.justPressed(B_BUTTON))
  {
    isMinimapVisible = !isMinimapVisible;
  }
}

  /*
  if(arduboy.justPressed(B_BUTTON) && isMinimapVisible == false)
  {
    isMinimapVisible = true;
  }

  if(arduboy.justPressed(B_BUTTON) && isMinimapVisible == true)
  {
    isMinimapVisible = false;
  }
  */
  
  /*if (isMinimapVisible != true)
  {
    //draw isometric
    if(arduboy.justPressed(B_BUTTON))
    //if(arduboy.pressed(B_BUTTON))
    //if(!arduboy.justPressed(B_BUTTON) && arduboy.pressed(B_BUTTON))
    //if(arduboy.pressed(B_BUTTON) && !arduboy.justPressed(B_BUTTON))
    {
      isMinimapVisible = true;
    }
  }
  else
  {
    //draw mini map
    drawMap();   
    if(arduboy.justPressed(B_BUTTON))
    //if(arduboy.pressed(B_BUTTON))
    //if(!arduboy.justPressed(B_BUTTON) && arduboy.pressed(B_BUTTON))
    //if(arduboy.pressed(B_BUTTON) && !arduboy.justPressed(B_BUTTON))
    {
      isMinimapVisible = false;
    }
  }
}*/



void debug()
{
  arduboy.print(camera.x);
  arduboy.print(camera.y);
}
