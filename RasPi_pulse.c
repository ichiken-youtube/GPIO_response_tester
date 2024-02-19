#include <gpiod.h>
#include <stdio.h>
#include <unistd.h>

#define LED_PIN 21
#define CONSUMER "gpio_control_consumer"

struct gpiod_chip *chip;
struct gpiod_line *led_line;

// SIGINTシグナルを受け取ったときに実行される関数
void signalHandler(int signalNumber) {
    // リソースを解放
    gpiod_line_release(led_line);
    gpiod_chip_close(chip);
    exit(0); // プログラムを正常に終了させる
}


int main(int argc, char *argv[]) {
    bool out_flag = true;

    // GPIOチップを開く
    // Pi4かPi5かを引数で与えると、それによって開くチップを変える
    if(argc == 1){
        chip = gpiod_chip_open("/dev/gpiochip0");
    }else{
        if(argv[1]=="pi4"){
            chip = gpiod_chip_open("/dev/gpiochip0");
        }else if(argv[1]=="pi5"){
            chip = gpiod_chip_open("/dev/gpiochip4");
        }else{
            chip = gpiod_chip_open("/dev/gpiochip0");
        }
    }
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

        if (out_flag) {
            gpiod_line_set_value(led_line, 1);
        } else {
            gpiod_line_set_value(led_line, 0);
        }

        out_flag=!out_flag;
    }

    return 0;
}
