#include <MPU6050.h>
#include <Wire.h>


MPU6050 mpu;

// Timers
int timerAcc = 0;
float timeStep = 0.05;

// Pitch, Roll and Yaw values
long pitch = 0;
long roll = 0;
long yaw = 0;

long CurrX;
long CurrY;
long PrevX;
long PrevY;

long currentRotation = 0;

void AccelerometerSetup() 
{
  Serial.begin(9600);
  // Initialize MPU6050
  
  /*while(!mpu.begin(MPU6050_SCALE_2000DPS, MPU6050_RANGE_2G))
  {
    Serial.println("Could not find a valid MPU6050 sensor, check wiring!");
    delay(500);
  }*/
  
  // Calibrate gyroscope. The calibration must be at rest.
  // If you don't want calibrate, comment this line.
  mpu.calibrateGyro();

  // Set threshold sensivty. Default 3.
  // If you don't want use threshold, comment this line or set 0.
  mpu.setThreshold(3);
}

void AccelerometerLoop()
{
  timerAcc = millis();
  // Read normalized values
  Vector norm = mpu.readNormalizeGyro();
  
  CurrX = norm.XAxis;
  CurrY = norm.YAxis;

  if (CurrX == 0 && CurrY == 0) {
      if (PrevX > abs(20) || PrevY > abs(20)){
          happiness - 10;
          PrevX = CurrX;
          PrevY = CurrY;
        }
      else {
        PrevX = CurrX;
        PrevY = CurrY;
        }
    }
  Serial.print("Y: ");
  Serial.println(norm.YAxis);
  Serial.print("X: ");
  Serial.println(norm.XAxis);
  Serial.print("Z: ");
  Serial.println(norm.ZAxis);

  // Wait to full timeStep period
  delay((timeStep*1000) - (millis() - timerAcc));
}
