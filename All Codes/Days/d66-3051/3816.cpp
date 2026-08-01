// Link: https://leetcode.com/problems/lexicographically-smallest-string-after-deleting-duplicate-characters/description/

#include <bits/stdc++.h>
using namespace std;

//TC: O(n^2)  SC: O(n)
// Approach: if some character occurs more than once, exactly one occurrence
// of some duplicated character must be removed; try removing each position
// whose character has count>=2 and keep the lexicographically smallest
// resulting string. If no character repeats, the string is returned as-is. 
class Solution
{
public:
    static string lexSmallestAfterDeletion(string s)
    {
        unsigned int let_cnt_src[26]{};
        unsigned int let_cnt_res[26]{};

        char *s_mn = &s.front();
        char *s_mx = &s.back();
        char *s_lo = s_mn - 1u;
        char *s_hi = s_mn;

        for (; s_hi <= s_mx; ++s_hi)
        {
            *s_hi -= 'a';
            ++let_cnt_src[*s_hi];
        }
        s_hi = s_mn;

        for (; s_hi <= s_mx; ++s_hi)
        {
            --let_cnt_src[*s_hi];

            while (s_lo >= s_mn && *s_lo > *s_hi &&
                   (let_cnt_src[*s_lo] > 0 || let_cnt_res[*s_lo] > 1))
            {
                --let_cnt_res[*s_lo];
                --s_lo;
            }

            *(++s_lo) = *s_hi;
            ++let_cnt_res[*s_hi];
        }
        s_hi = s_mn;

        while (s_lo >= s_mn && let_cnt_res[*s_lo] > 1)
            --let_cnt_res[*(s_lo--)];

        s.resize(s_lo - s_mn + 1u);
        for (; s_hi <= s_mx; ++s_hi)
            *s_hi += 'a';
        return s;
    }
};
