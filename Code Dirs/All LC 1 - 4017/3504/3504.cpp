// Link: https://leetcode.com/problems/longest-palindrome-after-substring-concatenation-ii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
    struct State {
        int len, link;
        int next[26];
    };

    vector<State> st;
    int sz, last;

    void sam_init(int max_len) {
        st.assign(max_len * 2 + 5, State());
        st[0].len = 0;
        st[0].link = -1;
        memset(st[0].next, -1, sizeof(st[0].next));
        sz = 1;
        last = 0;
    }

    void sam_extend(char c) {
        int cur = sz++;
        st[cur].len = st[last].len + 1;
        memset(st[cur].next, -1, sizeof(st[cur].next));
        int p = last;
        while (p != -1 && st[p].next[c - 'a'] == -1) {
            st[p].next[c - 'a'] = cur;
            p = st[p].link;
        }
        if (p == -1) {
            st[cur].link = 0;
        } else {
            int q = st[p].next[c - 'a'];
            if (st[p].len + 1 == st[q].len) {
                st[cur].link = q;
            } else {
                int clone = sz++;
                st[clone].len = st[p].len + 1;
                memcpy(st[clone].next, st[q].next, sizeof(st[q].next));
                st[clone].link = st[q].link;
                while (p != -1 && st[p].next[c - 'a'] == q) {
                    st[p].next[c - 'a'] = clone;
                    p = st[p].link;
                }
                st[q].link = st[cur].link = clone;
            }
        }
        last = cur;
    }

    vector<int> get_match(const string& text) {
        vector<int> match_len(text.length(), 0);
        int v = 0, l = 0;
        for (int i = 0; i < (int)text.length(); i++) {
            int c = text[i] - 'a';
            while (v != 0 && st[v].next[c] == -1) {
                v = st[v].link;
                l = st[v].len;
            }
            if (st[v].next[c] != -1) {
                v = st[v].next[c];
                l++;
            }
            match_len[i] = l;
        }
        return match_len;
    }

    vector<int> manacher(const string& S) {
        string T = "^#";
        for (char c : S) {
            T += c;
            T += "#";
        }
        T += "$";
        int n = T.length();
        vector<int> P(n, 0);
        int C = 0, R = 0;
        for (int i = 1; i < n - 1; i++) {
            int i_mirror = 2 * C - i;
            if (R > i) {
                P[i] = min(R - i, P[i_mirror]);
            } else {
                P[i] = 0;
            }
            while (T[i + 1 + P[i]] == T[i - 1 - P[i]]) {
                P[i]++;
            }
            if (i + P[i] > R) {
                C = i;
                R = i + P[i];
            }
        }
        return P;
    }

public:
    int longestPalindrome(string s, string t) {
        if (s.empty() && t.empty()) return 0;

        string t_rev = t;
        reverse(t_rev.begin(), t_rev.end());
        sam_init(t.length());
        for (char c : t_rev) sam_extend(c);

        vector<int> left_match = get_match(s);

        sam_init(s.length());
        for (char c : s) sam_extend(c);

        vector<int> match_len_tR = get_match(t_rev);

        int ans = 0;

        vector<int> P_s = manacher(s);
        for (int i = 1; i < (int)P_s.size() - 1; i++) {
            int len = P_s[i];
            int l = (i - len - 1) / 2;

            int avail = (l > 0) ? left_match[l - 1] : 0;
            ans = max(ans, len + 2 * avail);
        }

        vector<int> P_t = manacher(t);
        int m = t.length();
        for (int i = 1; i < (int)P_t.size() - 1; i++) {
            int len = P_t[i];
            int r = (i + len - 2) / 2;

            int avail = 0;
            if (r < m - 1) {
                int rev_idx = m - 2 - r;
                avail = match_len_tR[rev_idx];
            }
            ans = max(ans, len + 2 * avail);
        }

        return ans;
    }
};
