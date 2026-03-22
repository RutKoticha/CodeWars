/**
 * Author: Rut Koticha
 * Date: 2025-08-22 22:19
 */

#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<string>> groupAnagrams(vector<string> &strings) {
    // Create a hash map
    unordered_map<string, vector<string>> hash;

    // Take each string and sort it, take the sorted string,
    //  treat as key and insert the actual string as vector in hash map
    for (const string &str : strings) {
      string key = str;
      sort(key.begin(), key.end());
      hash[key].push_back(str);
    }

    // Convert values in hashmap to vector
    vector<vector<string>> groups;

    for (auto [_, strings] : hash) {
      groups.push_back(strings);
    }

    return groups;
  }
};
