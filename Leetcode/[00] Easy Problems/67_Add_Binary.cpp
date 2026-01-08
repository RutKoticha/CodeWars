#include <bits/stdc++.h>

/**
 * Author:	Rut Koticha
 * Created at:	2025-02-28 10:47:18 (Friday)
 */

class Solution {
  public:
    std::string addBinary(const std::string & a, const std::string & b);
};

std::string Solution::addBinary(const std::string & a, const std::string & b) {
    std::string answer = "";

    int carry = 0;

    int i = a.length() - 1,
        j = b.length() - 1;

    while(i >= 0 && j >= 0) {
        int bitA = a[i] - '0',
            bitB = b[j] - '0',
            sum = carry ^ bitA ^ bitB;

        carry = (carry & bitA) | (carry & bitB) | (bitA & bitB);
        answer = std::to_string(sum) + answer;
        i--;
        j--;
    }

    while(i >= 0) {
        int bitA = a[i] - '0',
            sum = carry ^ bitA;

        carry = (carry & bitA);
        answer = std::to_string(sum) + answer;
        i--;
    }

    while(j >= 0) {
        int bitB = b[j] - '0',
            sum = carry ^ bitB;

        carry = (carry & bitB);
        answer = std::to_string(sum) + answer;
        j--;
    }

    if(carry) {
        answer = std::to_string(carry) + answer;
    }

    return answer;
}
