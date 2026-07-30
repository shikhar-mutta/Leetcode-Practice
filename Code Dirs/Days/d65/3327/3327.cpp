// Link: https://leetcode.com/problems/check-if-dfs-strings-are-palindromes/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n), SC: O(n)
//  Approach: We can use a depth-first search (DFS) approach to solve this problem. We can traverse the tree in a DFS manner and store the characters of each node in a string. We can also maintain two vectors l and r to keep track of the left and right indices of each node in the string. After traversing the tree, we can check if the substring of the string from l[i] to r[i] is a palindrome for each node i. If it is a palindrome, we can set the corresponding index in the answer vector to true, otherwise false. Finally, we can return the answer vector.
class Solution
{
public:
    vector<int> l;
    vector<int> r;
    string post;
    vector<vector<int>> adj;
    void dfs(string &str, int node)
    {
        l[node] = post.size();
        for (auto it : adj[node])
        {
            dfs(str, it);
        }
        post += str[node];
        r[node] = post.size() - 1;
    }
    vector<bool> findAnswer(vector<int> &p, string s)
    {
        int n = p.size();
        adj.resize(n);
        l.resize(n);
        r.resize(n);
        for (int i = 0; i < n; i++)
        {
            if (p[i] != -1)
            {
                adj[p[i]].push_back(i);
            }
        }
        post = "";
        dfs(s, 0);
        s = post;
        vector<int> even(n, 0);
        for (int i = 0, le = 0, ri = -1; i < n; i++)
        {
            int k = (i > ri) ? 0 : min(even[le + ri + 1 - i], ri - i + 1);
            while (i - k - 1 >= 0 && i + k < n && s[i - k - 1] == s[i + k])
            {
                k++;
            }
            even[i] = k--;
            if (i + k > ri)
            {
                le = i - k - 1;
                ri = i + k;
            }
        }
        vector<int> odd(n, 0);
        for (int i = 0, le = 0, ri = -1; i < n; i++)
        {
            int k =
                (i > ri)
                    ? 1
                    : min(odd[le + ri - i],
                          ri - i +
                              1); // itna already pal hai no need to check again
            while (i - k >= 0 && i + k < n && s[i - k] == s[i + k])
            {
                k++;
            }
            odd[i] = k--;
            if (i + k > ri)
            {
                le = i - k;
                ri = i + k;
            }
        }
        vector<bool> ans(n, 0);
        for (int i = 0; i < n; i++)
        {
            int left = l[i];
            int right = r[i];
            int len = right - left + 1;
            if (len % 2 == 1)
            {
                int c = (right + left) / 2;
                if (odd[c] >= len / 2 + 1)
                    ans[i] = 1;
            }
            else
            {
                int c = (left + right + 1) / 2;
                if (even[c] >= len / 2)
                    ans[i] = 1;
            }
        }
        return ans;
    }
};
