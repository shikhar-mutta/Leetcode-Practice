// Link: https://leetcode.com/problems/minimum-operations-to-make-binary-palindrome/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    static vector<int> v;
    static bool done;
    bool isPalindromeBinary(int n)
    {
        string s = "";
        while (n > 0)
        {
            s += (n % 2) + '0';
            n /= 2;
        }
        int l = 0, r = s.size() - 1;
        while (l < r)
        {
            if (s[l] != s[r])
                return false;
            l++, r--;
        }
        return true;
    }
    vector<int> minOperations(vector<int> &nums)
    {
        int i, len = nums.size();
        if (!done)
        {
            done = true;
            for (i = 0; i < 5001; i++)
                if (isPalindromeBinary(i))
                    v.push_back(i);
        }

        vector<int> ans;
        for (i = 0; i < len; i++)
        {
            int idx = lower_bound(v.begin(), v.end(), nums[i]) - v.begin();
            int best = INT_MAX;
            if (idx < (int)v.size())
                best = min(best, abs(v[idx] - nums[i]));
            if (idx > 0)
                best = min(best, abs(v[idx - 1] - nums[i]));
            ans.push_back(best);
        }
        return ans;
    }
};
// Initialize static members(Out of class definition)
vector<int> Solution::v;
bool Solution::done = false;
