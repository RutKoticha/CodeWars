/**
 * Author: Rut Koticha
 * Date: 2025-08-22 22:49
 */

#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> topKFrequent(vector<int> &numbers, int k) {
    size_t n = numbers.size();

    // Create a hash table based on count of elements
    unordered_map<int, int> frequency;

    int max_frequency = 0;

    // Count number frequencies
    for (int number : numbers) {
      frequency[number]++;
      max_frequency = max(max_frequency, frequency[number]);
    }

    // Create bucket array and insert elements based on count
    vector<vector<int>> buckets(max_frequency + 1, vector<int>());

    // Insert values based on frequency
    for (const auto &[number, count] : frequency) {
      buckets[count].push_back(number);
    }

    // Traverse from back of the array and find k elements
    vector<int> result;

    for (int index = max_frequency; index >= 0; index--) {
      if (buckets[index].empty()) {
        continue;
      }

      for (int number : buckets[index]) {
        k--;
        result.push_back(number);

        if (k == 0) {
          return result;
        }
      }
    }

    return result;
  }
};
