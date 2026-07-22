// Link: https://leetcode.com/problems/decode-string/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n) where n is the length of the input string
    // SC: O(n) where n is the length of the input string, as we are using stacks to store the counts and strings
    // Approach:
    //   1. We will use two stacks, one to store the counts and another to store the strings.
    //   2. We will iterate through the input string character by character. If we encounter a digit, we will build the number. If we encounter a '[', we will push the current number and string onto their respective stacks and reset them. If we encounter a ']', we will pop the count and string from the stacks, repeat the current string the specified number of times, and append it to the previous string. If we encounter a letter, we will append it to the current string.
    //   3. Finally, we will return the current string which will contain the fully decoded string.
    string decodeString(string s)
    {
        int n = s.size();
        stack<int> countStack;
        stack<string> stringStack;

        int num = 0;
        string curr = "";
        for (char c : s)
        {
            if (isdigit(c))
                num = num * 10 + (c - '0');
            else if (c == '[')
            {
                countStack.push(num);
                stringStack.push(curr);
                num = 0;
                curr = "";
            }
            else if (c == ']')
            {
                int repeat = countStack.top();
                countStack.pop();
                string prev = stringStack.top();
                stringStack.pop();

                while (repeat--)
                {
                    prev += curr;
                }
                curr = prev;
            }
            else
                curr += c;
        }
        return curr;
    }
};