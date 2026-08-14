// Link: https://leetcode.com/problems/sum-of-digit-differences-of-all-pairs/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long sumDigitDifferences(vector<int>& nums) {
        int n = nums.size();
        vector<string> s(n);
        for (int i = 0; i < n; i++) s[i] = to_string(nums[i]);
        int len = s[0].size();
        long long total = 0;
        for (int pos = 0; pos < len; pos++) {
            vector<int> cnt(10, 0);
            for (int i = 0; i < n; i++) cnt[s[i][pos] - '0']++;
            long long same = 0;
            for (int d = 0; d < 10; d++) same += (long long)cnt[d] * (cnt[d] - 1) / 2;
            long long totalPairs = (long long)n * (n - 1) / 2;
            total += totalPairs - same;
        }
        return total;
    }
};
