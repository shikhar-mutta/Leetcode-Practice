// Link: https://leetcode.com/problems/last-visited-integers/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> lastVisitedIntegers(vector<int>& nums) {
        vector<int> seen, res;
        int k = 0;
        for (int x : nums) {
            if (x != -1) {
                seen.push_back(x);
                k = 0;
            } else {
                k++;
                if (k <= (int)seen.size()) res.push_back(seen[seen.size() - k]);
                else res.push_back(-1);
            }
        }
        return res;
    }
};
