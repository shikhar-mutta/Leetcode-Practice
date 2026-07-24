// Link: https://leetcode.com/problems/html-entity-parser/description/

#include <bits/stdc++.h>
using namespace std;

//TC: O(n) where n is the length of the string.
//SC: O(1) as we are using constant space for the encoded array.
//Approach:
//  1. We will use a two pointer approach to iterate through the string.
//  2. We will maintain a start pointer to keep track of the start of the encoded string and a pointer to keep track of the current position in the string.
//  3. When we encounter a '&' character, we will update the start pointer to the current position.
//  4. When we encounter a ';' character, we will check if the substring between the start and current position is a valid encoded string. If it is, we will replace it with the corresponding decoded character. If it is not, we will keep the substring as it is.
class Solution
{
public:
    string entityParser(string text)
    {
        vector<pair<string, char>> encoded[8] = {
            {},
            {},
            {},
            {},
            {{"&gt;", '>'}, {"&lt;", '<'}},
            {{"&amp;", '&'}},
            {{"&quot;", '"'}, {"&apos;", '\''}},
            {{"&frasl;", '/'}}};
        int st = 0, p = 0;
        for (size_t i = 0; i < text.size(); ++i, ++p)
        {
            text[p] = text[i];
            if (text[p] == '&')
                st = p;

            if (text[p] == ';')
            {
                size_t sz = p - st + 1;
                if (sz >= 4 && sz <= 7)
                {
                    for (auto &[enc, dec] : encoded[sz])
                    {
                        if (text.compare(st, sz, enc) == 0)
                        {
                            p = st;
                            text[p] = dec;
                            break;
                        }
                    }
                }

                st = p + 1;
            }
        }
        text.resize(p);
        return text;
    }
};
