// Link: https://leetcode.com/problems/count-alternating-subarrays/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long countAlternatingSubarrays(vector<int>& nums) {
        long long ans = 0;
        int runLen = 1;
        for (int i = 1; i < (int)nums.size(); i++) {
            if (nums[i] != nums[i-1]) runLen++;
            else runLen = 1;
            ans += runLen;
        }
        ans += 1; // first element alone
        return ans;
    }
};
