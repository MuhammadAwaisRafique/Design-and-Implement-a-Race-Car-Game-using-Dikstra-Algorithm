/*
    Member 1:-
	Name: Khawar
	ID  : 22i-2657
	Class: SE-B

	Member 2:-
	Name: Muhammad Awais
	ID  : 22i-2511
	Class: SE-B
	

*/
#include<iostream>
#include"Header.h"
using namespace std;
// ANSI escape codes for text color
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

void one()
{
	int i = 0;
	while (i < 20)
	{
		cout << endl;
		i++;
	}
	i = 0;
	cout << YELLOW << R"(
								 _        _______  _______  ______  _________ _        _______          
								( \      (  ___  )(  ___  )(  __  \ \__   __/( (    /|(  ____ \         
								| (      | (   ) || (   ) || (  \  )   ) (   |  \  ( || (    \/         
								| |      | |   | || (___) || |   ) |   | |   |   \ | || |               
								| |      | |   | ||  ___  || |   | |   | |   | (\ \) || | ____          
								| |      | |   | || (   ) || |   ) |   | |   | | \   || | \_  )         
								| (____/\| (___) || )   ( || (__/  )___) (___| )  \  || (___) | _   
								(_______/(_______)|/     \|(______/ \_______/|/    )_)(_______)(_)

		)" << RESET << endl;
}

void two()
{
	int i = 0;
	while (i < 20)
	{
		cout << endl;
		i++;
	}
	i = 0;
	cout << YELLOW << R"(
								 _        _______  _______  ______  _________ _        _______          
								( \      (  ___  )(  ___  )(  __  \ \__   __/( (    /|(  ____ \         
								| (      | (   ) || (   ) || (  \  )   ) (   |  \  ( || (    \/         
								| |      | |   | || (___) || |   ) |   | |   |   \ | || |               
								| |      | |   | ||  ___  || |   | |   | |   | (\ \) || | ____          
								| |      | |   | || (   ) || |   ) |   | |   | | \   || | \_  )         
								| (____/\| (___) || )   ( || (__/  )___) (___| )  \  || (___) | _  _  
								(_______/(_______)|/     \|(______/ \_______/|/    )_)(_______)(_)(_)

		)" << RESET << endl;
}

void three()
{
	int i = 0;
	while (i < 20)
	{
		cout << endl;
		i++;
	}
	i = 0;
	cout << YELLOW << R"(
								 _        _______  _______  ______  _________ _        _______          
								( \      (  ___  )(  ___  )(  __  \ \__   __/( (    /|(  ____ \         
								| (      | (   ) || (   ) || (  \  )   ) (   |  \  ( || (    \/         
								| |      | |   | || (___) || |   ) |   | |   |   \ | || |               
								| |      | |   | ||  ___  || |   | |   | |   | (\ \) || | ____          
								| |      | |   | || (   ) || |   ) |   | |   | | \   || | \_  )         
								| (____/\| (___) || )   ( || (__/  )___) (___| )  \  || (___) | _  _  _ 
								(_______/(_______)|/     \|(______/ \_______/|/    )_)(_______)(_)(_)(_)

		)" << RESET << endl;
}
int main()
{
	

	int i = 0;
	while (i < 10)
	{
		cout << endl;
		i++;
	}
	i = 0;
	while (i < 3)
	{
		one();
		Sleep(1000);
		system("cls");

		two();
		Sleep(1000);
		system("cls");
		three();
		Sleep(1000);
		system("cls");
		i++;
	}
	
	graph g(100);
	
	g.start();
	return 0;
}