#include <iostream>
#include <bits/stdc++.h>
using namespace std;
/*
    To get a better reading
    we get the range of the reading from the accuracy of each imu then we fuse them by getting the overlaping part of the two ranges

    then we will get a better range and finding its mean is closest to the true value

    accuracy = 1-(abs(Truevalue-measured value)/TrueValue)
    for example reading of 11.68 and 9.49
    the range of the first reading (11.68) of mpu6050 with accuracy of 0.78 is  [9.57,14.97]
    the range of the second reading (9.49) of bno55 with accuracy of 0.92 is [8.787,10.315]
    so the overlapped part is [9.57,10.315]
    and the mean = (9.57+10.315)/2 = 9.94
*/

//functions to get range of the accurate reading
float low(float,float);
float high(float,float);

int main()
{
    float mpu6050[10] = {0.0,11.68,18.95,23.56,25.72,25.38,22.65,18.01,10.14,-0.26};
    float bno55[10] = {0.0,9.49,16.36,21.2,23.16,22.8,19.5,14.85,6.79,-2.69};
    float output[10];
    float accuracy1 = 0.78, accuracy2 = 0.92,low1,high1,low2,high2,low3,high3; // 1 for mpu6050, 2 for bno55, 3 for output
    for(int i=0;i<10;i++)
    {
        low1 = low(mpu6050[i],accuracy1);
        high1 = high(mpu6050[i],accuracy1);

        low2 = low(bno55[i],accuracy2);
        high2 = high(bno55[i],accuracy2);

        if(high1<low2)//if there is no overlapping then we get the range near the imu with higher accuracy
        {
            low3 = high1;
            high3 = low2;
        }
        else if(high2<low1)
        {
            low3 = high2;
            high3 = low1;
        }
        else//there is overlapping
        {
            low3 = low1>low2?low1:low2;
            high3 = high1<high2?high1:high2;
        }
        output[i] = (low3+high3)/2;//calculating mean
    }
    cout<<"Output: ";
    for(int i=0;i<10;i++)
        cout<<output[i]<<" ";
    cout<<endl;
    return 0;
}

float low(float reading, float accuracy)
{
    float answer = reading/(2.0-accuracy);
    return answer;
}

float high(float reading, float accuracy)
{
    float answer = reading/accuracy;
    return answer;
}