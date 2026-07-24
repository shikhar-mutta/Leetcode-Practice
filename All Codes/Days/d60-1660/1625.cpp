// Link: https://leetcode.com/problems/lexicographically-smallest-string-after-applying-operations/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n * gcd(b, n)) where n is the length of the input string.
    // SC: O(n) for storing the result and the doubled string.
    // Approach:
    //        1. Use a greedy approach to find the lexicographically smallest string.
    //        2. Double the input string to handle rotation operations easily.
    //        3. Iterate through all possible rotations and apply the allowed operations to minimize each rotation.
    //        4. Return the lexicographically smallest string found.
    string findLexSmallestString(string s, int a, int b)
    {
        int n = s.size();
        string res = s;
        s = s + s;
        int g = gcd(b, n);

        auto add = [&](string &t, int start)
        {
            int minVal = 10, times = 0;
            for (int i = 0; i < 10; i++)
            {
                int added = ((t[start] - '0') + i * a) % 10;
                if (added < minVal)
                {
                    minVal = added;
                    times = i;
                }
            }
            for (int i = start; i < n; i += 2)
            {
                t[i] = '0' + ((t[i] - '0') + times * a) % 10;
            }
        };

        for (int i = 0; i < n; i += g)
        {
            string t = s.substr(i, n);
            add(t, 1);
            if (b % 2)
            {
                add(t, 0);
            }
            res = min(res, t);
        }
        return res;
    }
};
