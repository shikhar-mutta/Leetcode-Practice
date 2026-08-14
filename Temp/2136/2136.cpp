// Link: https://leetcode.com/problems/earliest-possible-day-of-full-bloom/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        int n = plantTime.size();
        vector<int> idx(n);
        for (int i = 0; i < n; i++) idx[i] = i;
        sort(idx.begin(), idx.end(), [&](int a, int b) { return growTime[a] > growTime[b]; });
        int day = 0, best = 0;
        for (int i : idx) {
            day += plantTime[i];
            best = max(best, day + growTime[i]);
        }
        return best;
    }
};
