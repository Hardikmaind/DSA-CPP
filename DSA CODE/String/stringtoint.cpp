#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main()
{
  string mystr; // Declare a string variable to store user input
  float price = 0; // Initialize price variable to 0
  int quantity = 0; // Initialize quantity variable to 0

  // Prompt the user to enter the price
  cout << "Enter price: ";
  getline(cin, mystr); // Read a line of input from the user and store it in mystr

  // Convert the input string to a float using stringstream
  stringstream(mystr) >> price;

  // Prompt the user to enter the quantity
  cout << "Enter quantity: ";
  getline(cin, mystr); // Read another line of input from the user and store it in mystr

  // Convert the input string to an integer using stringstream
  stringstream(mystr) >> quantity;      //here mystr is getting overwritten by the new input

  // Calculate and output the total price by multiplying price and quantity
  cout << "Total price: " << price * quantity << endl;

  return 0;
}

