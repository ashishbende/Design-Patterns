#include <iostream>
using namespace std;

class Game{

public:
    Game(int numOfPlayers) : num_of_players(numOfPlayers) {}

    void run(){
        start();
        while(!have_winner()){
            take_turns();
        }
        cout << "Player " << get_winner() << " won this round!" << endl;
    }

protected:
    virtual  void start()=0;
    virtual  bool have_winner() = 0;
    virtual int get_winner() = 0;
    virtual  void take_turns()=0;
    int curr_player{0};
    int num_of_players;
};

class Chess : public Game{
public:
    Chess() : Game(2) {  }

protected:
    void start() override {
        cout  << "Starting the game of chess with " << num_of_players<<endl;
    }

    bool have_winner() override {
        return turn == max_turns;
    }

    int get_winner() override {
        return curr_player;
    }

    void take_turns() override {
        cout << "Turn " << turn << " taken by player "<<curr_player << endl;
        turn++;
        curr_player = (curr_player+1)%num_of_players;
    }
private:
    int turn{0};
    int max_turns{10};
};
int main() {
    Chess chess;
    chess.run();
    return 0;
}
