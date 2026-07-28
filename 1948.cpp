// Link: https://leetcode.com/problems/delete-duplicate-folders-in-system/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(total path length * log)  SC: O(total path length)
// Approach: build a trie of folders, compute each subtree's canonical
// serialization (sorted child signatures), group nodes by signature; any
// signature (non-leaf) shared by 2+ nodes marks all of them for deletion.
// DFS again collecting paths for nodes not marked and not under a deleted node.
class Solution {
    struct Node {
        map<string, Node*> children;
        bool deleted = false;
    };

    unordered_map<string, vector<Node*>> sigGroups;

    string serialize(Node* node) {
        if (node->children.empty()) return "";
        vector<string> parts;
        for (auto& [name, child] : node->children) {
            parts.push_back(name + "(" + serialize(child) + ")");
        }
        string sig;
        for (auto& p : parts) sig += p;
        sigGroups[sig].push_back(node);
        return sig;
    }

    void collect(Node* node, vector<string>& cur, vector<vector<string>>& res) {
        for (auto& [name, child] : node->children) {
            if (child->deleted) continue;
            cur.push_back(name);
            res.push_back(cur);
            collect(child, cur, res);
            cur.pop_back();
        }
    }
public:
    vector<vector<string>> deleteDuplicateFolder(vector<vector<string>>& paths) {
        Node* root = new Node();
        for (auto& p : paths) {
            Node* cur = root;
            for (auto& name : p) {
                if (!cur->children.count(name)) cur->children[name] = new Node();
                cur = cur->children[name];
            }
        }
        serialize(root);
        for (auto& [sig, nodes] : sigGroups) {
            if (sig.empty()) continue;
            if (nodes.size() > 1) {
                for (auto* n : nodes) n->deleted = true;
            }
        }
        vector<vector<string>> res;
        vector<string> cur;
        collect(root, cur, res);
        return res;
    }
};
