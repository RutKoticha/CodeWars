/**
 * Author: Rut Koticha
 * Date: 2025-09-05 10:14
 */

#include <set>

using namespace std;

class Solution {
private:
  int square_sum(int n) {
    int sum = 0;
    while (n > 0) {
      sum += (n % 10) * (n % 10);
      n /= 10;
    }
    return sum;
  }

public:
  // We can detect cycle like the graph problem
  // using the fast and slow pointer method
  bool isHappy(int n) {
    int turtle = n;
    int rabbit = square_sum(n);

    while (rabbit != 1 && rabbit != turtle) {
      turtle = square_sum(turtle);
      rabbit = square_sum(square_sum(rabbit));
    }

    return (rabbit == 1);
  }
};
