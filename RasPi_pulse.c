#include <gpiod.h>
#include <stdio.h>
#include <unistd.h>

#define LED_PIN 21
#define CONSUMER "gpio_control_consumer"

int main(void) {
    struct gpiod_chip *chip;
    struct gpiod_line *led_line;
    bool out_flag;

    // GPIOチップを開く
    chip = gpiod_chip_open("/dev/gpiochip0");
    if (!chip) {
        perror("gpiod_chip_open failed");
        return 1;
    }

    // GPIOピンを取得
    led_line = gpiod_chip_get_line(chip, LED_PIN);

    if (!led_line) {
        perror("gpiod_chip_get_line failed");
        gpiod_chip_close(chip);
        return 1;
    }

    // LEDピンを出力として設定
    if (gpiod_line_request_output(led_line, CONSUMER, 0) < 0) {
        perror("gpiod_line_request_output failed");
        gpiod_chip_close(chip);
        return 1;
    }

    // メインループ
    while (1) {

        // ボタンが押されている（HIGH）場合はLEDを点灯
        if (out_flag) {
            gpiod_line_set_value(led_line, 1);
        } else {
            // ボタンが離された（LOW）場合はLEDを消灯
            gpiod_line_set_value(led_line, 0);
        }

        out_flag!=out_flag;
    }

    // リソースを解放
    gpiod_line_release(led_line);
    gpiod_chip_close(chip);

    return 0;
}
