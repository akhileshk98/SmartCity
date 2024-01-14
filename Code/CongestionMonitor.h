#ifndef congestion_monitor
#define congestion_monitor

#include<Arduino_FreeRTOS.h>
#include <Arduino.h>

class congestion_mtr{
public:
	congestion_mtr();

	bool CongStat_Curr = false;
	bool CongStat_Route1 = false;
	bool CongStat_Route2 = false;
	bool CongStat_Route3 = false;


	void CongestionMonitorTask();
	void CongStat_CurrentJunc();
	void CongeStat_NextJuncs();


};

extern congestion_mtr cj;
#endif