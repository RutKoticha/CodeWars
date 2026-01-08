/**
 * @file 28_Find_the_Index_of_the_First_Occurrence_in_a_String.cpp
 * @author Rut Koticha
 * @date 2026-01-03
 */

class Solution {
  public:
    int strStr(const std::string & haystack, const std::string & needle);
};

int Solution::strStr(const std::string & haystack, const std::string & needle) {
    if (needle.empty()) {
        return 0;
    }

    if (haystack.empty()) {
        return -1;
    }

    int haystackLength = haystack.length();
    int needleLength = needle.length();

    for (int i = 0; i <= (haystackLength - needleLength); i++) {
        if (haystack[i] == needle[0]) {
            int j = 0;

            while (j < needleLength && haystack[i + j] == needle[j]) {
                j++;
            }

            if (j == needleLength) {
                return i;
            }
        }
    }
    return -1;
}
