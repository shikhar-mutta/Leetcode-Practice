// Link: https://leetcode.com/problems/construct-smallest-number-from-di-string/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n), where n is the length of the input string pattern, as we iterate through each character of the string once.
// SC: O(n), where n is the length of the input string pattern, as we are using a stack to store the numbers that we need to construct the smallest number from the given pattern
//   Approach:
//     1. We initialize an empty string res to store the resulting smallest number and a stack stk to keep track of the numbers we need to construct the smallest number from the given pattern.
//     2. We iterate through each character in the input string pattern using a for loop. For each character, we push the current index + 1 onto the stack. This is because we want to construct the smallest number using the digits from 1 to n + 1, where n is the length of the input string pattern.
//     3. If the current character is 'I' or we have reached the end of the string, we pop all the elements from the stack and append them to the result string res. This is because we want to construct the smallest number by placing the numbers in increasing order when we encounter an 'I' or reach the end of the string.
//     4. Finally, we return the resulting string res, which represents the smallest number that can be constructed from the given pattern of 'I's and 'D's.
class Solution
{
public:
    string smallestNumber(string pattern)
    {
        string res;
        stack<int> stk;
        int n = pattern.size();

        for (int i = 0; i <= n; ++i)
        {
            stk.push(i + 1);
            if (i == n || pattern[i] == 'I')
            {
                while (!stk.empty())
                {
                    res += ('0' + stk.top());
                    stk.pop();
                }
            }
        }
        return res;
    }
};