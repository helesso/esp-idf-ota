#include "driver/gpio.h"
#include "sensor.h"
#define INPUT_GPIO GPIO_NUM_13
void input_init(void){
    gpio_reset_pin(INPUT_GPIO);
    gpio_set_direction(INPUT_GPIO, GPIO_MODE_INPUT);
    gpio_set_pull_mode(INPUT_GPIO,GPIO_PULLDOWN_ONLY);
}
int input_read(void){
    return gpio_get_level(INPUT_GPIO);
}
