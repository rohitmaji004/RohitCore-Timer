#include <RohitCoreTimer.h>

RohitCoreTimer timer;

void blink() {
  Serial.println("Blink every 1 second");
}

void onceTask() {
  Serial.println("Runs after 5 seconds");
}

void setup() {
  Serial.begin(115200);

  timer.every(1000, blink);
  timer.after(5000, onceTask);
}

void loop() {
  timer.update();
}
