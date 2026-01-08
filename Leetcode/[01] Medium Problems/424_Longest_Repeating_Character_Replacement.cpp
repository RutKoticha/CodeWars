/**
 * Author: Rut Koticha
 * Date: 2025-09-15 19:52
 */

#include <string>
#include <unordered_map>

class Solution {
public:
  int characterReplacement(std::string s, int k) {
    int n = s.length();
    int max_length = 0;
    std::unordered_map<char, int> frequency;

    int left = 0;
    int max_frequency = 0;

    for (int right = 0; right < n; right++) {
      char character = s[right];
      frequency[character]++;

      max_frequency = std::max(frequency[character], max_frequency);

      while (((right - left + 1) - max_frequency) > k) {
        char trim = s[left];
        frequency[trim]--;
        left++;
      }

      max_length = std::max(max_length, right - left + 1);
    }

    return max_length;
  }
};
