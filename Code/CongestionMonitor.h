#ifndef congestion_monitor
#define congestion_monitor

#include<Arduino_FreeRTOS.h>
#include <Arduino.h>

class congestion_mtr{
public:
	congestion_mtr();

	void CongestionMonitorTask();
	bool CongestionStatus();
	void AlertTrafficController();


};

extern congestion_mtr cj;
#endif