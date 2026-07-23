// Link: https://leetcode.com/problems/lexicographically-smallest-equivalent-string/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n + m) where n is the length of s1 and m is the length of baseStr
// SC: O(26) for parent and rank arrays
//  Approach:
//  1. We can use union-find (disjoint set union) to group equivalent characters together.
//  2. We can create a parent array of size 26 (for each character in the alphabet) and initialize each character to be its own parent.
//  3. We can iterate through the characters in s1 and s2 and unite them in the parent array.
//  4. We can then iterate through the characters in baseStr and find the parent of each character, which will give us the lexicographically smallest equivalent character for that character.
//  5. We can then build the answer string by appending the lexicographically smallest equivalent character for each character in baseStr.
class Solution
{
public:
    int n;
    vector<int> parent;
    vector<int> rank;
    int findParent(int node)
    {
        if (node == parent[node])
            return node;
        return parent[node] = findParent(parent[node]);
    }
    void unite(int u, int v)
    {
        int up = findParent(u);
        int vp = findParent(v);
        if (up == vp)
            return;
        if (up < vp)
        {
            parent[vp] = up;
        }
        else
            parent[up] = vp;
    }
    string smallestEquivalentString(string s1, string s2, string baseStr)
    {
        n = s1.size();
        string ans = "";
        parent.resize(26);
        rank.assign(n, 0);
        for (int i = 0; i < 26; i++)
        {
            parent[i] = i;
        }
        for (int i = 0; i < n; i++)
        {
            unite(s1[i] - 'a', s2[i] - 'a');
        }
        for (auto &ch : baseStr)
        {
            int temp = findParent(ch - 'a');
            ans += temp + 'a';
        }
        return ans;
    }
};