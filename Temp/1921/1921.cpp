// Link: https://leetcode.com/problems/eliminate-maximum-number-of-monsters/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n = dist.size();
        vector<double> arrival(n);
        for (int i = 0; i < n; i++) arrival[i] = (double)dist[i] / speed[i];
        sort(arrival.begin(), arrival.end());
        for (int i = 0; i < n; i++) {
            if (arrival[i] <= i) return i;
        }
        return n;
    }
};
