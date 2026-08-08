// Link: https://leetcode.com/problems/maximum-xor-with-an-element-from-array/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    struct TrieNode {
        TrieNode* child[2] = {nullptr, nullptr};
    };
    TrieNode* root = new TrieNode();

    void insert(int num) {
        TrieNode* node = root;
        for (int b = 29; b >= 0; b--) {
            int bit = (num >> b) & 1;
            if (!node->child[bit]) node->child[bit] = new TrieNode();
            node = node->child[bit];
        }
    }

    int query(int num) {
        TrieNode* node = root;
        int res = 0;
        for (int b = 29; b >= 0; b--) {
            int bit = (num >> b) & 1;
            int want = 1 - bit;
            if (node->child[want]) {
                res |= (1 << b);
                node = node->child[want];
            } else {
                node = node->child[bit];
            }
        }
        return res;
    }

    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        sort(nums.begin(), nums.end());
        int m = queries.size();
        vector<int> idx(m);
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](int a, int b) {
            return queries[a][1] < queries[b][1];
        });

        vector<int> ans(m, -1);
        int i = 0, n = nums.size();
        for (int qi : idx) {
            int x = queries[qi][0], limit = queries[qi][1];
            while (i < n && nums[i] <= limit) { insert(nums[i]); i++; }
            if (i == 0) { ans[qi] = -1; continue; }
            ans[qi] = query(x);
        }
        return ans;
    }
};
