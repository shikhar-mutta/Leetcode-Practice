// Link: https://leetcode.com/problems/find-duplicate-subtrees/description/

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

typedef long long ll;

constexpr int N = 5e3;

#define SHIFT(i, sh) ((ll)(unsigned short)(i) << (sh))
#define ID(i, j, k) (SHIFT(i, 32) | SHIFT(j, 16) | SHIFT(k, 0))

class Solution
{
private:
    unordered_map<ll, pair<int, int>> mp;
    vector<TreeNode *> ans;
    int nxt_id = 1;

    int dfs(TreeNode *x)
    {
        if (!x)
            return 0;
        int l = dfs(x->left), r = dfs(x->right);
        auto &[id, cnt] = mp[ID(x->val, l, r)];
        if (!id)
        {
            id = nxt_id++;
            cnt = 1;
        }
        else if (cnt++ == 1)
        {
            ans.push_back(x);
        }
        return id;
    }

public:
    vector<TreeNode *> findDuplicateSubtrees(TreeNode *root)
    {
        dfs(root);
        return move(ans);
    }
};