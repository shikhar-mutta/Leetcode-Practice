// Link: https://leetcode.com/problems/count-sequences-to-k/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(3^(n/2))  SC: O(3^(n/2))
// Approach: since every nums[i] is in [1,6], it factors purely into powers
// of 2,3,5; represent each element and k as an exponent triple. Each
// element's choice (skip / multiply / divide) adds 0, +vector, or -vector
// to a running exponent-triple total; we need sequences whose total equals
// k's triple. Split nums in half, DP a map (triple -> count of choice-
// sequences reaching it) for each half independently, then combine via
// meet-in-the-middle: answer = sum over left triples d of left[d] *
// right[target - d].
class Solution {
    map<int,array<int,3>> lookup = {
        {1,{0,0,0}}, {2,{1,0,0}}, {3,{0,1,0}}, {4,{2,0,0}}, {5,{0,0,1}}, {6,{1,1,0}}
    };

    map<array<int,3>, long long> count(vector<int>& nums) {
        map<array<int,3>, long long> dp;
        dp[{0,0,0}] = 1;
        for (int x : nums) {
            auto d = lookup[x];
            map<array<int,3>, long long> newDp;
            for (auto& [c, cnt] : dp) {
                newDp[c] += cnt;
                newDp[{c[0]+d[0], c[1]+d[1], c[2]+d[2]}] += cnt;
                newDp[{c[0]-d[0], c[1]-d[1], c[2]-d[2]}] += cnt;
            }
            dp = newDp;
        }
        return dp;
    }

public:
    int countSequences(vector<int>& nums, long long k) {
        array<int,3> target = {0,0,0};
        long long x = k;
        while (x % 2 == 0) { x /= 2; target[0]++; }
        while (x % 3 == 0) { x /= 3; target[1]++; }
        while (x % 5 == 0) { x /= 5; target[2]++; }
        if (x != 1) return 0;

        int n = nums.size();
        vector<int> leftNums(nums.begin(), nums.begin() + n/2);
        vector<int> rightNums(nums.begin() + n/2, nums.end());
        auto leftDp = count(leftNums);
        auto rightDp = count(rightNums);

        long long ans = 0;
        for (auto& [d, cnt] : leftDp) {
            array<int,3> need = {target[0]-d[0], target[1]-d[1], target[2]-d[2]};
            auto it = rightDp.find(need);
            if (it != rightDp.end()) ans += cnt * it->second;
        }
        return (int)ans;
    }
};
