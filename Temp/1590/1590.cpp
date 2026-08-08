// Link: https://leetcode.com/problems/make-sum-divisible-by-p/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        long long total = 0;
        for (int x : nums) total += x;
        int target = total % p;
        if (target == 0) return 0;

        unordered_map<int,int> lastIndex;
        lastIndex[0] = -1;
        int best = n;
        long long prefix = 0;
        for (int i = 0; i < n; i++) {
            prefix = (prefix + nums[i]) % p;
            int need = ((prefix - target) % p + p) % p;
            if (lastIndex.count(need)) {
                best = min(best, i - lastIndex[need]);
            }
            lastIndex[prefix] = i;
        }
        return best == n ? -1 : best;
    }
};
