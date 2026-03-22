/**
 * Author: Rut Koticha
 * Date: 2025-08-15 23:39
 */

class Solution {
public:
  bool isPowerOfTwo(int n) {
    if (n <= 0) {
      return false;
    }
    return !(n & (n - 1));
  }
};