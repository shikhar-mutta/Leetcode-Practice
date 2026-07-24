// Link: https://leetcode.com/problems/maximum-binary-string-after-change/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n) where n is the length of the input binary string.
    // SC: O(n) for storing the result of the maximum binary string.
    // Approach:
    //    1. Find the index of the first '0' in the binary string.
    //    2. Count the number of '1's after the first '0'.
    //    3. Create a result string filled with '1's.
    //    4. Set the position of the last '0' in the result string to be the index of the first '0' plus the count of '1's after it.
    //    5. Return the result string.
    string maximumBinaryString(string binary)
    {
        int idx = 0;
        while (idx < binary.size() && binary[idx] != '0')
            ++idx;

        string res(binary.size(), '1');
        if (idx == binary.size())
            return res;

        int cnt1 = 0;
        while (idx < binary.size())
            cnt1 += (binary[idx++] == '1');

        res[res.size() - 1 - cnt1] = '0';
        return res;
    }
};