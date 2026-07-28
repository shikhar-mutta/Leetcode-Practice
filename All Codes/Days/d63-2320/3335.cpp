// Link: https://leetcode.com/problems/total-characters-in-string-after-transformations-i/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) SC: O(1)
// Approach:
// 1. Count the frequency of each character in the string and store it in an array of size 26 (for each letter of the alphabet).
// 2. For each transformation, update the frequency of each character based on the transformation rules.
// 3. After all transformations, sum the frequencies of all characters to get the total number of characters in the string.
class Solution
{
public:
    int lengthAfterTransformations(string s, int t)
    {

        vector<long long> c(26, 0);
        long long mod = 1e9 + 7;

        for (auto &i : s)
            c[i - 'a'] += 1;
        // for(auto i:c)cout<<i<<" ";
        // cout<<endl;

        int cur = 0;
        while (t--)
        {

            cur = (cur + 25) % 26;

            c[(cur + 1) % 26] = (c[(cur + 1) % 26ll] + c[(cur)]) % mod;

            // for(int i=cur;i<(cur+26);i++)
            // cout<<c[i%26]<<" ";
            // cout<<endl;
        }

        // for(auto i:c)cout<<i<<" ";

        long long ans = 0;

        for (auto &i : c)
            ans = (ans + i) % mod;
        return ans;
    }
};