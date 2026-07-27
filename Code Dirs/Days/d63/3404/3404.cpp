// Link: https://leetcode.com/problems/count-special-subsequences/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n^2) SC: O(n^2)
// Approach: condition nums[p]*nums[r]==nums[q]*nums[s] rearranges to
// nums[p]/nums[q] == nums[s]/nums[r] (reduced by gcd to avoid floats).
// Precompute a hashmap of reduced (nums[s],nums[r]) ratio counts for all
// valid (r,s) with r>=4 and s>=r+2. Then sweep q from 2 upward: for each
// valid p<=q-2, look up its ratio vs nums[q] in the map and add matches;
// afterward drop the pairs with r==q+2 since they become invalid once q
// advances past them.
class Solution {
public:
    long long numberOfSubsequences(vector<int>& nums) {
        int n = nums.size();
        if (n < 7) return 0;

        auto keyOf = [](int a, int b) {
            int g = gcd(a, b);
            return (long long)(a / g) * 100000LL + (b / g);
        };

        unordered_map<long long, int> rightMap;
        for (int r = 4; r <= n - 3; r++)
            for (int s = r + 2; s <= n - 1; s++)
                rightMap[keyOf(nums[s], nums[r])]++;

        long long ans = 0;
        for (int q = 2; q <= n - 5; q++) {
            for (int p = 0; p <= q - 2; p++) {
                auto it = rightMap.find(keyOf(nums[p], nums[q]));
                if (it != rightMap.end()) ans += it->second;
            }
            int r = q + 2;
            if (r <= n - 3) {
                for (int s = r + 2; s <= n - 1; s++) {
                    long long k = keyOf(nums[s], nums[r]);
                    if (--rightMap[k] == 0) rightMap.erase(k);
                }
            }
        }
        return ans;
    }
};
