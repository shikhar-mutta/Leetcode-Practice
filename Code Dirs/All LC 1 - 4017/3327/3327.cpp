// Link: https://leetcode.com/problems/check-if-dfs-strings-are-palindromes/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<bool> findAnswer(vector<int>& parent, string s) {
        int n = parent.size();
        vector<vector<int>> children(n);
        for (int i = 1; i < n; i++) children[parent[i]].push_back(i);
        for (auto& c : children) sort(c.begin(), c.end());

        vector<int> order;
        order.reserve(n);
        {
            vector<pair<int,bool>> st;
            st.push_back({0, false});
            while (!st.empty()) {
                auto [node, processed] = st.back(); st.pop_back();
                if (processed) { order.push_back(node); continue; }
                st.push_back({node, true});
                for (int j = (int)children[node].size() - 1; j >= 0; j--) {
                    st.push_back({children[node][j], false});
                }
            }
        }

        vector<int> posInOrder(n);
        for (int k = 0; k < n; k++) posInOrder[order[k]] = k;

        vector<int> size(n, 1);
        // compute subtree sizes via reverse of a topological (post-order works: process order[] left to right, but need child sizes before parent)
        // order[] is post-order, so processing left to right, by the time we reach a node, its children are already processed (since post-order visits children first)
        for (int k = 0; k < n; k++) {
            int node = order[k];
            if (parent[node] != -1) size[parent[node]] += size[node];
        }

        string dfsStr(n, ' ');
        for (int k = 0; k < n; k++) dfsStr[k] = s[order[k]];

        const long long MOD = 1000000007;
        const long long BASE = 131542391;
        vector<long long> pw(n + 1), prefHash(n + 1, 0);
        pw[0] = 1;
        for (int i = 1; i <= n; i++) pw[i] = (__int128)pw[i-1] * BASE % MOD;
        for (int i = 0; i < n; i++) prefHash[i+1] = ((__int128)prefHash[i] * BASE + dfsStr[i]) % MOD;

        string rev(dfsStr.rbegin(), dfsStr.rend());
        vector<long long> revPrefHash(n + 1, 0);
        for (int i = 0; i < n; i++) revPrefHash[i+1] = ((__int128)revPrefHash[i] * BASE + rev[i]) % MOD;

        auto getHash = [&](vector<long long>& pref, int l, int r) -> long long {
            // hash of substring [l, r) 0-indexed
            return ((__int128)MOD + pref[r] - (__int128)pref[l] * pw[r-l] % MOD) % MOD;
        };

        vector<bool> res(n, false);
        for (int i = 0; i < n; i++) {
            int endPos = posInOrder[i]; // inclusive
            int startPos = endPos - size[i] + 1;
            long long h1 = getHash(prefHash, startPos, endPos + 1);
            // corresponding range in rev: rev = reverse of dfsStr, so dfsStr[startPos..endPos] reversed = rev[n-1-endPos .. n-1-startPos]
            int revL = n - 1 - endPos;
            int revR = n - 1 - startPos;
            long long h2 = getHash(revPrefHash, revL, revR + 1);
            res[i] = (h1 == h2);
        }
        return res;
    }
};
