// Link: https://leetcode.com/problems/minimum-number-of-days-to-eat-n-oranges/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    unordered_map<int, int> memo;
public:
    int minDays(int n) {
        if (n <= 1) return n;
        if (memo.count(n)) return memo[n];
        int res = 1 + min(n % 2 + minDays(n / 2), n % 3 + minDays(n / 3));
        return memo[n] = res;
    }
};
