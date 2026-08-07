// Link: https://leetcode.com/problems/combinations/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(C(n,k) * k)  SC: O(k) recursion depth (excluding output)
// Approach: backtracking with a start index to avoid duplicate/reordered combinations
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> cur;
        function<void(int)> bt = [&](int start) {
            if ((int)cur.size() == k) { res.push_back(cur); return; }
            for (int i = start; i <= n; i++) {
                cur.push_back(i);
                bt(i + 1);
                cur.pop_back();
            }
        };
        bt(1);
        return res;
    }
};
