#include <bits/stdc++.h>

/**
 * Author:	Rut Koticha
 * Created at:	2025-02-27 10:47:54 (Thursday)
 */

class Solution {
  public:
    int lengthOfLastWord(std::string s);
};

int Solution::lengthOfLastWord(std::string s) {
    int wordLength = 0;
    int index = s.size() - 1;

    while (index >= 0 && s[index] == ' ') {
        index--;
    }

    while (index >= 0 && s[index] != ' ') {
        wordLength++;
        index--;
    }
    return wordLength;
}
