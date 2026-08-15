// Link: https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n) where n is the length of the string s
    // SC: O(1) since we are using a fixed size array of 26
    // Approach:
    //   1. We will use a stack to keep track of the characters in the smallest subsequence.
    //   2. We will use a vector to keep track of the last index of each character in the string.
    //   3. We will iterate through the string and for each character, we will check if it is already in the stack. If it is not, we will check if the top character of the stack is greater than the current character and if the last index of the top character is greater than the current index. If both conditions are true, we will pop the top character from the stack and mark it as not in the stack. We will then push the current character to the stack and mark it as in the stack.
    //   4. Finally, we will return the stack as a string.
    string smallestSubsequence(string s)
    {
        vector<int> lastIdx(26, 0);
        for (int i = 0; i < (int)s.size(); i++)
            lastIdx[s[i] - 'a'] = i;

        string stack;
        vector<bool> inStack(26, false);
        for (int i = 0; i < (int)s.size(); i++)
        {
            int c = s[i] - 'a';
            if (inStack[c])
                continue;
            while (!stack.empty() && stack.back() > s[i] && lastIdx[stack.back() - 'a'] > i)
            {
                inStack[stack.back() - 'a'] = false;
                stack.pop_back();
            }
            stack += s[i];
            inStack[c] = true;
        }
        return stack;
    }
};
