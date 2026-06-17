// Link: https://leetcode.com/problems/utf-8-validation/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool validUtf8(vector<int> &data)
    {
        int n = data.size();
        int i = 0;
        while (i < n)
        {
            int byte = data[i] & 0xFF; // only low 8 bits matter
            int cnt;                   // number of bytes in this char
            if ((byte & 0x80) == 0x00)
                cnt = 1; // 0xxxxxxx
            else if ((byte & 0xE0) == 0xC0)
                cnt = 2; // 110xxxxx
            else if ((byte & 0xF0) == 0xE0)
                cnt = 3; // 1110xxxx
            else if ((byte & 0xF8) == 0xF0)
                cnt = 4; // 11110xxx
            else
                return false; // 10xxxxxx or 11111xxx

            if (i + cnt > n)
                return false; // not enough bytes
            for (int k = 1; k < cnt; k++)
                if ((data[i + k] & 0xC0) != 0x80) // must be 10xxxxxx
                    return false;

            i += cnt;
        }
        return true;
    }
};
