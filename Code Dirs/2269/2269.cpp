// Link: https://leetcode.com/problems/find-the-k-beauty-of-a-number/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC:O(n) SC:O(1)
    int divisorSubstrings(int num, int k)
    {
        string s = to_string(num);
        int cnt = 0;
        // slide a length-k window over the digits
        for (int i = 0; i + k <= (int)s.size(); i++)
        {
            int val = stoi(s.substr(i, k));
            if (val != 0 && num % val == 0)
                cnt++; // nonzero divisor of num
        }
        return cnt;
    }
};
