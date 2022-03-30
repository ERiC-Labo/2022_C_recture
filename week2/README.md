# Week2
# 今週のテーマ
今週は、構造体を勉強します。<br>先週の課題では、vectorに馬番と前走の体重と現在の体重を格納しました。<br>
配列やvectorは同じ型の情報しか格納できません。しかし、様々な型の情報を格納したいときもありますよね。<br>
競馬で考えてみると、例えばint型の情報は馬番、枠番、体重といった情報を、string型の情報は馬名や騎手の情報、<br>
float型だと斤量や上がり3ハロンの情報と複数の型の情報をレースの予想をするときに同時にみたいですよね、こういったときに構造体を利用すると便利です。<br>
構造体は以下のように宣言します。
~~~cpp
struct Hose {
  int gatenumber;
  int hosenumber;
  int weight;
  std::string hosename;
  std::string jokeyname;
  float handicap;
  float speed;
};
~~~
また、構造体に情報を格納し、格納した情報にアクセスするには以下のように行います。
~~~C++
int main(){
  Hose Orfevre = {6, 9, 462, "Orfevre", "K.Ikezoe", 55.0, 33.3};
  std::cout << Orfevre.hosename << std::endl;
};
~~~
構造体を使う事で複数の型の情報を格納できることがわかりましたね。<br>
また、構造体は複数の型だけではなく、関数も格納することができます。今は、馬の情報は一頭だけですが、本番のレースでは最大18頭の馬がいます。<br>
この情報をすべて表示しなければ行けないときに、いちいちプリントするのはめんどくさいですよね。そこで、構造体に関数を追加してみます。
~~~cpp
struct Hose {
  int gatenumber;
  int hosenumber;
  int weight;
  std::string hosename;
  std::string jokeyname;
  float handicap;
  float speed;
  void print_hose() {
      std::cout << "gatenumber = " << gatenumber << std::endl;
      std::cout << "hosenumber = " << hosenumber << std::endl;
      std::cout << "weight = " << weight << std::endl;
      std::cout << "hosename = " << hosename << std::endl;
      std::cout << "jockeyname = " << jokeyname << std::endl;
      std::cout << "handicap = " << handicap << std::endl;
      std::cout << "speed = " << hose.speed << std::endl;
      std::cout << std::endl;
  }
};
~~~
こうすると、複数の馬を表示するときにも便利です。メンバ関数は以下のように使います。
~~~cpp
int main(){
  Hose Orfevre = {6, 9, 462, "Orfevre", "K.Ikezoe", 55.0, 33.3};
  Hose Buena_Vista = {1, 1, 470, "Buena_Vista", "Y.Iwata", 55.0, 34.1};
  Orfevre.print_hose();
  Buena_Vista.print_hose();
};
~~~
出力は以下のようになると思います。
~~~
gatenumber = 6
hosenumber = 9
weight = 462
hosename = Orfevre
jockeyname = K.Ikezoe
handicap = 55
speed = 33.3

gatenumber = 1
hosenumber = 1
weight = 470
hosename = Buena_Vista
jockeyname = Y.Iwata
handicap = 55
speed = 34.1
~~~
# 課題
- 出走馬の枠番、馬番、体重、馬名、騎手名、斤量、上がり3ハロンの数値を要素として持つ構造体Hoseを作りなさい。<br>
その後、レース結果と構造体Hose、レース結果と馬の情報を表示する関数print_race()を要素に持つ構造体Raceを作りなさい。<br>
プログラムのメイン文では、構造体RaceにOrfevreとBuena_Vistaの情報を格納し、表示させなさい。<br>
# おまけ
[実際の結果がどうなったか気になる人は見てみてください．](https://www.youtube.com/watch?v=JOD6LL4yGZM)
