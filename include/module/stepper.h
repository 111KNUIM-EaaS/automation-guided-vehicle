#ifndef __STEPPER_H__
#define __STEPPER_H__

#include "esp_err.h"

typedef enum {
    STEPPER_STOP = 0x00, // 0b00000000 Stop

    // Straight movement
    STEPPER_FORWARD  = 0xF0, // 0b11110000 Straight forward
    STEPPER_BACKWARD = 0xFF, // 0b11111111 Straight backward

    // Diagonal movement
    STEPPER_FORWARD_RIGHT  = 0x60, // 0b01100000 Diagonal forward right
    STEPPER_FORWARD_LEFT   = 0x90, // 0b10010000 Diagonal forward left
    STEPPER_BACKWARD_RIGHT = 0x9F, // 0b10011111 Diagonal backward right
    STEPPER_BACKWARD_LEFT  = 0x6F, // 0b01101111 Diagonal backward left

    // Side way movement
    STEPPER_LEFT  = 0xF6, // 0b11110110 Side way left
    STEPPER_RIGHT = 0xF9, // 0b11111001 Side way right

    // Turn round movement
    STEPPER_TURN_COUNTERCLOCKWISE = 0xFA, // 0b11111010 Turn round counterclockwise
    STEPPER_TURN_CLOCKWISE        = 0xF5, // 0b11110101 Turn round clockwise

    // Turn of rear axis
    STEPPER_TURN_REAR_BACK_COUNTERCLOCKWISE  = 0xC8, // 0b11001000 Turn of rear axis back counterclockwise
    STEPPER_TURN_REAR_BACK_CLOCKWISE         = 0xC4, // 0b11000100 Turn of rear axis back clockwise
    STEPPER_TURN_REAR_FRONT_COUNTERCLOCKWISE = 0x32, // 0b00110010 Turn of rear axis front counterclockwise
    STEPPER_TURN_REAR_FRONT_CLOCKWISE        = 0x35, // 0b00110101 Turn of rear axis front clockwise

    // Concerning
    STEPPER_CONCERNING_RIGHT_CLOCKWISE        = 0x5F, // 0b01011111 Concerning right clockwise
    STEPPER_CONCERNING_RIGHT_COUNTERCLOCKWISE = 0x50, // 0b01010000 Concerning right counterclockwise
    STEPPER_CONCERNING_LEFT_CLOCKWISE         = 0xAF, // 0b10101111 Concerning left clockwise
    STEPPER_CONCERNING_LEFT_COUNTERCLOCKWISE  = 0xA0, // 0b10100000 Concerning left counterclockwise
} stepper_mode_t;

esp_err_t init_stepper();
void control_stepper(stepper_mode_t mode, uint64_t time, uint64_t *step);

#endif // __STEPPER_H__