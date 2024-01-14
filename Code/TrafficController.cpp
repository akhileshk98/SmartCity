#include "TrafficController.h"
#include "CongestionMonitor.h"


void traffic_ctlr::TrafficSig_PreviousJunc()
{
    if (cj.congStat_Curr == HIGH)
    {
        Serial.println("Traffic Signal in Previous Signal turns RED \0");
    }
    else
    {
        Serial.println("Traffic Signal in Previous Signal Normal Flow \0");
    }
}


void traffic_ctlr::TrafficSig_CurrentJunc()
{
    if (cj.congStat_Curr == HIGH)
    {
        if (cj.congStat_R1 == LOW && cj.congStat_R2 == LOW && cj.congStat_R3 == LOW) {
            Serial.println("R1,R2,R3 Opened");
        }
        else if (cj.congStat_R1 == LOW && cj.congStat_R2 == LOW && cj.congStat_R3 == HIGH) {
            Serial.println("R1,R2 Opened");
        }
        else if (cj.congStat_R1 == LOW && cj.congStat_R2 == HIGH && cj.congStat_R3 == LOW) {
            Serial.println("R1,R3 Opened");
        }
        else if (cj.congStat_R1 == LOW && cj.congStat_R2 == HIGH && cj.congStat_R3 == HIGH) {
            Serial.println("R1 Opened");
        }
        else if (cj.congStat_R1 == HIGH && cj.congStat_R2 == LOW && cj.congStat_R3 == LOW) {
            Serial.println("R2, R3 Opened");
        }
        else if (cj.congStat_R1 == HIGH && cj.congStat_R2 == LOW && cj.congStat_R3 == HIGH) {
            Serial.println("R2 Opened");
        }
        else if (cj.congStat_R1 == HIGH && cj.congStat_R2 == HIGH && cj.congStat_R3 == LOW) {
            Serial.println("R3 Opened");
        }
        else if (cj.congStat_R1 == HIGH && cj.congStat_R2 == HIGH && cj.congStat_R3 == HIGH) {
            Serial.println("No Routes Available for Rerouting");
        }

    }
    else {
        Serial.println("Normal Traffic Conditions in Current Junction");
    }

}


// Constructor
traffic_ctlr::traffic_ctlr()
{

}


