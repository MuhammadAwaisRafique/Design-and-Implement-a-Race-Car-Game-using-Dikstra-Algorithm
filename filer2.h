#pragma once
#include <iostream>
#include <fstream>
#include <string>
#define RESET "\033[0m"
#define CYAN "\033[31m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define RED "\033[1;31m"  
#define AQUA "\033[36m" 
#define GOLD "\033[38;5;220m" // ANSI escape code for gold color
#define NAVY_BLUE "\033[38;5;18m" // ANSI escape code for navy blue color
#define VIOLET "\033[38;5;92m" // ANSI escape code for violet color
#define CRIMSON "\033[38;5;196m"
#define GRAY "\033[38;5;245m"
using namespace std;
struct Node {
    string name;
    int score;
    Node* left;
    Node* right;

    Node(const string& n, int s) : name(n), score(s), left(nullptr), right(nullptr) {}
};

class BinaryTree {
private:
    Node* root;

    Node* insert(Node* node, const string& name, int score) {
        if (node == nullptr) {
            return new Node(name, score);
        }

        if (score < node->score) {
            node->left = insert(node->left, name, score);
        }
        else if (score > node->score) {
            node->right = insert(node->right, name, score);
        }

        return node;
    }

    void display(Node* node) {
        static int i = 0;

        if (node != nullptr) {
            display(node->right);
            i++;
            cout << "\t\t\t\t\t\t\t\t\t\t\t\t" << RED << i << ". " << YELLOW << node->name << " " << BLUE << node->score << endl;
            display(node->left);
        }
    }

public:
    BinaryTree() : root(nullptr) {}

    void insert(const string& name, int score) {
        root = insert(root, name, score);
    }

    void display() {
        cout << endl << endl << endl << endl;
        display(root);
    }
};
void Reading()
{
    BinaryTree tree;

    // Reading data from the file
    ifstream inputFile("leader_board_data.txt");
    if (!inputFile.is_open()) {
        cout << "Error opening file." << endl;
        return;
    }

    string name;
    int score;

    while (inputFile >> name >> score) {
        tree.insert(name, score);
    }

    inputFile.close();

    // Displaying the data
    tree.display();
}