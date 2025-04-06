#include <iostream>

int main(int argc, char* argv[]){
  float distance;
  float speed;
  float time;

  std::cout << "How fast is the train moving: ";
  std::cin >> speed;

  std::cout << "For how long is the train moving: ";
  std::cin >> time;

  distance = speed * time;
  std::cout << "The train has moved " << distance << " in " << speed << " seconds!" << std::endl;
  
  return 0;
}
