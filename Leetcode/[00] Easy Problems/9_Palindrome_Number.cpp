/**
 * @file 9_Palindrome_Number.cpp
 * @author Rut Koticha
 * @date 2025-12-21
 */

#include <algorithm>
#include <vector>

class Solution {
public:
  bool isPalindrome(int x)
  {
    if (x < 0)
      return false;

    int original = x;

    int reversed = 0;
    while (x)
    {
      reversed = (reversed * 10) + (x % 10);
      x /= 10;
    }

    return x == reversed;
  }
};
