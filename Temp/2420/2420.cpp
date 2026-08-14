// Link: https://leetcode.com/problems/find-all-good-indices/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> goodIndices(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> decLen(n, 1), incLen(n, 1);
        for (int i = 1; i < n; i++)
            if (nums[i] <= nums[i-1]) decLen[i] = decLen[i-1] + 1;
        for (int i = n - 2; i >= 0; i--)
            if (nums[i] <= nums[i+1]) incLen[i] = incLen[i+1] + 1;

        vector<int> ans;
        for (int i = k; i < n - k; i++) {
            if (decLen[i-1] >= k && incLen[i+1] >= k) ans.push_back(i);
        }
        return ans;
    }
};
