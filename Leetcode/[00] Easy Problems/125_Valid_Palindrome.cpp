/**
 * Author: Rut Koticha
 * Date: 2025-08-26 19:57
 */
#include <string>

using namespace std;

class Solution {
private:
  string remove_special_characters(const string &s) {
    string dense_string;
    for (const char &character : s) {
      if (!isalpha(character) && !isdigit(character)) {
        continue;
      }

      dense_string += character;
    }

    return dense_string;
  }

  string to_lowercase(const string &s) {
    string lowercase_string;

    for (const char &character : s) {
      lowercase_string += tolower(character);
    }

    return lowercase_string;
  }

public:
  bool isPalindrome(string input_string) {
    string dense_string = remove_special_characters(input_string);
    string lowercase_string = to_lowercase(dense_string);

    int n = lowercase_string.length();

    // Check for being palindrome
    int left = 0, right = n - 1;
    while (left < right) {
      if (lowercase_string[left] != lowercase_string[right]) {
        return false;
      }

      left++;
      right--;
    }

    return true;
  }
};
