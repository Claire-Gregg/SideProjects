#include <iostream>
#include <vector>

void print_game(std::vector<char> game) {
  for (int i = 0; i < game.size(); i++) {
    std::cout << game[i];
    if ((i + 1) % 3 == 0) {
      std::cout << "\n";
    }
    else {
      std::cout << " | ";
    }
  }
}

void input(std::vector<char> &game, char player) {
  int spot;
  print_game(game); 
  bool done = false;
  std::cout << "Where would you like to place your piece? ";
while (done == false) {
    std::cin >> spot;
    if (game[spot - 1] == '_') {
      game[spot - 1] = player;
      done = true;
    }
    else {
      std::cout << "That spot is already taken, choose another. ";
    }
  }
}

bool endgame(std::vector<char> game, char player) {

  for (int i = 0; i < 9; i++) {

    if (i % 3 == 0) {

      if ((game[i] == player) && (game[i + 1] == player) && (game[i + 2] == player)) {
        return true;
      } 

    }
    
    else if (i < 3) {

      if ((game[i] == player) && (game[i + 3] == player) && (game[i + 6] == player)) {
        return true;
      }

    }

    else if (i == 4) {

      if ( game[i] == player && ( (game[0] == player && game[8] == player) || ( game[2] == player && game[6] == player) ) ) {
        return true;
      }

    }

  }

  return false;

}