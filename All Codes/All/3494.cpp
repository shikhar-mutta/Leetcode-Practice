// Link: https://leetcode.com/problems/find-the-minimum-amount-of-time-to-brew-potions/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        int n = skill.size(), m = mana.size();
        vector<long long> finishPrev(n, 0);
        vector<long long> prefix(n + 1);

        for (int j = 0; j < m; j++) {
            prefix[0] = 0;
            for (int i = 0; i < n; i++) prefix[i+1] = prefix[i] + (long long)skill[i] * mana[j];

            long long start0 = 0;
            for (int i = 0; i < n; i++) start0 = max(start0, finishPrev[i] - prefix[i]);

            for (int i = 0; i < n; i++) finishPrev[i] = start0 + prefix[i+1];
        }

        return finishPrev[n-1];
    }
};
