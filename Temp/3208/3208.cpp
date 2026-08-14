// Link: https://leetcode.com/problems/alternating-groups-ii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n = colors.size();
        vector<int> streak(n + k - 1);
        streak[0] = 1;
        for (int idx = 1; idx < n + k - 1; idx++) {
            int i = idx % n, prev = (idx - 1) % n;
            if (colors[i] != colors[prev]) streak[idx] = streak[idx-1] + 1;
            else streak[idx] = 1;
        }
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            int endIdx = i + k - 1;
            if (streak[endIdx] >= k) cnt++;
        }
        return cnt;
    }
};
