#include <stdio.h>

#include "driver/gpio.h"
#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "sdkconfig.h"
#include "string.h"
// #include "taskdelayuntil"

// #include "wroom_log.h"

// 500 ms
#define PAUSE_TIME 100
// light is at GPIO 2
#define BLINK_GPIO 2

static uint8_t s_led_state = 0;

// important step to set the GPIO as output
void configure_led(void)
{
    esp_rom_gpio_pad_select_gpio(BLINK_GPIO);
    /* Set the GPIO as a push/pull output */
    gpio_set_direction(BLINK_GPIO, GPIO_MODE_OUTPUT);
}

void blink_led(void)
{
    int blinks = 0;
    while (true)
    {
        // switch LED state
        s_led_state = !s_led_state;
        // print over serial
        printf("Turning the LED %s! GPIO:%d, Blinked % 4i times.\n", s_led_state == false ? "  ON" : " OFF", BLINK_GPIO, blinks);
        // set to new state
        gpio_set_level(BLINK_GPIO, s_led_state);
        blinks++;
        // delay a bit
        vTaskDelay(PAUSE_TIME / portTICK_PERIOD_MS);
    }
}

void app_main(void)
{
    /* Configure the peripheral according to the LED type */
    configure_led();
    blink_led();
}