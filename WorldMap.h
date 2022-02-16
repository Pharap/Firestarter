const uint8_t world_width = 256;
const uint8_t world_height = 256;

// A 2D array of tile types/tile indices
uint8_t world[height][width] { /* Fill the map data in as necessary */ };

void drawMap()
{
  for(uint8_t y = 0; y < world_height; ++y)
  {
    // Calculate the y position to draw the tile at
    int16_t drawY = ((y * tileHeight) - camera.y);
    
    for(uint8_t x = 0; x < world_width; ++x)
    {
      // Calculate the x position to draw the tile at:
      int16_t drawX = ((x * tileWidth) - camera.x);
      
      uint8_t tileType = world[y][x];
      
      // Assuming that your tile types are the same as
      // the frames used in your tilesheet. Otherwise
      // you'll need a way to determine the sprite index
      // from the tile type.
      Sprites::drawOverwrite(drawX, drawY, tilesheet, tileType);
    }
  }
}
