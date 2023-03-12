//BASICS
int mood = 50;
long LastMsgT;
long RunTime = 60*15*1000;
long LastDrop = millis();
int volumeLevel = 15;

// Action variables

long ActionStart = 0;
long ActionTime = 0;
bool Paused = false;

// Dist Measure

float filterArrayN[10];
float filterArrayS[10];
float filterArrayE[10];
float filterArrayW[10];

float filterArrayCompN[10];
float filterArrayCompS[10];
float filterArrayCompE[10];
float filterArrayCompW[10];

float distN;
float distS;
float distE;
float distW;

float distCompN;
float distCompS;
float distCompE;
float distCompW;

float distDiffN;
float distDiffS;
float distDiffE;
float distDiffW;

float distRawN[10];
float distRawS[10];
float distRawE[10];
float distRawW[10];

float distTimer;
int distCount = 0;

int distance_cm;

bool avoiding = false;

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

int TREN = 33;
int BREN = 27;

int TRM_1 = 29;
int TRM_2 = 30;

int BRM_1 = 25;
int BRM_2 = 26;

//Right Side Motors

int TLEN = 22;
int BLEN = 28;

int TLM_1 = 32;
int TLM_2 = 31;

int BLM_1 = 24;
int BLM_2 = 23;

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

int ECN = 48;
int ECE = 46;
int ECS = 42;
int ECW = 44;

int TRN = 49;
int TRE = 47;
int TRS = 43;
int TRW = 45;

float distance_N;
float distance_E;
float distance_S;
float distance_W;

float minDistance = 10;
float maxDistance = 130;
