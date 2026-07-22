// Link: https://leetcode.com/problems/serialize-and-deserialize-bst/description/

#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Codec
{
public:
    void preorder(TreeNode *root, string &ans)
    {
        if (root == nullptr)
        {
            return;
        }
        ans += to_string(root->val) + ",";
        preorder(root->left, ans);
        preorder(root->right, ans);
    }
    TreeNode *build(vector<int> &nums, int &i, int low, int high)
    {
        if (i == nums.size())
        {
            return nullptr;
        }
        if (nums[i] < low || nums[i] > high)
        {
            return nullptr;
        }
        TreeNode *root = new TreeNode(nums[i]);
        i++;
        root->left = build(nums, i, low, root->val);
        root->right = build(nums, i, root->val, high);
        return root;
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        string ans = "";
        preorder(root, ans);
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        int n = data.length();
        vector<int> nums;
        string temp = "";
        for (char c : data)
        {
            if (c == ',')
            {
                nums.push_back(stoi(temp));
                temp = "";
            }
            else
            {
                temp += c;
            }
        }
        int i = 0;
        return build(nums, i, INT_MIN, INT_MAX);
    }
};