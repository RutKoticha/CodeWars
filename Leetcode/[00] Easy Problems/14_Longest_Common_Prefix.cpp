/**
 * @file 14_Longest_Common_Prefix.cpp
 * @author Rut Koticha
 * @date 2025-12-28
 * @brief Keep a track of the common string from the first string using a pointer
 */

#include <string>
#include <vector>

class Solution {
public:
  std::string longestCommonPrefix(std::vector<std::string>& strs)
  {
    std::string first = strs.front();
    size_t totalStrings = strs.size();

    size_t commonTill = first.length();

    for (size_t i = 1; i < totalStrings; i++)
    {
      std::string currentString = strs.at(i);
      size_t stringLength = currentString.length();

      commonTill = std::min(commonTill, stringLength);

      for (size_t character = 0; character < commonTill; character++)
      {
        if (currentString.at(character) != first.at(character))
          commonTill = character;
      }
    }

    return  first.substr(0, commonTill).c_str();
  }
};
