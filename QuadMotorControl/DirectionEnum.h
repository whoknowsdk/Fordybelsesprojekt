//En "liste" (enum) over alle de forskellige directions robotten kan flytte sig.
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

//Eftersom enum'en "Direction" kun kan refereres til via. en int (0, 1, 2... osv.), er dette char array med til at give
//muligheden for at refererer til retningen med navn istedet for tal. Dette gør det nemmere at skifte retningen,
//da det kan være svært at huske alle tallene.
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
