// Link: https://leetcode.com/problems/fair-distribution-of-cookies/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int best;
    void backtrack(vector<int>& cookies, int idx, vector<int>& bags) {
        if (idx == (int)cookies.size()) {
            best = min(best, *max_element(bags.begin(), bags.end()));
            return;
        }
        for (int i = 0; i < (int)bags.size(); i++) {
            if (bags[i] + cookies[idx] >= best) continue;
            bags[i] += cookies[idx];
            backtrack(cookies, idx + 1, bags);
            bags[i] -= cookies[idx];
        }
    }

    int distributeCookies(vector<int>& cookies, int k) {
        best = INT_MAX;
        vector<int> bags(k, 0);
        backtrack(cookies, 0, bags);
        return best;
    }
};
