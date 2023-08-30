#include <iostream>
#include <bits/stdc++.h>
#include <chrono>
#include <thread>
using namespace std;
using namespace std::this_thread; // sleep_for, sleep_until
using namespace std::chrono; // nanoseconds, system_clock, seconds
int main()
{
    int n;
    //validation of input
    do
    {
        cin>>n;
    } while (n <= 0);
    
    for(int i = n;i >= 1;i--)
    {
        cout<<i<<endl;
        sleep_for(seconds(1)); //sleep for 1 second
    }
    cout<<"Blast off to the monn!\n";
    return 0;
}