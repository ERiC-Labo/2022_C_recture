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
# 今週の課題
今週は、画像から競馬の枠連の結果を求めるプログラムを作ってもらいます。<br>
競馬は、枠の番号に８パターンの色がつけられており、ジョッキーは枠の色の帽子をレース中にかぶっています。<br>
そして枠連は、上位2頭の枠の色の組み合わせを予想する馬券の買い方です。<br>
## 問題設定
- 簡単のために、レースに出走する枠の色は赤、青、緑の3種類とする。
- HSV画像中の赤色の領域のマスク画像を作るdetect_red関数をクラス関数として作成する。
- 同様に青色と緑色の領域のマスク画像を作る関数を作成する。
- マスク画像から重心座標を求めるcentroid_image関数を作成する。返り値は、float型の重心座標のx座標とする。
- main文では、クラスのインスタンス化をした後に、各色の重心座標を求め、構造体Point_and_Colorに重心座標と色情報を格納する。
- 最後に、重心座標について構造体をソートし、1着~, ２着~のように出力してください。
# 用語解説
- 枠連:自分の選んだ2頭の馬の枠番号の組み合わせで馬券を買う買い方．1着と2着の順番は関係ない．
# 今後の予定
来週以降はC++を利用したプチ研究をしてもらおうと思います．<br>
研究した結果は院試終わった後ぐらいに他の研究室と発表会をする予定です．<br>
研究するネタについては先輩たちと話し合って決めてください．去年はみんな同じような内容だったので，できるだけかぶらないように．<br>
# プチ研究の例
プチ研究の例として自分が去年行ったプチ研究を簡単に紹介します．<br>
自分は，ロボットのピックアンドプレイスプログラムを作成しました．<br>
難しそうに聞こえるかもしれませんが，やっていることは今日の課題とほぼ一緒です．<br>
天井に固定したカメラから画像を入手し，その画像中の赤色の領域の重心座標を求め，その座標を把持位置としているだけです．<br>
後は，ロボットを動かすプログラムが書ければできそうですよね？<br>
とまあ，こんな感じでプチ研究に挑戦してみてください．<br>


https://user-images.githubusercontent.com/75206988/167041370-8b420297-987a-443b-9575-4e19459f63a4.mp4


# おまけ
[今週のおまけです．](https://www.youtube.com/watch?v=iuSLDkpJMQQ)
