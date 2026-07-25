// Link: https://leetcode.com/problems/count-number-of-texts/description/

#include <bits/stdc++.h>
using namespace std;

const int MX = 100'001;
const int MOD = 1'000'000'007;
long long k3[MX], k4[MX];

auto init = []
{
    k3[0] = 1, k3[1] = 1, k3[2] = 2, k3[3] = 4;
    k4[0] = 1, k4[1] = 1, k4[2] = 2, k4[3] = 4;
    for (int i = 4; i < MX; i++)
    {
        k3[i] = (k3[i - 1] + k3[i - 2] + k3[i - 3]) % MOD;
        k4[i] = (k4[i - 1] + k4[i - 2] + k4[i - 3] + k4[i - 4]) % MOD;
    }
    return 0;
}();

// TC: O(n), SC: O(1)
//  Approach:
//  1. We can use dynamic programming to find the number of ways to decode the pressed keys.
//  2. We can precompute the number of ways to decode sequences of length up to 100,000 for keys that can be pressed 3 times (2, 3, 4, 5, 6, 8) and keys that can be pressed 4 times (7, 9).
//  3. We can then iterate through the pressed keys and for each sequence of identical keys, we can multiply the number of ways to decode that sequence by the precomputed value for that length and key type.
//  4. Finally, we return the total number of ways to decode the entire pressed keys string modulo 1,000,000,007.
class Solution
{
public:
    int countTexts(string pressedKeys)
    {
        int n = pressedKeys.size();
        string &p = pressedKeys;
        p.push_back('0');
        long long ans = 1;
        int cnt = 1;
        char cur = p[0];
        for (int i = 0; i < n; i++)
        {
            char nxt = p[i + 1];
            if (nxt != cur)
            {
                int c = (cur == '7' || cur == '9') ? k4[cnt] : k3[cnt];
                ans = (ans * c) % MOD;
                cnt = 1;
            }
            else
            {
                cnt++;
            }
            cur = nxt;
        }
        return ans;
    }
};