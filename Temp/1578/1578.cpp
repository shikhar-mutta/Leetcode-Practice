// Link: https://leetcode.com/problems/minimum-time-to-make-rope-colorful/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int total = 0;
        int i = 0, n = colors.size();
        while (i < n) {
            int j = i;
            int sum = 0, mx = 0;
            while (j < n && colors[j] == colors[i]) {
                sum += neededTime[j];
                mx = max(mx, neededTime[j]);
                j++;
            }
            total += sum - mx;
            i = j;
        }
        return total;
    }
};
