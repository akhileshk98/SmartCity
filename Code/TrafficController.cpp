#include "TrafficController.h"
#include "CongestionMonitor.h"


void traffic_ctlr::TrafficSig_PreviousJunc()
{
	if (cj.CongStat_Curr == true)
	{
		Serial.println("Traffic Signal in Previous Signal turns RED");
	}else
	{
		Serial.println("Traffic Signal in Previous Signal Normal Flow");
	}
}


void traffic_ctlr::TrafficSig_CurrentJunc()
{
	if(cj.CongStat_Route1 == false && cj.CongStat_Route2 == false && cj.CongStat_Route3 == true && cj.CongStat_Curr == true)
	{
		Serial.println("Traffic Signal directs Vehicles to take Route 1 and Route 2");
	}
	else
	{
		Serial.println("Traffic Signal in Current Junc Normal Flow");
	}
}


// Constructor
traffic_ctlr::traffic_ctlr()
{

}


