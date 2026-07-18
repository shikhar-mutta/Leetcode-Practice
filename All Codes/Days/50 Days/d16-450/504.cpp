// Link: https://leetcode.com/problems/base-7/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(log7(n)), SC: O(log7(n))
    string convertToBase7(int num)
    {
        string ans = "";
        if (num == 0)
            return "0";
        bool isNegative = num < 0;
        num = abs(num);
        while (num > 0)
        {
            int rem = num % 7;
            ans += to_string(rem);
            num /= 7;
        }
        if (isNegative)
            ans += "-";
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
