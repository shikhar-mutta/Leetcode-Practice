// Link: https://leetcode.com/problems/apply-operations-to-maximize-frequency-score/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxFrequencyScore(vector<int>& nums, long long k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<long long> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) prefix[i+1] = prefix[i] + nums[i];

        auto cost = [&](int l, int r) -> long long {
            int m = (l + r) / 2;
            long long leftCost = (long long)nums[m] * (m - l) - (prefix[m] - prefix[l]);
            long long rightCost = (prefix[r+1] - prefix[m+1]) - (long long)nums[m] * (r - m);
            return leftCost + rightCost;
        };

        int l = 0, ans = 1;
        for (int r = 0; r < n; r++) {
            while (cost(l, r) > k) l++;
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};
