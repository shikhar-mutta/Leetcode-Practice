// Link: https://leetcode.com/problems/minimum-number-of-frogs-croaking/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minNumberOfFrogs(string croakOfFrogs) {
        string order = "croak";
        unordered_map<char,int> idx;
        for (int i = 0; i < 5; i++) idx[order[i]] = i;

        vector<int> cnt(5, 0);
        int active = 0, maxActive = 0;

        for (char c : croakOfFrogs) {
            int i = idx[c];
            if (i == 0) {
                cnt[0]++;
                active++;
                maxActive = max(maxActive, active);
            } else {
                if (cnt[i-1] == 0) return -1;
                cnt[i-1]--;
                cnt[i]++;
                if (i == 4) {
                    cnt[4]--;
                    active--;
                }
            }
        }
        if (active != 0) return -1;
        return maxActive;
    }
};
