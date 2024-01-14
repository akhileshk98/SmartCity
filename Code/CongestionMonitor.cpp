#include "CongestionMonitor.h"
#include "TrafficController.h"


// This functions checks the current status of congestion in initial traffic
void congestion_mtr::CongStat_CurrentJunc()
{
	CongStat_Curr = true;
	if(CongStat_Curr == true)
	{
		Serial.println("Congestion Detected in Current Route");
	}else
	{
		Serial.println("No Congestion Detected in Current Route");
	}
}

void congestion_mtr::CongeStat_NextJuncs()
{
	if (CongStat_Route1 == false && CongStat_Route2 == false && CongStat_Route3 == true)
	{
		Serial.println("No Congestion in Alternate Route 1 and 2");
	}else
	{
		Serial.println("Congestion Status in Next Junctions Check");
	}

}


// Constructor
congestion_mtr::congestion_mtr()
{

}
