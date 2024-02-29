/* Blink Example

   This example code is in the Public Domain (or CC0 licensed, at your option.)

   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.
*/
#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "esp_log.h"
#include "sdkconfig.h"
#include "esp_system.h"

// Definimos LEDS //

#define D1 GPIO_NUM_4
#define D2 GPIO_NUM_16
#define D3 GPIO_NUM_17
#define D4 GPIO_NUM_5
#define D5 GPIO_NUM_18
#define MAX     4

// Definimos switches //

#define SW1 GPIO_NUM_27
#define SW2 GPIO_NUM_26
#define SW3 GPIO_NUM_35
#define SW4 GPIO_NUM_33



//Led Array//
uint8_t ledArray[] = {

    D1, D2, D3, D4, D5
};




// Estado del led //
//static uint8_t s_led_state = 0;

static void initIO(){

    gpio_reset_pin(D1);
    gpio_reset_pin(D2);
    gpio_reset_pin(D3);
    gpio_reset_pin(D4);
    gpio_reset_pin(D5);

    gpio_reset_pin(SW1);
    gpio_reset_pin(SW2);
    gpio_reset_pin(SW3);
    gpio_reset_pin(SW4);

    gpio_set_direction(D1, GPIO_MODE_OUTPUT);
    gpio_set_direction(D2, GPIO_MODE_OUTPUT);
    gpio_set_direction(D3, GPIO_MODE_OUTPUT);
    gpio_set_direction(D4, GPIO_MODE_OUTPUT);
    gpio_set_direction(D5, GPIO_MODE_OUTPUT);

    gpio_set_direction(SW1, GPIO_MODE_INPUT);
    gpio_set_direction(SW2, GPIO_MODE_INPUT);
    gpio_set_direction(SW3, GPIO_MODE_INPUT);
    gpio_set_direction(SW4, GPIO_MODE_INPUT);

    gpio_set_pull_mode(SW1, GPIO_PULLUP_ENABLE);
    gpio_set_pull_mode(SW2, GPIO_PULLUP_ENABLE);
    gpio_set_pull_mode(SW3, GPIO_PULLUP_ENABLE);
    gpio_set_pull_mode(SW4, GPIO_PULLUP_ENABLE);
}

void updateLed(uint8_t ledNumber, uint8_t status) {

    gpio_set_level(ledArray[ledNumber], status);
}


void delayMs(uint16_t ms)
{
    vTaskDelay(ms / portTICK_PERIOD_MS);
}

