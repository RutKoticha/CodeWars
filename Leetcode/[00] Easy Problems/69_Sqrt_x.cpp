#include <bits/stdc++.h>

/**
 * Author:	Rut Koticha
 * Created at:	2025-02-28 11:09:33 (Friday)
 */

class Solution {
  public:
    int mySqrt(int x);
};


int Solution::mySqrt(int x) {
    if(x == 0 || x == 1) {
        return x;
    }

    double left = 0,
           right = x,
           root = -1;

    double epsilon = 1e-6;

    while(left <= right) {
        double mid = left + ((right - left) / 2.0);
        double square = mid * mid;

        std::cout << mid << std::endl;

        if(abs(square - x) < epsilon) {
            return std::floor(mid);
        }

        if(square == x) {
            root = mid;
            break;
        }

        if(square < x) {
            left = mid;
        } else {
            right = mid;
        }

        root = mid;
    }

    return std::floor(root);
}
