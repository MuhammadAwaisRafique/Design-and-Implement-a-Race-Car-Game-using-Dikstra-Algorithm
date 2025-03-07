#include<ctime>
#include<iostream>
#include<string>
#include<cstdlib>
#include<conio.h>
#include<windows.h>
#include"filer.h"
#include"filer2.h"
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
const int INF = 1e9;
using namespace std;


int sze = 0;
int i = 0;
int xx = 0;
int yy = 0;
class node
{
public:
	int id;
	int weight;
	int connections;
	int x;
	int y;
	int check;
	string type;
	node* next;
	//node* head;
	//node* tail;
	node()
	{
		check = 0;
		//head = NULL;
		//tail = NULL;
		next = NULL;
	}
};

struct queueNode
{
	node* data;
	queueNode* next;
};

class Queu
{
private:
	queueNode* front;
	queueNode* rear;
public:

	Queu()
	{
		front = NULL;
		rear = NULL;
	}

	bool empty()
	{
		if (front == NULL)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	void enqueue(node* data)
	{
		queueNode* temp = new queueNode;
		temp->data = data;
		temp->next = NULL;
		if (front == NULL)
		{
			front = temp;
		}
		else
		{
			rear->next = temp;
		}
		rear = temp;
	}

	void dequeue()
	{
		node* temp = front->data;
		front = front->next;
		return;
	}
	node* pop()
	{
		node* temp = front->data;
		return temp;
	}

};


class list
{

public:
	node* Head;
	node* Tail;
	list()
	{
		Head = NULL;
		Tail = NULL;
	}
	void add(int id, int x, int y, string type)
	{
		node* temp = new node;
		temp->id = id;
		temp->x = x;
		temp->y = y;
		temp->type = type;
		if (Head == NULL)
		{
			Head = temp;
		}
		else
		{
			node* temp1 = Head;
			while (temp1->next != NULL)
			{
				temp1 = temp1->next;
			}
			temp1->next = temp;
		}
	}
};
int wall = 0;
int pu = 0;
int obs = 0;
class graph
{
	Leaderboard lead;
	BinaryTree tree;
	Queu obstacle;
	Queu obstacle2;
	Queu power;
	Queu power2;
	list* arr;
	int size;
	node* head;
	node* tail;
	node* path_head;
	node* path_tail; int namee;
	string name;
	int score;
	int lifes;
	int walls;
	int health;
	int money;
public:
	graph(int size = 9)
	{
		money = 0;
		health = 0;
		namee = 0;
		walls = 0;
		lifes = 5;
		score = 0;
		head = NULL;
		tail = NULL;
		this->size = size;
		arr = new list[size];
		for (int i = 0; i < size; i++)
		{
			arr[i].Head = NULL;
			arr[i].Tail = NULL;
		}
	}

