/**
 * Author: Rut Koticha
 * Date: 2025-09-01 22:56
 */

class Solution {
public:
  int reverseBits(int n) {
    int reverse = 0;

    for (int i = 0; i < 32; i++, n >>= 1) {
      int bit = n & 1;
      reverse <<= 1;
      reverse |= bit;
    }

    return reverse;
  }
};
