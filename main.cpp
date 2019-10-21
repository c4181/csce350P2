#include <iostream>
#include <map>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::map;
using std::pair;
using std::stoi;
using std::string;
using std::vector;
/***************************************************************************
 * Author/copyright:  Christopher Moyer.  All rights reserved.
 * Date: 18 October 2019
 *
 * TODO Write program description
 *
 **/
void loop(vector<int> counts, int index, int num_of_loops, map<char, int> &solutions) {
  for (counts.at(index); counts.at(index) < 10; counts.at(index) = counts.at(index) + 1) {
    if (index != num_of_loops) {
      counts.push_back(0);
      loop(counts, index + 1, num_of_loops, solutions);
    } 
    
    if (index == num_of_loops) {
      for (size_t i = 0; i < counts.size(); ++i) {
        for (size_t j = 1; j < counts.size(); ++j) {
          if (j != i) {
            if (counts.at(i) == counts.at(j)) {
              cout << counts.at(i) << endl;
              return;
            }
          }
        }
      }
    
    for (map<char, int>::iterator it=solutions.begin(); it!=solutions.end(); ++it) {
      it -> second = counts.at(index);
      cout << counts.at(index);
    }
    return;
    }
  }
}
int main() {
  bool found_solution;
  string input;
  string first_word;
  string second_word;
  string third_word;
  map<char, int> solutions;
  vector<int> counts;
  
  while(cin >> input) {
    size_t plus_index;
    size_t equals_index;
    plus_index = input.find("+", 0);
    first_word = input.substr(0, plus_index);
    found_solution = false;

    equals_index = input.find("=");
    second_word = input.substr(plus_index + 1, (equals_index - plus_index) - 1);

    third_word = input.substr(equals_index + 1);

    for (size_t i = 0; i < first_word.size(); ++i) {
      solutions.insert(pair<char, int>(first_word.at(i), 0));
    }
    for (size_t i = 0; i < second_word.size(); ++i) {
      solutions.insert(pair<char, int>(second_word.at(i), 0));
    }
    for(size_t i = 0; i < third_word.size(); ++i) {
      solutions.insert(pair<char, int>(third_word.at(i), 0));
    }

    counts.push_back(1);
    loop(counts, 0, solutions.size() - 1, solutions);

    for (map<char, int>::iterator it = solutions.begin(); it != solutions.end(); ++it) {
      cout << it -> first << " " << it -> second << endl;
      string solution_string_1, solution_string_2, solution_string_3;
      int solution_int_1, solution_int_2, solution_int_3;

      for (size_t i = 0; i < first_word.size(); ++i) {
        solution_string_1 += solutions.find(first_word.at(i)) -> second;
      }
      for (size_t i = 0; i < second_word.size(); ++i) {
        solution_string_2 += solutions.find(second_word.at(i)) -> second;
      }
      for (size_t i = 0; i < third_word.size(); ++i) {
        solution_string_3 += solutions.find(third_word.at(i)) -> second;
      }

      solution_int_1 = stoi(solution_string_1);
      solution_int_2 = stoi(solution_string_2);
      solution_int_3 = stoi(solution_string_3);

      if (solution_int_1 + solution_int_2 == solution_int_3) {
        found_solution = true;
        cout << solution_int_1 << "+" << solution_int_2 << "=" << solution_int_3 << endl;
      }
    }
    if (found_solution == false) {
      cout << "no solution" << endl;
      cout << endl;
    } else {
      cout << endl;
    }
  }
}
