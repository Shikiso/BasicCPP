#include <iostream>

using namespace std;

int main(int argc, char *argv[]){
  float a = 0;
  float b = 0;
  float sum = 0;
  char o;
  char answer = 'y';
  
  while (true){
    cout << "Enter the first number: ";
    cin >> a;

    cout << "Enter the second number: ";
    cin >> b;
  
    cout << "1.Addition +\n2.Subtract - \n3.Mutliply x \n4.Divide / \nSelect an operator (e.g, +): ";
    cin >> o;

    switch (o){
      case '+':
        sum = a + b;
        break;
      case '-':
        sum = a - b;
        break;
      case 'x':
        sum = a * b;
        break;
      case '/':
        sum = a / b;
        break;
      default:
        cout << "Invalid operator!" << endl;
        continue;
    }

    cout << a << " " << o << " " << b << " = " << sum << endl;

    cout << "Do you want to do another equation? (y/n): ";
    cin >> answer;

    if (answer == 'n'){
      break;
    }
  }
  

  return 0;
}
