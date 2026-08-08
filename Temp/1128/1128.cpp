// Link: https://leetcode.com/problems/number-of-equivalent-domino-pairs/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        vector<int> cnt(100, 0);
        int res = 0;
        for (auto& d : dominoes) {
            int a = min(d[0], d[1]), b = max(d[0], d[1]);
            int key = a * 10 + b;
            res += cnt[key];
            cnt[key]++;
        }
        return res;
    }
};
