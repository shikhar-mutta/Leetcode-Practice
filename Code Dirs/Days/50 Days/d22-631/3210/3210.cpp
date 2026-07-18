// Link: https://leetcode.com/problems/find-the-encrypted-string/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n), SC: O(n)
    string getEncryptedString(string s, int k)
    {
        int n = s.size();
        k %= n; // rotation wraps around
        string r = s;
        // each position takes the char k steps ahead (cyclically)
        for (int i = 0; i < n; i++)
            r[i] = s[(i + k) % n];
        return r;
    }
};
