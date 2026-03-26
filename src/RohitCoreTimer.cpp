#include "RohitCore-Timer.h"

RohitCoreTimer::RohitCoreTimer() {
  for (int i = 0; i < MAX_TASKS; i++) {
    tasks[i].active = false;
  }
}

void RohitCoreTimer::every(unsigned long interval, TaskCallback callback) {
  for (int i = 0; i < MAX_TASKS; i++) {
    if (!tasks[i].active) {
      tasks[i] = {interval, millis(), callback, true, true};
      return;
    }
  }
  RohitCoreBase::log(RC_WARN, "No free task slots!");
}

void RohitCoreTimer::after(unsigned long delayTime, TaskCallback callback) {
  for (int i = 0; i < MAX_TASKS; i++) {
    if (!tasks[i].active) {
      tasks[i] = {delayTime, millis(), callback, false, true};
      return;
    }
  }
  RohitCoreBase::log(RC_WARN, "No free task slots!");
}

void RohitCoreTimer::update() {
  unsigned long now = millis();

  for (int i = 0; i < MAX_TASKS; i++) {
    if (tasks[i].active && (now - tasks[i].lastRun >= tasks[i].interval)) {
      tasks[i].callback();
      tasks[i].lastRun = now;

      if (!tasks[i].repeat) {
        tasks[i].active = false;
      }
    }
  }
}
