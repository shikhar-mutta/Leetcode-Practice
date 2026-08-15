// Link: https://leetcode.com/problems/factor-combinations/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(exponential in factor count)  SC: O(depth) recursion (excluding output)
// Approach: backtracking trying divisors from a running lower bound up to sqrt(remaining),
// each combination plus the leftover remaining factor forms one valid factorization
class Solution {
public:
    vector<vector<int>> getFactors(int n) {
        vector<vector<int>> res;
        vector<int> cur;
        function<void(int,int)> bt = [&](int remain, int start) {
            for (int i = start; (long long)i * i <= remain; i++) {
                if (remain % i == 0) {
                    cur.push_back(i);
                    cur.push_back(remain / i);
                    res.push_back(cur);
                    cur.pop_back();
                    bt(remain / i, i);
                    cur.pop_back();
                }
            }
        };
        bt(n, 2);
        return res;
    }
};
