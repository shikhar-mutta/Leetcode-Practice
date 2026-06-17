// Link: https://leetcode.com/problems/calculate-digit-sum-of-a-string/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n) where n is the length of s; SC: O(n)
    string digitSum(string s, int k)
    {
        // repeat until the string fits in one group
        while ((int)s.size() > k)
        {
            string next;
            for (int i = 0; i < (int)s.size(); i += k)
            {
                int sum = 0; // sum of this group's digits
                for (int j = i; j < min(i + k, (int)s.size()); j++)
                    sum += s[j] - '0';
                next += to_string(sum);
            }
            s = next;
        }
        return s;
    }
};
