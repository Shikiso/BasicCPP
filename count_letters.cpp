#include <iostream>
#include <string.h>

using namespace std;

int main(int argc, char *argv[]){
  string scentence;
  char letter;
  int count=0;

  cout << "Enter a scentence: ";
  getline(cin, scentence);

  cout << "Enter a letter to count: ";
  cin >> letter;
  
  for (int i=0; i<scentence.length(); i++){
    if (scentence[i] == letter){
      count++;
    }
  }

  cout << "The letter " << letter << " appeared " << count << " times!" << endl;

  return 0;
}
