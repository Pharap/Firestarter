#include "TileType.h"
#include <Arduboy2.h>
Arduboy2 arduboy;
#include "GameSprites.h"

class Vector {
  public:
    float x = 0;
    float y = 0;
};

Vector camera;

//Appropriate data types?
const uint8_t screen_height = 64;
const uint8_t screen_width = 128;

const uint8_t viewport_center_height = screen_height / 2;
const uint8_t viewport_center_width = screen_width / 2;

const uint8_t world_width = 255;
const uint8_t world_height = 255;
const uint8_t mapHeight = 9;
const uint8_t mapWidth = 9;

// A 2D array of tile types/tile indices
//uint8_t world[world_height][world_width] { /* Fill the map data in as necessary */ };
TileType tileMap[mapHeight][mapWidth] {};

//World array?

//Coordinates to isomentric?

void generateMap()
{
  for(uint16_t tileY = 0; tileY < world_height; ++tileY)
    for(uint16_t tileX = 0; tileX < world_width; ++tileX)
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
      
      //uint8_t tileType = world[y][x];
      
      // Assuming that your tile types are the same as
      // the frames used in your tilesheet. Otherwise
      // you'll need a way to determine the sprite index
      // from the tile type.
      Sprites::drawOverwrite(drawX, drawY, buildingPlaceholders, tileMap);
    }
  }
}
