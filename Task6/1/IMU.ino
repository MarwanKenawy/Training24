//including Wire.h library for I2C Communication with MPU6050 Sensor
#include <Wire.h>

//defining Variables
float RateRoll,RatePitch,RateYaw;
float AccX,AccY,AccZ;
float AngleRoll,AnglePitch,AngleYaw;
float elapsedTime = 0, currentTime = 0, previousTime = 0;

void gyro_signals()
{ 
  //Pull the Accelerometer measures from the sensor
  Wire.beginTransmission(0x68);
  Wire.write(0x3B);
  Wire.endTransmission();
  Wire.requestFrom(0x68,6);
  int AccXLSB = Wire.read() << 8|Wire.read();
  int AccYLSB = Wire.read() << 8|Wire.read();
  int AccZLSB = Wire.read() << 8|Wire.read();

  //pull gyroscope rotation rate measurements from the sensor
  previousTime = currentTime;
  currentTime = millis();
  elapsedTime = (currentTime - previousTime) / 1000;
  
  Wire.beginTransmission(0x68);
  Wire.write(0x43);
  Wire.endTransmission();
  Wire.requestFrom(0x68,6);
  int GyroX = (Wire.read() << 8 | Wire.read())/32.8;
  int GyroY = (Wire.read() << 8 | Wire.read())/32.8;
  int GyroZ = (Wire.read() << 8 | Wire.read())/32.8;

  //Calculating Yaw angle id degrees
  AngleYaw = AngleYaw + GyroZ * elapsedTime;

  //Convert measurements to physical values and dividing by ratios to according to sensetivity in datasheet
  RateRoll = (float) GyroX/65.5;
  RatePitch = (float) GyroY/65.5;
  RateYaw = (float) GyroZ/65.5;
  
  AccX =  (float) AccXLSB/4096;  
  AccY =  (float) AccYLSB/4096;  
  AccZ =  (float) AccZLSB/4096;

  //Calculating Roll and Pitch angles and converting from radian to degrees
  AngleRoll = atan(AccY/sqrt(AccX*AccX + AccZ*AccZ))*180/3.14; 
  AnglePitch = atan(-AccX/sqrt(AccY*AccY + AccZ*AccZ))*180/3.14;  
}
void setup() {
  Serial.begin(19200);
  Wire.begin();    //initialize communication
  Wire.beginTransmission(0x68); //Start communication with MPU6050
  Wire.write(0x6B);   //Talk to the register 6B
  Wire.write(0x00);  //Make reset - place a 0 into the 6B register
  Wire.endTransmission(); //end the transmission

  //Turn on Low Pass Filter
  Wire.beginTransmission(0x68);
  Wire.write(0x1A);
  Wire.write(0x05);
  Wire.endTransmission();
  
  //Configure Accelerometer output
  Wire.beginTransmission(0x68);
  Wire.write(0x1C);
  Wire.write(0x10); // +/- 8g full scale
  Wire.endTransmission();

  //configure Gyroscope output
  Wire.beginTransmission(0x68);
  Wire.write(0x1B);
  Wire.write(0x10); //1000 deg/s
  Wire.endTransmission();
}

void loop() {
  gyro_signals();
  
  // Print the values on the serial monitor
  Serial.print(AngleRoll);
  Serial.print("/");
  Serial.print(AnglePitch);
  Serial.print("/");
  Serial.println(AngleYaw);

}
