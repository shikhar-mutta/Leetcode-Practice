// Link: https://leetcode.com/problems/check-if-numbers-are-ascending-in-a-sentence/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n), where n is the length of the string. SC: O(1)
    bool areNumbersAscending(string s)
    {
        stringstream ss(s);
        string tok;
        int prev = -1; // last number seen (all numbers are positive)
        while (ss >> tok)
        {
            if (isdigit((unsigned char)tok[0]))
            {
                int num = stoi(tok);
                if (num <= prev)
                    return false; // must be strictly increasing
                prev = num;
            }
        }
        return true;
    }
};
