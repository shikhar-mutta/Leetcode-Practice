// Link: https://leetcode.com/problems/minimum-number-of-days-to-eat-n-oranges/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    unordered_map<int,int> memo;

    int minDays(int n) {
        if (n <= 1) return n;
        if (memo.count(n)) return memo[n];
        int res = min(n % 2 + 1 + minDays(n / 2), n % 3 + 1 + minDays(n / 3));
        memo[n] = res;
        return res;
    }
};
