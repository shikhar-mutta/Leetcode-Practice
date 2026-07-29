// Link: https://leetcode.com/problems/check-if-dfs-strings-are-palindromes/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(N), SC: O(N)
// Approach: since a DFS visits each subtree as one contiguous block, run one post-order DFS from
// the root over the whole tree to build a single global string, recording each node's [start,end)
// range within it — dfsStr(i) is exactly that substring. Run Manacher's algorithm once on the
// global string to answer "is [l,r) a palindrome" in O(1), then look up each node's range.
class Solution {
public:
    vector<bool> findAnswer(vector<int>& parent, string s) {
        int n = parent.size();
        vector<vector<int>> children(n);
        for (int i = 1; i < n; i++) children[parent[i]].push_back(i);
        // children naturally added in increasing index order already

        string big;
        big.reserve(n);
        vector<int> start(n), end_(n);

        // iterative post-order
        vector<int> childIdx(n, 0);
        vector<bool> entered(n, false);
        stack<int> st;
        st.push(0);
        while (!st.empty()) {
            int u = st.top();
            if (!entered[u]) {
                entered[u] = true;
                start[u] = big.size();
            }
            if (childIdx[u] < (int)children[u].size()) {
                int c = children[u][childIdx[u]++];
                st.push(c);
            } else {
                big += s[u];
                end_[u] = big.size(); // exclusive
                st.pop();
            }
        }

        // Manacher's algorithm on `big` using transformed string with separators
        string t = "^";
        for (char c : big) { t += '#'; t += c; }
        t += "#$";
        int m = t.size();
        vector<int> p(m, 0);
        int center = 0, right = 0;
        for (int i = 1; i < m-1; i++) {
            if (i < right) p[i] = min(right - i, p[2*center - i]);
            while (t[i + p[i] + 1] == t[i - p[i] - 1]) p[i]++;
            if (i + p[i] > right) { center = i; right = i + p[i]; }
        }

        // isPalindrome(l, r) inclusive, 0-indexed in `big`: corresponds to center index in t = l+r+2
        auto isPalin = [&](int l, int r) {
            int cIdx = l + r + 2;
            int len = r - l + 1;
            return p[cIdx] >= len;
        };

        vector<bool> ans(n);
        for (int i = 0; i < n; i++) {
            ans[i] = isPalin(start[i], end_[i] - 1);
        }
        return ans;
    }
};
