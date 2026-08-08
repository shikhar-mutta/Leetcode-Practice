// Link: https://leetcode.com/problems/numbers-with-same-consecutive-differences/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> res;
        for (int start = 1; start <= 9; start++) {
            vector<int> cur = {start};
            dfs(cur, n, k, res);
        }
        return res;
    }

private:
    void dfs(vector<int>& cur, int n, int k, vector<int>& res) {
        if ((int)cur.size() == n) {
            int num = 0;
            for (int d : cur) num = num * 10 + d;
            res.push_back(num);
            return;
        }
        int last = cur.back();
        for (int next : {last + k, last - k}) {
            if (next < 0 || next > 9) continue;
            if (k == 0 && next != last) continue;
            cur.push_back(next);
            dfs(cur, n, k, res);
            cur.pop_back();
            if (k == 0) break;
        }
    }
};
