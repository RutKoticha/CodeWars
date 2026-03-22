/**
 * Author: Rut Koticha
 * Date: 2025-08-26 11:55
 */

#include <unordered_map>
#include <vector>

using namespace std;

#define INT_MIN -1e9

class Solution {
private: /* <-- Data Members --> */
  unordered_map<int, int> parent;
  unordered_map<int, int> size;

private: /* <-- Methods -->*/
  void unite(int u, int v) {
    int parent_u = find(u);
    int parent_v = find(v);

    if (parent_u == parent_v) {
      return;
    }

    size[parent_u] += size[parent_v];

    parent[v] = u;
  }

  int find(int element) {
    if (parent.find(element) == parent.end()) {
      return INT_MIN;
    }

    if (parent[element] == element) {
      return element;
    }

    return parent[element] = find(parent[element]);
  }

public:
  int longestConsecutive(vector<int> &nums) {
    int n = nums.size();

    // Construct disjoint set
    for (int number : nums) {
      parent[number] = number;
      size[number] = 1;
    }

    // Get each number and make previous parent
    for (int number : nums) {
      if (find(number - 1) == INT_MIN) {
        continue;
      } else {
        unite(number - 1, number);
      }
    }

    int max_size = 0;

    // Get the max consecutive sequence
    for (auto [_, size] : size) {
      max_size = max(max_size, size);
    }

    return max_size;
  }
};
