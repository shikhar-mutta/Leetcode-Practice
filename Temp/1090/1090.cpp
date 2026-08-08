// Link: https://leetcode.com/problems/largest-values-from-labels/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int numWanted, int useLimit) {
        int n = values.size();
        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](int a, int b) { return values[a] > values[b]; });

        unordered_map<int,int> used;
        int sum = 0, count = 0;
        for (int i : idx) {
            if (count >= numWanted) break;
            if (used[labels[i]] >= useLimit) continue;
            sum += values[i];
            used[labels[i]]++;
            count++;
        }
        return sum;
    }
};
