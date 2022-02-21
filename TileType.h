#pragma once

// For uint8_t
#include <stdint.h>

// Represents different tile types
enum class TileType : uint8_t
{
  building0,
  building1,
  building2,
  building3,
};

// Gets the sprite index from the tile type.
inline constexpr uint8_t toTileIndex(TileType tileType)
{
  // The basic implementation just converts the
  // tile type to its underlying integer representation.
  return static_cast<uint8_t>(tileType);
}
