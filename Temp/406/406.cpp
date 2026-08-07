// Link: https://leetcode.com/problems/queue-reconstruction-by-height/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n^2)  SC: O(n)
// Approach: sort by height desc, k asc; insert each person at index k
// (taller/equal people already placed aren't affected by later shorter ones)
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[0] != b[0]) return a[0] > b[0];
            return a[1] < b[1];
        });
        vector<vector<int>> res;
        for (auto& p : people) res.insert(res.begin() + p[1], p);
        return res;
    }
};
