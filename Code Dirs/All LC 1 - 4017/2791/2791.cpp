// Link: https://leetcode.com/problems/count-paths-that-can-form-a-palindrome-in-a-tree/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long countPalindromePaths(vector<int>& parent, string s) {
        int n = parent.size();
        vector<vector<int>> children(n);
        for (int i = 1; i < n; i++) children[parent[i]].push_back(i);

        // mask[u] = XOR of edge-characters from root to u (edge i is between i and parent[i])
        vector<int> mask(n, 0);
        vector<int> order;
        stack<int> st;
        st.push(0);
        while (!st.empty()) {
            int u = st.top(); st.pop();
            order.push_back(u);
            for (int c : children[u]) {
                mask[c] = mask[u] ^ (1 << (s[c] - 'a'));
                st.push(c);
            }
        }

        unordered_map<int,long long> count;
        long long total = 0;
        for (int u : order) {
            int m = mask[u];
            total += count[m];
            for (int b = 0; b < 26; b++) {
                total += count[m ^ (1 << b)];
            }
            count[m]++;
        }
        return total;
    }
};
