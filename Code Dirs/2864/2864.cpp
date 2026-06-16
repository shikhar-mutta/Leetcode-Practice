// Link: https://leetcode.com/problems/maximum-odd-binary-number/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n), SC: O(n)
    string maximumOddBinaryNumber(string s)
    {
        // odd => last bit is 1; maximize by putting all other 1s at the front
        int ones = count(s.begin(), s.end(), '1');
        int zeros = s.size() - ones;
        return string(ones - 1, '1') + string(zeros, '0') + '1';
    }
};
