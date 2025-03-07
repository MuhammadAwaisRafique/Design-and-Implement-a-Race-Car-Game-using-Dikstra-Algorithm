#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>

const int MAX_PLAYERS = 100; // Maximum number of players
using namespace std;

class Leaderboard {
private:
    struct Player {
        string name;
        int score;
    }*players;

public:
    // Constructor
    Leaderboard() : players(new Player[MAX_PLAYERS]) {}

    // Destructor
    ~Leaderboard() {
        delete[] players;
    }

    // Function to input player data
    void inputPlayer(string name, int score) {

        ofstream outFile("leader_board_data.txt", std::ios::app);
        if (outFile.is_open()) {
            outFile << name << " " << score << std::endl;
            outFile.close();
        }
        else {
            cout << "Unable to open file for writing." << std::endl;
        }
    }
};