// VARIABLE SETUP
//
// M = Motor
// T = Top
// B = Bottom
// R = Right
// L = Left
// _1 = Roter Fremad
// _2 = Roter Bagud
//
//  EN = Enable
//
// Left Side Moters

int TREN = 22;
int BREN = 23;

int TRM_1 = 32;
int TRM_2 = 33;

int BRM_1 = 26;
int BRM_2 = 27;

//Right Side Motors

int TLEN = 31;
int BLEN = 30;

int TLM_1 = 34;
int TLM_2 = 35;

int BLM_1 = 25;
int BLM_2 = 24;

// Other motor variables

int minMotorSpeed = 125;
int maxMotorSpeed = 255;

bool showDirectionInfo = false;
bool showJoystickInfo = false;
bool showSensorInfo = false;
bool joystickControlOn = false;

// Sensor Variables

// EC = Echo
// TR = Trigger
// N = North
// S = South
// E = East
// W = West

int ECN = 40;
int ECE = 41;
int ECS = 38;
int ECW = 39;

int TRN = 45;
int TRE = 47;
int TRS = 44;
int TRW = 46;

float distance_N;
float distance_E;
float distance_S;
float distance_W;

float minDistance = 5;
float maxDistance = 130;
