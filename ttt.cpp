#include <iostream>
#include <vector>
#include "ttt_functions.hpp"

int main() {
  std::vector<char> game{'_', '_', '_', '_', '_', '_', '_', '_', '_'};
  char player = 'X';
  bool win = false;

  for (int i = 1; i < 10; i++) {
    if (i % 2 == 0) {
      player = 'O';
    }
    else {
      player = 'X';
    }

    input(game, player);
    win = endgame(game, player);
    if (win == true) {
      print_game(game);
      std::cout << player << " is the winner!";
      break;
    }
  }

  if (win == false) {
    print_game(game);
    std::cout << "Stalemate!";
  }


  return 0;
}