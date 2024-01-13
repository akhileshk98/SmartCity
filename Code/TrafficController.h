
#ifndef traffic_controller
#define traffic_controller

#include<Arduino_FreeRTOS.h>
#include <Arduino.h>

class traffic_ctlr {
public:
	traffic_ctlr();

	void TrafficControllerTask();
	void TrafficSignalControl();
	void AckCongestionAlert();
	void AlternateRouteCongestion();
};

extern traffic_ctlr tc;
#endif