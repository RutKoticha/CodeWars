/**
 * Author: Rut Koticha
 * Date: 2025-08-26 11:04
 */

#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
  vector<int> compute_prefix(const vector<int> &numbers) {
    int n = numbers.size();

    // Create the prefix multiplication vector of size same as numbers
    vector<int> prefix(n);

    // Set the default value in the vector
    prefix[0] = numbers[0];

    // Compute the values in prefix multiplication vector
    for (int i = 1; i < n; i++) {
      prefix[i] = prefix[i - 1] * numbers[i];
    }

    // Return the vector
    return prefix;
  }

  vector<int> compute_suffix(const vector<int> &numbers) {
    int n = numbers.size();

    // Create the suffix multiplication vector of size same as numbers
    vector<int> suffix(n);

    // Set the default value in the vector
    suffix[n - 1] = numbers[n - 1];

    // Compute the values in suffix multiplication vector
    for (int i = n - 2; i >= 0; i--) {
      suffix[i] = numbers[i] * suffix[i + 1];
    }

    // Return the vector
    return suffix;
  }

public:
  vector<int> productExceptSelf(vector<int> &numbers) {
    int n = numbers.size();

    // Get the prefix vector
    vector<int> prefix = compute_prefix(numbers);

    // Get the suffix vector
    vector<int> suffix = compute_suffix(numbers);

    // Create a result vector same size as numbers
    vector<int> result(n, 1);

    // Compute the result vector values by multiplying
    // prefix value with suffix value
    for (int i = 0; i < n; i++) {
      if (i - 1 >= 0) {
        result[i] = prefix[i - 1];
      }

      if (i + 1 < n) {
        result[i] *= suffix[i + 1];
      }
    }

    // Return the result vector
    return result;
  }
};
