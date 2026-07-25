// Link: https://leetcode.com/problems/k-divisible-elements-subarrays/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n log n) amortized (Suffix Automaton construction is O(n) states/
//     transitions with an unordered_map per state; sliding window is O(n))
// SC: O(n) (SAM has at most 2n-1 states)
// Approach: distinct subarrays satisfying the <=k divisible-by-p count are
// counted via a Suffix Automaton (SAM) built over nums - each SAM state
// represents an equivalence class of substrings (here, subarrays) sharing
// the same set of ending positions, and its firstpos is one valid ending
// index; the state's [link.len+1, len] range gives the distinct substring
// lengths ending there. Separately, a sliding window computes maxLen[e] =
// the longest subarray ending at e with at most k multiples of p. For each
// SAM state, intersecting its length range with maxLen[firstpos] gives the
// count of distinct subarrays (of that equivalence class) satisfying the
// constraint; summing over all states counts every distinct valid subarray
// exactly once.
class Solution {
public:
    struct State {
        int len, link, firstpos;
        unordered_map<int, int> next;
    };

    vector<State> sa;
    int last;

    void sa_init() {
        sa.clear();
        sa.push_back({0, -1, -1, {}});
        last = 0;
    }

    void sa_extend(int c, int pos) {
        int cur = sa.size();
        sa.push_back({sa[last].len + 1, -1, pos, {}});
        int p = last;
        while (p != -1 && !sa[p].next.count(c)) {
            sa[p].next[c] = cur;
            p = sa[p].link;
        }
        if (p == -1) {
            sa[cur].link = 0;
        } else {
            int q = sa[p].next[c];
            if (sa[p].len + 1 == sa[q].len) {
                sa[cur].link = q;
            } else {
                int clone = sa.size();
                sa.push_back(sa[q]);
                sa[clone].len = sa[p].len + 1;
                sa[clone].firstpos = sa[q].firstpos;
                while (p != -1 && sa[p].next[c] == q) {
                    sa[p].next[c] = clone;
                    p = sa[p].link;
                }
                sa[q].link = clone;
                sa[cur].link = clone;
            }
        }
        last = cur;
    }

    int countDistinct(vector<int>& nums, int k, int p) {
        int n = nums.size();

        // 1) build SAM over nums
        sa_init();
        for (int i = 0; i < n; i++)
            sa_extend(nums[i], i);

        // 2) maxLen[e] = longest window ending at e with <= k divisible-by-p
        // elements
        vector<int> maxLen(n);
        int lo = 0, cnt = 0;
        for (int e = 0; e < n; e++) {
            if (nums[e] % p == 0)
                cnt++;
            while (cnt > k) {
                if (nums[lo] % p == 0)
                    cnt--;
                lo++;
            }
            maxLen[e] = e - lo + 1;
        }

        // 3) sum valid length ranges over all SAM states
        long long ans = 0;
        for (int v = 1; v < (int)sa.size(); v++) {
            int e = sa[v].firstpos;
            int minlen = sa[sa[v].link].len + 1;
            int maxlen = sa[v].len;
            int cap = min(maxlen, maxLen[e]);
            if (cap >= minlen)
                ans += cap - minlen + 1;
        }
        return (int)ans;
    }
};
