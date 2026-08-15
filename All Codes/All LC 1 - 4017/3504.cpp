// Link: https://leetcode.com/problems/longest-palindrome-after-substring-concatenation-ii/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n + m), where n is the length of s and m is the length of t.
// SC: O(n + m), where n is the length of s and m is the length of t.
// Approach: We can use Suffix Automaton to find the longest palindromic substring that can be formed by concatenating a substring of s and a substring of t. We will build a Suffix Automaton for the reversed string t and then match the string s against it to find the longest prefix of s that matches a suffix of t. We will also build a Suffix Automaton for the string s and then match the reversed string t against it to find the longest prefix of t that matches a suffix of s. Finally, we will use Manacher's algorithm to find the longest palindromic substring in both s and t and combine the results to get the final answer.
class Solution
{
    struct State
    {
        int len, link;
        int next[26];
    };

    vector<State> st;
    int sz, last;

    void sam_init(int max_len)
    {
        st.assign(max_len * 2 + 5, State());
        st[0].len = 0;
        st[0].link = -1;
        memset(st[0].next, -1, sizeof(st[0].next));
        sz = 1;
        last = 0;
    }

    void sam_extend(char c)
    {
        int cur = sz++;
        st[cur].len = st[last].len + 1;
        memset(st[cur].next, -1, sizeof(st[cur].next));
        int p = last;
        while (p != -1 && st[p].next[c - 'a'] == -1)
        {
            st[p].next[c - 'a'] = cur;
            p = st[p].link;
        }
        if (p == -1)
        {
            st[cur].link = 0;
        }
        else
        {
            int q = st[p].next[c - 'a'];
            if (st[p].len + 1 == st[q].len)
            {
                st[cur].link = q;
            }
            else
            {
                int clone = sz++;
                st[clone].len = st[p].len + 1;
                memcpy(st[clone].next, st[q].next, sizeof(st[q].next));
                st[clone].link = st[q].link;
                while (p != -1 && st[p].next[c - 'a'] == q)
                {
                    st[p].next[c - 'a'] = clone;
                    p = st[p].link;
                }
                st[q].link = st[cur].link = clone;
            }
        }
        last = cur;
    }

    vector<int> get_match(const string &text)
    {
        vector<int> match_len(text.length(), 0);
        int v = 0, l = 0;
        for (int i = 0; i < text.length(); i++)
        {
            int c = text[i] - 'a';
            while (v != 0 && st[v].next[c] == -1)
            {
                v = st[v].link;
                l = st[v].len;
            }
            if (st[v].next[c] != -1)
            {
                v = st[v].next[c];
                l++;
            }
            match_len[i] = l;
        }
        return match_len;
    }

    vector<int> manacher(const string &S)
    {
        string T = "^#";
        for (char c : S)
        {
            T += c;
            T += "#";
        }
        T += "$";
        int n = T.length();
        vector<int> P(n, 0);
        int C = 0, R = 0;
        for (int i = 1; i < n - 1; i++)
        {
            int i_mirror = 2 * C - i;
            if (R > i)
            {
                P[i] = min(R - i, P[i_mirror]);
            }
            else
            {
                P[i] = 0;
            }
            while (T[i + 1 + P[i]] == T[i - 1 - P[i]])
            {
                P[i]++;
            }
            if (i + P[i] > R)
            {
                C = i;
                R = i + P[i];
            }
        }
        return P;
    }

public:
    int longestPalindrome(string s, string t)
    {
        if (s.empty() && t.empty())
            return 0;

        // 1. Build Suffix Automaton for reversed t
        string t_rev = t;
        reverse(t_rev.begin(), t_rev.end());
        sam_init(t.length());
        for (char c : t_rev)
            sam_extend(c);

        // Match lengths of s against reversed t
        vector<int> left_match = get_match(s);

        // 2. Build Suffix Automaton for s
        sam_init(s.length());
        for (char c : s)
            sam_extend(c);

        // Match lengths of reversed t against s
        vector<int> match_len_tR = get_match(t_rev);

        int ans = 0;

        // 3. Maximize combinations centered in s
        vector<int> P_s = manacher(s);
        for (int i = 1; i < P_s.size() - 1; i++)
        {
            int len = P_s[i];
            int l = (i - len - 1) / 2;

            int avail = (l > 0) ? left_match[l - 1] : 0;
            ans = max(ans, len + 2 * avail);
        }

        // 4. Maximize combinations centered in t
        vector<int> P_t = manacher(t);
        int m = t.length();
        for (int i = 1; i < P_t.size() - 1; i++)
        {
            int len = P_t[i];
            int r = (i + len - 2) / 2;

            int avail = 0;
            if (r < m - 1)
            {
                int rev_idx = m - 2 - r;
                avail = match_len_tR[rev_idx];
            }
            ans = max(ans, len + 2 * avail);
        }

        return ans;
    }
};
