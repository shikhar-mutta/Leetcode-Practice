// Link: https://leetcode.com/problems/find-good-days-to-rob-the-bank/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        int n = security.size();
        vector<int> nonIncRun(n, 1), nonDecRun(n, 1);
        for (int i = 1; i < n; i++) {
            if (security[i] <= security[i - 1]) nonIncRun[i] = nonIncRun[i - 1] + 1;
        }
        for (int i = n - 2; i >= 0; i--) {
            if (security[i] <= security[i + 1]) nonDecRun[i] = nonDecRun[i + 1] + 1;
        }
        vector<int> res;
        for (int i = 0; i < n; i++) {
            if (nonIncRun[i] >= time + 1 && nonDecRun[i] >= time + 1) res.push_back(i);
        }
        return res;
    }
};
