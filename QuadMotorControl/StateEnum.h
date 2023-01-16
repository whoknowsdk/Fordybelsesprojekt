// Homing = Finder den nærmeste væg/hjørne
// Happy = Bevæger sig rundt randomly, med passende intervaller (Hvert 15-30 sekundt), men holder en passende afstand til objekter (25 cm)
// Scared = Bevæger sig rundt randomly, med et panisk interval (Hvert 3-7 sekundt), og løber væk fra alle objeter nærmere end 100 cm. Tilpasser retningen ud fra om den bevæger sig tættere på objekter
// Depressed = Bevæger sig rundt randomly, med et langt interval (1-2 minutter), og ignorere afstands betingelser

enum State {
  Homing,
  Happy,
  Scared,
  Depressed,
  
};

#define IDNAME(name) #name
const char* stateNames[] = {
  IDNAME(Homing),
  IDNAME(Happy),
  IDNAME(Scared),
  IDNAME(Depressed)
};
