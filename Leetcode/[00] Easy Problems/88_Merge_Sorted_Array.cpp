#include <bits/stdc++.h>

/**
 * Author:	Rut Koticha
 * Created at:	2025-03-01 09:59:55 (Saturday)
 */

class Solution {
  public:
    void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n);
};

void Solution::merge(std::vector<int> & nums1, int m,
                     std::vector<int> & nums2, int n) {
    if(nums1.empty()) {
        nums1 = nums2;
        return;
    }

    if(nums2.empty()) {
        return;
    }

    int i = 0,
        j = 0;

    std::vector<int> temporary(m);
    for(int i = 0; i < m; i++) {
        temporary[i] = nums1[i];
    }

    while(i < n && j < m) {
        if(temporary[i] < nums2[j]) {
            nums1[i + j] = temporary[i];
        } else {
            nums1[i + j] = nums2[j];
        }
        i++;
        j++;
    }

    std::cout << i << " " << j << "\n";

    while(i < n) {
        nums1[i + j] = temporary[i];
        i++;
    }

    while(j < m) {
        nums1[i + j] = nums2[j];
        j++;
    }
}
