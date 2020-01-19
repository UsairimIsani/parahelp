#include <Arduino.h>
#include <Wire.h>
const int MPU6050_addr = 0x68;
int16_t AccX, AccY, AccZ, Temp, GyroX, GyroY, GyroZ;
//float roll,pitch,rollF,pitchF=0;
int Roll;
int Pitch;
int Yaw;
int valueDivider = 1023;

void setup()
{
  Wire.begin();
  Wire.beginTransmission(MPU6050_addr);
  Wire.write(0x6B);
  Wire.write(0);
  Wire.endTransmission(true);
  Serial.begin(115200);
}
void loop()
{
  Wire.beginTransmission(MPU6050_addr);
  Wire.write(0x3B);
  Wire.endTransmission(false);
  Wire.requestFrom(MPU6050_addr, 14, true);
  // AccX=Wire.read()<<8|Wire.read();
  // AccY=Wire.read()<<8|Wire.read();
  // AccZ=Wire.read()<<8|Wire.read();
  // Temp=Wire.read()<<8|Wire.read();
  GyroX = Wire.read() << 8 | Wire.read();
  GyroY = Wire.read() << 8 | Wire.read();
  GyroZ = Wire.read() << 8 | Wire.read();
  Roll = GyroX / valueDivider;
  Pitch = GyroY / valueDivider;
  Yaw = GyroZ / valueDivider;
  // Serial.print("AccX = "); Serial.print(AccX);
  // Serial.print(" || AccY = "); Serial.print(AccY);
  // Serial.print(" || AccZ = "); Serial.println(AccZ);
  // Serial.print(" || Temp = "); Serial.print(Temp/340.00+36.53);
  //
  if (Roll >= 14)
  {
    Serial.print(2);
  }
  else if (Roll <= -10)
  {
    Serial.print(3);
  }
  else if (Pitch <= -10)
  {
    Serial.print(4);
  }
  else if (Pitch >= 14)
  {
    Serial.print(5);
  }
  //  Serial.print(" || GyroX = "); Serial.print(GyroX/1023);
  //  Serial.print(" || GyroY = "); Serial.print(GyroY/1023);
  //  Serial.print(" || GyroZ = "); Serial.println(GyroZ/1023);
  delay(300);
}