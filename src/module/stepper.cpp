#include "module\stepper.h"

#include <Arduino.h>

// include ESP-IDF libraries
#include "esp_log.h"
#include "freeRTOS\freertos.h"
#include "freeRTOS\task.h"

// include custom libraries
#include "header.h"

#define STEPPER_TAG "stepper"

esp_err_t init_stepper() {
    gpio_config_t io_conf = {
        .pin_bit_mask   = A4988_PIN_MASK,
        .mode           = GPIO_MODE_OUTPUT,
        .pull_up_en     = GPIO_PULLUP_DISABLE,
        .pull_down_en   = GPIO_PULLDOWN_DISABLE,
        .intr_type      = GPIO_INTR_DISABLE,
    };

    esp_err_t err = gpio_config(&io_conf);

    if(err != ESP_OK) {
        ESP_LOGE(STEPPER_TAG, "gpio_config() failed with error %d", err);
        return err;
    }

    gpio_set_level(A4988_FR_DIR,  0);
    gpio_set_level(A4988_FR_STEP, 0);

    gpio_set_level(A4988_FL_DIR,  0);
    gpio_set_level(A4988_FL_STEP, 0);

    gpio_set_level(A4988_BR_DIR,  0);
    gpio_set_level(A4988_BR_STEP, 0);

    gpio_set_level(A4988_BL_DIR,  0);
    gpio_set_level(A4988_BL_STEP, 0);

    ESP_LOGI(STEPPER_TAG, "init_stepper() success");
    return err;
}

void control_stepper(stepper_mode_t mode, uint64_t time, uint64_t *step) {
    static unsigned long last_time = 0;
    if(millis() - last_time < time) {
        return;
    }

    static stepper_mode_t last_mode = STEPPER_FORWARD;
    static bool last_step = 0;
    last_step = !last_step;

    if(last_mode != mode) {
        last_mode = mode;

        gpio_set_level(A4988_FR_STEP, 0);
        gpio_set_level(A4988_FL_STEP, 0);
        gpio_set_level(A4988_BR_STEP, 0);
        gpio_set_level(A4988_BL_STEP, 0);

        gpio_set_level(A4988_FR_DIR,  mode & 0x01);
        gpio_set_level(A4988_FL_DIR,  mode & 0x02);
        gpio_set_level(A4988_BR_DIR,  mode & 0x04);
        gpio_set_level(A4988_BL_DIR,  mode & 0x08);

        last_step = true;
    }

    if(last_step) {
        gpio_set_level(A4988_FR_STEP, mode & 0x10);
        gpio_set_level(A4988_FL_STEP, mode & 0x20);
        gpio_set_level(A4988_BR_STEP, mode & 0x40);
        gpio_set_level(A4988_BL_STEP, mode & 0x80);

    } else {
        gpio_set_level(A4988_FR_STEP, 0);
        gpio_set_level(A4988_FL_STEP, 0);
        gpio_set_level(A4988_BR_STEP, 0);
        gpio_set_level(A4988_BL_STEP, 0);

        if(step != NULL) {
            *step += 1;
        }
    }

    // ESP_LOGI(STEPPER_TAG, "control_stepper() last_step: %d, mode: %d, time: %d", last_step, (int)mode, time);
    last_time = millis();
}
