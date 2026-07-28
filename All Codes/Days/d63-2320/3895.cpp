// Link: https://leetcode.com/problems/count-digit-appearances/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(sum of digit counts) SC: O(1)
// Approach: convert each number to a string and count occurrences of
// the target digit character.
class Solution
{
public:
    int countDigitOccurrences(vector<int> &nums, int digit)
    {
        int ans = 0;
        for (int n : nums)
        {
            while (n > 0)
            {
                int k = n % 10;
                if (k == digit)
                    ans++;
                n = n / 10;
            }
        }
        return ans;
    }
};