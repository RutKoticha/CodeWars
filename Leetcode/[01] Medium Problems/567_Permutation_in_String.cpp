/**
 * @file 567_Permutation_in_String.cpp
 * @author Rut Koticha
 * @date 2026-02-13
 */

#include <iostream>
#include <unordered_map>

class Solution {
public:
  bool checkInclusion(std::string s1, std::string s2)
  {
    size_t s1Length = s1.length();
    size_t s2Length = s2.length();

    if (s1Length > s2Length)
      return false;

    // Take the frequencies of the characters in s1
    std::unordered_map<int, int> frequency;

    for (char& character : s1)
      frequency[character]++;

    // Make a window of size equeal to s1 in s2
    size_t windowLeft = 0, windowRight = s1Length - 1;
    std::unordered_map<int, int> frequencyWindow;

    for (size_t i = windowLeft; i <= windowRight; i++)
    {
      frequencyWindow[s2.at(i)]++;
    }

    // Shift the window right until end
    while (windowRight < s2Length)
    {

      if (frequencyWindow == frequency)
        return true;

      char firstCharacter = s2.at(windowLeft);
      frequencyWindow[firstCharacter]--;
      if (!frequencyWindow[firstCharacter])
        frequencyWindow.erase(firstCharacter);

      windowLeft++;

      windowRight++;
      if (windowRight < s2Length)
        frequencyWindow[s2.at(windowRight)]++;
    }

    return false;
  }
};
