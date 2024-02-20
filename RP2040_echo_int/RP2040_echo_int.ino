#define GPIO_OUT_SET (sio_hw->gpio_set)
#define GPIO_OUT_CLR (sio_hw->gpio_clr)
#define GPIO_IN_BTN (sio_hw->gpio_in)

void setup() {
  pinMode(16, OUTPUT);
  pinMode(17, INPUT_PULLUP);
  GPIO_OUT_CLR |= 1ul << 16;
  attachInterrupt(digitalPinToInterrupt(17),set,FALLING);

}

void loop() {
  delay(3000);
  GPIO_OUT_CLR |= 1ul << 16;
}

void set(){
  GPIO_OUT_SET |= 1ul << 16;
}