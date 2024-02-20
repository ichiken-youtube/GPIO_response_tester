#define GPIO_OUT_SET (sio_hw->gpio_set)
#define GPIO_OUT_CLR (sio_hw->gpio_clr)

void setup() {
  // ピン16を出力として設定
  pinMode(16, OUTPUT);
  while(1){
    GPIO_OUT_SET |= 1ul << 16;
    GPIO_OUT_CLR |= 1ul << 16;
  }

}

void loop() {

}