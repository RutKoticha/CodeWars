/**
 * Author: Rut Koticha
 * Date: 2025-09-04 18:02
 */

#include <list>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> plusOne(vector<int> &digits) {
    // Sum the last digit with 1
    digits[digits.size() - 1] += 1;

    // Get the carry
    int carry = digits[digits.size() - 1] / 10;
    digits[digits.size() - 1] %= 10;

    // Continue adding to the previous on if
    // carry is generated until the first digit
    for (int i = digits.size() - 1; i > 0; i--) {
      digits[i - 1] += carry;
      carry = digits[i - 1] / 10;
      digits[i - 1] %= 10;
    }

    // Add a first digit same to carry if
    // there is any remaining
    if (carry > 0) {
      digits.insert(digits.begin(), carry);
    }

    return digits;
  }
};
