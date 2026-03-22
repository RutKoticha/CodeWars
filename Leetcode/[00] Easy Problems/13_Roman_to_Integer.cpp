/**
 * @file 13_Roman_to_Integer.cpp
 * @author Rut Koticha
 * @date 2025-12-31
 */

#include <string>

class Solution {
private:
    int GetValue(char);
public:
    int romanToInt(std::string);
};

int Solution::GetValue(char romanCharacter)
{
    switch (romanCharacter)
    {
    case 'I':
        return 1;
    case 'V':
        return 5;
    case 'X':
        return 10;
    case 'L':
        return 50;
    case 'C':
        return 100;
    case 'D':
        return 500;
    case 'M':
        return 1000;
    default:
        return -1;
    }
}

int Solution::romanToInt(std::string s)
{
    int result = 0;
    int length = s.length();
    int prevValue = Solution::GetValue(s[length - 1]);

    for (int i = length - 1; i >= 0; i--)
    {
        int intValue = Solution::GetValue(s[i]);

        if (intValue < result && prevValue != intValue)
            result -= intValue;
        else
            result += intValue;

        prevValue = intValue;
    }

    return result;
}
