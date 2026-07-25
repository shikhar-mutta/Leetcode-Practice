// Link: https://leetcode.com/problems/maximize-the-confusion-of-an-exam/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n), SC: O(1)
//   Approach:
//   1. We can use a sliding window approach to find the maximum length of the substring that can be obtained by changing at most k characters.
//   2. We can keep track of the number of 'T's and 'F's in the current window.
//   3. We can calculate the minimum of the number of 'T's and 'F's in the current window
//   4. If the minimum is greater than k, we can move the left pointer to the right until the minimum is less than or equal to k.
//   5. We can update the answer with the maximum length of the current window.
//   6. We can return the answer after iterating through the entire string.
class Solution
{
public:
    int maxConsecutiveAnswers(string answerKey, int k)
    {
        int left = 0;
        int ans = INT_MIN;
        int t = 0;
        int f = 0;

        for (int right = 0; right < answerKey.size(); right++)
        {
            if (answerKey[right] == 'T')
            {
                t++;
            }
            else
            {
                f++;
            }
            int mn = min(t, f);
            while (k < mn)
            {
                if (answerKey[left] == 'T')
                {
                    t--;
                }
                else
                {
                    f--;
                }
                mn = min(t, f);
                left++;
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};