	void start()
	{
		if (namee == 0)
		{
			cout << RED << R"(
			 ________              __                                                                                                                                                
			/        |            /  |                                                                                                                                               
			$$$$$$$$/  _______   _$$ |_     ______    ______         __    __   ______   __    __   ______               _______    ______   _____  ____    ______         __        
			$$ |__    /       \ / $$   |   /      \  /      \       /  |  /  | /      \ /  |  /  | /      \             /       \  /      \ /     \/    \  /      \       /  |______ 
			$$    |   $$$$$$$  |$$$$$$/   /$$$$$$  |/$$$$$$  |      $$ |  $$ |/$$$$$$  |$$ |  $$ |/$$$$$$  |            $$$$$$$  | $$$$$$  |$$$$$$ $$$$  |/$$$$$$  |      $$//      |
			$$$$$/    $$ |  $$ |  $$ | __ $$    $$ |$$ |  $$/       $$ |  $$ |$$ |  $$ |$$ |  $$ |$$ |  $$/             $$ |  $$ | /    $$ |$$ | $$ | $$ |$$    $$ |       __$$$$$$/ )" << BLUE << R"(
			$$ |_____ $$ |  $$ |  $$ |/  |$$$$$$$$/ $$ |            $$ \__$$ |$$ \__$$ |$$ \__$$ |$$ |                  $$ |  $$ |/$$$$$$$ |$$ | $$ | $$ |$$$$$$$$/       /  |       
			$$       |$$ |  $$ |  $$  $$/ $$       |$$ |            $$    $$ |$$    $$/ $$    $$/ $$ |                  $$ |  $$ |$$    $$ |$$ | $$ | $$ |$$       |      $$/        
			$$$$$$$$/ $$/   $$/    $$$$/   $$$$$$$/ $$/              $$$$$$$ | $$$$$$/   $$$$$$/  $$/                   $$/   $$/  $$$$$$$/ $$/  $$/  $$/  $$$$$$$/                  
			                                                        /  \__$$ |                                                                                                       
			                                                        $$    $$/                                                                                                        
			                                                         $$$$$$/    

			===========================================================================================================================================================================                                                                                                     
			

			)" << RESET << endl;
			cin >> name;
			namee++;
		}
		system("cls");
		cout << RED << R"(
						$$\      $$\                                     $$\    $$\                      $$\                                         
						$$$\    $$$ |                                    $$ |   $$ |                     $$ |                                        
						$$$$\  $$$$ | $$$$$$\  $$$$$$$$\  $$$$$$\        $$ |   $$ | $$$$$$\  $$$$$$$\ $$$$$$\   $$\   $$\  $$$$$$\   $$$$$$\        
						$$\$$\$$ $$ | \____$$\ \____$$  |$$  __$$\       \$$\  $$  |$$  __$$\ $$  __$$\\_$$  _|  $$ |  $$ |$$  __$$\ $$  __$$\       
						$$ \$$$  $$ | $$$$$$$ |  $$$$ _/ $$$$$$$$ |       \$$\$$  / $$$$$$$$ |$$ |  $$ | $$ |    $$ |  $$ |$$ |  \__|$$$$$$$$ |      )" << BLUE << R"(
						$$ |\$  /$$ |$$  __$$ | $$  _/   $$   ____|        \$$$  /  $$   ____|$$ |  $$ | $$ |$$\ $$ |  $$ |$$ |      $$   ____|      
						$$ | \_/ $$ |\$$$$$$$ |$$$$$$$$\ \$$$$$$$\          \$  /   \$$$$$$$\ $$ |  $$ | \$$$$  |\$$$$$$  |$$ |      \$$$$$$$\       
						\__|     \__| \_______|\________| \_______|          \_/     \_______|\__|  \__|  \____/  \______/ \__|       \_______|         
						=======================================================================================================================

                     )" << RESET;
		pu = 0;
		obs = 0;
		walls = 0;
		lifes = 5;
		score = 0;
		cout << endl << endl;
		int choice;
		cout << GREEN << "				\t\t\t\t\t\t  ======================" << endl;
		cout << GREEN << "				\t\t\t\t\t\t||			||" << endl;
		cout << GREEN << "				\t\t\t\t\t\t||\t" << YELLOW << "1. Manual" << GREEN << "  \t||" << endl;
		cout << GREEN << "					\t\t\t\t\t||\t" << YELLOW << "2. Auto" << GREEN << "\t\t||" << endl;
		cout << GREEN << "						\t\t\t\t||\t" << YELLOW << "3. Instructions" << GREEN << "\t||" << endl;
		cout << GREEN << "						\t\t\t\t||\t" << YELLOW << "4. Leader Board" << GREEN << "\t||" << endl;
		cout << GREEN << "						\t\t\t\t||\t" << YELLOW << "5. Exit" << GREEN << "\t\t||" << endl;
		cout << GREEN << "				\t\t\t\t\t\t||			||" << endl;
		cout << GREEN << "				\t\t\t\t\t\t  ======================" << endl;
		while (true)
		{
			if (_kbhit())
			{
				int choice = static_cast<int>(_getch());
				if (choice == '1')
				{
					createncheck(0);
					manual(head);
				}
				else if (choice == '2')
				{
					createncheck(1);
					Auto();
				}
				else if (choice == '3')
				{
					instructions();
				}

				else if (choice == '4')
				{
					leaderboard();
				}
				else if (choice == '5')
				{
					system("cls");

					cout << YELLOW << "Do you want to exit game?" << endl;
					cout << BLUE << "Y. Exit     "; cout << RED << "N. NO" << endl;
					while (true)
					{
						if (_kbhit())
						{
							int choice = static_cast<int>(_getch());
							if (choice == 'y')
							{
								exit(0);
							}
							if (choice == 'n')
							{
								start();
							}
						}
					}

				}
			}
		}
	}

	void leaderboard()
	{
		system("cls");
		cout << RED << R"(
						$$\                                $$\                           $$$$$$$\                                      $$\ 
						$$ |                               $$ |                          $$  __$$\                                     $$ |
						$$ |      $$$$$$\   $$$$$$\   $$$$$$$ | $$$$$$\   $$$$$$\        $$ |  $$ | $$$$$$\   $$$$$$\   $$$$$$\   $$$$$$$ |
						$$ |     $$  __$$\  \____$$\ $$  __$$ |$$  __$$\ $$  __$$\       $$$$$$$\ |$$  __$$\  \____$$\ $$  __$$\ $$  __$$ |
						$$ |     $$$$$$$$ | $$$$$$$ |$$ /  $$ |$$$$$$$$ |$$ |  \__|      $$  __$$\ $$ /  $$ | $$$$$$$ |$$ |  \__|$$ /  $$ | )" << BLUE << R"(
						$$ |     $$   ____|$$  __$$ |$$ |  $$ |$$   ____|$$ |            $$ |  $$ |$$ |  $$ |$$  __$$ |$$ |      $$ |  $$ |
						$$$$$$$$\\$$$$$$$\ \$$$$$$$ |\$$$$$$$ |\$$$$$$$\ $$ |            $$$$$$$  |\$$$$$$  |\$$$$$$$ |$$ |      \$$$$$$$ |
						\________|\_______| \_______| \_______| \_______|\__|            \_______/  \______/  \_______|\__|       \_______|
						=======================================================================================================================

					 )" << RESET;
		Reading();
		while (true)
		{
			if (_kbhit())
			{
				int choice = static_cast<int>(_getch());
				if (choice == 'b')
				{
					start();
				}
			}
		}
	}

	void write()
	{
		lead.inputPlayer(name, score);
	}
	void Pause(node* t)
	{
		system("cls");
		int choice;
		cout << "1. Resume" << endl;
		cout << "2. Quit" << endl;
		while (true)
		{
			
			if (_kbhit())
			{
				int choice = static_cast<int>(_getch());
				if (choice == '1')
				{
					manual(t);
				}
			
				else if (choice == '2')
				{
					system("cls");
					cout << "Do you want to exit game?" << endl;
					cout << "Y. Exit     "; cout << "N. NO" << endl;
					while (true)
					{
						if (_kbhit())
						{
							int choice = static_cast<int>(_getch());
							if (choice == 'y')
							{
								del();
								start();
							}
							if (choice == 'n')
							{
								Pause(t);
							}
						}
					}

				}
			}
		}
	}
	void instructions()
	{
		system("cls");

		cout << RED << R"(
							$$$$$$\                       $$\                                     $$\     $$\                                           
							\_$$  _|                      $$ |                                    $$ |    \__|                                          
							  $$ |  $$$$$$$\   $$$$$$$\ $$$$$$\    $$$$$$\  $$\   $$\  $$$$$$$\ $$$$$$\   $$\  $$$$$$\  $$$$$$$\   $$$$$$$\ $$\         
							  $$ |  $$  __$$\ $$  _____|\_$$  _|  $$  __$$\ $$ |  $$ |$$  _____|\_$$  _|  $$ |$$  __$$\ $$  __$$\ $$  _____|\__|$$$$$$\ 
							  $$ |  $$ |  $$ |\$$$$$$\    $$ |    $$ |  \__|$$ |  $$ |$$ /        $$ |    $$ |$$ /  $$ |$$ |  $$ |\$$$$$$\      \______|)" << BLUE << R"(
							  $$ |  $$ |  $$ | \____$$\   $$ |$$\ $$ |      $$ |  $$ |$$ |        $$ |$$\ $$ |$$ |  $$ |$$ |  $$ | \____$$\ $$\         
							$$$$$$\ $$ |  $$ |$$$$$$$  |  \$$$$  |$$ |      \$$$$$$  |\$$$$$$$\   \$$$$  |$$ |\$$$$$$  |$$ |  $$ |$$$$$$$  |\__|        
							\______|\__|  \__|\_______/    \____/ \__|       \______/  \_______|   \____/ \__| \______/ \__|  \__|\_______/             
                                                   )" << RESET;


		cout << endl << endl << endl << endl << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t============================================================" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t" << RED << "1. " << YELLOW << " Arrow keys are used for the movement of the car" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t" << RED << "2. " << YELLOW << "'#' represents a wall" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t" << RED << "3. " << YELLOW << "If you collide with wall or boundry you'll lose a life" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t" << RED << "4. " << YELLOW << "'P' represents power up which doubles your score" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t" << RED << "5. " << YELLOW << "'o' represents obstacle which negates 5 from your score" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t" << RED << "6. " << YELLOW << "IF you lose all your lifes the game ends" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t" << RED << "7. " << YELLOW << "In auto mode the car will move by itself" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t" << RED << "8. " << YELLOW << "Press 'p' to pause the game" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t" << RED << "b. " << YELLOW << "Enter 'b' to go back to main menu" << endl;
		cout << "\t\t\t\t\t\t\t\t\t\t\t============================================================" << endl;
		while (true)
		{
			if (_kbhit())
			{
				int choice = static_cast<int>(_getch());
				if (choice == 'b')
				{
					start();
				}
			}
		}
	}

	void adjlist(node* node1, node* node2) 
	{
		int src = node1->id;
		int dest = node2->id;
		bool find = false;
		node* temp = new node;///destination
		temp->id = dest;
		temp->weight = node2->weight;
		temp->type = node2->type;
		node* temp1 =new node;//source
		temp1->weight =node1->weight;
		temp1->id = src;
		temp1->type = node1->type;
		node* curr = arr[src].Head;

		while (curr) {
			if (curr->id == dest) {
				find = true;
				break;
			}
			curr = curr->next;
		}

		if (find==false) {
			if (arr[src].Head == NULL)
			{
				arr[src].Head = temp;
				arr[src].Tail = temp;
			}
			else 
			{
				arr[src].Tail->next = temp;
				arr[src].Tail = temp;
			}
			if (arr[dest].Head == NULL) 
			{
				arr[dest].Head = temp1;
				arr[dest].Tail = temp1;
			}
			else 
			{
				arr[dest].Tail->next = temp1;
				arr[dest].Tail = temp1;
			}
		}
	}


	void createnodes(int mode)
	{
		srand(time(0));
		for (int i = 0; i < size; i++)
		{

			node* temp = new node;
			temp->id = i;
			int randomNumber = rand() % 10;
			if (randomNumber == 1&&obs<10)
			{
				temp->type = "o";
				temp->weight = 5;
				obs++;
				obstacle.enqueue(temp);
			}
			else if (randomNumber == 0&&pu<8)
			{
				temp->type = "P";
				temp->weight = 1;
				pu++;
				power.enqueue(temp);
			}
			else if (randomNumber == 4 && walls < 100)
			{
				temp->type = "#";
				temp->weight = 10000;
				walls++;
			}
			else if (randomNumber == 3 && health < 2)
			{
				temp->type = "H";
				temp->weight = 3;
				health++;
			}
			else if (randomNumber == 5 && walls < 10)
			{
				temp->type = "M";
				temp->weight = 6;
				money++;
			}
			else
			{
				temp->type = "O";
				temp->weight = 2;
			}
			if (i == size - 1)
			{
				temp->type = "E";
				temp->weight = 1;
			}
			

			temp->x = xx;
			temp->y = yy;

			if (xx == (sqrt(size) - 1))
			{
				xx = 0;
				yy++;
			}
			else
			{
				xx++;
			}
			if ((temp->x == 0 && temp->y == 0) || (temp->x == 0 && temp->y == sqrt(size) - 1) || (temp->x == sqrt(size) - 1 && temp->y == 0) || (temp->x == sqrt(size) - 1 && temp->y == sqrt(size) - 1))
			{
				temp->connections = 2;
			}
			else if (temp->x == 0 || temp->x == sqrt(size) - 1 || temp->y == 0 || temp->y == sqrt(size) - 1)
			{
				temp->connections = 3;
			}
			else
			{
				temp->connections = 4;
			}
			if (head == NULL)
			{
				head = temp;
				tail = temp;
				head->type = "S";
				tail->type = "S";
			}
			else
			{
				tail->next = temp;
				tail = temp;
			}
		}
	}

	node* find(int x, int y)
	{
		node* curr = head;
		while (curr)
		{
			if (curr->x == x && curr->y == y)
			{
				return curr;
			}
			curr = curr->next;
		}
		return NULL;
	}

	void connect()
	{
		node* temp = head;
		node* curr;
		int x, y;
		while (temp)
		{
			for (int i = 0; i < 4; i++)
			{
				if (i == 0)//up
				{
					x = temp->x;
					y = temp->y - 1;
					curr = find(x, y);
					if (curr != NULL)
					{
						adjlist(temp, curr);
					}
				}
				if (i == 1)//down
				{
					x = temp->x;
					y = temp->y + 1;
					curr = find(x, y);
					if (curr != NULL)
					{
						adjlist(temp, curr);
					}
				}
				if (i == 2)//left
				{
					x = temp->x-1;
					y = temp->y ;
					curr = find(x, y);
					if (curr != NULL)
					{
						adjlist(temp, curr);
					}
				}
				if (i == 3)//right
				{
					x = temp->x+1;
					y = temp->y;
					curr = find(x, y);
					if (curr != NULL)
					{
						adjlist(temp, curr);
					}
				}
			}
			temp = temp->next;
		}
		
	}

	void displaynodes(int mode)
	{
		system("cls");
		if (mode == 0)
		{
			cout<<YELLOW << "SCORE: " << score <<RESET<< endl;
			cout <<YELLOW<< "Lifes: " << lifes <<RESET<< endl;
		}
		cout << endl;
		node* temp = head;
		cout<< YELLOW << "----------------------------------------------------"<< RESET << endl;
		cout << YELLOW << "----------------------------------------------------" << RESET << endl;
		for (int i = 0; i < size; i++)
		{
			if (temp->x == 0)
			{
				cout << YELLOW << "|| " << RESET;
			}
			if (temp->type == "O")
			{
				if (mode == 0)
				{
					if (temp->check == 0)
					{
						cout << GREEN << "*" << RESET;
					}
					else
					{
						cout << GRAY << "*" << RESET;
					}
				}
				else
				{
					cout << " ";
				}
				
				
			}
			else if(temp->type=="o")
			{
				cout<<RED << temp->type<<RESET;
			}
			else if (temp->type == "P")
			{
				cout << YELLOW << temp->type << RESET;
			}
			else if (temp->type == "M")
			{
				cout << YELLOW << temp->type << RESET;
			}
			else if (temp->type == "H")
			{
				cout << GREEN << temp->type << RESET;
			}
			else if (temp->type == "#")
			{
				cout << BLUE << temp->type << RESET;
			}
			else if (temp->type == "C")
			{
				cout << GREEN << temp->type << RESET;
			}
			else if (temp->type == "S")
			{
				cout << temp->type ;
			}
			else if (temp->type == "E")
			{
				cout << temp->type ;
			}
			else if (temp->type == "*")
			{
				cout << temp->type;
			}
			if (temp->x == (sqrt(size) - 1))
			{
				if (i != size - 1)
				{
					cout << YELLOW << " ||" << RESET;
					cout << endl;
					cout << endl;
				}
				else
				{
					cout << YELLOW << " ||" << RESET;
					cout << endl;
				}
				
			}
			else
			{
				int x = temp->x + 1;
				int y = temp->y;
				node* curr = find(x, y);
				if(curr)
				{
					if (temp->type == "#")
					{
						cout << "    ";
					}
					else if (curr->type == "#")
					{
						cout << "    ";
					}
					else
					{
						cout << GRAY << "----" << RESET;
					}
				}
				else
				{
					cout << GRAY << "----" << RESET;
				}
				
			}
			temp = temp->next;
		}
		cout << YELLOW << "----------------------------------------------------" << RESET << endl;
		cout << YELLOW << "----------------------------------------------------" << RESET << endl;
		if (lifes == 0)
		{
			system("cls");
			cout << "Game Ended!" << endl;
			cout << endl;
			cout << "Name: " << name << endl;
			cout << "Score: " << score << endl;
			Sleep(5000);
			write();
			del();
			start();
		}
	}

	void manual(node* t)
	{
		displaynodes(0);
		node* temp = t;
		node* curr;
		int x, y;
		while (true)
		{
			if (_kbhit()) {
				int asciiValue = static_cast<int>(_getch());
				if (asciiValue==72)//up
				{
					x = temp->x;
					y = temp->y - 1;
					curr = find(x, y);
					if (curr != NULL)
					{
						string s = "C";
					if (curr->type == "P")
					{
						if (curr->check == 0)
						{
							score *= 2;
							curr->check = 1;
						}
						while (power.empty() != true)
						{
							node* curr2 = power.pop();
							if (curr2->x == x && curr2->y == y)
							{
								curr2->type = "O";
								power.dequeue();
							}
							else
							{
								power2.enqueue(power.pop());
								power.dequeue();
							}

						}
						while (power2.empty() != true)
						{

							power.enqueue(power2.pop());
							power2.dequeue();
						}
						temp->type = "O";
						curr->type = s;
						temp = curr;

						displaynodes(0);
					}
						
						else if (curr->type == "o")
						{
							if (curr->check == 0)
							{
								score -= 5;
								curr->check = 1;
							}
							while (obstacle.empty() != true)
							{
								node* curr2 = obstacle.pop();
								if (curr2->x == x && curr2->y == y)
								{
									curr2->type = "O";
									obstacle.dequeue();
								}
								else
								{
									obstacle2.enqueue(obstacle.pop());
									obstacle.dequeue();
								}
								
							}
							while (obstacle2.empty() != true)
							{
								
								obstacle.enqueue(obstacle2.pop());
								obstacle2.dequeue();
							}
							temp->type = "O";
							curr->type = s;
							temp = curr;
							
							displaynodes(0);
						}

						else if (curr->type == "O")
						{
							if (curr->check == 0)
							{
								score += 10;
								curr->check = 1;
							}
							temp->type = "O";
							curr->type = s;
							temp = curr;
							displaynodes(0);
						}
						else if (curr->type == "M")
					    {
						if (curr->check == 0)
						{
							score += 20;
							curr->check = 1;
						}
						temp->type = "O";
						curr->type = s;
						temp = curr;
						displaynodes(0);
						}
						else if (curr->type == "H")
						{
						if (curr->check == 0)
						{
							lifes += 1;
							curr->check = 1;
						}
						temp->type = "O";
						curr->type = s;
						temp = curr;
						displaynodes(0);
						}
						else if (curr->type == "E")
						{
							temp->type = "O";
							curr->type = s;
							temp = curr;
							displaynodes(0);
							system("cls");
							cout << "Congratulations You escaped the maze" << endl;
							cout << "Name: " << name << endl;
							cout << "Score: " << score << endl;
							write();
							Sleep(5000);
							del();
							start();
						}

						else if (curr->type == "#")
						{
							lifes -= 1;
							displaynodes(0);
							if (lifes == 0)
							{
								system("cls");
								cout << "Game ended!" << endl;
								cout << "Name: " << name << endl;
								cout << "Score: " << score << endl;
								write();
								Sleep(5000);
								del();
								start();
							}
						}
						
					}
					else
					{
						lifes -= 1;
						displaynodes(0);
						if (lifes == 0)
						{
							system("cls");
							cout << "Game Ended!" << endl;
							cout << "Name: " << name << endl;
							cout << "Score: " << score << endl;
							write();
							Sleep(5000);
							del();
							start();
						}
					}
					
				}
				if (asciiValue==80)//down
				{
					x = temp->x;
					y = temp->y +1;
					curr = find(x, y);
					if (curr != NULL)
					{
						string s = "C";
						if (curr->type == "P")
						{
							if (curr->check == 0)
							{
								score *= 2;
								curr->check = 1;
							}
							while (power.empty() != true)
							{
								node* curr2 = power.pop();
								if (curr2->x == x && curr2->y == y)
								{
									curr2->type = "O";
									power.dequeue();
								}
								else
								{
									power2.enqueue(power.pop());
									power.dequeue();
								}

							}
							while (power2.empty() != true)
							{

								power.enqueue(power2.pop());
								power2.dequeue();
							}
							temp->type = "O";
							curr->type = s;
							temp = curr;

							displaynodes(0);
						}

						else if (curr->type == "o")
						{
							if (curr->check == 0)
							{
								score -= 5;
								curr->check = 1;
							}
							while (obstacle.empty() != true)
							{
								node* curr2 = obstacle.pop();
								if (curr2->x == x && curr2->y == y)
								{
									curr2->type = "O";
									obstacle.dequeue();
								}
								else
								{
									obstacle2.enqueue(obstacle.pop());
									obstacle.dequeue();
								}

							}
							while (obstacle2.empty() != true)
							{

								obstacle.enqueue(obstacle2.pop());
								obstacle2.dequeue();
							}
							temp->type = "O";
							curr->type = s;
							temp = curr;

							displaynodes(0);
						}

						else if (curr->type == "O")
						{
							if (curr->check == 0)
							{
								score += 10;
								curr->check = 1;
							}
							temp->type = "O";
							curr->type = s;
							temp = curr;
							displaynodes(0);
						}
						else if (curr->type == "M")
						{
							if (curr->check == 0)
							{
								score += 20;
								curr->check = 1;
							}
							temp->type = "O";
							curr->type = s;
							temp = curr;
							displaynodes(0);
						}
						else if (curr->type == "H")
						{
							if (curr->check == 0)
							{
								lifes += 1;
								curr->check = 1;
							}
							temp->type = "O";
							curr->type = s;
							temp = curr;
							displaynodes(0);
						}
						else if (curr->type == "#")
						{
							lifes -= 1;
							displaynodes(0);
							if (lifes == 0)
							{
								system("cls");
								cout << "Game Ended!" << endl;
								cout << "Name: " << name << endl;
								cout << "Score: " << score << endl;
								write();
								Sleep(5000);
								del();
								start();
							}
						}
						else if (curr->type == "E")
						{
							temp->type = "O";
							curr->type = s;
							temp = curr;
							displaynodes(0);
							system("cls");
							cout << "Congratulations You escaped the maze" << endl;
							cout << "Name: " << name << endl;
							cout << "Score: " << score << endl;
							write();
							Sleep(5000);
							del();
							start();
						}
						
					}
					else
					{
						lifes -= 1;
						displaynodes(0);
						if (lifes == 0)
						{
							system("cls");
							cout << "Game Ended!" << endl;
							cout << "Name: " << name << endl;
							cout << "Score: " << score << endl;
							write();
							Sleep(5000);
							del();
							start();
						}
					}
				}
				if (asciiValue==75)//left
				{
					x = temp->x-1;
					y = temp->y;
					curr = find(x, y);
					if (curr != NULL)
					{
						string s = "C";
						if (curr->type == "P")
						{
							if (curr->check == 0)
							{
								score *= 2;
								curr->check = 1;
							}
							while (power.empty() != true)
							{
								node* curr2 = power.pop();
								if (curr2->x == x && curr2->y == y)
								{
									curr2->type = "O";
									power.dequeue();
								}
								else
								{
									power2.enqueue(power.pop());
									power.dequeue();
								}

							}
							while (power2.empty() != true)
							{

								power.enqueue(power2.pop());
								power2.dequeue();
							}
							temp->type = "O";
							curr->type = s;
							temp = curr;

							displaynodes(0);
						}

						else if (curr->type == "o")
						{
							if (curr->check == 0)
							{
								score -= 5;
								curr->check = 1;
							}
							while (obstacle.empty() != true)
							{
								node* curr2 = obstacle.pop();
								if (curr2->x == x && curr2->y == y)
								{
									curr2->type = "O";
									obstacle.dequeue();
								}
								else
								{
									obstacle2.enqueue(obstacle.pop());
									obstacle.dequeue();
								}

							}
							while (obstacle2.empty() != true)
							{

								obstacle.enqueue(obstacle2.pop());
								obstacle2.dequeue();
							}
							temp->type = "O";
							curr->type = s;
							temp = curr;

							displaynodes(0);
						}

						else if (curr->type == "O")
						{
							if (curr->check == 0)
							{
								score += 10;
								curr->check = 1;
							}
							temp->type = "O";
							curr->type = s;
							temp = curr;
							displaynodes(0);
						}

						else if (curr->type == "#")
						{
							lifes -= 1;
							displaynodes(0);
							if (lifes == 0)
							{
								system("cls");
								cout << "Game ended!" << endl;
								cout << "Name: " << name << endl;
								cout << "Score: " << score << endl;
								write();
								Sleep(5000);
								del();
								start();
							}
						}
						else if (curr->type == "E")
						{
							temp->type = "O";
							curr->type = s;
							temp = curr;
							displaynodes(0);
							system("cls");
							cout << "Congratulations You escaped the maze" << endl;
							cout << "Name: " << name << endl;
							cout << "Score: " << score << endl;
							write();
							Sleep(5000);
							del();
							start();
						}
						
					}
					else
					{
						lifes -= 1;
						displaynodes(0);
						if (lifes == 0)
						{
							system("cls");
							cout << "Game Ended!" << endl;
							cout << "Name: " << name << endl;
							cout << "Score: " << score << endl;
							write();
							Sleep(5000);
							del();
							start();
						}
					}
				}
				if (asciiValue==77)//right
				{
					x = temp->x+1;
					y = temp->y;
					curr = find(x, y);
					if (curr != NULL)
					{
						string s = "C";
						if (curr->type == "P")
						{
							if (curr->check == 0)
							{
								score *= 2;
								curr->check = 1;
							}
							while (power.empty() != true)
							{
								node* curr2 = power.pop();
								if (curr2->x == x && curr2->y == y)
								{
									curr2->type = "O";
									power.dequeue();
								}
								else
								{
									power2.enqueue(power.pop());
									power.dequeue();
								}

							}
							while (power2.empty() != true)
							{

								power.enqueue(power2.pop());
								power2.dequeue();
							}
							temp->type = "O";
							curr->type = s;
							temp = curr;

							displaynodes(0);
						}

						else if (curr->type == "o")
						{
							if (curr->check == 0)
							{
								score -= 5;
								curr->check = 1;
							}
							while (obstacle.empty() != true)
							{
								node* curr2 = obstacle.pop();
								if (curr2->x == x && curr2->y == y)
								{
									curr2->type = "O";
									obstacle.dequeue();
								}
								else
								{
									obstacle2.enqueue(obstacle.pop());
									obstacle.dequeue();
								}

							}
							while (obstacle2.empty() != true)
							{

								obstacle.enqueue(obstacle2.pop());
								obstacle2.dequeue();
							}
							temp->type = "O";
							curr->type = s;
							temp = curr;

							displaynodes(0);
						}
						else if (curr->type == "M")
						{
							if (curr->check == 0)
							{
								score += 20;
								curr->check = 1;
							}
							temp->type = "O";
							curr->type = s;
							temp = curr;
							displaynodes(0);
						}
						else if (curr->type == "H")
						{
							if (curr->check == 0)
							{
								lifes += 1;
								curr->check = 1;
							}
							temp->type = "O";
							curr->type = s;
							temp = curr;
							displaynodes(0);
						}
						else if (curr->type == "O")
						{
							if (curr->check == 0)
							{
								score +=10;
								curr->check = 1;
							}
							temp->type = "O";
							curr->type = s;
							temp = curr;
							displaynodes(0);
						}

						else if (curr->type == "#")
						{
							lifes -= 1;
							displaynodes(0);
							if (lifes == 0)
							{
								system("cls");
								cout << "Game Ended!" << endl;
								cout << "Name: " << name << endl;
								cout << "Score: " << score << endl;
								write();
								Sleep(5000);
								del();
								start();
							}
						}
						else if (curr->type == "E")
						{
							temp->type = "O";
							curr->type = s;
							temp = curr;
							displaynodes(0);
							system("cls");
							cout << "Congratulations You escaped the maze" << endl;
							cout << "Name: " << name << endl;
							cout << "Score: " << score << endl;
							write();
							Sleep(5000);
							del();
							start();
						}
						
						
					}
					else
					{
						lifes -= 1;
						displaynodes(0);
						if (lifes == 0)
						{
							system("cls");
							cout << "Game Ended!" << endl;
							cout << "Name: " << name << endl;
							cout << "Score: " << score << endl;
							write();
							Sleep(5000);
							del();
							start();
						}
					}
				}
				if (lifes == 0)
				{
					system("cls");
					cout << "Game Ended!" << endl;
					cout << "Name: " << name << endl;
					cout << "Score: " << score << endl;
					write();
					Sleep(5000);
					del();
					start();
				}
				
				if (asciiValue == 'p') // Break the loop if the 'q' key is pressed
				{
					Pause(temp);
				}
			}
		}
	}

	void display()
	{
		cout << "size " << sze << endl;
		for (int i = 0; i < size; i++)
		{
			cout << "list " << i << " :" << endl;
			node* temp = arr[i].Head;
			while (temp)
			{
				cout << temp->id << " ";
				temp = temp->next;
			}
			cout << endl;
		}
	}

	
	void dijkstra(int startNode) 
	{
		int* dist = new int[size];
		bool* visit = new bool[size];
		int* last = new int[size];
		int i = 0;
		while ( i < size) 
		{
			dist[i] = INF;
			visit[i] = false;
			last[i] = -1;
			i += 1;
		}

		dist[startNode] = 0;
		int count = 0;
		while ( count < size - 1) 
		{
			int u = smallerdist(dist, visit);

			visit[u] = true;
			node* neighbor = arr[u].Head;
			while ( neighbor) 
			{
				int v = neighbor->id;
				int weight = neighbor->weight; // Assuming all edges have the same weight

				if (!visit[v] && dist[u] + weight < dist[v])
				{
					dist[v] = dist[u] + weight;
					last[v] = u;
				}
				neighbor = neighbor->next;
			}
			count += 1;
		}

		 i = 99;
		
		findpath(last, i);
		cout << endl;
		

		delete[] dist;
		delete[] visit;
		delete[] last;
	}
	int smallerdist(int distance[], bool visited[]) 
	{
		int minD = INF;
		int minInd = -1;

		for (int v = 0; v < size; ++v) 
		{
			if (!visited[v] && distance[v] <= minD) 
			{
				minD= distance[v];
				minInd = v;
			}
		}

		return minInd;
	}

	void findpath(int last[], int n) 
	{
		if (last[n] != -1) 
		{
			findpath(last, last[n]);
		}
		node* temp = new node;
		temp->id = n;
		if (path_head == NULL)
		{
			path_head=temp;
			path_tail = temp;
		}
		else
		{
			path_tail->next = temp;
			path_tail = temp;
		}
		
	}

	void createncheck(int mode)
	{
		bool check = true;
		node* temp = path_head;
		node* temp2;
		bool found = false;

		while (check)
		{
			found = false;
			createnodes(mode);
			connect();
			dijkstra(0);
			temp = path_head;
			while (temp)
			{
				temp2 = head;
				while (temp2)
				{
					if (temp->id == temp2->id)
					{
						if (temp2->type == "#")
						{
							found = true;
						}
					}
					temp2 = temp2->next;
				}
				temp = temp->next;
			}
			if (found == true)
			{
				del();
			}
			else
			{
				check = false;
			}
		}
	}
	void del()
	{
		head->next = NULL;
		head = NULL;
		tail->next = NULL;
		tail = NULL;
		path_head->next = NULL;
		path_head = NULL;
		path_tail->next = NULL;
		path_tail = NULL;
		for (int i = 0; i < size; i++)
		{
			
			arr[i].Head->next = NULL;
			arr[i].Head = NULL;
			arr[i].Tail = NULL;
		}

	}
	void display2()
	{
		node* curr = path_head;
		while (curr)
		{
			cout << curr->id<<"->";
			curr = curr->next;
		}
		cout << endl;
	}

	void Auto()
	{
		displaynodes(1);
		node* temp = path_head;
		node* curr;
		string car = "C";
		while (temp)
		{
			curr = head;
			while (curr)
			{
				if (curr->id == temp->id)
				{
					curr->type = "*";
				}
				curr = curr->next;
			}
			temp = temp->next;
		}
		head->type = "C";
		tail->type = "E";
		temp = path_head;
		int pre = temp->id;
		temp = temp->next;
		displaynodes(1);

		while (temp)
		{
			Sleep(1000);
			curr = head;
			while (curr)
			{
				if (curr->id == temp->id)
				{
					curr->type = "C";
				}
				curr = curr->next;
			}
			curr = head;
			while (curr)
			{
				if (curr->id == pre)
				{
					curr->type = "O";
				}
				curr = curr->next;
			}
			pre = temp->id;
			temp = temp->next;
			displaynodes(1);
		}
		system("cls");
		cout << "Reached the exit." << endl;
		cout << "Name: " << name << endl;
		Sleep(5000);
		del();
		start();
	}
};