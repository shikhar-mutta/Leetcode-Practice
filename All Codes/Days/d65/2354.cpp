// Link: https://leetcode.com/problems/number-of-excellent-pairs/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(N + 32*32), SC: O(N)
// Approach: identity popcount(a|b)+popcount(a&b)=popcount(a)+popcount(b). Group distinct values
// by popcount, sum freq[p1]*freq[p2] over ordered popcount pairs with p1+p2>=k.
class Solution {
public:
    long long countExcellentPairs(vector<int>& nums, int k) {
        unordered_set<int> distinct(nums.begin(), nums.end());
        long long freq[32] = {};
        for (int v : distinct) freq[__builtin_popcount(v)]++;

        long long ans = 0;
        for (int p1 = 0; p1 < 32; p1++)
            for (int p2 = 0; p2 < 32; p2++)
                if (p1 + p2 >= k) ans += freq[p1] * freq[p2];
        return ans;
    }
};
