// Link: https://leetcode.com/problems/check-if-array-is-good/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n = nums.size() - 1;
        if (n < 1) return false;
        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());
        for (int i = 0; i < n - 1; i++) {
            if (sorted[i] != i + 1) return false;
        }
        return sorted[n-1] == n && sorted[n] == n;
    }
};
