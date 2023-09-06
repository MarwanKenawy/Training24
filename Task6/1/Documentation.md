# MPU 6050
## Ienertial measurement unit(**IMU**) sensor
> MPU6050 sensor module is complete 6-axis Motion Tracking Device. It combines 3-axis Gyroscope, 3-axis Accelerometer and Digital Motion Processor all in small package. Also, it has additional feature of on-chip Temperature sensor. It has I2C bus interface to communicate with the microcontrollers.

## MPU6050 Module Pinout
![IMU](img\MPU6050_Module.webp)
### MPU pin description
- ***INT***: Interrupt digital output pin.
- ***AD0***: I2C Slave Address LSB pin. This is 0th bit in 7-bit slave address of device. If connected to VCC then it is read as logic one and slave address changes.
- ***XCL***: Auxiliary Serial Clock pin. This pin is used to connect other I2C interface enabled sensors SCL pin to MPU-6050.
- ***XDA***: Auxiliary Serial Data pin. This pin is used to connect other I2C interface enabled sensors SDA pin to MPU-6050.
- ***SCL***: Serial Clock pin. Connect this pin to microcontrollers SCL pin.
- ***SDA***: Serial Data pin. Connect this pin to microcontrollers SDA pin.
- ***GND***: Ground pin. Connect this pin to ground connection.
- ***VCC***: Power supply pin. Connect this pin to +5V DC supply.
- MPU-6050 module has Slave address (When AD0 = 0, i.e. it is not connected to Vcc) as,
- Slave Write address(SLA+W): 0xD0
- Slave Read address(SLA+R): 0xD1

### Calculations
> Note that gyroscope and accelerometer sensor data of MPU6050 module consists of 16-bit raw data in 2’s complement form.

Now suppose we have selected,

-  Accelerometer full scale range of +/- 2g with Sensitivity Scale Factor of 16,384 LSB(Count)/g.

-  Gyroscope full scale range of +/- 250 °/s with Sensitivity Scale Factor of 131 LSB (Count)/°/s.

then,

To get sensor raw data, we need to first perform 2’s complement on sensor data of Accelerometer and gyroscope.

After getting sensor raw data we can calculate acceleration and angular velocity by dividing sensor raw data with their sensitivity scale factor

## Digital Low Pass filter (DLPF)
> the Digital Low Pass Filter (DLPF)setting for both the gyroscopes and accelerometers
>
> The accelerometer works with fs = 1kHz
>
> while gyroscope can work with fs = 1kHz or 8kHz according to the bandwidth and delay

![DLPF](img\DLPF.jpg)
