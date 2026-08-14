// Link: https://leetcode.com/problems/sort-even-and-odd-indices-independently/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
        vector<int> evens, odds;
        for (int i = 0; i < (int)nums.size(); i++) {
            if (i % 2 == 0) evens.push_back(nums[i]);
            else odds.push_back(nums[i]);
        }
        sort(evens.begin(), evens.end());
        sort(odds.begin(), odds.end(), greater<int>());
        vector<int> res(nums.size());
        for (int i = 0, e = 0, o = 0; i < (int)nums.size(); i++) {
            if (i % 2 == 0) res[i] = evens[e++];
            else res[i] = odds[o++];
        }
        return res;
    }
};
