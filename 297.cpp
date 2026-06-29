// Link: https://leetcode.com/problems/serialize-and-deserialize-binary-tree/description/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#pragma GCC optimize("Ofast,unroll-loops,fast-math")
#pragma GCC target("avx,avx2,fma,sse4,popcnt,lzcnt,bmi,bmi2")

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;

static constexpr size_t mxal = alignof(max_align_t);
alignas(mxal) static unsigned char buf[256 * 1024 * 1024];
static size_t pos = 0;

void *operator new(size_t sz)
{
    size_t pad = (mxal - (pos % mxal)) % mxal;
    pos += pad + sz;
    return (void *)(&buf[pos - sz]);
}

void *operator new[](size_t sz) { return operator new(sz); }

void operator delete(void *) noexcept {}
void operator delete[](void *) noexcept {}
void operator delete(void *, size_t) noexcept {}
void operator delete[](void *, size_t) noexcept {}

int speedUp = []
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();
class Codec
{
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        if (!root)
            return "";

        queue<TreeNode *> q;
        q.push(root);
        string s = "";
        while (!q.empty())
        {
            TreeNode *node = q.front();
            q.pop();
            if (node == nullptr)
            {
                s.append("$,");
            }
            else
            {
                s.append(to_string(node->val) + ',');
            }
            if (node != nullptr)
            {
                q.push(node->left);
                q.push(node->right);
            }
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        if (data.length() == 0)
            return nullptr;

        stringstream s(data);
        string nodestr;
        getline(s, nodestr, ',');

        TreeNode *root = new TreeNode(stoi(nodestr));
        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            TreeNode *node = q.front();
            q.pop();

            getline(s, nodestr, ',');

            if (nodestr == "$")
            {
                node->left = nullptr;
            }
            else
            {
                TreeNode *newNode = new TreeNode(stoi(nodestr));
                node->left = newNode;
                q.push(node->left);
            }

            getline(s, nodestr, ',');

            if (nodestr == "$")
            {
                node->right = nullptr;
            }
            else
            {
                TreeNode *newNode = new TreeNode(stoi(nodestr));
                node->right = newNode;
                q.push(node->right);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));