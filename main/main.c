// for printf
#include <stdio.h>
// for LEDs and other GPIOs
#include "driver/gpio.h"
// RTOS, handles tasks and delays
#include "freertos/FreeRTOS.h"
// RTC (Real Time Clock) starts ticking at startup
#include "rtc.h"

// seemingly unused imports:
// #include "sdkconfig.h"
// #include "freertos/task.h"

// 100 ms
#define PAUSE_TIME 100

// light is at GPIO 2
#define BLINK_GPIO 2

static uint8_t s_led_state = 0;

// important step to set the GPIO as output
void configure_led(void)
{
    esp_rom_gpio_pad_select_gpio(BLINK_GPIO);
    // Set the GPIO as a push/pull output
    gpio_set_direction(BLINK_GPIO, GPIO_MODE_OUTPUT);
}

void blink_led(void)
{
    uint64_t startTime = esp_rtc_get_time_us();
    int blinks = 0;
    while (true)
    {
        // switch LED state
        s_led_state = !s_led_state;
        // print over serial
        printf("Turning the LED %s! GPIO:%d, Blinked % 4i times. Time passed: %f\n", s_led_state == false ? "  ON" : " OFF", BLINK_GPIO, blinks, ((float)esp_rtc_get_time_us() - startTime) / 1000000);
        // set to new state
        gpio_set_level(BLINK_GPIO, s_led_state);
        blinks++;
        // delay a bit
        vTaskDelay(PAUSE_TIME / portTICK_PERIOD_MS);
    }
}

void app_main(void)
{
    configure_led();
    blink_led();
}
