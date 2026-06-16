// Link: https://leetcode.com/problems/reverse-degree-of-a-string/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n), SC: O(1)
    int reverseDegree(string s)
    {
        // reverse value: 'a'->26, 'b'->25, ... 'z'->1; weight by 1-based position
        int sum = 0;
        for (int i = 0; i < (int)s.size(); ++i)
            sum += (26 - (s[i] - 'a')) * (i + 1);
        return sum;
    }
};
