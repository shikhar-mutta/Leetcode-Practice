// Link: https://leetcode.com/problems/minimum-initial-energy-to-finish-tasks/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        sort(tasks.begin(), tasks.end(), [](const vector<int>& a, const vector<int>& b) {
            return (a[1] - a[0]) > (b[1] - b[0]);
        });
        long long spent = 0, needed = 0;
        for (auto& t : tasks) {
            needed = max(needed, (long long)t[1] + spent);
            spent += t[0];
        }
        return (int)needed;
    }
};
