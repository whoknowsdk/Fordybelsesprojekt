enum Direction {
  Stop,
  North,
  South,
  East,
  West,
  NorthEast,
  NorthWest,
  SouthEast,
  SouthWest,
  RotateLeft,
  RotateRight
};

#define IDNAME(name) #name
const char* directionNames[] = {
  IDNAME(Stop),
  IDNAME(North),
  IDNAME(South),
  IDNAME(East),
  IDNAME(West),
  IDNAME(NorthEast),
  IDNAME(NorthWest),
  IDNAME(SouthEast),
  IDNAME(SouthWest),
  IDNAME(RotateLeft),
  IDNAME(RotateRight)
};
