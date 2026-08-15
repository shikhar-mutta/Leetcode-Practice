// Link: https://leetcode.com/problems/partition-array-according-to-given-pivot/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> less, equal, greater;
        for (int x : nums) {
            if (x < pivot) less.push_back(x);
            else if (x == pivot) equal.push_back(x);
            else greater.push_back(x);
        }
        vector<int> res;
        res.insert(res.end(), less.begin(), less.end());
        res.insert(res.end(), equal.begin(), equal.end());
        res.insert(res.end(), greater.begin(), greater.end());
        return res;
    }
};
