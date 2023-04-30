#ifndef __HEADER_H__
#define __HEADER_H__

#include "driver/gpio.h"

// A4988 pin
#define A4988_FR_DIR  (GPIO_NUM_4 )
#define A4988_FR_STEP (GPIO_NUM_15)

#define A4988_FL_DIR  (GPIO_NUM_17)
#define A4988_FL_STEP (GPIO_NUM_16)

#define A4988_BR_DIR  (GPIO_NUM_23)
#define A4988_BR_STEP (GPIO_NUM_19)

#define A4988_BL_DIR  (GPIO_NUM_5 )
#define A4988_BL_STEP (GPIO_NUM_18)

#define A4988_PIN_MASK (            \
    ( 1ULL << (A4988_FR_DIR ) ) |   \
    ( 1ULL << (A4988_FR_STEP) ) |   \
    ( 1ULL << (A4988_FL_DIR ) ) |   \
    ( 1ULL << (A4988_FL_STEP) ) |   \
    ( 1ULL << (A4988_BR_DIR ) ) |   \
    ( 1ULL << (A4988_BR_STEP) ) |   \
    ( 1ULL << (A4988_BL_DIR ) ) |   \
    ( 1ULL << (A4988_BL_STEP) )     \
)

#endif // __HEADER_H__
