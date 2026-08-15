// Link: https://leetcode.com/problems/maximum-bags-with-full-capacity-of-rocks/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int n = capacity.size();
        vector<int> remaining(n);
        for (int i = 0; i < n; i++) remaining[i] = capacity[i] - rocks[i];
        vector<int> idx(n);
        for (int i = 0; i < n; i++) idx[i] = i;
        sort(idx.begin(), idx.end(), [&](int a, int b) { return remaining[a] < remaining[b]; });
        int count = 0;
        for (int i : idx) {
            if (remaining[i] <= additionalRocks) {
                additionalRocks -= remaining[i];
                count++;
            } else break;
        }
        return count;
    }
};
