// Link: https://leetcode.com/problems/the-latest-time-to-catch-a-bus/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int latestTimeCatchTheBus(vector<int>& buses, vector<int>& passengers, int capacity) {
        sort(buses.begin(), buses.end());
        sort(passengers.begin(), passengers.end());
        int n = passengers.size();
        int j = 0;
        int cnt = 0;
        for (int b : buses) {
            cnt = 0;
            while (j < n && passengers[j] <= b && cnt < capacity) { cnt++; j++; }
        }
        int ans = (cnt < capacity) ? buses.back() : passengers[j - 1] - 1;
        unordered_set<int> passSet(passengers.begin(), passengers.end());
        while (ans > 0 && passSet.count(ans)) ans--;
        return ans;
    }
};
