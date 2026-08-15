// Link: https://leetcode.com/problems/consecutive-numbers-sum/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(sqrt(n)) SC: O(1)
// Approach: for k consecutive numbers starting at a, sum = k*a + k*(k-1)/2 = n; solve for a = (n - k*(k-1)/2) / k, valid if positive integer. Try k from 1 while k*(k+1)/2 <= n.
class Solution {
public:
    int consecutiveNumbersSum(int n) {
        int count = 0;
        for (long long k = 1; k*(k-1)/2 < n; k++) {
            long long rem = n - k*(k-1)/2;
            if (rem % k == 0) count++;
        }
        return count;
    }
};
