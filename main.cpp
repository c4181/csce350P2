#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::map;
using std::pair;
using std::next_permutation;
using std::stoi;
using std::string;
using std::to_string;
using std::vector;
/***************************************************************************
 * Author/copyright:  Christopher Moyer.  All rights reserved.
 * Date: 21 October 2019
 *
 * TODO Write program description
 *
 **/
int main() {
  string input;
  string first_word, second_word, third_word;
  vector<int> permuations {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  
  while(cin >> input) {
    bool solution_found = false;
    size_t plus_index;
    size_t equals_index;
    plus_index = input.find("+", 0);
    first_word = input.substr(0, plus_index);
    map<char, int> tester;
    vector<map<char, int>> checked_permutations;

    equals_index = input.find("=");
    second_word = input.substr(plus_index + 1, (equals_index - plus_index) - 1);

    third_word = input.substr(equals_index + 1);

    for (size_t i = 0; i < first_word.size(); ++i) {
      tester.insert(pair<char, int>(first_word.at(i), 0));
    }
    for (size_t i = 0; i < second_word.size(); ++i) {
      tester.insert(pair<char, int>(second_word.at(i), 0));
    }
    for(size_t i = 0; i < third_word.size(); ++i) {
      tester.insert(pair<char, int>(third_word.at(i), 0));
    }

    do {
      int i = 0;
      map<char, int>::iterator it;
      bool already_checked = false;
      string first_word_test, second_word_test, third_word_test;
      int first_word_int, second_word_int, thrid_word_int;
      for (it = tester.begin(); it != tester.end(); ++it) {
        it -> second = permuations.at(i);
        ++i;
      }

      for (size_t i = 0; i < first_word.size(); ++i) {
        it = tester.find(first_word.at(i));
        first_word_test += to_string(it -> second);
      }
      if (first_word_test.at(0) == '0') continue;
      for (size_t i = 0; i < second_word.size(); ++i) {
        it = tester.find(second_word.at(i));
        second_word_test += to_string(it -> second);
      }
      if (second_word_test.at(0) == '0') continue;
      for (size_t i = 0; i < third_word.size(); ++i) {
        it = tester.find(third_word.at(i));
        third_word_test += to_string(it -> second);
      }
      if (third_word_test.at(0) == '0') continue;

      first_word_int = stoi(first_word_test);
      second_word_int = stoi(second_word_test);
      thrid_word_int = stoi(third_word_test);

      if (first_word_int + second_word_int == thrid_word_int) {
        for (size_t i = 0; i < checked_permutations.size(); ++i) {
          if (checked_permutations.at(i) == tester) {
            already_checked = true;
            break;
          }
        }
        if (already_checked) {
          continue;
        } else checked_permutations.push_back(tester);
        cout << first_word_int << "+" << second_word_int << "=" << thrid_word_int << endl;
        solution_found = true;
      }
    } while (next_permutation(permuations.begin(), permuations.end()));

    if (solution_found == false) {
      cout << "no solution" << endl;
      cout << endl;
    } else {
      cout << endl;
    }
  }
}
