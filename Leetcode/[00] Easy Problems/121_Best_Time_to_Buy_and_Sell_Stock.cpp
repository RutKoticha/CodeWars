/**
 * Author: Rut Koticha
 * Date: 2025-08-28 23:24
 */

#include <vector>

using namespace std;

class Solution {
public:
  int maxProfit(vector<int> &prices) {
    if (prices.empty()) {
      return 0;
    }

    int maxProfit = 0;

    int left = 0;
    int right = 0;

    while (right < prices.size()) {
      if (prices[left] < prices[right]) {
        int profit = prices[right] - prices[left];
        maxProfit = max(maxProfit, profit);
        right++;
      } else {
        left = right;
        right++;
      }
    }

    return maxProfit;
  }
};
