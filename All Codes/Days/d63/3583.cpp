// Link: https://leetcode.com/problems/count-special-triplets/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) SC: O(n)
// Approach: for each middle index j, count = (occurrences of nums[j]*2
// before j) * (occurrences of nums[j]*2 after j). Maintain a left
// frequency map built incrementally and a right frequency map that
// starts as the full count and gets decremented as we pass each index.
class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        const long long MOD = 1e9 + 7;
        unordered_map<int, long long> left, right;
        for (int x : nums) right[x]++;

        long long ans = 0;
        for (int x : nums) {
            right[x]--;
            long long need = (long long)x * 2;
            auto lit = left.find(need);
            auto rit = right.find(need);
            if (lit != left.end() && rit != right.end()) {
                ans = (ans + (lit->second * rit->second) % MOD) % MOD;
            }
            left[x]++;
        }
        return (int)ans;
    }
};
