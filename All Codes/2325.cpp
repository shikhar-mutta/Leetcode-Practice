// Link: https://leetcode.com/problems/decode-the-message/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n), SC: O(1)
    string decodeMessage(string key, string message)
    {
        char map[26] = {0};
        char next = 'a';
        // first time a letter appears in key, assign it the next cipher letter
        for (char c : key)
            if (c != ' ' && !map[c - 'a'])
                map[c - 'a'] = next++;

        // translate the message; spaces pass through
        for (char &c : message)
            if (c != ' ')
                c = map[c - 'a'];
        return message;
    }
};
