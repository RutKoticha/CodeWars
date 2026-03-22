/**
 * Author: Rut Koticha
 * Date: 2025-09-06 15:30
 */

#include <unordered_set>
#include <vector>

class Solution {
public:
  int longestConsecutive(std::vector<int> &numbers) {
    int n = numbers.size();
    std::unordered_set<int> numbers_set(numbers.begin(), numbers.end());

    int max_length = 0;

    for (auto number : numbers_set) {
      // If not start of a sequence
      // Then leave this number
      if (numbers_set.find(number - 1) != numbers_set.end()) {
        continue;
      }

      // Count the sequence length
      int length = 0;
      while (numbers_set.find(number + length) != numbers_set.end()) {
        length++;
      }

      // Update the max if needed
      max_length = std::max(max_length, length);
    }

    return max_length;
  }
};
