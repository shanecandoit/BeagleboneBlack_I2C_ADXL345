/*
 * Accelerometer_Test.cpp
 *
 *  Created on: Aug 5, 2014
 *      Author: mahen
 * some changes by shane
 */

#include "ADXL345Accelerometer.h"
#include <iostream>
#include <string>

//shane include this for sleep
#include <unistd.h>

using namespace std;


int main(int argc, char *argv[])
{
	cout << "Testing ADXL345Accelerometer " << endl;

	//ADXL345Accelerometer Accelerometer_Test(1, 0x53);
	//cout<<"Device ID : "<< hex << Accelerometer_Test.getAccelerometer_ID()<<endl;
	ADXL345Accelerometer Accelerometer_Test(2, 0x1D);
	cout<<"Device ID : "<< hex << Accelerometer_Test.getAccelerometer_ID()<<endl;
	Accelerometer_Test.SetPowerMode(0x01);
	Accelerometer_Test.getAccelerationData();

	// shane
	int i=0;

	//while (1) {
	//shane
	cout<<"Xdata \tYData \tZData \tPitch \tRoll"<<endl;;
	while(i<50) {
		cout <<  dec <<Accelerometer_Test.getAcceleration_X()
			<<"\t"<< dec <<Accelerometer_Test.getAcceleration_Y()
			<<"\t"<< dec <<Accelerometer_Test.getAcceleration_Z();
		cout <<"\t"<< dec << Accelerometer_Test.getPitch()
			<<"\t"<< dec << Accelerometer_Test.getRoll()<<endl;
		//usleep(1000000);
		usleep(100000);// one less zero
		Accelerometer_Test.getAccelerationData();

		// shane
		i++;
	}
	cout << "Testing Accelerometer Complete" << endl;

	return 0;
}


