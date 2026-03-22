/**
 * @file 2_Add_Two_Numbers.cpp
 * @author Rut Koticha
 * @date 2025-12-19
 */

#ifdef LOCAL_RUN
struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};
#endif

class Solution {
  void Add(int a, int b, int& sum, int& carry)
  {
    sum = a + b + carry;
    carry = sum / 10;
    sum = sum % 10;
  }

public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
  {
    ListNode* number1 = l1,
      * number2 = l2,
      * answer = new ListNode(),
      * answerStart = answer;

    int sum = 0, carry = 0;

    // Add the two numbers
    while (number1 && number2)
    {
      Add(number1->val, number2->val, sum, carry);

      answer->next = new ListNode(sum);
      answer = answer->next;

      number1 = number1->next;
      number2 = number2->next;
    }

    // Add remaining number1
    while (number1)
    {
      Add(number1->val, 0, sum, carry);

      answer->next = new ListNode(sum);
      answer = answer->next;

      number1 = number1->next;
    }

    // Add remaining number2
    while (number2)
    {
      Add(number2->val, 0, sum, carry);

      answer->next = new ListNode(sum);
      answer = answer->next;

      number2 = number2->next;
    }

    // Deal with left-over carry
    if (carry)
      answer->next = new ListNode(carry);

    // Remove the first dummy node
    ListNode* dummy = answerStart;
    answerStart = answerStart->next;
    delete dummy;

    return answerStart;
  }
};
