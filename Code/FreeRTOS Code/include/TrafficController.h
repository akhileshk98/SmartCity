
#ifndef traffic_controller
#define traffic_controller

#include<Arduino_FreeRTOS.h>
#include <Arduino.h>

class traffic_ctlr {
public:
	traffic_ctlr();

	void TrafficSig_PreviousJunc();
	void TrafficSig_CurrentJunc();

};

extern traffic_ctlr tc;
#endif