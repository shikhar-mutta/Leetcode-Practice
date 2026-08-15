// Link: https://leetcode.com/problems/beautiful-array/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> beautifulArray(int n) {
        return build(n);
    }

private:
    unordered_map<int, vector<int>> memo;
    vector<int> build(int n) {
        if (n == 1) return {1};
        if (memo.count(n)) return memo[n];
        vector<int> left = build((n + 1) / 2);
        vector<int> right = build(n / 2);
        vector<int> res;
        for (int x : left) res.push_back(2 * x - 1);
        for (int x : right) res.push_back(2 * x);
        memo[n] = res;
        return res;
    }
};
