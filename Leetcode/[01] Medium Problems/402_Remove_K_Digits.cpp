/**
 * @file 402_Remove_K_Digits.cpp
 * @author Rut Koticha
 * @date 2026-01-22
 * @brief Remove digits which are bigger
 *        than correct one
 */

#include <string>
#include <stack>

class Solution {
private:
  int IntValue(char character)
  {
    return character - '0';
  }

public:
  std::string removeKdigits(std::string num, int k)
  {
    std::stack<char> stack;

    int index = 0;

    // Remove preciding zeros
    while (!IntValue(num.at(index)))
      index++;

    // Return early if the number is all 0s
    if (index >= num.size())
      return "0";

    // Add the first value to stack
    stack.push(num.at(index));
    index++;

    // Go till the number is reached 0 or k runs out
    while (index < num.size() && k)
    {
      printf("Processing %c,\n", num.at(index));

      if (num.at(index) < stack.top())
      {
        printf("Popping from stack\n");
        stack.pop();
        k--;
      }

      stack.push(num.at(index));
      index++;
    }

    // Add remaining elements to the stack
    while (index < num.size())
    {
      stack.push(num.at(index));
      index++;
    }

    // Keep going until k is done
    while (!stack.empty() && k)
      stack.pop();

    // Construct the number remaining
    std::stack<char> reverser;
    std::string digits(std::max(stack.size(), size_t(1)), '0');

    while (!stack.empty())
    {
      reverser.push(stack.top());
      stack.pop();
    }

    while (!reverser.empty() && !IntValue(reverser.top()))
      reverser.pop();

    index = 0;
    while (!reverser.empty())
    {
      digits.at(index) = reverser.top();
      index++;
    }

    return digits;
  }
};
