#ifndef congestion_monitor
#define congestion_monitor

#include<Arduino_FreeRTOS.h>
#include <Arduino.h>

class congestion_mtr{
public:
	congestion_mtr();
		// Define variables
	int buttonPin_Curr = 2;
	int buttonPin_R1 = 3;
	int buttonPin_R2 = 4;
	int buttonPin_R3 = 5; // Digital pin where the button is connected. (2,3,4,5)
	
	int ledPin_Curr = 13;  // Digital pin where the LED is connected. (13,12,11,10)
	int ledPin_R1 = 12;
	int ledPin_R2 = 11;
	int ledPin_R3 = 10;

	bool congStat_Curr = LOW;
	bool congStat_R1 = LOW;
	bool congStat_R2 = LOW;
	bool congStat_R3 = LOW;

	void Initialize_Setup();
	void CongStat_CurrentJunc();
	void CongeStat_NextJuncs();


};

extern congestion_mtr cm;
#endif