# Rotary Encoder
> Rotary Encoders are sensors that detect position and speed by converting rotational mechanical displacements into electrical signals and processing those signals. Sensors that detect mechanical displacement for straight lines are referred to as Linear Encoders
>
> Rotary Encoders measure the number of rotations, the rotational angle, and the rotational position. Linear Encoders are also available to measure linear movement.

![Encoder](img\Rotary-Encoder-Construction.jpg)

## Rotary Encoder Pinout
![Encoder Pinout](img\rotary-encoder-module-pinout.png)
- ***GND*** is the ground connection.
- ***VCC*** is the positive supply voltage, which is typically between 3.3 and 5 volts.
- ***SW*** is the output of the push button switch (active low). When the knob is depressed, the voltage goes LOW.
- ***DT (Output B)*** is similar to CLK output, but it lags behind CLK by a 90° phase shift. This output is used to determine the direction of rotation.
- ***CLK (Output A)*** is the primary output pulse used to determine the amount of rotation. Each time the knob is turned in either direction by just one detent (click), the ‘CLK’ output goes through one cycle of going HIGH and then LOW.


## Software Practical Low Pass Filter (LPF)

>Given Diameter of the wheel = 40cm
>
>so, Radius = 20cm = 0.2m
>
>This indicates that the wheel covers 2*pi*r per revolution = 2*3.14*0.2 = 1.2566m
>
>Given velocity = 0.5m/s
>
>so, time covered per revolution = 1.2566/0.5 = 2.513 s
>
>Given encoder has resolution = 540 pulses per revolution
>
>so, time for 1 revolution = time for 540 pulses = 2.513 s
>
>so the frequency of encoder = 540/2.513 = 24.86 pulse/sec
>> The Critical Frequency of The Low Pass Filter = 24.86 pulse/sec