# RohitCore-Timer

A lightweight, non-blocking timer and task scheduler for Arduino using `millis()`.  
Designed to replace `delay()` and enable efficient multitasking on Arduino boards.

Part of the **RohitCore ecosystem**.

---

## 🚀 Features

- ⏱️ Non-blocking timing (no `delay()`)
- 🔁 Repeated task scheduling
- ⏳ One-time delayed task execution
- ⚡ Lightweight and efficient
- 🔗 Seamless integration with RohitCore-Base

---

## 🧰 Supported Boards

- Arduino UNO  
- Arduino Nano  
- ESP32  

---

## 📦 Installation

### Method 1: Arduino Library Manager (Recommended)
1. Open Arduino IDE  
2. Go to **Sketch → Include Library → Manage Libraries**  
3. Search for **RohitCore-Timer**  
4. Click **Install**

> ⚠️ This library depends on **RohitCore-Base**, which will be installed automatically.

---

## 🧪 Example Usage

```cpp
#include <RohitCoreTimer.h>

RohitCoreTimer timer;

void blink() {
  Serial.println("Running every 1 second");
}

void onceTask() {
  Serial.println("Runs after 5 seconds");
}

void setup() {
  Serial.begin(115200);

  timer.every(1000, blink);     // Runs every 1 second
  timer.after(5000, onceTask);  // Runs once after 5 seconds
}

void loop() {
  timer.update();  // Must be called continuously
}
