// Link: https://leetcode.com/problems/positions-of-large-groups/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) SC: O(1) extra
// Approach: scan runs of identical characters; record [start,end] for runs of length >= 3.
class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
        vector<vector<int>> res;
        int n = s.size();
        int i = 0;
        while (i < n) {
            int j = i;
            while (j < n && s[j] == s[i]) j++;
            if (j - i >= 3) res.push_back({i, j-1});
            i = j;
        }
        return res;
    }
};
