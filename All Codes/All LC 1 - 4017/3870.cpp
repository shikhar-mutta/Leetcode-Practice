// Link: https://leetcode.com/problems/count-commas-in-range/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(1) SC: O(1)
//  Approach: only numbers from 1000 to n have commas. So the count is max(0, n - 999).
class Solution
{
public:
    int countCommas(int n)
    {
        return max(0, n - 999);
    }
};