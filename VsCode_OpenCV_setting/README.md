## Opencvをvscodeで実行するための設定

#### launch.json
```
{
    "version": "0.2.0",
    "configurations": [
        {
            "name": "g++ - アクティブ ファイルのビルドとデバッグ",
            "type": "cppdbg",
            "request": "launch",
            "program": "${fileDirname}/${fileBasenameNoExtension}",
            "cwd": "${fileDirname}",    
        }
    ]
}
```
#### task.json(argsの部分だけ変更)
```
"args": [
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