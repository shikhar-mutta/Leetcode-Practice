// Link: https://leetcode.com/problems/jewels-and-stones/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(J + S), SC: O(1)
    int numJewelsInStones(string jewels, string stones)
    {
        bitset<'z' - 'A' + 1> s;
        int ans = 0;

        for (char c : jewels)
            s.set(c - 'A');

        for (char c : stones)
            if (s.test(c - 'A'))
                ans++;

        return ans;
    }
};
