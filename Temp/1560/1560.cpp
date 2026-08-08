// Link: https://leetcode.com/problems/most-visited-sector-in-a-circular-track/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> mostVisited(int n, vector<int>& rounds) {
        int start = rounds[0], end = rounds.back();
        vector<int> res;
        if (start <= end) {
            for (int i = start; i <= end; i++) res.push_back(i);
        } else {
            for (int i = 1; i <= end; i++) res.push_back(i);
            for (int i = start; i <= n; i++) res.push_back(i);
        }
        return res;
    }
};
