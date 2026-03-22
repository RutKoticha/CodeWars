/**
 * Author: Rut Koticha
 * Date: 2025-09-01 22:40
 */

#include <vector>

using namespace std;

class Solution {
public:
  vector<int> countBits(int n) {
    vector<int> bits(n + 1);
    bits[0] = 0;

    for (int i = 1; i <= n; i++) {
      bits[i] = bits[i >> 1] + (i & 1);
    }

    return bits;
  }
};
