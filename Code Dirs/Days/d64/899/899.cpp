// Link: https://leetcode.com/problems/orderly-queue/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(nlogn)  SC: O(n)
//  Approach: if k==1, we can only rotate the string, so we try all rotations and return the smallest one. If k>1, we can sort the string and return it.
class Solution
{
public:
    string brute_force(string s, int k)
    {
        int n = s.size();
        string res = s;
        for (int i = 0; i < n; i++)
        {
            char ch = s[0];
            s.erase(s.begin());
            s.push_back(ch);
            if (s < res)
            {
                res = s;
            }
        }
        return res;
    }
    string orderlyQueue(string s, int k)
    {
        if (k == 1)
        {
            return brute_force(s, k);
        }
        sort(s.begin(), s.end());
        return s;
    }
};