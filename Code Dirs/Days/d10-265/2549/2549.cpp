// Link: https://leetcode.com/problems/count-distinct-numbers-on-board/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(1), SC: O(1)
    int distinctIntegers(int n)
    {
        if (n == 1)
        {
            return 1;
        }
        return n - 1;
    }
};
