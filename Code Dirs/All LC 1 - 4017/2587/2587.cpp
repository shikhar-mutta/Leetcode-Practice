// Link: https://leetcode.com/problems/rearrange-array-to-maximize-prefix-score/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxScore(vector<int>& nums) {
        sort(nums.rbegin(), nums.rend());
        long long sum = 0;
        int count = 0;
        for (int x : nums) {
            sum += x;
            if (sum > 0) count++;
            else break;
        }
        return count;
    }
};
