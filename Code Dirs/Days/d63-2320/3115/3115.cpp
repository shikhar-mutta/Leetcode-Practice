// Link: https://leetcode.com/problems/maximum-prime-difference/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n * sqrt(maxVal)), SC: O(1)
// Approach: Find the index of the first prime scanning from the left and
// the index of the last prime scanning from the right; the answer is the
// gap between them.
class Solution {
public:
    bool isprime(int n) {
        if (n < 2)
            return false;
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0)
                return false;
        }
        return true;
    }
    int maximumPrimeDifference(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int first = 0, last = 0, n = nums.size();
        for (int i = 0; i < n; i++) {
            if (isprime(nums[i])) {
                first = i;
                break;
            }
        }
        for (int i = n - 1; i >= 0; i--) {
            if (isprime(nums[i])) {
                last = i;
                break;
            }
        }
        return last - first;
    }
};
