// Link: https://leetcode.com/problems/minimum-initial-energy-to-finish-tasks/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        sort(tasks.begin(), tasks.end(), [](auto& a, auto& b) {
            return (a[1] - a[0]) > (b[1] - b[0]);
        });
        long long sum = 0, ans = 0;
        for (auto& t : tasks) {
            ans = max(ans, sum + t[1]);
            sum += t[0];
        }
        return (int)ans;
    }
};
