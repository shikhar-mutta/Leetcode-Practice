// Link: https://leetcode.com/problems/goal-parser-interpretation/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n), SC: O(n)
    string interpret(string command)
    {
        string res;
        for (int i = 0; i < (int)command.size();)
        {
            if (command[i] == 'G')
            {
                res += 'G';
                i++;
            }
            else if (command[i + 1] == ')')
            {
                res += 'o';
                i += 2;
            } // "()"
            else
            {
                res += "al";
                i += 4;
            } // "(al)"
        }
        return res;
    }
};
