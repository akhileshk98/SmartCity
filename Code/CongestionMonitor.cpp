#include "CongestionMonitor.h"
#include "TrafficController.h"



void congestion_mtr::Initialize_Setup()
{
    pinMode(ledPin_Curr, OUTPUT);    // LED pin as an output.
    pinMode(ledPin_R1, OUTPUT);
    pinMode(ledPin_R2, OUTPUT);
    pinMode(ledPin_R3, OUTPUT);

    pinMode(buttonPin_Curr, INPUT);
    pinMode(buttonPin_R1, INPUT);
    pinMode(buttonPin_R2, INPUT);
    pinMode(buttonPin_R3, INPUT);  // Button pin as an input.
}

// This functions checks the current status of congestion in initial traffic
void congestion_mtr::CongStat_CurrentJunc()
{
    Serial.println("Task1 Started");
    congStat_Curr = digitalRead(buttonPin_Curr);
    if (congStat_Curr == HIGH) {
        digitalWrite(ledPin_Curr, HIGH);   // Turn LED on.
    }
    else {
        digitalWrite(ledPin_Curr, LOW);    // Turn LED off.
    }

}

void congestion_mtr::CongeStat_NextJuncs()
{
    Serial.println("Task 3 Running");

    congStat_R1 = digitalRead(buttonPin_R1);
    congStat_R2 = digitalRead(buttonPin_R2);
    congStat_R3 = digitalRead(buttonPin_R3);

    if (congStat_R1 == HIGH) {
        digitalWrite(ledPin_R1, HIGH);
    }
    else {
        digitalWrite(ledPin_R1, LOW);
    }

    if (congStat_R2 == HIGH) {
        digitalWrite(ledPin_R2, HIGH);
    }
    else {
        digitalWrite(ledPin_R2, LOW);
    }

    if (congStat_R3 == HIGH) {
        digitalWrite(ledPin_R3, HIGH);
    }
    else {
        digitalWrite(ledPin_R3, LOW);
    }

}


// Constructor
congestion_mtr::congestion_mtr()
{

}
