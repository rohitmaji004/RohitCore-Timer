#ifndef RohitCoreTimer_h
#define RohitCoreTimer_h

#include <Arduino.h>
#include <RohitCoreBase.h>

#define MAX_TASKS 10

typedef void (*TaskCallback)();

struct Task {
  unsigned long interval;
  unsigned long lastRun;
  TaskCallback callback;
  bool repeat;
  bool active;
};

class RohitCoreTimer {
  public:
    RohitCoreTimer();

    void every(unsigned long interval, TaskCallback callback);
    void after(unsigned long delayTime, TaskCallback callback);
    void update();

  private:
    Task tasks[MAX_TASKS];
};

#endif
