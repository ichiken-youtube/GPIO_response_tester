# GPIO_response-_tester
イチケンがRaspberryPi5のレビュー動画内で使用した、RasPiシリーズ各種やマイコンのGPIOピンの応答速度を計測するためのプログラムです。  

# RaspberryPi4/5
RaspberryPiのGPIOピン20に入力スイッチ、21に出力が繋がるように配線してください。  

libgpiodが必要です。
```
$ sudo apt install libgpiod2 libgpiod-dev libgpiod-doc
```
gccでコンパイルしてください。
```
$ gcc RasPi_***.c -lgpiod
```
スイッチを押している間だけ出力がHighになります。  
入力ピンと出力ピンの立ち上がりの時間差をオシロスコープで観察してください。  
なぜPi5はPi4より遅いのか、さらにそれらは後述のマイコンより遅いのか、そしてなぜ応答速度にバラつきがあるのかについては動画内で解説しています。ぜひご覧ください。  

# マイコン