void app_main(void) {
    /* Configure the peripheral according to the LED type */
    initIO();

    while (1) {

        if(gpio_get_level(SW1) == 0 && gpio_get_level(SW2) == 0 && gpio_get_level(SW3) == 0 && gpio_get_level(SW4) == 0) {
            updateLed(0,1);
            delayMs(100);
            updateLed(1,1);
            delayMs(100);
            updateLed(2,1);
            delayMs(100);
            updateLed(3,1);
            delayMs(100);
            updateLed(4,1);
            delayMs(100);
            updateLed(0,0);
            updateLed(1,0);
            updateLed(2,0);
            updateLed(3,0);
            updateLed(4,0);
            printf("No switch pressed.\n");
        }

        if(gpio_get_level(SW1) == 1 && gpio_get_level(SW2) == 0 && gpio_get_level(SW3) == 0 && gpio_get_level(SW4) == 0) {
            updateLed(0,1);
            delayMs(100);
            updateLed(1,1);
            delayMs(100);
            updateLed(2,1);
            delayMs(100);
            updateLed(0,0);
            updateLed(1,0);
            updateLed(2,0);
            delayMs(1000);
            updateLed(0,1);
            updateLed(1,1);
            updateLed(2,1);
            delayMs(1000);
            updateLed(0,0);
            updateLed(1,0);
            updateLed(2,0);
            printf("Switch 1 pressed.\n");
        }

        if(gpio_get_level(SW1) == 0 && gpio_get_level(SW2) == 1 && gpio_get_level(SW3) == 0 && gpio_get_level(SW4) == 0) {
            updateLed(2,1);
            delayMs(100);
            updateLed(3,1);
            delayMs(100);
            updateLed(4,1);
            delayMs(100);
            updateLed(2,0);
            updateLed(3,0);
            updateLed(4,0);
            delayMs(1000);
            updateLed(2,1);
            updateLed(3,1);
            updateLed(4,1);
            delayMs(1000);
            updateLed(2,0);
            updateLed(3,0);
            updateLed(4,0);
            printf("Switch 2 pressed.\n");
        }
        //Speed
        if(gpio_get_level(SW1) == 0 && gpio_get_level(SW2) == 0 && gpio_get_level(SW3) == 1 && gpio_get_level(SW4) == 0) {
            updateLed(0,1);
            delayMs(50);
            updateLed(1,1);
            delayMs(50);
            updateLed(2,1);
            delayMs(50);
            updateLed(3,1);
            delayMs(50);
            updateLed(4,1);
            delayMs(50);
            updateLed(0,0);
            updateLed(1,0);
            updateLed(2,0);
            updateLed(3,0);
            updateLed(4,0);
            printf("Speed +1 and no switch pressed.\n");
        }

        if(gpio_get_level(SW1) == 1 && gpio_get_level(SW2) == 0 && gpio_get_level(SW3) == 1 && gpio_get_level(SW4) == 0) {
            updateLed(0,1);
            delayMs(50);
            updateLed(1,1);
            delayMs(50);
            updateLed(2,1);
            delayMs(50);
            updateLed(0,0);
            updateLed(1,0);
            updateLed(2,0);
            delayMs(500);
            updateLed(0,1);
            updateLed(1,1);
            updateLed(2,1);
            delayMs(500);
            updateLed(0,0);
            updateLed(1,0);
            updateLed(2,0);
            printf("Speed +1 Switch 1 pressed.\n");
        }

        if(gpio_get_level(SW1) == 0 && gpio_get_level(SW2) == 1 && gpio_get_level(SW3) == 1 && gpio_get_level(SW4) == 0) {
            updateLed(2,1);
            delayMs(50);
            updateLed(3,1);
            delayMs(50);
            updateLed(4,1);
            delayMs(50);
            updateLed(2,0);
            updateLed(3,0);
            updateLed(4,0);
            delayMs(500);
            updateLed(2,1);
            updateLed(3,1);
            updateLed(4,1);
            delayMs(500);
            updateLed(2,0);
            updateLed(3,0);
            updateLed(4,0);
            printf("Speed +1 Switch 2 pressed.\n");
        }
        //Slow
        if(gpio_get_level(SW1) == 0 && gpio_get_level(SW2) == 0 && gpio_get_level(SW3) == 0 && gpio_get_level(SW4) == 1) {
            updateLed(0,1);
            delayMs(1000);
            updateLed(1,1);
            delayMs(1000);
            updateLed(2,1);
            delayMs(1000);
            updateLed(3,1);
            delayMs(1000);
            updateLed(4,1);
            delayMs(1000);
            updateLed(0,0);
            updateLed(1,0);
            updateLed(2,0);
            updateLed(3,0);
            updateLed(4,0);
            printf("Speed -1 and no switch pressed.\n");
        }

        if(gpio_get_level(SW1) == 1 && gpio_get_level(SW2) == 0 && gpio_get_level(SW3) == 0 && gpio_get_level(SW4) == 1) {
            updateLed(0,1);
            delayMs(1000);
            updateLed(1,1);
            delayMs(1000);
            updateLed(2,1);
            delayMs(1000);
            updateLed(0,0);
            updateLed(1,0);
            updateLed(2,0);
            delayMs(1000);
            updateLed(0,1);
            updateLed(1,1);
            updateLed(2,1);
            delayMs(1000);
            updateLed(0,0);
            updateLed(1,0);
            updateLed(2,0);
            printf("Speed -1 Switch 1 pressed.\n");
        }

        if(gpio_get_level(SW1) == 0 && gpio_get_level(SW2) == 1 && gpio_get_level(SW3) == 0 && gpio_get_level(SW4) == 1) {
            updateLed(2,1);
            delayMs(1000);
            updateLed(3,1);
            delayMs(1000);
            updateLed(4,1);
            delayMs(1000);
            updateLed(2,0);
            updateLed(3,0);
            updateLed(4,0);
            delayMs(1000);
            updateLed(2,1);
            updateLed(3,1);
            updateLed(4,1);
            delayMs(1000);
            updateLed(2,0);
            updateLed(3,0);
            updateLed(4,0);
            printf("Speed -1 Switch 2 pressed.\n");
        }
    }
}
