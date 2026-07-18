// Link: https://leetcode.com/problems/path-crossing/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n), SC: O(n)
    bool isPathCrossing(string path)
    {
        int x = 0, y = 0;
        // encode (x,y) as single long long — no custom hash needed
        auto encode = [](int x, int y)
        { return (long long)x << 32 | (unsigned int)y; };
        unordered_set<long long> st;
        st.insert(encode(x, y));

        for (char c : path)
        {
            if (c == 'N')
                y++;
            else if (c == 'S')
                y--;
            else if (c == 'E')
                x++;
            else
                x--;

            long long key = encode(x, y);
            if (st.count(key))
                return true;
            st.insert(key);
        }
        return false;
    }
};
