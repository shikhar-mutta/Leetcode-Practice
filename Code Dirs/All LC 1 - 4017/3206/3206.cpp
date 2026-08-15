// Link: https://leetcode.com/problems/alternating-groups-i/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors) {
        int n = colors.size();
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            int prev = colors[(i - 1 + n) % n];
            int next = colors[(i + 1) % n];
            if (colors[i] != prev && colors[i] != next) cnt++;
        }
        return cnt;
    }
};
