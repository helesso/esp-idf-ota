#include "esp_ota_ops.h"
#include "driver/gpio.h"
#include "esp_log.h"
#include "sensor.h"
#include "esp_rom_sys.h" 
#define TAG "MAIN_APP"
void delay(int d) {
    esp_rom_delay_us(d * 1000);
}
void app_main() {
    const esp_partition_t* running = esp_ota_get_running_partition();
    esp_ota_img_states_t ota_state;
    if (esp_ota_get_state_partition(running, &ota_state) == ESP_OK) {
        if (ota_state == ESP_OTA_IMG_PENDING_VERIFY) {
            esp_ota_mark_app_valid_cancel_rollback();
        }
    }
    input_init();
    led_init();
    while (1) {
        if (input_read() == 1){
            ESP_LOGI("INPUT","есть напряжение");
            
            led_on();
            ESP_LOGI("LED","горит 1 секунду");
            delay(1000);
            
            led_off();
            ESP_LOGI("LED","не горит 1 секунду");
            delay(1000);
            
            led_on();
            ESP_LOGI("LED","горит 2 секунды");
            delay(2000);
            
            led_off();
            ESP_LOGI("LED","не горит 2 секунды");
            delay(2000);
        } else {
            led_off();
            ESP_LOGI("INPUT","НЕТ НАПРЯЖЕНИЯ");
            delay(500);
        }
    }
}
