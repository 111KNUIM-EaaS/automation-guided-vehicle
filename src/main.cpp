#include <Arduino.h>
#include <EaaS.h>

#include "header.h"
#include "module/stepper.h"

unsigned long stepper_time = 0;

uint64_t stepper_step = 0;

extern uint8_t task_status;

#define STEPPER_MODE_LENGTH 12
stepper_mode_t stepper_mode[STEPPER_MODE_LENGTH] = {
    STEPPER_FORWARD,
    STEPPER_LEFT,
    STEPPER_BACKWARD,
    STEPPER_RIGHT,
    STEPPER_FORWARD_LEFT,
    STEPPER_BACKWARD_RIGHT,
    STEPPER_LEFT,
    STEPPER_FORWARD_RIGHT,
    STEPPER_BACKWARD_LEFT,
    STEPPER_RIGHT,
    STEPPER_TURN_COUNTERCLOCKWISE,
    STEPPER_TURN_CLOCKWISE,
};

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
        control_stepper(stepper_mode[(int)stepper_step / 500], 4, &stepper_step);

        if(stepper_step > STEPPER_MODE_LENGTH * 500) {
            stepper_step = 0;
        }
    }
}
