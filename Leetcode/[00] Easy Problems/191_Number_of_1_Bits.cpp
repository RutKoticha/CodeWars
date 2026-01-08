/**
 * Author: Rut Koticha
 * Date: 2025-08-31 07:52
 */

class Solution {
public:
  int hammingWeight(int n) {
    int total = 0;

    do {
      total += (n & 1);
    } while (n >>= 1);

    return total;
  }
};
