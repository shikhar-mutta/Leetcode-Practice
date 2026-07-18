// Link: https://leetcode.com/problems/find-numbers-with-even-number-of-digits/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findNumbers(vector<int> &nums)
    {
        int cnt = 0;
        for (auto it : nums)
        {
            string s = to_string(it);
            if (s.length() % 2 == 0)
                cnt++;
        }
        return cnt;
    }
};
