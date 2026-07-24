// Link: https://leetcode.com/problems/maximum-69-number/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n)
    // SC: O(n)
    // Approach:
    //   1. Convert the input number to a string representation.
    //   2. Iterate through the characters of the string.
    //   3. If a '6' is encountered, change it to '9' and break the loop to ensure only the first '6' is changed.
    //  4. Convert the modified string back to an integer and return it as the result.
    int maximum69Number(int num)
    {
        string s = to_string(num);
        for (char &c : s)
        {
            if (c == '6')
            {
                c = '9';
                break;
            }
        }
        return stoi(s);
    }
};