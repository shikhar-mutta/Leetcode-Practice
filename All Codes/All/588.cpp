// Link: https://leetcode.com/problems/design-in-memory-file-system/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(path length + result size) per op SC: O(total files/dirs)
// Approach: trie-like tree of Node objects; each node has name->child map, isFile flag, and content string. Traverse path splitting on '/'.
struct FSNode {
    bool isFile = false;
    string content;
    map<string, FSNode*> children;
};

class FileSystem {
    FSNode* root;

    vector<string> split(const string& path) {
        vector<string> parts;
        string cur;
        for (char c : path) {
            if (c == '/') {
                if (!cur.empty()) parts.push_back(cur);
                cur.clear();
            } else cur += c;
        }
        if (!cur.empty()) parts.push_back(cur);
        return parts;
    }

    FSNode* traverse(const vector<string>& parts, bool createDirs) {
        FSNode* node = root;
        for (auto& p : parts) {
            if (node->children.find(p) == node->children.end()) {
                if (!createDirs) return nullptr;
                node->children[p] = new FSNode();
            }
            node = node->children[p];
        }
        return node;
    }

public:
    FileSystem() { root = new FSNode(); }

    vector<string> ls(string path) {
        auto parts = split(path);
        FSNode* node = traverse(parts, false);
        if (node->isFile) return {parts.back()};
        vector<string> res;
        for (auto& [name, child] : node->children) res.push_back(name);
        return res;
    }

    void mkdir(string path) {
        traverse(split(path), true);
    }

    void addContentToFile(string filePath, string content) {
        FSNode* node = traverse(split(filePath), true);
        node->isFile = true;
        node->content += content;
    }

    string readContentFromFile(string filePath) {
        FSNode* node = traverse(split(filePath), true);
        return node->content;
    }
};
