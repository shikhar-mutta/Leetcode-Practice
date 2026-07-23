// Link: https://leetcode.com/problems/check-if-word-is-valid-after-substitutions/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n) where n is the length of the input string.
    // SC: O(n) where n is the length of the input string.
    // Approach:
    // 1. We will use a string as a stack to store the characters of the input string.
    // 2. We will iterate through the input string and for each character, we will check if it is 'c'. If it is, we will check if the last two characters in the stack are 'b' and 'a' respectively. If they are, we will pop them from the stack. If they are not, we will return false.
    // 3. If the character is not 'c', we will push it to the stack.
    // 4. Finally, we will check if the stack is empty. If it is, we will return true. If it is not, we will return false.
    bool isValid(string s)
    {
        string stack;
        for (char c : s)
        {
            if (c == 'c')
            {
                if (stack.size() < 2 || stack.back() != 'b')
                    return false;
                stack.pop_back();
                if (stack.back() != 'a')
                    return false;
                stack.pop_back();
            }
            else
            {
                stack += c;
            }
        }
        return stack.empty();
    }
};
