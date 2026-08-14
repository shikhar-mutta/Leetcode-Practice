// Link: https://leetcode.com/problems/longest-subsequence-with-limited-sum/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(), nums.end());
        vector<int> prefix(nums.size());
        int sum = 0;
        for (int i = 0; i < (int)nums.size(); i++) {
            sum += nums[i];
            prefix[i] = sum;
        }
        vector<int> ans;
        for (int q : queries) {
            int cnt = upper_bound(prefix.begin(), prefix.end(), q) - prefix.begin();
            ans.push_back(cnt);
        }
        return ans;
    }
};
