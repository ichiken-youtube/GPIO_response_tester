# 概要
イチケンが[RaspberryPi5のレビュー動画](https://youtu.be/KUwH7JNcvJ0)内で使用した、RasPiシリーズ各種やマイコンのGPIOピンの応答速度を計測するためのプログラムです。  

# RaspberryPi4/5
RaspberryPiのGPIOピン20に入力スイッチ、21に出力が繋がるように配線してください。  
入力ピンは内蔵プルダウンされている点に注意してください。  

libgpiodが必要です。
```
$ sudo apt install libgpiod2 libgpiod-dev libgpiod-doc
```
gccでコンパイルしてください。
```
$ gcc RasPi_***.c -lgpiod
```
スイッチを押している間だけ出力がHighになります。  

以下のようにpi5/pi4いずれかの引数を渡して実行します。  
```
$ ./RaspPi_pulse.out pi5
```

# マイコン
RP2040搭載のマイコン(この場合はRaspberryPi Pico)で出力を16、入力を17に接続してください。  
RaspberryPiでの計測と異なり、内蔵プルアップを使用している点に注意してください。  

# 計測について
入力ピンと出力ピンの立ち上がり、あるいは立ち下りの時間差をオシロスコープで観察してください。  
Pi4とPi5で応答速度の差はどうか、なぜPi5,Pi4はマイコンより遅いのか、そしてなぜ応答速度にバラつきがあるのかについては動画内で解説しています。ぜひご覧ください。  