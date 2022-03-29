# Week4
# 今週のテーマ
今週はクラスについて勉強します．<br>
## なぜクラスを使うか
クラスを使う一番の理由は，保守性の向上です．<br>
人にコードを引き継ぐときにある程度の機能ごとに分割されていないとどこに目的の関数などがあるか探しにくいです．<br>
また，自分で研究をする際にも一か月もしたら，自分の書いたコードがどこにあるかわからなくなります．<br>
そのため，クラスを使ったり，積極的にメモを残したりして保守性の高いコードを作成しましょう．<br>

# 練習
今回は，Imageクラスを作って，ImageProcessingクラスに画像処理を行う関数を作成することを目的とします．<br>
まず、Image_processing.hppというヘッダファイル,Image_processing.cppというクラスの内容を記入するファイル、<br>
そして、Image_processing.cppというmain文を記載するファイルを作成してください。<br>
## ヘッダファイル
まずは、Image_processing.hppを使ってヘッダファイルを作成します。<br>
### コンストラクタ
まずは、コンストラクタを作成します。コンストラクタは、プログラムが実行されるときに必ず実行される関数で、<br>
普段は変数の初期化などをこのコンストラクタで行います。<br>
### 変数、関数の定義
次に、変数を定義します。変数はprivateとpublicに分けて定義します。<br>
privateとpublicに分ける理由としては、変数を勝手に変更することを防ぐためです。<br>
publicに定義したものは、クラスのcppファイルとmain文のcppファイルのどちらからでも触れますが、<br>
privateに定義したものは、クラスのcppファイルからだけしかさわれません。<br>
最後にクラス関数を定義します。<br>
練習では、入力画像を格納するinput_iageという関数とrgbからhsvに変換するrgb_to_hsvという関数を定義します。
練習で作成するヘッダファイルは以下の通りです。
~~~cpp
#pragma once 
#include <iostream>
#include <opencv4/opencv2/opencv.hpp>


class ImageProcessing {
    private:
        std::string path; //画像へのパス

    public:
        ImageProcessing();
        cv::Mat input_img; //入力画像
        cv::Mat hsv_img; //hsv画像
        void input_image(); //入力画像を格納
        void rgb_to_hsv(cv::Mat img); //rgbからhsvに変換
};
~~~
## クラスファイル
クラスファイルについては、簡単なので以下のコードを読んで理解してください。
~~~cpp
#include "Image_processing.hpp"
#include <iostream>

ImageProcessing::ImageProcessing()
{
    input_image();
    rgb_to_hsv(ImageProcessing::input_img);
}

void ImageProcessing::input_image()
{
    std::cout << "Please enter the path to the image." << std::endl;
    std::cin >> ImageProcessing::path;
    ImageProcessing::input_img = cv::imread(ImageProcessing::path);
    cv::imshow("input_img", ImageProcessing::input_img);
    
}

void ImageProcessing::rgb_to_hsv(cv::Mat img)
{
    cv::cvtColor(img, hsv_img, cv::COLOR_BGR2HSV);
    std::cout << "From BGR To HSV was done." << std::endl;
}
~~~
## main文
main文では、まずクラスのインスタンス化を行います。インスタンス化することで、自動的にコンストラクタが実行されます。<br>
~~~cpp
#include "Image_processing.hpp"

int main(void){
    ImageProcessing IP;

    return 0;
}
~~~
## コンパイル方法
今週の例のようにファイルを分割した場合、分割コンパイルという方法でコンパイルする必要があります。<br>
分割コンパイルを行うにはいろいろ方法がありますが、今回はCmakeを利用してコンパイルを行います。<br>
なぜCmakeを利用するかというと、今回はROSと一緒にOpenCVをインストールしたためです。<br>
まずは、CMakeLists.txtというファイルを作成します。
記載する内容は以下を参考にしてください。
~~~
cmake_minimum_required(VERSION 3.16.3) ##CMake 3.16.3以上を条件として設定．
project(WEEK4_ANSWER) ##プロジェクト名をいれる

find_package(OpenCV REQUIRED) ##OpenCVのビルド環境の設定ファイルを読み込む
 
##OpenCV関係のインクルードディレクトリのパスを設定
include_directories(
    ${OpenCV_INCLUDE_DIRS}
)
 
##実行ファイル名を設定
add_executable(
    ${PROJECT_NAME} Image_processing.cpp Image_processing_class.cpp
)
 
##リンクするライブラリを読み込む
target_link_libraries(
    ${PROJECT_NAME} ${OpenCV_LIBRARIES}
)
~~~
次に、hppやcppファイルと同じ階層にbuildというディレクトリを作成します。<br>
その後、ターミナル上でcmake..とコマンドを打ちます。これでコンパイルの準備は完了です。<br>
最後にmakeとターミナル上でコマンドを打てばコンパイル完了です。<br>
