/**
 * Author: Rut Koticha
 * Date: 2025-08-15 23:12
 */

class Solution {
public:
  bool isPowerOfFour(int n) {
    int number = 1;

    while (number < n) {
      number <<= 2;
    }

    return (number == n);
  }
};
