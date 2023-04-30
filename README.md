# KNU Equipment as a Service(EaaS) for Automation Guided Vehicle

[![6.1.0](https://img.shields.io/badge/platform-espressif32%406.1.0-green)](https://github.com/platformio/platform-espressif32/releases/tag/v6.1.0)
[![ESP-IDF-v5.0.1](https://img.shields.io/badge/ESP--IDF-v5.0.1-blue)](https://docs.espressif.com/projects/esp-idf/en/v5.0.1/esp32/index.html)
![esp32doit](https://img.shields.io/badge/board-esp32doit--devkit--v1-lightgrey)
![arduino](https://img.shields.io/badge/framework-arduino-blue)

## Automation Guided Vehicle Image

![Automation Guided Vehicle](https://github.com/111KNUIM-EaaS/.github/releases/download/v0.0.0/agv.jpg)

## Include EaaS library

main.cpp

```cpp
#include <Arduino.h>
#include "EaaS/EaaS.h"

void setup() {
    init_EaaS();

    // Your code here
}

void loop() {
    EaaS_OTA();

    // Your code here
}
```

## Setup Release and Update Firmware
