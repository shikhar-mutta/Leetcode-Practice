// Link: https://leetcode.com/problems/maximum-number-of-operations-with-the-same-score-i/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxOperations(vector<int>& nums) {
        int n = nums.size();
        int target = nums[0] + nums[1];
        int cnt = 0;
        for (int i = 0; i + 1 < n; i += 2) {
            if (nums[i] + nums[i+1] != target) break;
            cnt++;
        }
        return cnt;
    }
};
