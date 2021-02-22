#include <iostream>
#include <variant>

using namespace std;


struct AddressPrinter{
    void operator()(const string& house_name) const{
        cout << "A house called " << house_name << endl;
    }

    void operator()(const int house_number) const{
        cout << "A house called " << house_number << endl;
    }
};
int main(){
    variant<string, int> house;
    house = "Rio Robles";
    AddressPrinter ap;

    visit(ap, house);

    // using lambda expression
    visit([](auto& arg){
        using T = decay_t<decltype(arg)>;
        if constexpr (is_same_v<T, string>){
            cout << "A house called " << arg << endl;
        }

        if constexpr (is_same_v<T, int>){
            cout << "A house called " << arg << endl;
        }
        }, house);

    return 0;

}