// Link: https://leetcode.com/problems/minimum-moves-to-make-array-complementary/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<int> delta(2 * limit + 2, 0);
        for (int i = 0; i < n / 2; i++) {
            int a = nums[i], b = nums[n - 1 - i];
            int lo = min(a, b) + 1, hi = max(a, b) + limit - 1;
            delta[2] += 2;
            delta[lo] -= 1;
            delta[a + b] -= 1;
            delta[a + b + 1] += 1;
            delta[hi + 1] += 1;
        }
        int best = INT_MAX, cur = 0;
        for (int s = 2; s <= 2 * limit; s++) {
            cur += delta[s];
            best = min(best, cur);
        }
        return best;
    }
};
