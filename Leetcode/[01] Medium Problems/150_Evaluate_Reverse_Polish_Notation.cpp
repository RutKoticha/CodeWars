/**
 * @file 150_Evaluate_Reverse_Polish_Notation.cpp
 * @author Rut Koticha
 * @date 2025-12-17
 */

#include <vector>
#include <string>
#include <stack>

class Solution {
private:
  std::stack<int> stack;

private:
  bool IsOperator(std::string value)
  {
    switch (value[0])
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

  int Operate(int operand1, int operand2, char op)
  {
    switch (op)
    {
    case '+':
      return operand1 + operand2;
    case '-':
      return operand1 - operand2;
    case '*':
      return operand1 * operand2;
    case '/':
      return operand1 / operand2;
    }

    return -1;
  }

public:
  int evalRPN(std::vector<std::string>& tokens)
  {
    for (std::string token : tokens)
    {
      if (IsOperator(token))
      {
        int operand2 = stack.top();
        stack.pop();

        int operand1 = stack.top();
        stack.pop();

        int answer = Operate(operand1, operand2, token[0]);
        stack.push(answer);
        printf("%s %s %s = %s\n", operand1, operand2, token, answer);
      }
      else
      {
        stack.push(std::stoi(token));
        printf("Operand : %d\n", stack.top());
      }
    }

    return stack.top();
  }
};
