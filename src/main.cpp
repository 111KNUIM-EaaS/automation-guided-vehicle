#include <Arduino.h>
#include <EaaS.h>

#include "header.h"
#include "module/stepper.h"

unsigned long stepper_time = 0;

uint64_t stepper_step = 0;

extern uint8_t task_status;

void setup() {
    init_EaaS();

    init_stepper();
}

void loop() {
    EaaS_OTA();
    
    if(task_status == 0) {
        control_stepper(STEPPER_STOP, 4, NULL);
    }

    if(task_status == 1) {
        if(stepper_step < 500) {
            control_stepper(STEPPER_FORWARD, 4, &stepper_step);

        } else if(stepper_step < 1000) {
            control_stepper(STEPPER_LEFT, 4, &stepper_step);

        } else if(stepper_step < 1500) {
            control_stepper(STEPPER_BACKWARD, 4, &stepper_step);

        } else if(stepper_step < 2000) {
            control_stepper(STEPPER_RIGHT, 4, &stepper_step);

        } else {
            stepper_step = 0;
        }
    }
}
