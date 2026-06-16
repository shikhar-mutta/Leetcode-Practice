// Link: https://leetcode.com/problems/remove-trailing-zeros-from-a-string/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n), SC: O(1)
    string removeTrailingZeros(string num)
    {
        int i = num.size() - 1;
        while (i >= 0 && num[i] == '0')
            i--;
        return num.substr(0, i + 1);
    }
};
