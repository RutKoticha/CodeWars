/**
 * Author: Rut Koticha
 * Date: 2025-09-17 17:35
 */

#include <cmath>
#include <string>
#include <unordered_map>

using HashMap = std::unordered_map<char, int>;

class Solution {
public:
  std::string minWindow(std::string s, std::string t) {
    int n = s.length(), m = t.length();

    if (!m) {
      return "";
    }

    // Take the character frequency of t
    HashMap countT;
    for (const char &character : t) {
      countT[character]++;
    }

    HashMap countS;
    int have = 0, need = countT.size();

    std::pair<int, int> result = {-1, -1};
    int resultLength = __INT_MAX__;

    int left = 0;
    for (int right = 0; right < n; right++) {
      // Take the character
      char character = s.at(right);
      countS[character]++;

      bool weCare = (countT.find(character) != countT.end());
      if (weCare && (countS.at(character) == countT.at(character))) {
        have++;
      }

      while (have == need) {
        // Update result
        int length = right - left + 1;
        if (length < resultLength) {
          result = {left, right};
          resultLength = length;
        }

        // Shrink the string
        char trim = s.at(left);
        countS[trim]--;

        bool weCare = (countT.find(trim) != countT.end());
        if (weCare && countS[trim] < countT[trim]) {
          have--;
        }

        left++;
      }
    }

    // Return the result
    if (resultLength == __INT_MAX__) {
      return "";
    }

    return s.substr(result.first, resultLength);
  }
};
