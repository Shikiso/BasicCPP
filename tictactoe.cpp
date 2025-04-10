#include <iostream>
#include <cctype>
#include <cstdlib>

using namespace std;

/*
0|1|2
3|4|5
6|7|8
*/ 

// # are positions to be played
string map = "#|#|#\n#|#|#\n#|#|#";

int Useds_positions[9] = {};
int turnCounter = 0;

char Player = 'X';
char AI = 'O';
char currentTurn = 'X';
char restart;

void draw_map(){
  cout << map << "\n\n";
}

int check_position_is_valid(int pos){
  for (int i=0; i<map.length(); i=i+2){
    if (map[i] == '#' && i/2 == pos-1){
      return 1; // Valid
    }
  }
  return 0; // Invalid
}

// Positions = 0 2 4 6 8 10 12 14 16
int set_position(int pos, char player){
  string newMap;
  pos = pos * 2;
  for (int i=0; i<map.length(); i++){
    if (i == pos){
      newMap = newMap+ player;
    }
    else{
      newMap = newMap + map[i];
    }
  }
  map = newMap;
  return 0;
}

// Lets player choose whether to be O or X
void select_object(){
  while (true){
    char selection;
    cout << "Do you want to be O or X, enter the one you want to play as: ";
    cin >> selection;
    selection = tolower(selection);
    if (selection == 'x'){
      Player = 'X';
      AI = 'O';
      break;
    }
    else if (selection == 'o'){
      Player = 'O';
      AI = 'X';
      break;
    }
    else{
      cout << "Invalid selection!" << endl;
    }
  }
}

int checkWinner(){
  // Checking rows
  for (int i=4; i<map.length(); i=i+6){
    if (map[i] == map[i-2] && map[i] == map[i-4] && map[i] != '#'){
      cout << map[i] << " is a winner!" << endl;
      return 1;
    }
  }
  
  // Checking columns
  for (int i=12; i<map.length(); i=i+2){
    if (map[i] == map[i-6] && map[i] == map[i-12] && map[i] != '#'){
      cout << map[i] << " is a winner!" << endl;
      return 1;
    }
  }

  // Checking diagonal
  for (int i=12; i<map.length(); i=i+4){
    if (map[i] == map[i-4] && map[i] == map[i-8] && map[i] != '#'){
      cout << map[i] << " is a winner!" << endl;
      return 1;
    }
    if (map[i] == map[i-8] && map[i] == map[i-16] && map[i] != '#'){
      cout << map[i] << " is a winner!" << endl;
      return 1;
    }
  }

  // Checking for draw
  for (int i=0; i<map.length(); i++){
    if (map[i] == '#'){
      return 0;
    }
  }
  cout << "Draw!" << endl;
  return 1;
}

int get_AI_position(){
  int position = 0;
  while (true){
    position = rand() % 10;
    if (check_position_is_valid(position) == 1){
      return position;
    }
  }
  return 0;
}

void play_position(){
  int position;
  while (true){
    if (Player == currentTurn){
      cout << "Players turn select where you want to play: ";
      cin >> position;

      if (position > 9 || check_position_is_valid(position) == 0){
        cout << "Invalid position! Try again!" << endl;
        continue;
      }
      else{
        set_position(position-1, currentTurn);
        currentTurn = AI;
      }
    }
    else{
      cout << "AI turn." << endl;
      position = get_AI_position();
      set_position(position-1, currentTurn);
      currentTurn = Player;
    }
    break;
  }
  Useds_positions[turnCounter] = position;
  turnCounter++;
}

void mainLoop(){
  while (true){
    draw_map();
    play_position();
    if (checkWinner() == 1){
      draw_map();
      cout << "Do you wish to play again? (y/n): ";
      cin >> restart;
      if (tolower(restart) == 'y'){
        map = "#|#|#\n#|#|#\n#|#|#";
        currentTurn = 'X';
        select_object();
        continue;
      }
      else{
        break;
      }
    }
  }
}

int main(int argc, char* argv[]){
  // Start up
  select_object();
  mainLoop();
  return 0;
}
