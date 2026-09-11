// Link: https://leetcode.com/problems/di-string-match/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> diStringMatch(string s)
    {
        int n = s.size();
        vector<int> result(n + 1);
        int low = 0, high = n;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'I')
            {
                result[i] = low++;
            }
            else
            {
                result[i] = high--;
            }
        }
        result[n] = low; // At the end, low and high will be equal
        return result;
    }
};
