// Link: https://leetcode.com/problems/max-sum-of-a-pair-with-equal-sum-of-digits/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int digitSum(int x) {
        int s = 0;
        while (x > 0) { s += x % 10; x /= 10; }
        return s;
    }

    int maximumSum(vector<int>& nums) {
        unordered_map<int,int> best;
        int ans = -1;
        for (int x : nums) {
            int s = digitSum(x);
            if (best.count(s)) ans = max(ans, best[s] + x);
            best[s] = max(best.count(s) ? best[s] : 0, x);
        }
        return ans;
    }
};
