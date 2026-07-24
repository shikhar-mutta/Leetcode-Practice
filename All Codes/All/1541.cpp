// Link: https://leetcode.com/problems/minimum-insertions-to-balance-a-parentheses-string/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) SC: O(1)
//   Approach:
//     1. We will keep track of the number of open parentheses and the number of insertions required to balance the string.
//     2. We will iterate through the string and for each character, we will check if it is an open or close parenthesis.
//     3. If it is an open parenthesis, we will increment the open count.
//     4. If it is a close parenthesis, we will check if the next character is also a close parenthesis. If it is, we will skip the next character and decrement the open count. If it is not, we will increment the insertion count and decrement the open count. If the open count is zero, we will increment the insertion count.
//     5. Finally, we will add the number of open parentheses multiplied by 2 to the insertion count and return the result.
class Solution
{
public:
    int minInsertions(string s)
    {
        int open = 0, ans = 0, n = s.length();
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '(')
                open++;
            else
            {
                if (i + 1 < n && s[i + 1] == ')')
                    i++;
                else
                    ans++;

                if (open > 0)
                    open--;
                else
                    ans++;
            }
        }

        ans += open * 2;
        return ans;
    }
};