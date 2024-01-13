#include <Arduino_FreeRTOS.h>
#include <semphr.h>
#include "TrafficController.h"
#include "CongestionMonitor.h"

traffic_ctlr tc;
congestion_mtr cj;

// Task handles
TaskHandle_t xTask1;
TaskHandle_t xTask2;

// Semaphore for synchronization
SemaphoreHandle_t xTaskSync;

// Task periods (in milliseconds)
#define TASK1_PERIOD 1000
#define TASK2_PERIOD 2000

// Task next release times
TickType_t xTask1NextRelease;
TickType_t xTask2NextRelease;

// Task functions
void vTask1(void* pvParameters);
void vTask2(void* pvParameters);

void setup() {
    Serial.begin(9600);

    // Initialize synchronization semaphore
    xTaskSync = xSemaphoreCreateBinary();

    // Initialize task next release times
    xTask1NextRelease = xTaskGetTickCount();
    xTask2NextRelease = xTaskGetTickCount();

    // Create Task1 with priority 1
    xTaskCreate(vTask1, "Task1", 128, NULL, 1, &xTask1);

    // Create Task2 with priority 2
    xTaskCreate(vTask2, "Task2", 128, NULL, 2, &xTask2);

    // Start the FreeRTOS scheduler
    vTaskStartScheduler();
}

void loop() {
    // The scheduler should never return, but if it does, there's an error
    for (;;) {}
}

void vTask1(void* pvParameters) {
    for (;;) {
        // Perform Task 1 activity
        Serial.println("Task1 is running...");
        cj.CongestionMonitorTask();

        // Notify Task 2 to execute
        xSemaphoreGive(xTaskSync);

        // Wait for the next period
        xTask1NextRelease += pdMS_TO_TICKS(TASK1_PERIOD);
        vTaskDelayUntil(&xTask1NextRelease, pdMS_TO_TICKS(TASK1_PERIOD));
    }
}

void vTask2(void* pvParameters) {
    for (;;) {
        // Wait for Task 1 to notify
        xSemaphoreTake(xTaskSync, portMAX_DELAY);

        // Perform Task 2 activity
        Serial.println("Task2 is running...");
        tc.TrafficControllerTask();

        // Wait for the next period
        xTask2NextRelease += pdMS_TO_TICKS(TASK2_PERIOD);
        vTaskDelayUntil(&xTask2NextRelease, pdMS_TO_TICKS(TASK2_PERIOD));
    }
}
