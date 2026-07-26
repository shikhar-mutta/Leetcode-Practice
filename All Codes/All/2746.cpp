// Link: https://leetcode.com/problems/decremental-string-concatenation/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n * 26)
// SC: O(26*26) for the DP table
// Approach: joining consecutive words merges their shared boundary letter
// (last[i]==first[i+1]) into one character, saving 1 length each time. Total
// length = sum of all word lengths minus the max total savings achievable by
// choosing, at each merge, whether to keep the accumulated block's current
// left/right end or swap in the new word's opposite end (since either
// boundary of the still-open block could be exposed for the NEXT merge).
// cancel[cl][cr] = max total savings so far when the merged block currently
// has left-end char cl and right-end char cr; rolls between two buffers
// (cur/prev) indexed by parity of i to avoid re-allocating each step.
class Solution {
private:
    static int cancel[2][26][26];

public:
    int minimizeConcatenatedLength(vector<string>& words) {
        int n = words.size();
        int len = words[0].size();
        int lwl = words[0].front() - 'a';
        int lwr = words[0].back() - 'a';
        memset(cancel, 0xff, sizeof(cancel));
        cancel[0][lwl][lwr] = 0;
        for (int i = 1; i < n; ++i) {
            len += words[i].size();
            int cur = i & 1;
            int prev = cur ^ 1;
            memset(cancel[cur], 0xff, sizeof(cancel[cur]));
            int wl = words[i].front() - 'a';
            int wr = words[i].back() - 'a';
            int backCancel = (lwr == wl);
            int frontCancel = (lwl == wr);
            for (int cl = 0; cl < 26; ++cl) {
                if (cancel[prev][cl][lwr] < 0)
                    continue;
                cancel[cur][cl][wr] = max(cancel[cur][cl][wr],
                                          cancel[prev][cl][lwr] + backCancel);
                if (cl == wr)
                    cancel[cur][wl][lwr] =
                        max(cancel[cur][wl][lwr], cancel[prev][cl][lwr] + 1);
                else
                    cancel[cur][wl][lwr] =
                        max(cancel[cur][wl][lwr], cancel[prev][cl][lwr]);
            }
            for (int cr = 0; cr < 26; ++cr) {
                if (cancel[prev][lwl][cr] < 0)
                    continue;
                if (cr == wl)
                    cancel[cur][lwl][wr] =
                        max(cancel[cur][lwl][wr], cancel[prev][lwl][cr] + 1);
                else
                    cancel[cur][lwl][wr] =
                        max(cancel[cur][lwl][wr], cancel[prev][lwl][cr]);
                cancel[cur][wl][cr] = max(cancel[cur][wl][cr],
                                          cancel[prev][lwl][cr] + frontCancel);
            }
            lwl = wl;
            lwr = wr;
        }
        int last = (n - 1) & 1;
        int maxCancel = 0;
        for (int cl = 0; cl < 26; ++cl) {
            maxCancel = max(maxCancel, cancel[last][cl][lwr]);
        }
        for (int cr = 0; cr < 26; ++cr) {
            maxCancel = max(maxCancel, cancel[last][lwl][cr]);
        }
        return len - maxCancel;
    }
};

int Solution::cancel[2][26][26];
