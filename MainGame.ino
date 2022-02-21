#include "MainGame.h"
#include "TileType.h"
#include "GameSprites.h"
#include <Arduboy2.h>
Arduboy2 arduboy;

Vector camera;
Vector buildingLoc;

const uint8_t world_width = 256;
const uint8_t world_height = 256;
const uint8_t mapHeight = 9;
const uint8_t mapWidth = 9;

// A 2D array of tile types/tile indices
uint8_t world[world_height][world_width] { /* Fill the map data in as necessary */ };
TileType tileMap[mapHeight][mapWidth] {};

void setup() {
  arduboy.begin();
  arduboy.clear();
  arduboy.initRandomSeed();
  uint8_t tileType = random (0,3);
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

void generateMap()
{
  for(uint8_t tileY = 0; tileY < world_height; ++tileY)
    for(uint8_t tileX = 0; tileX < world_width; ++tileX)
      tileMap[tileY][tileX] = static_cast<TileType>(random() % 4);
}

void drawMap()
{
  for(uint8_t y = 0; y < world_height; ++y)
  {
    // Calculate the y position to draw the tile at, 6 is tile height
    int16_t drawY = ((y * 6) - camera.y);
    
    for(uint8_t x = 0; x < world_width; ++x)
    {
      // Calculate the x position to draw the tile at, 6 is tile width:
      int16_t drawX = ((x * 6) - camera.x);
      
      uint8_t tileType = world[y][x];
      
      // Assuming that your tile types are the same as
      // the frames used in your tilesheet. Otherwise
      // you'll need a way to determine the sprite index
      // from the tile type.
      Sprites::drawOverwrite(drawX, drawY, buildingPlaceholders, tileType);
    }
  }
}

void debug()
{
  arduboy.print(camera.x);
  arduboy.print(camera.y);
}
