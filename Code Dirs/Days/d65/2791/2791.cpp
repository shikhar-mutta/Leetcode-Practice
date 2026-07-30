// Link: https://leetcode.com/problems/count-paths-that-can-form-a-palindrome-in-a-tree/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) where n is the length of the parent, SC: O(n) where n is the length of the parent
// Approach: We can use a bitmask to represent the characters in the path from the root to the current node. We will use a queue to perform a BFS traversal of the tree. For each node, we will update the bitmask by XORing it with the character at that node. We will also maintain a frequency map to count the number of times each bitmask has been seen. Finally, we will calculate the number of palindrome paths by checking if the current bitmask or any bitmask that differs by one bit has been seen before.
class Solution
{
public:
    long long countPalindromePaths(vector<int> &parent, string s)
    {
        int n = (int)parent.size();
        vector<vector<pair<int, char>>> g(n);
        for (int i = 1; i < n; i++)
        {
            g[parent[i]].push_back({i, s[i]});
        }
        queue<pair<int, int>> q;
        unordered_map<int, int> freq;
        q.push({0, 0});
        while (!q.empty())
        {
            auto [mask, i] = q.front();
            q.pop();
            freq[mask]++;
            for (auto [v, c] : g[i])
            {
                q.push({mask ^ (1 << (c - 'a')), v});
            }
        }
        long long ans = 0;
        for (auto [mask, cnt] : freq)
        {
            ans += (long long)cnt * (cnt - 1) / 2;
            for (int i = 0; i < 26; i++)
            {
                if ((mask ^ (1 << i)) < mask && freq.count(mask ^ (1 << i)))
                    ans += (long long)cnt * freq[mask ^ (1 << i)];
            }
        }
        return ans;
    }
};
