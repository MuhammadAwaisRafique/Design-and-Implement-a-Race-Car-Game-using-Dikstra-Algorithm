Race Car Game - Data Structures Project

Project Title: Race Car Game

Project Description

This project is a console-based 2D race car game implemented in C++, designed as a semester project for the Data Structures course. The game integrates key data structures such as graphs,Djikstra Alogorithm for shortest Path, queues, and linked lists to efficiently manage game elements like navigation, obstacles, and collected items.

🚗 Game Features

Text-Based User Interface (TUI): Uses ASCII characters to display the game elements in the console.

Player Controls: Players can control their race car using keyboard inputs.

Obstacle Management (Queue Implementation): Obstacles are dynamically introduced into the game using a queue.

Graph-Based Navigation: The race track is represented as a graph for pathfinding and efficient navigation.

Linked List for Collected Items: Keeps track of collected coins or trophies using a linked list.

Scoring System: Players earn points by avoiding obstacles and collecting items.

Win/Loss Conditions: Game logic ensures proper gameplay flow with conditions for winning or losing.

📌 Data Structures Used

1️⃣ Graph for Map and Navigation

Represents the race track as a graph where nodes are waypoints and edges define paths.

Implements Dijkstra’s algorithm (or another shortest path algorithm) for optimized navigation.

2️⃣ Queue for Obstacles

Manages obstacle generation dynamically using a queue.

Obstacles are added to the queue and processed in real-time during gameplay.

3️⃣ Linked List for Collected Items

Maintains a linked list of collected coins or trophies.

Used to track and display the player's progress and achievements.

🖥️ How to Run the Project

Prerequisites

A C++ compiler (GCC, MinGW, or MSVC)

Any IDE supporting C++ (Code::Blocks, Visual Studio, Dev-C++, etc.)

Steps to Run

Clone the repository:

git clone https://github.com/MuhammadAwaisRafique/Design-and-Implement-a-Race-Car-Game-using-Dikstra-Algorithm.git

Navigate to the project folder:

cd race-car-game

Compile the program:

g++ main.cpp -o racecar.exe

Run the executable:

./racecar.exe

🤝 Contributors

Muhammad Awais Rafique (Myself)

