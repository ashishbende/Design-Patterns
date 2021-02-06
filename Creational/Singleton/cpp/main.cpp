#include <iostream>

using namespace std;

class Leader{
 public:
  static Leader* getInstance(){
    if(_instance == nullptr){
      _instance = new Leader;
    }
    return _instance;
  }
  void giveSpeech(){
    cout << "Address the public!" << endl;
  }
 private:
  static Leader* _instance;
  Leader(){
    cout << "New leader elected" <<endl;
  }
};

Leader* Leader::_instance = nullptr;
int main() {
  Leader::getInstance()->giveSpeech();
  return 0;
}
