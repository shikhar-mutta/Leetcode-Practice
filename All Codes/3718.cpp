// Link: https://leetcode.com/problems/smallest-missing-multiple-of-k/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n), SC: O(n)
    int missingMultiple(vector<int> &nums, int k)
    {
        unordered_set<int> s(nums.begin(), nums.end());
        int multiple = k;
        while (s.count(multiple))
            multiple += k;
        return multiple;
    }
};
