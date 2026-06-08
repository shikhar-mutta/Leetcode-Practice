// Link: https://leetcode.com/problems/concatenate-array-with-reverse/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n), SC: O(n)
    vector<int> concatWithReverse(vector<int> &nums)
    {
        vector<int> result(nums);
        result.insert(result.end(), nums.rbegin(), nums.rend());
        return result;
    }
};
