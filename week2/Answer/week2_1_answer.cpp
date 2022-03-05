#include <iostream>
#include <string>
struct Hose {
  int gatenumber;
  int hosenumber;
  int weight;
  std::string hosename;
  std::string jokeyname;
  float handicap;
  float speed;
};
struct Arima {
    int rank;
    Hose hose;
    void print(){
      std::cout << "rank = " << rank << std::endl;
      std::cout << "gatenumber = " << hose.gatenumber << std::endl;
      std::cout << "hosenumber = " << hose.hosenumber << std::endl;
      std::cout << "weight = " << hose.weight << std::endl;
      std::cout << "hosename = " << hose.hosename << std::endl;
      std::cout << "jockeyname = " << hose.jokeyname << std::endl;
      std::cout << "handicap = " << hose.handicap << std::endl;
      std::cout << "speed = " << hose.speed << std::endl;
      std::cout << std::endl;
    }
};

int main(){
  Arima Arima[2] = {{1, 6, 9, 462, "Orfevre", "K.Ikezoe", 55.0, 33.3},
                    {7, 1, 1, 470, "Buena_Vista", "Y.Iwata", 55.0, 34.1}};

  for(int i = 0 ; i < 2; i++){
      Arima[i].print();
  };
  
};