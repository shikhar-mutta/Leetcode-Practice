// Link: https://leetcode.com/problems/longest-duplicate-substring/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)  SC: O(n)
// Approach: We can use a suffix automaton to find the longest duplicate substring. A suffix automaton is a compressed version of a suffix trie that allows us to efficiently find the longest substring that appears at least twice in the input string. The algorithm constructs the suffix automaton in linear time and then traverses it to find the longest substring with at least two occurrences.
class Solution
{
public:
    struct State
    {
        int len, link;
        int next[26];
        int occ;
        int firstPos;
        State()
        {
            len = 0;
            link = -1;
            occ = 0;
            firstPos = -1;
            memset(next, -1, sizeof(next));
        }
    };
    vector<State> st;
    int last, sz;
    void extend(char ch, int pos)
    {
        int c = ch - 'a';
        int cur = sz++;
        st[cur].len = st[last].len + 1;
        st[cur].occ = 1;
        st[cur].firstPos = pos;
        int p = last;
        while (p != -1 && st[p].next[c] == -1)
        {
            st[p].next[c] = cur;
            p = st[p].link;
        }
        if (p == -1)
        {
            st[cur].link = 0;
        }
        else
        {
            int q = st[p].next[c];

            if (st[p].len + 1 == st[q].len)
            {
                st[cur].link = q;
            }
            else
            {

                int clone = sz++;

                st[clone] = st[q];
                st[clone].len = st[p].len + 1;
                st[clone].occ = 0;

                while (p != -1 && st[p].next[c] == q)
                {
                    st[p].next[c] = clone;
                    p = st[p].link;
                }

                st[q].link = clone;
                st[cur].link = clone;
            }
        }

        last = cur;
    }

    string longestDupSubstring(string s)
    {

        int n = s.size();

        st.resize(2 * n + 5);

        sz = 1;
        last = 0;

        for (int i = 0; i < n; i++)
            extend(s[i], i);

        vector<int> cnt(n + 1);

        for (int i = 0; i < sz; i++)
            cnt[st[i].len]++;

        for (int i = 1; i <= n; i++)
            cnt[i] += cnt[i - 1];

        vector<int> order(sz);

        for (int i = sz - 1; i >= 0; i--)
            order[--cnt[st[i].len]] = i;

        for (int i = sz - 1; i > 0; i--)
        {
            int v = order[i];
            int p = st[v].link;

            if (p >= 0)
                st[p].occ += st[v].occ;
        }

        int best = -1;

        for (int v = 1; v < sz; v++)
        {
            if (st[v].occ >= 2)
            {
                if (best == -1 ||
                    st[v].len > st[best].len)
                    best = v;
            }
        }

        if (best == -1)
            return "";

        int L = st[best].len;
        int endPos = st[best].firstPos;

        return s.substr(endPos - L + 1, L);
    }
};