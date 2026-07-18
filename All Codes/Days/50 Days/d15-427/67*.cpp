// Link: https://leetcode.com/problems/add-binary/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(max(m, n)), SC: O(max(m, n))
    string addBinary(string a, string b)
    {
        string res;
        int i = a.size() - 1, j = b.size() - 1, carry = 0;
        while (i >= 0 || j >= 0 || carry)
        {
            int sum = carry;
            if (i >= 0)
                sum += a[i--] - '0';
            if (j >= 0)
                sum += b[j--] - '0';
            res += (sum % 2) + '0';
            carry = sum / 2;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
