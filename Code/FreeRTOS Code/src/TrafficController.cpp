#include "../include/CongestionMonitor.h"
#include "../include/TrafficController.h"


void traffic_ctlr::TrafficSig_PreviousJunc()
{
  if (cm.congStat_Curr == HIGH)
  {
    Serial.println("Traffic Light in Previous Signal turns RED \0");
  } else
  {
    Serial.println("Traffic Light in Previous Signal Normal Flow \0");
  }
}


void traffic_ctlr::TrafficSig_CurrentJunc()
{
  if (cm.congStat_Curr == HIGH)
  {
    if (cm.congStat_R1 == LOW && cm.congStat_R2 == LOW && cm.congStat_R3 == LOW) {
      Serial.println("R1,R2,R3 Opened");
    }
    else if (cm.congStat_R1 == LOW && cm.congStat_R2 == LOW && cm.congStat_R3 == HIGH) {
      Serial.println("R1,R2 Opened");
    }
    else if (cm.congStat_R1 == LOW && cm.congStat_R2 == HIGH && cm.congStat_R3 == LOW) {
      Serial.println("R1,R3 Opened");
    }
    else if (cm.congStat_R1 == LOW && cm.congStat_R2 == HIGH && cm.congStat_R3 == HIGH) {
      Serial.println("R1 Opened");
    }
    else if (cm.congStat_R1 == HIGH && cm.congStat_R2 == LOW && cm.congStat_R3 == LOW) {
      Serial.println("R2, R3 Opened");
    }
    else if (cm.congStat_R1 == HIGH && cm.congStat_R2 == LOW && cm.congStat_R3 == HIGH) {
      Serial.println("R2 Opened");
    }
    else if (cm.congStat_R1 == HIGH && cm.congStat_R2 == HIGH && cm.congStat_R3 == LOW) {
      Serial.println("R3 Opened");
    }
    else if (cm.congStat_R1 == HIGH && cm.congStat_R2 == HIGH && cm.congStat_R3 == HIGH) {
      Serial.println("No Routes Available for Rerouting");
    }

  } else{
		Serial.println("Normal Traffic Conditions in Current Junction");
	}

}


// Constructor
traffic_ctlr::traffic_ctlr()
{

}


