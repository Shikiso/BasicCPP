#include <iostream>
#include <cmath>

// c_squared = a_squared + b_squared

using namespace std;

int main(int argc, char** argv[]){
  float c;
  float a;
  float b;

  cout << "Enter the a size: ";
  cin >> a;

  cout << "Enter the b size: ";
  cin >> b;

  // Equation
  c = sqrt((a * a) + (b * b));
  cout << "a squared + b squared = " << c << " squared!" << endl;

  return 0;
}
