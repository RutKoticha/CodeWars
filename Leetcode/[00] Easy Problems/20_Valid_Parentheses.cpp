/**
 * Author: Rut Koticha
 * Date: 2025-08-29 21:13
 */

#include <stack>
#include <string>

using namespace std;

class Solution {
private:
  bool is_opening(char character) {
    switch (character) {
    case '(':
    case '[':
    case '{':
      return true;
    }

    return false;
  }

  char get_opening(char character) {
    switch (character) {
    case ')':
      return '(';
    case ']':
      return '[';
    case '}':
      return '{';
    }

    return -1;
  }

public:
  bool isValid(string s) {
    stack<char> brackets;

    for (char character : s) {
      // Push to stack if the character is an opening bracket
      if (is_opening(character)) {
        brackets.push(character);
      }
      // Pop from stack if the character is a closing bracket
      else {
        if (brackets.empty() || brackets.top() != get_opening(character)) {
          return false;
        }

        brackets.pop();
      }
    }

    return brackets.empty();
  }
};
