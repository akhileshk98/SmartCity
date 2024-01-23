#include <Arduino_FreeRTOS.h>
#include <semphr.h>
#include "TrafficController.h"
#include "CongestionMonitor.h"

congestion_mtr cm;
traffic_ctlr tc;

// Task handles
TaskHandle_t xTask1;
TaskHandle_t xTask2;
TaskHandle_t xTask3;
TaskHandle_t xTask4;

// Semaphore for synchronization between Task1 and Task2
SemaphoreHandle_t xTask12Sync;

// Semaphore for synchronization between Task3 and Task4
SemaphoreHandle_t xTask34Sync;

// Task periods (in milliseconds)
#define TASK1_PERIOD 100
#define TASK2_PERIOD 200
#define TASK3_PERIOD 300
#define TASK4_PERIOD 400

// Task next release times
TickType_t xTask1NextRelease;
TickType_t xTask2NextRelease;
TickType_t xTask3NextRelease;
TickType_t xTask4NextRelease;

// Task functions
void vTask1(void* pvParameters);
void vTask2(void* pvParameters);
void vTask3(void* pvParameters);
void vTask4(void* pvParameters);

void CreateTasks()
{

  // Create Task1 with priority 1
  xTaskCreate(
    vTask1,
    "Task1",
    128,
    NULL,
    1,
    &xTask1);

  // Create Task2 with priority 2
  xTaskCreate(
    vTask2,
    "Task2",
    128,
    NULL,
    2,
    &xTask2);

  // Create Task3 with priority 3
  xTaskCreate(
    vTask3,
    "Task3",
    128,
    NULL,
    3,
    &xTask3);

  // Create Task4 with priority 4
  xTaskCreate(
    vTask4,
    "Task4",
    128,
    NULL,
    4,
    &xTask4);
}


void setup() {
  Serial.begin(250000);

  cm.Initialize_Setup();

  // Initialize synchronization semaphores
  xTask12Sync = xSemaphoreCreateBinary();
  xTask34Sync = xSemaphoreCreateBinary();

  // Initialize task next release times
  xTask1NextRelease = xTaskGetTickCount();
  xTask2NextRelease = xTaskGetTickCount();
  xTask3NextRelease = xTaskGetTickCount();
  xTask4NextRelease = xTaskGetTickCount();

  CreateTasks();

  // Start the FreeRTOS scheduler
  vTaskStartScheduler();
}

void loop() {
  // The scheduler should never return, but if it does, there's an error
  for (;;) {
  }
}


void vTask1(void* pvParameters) {
  for (;;) {

    // Task 1 logic
    cm.CongStat_CurrentJunc();

       // Notify Task 2 to execute
    xSemaphoreGive(xTask12Sync);



    xTask1NextRelease += pdMS_TO_TICKS(TASK1_PERIOD);
    vTaskDelayUntil(&xTask1NextRelease, pdMS_TO_TICKS(TASK1_PERIOD));
  }
}

void vTask2(void* pvParameters) {
  for (;;) {
    // Wait for Task 1 to notify
    xSemaphoreTake(xTask12Sync, portMAX_DELAY);

    tc.TrafficSig_PreviousJunc();

    // Wait for the next period
    xTask2NextRelease += pdMS_TO_TICKS(TASK2_PERIOD);
    vTaskDelayUntil(&xTask2NextRelease, pdMS_TO_TICKS(TASK2_PERIOD));
  }
}

void vTask3(void* pvParameters) {
  for (;;) {
    // Task 3 logic
    cm.CongeStat_NextJuncs();

    // Notify Task 4 to execute
    xSemaphoreGive(xTask34Sync);

    // Wait for the next period
    xTask3NextRelease += pdMS_TO_TICKS(TASK3_PERIOD);
    vTaskDelayUntil(&xTask3NextRelease, pdMS_TO_TICKS(TASK3_PERIOD));
  }
}

void vTask4(void* pvParameters) {
  for (;;) {
    // Wait for Task 3 to notify
    xSemaphoreTake(xTask34Sync, portMAX_DELAY);

    // Task 4 logic
    tc.TrafficSig_CurrentJunc();

    // Wait for the next period
    xTask4NextRelease += pdMS_TO_TICKS(TASK4_PERIOD);
    vTaskDelayUntil(&xTask4NextRelease, pdMS_TO_TICKS(TASK4_PERIOD));
  }

}

