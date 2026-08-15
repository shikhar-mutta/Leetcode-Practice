// Link: https://leetcode.com/problems/max-pair-sum-in-an-array/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSum(vector<int>& nums) {
        unordered_map<int, int> best;
        int ans = -1;
        for (int x : nums) {
            int m = 0, t = x;
            while (t) { m = max(m, t % 10); t /= 10; }
            if (best.count(m)) ans = max(ans, best[m] + x);
            best[m] = max(best[m], x);
        }
        return ans;
    }
};
