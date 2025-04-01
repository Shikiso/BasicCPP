#include <iostream>
#include <cctype>

using namespace std;

/*
0|1|2
3|4|5
6|7|8
*/ 

// # are positions to be played
string map = "#|#|#\n#|#|#\n#|#|#";

char Player = 'X';
char AI = 'O';
char currentTurn = 'X';
char restart;

void draw_map(){
  cout << map << "\n\n";
}

// Positions = 0 2 4 6 8 10 12 14 16
int set_position(int pos, char player){
  string newMap;
  pos = pos * 2;
  for (int i=0; i<map.length(); i++){
    if (i == pos){
      if (map[i] != '#'){
        return -1;
      }
      else{
        newMap = newMap+ player;
      }
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
  int preferedPositions[4] = {0, 2, 6, 8};

  if (AI == 'O'){
    for (int i=0; i<4; i++){
      for (int j=0; j<map.length(); j++){
        if (map[j] == '#' && j/2 == preferedPositions[i]){
          currentTurn = Player;
          return preferedPositions[i];
        }
      }
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

      if (position > 9){
        cout << "Invalid position! Try again!" << endl;
        continue;
      }
      else{
        if (set_position(position-1, currentTurn) == -1){
          cout << "Invalid position! Try again!" << endl;
          continue;
        }
        else{
          currentTurn = AI;
        }
      }
    }
    else{
      cout << "AI turn." << endl;
      set_position(get_AI_position(), currentTurn);
    }
    break;
  }
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
