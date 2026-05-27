// Link: https://leetcode.com/problems/contains-duplicate/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        // Use an unordered_set to track seen numbers
        unordered_set<int> seen;
        for (int n : nums)
        {
            // early exit if we encounter a duplicate
            if (!seen.insert(n).second)
                return true;
        }
        return false;
    }
};