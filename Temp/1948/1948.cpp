// Link: https://leetcode.com/problems/delete-duplicate-folders-in-system/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    struct Node {
        map<string, Node*> children;
        bool deleted = false;
    };

    unordered_map<string, int> serialCount;

    string serialize(Node* node) {
        if (node->children.empty()) return "";
        string s = "(";
        for (auto& [name, child] : node->children) {
            s += name + serialize(child);
        }
        s += ")";
        return s;
    }

    void markDeleted(Node* node) {
        if (node->children.empty()) return;
        string s = serialize(node);
        if (serialCount[s] >= 2) {
            node->deleted = true;
        }
        for (auto& [name, child] : node->children) markDeleted(child);
    }

    void collect(Node* node, vector<string>& path, vector<vector<string>>& res) {
        for (auto& [name, child] : node->children) {
            if (child->deleted) continue;
            path.push_back(name);
            res.push_back(path);
            collect(child, path, res);
            path.pop_back();
        }
    }

    vector<vector<string>> deleteDuplicateFolder(vector<vector<string>>& paths) {
        Node* root = new Node();
        for (auto& p : paths) {
            Node* cur = root;
            for (auto& name : p) {
                if (!cur->children.count(name)) cur->children[name] = new Node();
                cur = cur->children[name];
            }
        }

        function<void(Node*)> countSerials = [&](Node* node) {
            if (node->children.empty()) return;
            string s = serialize(node);
            serialCount[s]++;
            for (auto& [name, child] : node->children) countSerials(child);
        };
        countSerials(root);

        for (auto& [name, child] : root->children) markDeleted(child);

        vector<vector<string>> res;
        vector<string> path;
        collect(root, path, res);
        return res;
    }
};
