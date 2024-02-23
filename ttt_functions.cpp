#include <iostream>
#include <vector>
#include <string>
#include "ttt_functions.hpp"

std::string grid[10] = {" ", " ", " ", " ", " ", " ", " ", " ", " ", " "};
std::vector<std::string> players;
int player = 1;
std::string playerOne;
std::string playerTwo;
int choices;


void welcome(){
  std::cout << "--------------------------\n";
  std::cout << "--------------------------\n";
  std::cout << "  Welcome to Tic-Tac-Toe!\n";
  std::cout << "--------------------------\n";
  std::cout << "--------------------------\n\n";
}

void setUp(){
  std::cout << "X, enter your name: \n";
  std::cin >> playerOne;
  players.push_back(playerOne);
  std::cout << "O, enter your name: \n";
  std::cin >> playerTwo;
  players.push_back(playerTwo);
  std::cout << "\n"; 
}

bool fullGrid(){
	bool full = true;
	for(int i = 1; i < 10; i++){
		if(grid[i] == " "){
			full = false; 
		}
	}
	return full;
}

void showGrid(){
	std::cout << "  " << grid[1] << " | " << grid[2] << " | " << grid[3] << "\n";
	std::cout << "-------------\n";
	std::cout << "  " << grid[4] << " | " << grid[5] << " | " << grid[6] << "\n";
	std::cout << "-------------\n";
	std::cout << "  " << grid[7] << " | " << grid[8] << " | " << grid[9] << "\n";
}

bool isWinner() {

  bool wins = false;
  // rows
  if ((grid[1] == grid[2]) && (grid[2] == grid[3]) && grid[1] != " ") {
    wins = true;
  } else if ((grid[4] == grid[5]) && (grid[5] == grid[6]) && grid[4] != " ") {
    wins = true;
  } else if ((grid[7] == grid[8]) && (grid[8] == grid[9]) && grid[7] != " ") {
    wins = true;
  } 
  // columns
  else if ((grid[1] == grid[4]) && (grid[1] == grid[7]) && grid[1] != " ") {
    wins = true;
  } else if ((grid[2] == grid[5]) && (grid[2] == grid[8]) && grid[2] != " ") {
    wins = true;
  } else if ((grid[3] == grid[6]) && (grid[3] == grid[9]) && grid[3] != " ") {
    wins = true;
  } // diagonals
  else if ((grid[1] == grid[5]) && (grid[1] == grid[9]) && grid[1] != " ") {
    wins = true;
  }
  else if ((grid[3] == grid[5]) && (grid[3] == grid[7]) && grid[3] != " ") {
    wins = true;
  }

  return wins;

}

std::string getMark(){
	if(player == 0) {
		return "X";
	} else {
		return "O";
	}

}

int getPlayer(){
	if(player == 1){
		player--;
	} else {
		player++;
	}
	return player;
}

void play(){
	while(!isWinner() && !fullGrid()){
		std::cout << players[getPlayer()] << "'s turn. Choose position: \n";
		std::cin >> choices;
		if(grid[choices] == " "){
			grid[choices] = getMark();
			showGrid();
		} else {
      if (player == 0) {
        player++;
      }
      else
      {
        player--;
      }
      std::cout << players[getPlayer()]<< "Try again \n";
      std::cin >> choices;
      grid[choices] = getMark();
      showGrid();
    }
	}
}

void endGame(){
	if(fullGrid() && isWinner()){
		std::cout << "Game end," << players[player] << " wins!\n";
	} else if(fullGrid() && !isWinner()) {
		std::cout << "Game end, nobody wins!\n";
	} else {
		std::cout << "Game end," << players[player] << " wins!\n"; 
	}
}

