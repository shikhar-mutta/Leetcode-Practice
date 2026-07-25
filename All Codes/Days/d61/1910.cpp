// Link: https://leetcode.com/problems/remove-all-occurrences-of-a-substring/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n * m) where n is the length of the string s and m is the length of the string part
// SC: O(n) where n is the length of the string s
// Approach: Stack
//   1. Create a stack to store the characters of the string s.
//   2. Iterate through the string s and push each character onto the stack.
//   3. After pushing a character onto the stack, check if the top m characters of the stack form the string part. If they do, pop the top m characters from the stack
//   4. After iterating through the string s, the stack will contain the characters of the string s with all occurrences of the string part removed. Return the string formed by the characters in the stack.
class Solution
{
public:
    string removeOccurrences(string s, string part)
    {
        string stk;
        int m = part.size();
        for (char c : s)
        {
            stk.push_back(c);
            if (stk.size() >= m && stk.compare(stk.size() - m, m, part) == 0)
            {
                stk.erase(stk.size() - m);
            }
        }
        return stk;
    }
};