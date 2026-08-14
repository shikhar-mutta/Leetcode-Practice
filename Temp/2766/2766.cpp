// Link: https://leetcode.com/problems/relocate-marbles/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> relocateMarbles(vector<int>& nums, vector<int>& moveFrom, vector<int>& moveTo) {
        set<int> positions(nums.begin(), nums.end());
        for (int i = 0; i < (int)moveFrom.size(); i++) {
            positions.erase(moveFrom[i]);
            positions.insert(moveTo[i]);
        }
        return vector<int>(positions.begin(), positions.end());
    }
};
