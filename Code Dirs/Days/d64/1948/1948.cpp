// Link: https://leetcode.com/problems/delete-duplicate-folders-in-system/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n log n) SC: O(n)
// Approach: We can use a trie data structure to store the folder structure. We can then perform a depth-first search (DFS) on the tree and for each node, we can create a signature of the subtree rooted at that node. We can then use a hash map to keep track of the number of times each signature has been seen. If a signature has been seen more than once, we can mark the corresponding node as deleted. Finally, we can return the remaining paths in the trie.
struct Signature
{
    vector<pair<int, int>> children;

    bool operator==(const Signature &) const = default;
};

struct SignatureHash
{
    static uint64_t mix(uint64_t value)
    {
        value += 0x9e3779b97f4a7c15ULL;
        value = (value ^ (value >> 30)) * 0xbf58476d1ce4e5b9ULL;
        value = (value ^ (value >> 27)) * 0x94d049bb133111ebULL;
        return value ^ (value >> 31);
    }

    size_t operator()(const Signature &signature) const
    {
        uint64_t hash = mix(signature.children.size());
        for (auto [name_id, child_id] : signature.children)
        {
            uint64_t entry =
                (static_cast<uint64_t>(static_cast<uint32_t>(name_id)) << 32) |
                static_cast<uint32_t>(child_id);
            hash = mix(hash ^ mix(entry));
        }
        return static_cast<size_t>(hash);
    }
};

struct Node
{
    unordered_map<int, Node> children;
    int id = 0;
};

class Solution
{
    unordered_map<string, int> name_ids;
    unordered_map<Signature, int, SignatureHash> subtree_ids;
    vector<int> seen{1};
    Node root;
    int next_name_id = 1;
    int next_subtree_id = 1;

    int compress_name(const string &name)
    {
        auto [it, inserted] = name_ids.try_emplace(name, next_name_id);
        if (inserted)
            ++next_name_id;
        return it->second;
    }

    void visit(const vector<string> &path)
    {
        Node *node = &root;
        for (const string &name : path)
        {
            node = &node->children[compress_name(name)];
        }
    }

    int compress_node(Node &node)
    {
        if (node.children.empty())
            return node.id = 0;

        Signature signature;
        signature.children.reserve(node.children.size());
        for (auto &[name_id, child] : node.children)
        {
            signature.children.emplace_back(name_id, compress_node(child));
        }
        ranges::sort(signature.children);

        auto [it, inserted] =
            subtree_ids.try_emplace(std::move(signature), next_subtree_id);
        if (inserted)
        {
            ++next_subtree_id;
            seen.push_back(0);
        }
        node.id = it->second;
        ++seen[node.id];
        return node.id;
    }

    bool is_del(const vector<string> &path) const
    {
        const Node *node = &root;
        for (const string &name : path)
        {
            if (node->id && seen[node->id] > 1)
                return true;

            auto name_it = name_ids.find(name);
            if (name_it == name_ids.end())
                return false;
            auto child_it = node->children.find(name_it->second);
            if (child_it == node->children.end())
                return false;
            node = &child_it->second;
        }
        return node->id && seen[node->id] > 1;
    }

public:
    vector<vector<string>>
    deleteDuplicateFolder(vector<vector<string>> &paths)
    {
        name_ids.reserve(paths.size() * 2);
        subtree_ids.reserve(paths.size());
        for (const vector<string> &path : paths)
            visit(path);

        compress_node(root);

        vector<vector<string>> res;
        res.reserve(paths.size());
        for (const vector<string> &path : paths)
        {
            if (!is_del(path))
                res.push_back(path);
        }
        return res;
    }
};