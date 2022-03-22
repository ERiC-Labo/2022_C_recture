# Week3
# 今週のテーマ
今週はポインタについて勉強します。<br>
ポインタについて詳しく語るのは大変なので、以下のリンクを参考にしてください。<br>
[ポインタ参考資料-1](https://bi.biopapyrus.jp/cpp/syntax/pointer.html)<br>
[ポインタ参考資料-2](https://qiita.com/yokoto/items/5672ff20b63815728d90)<br>
# 課題
ポインタを使うといっても，よくある練習問題はつまらないし，こんな場面で使うよってのも具体的に示すのは難しいんで．<br>
こういう風にポインタを使ったらコードがよりよくなるよっていう簡単な練習問題を今週は解いてみましょう．<br>
<br>
まずは，以下の関数を見てください．<br>
~~~cpp
void print_hose(int hose_number, std::string hose_name, float handicap){
    std::cout << "hose_number: " << hose_number << std::endl;
    std::cout << "hose_name: " << hose_name << std::endl;
    std::cout << "handicap: " << handicap << std::endl;
}
~~~
この関数は、馬の情報を出力する関数です<br>
この関数では、値渡しを使って関数に情報を渡しています。<br>
現代のコンピュータではそこまで気にする必要はないのかもしれませんが、大量のデータを値渡しすると、実行速度が遅くなります.<br>
また、何よりコードがごちゃごちゃして見づらいです。<br>
そこで、今週は構造体のポインタ渡しを作って上記の関数をスッキリさせてみてください。
