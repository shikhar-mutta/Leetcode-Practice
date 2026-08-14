// Link: https://leetcode.com/problems/find-occurrences-of-an-element-in-an-array/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
        vector<int> pos;
        for (int i = 0; i < (int)nums.size(); i++) if (nums[i] == x) pos.push_back(i);
        vector<int> res;
        for (int q : queries) {
            if (q > (int)pos.size()) res.push_back(-1);
            else res.push_back(pos[q-1]);
        }
        return res;
    }
};
