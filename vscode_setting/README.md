## Opencvをvscodeで実行するための設定

##### task.json
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
#### launch.jsonが生成されないのは仕方ないので諦めてください