// Link: https://leetcode.com/problems/count-the-number-of-good-partitions/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfGoodPartitions(vector<int>& nums) {
        unordered_map<int, int> last;
        for (int i = 0; i < (int)nums.size(); i++) last[nums[i]] = i;
        const long long MOD = 1e9 + 7;
        int groups = 0;
        int end = -1;
        for (int i = 0; i < (int)nums.size(); i++) {
            if (i > end) groups++;
            end = max(end, last[nums[i]]);
        }
        long long ans = 1;
        for (int i = 0; i < groups - 1; i++) ans = ans * 2 % MOD;
        return (int)ans;
    }
};
