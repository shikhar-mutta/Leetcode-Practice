// Link: https://leetcode.com/problems/reducing-dishes/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(n log n)  SC: O(1)
// Approach: sort descending, then greedily add dishes from the top. If
// adding a dish still keeps the running "total" (sum of all included
// dishes, since each addition also adds 1 to every previously included
// dish's multiplier) non-negative, keep it and accumulate into the
// answer; otherwise stop (a sorted-descending sequence means once
// adding stops helping, it never helps again).
class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.rbegin(), satisfaction.rend());
        int total = 0, ans = 0;
        for (int s : satisfaction) {
            total += s;
            if (total <= 0) break;
            ans += total;
        }
        return ans;
    }
};
