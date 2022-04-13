## Opencvをvscodeで実行するための設定

### launch.jsonが生成されないのは仕方ないので諦めてください
#### task.json
```
"args": [
    "-fdiagnostics-color=always",
    "-g",
    "${file}",
    "-o",
    "${fileDirname}/${fileBasenameNoExtension}",
    "-I",
    "/usr/include/opencv4",
    "-l",
    "opencv_core",
    "-l",
    "opencv_imgcodecs",
    "-l",
    "opencv_highgui"
]
```


#### ちなみにターミナルでコンパイルする手順は以下のとおりです。(プログラムがopen.cpp)
```
g++ open.cpp -o open -I /usr/include/opencv4 -l opencv_core -l opencv_imgcodecs -l opencv_highgui
```
#### openという名前の実行ファイルが生成されたので、以下で実行します
```
./open
```