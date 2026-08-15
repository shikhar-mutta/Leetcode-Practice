// Link: https://leetcode.com/problems/find-subtree-sizes-after-changes/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();
        vector<vector<int>> origChildren(n);
        for (int i = 1; i < n; i++) origChildren[parent[i]].push_back(i);

        vector<int> newParent(n, -1);
        vector<vector<int>> charStack(26);
        {
            vector<pair<int,bool>> st;
            st.push_back({0, false});
            while (!st.empty()) {
                auto [node, exiting] = st.back(); st.pop_back();
                int c = s[node] - 'a';
                if (exiting) { charStack[c].pop_back(); continue; }

                if (node != 0) {
                    if (!charStack[c].empty()) newParent[node] = charStack[c].back();
                    else newParent[node] = parent[node];
                }
                charStack[c].push_back(node);
                st.push_back({node, true});
                for (int ch : origChildren[node]) st.push_back({ch, false});
            }
        }

        vector<vector<int>> newChildren(n);
        for (int i = 1; i < n; i++) newChildren[newParent[i]].push_back(i);

        vector<int> order;
        order.reserve(n);
        {
            vector<pair<int,bool>> st;
            st.push_back({0, false});
            while (!st.empty()) {
                auto [node, processed] = st.back(); st.pop_back();
                if (processed) { order.push_back(node); continue; }
                st.push_back({node, true});
                for (int ch : newChildren[node]) st.push_back({ch, false});
            }
        }

        vector<int> size(n, 1);
        for (int node : order) {
            if (newParent[node] != -1) size[newParent[node]] += size[node];
        }

        return size;
    }
};
