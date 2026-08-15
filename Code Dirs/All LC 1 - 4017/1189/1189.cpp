// Link: https://leetcode.com/problems/maximum-number-of-balloons/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char,int> cnt;
        for (char c : text) cnt[c]++;
        int best = INT_MAX;
        best = min(best, cnt['b']);
        best = min(best, cnt['a']);
        best = min(best, cnt['l'] / 2);
        best = min(best, cnt['o'] / 2);
        best = min(best, cnt['n']);
        return best == INT_MAX ? 0 : best;
    }
};
