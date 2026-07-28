// Link: https://leetcode.com/problems/lexicographically-smallest-string-after-reverse/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n^2) SC: O(n)
//  Approach: n is small, so just try every k for reversing the prefix and
//  every k for reversing the suffix, tracking the lexicographically
//  smallest result.
class Solution
{
public:
    string lexSmallest(string s)
    {
        int n = size(s);
        auto ch_min = *min_element(begin(s), end(s));
        queue<int> q;
        for (int i = n - 1; i >= 0; --i)
            if (s[i] == ch_min)
                q.emplace(i);
        int len = 1;
        while (size(q) > 1)
        {
            char ch_next = CHAR_MAX;
            int sz = size(q), prev = -1;
            while (sz--)
            {
                int i = q.front(), j = i - len < 0 ? len : i - len;
                q.pop();
                ch_next = min(ch_next, s[j]);
                if (i != prev)
                    q.emplace(i);
                prev = j;
            }
            sz = size(q);
            while (sz--)
            {
                int i = q.front(), j = i - len < 0 ? len : i - len;
                q.pop();
                if (s[j] == ch_next)
                    q.emplace(i);
            }
            ++len;
        }
        int i = q.front();
        q.pop();
        string f_s = s, b_s = s;
        reverse(begin(f_s), begin(f_s) + i + 1);
        len = 1;
        vector<int> t(n);
        t[n - 1] = n;
        for (int pos = n - 2, cnd = n - 1; pos >= 0; --pos, --cnd)
        {
            if (s[pos] == s[cnd])
                t[pos] = t[cnd];
            else
            {
                t[pos] = cnd;
                while (cnd != n && s[pos] != s[cnd])
                    cnd = t[cnd];
            }
        }
        for (int i = 0, j = n - 1; i < n; ++i, --j)
        {
            while (j != n && s[i] < s[j])
                j = t[j];
            if (j != n && s[i] > s[j])
            {
                reverse(begin(b_s) + i, begin(b_s) + j + 1);
                break;
            }
        }
        for (int i = 0; i < n; ++i)
        {
            if (s[i] > s[n - 1])
            {
                reverse(begin(s) + i, end(s));
                break;
            }
        }
        return min({s, f_s, b_s});
    }
};