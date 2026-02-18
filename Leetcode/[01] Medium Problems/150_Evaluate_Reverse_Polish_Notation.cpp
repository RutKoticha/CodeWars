/**
 * @file 150_Evaluate_Reverse_Polish_Notation.cpp
 * @author Rut Koticha
 * @date 2026-02-14
 */

#include <vector>
#include <string>
#include <stack>

class Solution {
  bool IsValidOperator(std::string token)
  {
    bool isTokenLengthNot1 = token.length() - 1;
    if (isTokenLengthNot1)
      return false;

    switch (token.front())
    {
    case '+':
    case '-':
    case '*':
    case '/':
      return true;

    default:
      return false;
    }
  }

  int Operate(std::string token, int operand1, int operand2)
  {
    switch (token.front())
    {
    case '+': return operand1 + operand2;
    case '-': return operand1 - operand2;
    case '*': return operand1 * operand2;
    case '/': return operand1 / operand2;
    default: return -1;
    }
  }

public:
  int evalRPN(std::vector<std::string>& tokens)
  {
    std::stack<int> operandStack;

    for (std::string& token : tokens)
    {
      if (IsValidOperator(token))
      {
        int operand2 = operandStack.top();
        operandStack.pop();
        int operand1 = operandStack.top();
        operandStack.pop();

        operandStack.push(Operate(token, operand1, operand2));
      }
      else
      {
        operandStack.push(std::stoi(token));
      }
    }

    return operandStack.top();
  }
};
