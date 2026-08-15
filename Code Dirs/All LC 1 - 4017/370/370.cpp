// Link: https://leetcode.com/problems/range-addition/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n + q)  SC: O(n)
// Approach: difference array - add inc at start, subtract at end+1, then
// prefix-sum to get final array
class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        vector<int> diff(length + 1, 0);
        for (auto& u : updates) {
            diff[u[0]] += u[2];
            diff[u[1] + 1] -= u[2];
        }
        vector<int> res(length);
        int running = 0;
        for (int i = 0; i < length; i++) {
            running += diff[i];
            res[i] = running;
        }
        return res;
    }
};
