// Link: https://leetcode.com/problems/password-strength/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) SC: O(1)
// Approach: track distinct characters seen, score each once by its
// category (lowercase 1, uppercase 2, digit 3, special "!@#$" 5).
class Solution
{
public:
    int passwordStrength(string password)
    {
        string loweralpha = "abcdefghijklmnopqrstuvwxyz";
        string upperalpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        string nums = "0123456789";
        string special = "!@#$";
        int ans = 0;

        for (int i = 0; i < loweralpha.length(); i++)
        {
            if (password.contains(loweralpha[i]))
            {
                ans++;
            }

            if (password.contains(upperalpha[i]))
            {
                ans += 2;
            }
        }

        for (int i = 0; i < nums.length(); i++)
        {
            if (password.contains(nums[i]))
            {
                ans += 3;
            }
        }

        for (int i = 0; i < special.length(); i++)
        {
            if (password.contains(special[i]))
            {
                ans += 5;
            }
        }

        return ans;
    }
};