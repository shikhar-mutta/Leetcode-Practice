// Link: https://leetcode.com/problems/next-greater-element-i/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> v;
        for (int x : nums1)
        { // fixed typo (nums1 instead of num1)
            int nextGrt = -1;
            bool found = false;
            for (int y : nums2)
            {
                if (x == y)
                    found = true;
                if (found && y > x)
                {
                    nextGrt = y; // store actual greater element
                    break;
                }
            }
            v.push_back(nextGrt); // push result (-1 if not found)
        }
        return v;
    }
};