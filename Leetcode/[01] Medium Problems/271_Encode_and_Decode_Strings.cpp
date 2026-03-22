/**
 * Author: Rut Koticha
 * Date: 2025-08-23 09:52
 */

#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  string encode(vector<string> &strings) {
    string encoded_string;

    for (string string : strings) {
      encoded_string += string.length() + "#" + string;
    }

    return encoded_string;
  }

  vector<string> decode(string &encoded_string) {
    int string_length = encoded_string.length();
    vector<string> decoded_strings;

    int index = 0;
    while (index < string_length) {
      // Get the length of the string
      int length = 0;
      while (encoded_string[index] != '#') {
        length = (length * 10) + (encoded_string[index] - '0');
        index++;
      }

      // Get the string
      string string = encoded_string.substr(index + 1, length);
      decoded_strings.push_back(string);

      index += length + 1;
    }

    return decoded_strings;
  }
};
