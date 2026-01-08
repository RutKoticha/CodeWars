/**
 * @file 155_Min_Stack.cpp
 * @author Rut Koticha
 * @date 2025-12-17
 */

#include <stack>

class MinStack {
private:
  struct StackItem {
    int value;
    int minValue;
  };

private:
  std::stack<StackItem> stack;

public:
  MinStack()
  {
  }

  void push(int value)
  {
    if (!stack.empty())
      stack.push({ .value = value, .minValue = stack.top().minValue });
    else
      stack.push({ .value = value, .minValue = value });
  }

  void pop()
  {
    stack.pop();
  }

  int top()
  {
    return stack.top().value;
  }

  int getMin()
  {
    return stack.top().minValue;
  }
};
