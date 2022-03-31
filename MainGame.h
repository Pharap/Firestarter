#include "TileType.h"
#include <Arduboy2.h>
Arduboy2 arduboy;
#include "GameSprites.h"

// Changes to make:
// - Create pause function on B button press and call drawMap function in it
// - Create functions toIso and toCart to go to and from Isometric/Cartesian
// - Draw new map tiles using toIso (and probably an enum due to how theyre stored in memory?)

class Vector {
  public:
    float x = 0;
    float y = 0;
};

// The game camera, represented by the camera's top left coordinates
Vector camera;

// The dimensions of the screen
constexpr uint8_t screen_height = HEIGHT;
constexpr uint8_t screen_width = WIDTH;

// The centre coordinates of the screen
constexpr uint8_t viewport_center_height = screen_height / 2;
constexpr uint8_t viewport_center_width = screen_width / 2;

// The dimensions of the map
constexpr uint8_t mapHeight = 32;
constexpr uint8_t mapWidth = 32;

// A 2D array of tiles, represented with 'TileType'
TileType tileMap[mapHeight][mapWidth] {};
TileType tileIsoMap[mapHeight][mapWidth] {};

//Create timer
unsigned long currentMillis = 0;
unsigned long previousMillis = 0;

unsigned long getElapsedTime()
{
  return (currentMillis - previousMillis);
}

void updatePreviousTime()
{
  previousMillis = currentMillis;
} 

void updateCurrentTime()
{
  currentMillis = millis();
}

// Generates a random map by filling the map with random tiles,
// moving from left to right, top to bottom.
// Called in setup
void generateMap()
{
  // Top to bottom
  for(uint16_t tileY = 0; tileY < mapHeight; ++tileY)
  {
    // Left to right
    for(uint16_t tileX = 0; tileX < mapWidth; ++tileX)
    {
      // Create a tile value from a random number
      // and assign it to a tile in the tile map.
      tileMap[tileY][tileX] = fromTileIndex(random());
    }
  }
}

void drawMiniMap()
{
  for(uint8_t y = 0; y < mapHeight; ++y)
  {
    // Calculate the y position to draw the tile at, 6 is tile height
    int16_t drawY = ((y * 6) - camera.y);
    
    for(uint8_t x = 0; x < mapWidth; ++x)
    {
      // Calculate the x position to draw the tile at, 6 is tile width:
      int16_t drawX = ((x * 6) - camera.x);

      // Read the tile from the map.
      TileType tileType = tileMap[y][x];

      // Figure out the tile index.
      uint8_t tileIndex = toTileIndex(tileType);

      // Draw the tile at the calculated position.
      Sprites::drawOverwrite(drawX, drawY, buildingPlaceholders, tileIndex);
    }
  }
}
  
// Isometric map tiles
constexpr uint8_t const * buildings[]
{
  building0,
  building1,
  building2,
  building3,
};

// Isometric to cartesian:
// isoX = cartX - cartY;
// isoY = (cartX + cartY) / 2;

// Cartesian to Isometric:
// cartX = (2 * isoY + isoX) / 2;
// cartY = (2 * isoY - isoX) / 2;

void drawIsoMap()
{
  for(uint8_t y = 0; y < mapHeight; ++y)
  {
    // Calculate the y position to draw the tile at, 6 is tile height
    int16_t drawY = ((y * 6) - camera.y);

    for(uint8_t x = 0; x < mapWidth; ++x)
    {
      // Calculate the x position to draw the tile at, 6 is tile width:
      int16_t drawX = ((x * 6) - camera.x);
      int16_t drawIsoX = drawX - drawY;
      int16_t drawIsoY = (drawX + drawY) / 2;

      // Read the tile from the map.
    TileType tileType = tileMap[y][x];
    
    // Figure out the tile index.
    uint8_t tileIndex = toTileIndex(tileType);
    
    // Select the building sprite
    const uint8_t * buildingSprite = buildings[tileIndex];
    
    // Draw the tile at the calculated position.
    Sprites::drawOverwrite(drawIsoX, drawIsoY, buildingSprite, 0);
    }
  }
}
