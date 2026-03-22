/**
 * Author: Rut Koticha
 * Date: 2025-08-08 19:51
 */

#include <string>
#include <vector>

class Solution {
public:
  int lengthOfLongestSubstring(std::string s) {
    int n = s.length();
    int max_length = 0;

    std::vector<bool> visited(256);

    // define pointers
    int left = 0, right = 0;

    // loop till the right reaches to the end
    while (right < n) {
      // Remove the already visited elements from the left
      while (visited[s[right]]) {
        visited[s[left]] = false;
        left++;
      }

      // Calculate the answer
      max_length = std::max(max_length, right - left + 1);

      // Mark the current element as visited
      visited[s[right]] = true;
      right++;
    }

    return max_length;
  }
};
