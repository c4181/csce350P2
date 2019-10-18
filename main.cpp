#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;
/***************************************************************************
 * Author/copyright:  Christopher Moyer.  All rights reserved.
 * Date: 18 October 2019
 *
 * TODO Write program description
 *
 **/

int main() {
  string input;
  string first_word;
  string second_word;
  string third_word;
  
  while(cin >> input) {
    size_t plus_index;
    size_t equals_index;
    plus_index = input.find("+", 0);
    first_word = input.substr(0, plus_index);

    equals_index = input.find("=");
    second_word = input.substr(plus_index + 1, (equals_index - plus_index) - 1);

    third_word = input.substr(equals_index + 1);

    cout << first_word << endl;
    cout << second_word << endl;
    cout << third_word << endl;
  }
}
