// Link: https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numberOfSubstrings(string s)
    {
        int last[3] = {-1, -1, -1};
        long long count = 0;
        for (int i = 0; i < (int)s.size(); i++)
        {
            last[s[i] - 'a'] = i;
            // Every left endpoint in [0, min(last a,b,c)] forms a valid substring
            count += min({last[0], last[1], last[2]}) + 1;
        }
        return (int)count;
    }
};
