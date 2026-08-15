// Link: https://leetcode.com/problems/sort-integers-by-the-power-value/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    unordered_map<long long,int> memo;

    int power(long long n) {
        if (n == 1) return 0;
        if (memo.count(n)) return memo[n];
        int res = 1 + power(n % 2 == 0 ? n / 2 : 3 * n + 1);
        memo[n] = res;
        return res;
    }

    int getKth(int lo, int hi, int k) {
        vector<int> nums(hi - lo + 1);
        iota(nums.begin(), nums.end(), lo);
        sort(nums.begin(), nums.end(), [&](int a, int b) {
            int pa = power(a), pb = power(b);
            if (pa != pb) return pa < pb;
            return a < b;
        });
        return nums[k-1];
    }
};
