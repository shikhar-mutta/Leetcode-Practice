// Link: https://leetcode.com/problems/count-asterisks/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n), SC: O(1)
    int countAsterisks(string s)
    {
        int bars = 0, count = 0;
        for (char c : s)
        {
            if (c == '|')
                bars++; // toggle in/out of a |...| pair
            else if (c == '*' && bars % 2 == 0)
                count++; // only count when outside a pair
        }
        return count;
    }
};
