// Link: https://leetcode.com/problems/earliest-possible-day-of-full-bloom/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(n log n)  SC: O(n)
// Approach: greedily plant seeds with larger growTime first (since planting
// time is sequential but grow time overlaps with other plants' planting).
// Track running planting time, bloom = plantEnd + growTime, answer = max.
class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        int n = plantTime.size();
        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](int a, int b) { return growTime[a] > growTime[b]; });
        long long cur = 0, ans = 0;
        for (int i : idx) {
            cur += plantTime[i];
            ans = max(ans, cur + growTime[i]);
        }
        return (int)ans;
    }
};
